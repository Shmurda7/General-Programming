function dstatedt = Satellite(t, state)

global BB invI I m mu nextMagUpdate lastMagUpdate lastSensorUpdate maxSpeed
global nextSensorUpdate BfieldMeasured pqrMeasured BfieldNav pqrNav
global BfieldNavPrev pqrNavPrev current Is Ir1Bcg Ir2Bcg Ir3Bcg n1 n2 n3
global maxAlpha Ir1B Ir2B Ir3B ptpMeasured ptpNavPrev ptpNav rwalphas
global fsensor MagFieldBias AngFieldBias EulerBias
global MagFieldNoise AngFieldNoise EulerNoise R Amax lmax CD
%stateinitial = [x0;y0;z0;xdot0;ydot0;zdot0];
x = state(1);
y = state(2);
z = state(3);
% xdot = state(4);
% ydot = state(5);
% zdot = state(6);
q0123 = state(7:10);
ptp = Quaternions2EulerAngles(q0123')';
p = state(11);
q = state(12);
r = state(13);
pqr = state(11:13);
w123 = state(14:16);

%%%inertia and mass
%m = 2.6; %kg  MADE GLOBAL

%translational kinematics
vel = state(4:6);

%rotational kinematics
PQRMAT = [0 -p -q -r; 
          p 0 r -q;
          q -r 0 p;
          r q -p 0];
q0123dot = (1/2)*PQRMAT*q0123;

%Gravity Model
planet
r = state(1:3); %x, y, z
rho = norm(r);
rhat = r/rho;
Fgrav = -(mu*m/rho^2)*rhat;

%Call the magnetic field model
if t>= lastMagUpdate
    lastMagUpdate = lastMagUpdate+nextMagUpdate;
    %convert cartesian x,y,z into lat,long,alt
    phiE = 0;
    thetaE = acos(z/rho);
    psiE = atan2(y,x);
    latitude = 90-thetaE*180/pi;
    longitude = psiE*180/pi;
    rho_km = rho/1000; %from the center of earth
    [BN, BE, BD] = igrf('01-Jan-2020',latitude, longitude, rho_km,'geocentric');
    
    %intertial frame
    BNED = [BN;BE;BD]; %BD should be neg, but ima follow the video and have it positive
    BI = TIB(phiE, thetaE+pi, psiE)*BNED;
    BB = TIBquat(q0123)'*BI; %body frame
    %%%convert to tesla
    BB = BB*1e-9;
end

if t >= lastSensorUpdate
    %%%%Sensor Block
    lastSensorUpdate = lastSensorUpdate + nextSensorUpdate;
    [BfieldMeasured,pqrMeasured,ptpMeasured] = Sensor(BB,pqr,ptp);

    %%%Navigation Block
    [BfieldNav,pqrNav,ptpNav] = Navigation(BfieldMeasured,pqrMeasured,ptpMeasured);
    
end

%%%Control Block
[current,rwalphas] = Control(BfieldNav,pqrNav,ptpNav);

%magtorquer model
magtorquer_params

%%% add in saturation controller
if sum(abs(current)) > maxCurrent/1000
    current = (current/sum(abs(current)))*maxCurrent/1000;
end
muB = current*n*A;
LMN_magtorquers = cross(muB,BB);

%%% reaction wheel torques
w123dot = [0;0;0]; %for allocation

%%%basically whats done is 2 checks, one if the RW is spinning too fast you
%%%can't spin it any faster, two if your trying to accelerate it too
%%%quickly you can't
for idx = 1:3
    if abs(w123(idx)) > maxSpeed 
        w123dot(idx) = 0;
    else
        if abs(rwalphas(idx)) > maxAlpha
            rwalphas(idx) = sign(rwalphas(idx))*maxAlpha;
        end
    w123dot(idx) = rwalphas(idx);
    end
end

LMN_RWs = Ir1B*w123dot(1)*n1 + Ir2B*w123dot(2)*n2 + Ir3B*w123dot(3)*n3;

%%%compute disturbance forces and moments
[XYZD,LMND] = Disurbance(rho-R,Amax,lmax,vel,CD,BB);

%%%total moments
LMN  = LMN_magtorquers - LMN_RWs + LMND; %RW spin one way makes satellite spin other way and so thats why it's - LMN..

%translational dynamics
F = Fgrav + XYZD;
accel = F/m;

%need to compute the total angular momentum stuff
w1 = w123(1);
w2 = w123(2);
w3 = w123(3);
H = Is*pqr + Ir1B*w1*n1 + Ir2B*w2*n2 + Ir3B*w3*n3;

%H = I*pqr;

%rotational dynamics
pqrdot = invI*(LMN - cross(pqr,H));

%return derivatives vector
dstatedt = [vel;accel;q0123dot;pqrdot;w123dot];