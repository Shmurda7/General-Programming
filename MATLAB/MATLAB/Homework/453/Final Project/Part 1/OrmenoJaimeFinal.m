clear;clc; close all;

%% Initial Conditions
%time
tf = 100;
tspan = [0 tf];
dt = 0.01;

%givens for T-37 Dragonfly (trainer) for Longitudinal Motion
%speed of sound
delta_u = 0; %ft/s
delta_q_long = 0; %deg/s
delta_theta = 1*(pi/180); %deg
delta_a = 1*(pi/180); %deg

% putting together the initial state vector
x0 = [delta_u, delta_a, delta_q_long, delta_theta]';

%givens for T-37 Dragonfly (trainer) for Lateral Motion
%speed of sound
delta_p_lat = 0; %ft/s
delta_r = 0; %deg/s
delta_beta = 1*(pi/180); %deg
delta_phi = 1*(pi/180); %deg

% putting together the initial state vector
y0 = [delta_beta, delta_p_lat, delta_r, delta_phi]';



%% using RK4 - correct implementation of this results in extra credit
% initialize the integrated parameters
x_rk4 = x0;

% initialize the integrated parameters
t_rk4 = 0;
y_rk4 = y0;


% initialize output logging
time_log_rk4 = [];
x_log_rk4 = [];
y_log_rk4 = [];


% RK4 integration loop
while t_rk4 <= tf
%**************** Long *****************
% output datalogging
x_log_rk4(end+1,:) = x_rk4';
% calculating the derivatives
k1_long = EOM_LONG(x_rk4);
k2_long = EOM_LONG(x_rk4 + k1_long*dt/2);
k3_long = EOM_LONG(x_rk4 + k2_long*dt/2);
k4_long = EOM_LONG(x_rk4 + k3_long*dt);
% calculating the increment of the state vector
dx = (dt/6)*(k1_long + 2*k2_long + 2*k3_long + k4_long);
% increment the state vector
x_rk4 = x_rk4 + dx;

%*************** Lateral ***************
% output datalogging
time_log_rk4(end+1,:) = t_rk4;
y_log_rk4(end+1,:) = y_rk4';
% calculating the derivatives
k1_lat = EOM_LAT(y_rk4);
k2_lat = EOM_LAT(y_rk4 + k1_lat*dt/2);
k3_lat = EOM_LAT(y_rk4 + k2_lat*dt/2);
k4_lat = EOM_LAT(y_rk4 + k3_lat*dt);
% calculating the increment of the state vector
dy = (dt/6)*(k1_lat + 2*k2_lat + 2*k3_lat + k4_lat);
% increment the state vector
y_rk4 = y_rk4 + dy;
% increment the integration time - this is super important, failure to
% do this will result in getting stuck in the loop forever
t_rk4 = t_rk4 + dt;
end

%% Graphs %%
%***************** LONG ******************
figure(1)
subplot(2,2,1);
plot(time_log_rk4(:,1), x_log_rk4(:,1),'color','b','linewidth',2)
hold on
grid on
title('x-velocity (delta u) [ft/s]')
xlabel('time [s]')
ylabel('delta u [ft/s]')
subplot(2,2,2);
plot(time_log_rk4(:,1), x_log_rk4(:,2),'color','b','linewidth',2)
hold on
grid on
title('angle of attack (delta a) [deg]')
xlabel('time [s]')
ylabel('delta a [deg]')
subplot(2,2,3);
plot(time_log_rk4(:,1), x_log_rk4(:,3)*(180/pi),'color','b','linewidth',2)
hold on
grid on
title('pitch rate (delta p) [deg/s]')
xlabel('time [s]')
ylabel('delta q [deg/s]')
subplot(2,2,4);
plot(time_log_rk4(:,1), x_log_rk4(:,4)*(180/pi),'color','b','linewidth',2)
hold on
grid on
title('pitch (delta theta) [deg]')
xlabel('time [s]')
ylabel('delta theta [deg]')

figure(4)
plot(x_log_rk4(:,4)*(180/pi), x_log_rk4(:,3)*(180/pi),'color','b','linewidth',2)
hold on
grid on
title('phase portrait: delta p vs. delta theta')
xlabel('delta q [deg/s]')
ylabel('delta theta [deg]')

%****************** LAT *******************

figure(2)
subplot(2,2,1);
plot(time_log_rk4(:,1), y_log_rk4(:,1),'color','b','linewidth',2)
hold on
grid on
title('sideslip (delta b) [deg]')
xlabel('time [s]')
ylabel('delta beta [deg]')
subplot(2,2,2);
plot(time_log_rk4(:,1), y_log_rk4(:,2),'color','b','linewidth',2)
hold on
grid on
title('roll rate (delta p) [deg/s]')
xlabel('time [s]')
ylabel('delta p [deg/s]')
subplot(2,2,3);
plot(time_log_rk4(:,1), y_log_rk4(:,3)*(180/pi),'color','b','linewidth',2)
hold on
grid on
title('yaw rate (delta r) [deg/s]')
xlabel('time [s]')
ylabel('delta r [deg/s]')
subplot(2,2,4);
plot(time_log_rk4(:,1), y_log_rk4(:,4)*(180/pi),'color','b','linewidth',2)
hold on
grid on
title('roll (delta phi) [deg]')
xlabel('time [s]')
ylabel('delta phi [deg]')

figure (3)
plot(y_log_rk4(:,1)*(180/pi), y_log_rk4(:,4)*(180/pi),'color','b','linewidth',2)
hold on
grid on
title('phase portrait: delta phi vs. delta b')
xlabel('beta [deg]')
ylabel('delta phi [deg]')



