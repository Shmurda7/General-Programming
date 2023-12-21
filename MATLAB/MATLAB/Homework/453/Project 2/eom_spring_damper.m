function zdot = eom_spring_damper(t,z)
%dynamics parameters
k = 1;
c = 1;
m = 1;
% mapping out variables
vx = z(1);
x = z(2);
% actuation force as a function of time
F_actuation = 0.5*sin(0.1*t);
% force from the spring
F_spring = -k*x;
% force from the damper
F_damper = -c*vx;
% total force
F_total = F_actuation + F_spring + F_damper;
vxdot = F_total/m;
xdot = vx;
zdot = [vxdot xdot]';