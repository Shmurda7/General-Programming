%%inertia and mass
ms = 2.6; %kg

%%% cuboid model
%%% inertia of satellite
lx = 10/100; %cm to m
ly = 10/100;
lz = 20/100;

Ixx = (lx^2+ly^2);
Iyy = (lx^2+lz^2);
Izz = (ly^2+lz^2);

l = [lx;ly;lz];
lsort = sort(l);
Amax = lsort(2)*lsort(3);
lmax = l(3);
CD = 1.0;

%%%Inertia in kg-m^2
Is = (ms/12)*[Ixx  0    0; 
              0   Iyy   0; 
              0    0   Izz];

%%%call reation wheel params
reaction_wheel_params

%%% add everything up
m = ms + 3*mr;
I = Is + Ir1Bcg + Ir2Bcg + Ir3Bcg; %only use cg for computing total inertia

invI = inv(I);




r = 10.2/100;

lx = pi*r^2
ly = pi*r^2

