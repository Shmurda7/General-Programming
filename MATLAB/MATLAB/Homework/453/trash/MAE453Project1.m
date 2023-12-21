clear;clc; close all

%Flight Conditions:
sh_sw=linspace(0.01,0.5,100)'; 
aoa_nom=0; %Nominal fight condition
aoa_max=8; % Maximum degree
cl_max=1.5; %Maximum Cl value 

%List all given values:

%Plane Dimensions in Centimeters:
b=240; % Wingspan 
c=40; % Chord 
x_acw= 10; % wing aerodynamic center 
x_cg= 14; % Center of gravity
lh=95; % Length 

% Wing NACA 4415 Criteria 
iw= 2*(pi/180); % Degrees all convert to radians
ew=0.975; % Oswald factor
fw=0.987; % Lift slope correction
Claw_inf= 0.1*(180/pi); % Coefficient of lift @ alpha infinity (wing), Convert to radians 
aoalo_w= -4* (pi/180); % Convert to radians 
C_macw=-0.1; % Moment coefficient at AC of the wing
Cd_w0=0.0075; % Value found from NACA 4415 Graph
ARw= (b)^2 / (b*c); % Aspect Ratio formula
REw=3*10^6; %Reynolds Number

%Tail NACA 0009 criteria 
ARh=4.0; % Aspect Ratio 
eh=0.99; % Oswald factor
fh=1.0; % Life slope correction 
nh=0.75; % Effiency
Clhw_inf=0.1*(180/pi); % Coefficient of lift @ alpha infinity (tail)
Cd_h0=0.005;
Cl_h0=-0.1;
C_mach=0; % Moment coefficient at AC of the tail
REh=3*10^6; %Reynolds Number

%Equations: 
C_law= fw*Claw_inf / (1+Claw_inf/(pi*ARw));
C_lah= fh*Clhw_inf / (1+Clhw_inf/(pi*ARh));

de_da=(2*C_law) / (pi*ARw); % Given de/dalpha formula  
CL_w= C_law*(aoa_nom+iw-aoalo_w); 
CL_alpha= C_law + nh * sh_sw * (1 - de_da) * C_lah;
X_bar= (x_cg -x_acw) / c; % A fundamental equation for 453 

%Part 1: Tail Lift & Tail Size Relationship
CL_h= (CL_w * X_bar + C_macw + sh_sw * C_mach)./(nh * sh_sw * lh/c);

%Part 2: Total Cl 
Total_CL= CL_w + nh * sh_sw .* CL_h;

%Part 3: Total Drag 
CD_h= Cd_h0 + CL_h.^2 / (pi*ARh*eh); % Tail Drag Coefficient 
CD_w= Cd_w0 + CL_w.^2 / (pi*ARw*ew); % Wing Drag Coefficient 
Total_CD= CD_w + nh*sh_sw.*CD_h; 

%Part 4: Plotting L/D
L_D= Total_CL./Total_CD; 
figure(1);
hold on;
plot(sh_sw*100,L_D,'r','linewidth',1);
grid on; 
xlabel('Sh/Sw (percent %)'); 
ylabel ('L/D (unitless)');
title('Sh/Sw versus L/D');

%Part 5 Sh/Sw & aoa_tail Relationship
aoa_tail=abs((cl_max*X_bar + C_macw + sh_sw*C_mach)./(nh*sh_sw*C_lah*lh/c));
min_sh_sw=interp1(aoa_tail*(180/pi), sh_sw, aoa_max);
figure(2); 
hold on; 
plot(sh_sw*100,aoa_tail*(180/pi), 'b', 'LineWidth', 1); 
grid on; 
xlabel('Sh/Sw (percent %)');
ylabel('Tail \alpha (degrees)');
title('Tail \alpha versus Sh/Sw')

%Part 6: Static Margin (SM)
dCmcg_da=C_law*X_bar-nh*(sh_sw*lh/c)*C_lah*(1-de_da);
SM=-dCmcg_da./CL_alpha;
figure(3);
hold on;
plot(sh_sw*100, SM*100, 'g', 'linewidth', 1);
grid on;
xlabel('Sh/Sw (percent %)');
ylabel('SM (percent %)');
title('Sh/Sw versus SM')


%Part 7: Optimal configuration of C_Lh
CL_opth= (CL_w*X_bar+C_macw+min_sh_sw*C_mach)./(nh*lh/c*min_sh_sw);
figure(1);
plot([min_sh_sw min_sh_sw] *100, [(min(L_D)-0.1) (max(L_D)+0.1)], 'm','linewidth',1);
figure(2); 
plot([3,50],[8,8], 'm','LineWidth',1);
figure(3);
plot([min_sh_sw min_sh_sw]*100, [(min(SM*100)-2) (max(SM+100)+2)], 'm','linewidth', 1);

%Deliverables 
fprintf('The optimal Sh/Sw value is = %4.4f  \n', sh_sw(20))
fprintf('\n Question 4.1) The corresponding SM value is = %4.4f \n', SM(20))
fprintf('\n Question 4.2) The design is slightly unstable making auto-stabilization system necessary. \n')
fprintf('\n Question 5.1) The Cl value at alpha=0 is %4.4f \n', CL_w)
fprintf('\n Question 5.2) The Clh value at alpha=0 is %4.4f \n', CL_opth)
fprintf('\n Question 5.3) The Cdw value at alpha=0 is %4.4f \n', CD_w)
fprintf('\n Question 5.4) The Cdh value at alpha=0 is %4.4f \n', CD_h(20))
fprintf('\n Question 5.5) The total CL value at the nominal condition is %4.4f \n', Total_CL(20))
fprintf('\n Question 5.6) The total CD value at the nominal condition is %4.4f \n', Total_CD(20))
fprintf('\n Question 5.7) The L/D value at the nominal condition is %4.4f \n', L_D(20))
ihopt= (180/pi)*((aoa_tail*(pi/180))-(1-de_da)*aoa_nom+(de_da)*(iw-aoalo_w));
fprintf('\n Question 5.8.1) The optimal ih value at nominal flight is %4.4f degrees with the tail deflecting down. \n', ihopt(20))
fprintf('\n Question 5.8.2) The ih value at the CL max of 1.5 is %4.4f degrees with the tail deflecting up. \n', ihopt(4))
