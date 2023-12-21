clear all; clc; close all;

%time step portion
dt = 0.2;
t = 0:dt:10;

%range of values
Nsamples = length(t);

%storage varaibles
Avgsaved = zeros(Nsamples, 1);
Xmsaved = zeros(Nsamples, 1);

%looping portion to get the true voltage and recursively computed average
%is the measurement noise vs the recursive
for  k=1:Nsamples
    xm = GetVolt();
    avg = AvgFilter(xm);
    
    %storing within the loop
    Avgsaved(k) = avg;
    Xmsaved(k) = xm;
end

%plotting
figure (1)
plot(t, Xmsaved, 'r:*');
hold on
plot(t, Avgsaved, 'o-');
