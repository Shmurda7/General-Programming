clear; clc; close all;
%% Objective %%
%Determine tail size @ max L/D
% @ CL = -0.5, abs(CL) < 1

%Sh/Sw array for plotting
Sh_Sw = linspace(0.01, 0.5, 100)';

%% Geometry %%
c = 40; %wingspan (cm)
b = 240; %chord (cm)
x_cg = 14; %center of gravity (cm)
x_acw = 10; %wing aerodynamic center (cm)
lh = 95; %length of tail (cm)

%% Assumptions %%
%NASA4415 Wing
%Givens
iw = 2 * (pi / 180); %incidence of wing (rad)
ew = 0.975; %oswald factor of wing
fw = 0.987; %lift slope correction of wing
%Graphs
CLaw_Ainf = 0.1 * (180 / pi); %coefficient of lift @ alpha wing (rad)
ARw = b / c; %aspect ratio of wing
a_0Lw = -4* (pi / 180);  %angle of attack @ 0 lift (rad)
CD0w = 0.0074; %coefficient of drag at lowest point on graph
Cmacw = -0.1; %moment coefficient at ac of the wing

%NASA009 Tail
%Givens
ARh = 4; %aspect ratio of the tail
eh = 0.99; %oswald factor of tail
fh = 1; %lift slope correction of tail
eff = 0.75; %efficiency
%Graphs
CLah_Ainf = 0.1 * (180 / pi); %coefficient of lift @ alpha tail (rad)
CD0h = 0.0055; %coefficient of drag at lowest point on graph
Cmach = 0; %moment coefficient at ac of the tail

%Nominal flight condition constraint
a_nom = 0; %(rad)
CLw_con = -0.5;  %constraint from objective

%% Additional values %%
%values from class notes to solve for values need for CLa & CLw
CLaw_da = fw * (CLaw_Ainf / (1 + CLaw_Ainf / (pi * ARw))); %CLaw/da
CLah_da = fh * (CLah_Ainf / (1 + CLah_Ainf / (pi * ARh))); %CLah/da
%given equation
dE_da = 2 * CLaw_da / (pi * ARw); %dE/da
%values needed for trim equation
xa_bar = (x_cg - x_acw) / c;
CLa = CLaw_da + (eff * Sh_Sw * (1 - dE_da) * CLah_da); 
CLw = CLaw_da * (a_nom + iw - a_0Lw);
K = Sh_Sw * (lh / c);

%% Steps
% Step 1 trim equation for CLh as a function of Sh/Sw
CLh = ((CLw * xa_bar) + Cmacw + (Sh_Sw * Cmach)) ./ (eff * K);

%step 2 establish the total vehicle CL @ a_nom = 0
CL_total = CLw + eff * Sh_Sw .* CLh;

%step 3 establish the total vehicle CD
CDw = CD0w + CLw^2 / (pi * ARw * ew);
CDh = CD0h + CLh.^2 / (pi * ARh * ew);
CD_total = CDw + eff * Sh_Sw .* CDh;

%step 4, determine the L/D to then plot
Lift_Drag = CL_total ./ CD_total; %L/D

%step 5 trim equation for CLh but w/ CLw_con
CLh_con = ((CLw_con * xa_bar) + Cmacw + (Sh_Sw * Cmach)) ./ (eff * K);
%mentioned in the objective, need |CLh| @ CLw = -0.5
abs_CLh = abs(CLh_con);

%step 6 roughly the optimal value for this, gotten from the first graph 
Sh_Sw_opt = 0.117383383383383;

%step 7 determine the SM and stability of optimal configuration
dCmcg_da = CLaw_da * xa_bar - eff * (Sh_Sw * (lh / c) * CLah_da * (1 - dE_da));
SM = -dCmcg_da ./ CLa;

