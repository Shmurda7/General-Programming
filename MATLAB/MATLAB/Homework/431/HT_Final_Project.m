% Input data
r = 0.5; % radius of the cylinder (m)
h = 1; % height of the cylinder (m)
v = 15 * 0.44704; % velocity of the cylinder (m/s)
q_gen = 100; % heat generation rate (W/m^3)
T_inf = 25; % temperature of the surrounding fluid (°C)
v_inf = 10; % velocity of the surrounding fluid (m/s)
k = 385; % thermal conductivity of the cylinder material (W/mK)
cp = 900; % heat capacity of the cylinder material (J/kgK)
rho = 8000; % density of the cylinder material (kg/m^3)
alpha = k/(cp*rho); % thermal diffusivity
Pr = 0.7; % Prandtl number
h_conv = 10; % convective heat transfer coefficient (W/m^2K)
 
% Calculation of Reynolds number
Re = rho*v*h/Pr;
 
% Calculation of Nusselt number for forced convection
Nu = 0.3*(Re^0.5)*(Pr^0.33);
 
% Calculation of convective heat transfer coefficient
h_conv = Nu*k/h;
 
% Calculation of Biot number
Bi = h_conv*h/(k*alpha);
 
% Calculation of temperature distribution around the cylinder
n = 50; % number of grid points
theta = linspace(0,2*pi,n);
r_grid = linspace(0,r,n);
delta_r = r/n;
delta_theta = 2*pi/n;
T = zeros(n,n);
for i = 1:n
	for j = 1:n
    	r_val = r_grid(i);
    	theta_val = theta(j);
    	x = r_val*cos(theta_val);
    	y = r_val*sin(theta_val);
    	u = v_inf*(r-r_val)/r;
    	Re_loc = rho*u*h/Pr;
    	Nu_loc = 0.3*(Re_loc^0.5)*(Pr^0.33);
    	h_loc = Nu_loc*k/h;
    	Bi_loc = h_loc*r_val/k;
    	if Bi_loc <= 0.1
        	T(i,j) = T_inf + q_gen/(2*h_conv*r)*(r^2-r_val^2);
    	else
        	T(i,j) = T_inf + q_gen/(4*k)*r_val^2*(1-cos(theta_val));
       end
	end
end
 
% Plotting the temperature distribution
[X,Y] = meshgrid(theta,r_grid);
Z = T';
figure;
contourf(X,Y,Z);
colorbar;
xlabel('Theta (rad)');
ylabel('Radius (m)');
title('Temperature distribution around a moving cylinder');
