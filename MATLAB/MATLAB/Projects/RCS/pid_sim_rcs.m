clear all; close all; clc;


% Target angle in degrees
target_angle_deg = 0;

% Convert target angle to radians
target_angle = target_angle_deg * pi / 180;

t = 0;
dt = 0.01;  % Time step
tf = 100;   % Total simulation time

angle = 0;       % Initial angle in radians
angle_vel = 400 * (2*pi/60); % Constant angular velocity in radians per second

z_initial = [angle; angle_vel];

%initial conditions
q0 = [0, 0, 0]';

% Create arrays to store data for plotting (optional)
time_array = [];
angle_array = [];
angle_vel_array = [];

% Constants for PID controller
Kp = 1;  % Proportional gain
Ki = 0.1; % Integral gain
Kd = 0.01; % Derivative gain

% Initialize PID controller variables
integral = 0;
prev_error = 0;

while t <= tf
     % Calculate PID control signal
    error = target_angle - angle;
    integral = integral + error * dt;
    derivative = (error - prev_error) / dt;
    control_signal = Kp * error + Ki * integral + Kd * derivative;

    % Apply the control signal to adjust angular velocity
    angle_vel = angle_vel + control_signal;

    % Update state variables using the derivatives
    angle = angle + angle_vel * dt;  % Update the angle using the constant velocity

    % Append data to arrays for plotting (optional)
    time_array = [time_array, t];
    angle_array = [angle_array, angle];
    angle_vel_array = [angle_vel_array, angle_vel];

    % Update time and error
    prev_error = error;
    t = t + dt;
end


% Plot the results (optional)
figure;
subplot(2, 1, 1);
plot(time_array, angle_array);
xlabel('Time');
ylabel('Angle (deg)');
title('Angle vs. Time');

subplot(2, 1, 2);
plot(time_array, angle_vel_array);
xlabel('Time');
ylabel('Angular Velocity (deg/s)');
title('Angular Velocity vs. Time');

