clear;clc;close all

%% Initial Conditions
%time
tf = 100;
tspan = [0 tf];
dt = 0.1;

%givens for T-37 Dragonfly (trainer) for Lateral Motion
%speed of sound
delta_p_lat = 0; %ft/s
delta_r = 0; %deg/s
delta_beta = 0; %deg
delta_phi = 0; %deg

% putting together the initial state vector
y0 = [delta_beta, delta_p_lat, delta_r, delta_phi]';

%% using RK4 - correct implementation of this results in extra credit
% initialize the integrated parameters
t_rk4 = 0;
y_rk4 = y0;


% initialize output logging
time_log_rk4 = [];
y_log_rk4 = [];


% RK4 integration loop
for ii = t_rk4:dt:tf
%*************** Lateral ***************
% output datalogging
time_log_rk4(end+1,:) = t_rk4;
y_log_rk4(end+1,:) = y_rk4';
% calculating the derivatives
k1_lat = EOM_lat_control(y_rk4);
k2_lat = EOM_lat_control(y_rk4 + k1_lat*dt/2);
k3_lat = EOM_lat_control(y_rk4 + k2_lat*dt/2);
k4_lat = EOM_lat_control(y_rk4 + k3_lat*dt);
% calculating the increment of the state vector
dy = (dt/6)*(k1_lat + 2*k2_lat + 2*k3_lat + k4_lat);
% increment the state vector
y_rk4 = y_rk4 + dy;
% increment the integration time - this is super important, failure to
% do this will result in getting stuck in the loop forever
t_rk4 = t_rk4 + dt;

waitbar(ii/tf,waitbar(0), "Progress (" +ii+ "/" + tf + ")");
end

%% Graphs %%

%****************** LAT *******************
figure(2)
plot(time_log_rk4(:,1), y_log_rk4(:,4)*(180/pi),'color','b','linewidth',2)
hold on
grid on
title('phi vs t')
xlabel('time [s]')
ylabel('delta phi [deg]')
