function [current,rwalphas] = Control(BfieldNav,pqrNav,ptpNav)
%rwalphas is the angular velocity of the RW
global IrR Jinv

%BDOT Controller
k = 67200; % 672000 was huge!!
%%%Bfield is in teslas - 40000 nT = 4e4e-9 = 4e-5
%%% pqr is in rad/s - 0.1 rad/s = 1e-1
%%% pqr*Bfield = 1e-1*1e-5 = 1e-6
%%% pqr*Bfield / (n*A) = 6e-7
%%% muB = n*I*A = 
magtorquer_params

current = k*cross(pqrNav,BfieldNav)/(n*A);

%%% want current to be in amps ~= 40mA = 40e-3 = 4e-2
%%%math for gain
%%% 1e-6/(84*0.02) = 5.9524e-7
%%% 4e-2/ans

%%%% RW Controller
% pqrcommand = [0;0;0];
% ptpcommand = [0;0;0];
% KD = eye(3)*5;
% KP = eye(3)*20;
% rwalphas = KP*(ptpcommand - ptpNav) + KD*(pqrcommand - pqrNav);
reaction_wheel_params

if sum(abs(pqrNav)) < 0.1
    pqrcommand = [0;0;0];
    ptpcommand = [1;0;0];
    KD = eye(3)*45*IrR(1,1);
    KP = eye(3)*1*IrR(1,1);
    Mdesired = -KD*(pqrcommand - pqrNav) - KP*(ptpcommand - ptpNav);
else
    Mdesired = [0;0;0];
end

rwalphas = Jinv*Mdesired;