clear;clc;close all;

%titanium alloy
density_t = 4500; %kg/m3

%aluminum
density_a = 2660; %kg/m3

%carbon
density_c = 1750; %kg/m3

%volume of spacecraft
l_s = 7; %m
w_s = 6; %m
h_s = 3.7; %m

%volume of capulse
l = 6.2; %m
w = 5; %m
h = 3.5; %m

%thickness
t_cap = 0.127; %m
t_spac = 0.0762; %m

%volume of capsule
Vcap = l*w*h;
Vemt_cap = (l - 2*t_cap)*(w - 2*t_cap)*(h - 2*t_cap);

Vcap_2 = Vcap - Vemt_cap;

Mass_cap = Vcap_2*density_c; %kg

NOAA = (1418 + 735)/2;

Mass_cap_tot = Mass_cap + NOAA;

%volume of spacecraft
Vspac = l_s*w_s*h_s;
Vemt_spac = (l_s - 2*t_spac)*(w_s - 2*t_spac)*(h_s - 2*t_spac);
arms = 750; %kg

Vspac_2 = Vspac - Vemt_spac;

Mass_spac = Vspac_2*density_c + arms; %kg

Mass_total = Mass_spac*.5 + 0*Mass_cap

final_mass = Mass_total + (54*900)/2;

%1500
%900

%68788
%41400