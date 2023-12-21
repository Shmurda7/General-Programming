clear; clc; close all;

%% Initial Conditions
%time
tf = 100;
tspan = [0 tf];
dt = 0.1;

%givens for T-37 Dragonfly (trainer) for Longitudinal Motion
%speed of sound
delta_u = 0; %ft/s
delta_q_long = 0; %deg/s
delta_theta = 0; %deg
delta_a = 0; %deg

% putting together the initial state vector
x0 = [delta_u, delta_a, delta_q_long, delta_theta]';
%u0 = 0;


%% using RK4 - correct implementation of this results in extra credit
% initialize the integrated parameters
t_rk4 = 0;
x_rk4 = x0;
%u_rk4 = u0;

% initialize output logging
time_log_rk4 = [];
x_log_rk4 = [];
%u_log = [];


% RK4 integration loop
for ii = t_rk4:dt:tf
%**************** Long *****************
% output datalogging
time_log_rk4(end+1,:) = t_rk4;
%u_log(:,end+1) = u_rk4;
x_log_rk4(end+1,:) = x_rk4';
% calculating the derivatives
k1_long = EOM_long_control(x_rk4);
k2_long = EOM_long_control(x_rk4 + k1_long*dt/2);
k3_long = EOM_long_control(x_rk4 + k2_long*dt/2);
k4_long = EOM_long_control(x_rk4 + k3_long*dt);
% calculating the increment of the state vector
dx = (dt/6)*(k1_long + 2*k2_long + 2*k3_long + k4_long);
% increment the state vector
x_rk4 = x_rk4 + dx;

% calculating the increment of the state vector
%du = k4_long(:,1);
% increment the state vector
%u_rk4 = u_rk4 + du;

t_rk4 = t_rk4 + dt;

waitbar(ii/tf,waitbar(0), "Progress (" +ii+ "/" + tf + ")");
end

%% Graphs %%
%***************** LONG ******************
% figure(1)
% plot(time_log_rk4, u_log*(180/pi),'color','b','linewidth',2)
% hold on
% grid on
% title('deflection elevator')
% xlabel('time [s]')
% ylabel('de [deg]')

figure(2);
plot(time_log_rk4(:,1), x_log_rk4(:,4)*(180/pi),'color','b','linewidth',2)
hold on
grid on
title('theta vs t')
xlabel('time [s]')
ylabel('delta theta [deg]')

