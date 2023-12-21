function state = EOM_CubeSat(t, state)

%********* Initial Mass Properties ***************
m = 2.5; %kg 

%3U parameters
lx = 10/100; %cm to m
ly = 10/100;
lz = 30/100;

%Inertia Parameters
Ixx = (lx^2+ly^2);
Iyy = (lx^2+lz^2);
Izz = (ly^2+lz^2);

I = (m/12) * [Ixx, 0, 0;
              0, Iyy, 0;
              0, 0, Izz]; 


%**************** Unpack States ************************
xyz = state(1:3); %position
xyzdot = state(4:6); %velocity
ptp = state(7:9); %angles
pqr = state(10:12); %angluar velocity



dstate = [xyz; xyzdot; ptp; pqr];
end
