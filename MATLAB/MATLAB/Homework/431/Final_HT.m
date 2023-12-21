clear;clc;

% merino wool
k = 0.031;
h = 9.093;

% %cotton
% k = 0.041;
% h = 12.027;
% 
% %polyester
% k = 0.081;
% h = 23.76;

%jan
qrad = 1426.46;
% %jun
% qrad = 2190.46;
% %oct
% qrad = 1775.19;

%person
Qgen = (48/60)*(2720.45); %Btu
r1 = (9/12)/2;
r2_ded = 0;
L1 = 5+(1/2);
L2 = 1/2;
Tb = 96.8;
Ta = 67;

Ac_cloth = 2*pi*r1*L1;

As_cloth = 2*pi*r1*L1+2*pi*r1^2;
As_head = 2*pi*r1*(L1+L2)+2*pi*r1^2;
% 
% Ts = (-(qrad*As_cloth)-Qgen+((k*Ac_cloth)/(r2-r1))*Tb-h*As_cloth*Ta)/((k*Ac_cloth)/((r2-r1))-h*As_cloth);
% 
% Rcyl = ((log(r2/r1)))/(2*pi*r2*k);
% Rconv1 = 1/(h*As_cloth);
% Rconv2 = 1/(h*As_head);
% Rrad1 = (Ts-Ta)/(qrad*As_cloth);
% Rrad2 = (Tb-Ta)/(qrad*As_head);
% 
% %Qcond with condition of body can't go below 33F
% Tscond = 33;
% Qcond = (Tscond-Ta)/Rcyl;
% 
% Qbody = (Tb-Ta)/(Rcyl+(1/((1/Rconv1)+(1/Rrad1))));
% Qhead = (Tb-Ta)/(1/((1/Rconv2)+(1/Rrad2)));
% 
% Qtotal = Qhead+Qbody;

% Set up loop parameters
start_value = r1;
stop_value = 1;
step_size = .0005;

% Loop through values
for i = start_value:step_size:stop_value
    % Assign value to variable
    r2 = i;
    
    % Evaluate equations
    Ts = (-(qrad*As_cloth)-Qgen+((k*Ac_cloth)/(r2-r1))*Tb-h*As_cloth*Ta)/((k*Ac_cloth)/((r2-r1))-h*As_cloth);
    
    Rcyl = ((log(r2/r1)))/(2*pi*r2*k);
    Rconv1 = 1/(h*As_cloth);
    Rconv2 = 1/(h*As_head);
    Rrad1 = (Ts-Ta)/(qrad*As_cloth);
    Rrad2 = (Tb-Ta)/(qrad*As_head);
    
    %Qcond with condition of body can't go below 33F
    Tscond = 33;
    Qcond = (Tscond-Ta)/Rcyl;
    
    Qbody = (Tb-Ta)/(Rcyl+(1/((1/Rconv1)+(1/Rrad1))));
    Qhead = (Tb-Ta)/(1/((1/Rconv2)+(1/Rrad2)));
    
    Qtotal = Qhead+Qbody;
    % Store results
    Qbody_values(i) = Qbody;
end

% Plot the results
figure
plot(r2_values, Qbody_values, 'b-')
xlabel('r2')
ylabel('Qbody')
title('Variation of Qbody with r2')
grid on