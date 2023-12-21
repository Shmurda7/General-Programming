function qdot = EOM_Ormeno_Jaime(t, q)

%% Initial Mass Properties %%
m = 1000; %kg
Ixx = 500; %kgm^2
Iyy = 1500; %kgm^2
Izz = 1800; %kgm^2
Ixz = -800; %kgm^2

g = 9.81; %m/s^2

W = m*g;
%% Dynamic Conditions %%
% Aero Force
L_af = 10000; %N
D_af = 1000; %N

%Thrust
%convert to rads for calculations
T_mag = 2000; %N
Yaw_mis = 0.1 * (pi / 180); %deg
Pitch_mis = -0.5 * (pi / 180); %deg
Roll_mis = 0;

R3t = [ cos(Yaw_mis)   sin(Yaw_mis)     0;
       -sin(Yaw_mis)  cos(Yaw_mis)     0;
          0          0         1];

R2t = [ cos(Pitch_mis)    0     -sin(Pitch_mis);
          0          1          0;
       sin(Pitch_mis)    0      cos(Pitch_mis)];


R1t = [ 1         0          0;
       0     cos(Roll_mis)   sin(Roll_mis);
      0    -sin(Roll_mis)   cos(Roll_mis)];


R_b2th = R1t*R2t*R3t;
%no good
R_b2th_bet = angle2dcm(Yaw_mis, Pitch_mis, 0, 'ZYX');

%unpack state
Vb = q(1:3);
omega = q(4:6);
EA = q(7:9);
pos = q(10:12);

%decompose
Vbx = Vb(1);
Vby = Vb(2);
Vbz = Vb(3);

phi = EA(1);
theta = EA(2);
psi = EA(3);

%Inertial Matrix
I = [Ixx, 0, -Ixz;
       0, Iyy, 0;
       -Ixz, 0, Izz];


%Aero Moments
L_am = 10 * cos(0.25 * t); %Nm
M_am = 10 * sin(0.1 * t); %Nm
N_am = -5; %Nm


%stability frame moment
Moment_s = [L_am, M_am, N_am]'; %here
aoa = atan2(Vbz, Vbx);

M_s2b = [cos(aoa),  0,  -sin(aoa);
            0,      1,        0;
         sin(aoa),  0,   cos(aoa)];

Faero_s = [-D_af, 0, -L_af]'; %here
Faero_b = M_s2b*Faero_s;

Fthrust_thr = [T_mag, 0, 0]'; %here
Fthrust_b = R_b2th'*Fthrust_thr;
Moment_b = M_s2b*Moment_s;

invD = [ 1         sin(phi)*tan(theta)        cos(phi)*tan(theta);
         0              cos(phi)                    -sin(phi);
         0         sin(phi)*sec(theta)        cos(phi)*sec(theta)];

R3 = [ cos(psi)   sin(psi)     0;
       -sin(psi)  cos(psi)     0;
          0          0         1];

R2 = [ cos(theta)    0      -sin(theta);
          0          1          0;
       sin(theta)    0      cos(theta)];


R1 = [ 1         0          0;
       0     cos(phi)   sin(phi);
       0    -sin(phi)   cos(phi)];


R_E2B = R1*R2*R3;

Weight_Vector_E = [0,   0,  W]';
Force = (Fthrust_b + Faero_b)*1 + 1*(R_E2B*Weight_Vector_E);

Vb_dot = Force/m - cross(omega, Vb);
omega_dot = inv(I)*(Moment_b - cross(omega, I*omega));
EA_dot = invD*omega;
pos_dot = R_E2B'*Vb;

qdot = [Vb_dot;
        omega_dot;
        EA_dot;
        pos_dot];

