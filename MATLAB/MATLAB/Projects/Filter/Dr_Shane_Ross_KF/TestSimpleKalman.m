clear all; clc; close all;

%time step portion
dt = 0.2;
t = 0:dt:10;

%range of values
Nsamples = length(t);

%storage varaibles
Xsaved = zeros(Nsamples, 1);
Zsaved = zeros(Nsamples, 1);

%looping portion to get the true voltage and recursively computed average
%is the measurement noise vs the recursive
for  k=1:Nsamples
    z = GetVolt();
    volt = AvgFilter(z);
    
    %storing within the loop
    Xsaved(k) = volt;
    Zsaved(k) = z;
end

%plotting
figure (1)
plot(t, Xsaved, 'o-', 'linewidth', 4);
hold on
plot(t, Zsaved, 'r:x', 'markersize', 10, 'LineWidth', 2);
xlabel('time (s)'); ylabel('voltage (V)');
title('Voltage');
legend('Kalman Filter', 'Measurements');
set(gca, 'fontsize', 18);
grid on

