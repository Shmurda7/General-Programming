function [moon, ic, vehicle, rcs] = aero_dap3dofdata(lat_0, lon_0, alt_0, vel_0, flightpath_0, heading_0, libration_rad)
% aero_dap3dofdata - Initialize aero_dap3dof model parameters for the
% Apollo mission phase "Descent Orbit Insertion trajectory (Engine
% cutoff)".

% Copyright 2012-2021 The MathWorks, Inc.

%% Moon Planetary Properties: 
moon.r_moon_eq = 5702428; % Moon equatorial radius [ft]
moon.f_moon    = .0012; % Moon flattening

%% Initial Vehicle States
ic.t_runtime = 120; % (run for first 2 minutes) [s]

% Calculate position in Moon-fixed Mean Earth\Pole Axis (ME) frame
pos_me = convlength(lla2ecef( ...
    [lat_0 lon_0 convlength(alt_0, "ft", "m")], ...
    moon.f_moon, convlength(moon.r_moon_eq, "ft", "m")), ... % use Moon f and Re
    "m", "ft")'; % [ft]
% Compute rotation from ME to inertial frame
dcm_me2inertial = angle2dcm(libration_rad(1), libration_rad(2), libration_rad(3), "ZXZ")';
% Convert to inertial position using libration angles
ic.pos_inertial = (dcm_me2inertial * pos_me)'; % [ft]
% Calculate inertial NED velocity from flight path angle and heading angle
vel_ned_inertial_fps = angle2dcm( ...
    deg2rad(heading_0), deg2rad(flightpath_0), 0, "ZYX") ...
    * [vel_0 0 0]'; % [ft/s]
% Calculate rotation from NED to ME
dcm_ned2me = dcmecef2ned(lat_0, lon_0)';
% Convert inertial velocity from NED to inertial frame
ic.vel_inertial = (dcm_me2inertial * dcm_ned2me * vel_ned_inertial_fps)'; % [ft/s]

% Define initial attitude (NED to Body)
ic.euler_0 = [-30 -10 -60]; % [deg]

%% Vehicle Properties
I1 = 10000; I2 = 100000; I3 = 110000;
vehicle.inertia_0 = diag([I2, I3, I1], 0); % Inertia tensor [slug*ft^2]
vehicle.mass_0    = 33296; % Mass [lb]

%% RCS Properties
rcs.Force  = 100; % RCS jet Force [lbf]
rcs.L_arm  = 5.5; % RCS Jet moment arm [ft]
rcs.DB     = deg2rad(0.345); % Deadband [rad/s^2]
rcs.tmin   = 0.014; % Minimum impulse firing time [s]
rcs.alph1  = rcs.Force * rcs.L_arm / I1; % Yaw axis single jet accel [rad/s^2]
rcs.alph2  = rcs.Force * rcs.L_arm * sqrt(2) / 2 / I2; % Pitch axis single jet accel [rad/s^2]
rcs.alph3  = rcs.Force * rcs.L_arm / I3; % Roll axis single jet accel [rad/s^2]
rcs.alphu  = [sqrt(2) sqrt(2)] / 2 * [rcs.alph2 rcs.alph3]'; % U axis single jet accel [rad/s^2] 
rcs.alphv  = [-sqrt(2) sqrt(2)] / 2 * [rcs.alph2 rcs.alph3]'; % V axis single jet accel [rad/s^2]
rcs.alphs1 = 0.1 * rcs.alph1; % Yaw axis single jet switch curve accel [rad/s^2]
rcs.alphsu = 0.1 * rcs.alphu; % U axis single jet switch curve accel [rad/s^2]
rcs.alphsv = 0.1 * rcs.alphv; % V axis single jet switch curve accel [rad/s^2]

%% RCS Control Clocks
rcs.clockt    = 1/200; % rcs counter [s]
rcs.delt      = .1; % rcs sample time [s]

end