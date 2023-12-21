function xdot = EOM_LONG(x)

%% Initial Mass & Geometry Properties
%Givens
W = 6360; %lb
g = 32.2; %ft/s2
Ixx = 7.99e3; %slug ft2
Iyy = 3.33e3; %slug ft2
Izz = 1.12e4; %slug ft2
Ixz = -3.91e1; %slug ft2

m = W/32.2; %lb

%Inertial Matrix
I = [Ixx, 0,-Ixz;
      0, Iyy, 0;
    -Ixz, 0, Izz]; 

S = 182; %ft2
b = 33.8; %ft
c_hat = 5.47; %ft
x_cg = 27; 
trim_aoa = 0.7; %deg

%% Longitudinal Derivatives
Xu = -0.0168;
Xa = 14.8205;
Zu = -0.1844;
Za = -645.1571;
Mu = 0;
Ma = -28.9722;
Madot = -2.2569;
Mq = -4.8604;
Xde = 0;
Zde = -53.4070;
Mde = -46.4075;
theta = 0;
U1 = 349;

%% Mapping Out Longitudinal Motion
%unpack state from the q state column vector
x = x(1:4);

%******** Motion *************
A1 = [        Xu                 Xa                   0         -g*cos(theta);
            Zu/U1               Za/U1                1        (-g*sin(theta)/U1);
      Mu + (Madot/U1)*Zu  Ma + Madot*(Za/U1)     Mq + Madot         0;
             0                  0                    1              0];


%******** Control *************
% B1 = [    Xde;
%          Zde/U1;
%       Mde + (Madot/U1)*Zde;
%            0];
% 
% u = delta_de;
 
xdot = A1*x;
end
