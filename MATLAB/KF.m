% Define the state-space model
A = [1 1; 0 1];  % State transition matrix
B = [0.5; 1];    % Control input matrix (if applicable)
H = [1 0];       % Measurement matrix
Q = [0.02 0; 0 0.02];  % Process noise covariance
R = 1.5;           % Measurement noise covariance

% Initialize the initial state estimate and covariance
x_hat = [0; 0];   % Initial state estimate
P = eye(2);       % Initial state covariance

% Initialize the initial state
true_state(:, 1) = [0; 0];  % Initial state at t = 1

% Simulate measurements (replace this with your actual measurements)
T = 100;          % Number of time steps
measurements = zeros(1, T);

for t = 2:T  % Start the loop at t = 2 since t = 1 is already initialized
    % Simulate the true state dynamics (replace this with your system model)
    true_state(:, t) = A * true_state(:, t-1) + sqrt(Q) * randn(2, 1);
    
    % Simulate a noisy measurement (replace this with your measurement model)
    measurements(t) = H * true_state(:, t) + sqrt(R) * randn;
    
    % Kalman filter prediction step
    x_hat_minus = A * x_hat;
    P_minus = A * P * A' + Q;
    
    % Kalman filter update step
    K = P_minus * H' / (H * P_minus * H' + R);
    x_hat = x_hat_minus + K * (measurements(t) - H * x_hat_minus);
    P = (eye(2) - K * H) * P_minus;
    
    % Store the estimated state
    estimated_state(:, t) = x_hat;
end


% Plot the true state, measurements, and estimated state
figure;
subplot(2,1,1);
plot(true_state(1,:), 'b', 'LineWidth', 2);
hold on;
plot(measurements, 'r.', 'MarkerSize', 10);
plot(estimated_state(1,:), 'g', 'LineWidth', 2);
xlabel('Time Step');
ylabel('Position');
legend('True State', 'Measurements', 'Estimated State');
title('Position Estimation');
sdf
sd
s
d
sd
sd

subplot(2,1,2);
plot(true_state(2,:), 'b', 'LineWidth', 2);
hold on;
plot(estimated_state(2,:), 'g', 'LineWidth', 2);
xlabel('Time Step');
ylabel('Velocity');
legend('True State', 'Estimated State');
title('Velocity Estimation');

