clear;clc;

% polyester
k = 0.081;
h = 23.76;

% jun
qrad = 219.046;

% person
Qgen = (48/60)*(2720.45); %Btu
r1 = (9/12)/2;
L = 5+(1/2);
Tb = 96.8;
Ta = 67;

A1 = 2*pi*((9/12)/2)*(5+(1/2))+2*pi*((9/12)/2)^2;
A2 = 4*pi*((9/12)/2)^2;
A3 = A1+A2;

% initial guess for r2
r2 = 0.001;

% tolerance level for convergence
tol = 0.01;

% maximum number of iterations
max_iter = 100;

iter = 0;
err = Inf;
while err > tol && iter < max_iter
    
    % calculate surface temperature
    Ts = ((qrad*A3)+Qgen+((k*A1)/L)*Tb+h*A1*Ta)/(k*A1+h*A1);
    
    % calculate resistances
    Rcyl = ((log(r2/r1)/log(exp(1))))/(2*pi*L*k);
    Rconv1 = 1/(h*A1);
    Rconv2 = 1/(h*A2);
    Rrad1 = (Ts-Ta)/(qrad*A1);
    Rrad2 = (Ts-Ta)/(qrad*A2);
    
    % calculate heat fluxes
    Qcond = (Tb-Ts)/(Rcyl);
    Qbody = (Tb-Ta)/(Rcyl+(1/((1/Rconv1)+(1/Rrad1))));
    Qhead = (Tb-Ta)/(1/((1/Rconv2)+(1/Rrad2)));
    Qtotal = Qbody + Qhead;
    
    % adjust r2 based on error
    err = abs(Qtotal - Qcond);
    r2 = r2 + 0.001*(Qtotal - Qcond);
    
    iter = iter + 1;
end

fprintf('r2 = %.4f inches\n', r2);

