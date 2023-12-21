clear; clc; close all

% Lat Derivatives
%given from the tables
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

g = 32.17; %ft/s2

%******** Motion *************
A2 = [YB/U1 Yp/U1 -(1-Yr/U1) (g/U1)*cos(theta);
        LB    Lp      Lr             0;
        NB    Np      Nr             0;
        0     1       0              0];

eigen_v = eig(A2)


%check criteria 1
crt_1 = poly(A2)

AA = crt_1(1);
BB = crt_1(2);
CC = crt_1(3);
DD = crt_1(4);
EE = crt_1(5);

%check criteria 2
crt_2 = BB*CC*DD - AA*DD^2 - BB^2*EE

n_DR = -0.2897;
omega_DR = 2.9276;

n_R = -2.4791;
omega_R = 0;

n_S = -0.0111;
omega_S = 0;

%since it's stable it's time to half
%time to half if stable
%dutch roll time to half
t_half_DR = log(2)/abs(n_DR)

%roll mode time to half
t_half_R = log(2)/abs(n_R)

%spiral mode time to to half
t_half_S = log(2)/abs(n_S)
