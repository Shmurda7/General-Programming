clear all
close all
clc

%% Initial Conditions
% define the integration time interval
tf = 2;
tspan = [0 tf];
dt = 0.0001;

% putting together the initial state vector
q0 = [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]';
q0(4) = (20000*2*pi)/60;%rpm -> rad/s

%q0(4) = 20; %can see the precesion with a lower rotational speed

%% using ode45 - I expect this is the default solution
%[t_ode45, q_ode45] = ode45(@EOM_Ormeno_Jaime_gyro, tspan, q0);
%% using RK4 - correct implementation of this results in extra credit
% initialize the integrated parameters
t_rk4 = 0;
q_rk4 = q0;

% initialize output logging
time_log_rk4 = [];
q_log_rk4 = [];

% RK4 integration loop
while t_rk4 <= tf
% output datalogging
time_log_rk4(end+1,:) = t_rk4;
q_log_rk4(end+1,:) = q_rk4';
% calculating the derivatives
k1 = EOM_Ormeno_Jaime_gyro(t_rk4, q_rk4);
k2 = EOM_Ormeno_Jaime_gyro(t_rk4 + dt/2, q_rk4 + k1*dt/2);
k3 = EOM_Ormeno_Jaime_gyro(t_rk4 + dt/2, q_rk4 + k2*dt/2);
k4 = EOM_Ormeno_Jaime_gyro(t_rk4 + dt, q_rk4 + k3*dt);
% calculating the increment of the state vector
dq = (dt/6)*(k1 + 2*k2 + 2*k3 + k4);
% increment the state vector
q_rk4 = q_rk4 + dq;
% increment the integration time - this is super important, failure to
% do this will result in getting stuck in the loop forever
t_rk4 = t_rk4 + dt;
end

%% Analyitical Solution Method
%p0 = (20000*2*pi)/60;
t = 0:0.0001:2;
q_analytical = 50/(500*((20000*2*pi)/60))*t;

%% plots
figure(1)
plot(time_log_rk4(:,1), q_log_rk4(:,9),'color','b','linewidth',2)
hold on
plot(t, q_analytical,'color','r','linewidth',1)
grid on
title('psi vs t')
xlabel('time [s]')
ylabel('psi [rad]')


figure(2)
hold on
plot(time_log_rk4(:,1), q_log_rk4(:,8),'color','b','linewidth',2)
hold on
grid on
title('theta vs t')
xlabel('time [s]')
ylabel('theta [rad]')