%% Optimal Sh_Sw %%
%optimal portion for the optimal lines
%Problem 4.1
CLa_opt = CLaw_da + (eff * Sh_Sw_opt * (1 - dE_da) * CLah_da);
K_opt = Sh_Sw_opt * (lh / c);
dCmcg_da_opt = CLaw_da * xa_bar - eff * K_opt * CLah_da * (1 - dE_da);
SM_opt = -dCmcg_da_opt ./ CLa_opt;
%Problem 5.1
CLw_opt = CLaw_da * (a_nom + iw - a_0Lw);
%Problem 5.2
CLh_opt = ((CLw_opt * xa_bar) + Cmacw + (Sh_Sw_opt * Cmach)) ./ (eff * K_opt);
%Problem 5.3
CDw_opt = CD0w + CLw_opt^2 / (pi * ARw * ew);
%Problem 5.4
CDh_opt = CD0h + CLh_opt.^2 / (pi * ARh* ew);
%Problem 5.5
CL_total_opt = CLw_opt + eff*Sh_Sw_opt.*CLh_opt;
%Problem 5.6
CD_total_opt = CDw_opt + eff * Sh_Sw_opt .* CDh_opt;
%Problem 5.7
Lift_Drag_opt = CL_total_opt ./ CD_total_opt;

%% 5.8 section
%similar to quiz 4, assume Cmcg = 0
aoa_tail=abs((CL_total_opt*xa_bar + Cmacw + Sh_Sw_opt*Cmach)./(eff*Sh_Sw_opt*CLah_da*lh/c));
% Problem 5.8.1
ah = (CLw* xa_bar + Cmacw) / ((eff * K_opt) * CLah_da);
ih_uno = -(aoa_tail*(1 - dE_da) * a_nom - dE_da * (iw - a_0Lw)) + ah;
%Problem 5.8.2
ah = (CLw_con* xa_bar + Cmacw) / (eff * K_opt * CLah_da);
ih_dos = -(aoa_tail*(1 - dE_da) * a_nom - dE_da * (iw - a_0Lw)) + ah; 

%% Graphs %%
%plotting for step 4
%determine the optimal Sh/Sw value from clicking the points on the graph
%got optimal Sh/Sw to be 0.117383383383383
figure(1)
hold on
plot (Sh_Sw, Lift_Drag, 'linewidth', 2);
xlabel('S_{h}/S_{w}')
ylabel('L/D');
title('L/D vs. S_{h}/S_{w}')
grid on

%plotting for step 5
figure (2)
hold on
plot (Sh_Sw, abs_CLh, 'linewidth', 2);
xlabel('S_{h}/S_{w}');
ylabel('CL{h} (rad)');
title('CL{h} vs. S_{h}/S_{w}')
grid on

figure (3)
hold on
plot(Sh_Sw, SM,'LineWidth',2);
xlabel('S_{h}/S_{w}')
ylabel('SM (unitless)');
title('SM vs. S_{h}/S_{w}')
grid on

% Lines for the points where Sh/Sw is optimal
figure(1)
plot([Sh_Sw_opt Sh_Sw_opt], [min(Lift_Drag) (max(Lift_Drag))], 'r', 'linewidth', 2);

figure(2)
plot([Sh_Sw_opt Sh_Sw_opt], [min(abs_CLh) (max(abs_CLh))], 'r', 'linewidth', 2);

figure(3)
plot([Sh_Sw_opt Sh_Sw_opt], [min(SM) max(SM)], 'r', 'linewidth', 2);

%% Prints %%
%deliverables for the project
disp('--------- Solutions for Problem 3 & 4 ---------');
fprintf('Problem 3: the optimal Sh/Sw = %f\n', Sh_Sw_opt);
fprintf('Problem 4.1: at optimal Sh/Sw SM = %f\n', SM_opt);
fprintf('Problem 4.2: vehicle is stable due to SM > 0\n');

disp('--------- Solutions for Problem 5 ---------');
fprintf('Problem 5.1: at optimal Sh_Sw, CLw = %f\n', CLw_opt);
fprintf('Problem 5.2: at optimal Sh_Sw, CLh = %f\n', CLh_opt);
fprintf('Problem 5.3: at optimal Sh_Sw, CDw = %f\n', CDw_opt);
fprintf('Problem 5.4: at optimal Sh_Sw, CDh = %f\n', CDh_opt);
fprintf('Problem 5.5: at optimal Sh_Sw, CL = %f\n', CL_total_opt);
fprintf('Problem 5.6: at optimal Sh_Sw, CD = %f\n', CD_total_opt);
fprintf('Problem 5.7: at optimal Sh_Sw, L/D = %f\n', Lift_Drag_opt);
fprintf('Problem 5.8.1: at nominal flight condition , ih = %f deg\n', ih_uno * (180 / pi));
fprintf('Problem 5.8.2: at CLw = -0.5 , ih = %f deg\n', ih_dos * (180 / pi));