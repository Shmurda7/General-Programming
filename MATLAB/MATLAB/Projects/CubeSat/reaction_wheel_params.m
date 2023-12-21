%%%using blue canyon reaction wheels
mr = 0.13; %mass of RW
rr = 42/1000; %radius in mm to m
hr = 19/1000; %height in mm to m

%%% Max Speeds
rpm = 8000; %rpm
maxSpeed = rpm*2*pi/60; %rad/s

%Maximum Torque
maxTorque = 0.004; %Nm

%%%power consumption parameters
dc_voltage = 5; % (V) from random RW
peack_power = 3.25; %(W)

%%% gonna have 3 reactions wheels
%%% orientation of the reaciton wheel, below is for each wheel
%%%% reaction wheels are all along the principle axis of inertia
n1 = [1;0;0]; %rot about x
n2 = [0;1;0]; %rot about y
%n3 = [0;0;1]; %rot about z
%%% one RW is angled
%%% one wheel about the x axis and one for y axis and other 45deg angle for
%%% in between those axis, need to make sure it's a unit vector and when
%%% making reactions wheels need to make sure you have a traid
n3 = [1;1;1];
n3 = n3/norm(n3);


%%% Move the RW  a bit from the cg
%%%size of cubesat in probably 10
%%% moved closer to the cg
r1 = [4;0;0]/1000; %mm to m
r2 = [0;4;0]/1000;
r3 = [0;0;4]/1000;

%originally
% r1 = [20;0;0]/1000; %mm to m
% r2 = [0;20;0]/1000;
% r3 = [0;0;20]/1000;

Iother = (1/2)*rr^2;
Idisk = (1/12)*(3*rr^2+hr^2); % moment of inertia

IrR = mr*[Iother   0      0; %mass moment of intertia 
          0      Idisk    0; 
          0       0     Idisk]; %inertia of RW in RW frame

%%%compute max angular acceleration
maxAlpha = maxTorque/IrR(1,1); %N-m

%%%comput power consumption ratio
Power2Alpha = peack_power/maxAlpha; %W/rad/s^2
Amps2Alpha = Power2Alpha/dc_voltage; % Amps/rad/s^2

%%% Transformation from RW frame to body frame of satellite
T1 = Rscrew(n1);
T2 = Rscrew(n2);
T3 = Rscrew(n3);
%%% compute inertia of reaction wheel in body frame of satellite
Ir1B = T1'*IrR*T1; %inertia of the 1nd RW in the body frame of the satellite
Ir2B = T2'*IrR*T2; %inertia of the 2nd RW in the body frame of the satellite
Ir3B = T3'*IrR*T3; %inertia of the 3nd RW in the body frame of the satellite

%%%% Comput J for control
J = [Ir1B*n1,Ir2B*n2,Ir3B*n3];
Jinv = inv(J'*J)*J'; %if using 3 reaction wheels use this one
%Jinv = J'*(inv(J*J')); %use this if using more than 3 reation wheels

%%%Compute the inertia of the RW in the body frame in ref to the cg of the
%%%satellite
%typically when moving a RW you also move the cg slightly, assumption made
%here is the cg is already account for theat (composite cg)
%%%which mean we need to use the parallel axis theorem
sr1 = skew(r1);
Ir1Bcg = Ir1B + mr*(sr1')*sr1;
sr2 = skew(r2);
Ir2Bcg = Ir2B + mr*(sr2')*sr2;
sr3 = skew(r3);
Ir3Bcg = Ir3B + mr*(sr3')*sr3;