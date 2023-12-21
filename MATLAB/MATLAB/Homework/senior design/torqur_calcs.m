clear;clc;close all;

%% Side View
%intial inputs
spin = 1.5; %deg/s
omega = spin*(pi/180); %rad/s
m = 80000;% kg
l = 7; %m 
w = 3.7; %m
t = 1.5; %s

A = l*w; %cross area of tubing

I = A^4/12; %moment of intertia
L = omega*I; %angular moment
tau_side = L/t %torque
F_side = tau_side/l; %force

%% Top View
%intial inputs
spin = 1.5; %deg/s
omega = spin*(pi/180); %rad/s
m = 80000;% kg
l = 7; %m
w = 6; %m

A = l*w; %cross area of tubing

I = A^4/12; %moment of intertia
L = omega*I; %angular moment
tau_top = L/t %torque
F_top = tau_top/l; %force