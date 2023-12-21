clear; clc; close all;

num_points = 100;
Sh_Sw_array = linspace(0.01, 0.5, num_points)';

% abs(CLh) < 1
%note to self redo code with the optimal Sh/Sw
%this would the value at the bottom
% optimal Sh/Sw = 0.117383383383383
%this value is at max L/D

%ask if we need a 3rd graph
%check our answer with Joe



%constraint
%% plane
wing_c = 40;
wing_b = 240;

%% change due to project numbers
%wing 
%NASA4415
Claw_Ainf = 0.1*180/pi; %
ARw = wing_b/wing_c; %
fw = 0.987;%
ew = 0.975; %
iw = 2*pi/180; %
aoa_0Lw = -4*pi/180; %
CD0w = 0.0074; %
Cmacw = -0.1; %
CLw_ext = -0.5; %

%tail
%NASA009
Clah_Ainf = 0.1*180/pi; %
ARh = 4.0; %
eh = 0.99; %
fh = 1; %
CD0h = 0.0055; %
Cmach = 0.0; %
etah = 0.75; %

%layout
Xcg = 14;
Xacw = 10;
lh = 95;

%nominal operating condition
aoa_nom = 0;

CLaw = fw*(Claw_Ainf/(1+Claw_Ainf/(pi*ARw))); %dCL/da
CLah = fh*(Clah_Ainf/(1+Clah_Ainf/(pi*ARh)));
de_da = 2*CLaw/(pi*ARw);

CLa = CLaw + etah*Sh_Sw_array*(1-de_da)*CLah;

CLw = CLaw*(aoa_nom + iw - aoa_0Lw);
Xa_bar = (Xcg - Xacw)/wing_c;

%step 1, establish the relationship between Sh/Sw and CLh
CLh = (CLw*Xa_bar + Cmacw + Sh_Sw_array*Cmach)./(etah*Sh_Sw_array*lh/wing_c); %solve for the CLh from...

%step 2, establish the total CL
CLtotal = CLw + etah*Sh_Sw_array.*CLh;

%step 3 drag
CDw = CD0w + CLw^2/(pi*ARw*ew);
CDh = CD0h + CLh.^2/(pi*ARh*ew);
CDtotal = CDw + etah*Sh_Sw_array.*CDh;


%step 4, L/D
L_over_D = CLtotal./CDtotal;

figure(1)
hold on
plot (Sh_Sw_array, L_over_D, 'linewidth', 2);
xlabel('S_{h}/S_{w} [dec]')
ylabel('L/D');
grid on

%step 5, relationship between aoa_h and Sh/Sw
%abs_aoa_h = abs((CLw_ext*Xa_bar + Cmacw + Sh_Sw_array*Cmach)./(etah*Sh_Sw_array*CLah*lh/wing_c));
CL_test = abs(CLw_ext*Xa_bar + Cmacw + Sh_Sw_array*Cmach)./(etah*Sh_Sw_array*lh/wing_c);
%Sh_Sw_min = interpolate(abs_aoa_h*180/pi, Sh_Sw_array, aoa_h_max_deg);

figure (2)
hold on
plot (Sh_Sw_array, CL_test, 'linewidth', 2);
%plot(Sh_Sw_array, aoa_h_max_deg*ones(num_points,1),'color','r','linewidth',2);
xlabel('S_{h}/S_{w} [dec]')
ylabel('CLh {h} [rad]');
grid on

%step 6
dCmcg_da = CLaw*Xa_bar - etah*(0.117383383383383*lh/wing_c*CLah*(1-de_da));
SM = -dCmcg_da./CLa;
figure (3)
hold on
plot(Sh_Sw_array, SM,'LineWidth',2);
xlabel('S_{h}/S_{w} [dec]')
ylabel('SM [dec]');
title('SM vs. S_{h}/S_{w}')
grid on

%step 7
CLh_opt = (CLw*Xa_bar + Cmacw + 0.117383383383383*Cmach)./(etah*0.117383383383383*lh/wing_c);

figure (1)
plot( [0.117383383383383 0.117383383383383], [min(L_over_D)-1 (max(L_over_D)+0.1)],'r','linewidth',2);

figure (3)
plot( [0.117383383383383 0.117383383383383],[min(SM)-1 max(SM)+2],'r','linewidth',2);
