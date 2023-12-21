%%%inertia and mass
m = 2.39; %%kilograms
lx = 10/100; %%meters
ly = 10/100; %%meters
lz = 30/100; %%meters

%%%Inertia of satellite in kg-m^2
I = (m/12)*[(lx^2+ly^2) 0 0 ;0 (lx^2+lz^2) 0;0 0 (ly^2+lz^2)]
