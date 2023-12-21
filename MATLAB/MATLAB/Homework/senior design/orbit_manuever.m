clear; clc; close all;

%making some assumption
%launch puts us close to NOAA-12
%inclination
i_1 = 98.5; %deg
i_2 = 55.5; %deg

di = i_2 - i_1;

m = 1500 + 400;

%earth parameters
%making assumption for prelim calcs it's in a circular orbit
%h = (820.9 + 802.3)/2; %km
%r1 = h + earthRadius/1000; %km
ra_N = 820.9 + earthRadius/1000; %km
rp_N = 802.3 + earthRadius/1000; %km

mu = 398600; 

%v_c = sqrt(mu/r1);

%so no more inclination change

%plane change
%dv_i = 2*v_c*sin(di/2);

r2 = 200 + earthRadius/1000; %km
v_c = sqrt(mu/r2);

r3 = 500 + earthRadius/1000; %km
v_c_2 = sqrt(mu/r3);

%hohmann transfer from 500km to NOAA-12
h_4 = sqrt(2*mu)*sqrt((ra_N*rp_N)/(ra_N + rp_N));
h_5 = sqrt(2*mu)*sqrt((rp_N*r3)/(rp_N + r3));
h_6 = sqrt(mu*r3);

v4 = h_4/rp_N;
v5 = h_5/r3;

dv_tran = v5 - v4;

v6 = h_6/r3;

dv_cir = v6 - v5;

total_dv_t = abs(dv_cir) + abs(dv_tran);

burn_speed = 8;

dv_burn = 8-v_c_2;

total_dv_1 = total_dv_t + dv_burn


%hohmann transfer NOAA-12 orbit to 200km
h_1 = sqrt(2*mu)*sqrt((ra_N*rp_N)/(ra_N + rp_N));
h_2 = sqrt(2*mu)*sqrt((rp_N*r2)/(rp_N + r2));
h_3 = sqrt(mu*r2);

v1 = h_1/rp_N;
v2 = h_2/r2;

dv_tran = v2 - v1;

v3 = h_3/r2;

dv_cir = v3 -v2;

total_dv_t = abs(dv_cir) + abs(dv_tran);

burn_speed = 8;

dv_burn = 8-v_c;

total_dv_2 = total_dv_t + dv_burn

total_dv = total_dv_2 + total_dv_1

%atmo drag
rho = 1.75e-10;
A = 8*6;
Cd = 2; 

%D = (1/2)*rho*v3^2*A*Cd


