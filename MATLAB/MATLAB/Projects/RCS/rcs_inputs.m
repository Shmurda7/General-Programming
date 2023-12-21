clear all
close all
%% Initial Conditions
%time
tf = 30;
tspan = [0 tf];
dt = 0.01;

%givens
rot = (240*2*pi)/60;%rpm -> rad/s

% putting together the initial state vector
rcs0 = [ 0, 0, 0, rot, 0, 0, 0, 0, 0, 0, 0, 0]';

t = [dt]

%% Run the model
sim('RCS_Model.slx')