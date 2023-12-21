clear; clc;

%% Rocket Parameters for Rotation %%

%Sizing
rocket_length = 4/3.281; %m
rocket_diameter = 1.95/39.37; %m
rocket_mass = 10; %kg

%flight parameters
rocket_thrust = 75*4.44822; %N
gravity = 9.81; %m/s^2

%Tank Parameters (fluid - CO2)
tank_pressure = 100*6.894757; %kPa
density = 1.87; %kg/m3 
tank_mass = 16/1000; %kg 
mass_dot = 0.00463*0.45359237; %kg/s

%Thruster Parameters
Gas_Const = 0.1889; %kJ/kg*K
T1 = 26.85+273.15; %K
SV_pressure = 40*6.894757; %kPa
atm_pressure= 101.325; %kPa
k = 1.285;
Pc = tank_pressure; %chamber pressure
t_radius = (1/8)*39.37; %m
gamma =1.4; %specific heat


%% Calculations for Rotation %%

angular_velocity = 62.83; %rad/s
time_step = 1; %s
moment_inertia = (1/2)*rocket_mass*rocket_diameter; %mkg
angular_moment = (angular_velocity*moment_inertia)/2; %mkg/s
%account for 2 thrusters
torque = angular_moment*time_step; %Nm

%% Calculations for COPV %%

Vtwo = mass_dot/density; %m3
Vone = ((SV_pressure*Vtwo)/tank_pressure); %m3


%% Calculations for Thrusters %%

t_thrust = 0.25*4.44822; %N
ISP = 39.32801; %s
%time for fire with previous thrust
new_time_step = (t_thrust)/angular_moment

%once we get the sizing from RPA
%we can get the nominal thrust and use that for calculations
%use ISP equation
%mass_dot = t_thrust/(ISP*g)

%torque = t_thrust*radius; %Nm

    %rocket propulsion elements - base elements
    %bluebook - imperical
    %isentropic expansion
    %calculate temp after insentropic expainsion
%----find temp before SV----%
    %maybe
%----find temp after SV----%
T2 = T1*((SV_pressure/tank_pressure)^((k-1)/k));
%from close side of SV, to chamber----%

%----finding throat area with steady state flow----%
%----finding mass flow in system for 1 SV----%
mdot = Vone*density;
%----calculate throat area----%
Ath = mdot/(tank_pressure*sqrt((gamma/(Gas_Const*T1))*(2/(gamma+1)^((gamma+1)/(gamma-1)))));
%----throat_area = (tank_pressure/(density*t_radius))*sqrt((gamma/(Gas_Const*T2))*(2/(gamma+1)^((gamma+1)/(gamma-1))))
%----mach number for expansion ration----%
M2 = sqrt((2/(gamma-1))*((atm_pressure/SV_pressure)^((gamma-1)/gamma))-1);
%----expansion ratio----%
expansion_ratio = (1/M2)*(2/(gamma+1)*(1+((gamma-1)/2)*M2^2))^((gamma+1)/(2*(gamma-1)))
%conicle 15deg half angle

%% HOW It'll Operate %%
%open SV to start system
%have presssure regulator keep it at 50psi
%then when starts to rotate, turn on 2 SV at the appropriate time

tank_volume_inch = Vone*61020
throat_Area_inch = Ath*10.764 


