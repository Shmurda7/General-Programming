clear;clc;

%% Problem 1 part a %%
n = 10;
for i = 1:n
    x = [factorial(1*i)];
end

disp(x)




%% Problem 1 part b %%
m = 999;
y = 0;
for ii = 1:m
    y = y + ii;
end

disp(y)


%% Problem 2 %%

    m_initial = 3000;
    m_threshold = 100;
    t = 0;

    % Define the function handle for dm/dt
    dm_dt = @(t, m) -(3 + (t / 10)^2 * exp(-0.1 * t));

    % Initialize a tolerance value for mass comparison
    tolerance = 1e-6;

    while t < 1000 % Maximum time limit to prevent an infinite loop
        % Use ode45 to numerically integrate the differential equation
        [t_new, m_new] = ode45(@(t, m) dm_dt(t, m), [t, t + 0.01], m_initial);

        % Update time and mass values
        t = t_new(end);
        m_initial = m_new(end);

        if m_initial < m_threshold + tolerance
            break; % Exit the loop if mass goes below the threshold
        end
    end

    fprintf('Time when water mass goes below 100 kg: %.4f seconds\n', t);
    fprintf('Final water mass at that time: %.4f kg\n', m_initial);

%% Problem 3 %%
% Define the function
syms t;
y = (t/10)^2 * exp(-0.1*t);

% Differentiate the function
y_prime = diff(y, t);

% Find critical points by solving the derivative equation
critical_points = solve(y_prime, t);

% Evaluate the second derivative at critical points to determine maxima
max_points = [];
for i = 1:length(critical_points)
    second_derivative = subs(diff(y_prime, t), t, critical_points(i));
    if second_derivative < 0  % Checking for concavity
        max_points = [max_points; [critical_points(i), subs(y, t, critical_points(i))]];
    end
end

% Find the maximum point from the identified maxima
[max_y, max_index] = max(max_points(:, 2));
max_t = double(max_points(max_index, 1)); % Convert symbolic value to numeric

disp('Maximum point:');
disp(['t = ', char(max_t)]);
disp(['y = ', char(max_y)]);



