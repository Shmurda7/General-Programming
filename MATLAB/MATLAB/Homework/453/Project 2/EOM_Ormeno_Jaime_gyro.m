function qdot = EOM_Ormeno_Jaime_gyro(t, q)
%% Initial Mass Properties
%Givens
m = 1000;
Ixx = 500;
Iyy = 1500;
Izz = 1500;
Ixz = 0;

%Inertial Matrix
I = [Ixx, 0,-Ixz;
      0, Iyy, 0;
    -Ixz, 0, Izz]; 


%% Mapping Out
%unpack state from the q state column vector
Vb = q(1:3);
omega = q(4:6);
EA = q(7:9);
pos = q(10:12);

%decompose the variables for use in the later calcuations
%velocity variables
u = Vb(1);
v = Vb(2);
w = Vb(3);

%euler angle variables
phi = EA(1);
theta = EA(2);
psi = EA(3);

%% Aero Forces
F_aero_L = 0; %N
F_aero_D = 0; %N

%angle of attack
aoa = atan2(w, u);

%rotation matrix for aero forces and moments
Rot_y_A = [cos(aoa),  0,  -sin(aoa);
              0,      1,       0;
           sin(aoa),  0,   cos(aoa)];

F_aero_s = [-F_aero_D, 0, -F_aero_L]';
F_aero_b = Rot_y_A*F_aero_s;

%% Aero Moments
%Givens
tau = 50; %Nm
L_am = 0; %Nm
M_am = tau*cos(phi); %Nm
N_am = -tau*sin(phi); %Nm


%moment in the stability frame as a column vector
%Moment_s = [M_aero_L, M_aero_M, M_aero_N]'; 
%moment in the body frame as a column vector
%Moment_b = Rot_y_A*Moment_s;
Moment_b = [L_am, M_am, N_am]';

%% Thrust Misalignment
%Given
Thrust = 2000; %N
%thrust misalignment
Yaw_mis = 0.1 * (pi / 180); %deg -> rad
Pitch_mis = -0.5 * (pi / 180); %deg -> rad
Roll_mis = 0; %rad

%rotation matrices 3,2,1 for thrust variables
Rot_z_T = [ cos(Yaw_mis)   sin(Yaw_mis)     0;
       -sin(Yaw_mis)  cos(Yaw_mis)     0;
          0          0         1];

Rot_y_T = [ cos(Pitch_mis)    0     -sin(Pitch_mis);
          0          1          0;
       sin(Pitch_mis)    0      cos(Pitch_mis)];


Rot_x_T = [ 1         0          0;
       0     cos(Roll_mis)   sin(Roll_mis);
      0    -sin(Roll_mis)   cos(Roll_mis)];

%rotation matrix for body frame to thrust frame
R_B2T = Rot_x_T*Rot_y_T*Rot_z_T;
%thrust in the thurst frame
F_thrust_t = [Thrust, 0, 0]';
%converting thrust frame to body frame
F_thrust_b = R_B2T'*F_thrust_t;


%% Euler2Body
%roation matrcies 3,2,1 for euler angles
Rot_z_E = [ cos(psi)   sin(psi)     0;
           -sin(psi)   cos(psi)     0;
               0          0         1];

Rot_y_E = [ cos(theta)    0      -sin(theta);
                0         1           0;
            sin(theta)    0      cos(theta)];
    

Rot_x_E = [ 1         0          0;
            0     cos(phi)   sin(phi);
            0    -sin(phi)   cos(phi)];

%rotation matrix for euler frame to body frame
R_E2B = Rot_x_E*Rot_y_E*Rot_z_E;

%% Force & Moment Sum
%some givens needed
g = 9.81; %m/s^2
W = m*g;

%weight in the euler frame
Weight_E = [0,   0,  W]';
%converting euler frame to body frame
Weight_b = R_E2B*Weight_E;
%total forces acting on the plane
Force_tot = (F_thrust_b + F_aero_b)*0 + Weight_b;

%% Derivatives
%box needed for euler transformation
square = (1/cos(theta)) * [ cos(theta)  sin(phi)*sin(theta)        cos(phi)*sin(theta);
                               0        cos(phi)*cos(theta)       -sin(phi)*cos(theta);
                               0             sin(phi)                     cos(phi)];

%gotten from notes
Vb_dot = Force_tot/m - cross(omega, Vb);
omega_dot = inv(I)*(Moment_b - cross(omega, I*omega));
EA_dot = square*omega;
pos_dot = R_E2B'*Vb; 
%mistake was here ^, from what he went over in class
%originally pos_dot = R_E2B*Vb
%corrected pos_dot = R_E2B'*Vb
%need to transpose the R_E2B to be able to convert the body frame to the
%euler frame for correct position

qdot = [Vb_dot;
        omega_dot;
        EA_dot;
        pos_dot];

end