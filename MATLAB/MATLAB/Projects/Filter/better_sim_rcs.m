clear all; clc; close all;

%% Initial Conditions
%time
t0 = 0;
dt = 0.01;
tf = 100;

Nsamples = 41500; % Number of data points
Kalamnsaved = zeros(Nsamples, 3);


%variables
rcs0 = [0, 0, 0, 0, 0, 0]';

while t <= tf
     rcs0(1:3) = GetGyro();
     rcs0(4:6) = GetMag();
     A = eye(4) + dt*(1/2) * [ 0   -rcs0(1)  -rcs0(2)  -rcs0(3) ;
                               rcs0(1)   0    rcs0(3)  -rcs0(2) ;
                               rcs0(2)  -rcs0(3)   0    rcs0(1) ;
                               rcs0(3)   rcs0(2)  -rcs0(1)   0  ];
    


     rcsdot = KalmanFilter(A, rcs0);

     Kalmansaved(k, :) = rcsdot;
end

t = t0:dt:Nsamples*dt-dt;
