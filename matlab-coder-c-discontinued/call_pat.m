clc;
close all;
clear all;

[tm,signal,fs,labels] = rdmat('100m');
ch1 = signal(:,1);
ch2 = signal(:,2);
t = tm(1:1800);
s1 = ch1(1:1800);
s2 = ch2(1:1800);

x = s1;

[heart_rate, r_peaks] = pat(x, fs);

heart_rate;
r_peaks;

z = ones(size(x)); % Ensure z matches the signal length
stem(t(r_peaks), z(r_peaks), 'r');
hold on;
plot(t, x);
xlabel('Time (s)');
ylabel('Amplitude');
title('R-Peak Locations');
grid on;
hold off;