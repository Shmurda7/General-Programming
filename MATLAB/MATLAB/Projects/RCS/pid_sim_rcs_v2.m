clear all
close all
%% Initial Conditions
%time
tf = 30;
tspan = [0 tf];
dt = 0.01;

%givens
rot = (240*2*pi)/60;%rpm -> rad/s

% putting together the initial state vector
rcs0 = [ 0, 0, 0, rot, 0, 0, 0, 0, 0, 0, 0, 0]';

% Target motion
target = [ 0, 0, 0]';

%% using PID
% Constants for PID controller
Kp = 1;  % Proportional gain
Ki = 0.1; % Integral gain
Kd = 0.01; % Derivative gain

% Initialize PID controller variables
integral = 0;
prev_error = 0;

% initialize the integrated parameters
t_pid = 0;
rcs_pid = rcs0;

% initialize output logging
time_log_pid = [];
rcs_log_pid = [];


% pid integration loop
while t_pid <= tf
    % output datalogging
    time_log_pid(end+1,:) = t_pid;
    rcs_log_pid(end+1,:) = rcs_pid';

    % Extract relevant state variables
    rcs_angle = rcs_pid(7); % Euler angle phi
    rcs_rate = rcs_pid(4); % Angular velocity P

     % Calculate PID control signal
    error = target(1) - rcs_angle;
    integral = integral + error * dt;
    derivative = (error - prev_error) / dt;
    control_signal = Kp * error + Ki * integral + Kd * derivative;

    % Apply the control signal to adjust angular velocity
    rcs_rate = rcs_rate + control_signal;

    % Update state variables using the derivatives
    rcs_angle = rcs_angle + rcs_rate * dt;  % Update the angle using the constant velocity

    % Update time and error
    prev_error = error;
    t_pid = t_pid + dt;

    % Update the state vector for integration
    rcs_pid(4) = rcs_rate;
    rcs_pid(7) = rcs_angle;
end

%% plots
%first plots for U, V, W, velocity of the plane
%plot the U velocity
figure(1)
subplot(2,2,1);
plot(time_log_pid(:,1), rcs_log_pid(:,1),'color','b','linewidth',2)
hold on
grid on
title('U vs t')
xlabel('time [s]')
ylabel('U [m/s]')
%plot the V velocity
subplot(2,2,2);
plot(time_log_pid(:,1), rcs_log_pid(:,2),'color','b','linewidth',2)
hold on
grid on
title('V vs t')
xlabel('time [s]')
ylabel('V [m/s]')
%plot the W velocity
subplot(2,2,3);
plot(time_log_pid(:,1), rcs_log_pid(:,3),'color','b','linewidth',2)
hold on
grid on
title('W vs t')
xlabel('time [s]')
ylabel('W [m/s]')

%second plots for P, rcs, R, omega of the plane
%plot the P 
figure(2)
hold on
subplot(2,2,1);
plot(time_log_pid(:,1), rcs_log_pid(:,4),'color','b','linewidth',2)
hold on
grid on
title('P vs t')
xlabel('time [s]')
ylabel('P [rad/s]')
%plot the rcs
subplot(2,2,2);
plot(time_log_pid(:,1), rcs_log_pid(:,5),'color','b','linewidth',2)
hold on
grid on
title('rcs vs t')
xlabel('time [s]')
ylabel('V [rad/s]')
%plot the R 
subplot(2,2,3);
plot(time_log_pid(:,1), rcs_log_pid(:,6),'color','b','linewidth',2)
hold on
grid on
title('R vs t')
xlabel('time [s]')
ylabel('R [rad/s]')

%third plots for Euler angles
%plot euler phi
figure(3)
hold on
subplot(2,2,1);
plot(time_log_pid(:,1), rcs_log_pid(:,7),'color','b','linewidth',2)
hold on
grid on
title('phi vs t')
xlabel('time [s]')
ylabel('phi [rad]')
%plot euler theta
subplot(2,2,2);
plot(time_log_pid(:,1), rcs_log_pid(:,8),'color','b','linewidth',2)
hold on
grid on
title('theta vs t')
xlabel('time [s]')
ylabel('theta [rad]')
%plot euler psi
subplot(2,2,3);
plot(time_log_pid(:,1), rcs_log_pid(:,9),'color','b','linewidth',2)
hold on
grid on
title('psi vs t')
xlabel('time [s]')
ylabel('psi [rad]')