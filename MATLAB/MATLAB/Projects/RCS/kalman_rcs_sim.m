clear; clc; close all;T

%% What do we want to do combine gyro and mag data to get good estimate of attitude
Nsamples  = 5000;
KalmanSaved  = zeros(Nsamples, 3);

%time
t0 = 0;
dt = 0.1;
tf = 100;

%initial conditions
psi = 0;
theta = 0;
phi = 0;

%setup variables
rcs_dot =[psi, theta, phi];
rcs_dot_ang = [psi_dot, theta_dot, phi_dot];
rcs_dot_mag = [mag_x, mag_y, mag_z];

%loop for the code
for k=1:Nsamples    
    %getting the gyro data
    rcs_dot_ang = GetRCSGyro();
    %getting the updated perveriance matrix w/ respect to euler angles
    A = eye(4) + dt * (1/2) * [0          -rcs_dot_ang(1)  -rcs_dot_ang(2)   -rcs_dot_ang(3) ;
                              rcs_dot_ang(1)   0            rcs_dot_ang(3)   -rcs_dot_ang(2) ;
                              rcs_dot_ang(2)  -rcs_dot_ang(3)        0        rcs_dot_ang(1) ;
                              rcs_dot_ang(3)   rcs_dot_ang(2)  -rcs_dot_ang(1)      0  ];
    
    %getting the mag data
    rcs_dot_mag = GetRCSMag();
    %converting the mag data into angles
    rcs_dot = ConvMag(rcs_dot_mag);

    %converting B2E frame for the kalman filter
    z = E2B(rcs_dot');
    rcs_dot = KalmanFilter(A, z);

    KalmanSaved(k,:) = rcs_dot;
end

psi = rcs_dot_ang(1) * (180/pi);
theta = rcs_dot_ang(2) * (180/pi);
phi = rcs_dot_ang(3) * (180/pi);

t = t0:dt:Nsamples*dt-dt;
