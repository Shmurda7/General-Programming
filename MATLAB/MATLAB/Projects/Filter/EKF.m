% Define the state transition function (nonlinear) and measurement function
% (linearized)
f = @(x, u) x + u;            % State transition function
h = @(x) x^3;                 % Measurement function

% Define the Jacobians of the state transition and measurement functions
df_dx = @(x, u) 1;            % Jacobian of f with respect to x
dh_dx = @(x) 3 * x^2;         % Jacobian of h with respect to x

% Initialize the state and covariance matrix
x = 0;                         % Initial state
P = 1;                         % Initial covariance

% Define process and measurement noise covariances
Q = 0.01;                      % Process noise covariance
R = 0.1;                       % Measurement noise covariance

% Number of time steps
T = 100;

% Generate input and measurement data
u = randn(1, T);               % Process noise
z_true = zeros(1, T);          % True state (for comparison)
z_meas = zeros(1, T);          % Measured state (with noise)
x_est = zeros(1, T);           % Estimated state

for t = 1:T
    % True state propagation (without noise)
    z_true(t) = f(x, 0);
    
    % Measurement with noise
    z_meas(t) = h(z_true(t)) + sqrt(R) * randn();
    
    % EKF prediction step
    x_hat = f(x, u(t));
    P = df_dx(x, u(t)) * P * df_dx(x, u(t))' + Q;
    
    % EKF update step
    K = P * dh_dx(x_hat) / (dh_dx(x_hat) * P * dh_dx(x_hat)' + R);
    x = x_hat + K * (z_meas(t) - h(x_hat));
    P = (1 - K * dh_dx(x_hat)) * P;
    
    % Store the filtered state estimate
    x_est(t) = x;
end

% Plot the results
figure;
plot(1:T, z_true, 'b', 1:T, z_meas, 'r', 1:T, x_est, 'g');
legend('True State', 'Measured State', 'Estimated State');
xlabel('Time Step');
ylabel('State Value');
title('Extended Kalman Filter in MATLAB');


