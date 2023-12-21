clear;clc; close all
% Longitudinal Derivatives
%given from the tables
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

g = 32.2; %ft/s2


%******** Motion *************
A1 = [        Xu                 Xa                   0         -g*cos(theta);
            Zu/U1               Za/U1                1        (-g*sin(theta)/U1);
      Mu + (Madot/U1)*Zu  Ma + Madot*(Za/U1)     Mq + Madot         0;
             0                  0                    1              0];

%getting the eigen values of the A matrix
eigen_v = eig(A1)

%check criteria 1
crt_1 = poly(A1)

AA = crt_1(1);
BB = crt_1(2);
CC = crt_1(3);
DD = crt_1(4);
EE = crt_1(5);

%check criteria 2
crt_2 = BB*CC*DD - AA*DD^2 - BB^2*EE

%short period mode
n_SP = -4.4835; %amplitude
omega_SP = 4.2261; %oscillation frequency

%phugoid mode
n_PH = -0.0079; %amplitude
omega_PH = 0.1137; %oscillation frequency

%since it's stable it's time to half
%time to half if stable
%short period mode time to half
t_half_SP = log(2)/abs(n_SP)

%phugoid mode time to to half
t_half_PH = log(2)/abs(n_PH)
