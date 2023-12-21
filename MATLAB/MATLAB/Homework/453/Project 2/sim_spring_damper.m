clear all
close all
% define the integration time interval
tf = 300;
tspan = [0 tf];
%% setting up the initial conditions
vx0 = 0;
x0 = 0;
% putting together the initial state vector
z0 = [vx0 x0]';
%% using ode45 - I expect this is the default solution
[t_ode45, z_ode45] = ode45(@eom_spring_damper, tspan, z0);
%% using RK4 - correct implementation of this results in extra credit
% define integration timestep
dt = 0.1;
% initialize the integrated parameters
t_rk4 = 0;
z_rk4 = z0;
% initialize output logging
time_array_rk4 = [];
z_output_rk4 = [];
% RK4 integration loop
while t_rk4 <= tf
% output datalogging
time_array_rk4(end+1,:) = t_rk4;
z_output_rk4(end+1,:) = z_rk4';
% calculating the derivatives
k1 = eom_spring_damper(t_rk4, z_rk4);
k2 = eom_spring_damper(t_rk4 + dt/2, z_rk4 + k1*dt/2);
k3 = eom_spring_damper(t_rk4 + dt/2, z_rk4 + k2*dt/2);
k4 = eom_spring_damper(t_rk4 + dt, z_rk4 + k3*dt);
% calculating the increment of the state vector
dz = (dt/6)*(k1 + 2*k2 + 2*k3 + k4);
% increment the state vector
z_rk4 = z_rk4 + dz;
% increment the integration time - this is super important, failure to
% do this will result in getting stuck in the loop forever
t_rk4 = t_rk4 + dt;
end
%% plots
figure(1)
hold on
plot(time_array_rk4(:,1), z_output_rk4(:,1),'color','b','linewidth',3)
plot(t_ode45, z_ode45(:,1),'r')
grid on
title('VX')
xlabel('time [sec]')
ylabel('Vx [m/s]')
legend('RK4','ODE45','location','bestoutside');
figure(2)
hold on
plot(time_array_rk4(:,1), z_output_rk4(:,2),'color','b','linewidth',3)
plot(t_ode45, z_ode45(:,2),'r')
grid on
title('X')
xlabel('time [sec]')
ylabel('x [m]')
legend('RK4','ODE45','location','bestoutside');
