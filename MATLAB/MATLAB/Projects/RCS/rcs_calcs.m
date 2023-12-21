clear;clc;

%intial inputs
spin = 120; %rpm
mass = 2000; %g %3000g for rocket
radius = 2.165; %in
time = 1; %s

%conversions to SI
omega = 2*pi*spin/60; %rad/s
m = mass/1000;% kg
r = radius/39.37; %m
t = time; %s

r_tube = 0.003175; %m radius of outside exit and entrance
%https://www.amazon.com/Beduan-Normally-Closed-Electric-Solenoid/dp/B07N2LGFYS/ref=sxin_16_pa_sp_search_thematic_sspa?content-id=amzn1.sym.f1ae5671-a572-4614-89aa-2c9d534241e0%3Aamzn1.sym.f1ae5671-a572-4614-89aa-2c9d534241e0&cv_ct_cx=solenoid%2Bvalve&keywords=solenoid%2Bvalve&pd_rd_i=B07N2LGFYS&pd_rd_r=c859f397-7804-4f65-ae58-6962d074ff3b&pd_rd_w=tTGX3&pd_rd_wg=Pexgi&pf_rd_p=f1ae5671-a572-4614-89aa-2c9d534241e0&pf_rd_r=SPV08HM45RBYNJRB60SN&qid=1701125561&sbo=RZvfv%2F%2FHxDF%2BO5021pAnSA%3D%3D&sr=1-2-ac07dfd7-5f37-4797-bcf7-0f4905c82761-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9zZWFyY2hfdGhlbWF0aWM&th=1
%a_o = pi*((0.25/4)/25.4)^2; %area of orfice in to m
Cf = 0.23; %Cv in the product

V1 = 0; %m/s stationary
%dV_g = 25; %m/s gas speed
%dV_l = 1.1; %m/s liquid speed
A = pi*r_tube^2; %cross area of tubing
%A_b = pi*r^2;

%% GAS

%air characteristics
n = 28.97; %g/mol of air
density = 1.225; %density of air
R = 8.3145; %universal gas constant
T = 24+273.15; %K room temperature

% %nitrogen characteristics
% n = 28.02; %g/mol of air
% density = 1.165; %density of air
% R = 8.3145; %universal gas constant
% T = 24+273.15; %K room temperature

I = (1/2)*m*r^2; %moment of intertia
L = omega*I; %angular moment
tau = L/t; %torque
F = tau/r %force

%we saying that start pressure is 100
p1 = 100*6894.76; %psi to pa of tank
p2 = 101325; % atmo pa
dp = p1-p2;

%https://www.efunda.com/FORMULAE/fluids/calc_orifice_flowmeter.cfm
%https://www.princeton.edu/~asmits/Bicycle_web/Bernoulli.html
%Q = Cf*a_o*sqrt((2*dp)/density); %volumetric flow rate
Q = (22/(100/14.7))*4.719e-4 %m3/s
mdot = (Q*density); %mass flow
V2 = sqrt(2*dp/density);

F_SV = 2*(mdot*V2)

vflow = mdot/density;
velocity = vflow/A;

F_SV_2 = mdot*velocity;


%V = mdot/(density*A) %volume of tank
%P = (n*R*T)/V;
%psi_P = P*6895 
% psi_P = 4000
% P = psi_P*6895;
%V = (n*R*T)/P

%h = V/(pi*r^2); %height of tank
%in_h = h/4.921

 %% Liquids
% %water characteristics
% n = 18.02; %g/mol of air
% density = 998; %density of air
% 
% I = (1/2)*m*r^2 %moment of intertia
% L = omega*I %angular moment
% tau = L/t %torque
% F = tau/r %force
% 
% % psi_P = 100
% % P = psi_P*6895;
% % F = P/A_b
% 
% mdot = F/dV_l %mass flow
% P = F/A_b;
% psi_P = P/6895 
% 
% V = mdot/(density*A)
% h = V/(A_b); %height of tank
% in_h = h*39.37
% 
% new_m = density*V