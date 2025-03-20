function [heart_rate, r_peaks] = pat(ecg_signal, fs) 
%#codegen

%PAN_TOMPKINS_ECG Detects R-peaks and computes heart rate from an ECG signal.
%   [heart_rate, r_peaks] = PAN_TOMPKINS_ECG(ecg_signal, fs) processes the
%   input ECG signal sampled at frequency fs, detects R-peaks using the
%   Pan-Tompkins algorithm, and calculates the instantaneous heart rate.
%
%   Inputs:
%       ecg_signal - Vector containing the ECG signal data.
%       fs         - Sampling frequency of the ECG signal in Hz.
%
%   Outputs:
%       heart_rate - Vector of instantaneous heart rates in beats per minute (BPM).
%       r_peaks    - Indices of detected R-peaks in the ECG signal.

    % Ensure the input signal is a column vector
    ecg_signal = ecg_signal(:);

    % Length of the input signal
    N = length(ecg_signal);

    % Initialize variables
    r_peaks = []; % Store detected R-peak locations

    % Bandpass Filter Design (5-15 Hz)
    [b_band, a_band] = butter(1, [5 15] / (fs / 2), 'bandpass');
    filtered_ecg = filtfilt(b_band, a_band, ecg_signal);

    % Differentiation
    diff_ecg = diff(filtered_ecg);

    % Squaring
    squared_ecg = diff_ecg .^ 2;

    % Moving Window Integration
    window_size = round(0.150 * fs); % 150 ms window
    mwi_ecg = filter(ones(1, window_size) / window_size, 1, squared_ecg);

    % Threshold Initialization
    threshold = 0.6 * max(mwi_ecg); % Initial threshold
    SPKI = threshold;  % Initial signal peak estimate
    NPKI = 0.5 * threshold; % Initial noise peak estimate

    % Peak Detection
    i = 1;
    while i <= N - window_size
        if mwi_ecg(i) > threshold
            % Search back for the corresponding peak in the original signal
            [~, peak_index] = max(ecg_signal(i:i + window_size - 1));
            r_peak = i + peak_index - 1;
            r_peaks = [r_peaks; r_peak];

            % Update signal peak estimate
            SPKI = 0.125 * mwi_ecg(i) + 0.875 * SPKI;

            % Update threshold
            threshold = NPKI + 0.25 * (SPKI - NPKI);

            % Skip refractory period (200 ms)
            i = i + round(0.2 * fs);
        else
            % Update noise peak estimate
            NPKI = 0.125 * mwi_ecg(i) + 0.875 * NPKI;

            % Update threshold
            threshold = NPKI + 0.25 * (SPKI - NPKI);

            i = i + 1;
        end
    end

    % Compute Heart Rate
    if length(r_peaks) > 1
        rr_intervals = diff(r_peaks) / fs;
        heart_rate = 60 ./ rr_intervals; % Convert RR intervals to BPM
    else
        heart_rate = [];
    end
end
