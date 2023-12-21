clear all
close all
%% Initial Conditions
%time
tf = 30;
tspan = [0 tf];
dt = 0.01;

%givens
%speed of sound
soa = 343; %m/s
Machx = 0.5;

% putting together the initial state vector
q0 = [ Machx*soa, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]';
%% using ode45 - I expect this is the default solution
[t_ode45, q_ode45] = ode45(@EOM_Ormeno_Jaime, tspan, q0);
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
k1 = EOM_Ormeno_Jaime(t_rk4, q_rk4);
k2 = EOM_Ormeno_Jaime(t_rk4 + dt/2, q_rk4 + k1*dt/2);
k3 = EOM_Ormeno_Jaime(t_rk4 + dt/2, q_rk4 + k2*dt/2);
k4 = EOM_Ormeno_Jaime(t_rk4 + dt, q_rk4 + k3*dt);
% calculating the increment of the state vector
dq = (dt/6)*(k1 + 2*k2 + 2*k3 + k4);
% increment the state vector
q_rk4 = q_rk4 + dq;
% increment the integration time - this is super important, failure to
% do this will result in getting stuck in the loop forever
t_rk4 = t_rk4 + dt;
end

%% plots
%first plots for U, V, W, velocity of the plane
%plot the U velocity
figure(1)
subplot(2,2,1);
plot(time_log_rk4(:,1), q_log_rk4(:,1),'color','b','linewidth',2)
hold on
plot(t_ode45, q_ode45(:,1),'color', 'r')
grid on
title('U vs t')
xlabel('time [s]')
ylabel('U [m/s]')
%plot the V velocity
subplot(2,2,2);
plot(time_log_rk4(:,1), q_log_rk4(:,2),'color','b','linewidth',2)
hold on
plot(t_ode45, q_ode45(:,2),'color', 'r')
grid on
title('V vs t')
xlabel('time [s]')
ylabel('V [m/s]')
%plot the W velocity
subplot(2,2,3);
plot(time_log_rk4(:,1), q_log_rk4(:,3),'color','b','linewidth',2)
hold on
plot(t_ode45, q_ode45(:,3),'color', 'r')
grid on
title('W vs t')
xlabel('time [s]')
ylabel('W [m/s]')
legend('RK4','ODE45','location','bestoutside');

%second plots for P, Q, R, omega of the plane
%plot the P 
figure(2)
hold on
subplot(2,2,1);
plot(time_log_rk4(:,1), q_log_rk4(:,4),'color','b','linewidth',2)
hold on
plot(t_ode45, q_ode45(:,4),'color', 'r')
grid on
title('P vs t')
xlabel('time [s]')
ylabel('P [rad/s]')
%plot the Q
subplot(2,2,2);
plot(time_log_rk4(:,1), q_log_rk4(:,5),'color','b','linewidth',2)
hold on
plot(t_ode45, q_ode45(:,5),'color', 'r')
grid on
title('Q vs t')
xlabel('time [s]')
ylabel('Q [rad/s]')
%plot the R 
subplot(2,2,3);
plot(time_log_rk4(:,1), q_log_rk4(:,6),'color','b','linewidth',2)
hold on
plot(t_ode45, q_ode45(:,6),'color', 'r')
grid on
title('R vs t')
xlabel('time [s]')
ylabel('R [rad/s]')
legend('RK4','ODE45','location','bestoutside');

%third plots for Euler angles
%plot euler phi
figure(3)
hold on
subplot(2,2,1);
plot(time_log_rk4(:,1), q_log_rk4(:,7),'color','b','linewidth',2)
hold on
plot(t_ode45, q_ode45(:,7),'color', 'r')
grid on
title('phi vs t')
xlabel('time [s]')
ylabel('phi [rad]')
%plot euler theta
subplot(2,2,2);
plot(time_log_rk4(:,1), q_log_rk4(:,8),'color','b','linewidth',2)
hold on
plot(t_ode45, q_ode45(:,8),'color', 'r')
grid on
title('theta vs t')
xlabel('time [s]')
ylabel('theta [rad]')
%plot euler psi
subplot(2,2,3);
plot(time_log_rk4(:,1), q_log_rk4(:,9),'color','b','linewidth',2)
hold on
plot(t_ode45, q_ode45(:,9),'color', 'r')
grid on
title('psi vs t')
xlabel('time [s]')
ylabel('psi [rad]')
legend('RK4','ODE45','location','bestoutside');