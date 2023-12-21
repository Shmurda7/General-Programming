clear; clc; close all
%************* Earth ***************
planet

%*********** Initial **************
%initial states
altitude = 500*1000; %km to m
h = altitude + R; %m

x = 0;
y = 0;
z = h;
xyz = [x;y;z];

%orbit parameters
inclination = 56*(pi/180); %deg to rad
semi_major = norm(xyz);
vcircular = sqrt(mu/semi_major);

xdot = vcircular*cos(inclination);
ydot = vcircular*sin(inclination);
zdot = 0;
xyzdot = [xdot;ydot;zdot];

phi = 0;
theta = 0;
psi = 0;
ptp = [phi;theta;psi];

P = 0;
Q = 0;
R = 0;
PQR = [P;Q;R];

state = [xyz;xyzdot;ptp;PQR];

%time
period = 2*(pi/sqrt(mu)*semi_major^(3/2));