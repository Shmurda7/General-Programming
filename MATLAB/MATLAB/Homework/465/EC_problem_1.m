clear;clc;

E = 210*10^9; %Pa
v = 0.3; 
t = 5/1000; %m

length = 500/1000; %m
height = 250/1000; %m

theta = 30; %deg

force = 40*1000; %N

%% part a Q4 Method

x = .083;
y = .125;

b = 0.25;
h = 0.125;

B_matrix = (1/(4*b*h))*[-(h-y), 0, (h-y), 0, (h+y), 0, -(h+y), 0;
                        0, -(b-x), 0, -(b+x), 0, (b+x), 0, (b-x);
                        -(b-x), -(h-y), -(b+x), (h-y), (b+x), (h+y), (b-x), -(h+y);];

C_matrix = (E/(1-(v)^2))*[1, v, 0;
                          v, 1, 0;
                          0, 0, (1-v)/2;];

k_non = @(b) (B_matrix.'*C_matrix*B_matrix);

K_matrix = @(h) integral(k_non, -b, b, 'ArrayValued',true);

k_for_two = integral(K_matrix, -h, h, 'ArrayValued',true);

K_two_matrix = t*k_for_two;

K_MATRIX = [0.3583, 0;
            0, 1.0236];

%Finding the force
Fx = force*cos(theta);
Fy = force*sin(theta);

%Finding the displacement
F = [Fx;
     Fy;];

d = K_MATRIX^-1*F;

displacement = [0;
                0;
                1.722*10^-4;
                -3.8610*10^-4;
                0;
                0;
                0;
                0];

eta = B_matrix*displacement;

sigma = C_matrix*eta
