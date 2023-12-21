function ydot = EOM_LAT(y)
%% Initial Mass & Geometry Properties
%Givens
W = 6360; %lb
g = 32.17; %ft/s2
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
trim_state_aoa = 0; %deg 

%% Lat Derivatives
YB = -48.199;
Yp = 0;
Yr = 0;
LB = -9.4992;
Lp = -2.3783;
Lr = 0.3189;
NB = 8.3856;
Np = -0.0594;
Nr = -0.5531;
U1 = 349; %ft/s
theta = 0;


%% Mapping Out Lateral Motion
%unpack state from the q state column vector
y = y(1:4);

%******** Motion *************
A2 = [YB/U1 Yp/U1 -(1-Yr/U1) (g/U1)*cos(theta);
        LB    Lp      Lr             0;
        NB    Np      Nr             0;
        0     1       0              0];


%******** Control *************
% B2 = [0   Ydr;
%       Lda Ldr;
%       Nde Ndr;
%       0    0];
% 
% v = [delta_a;
%      delta_r];

ydot = A2*y;
end