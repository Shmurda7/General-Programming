clear;clc; close all

%% ******** Initial Conditions **********
%time
tf = 30; %s
dt = 0.01; %s

%givens
%position
x = 0;
y = 0;
z = 0;
xyz = [x;y;z];

%velocity
xdot = 0;
ydot = 0;
zdot = 0;
xyzdot = [xdot;ydot;zdot];

%euler angles
phi = 0;
theta = 0;
psi = 0;
ptp = [phi; theta; psi];

%body rates
p = 0;
q = 0;
r = 0;
pqr = [p; q; r];

state = [xyz; xyzdot; ptp; pqr];

%% ************** RK4 Integration ********************
% initialize the integrated parameters
t_rk4 = 0;
state_rk4 = state;

% initialize output logging
time_log_rk4 = [];
state_log_rk4 = [];

% RK4 integration loop
while t_rk4 <= tf
    % output datalogging
    time_log_rk4(end+1,:) = t_rk4;
    state_log_rk4(end+1,:) = state_rk4';

    % calculating the derivatives
    k1 = EOM_CubeSat(t_rk4, state_rk4);
    k2 = EOM_CubeSat(t_rk4 + dt/2, state_rk4 + k1*dt/2);
    k3 = EOM_CubeSat(t_rk4 + dt/2, state_rk4 + k2*dt/2);
    k4 = EOM_CubeSat(t_rk4 + dt, state_rk4 + k3*dt);

    % calculating the increment of the state vector
    dstate = (dt/6)*(k1 + 2*k2 + 2*k3 + k4);

    % increment the state vector
    state_rk4 = state_rk4 + dstate;

    % increment the integration time - this is super important, failure to
    % do this will result in getting stuck in the loop forever
    t_rk4 = t_rk4 + dt;
end

