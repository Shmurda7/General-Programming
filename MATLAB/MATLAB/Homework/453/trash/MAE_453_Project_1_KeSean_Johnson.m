clear all
close all

% Establish plot points for Sh_Sw plots
Sh_SW_Points = 100;
Sh_Sw_Range = linspace(0.01,0.5,Sh_SW_Points)';

% Constraints
AoA_h_max_deg = 8;

% Wing NACA4415
ARinf_w = 0.31180/pi;
ARw = 6.0;
fw = 0.987;
ew = 0.975;
iw = 2pi/180;
aoa_0Lw = -4pi/180;
CD0w = 0.0074;
Cmacw = -0.098;
CLw_max = 1.5;

% Tail NACA0009
ARinf_h = 0.11180/pi;
ARh = 4.0;
eh = 0.99;
fh = 1.0;
CD0h = 0.0052;
Cmach = 0.0;
efficiency_h = 0.75;

% Layout dimensions of aircraft
Xcg = 14;
Xacw = 10;
lh = 95;
c = 40;

% Given nominal operating condition
aoa_nom = 0;

% Define functional relationships
CLaw = fw.ARinf_w/(1+ARinf_w)/(pi.ARw);
CLah = fh.ARinf_h/(1+ARinf_h)/(pi.ARh);
de_da = 2CLaw/(piARw);
CLh = CLaw + efficiency_h.Sh_Sw_Range(1-de_da).CLah;
CLw = CLaw.(aoa_nom + iw - aoa_0Lw);
Xa_b = (Xcg - Xacw)./c;

% Step 1 Establish relationship between Sh/Sw and CLh
% Solve for dCLh/da in the equation at the end of Lecture 6 slides
CLh = (CLw.Xa_b + Cmacw + Sh_Sw_Range.Cmach)./(efficiency_hSh_Sw_Rangelh/c);

% Step 2 Establish total vehicle CL at nominal condition
% Referenced Lecture 5 Slides
CL_tot = CLw + efficiency_hSh_Sw_Range.CLh;

% Step 3 Establish total vehicle drag , given parameters for CDw, CDh, CD
% Simply just rewrote the formulas given in steps page
CDw = CD0w + CLw.^2/(piARwew);
CDh = CD0h + CLh.^2/(piARhew);
CD_tot = CDw + efficiency_h.Sh_Sw_Range.CDh;

% Step 4 Establish L/D and plot it
%L/D is simply total lift over total drag
LD = CL_tot./CD_tot;

%Setup parameters for plot
figure(1)
hold on
plot(Sh_Sw_Range.100, LD,'linewidth',2);
xlabel('Sh/Sw');
ylabel('L/D');
grid on
title('L/D vs Sh/Sw')

%Step 5 Establish relationship between tail angle of attack at CLw
%constraint and Sh/Sw
%done in reference to trim equation, but I also used a lot of assistance
%from the hint because I kept running into errors
aoh_h_under_constraint = abs((CLw_max.Xa_b + Cmacw + Sh_Sw_Range.Cmach)./(efficiency_h.Sh_Sw_Range.CLah.lh/c));
% determine minimum tail size in regards to straint
Sh_Sw_min = interpl(aoh_h_under_constraint.180/pi, Sh_Sw_Range,AoA_h_max_deg);

figure(2)
hold on
plot(Sh_Sw_Range100, aoh_h_under_constraint.180/pi, 'linewidth',2);
plot(Sh_Sw_Range100, AoA_h_max_deg.ones(Sh_SW_Points,1),'color','r','linewidth',2);
xlabel('Sh/Sw')
ylabel('ah [deg]');
grid on
title ('\ah at CLw = 1.6')


%Step 6 Determine optimal Sh/Sw
%Took dCmcg_da equation from very last equation on Lecture 6 slides
dCmcg_da = CLaw.Xa_b - efficiency_h.(Sh_Sw_Range.lh/c).CLah.(1-de_da);
%SM formula that I used on quiz/midterm
SM = -dCmcg_da./CLa;
figure(3)
hold on
plot( [Sh_Sw_min Sh_Sw_min]100,[(min(SM100)-2) (max(SM100)+2)],'r','linewidth',2);
%plot(Sh_Sw_Range.100, SM.100, 'linewidth',2);
xlabel('Sh_Sw')
ylabel('SM')
title('Sh_Sw vs SM')
grid on

%Step 7 Determine SM
%Optimal CLh
CLh_opt = (CLw.Xa_b + Cmacw + Sh_Sw_min.Cmach)./(efficiency_h.Sh_Sw_min.*lh/c);
