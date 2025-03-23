#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FS 360.0f          // Sampling frequency in Hz
#define WINDOW_SIZE 30     // Sliding window size for integration
#define BUFFER_SIZE 900   // Increased to 1800 samples
#define MAX_PEAKS 100      // Max number of R-peaks (for internal use)

// Memory buffers
float ecg_signal[BUFFER_SIZE];
float y_lp[BUFFER_SIZE];
float y_hp[BUFFER_SIZE];
float y_der[BUFFER_SIZE];
float y_sq[BUFFER_SIZE];
float y_int[BUFFER_SIZE];
int r_peaks[MAX_PEAKS];           // Internal array for R-peak indices
int r_peak_binary[BUFFER_SIZE];   // New binary array (0s and 1s)
float heart_rate;
int num_peaks = 0;

// Function prototypes
void low_pass_filter(float *x, float *y, int N);
void high_pass_filter(float *x, float *y, int N);
void derivative(float *x, float *y, int N);
void square(float *x, float *y, int N);
void integration(float *x, float *y, int N);
void peak_detection(float *x, int N, float fs, int *r_peaks, int *r_peak_binary, int *num_peaks, float *heart_rate);
void save_to_file(float *data, int N, const char *filename);
void save_binary_to_file(int *data, int N, const char *filename);

void low_pass_filter(float *x, float *y, int N) {
    memset(y, 0, N * sizeof(float));
    for (int n = 12; n < N; n++) {
        y[n] = 2 * y[n - 1] - y[n - 2] + x[n] - 2 * x[n - 6] + x[n - 12];
    }
}

void high_pass_filter(float *x, float *y, int N) {
    memset(y, 0, N * sizeof(float));
    for (int n = 32; n < N; n++) {
        y[n] = y[n - 1] - (1.0f / 32.0f) * x[n] + x[n - 16] - x[n - 17] + (1.0f / 32.0f) * x[n - 32];
    }
}

void derivative(float *x, float *y, int N) {
    memset(y, 0, N * sizeof(float));
    for (int n = 4; n < N; n++) {
        y[n] = (1.0f / 8.0f) * (2 * x[n] + x[n - 1] - x[n - 3] - 2 * x[n - 4]);
    }
}

void square(float *x, float *y, int N) {
    for (int n = 0; n < N; n++) {
        y[n] = x[n] * x[n];
    }
}

void integration(float *x, float *y, int N) {
    memset(y, 0, N * sizeof(float));
    for (int n = WINDOW_SIZE - 1; n < N; n++) {
        float sum = 0.0f;
        for (int i = 0; i < WINDOW_SIZE; i++) {
            sum += x[n - i];
        }
        y[n] = sum / WINDOW_SIZE;
    }
}

void peak_detection(float *x, int N, float fs, int *r_peaks, int *r_peak_binary, int *num_peaks, float *heart_rate) {
    float SPKI = 0.0f, NPKI = 0.0f, THRESHOLD1, THRESHOLD2;
    int last_peak = 0;
    *num_peaks = 0;

    // Initialize r_peak_binary to zeros
    memset(r_peak_binary, 0, N * sizeof(int));

    // Find maximum value for initial thresholds
    float max_val = x[0];
    for (int i = 1; i < N; i++) {
        if (x[i] > max_val) max_val = x[i];
    }
    SPKI = max_val * 0.25f;
    NPKI = max_val * 0.125f;
    THRESHOLD1 = NPKI + 0.25f * (SPKI - NPKI);
    THRESHOLD2 = 0.5f * THRESHOLD1;

    // Peak detection loop
    for (int n = 1; n < N - 1; n++) {
        if (x[n] > x[n - 1] && x[n] > x[n + 1]) {
            float PEAKI = x[n];
            if (PEAKI > THRESHOLD1) {
                if (*num_peaks == 0 || (n - last_peak) > (int)(0.6f * fs)) {
                    if (*num_peaks < MAX_PEAKS) {
                        r_peaks[*num_peaks] = n;          // Store index internally
                        r_peak_binary[n] = 1;             // Set 1 at peak location
                        (*num_peaks)++;
                        last_peak = n;
                        SPKI = 0.125f * PEAKI + 0.875f * SPKI;
                    }
                }
            } else {
                NPKI = 0.125f * PEAKI + 0.875f * NPKI;
            }
            THRESHOLD1 = NPKI + 0.25f * (SPKI - NPKI);
            THRESHOLD2 = 0.5f * THRESHOLD1;
        }
    }

    // Compute heart rate
    if (*num_peaks > 1) {
        float rr_sum = 0.0f;
        for (int i = 1; i < *num_peaks; i++) {
            float rr = (float)(r_peaks[i] - r_peaks[i - 1]) / fs;
            rr_sum += 60.0f / rr;
        }
        *heart_rate = rr_sum / (*num_peaks - 1);
    } else {
        *heart_rate = 0.0f;
    }
}

void save_to_file(float *data, int N, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }
    for (int i = 0; i < N; i++) {
        fprintf(fp, "%.6f\n", data[i]);
    }
    fclose(fp);
}

void save_binary_to_file(int *data, int N, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }
    for (int i = 0; i < N; i++) {
        fprintf(fp, "%d\n", data[i]);
    }
    fclose(fp);
}

int main() {
    FILE *fp = fopen("ecg_data.txt", "r");
    if (fp == NULL) {
        printf("Error opening ecg_data.txt\n");
        return 1;
    }

    for (int i = 0; i < BUFFER_SIZE; i++) {
        if (fscanf(fp, "%f", &ecg_signal[i]) != 1) {
            printf("Error reading sample %d\n", i);
            break;
        }
    }
    fclose(fp);
    int signal_length = BUFFER_SIZE;

    low_pass_filter(ecg_signal, y_lp, signal_length);
    save_to_file(y_lp, signal_length, "lpf_output.txt");

    high_pass_filter(y_lp, y_hp, signal_length);
    save_to_file(y_hp, signal_length, "hpf_output.txt");

    derivative(y_hp, y_der, signal_length);
    save_to_file(y_der, signal_length, "diff_output.txt");

    square(y_der, y_sq, signal_length);
    save_to_file(y_sq, signal_length, "square_output.txt");

    integration(y_sq, y_int, signal_length);
    save_to_file(y_int, signal_length, "integration_output.txt");

    peak_detection(y_int, signal_length, FS, r_peaks, r_peak_binary, &num_peaks, &heart_rate);
    save_binary_to_file(r_peak_binary, signal_length, "r_peak_binary.txt");

    printf("Processing complete.\n");
    printf("Heart Rate: %.2f BPM\n", heart_rate);

    printf("R peaks detected at following indices:\n");
    for(int i = 0; i < num_peaks; i++) {
        printf("%d ", r_peaks[i]);
    }

    return 0;

}