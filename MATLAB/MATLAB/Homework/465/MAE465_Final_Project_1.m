%% MAE 465 Aerospace Structures II %%
% Final Project Spring 2023
% Professor Shaher Abdallah
% Group:
% Andrew Lee
% Kris Morada
% Ripudamini Bajaj
% Jaime Ormeno
% Due Date: 10 May 2023

%% Givens: %%
b = 360;                % Dimension, b (in)
b2 = sqrt((b^2)+(b^2)); % Dimension of elements 7,8,9,10 (in)
SF = 1.5;               % Factor of Safety
P1 = -66.67*10^3;       % Load P1 (kips to lbs)
P2 = -66.67*10^3;       % Load P2 (kips to lbs)
density = 0.1;          % Density (lb/in^3)
E = (10^4)*10^3;        % Modulus of Elasticity (kips to lbs)
S_all = 25*10^3;        % Allowable stress (ksi to psi)
S_all9 = 75*10^3;       % Allowable stress for member 9 (ksi to psi)
A = ones(10,1);         % Initial Area Matrix
CSA_Min = 0.1;          % Minimum cross-sectional area (in^2)

%% From Figure %%
% Angles according to given figure: (in degrees)
angle1=0; angle2=0; angle3=0; angle4=0;
angle5=90; angle6=90;
angle7=135; angle8=45; angle9=135; angle10=45;
% Matrix of angles in element order:
angle = [angle1;angle2;angle3;angle4;angle5;angle6;angle7;angle8;angle9;angle10];
% Force Matrix based on given figure:
% u1, v1, u2, v2, u3, v3, u4, v4 (with boundary conditions)
F = [0;0;0;P2;0;0;0;P1];

%% Finding the initial local stiffness matrices:
% find the local k matrix for each element

% Element 1 (nodes 5 to 3)
c1=cosd(angle(1)); 
s1=sind(angle(1)); 
cs1=c1*s1;
k1=((A(1)*E)/b)*[c1^2 cs1 -c1^2 -cs1;
                 cs1 s1^2 -cs1 -s1^2;
                 -c1^2 -cs1 c1^2 cs1;
                -cs1 -s1^2 cs1 s1^2];
% Element 2 (nodes 3 to 1)
c2=cosd(angle(2)); 
s2=sind(angle(2)); 
cs2=c2*s2;
k2=((A(2)*E)/b)*[c2^2 cs2 -c2^2 -cs2;
                 cs2 s2^2 -cs2 -s2^2;
                 -c2^2 -cs2 c2^2 cs2;
                -cs2 -s2^2 cs2 s2^2];
% Element 3 (nodes 6 to 4)
c3=cosd(angle(3)); 
s3=sind(angle(3)); 
cs3=c3*s3;
k3=((A(3)*E)/b)*[c3^2 cs3 -c3^2 -cs3;
                 cs3 s3^2 -cs3 -s3^2;
                 -c3^2 -cs3 c3^2 cs3;
                -cs3 -s3^2 cs3 s3^2];
% Element 4 (nodes 4 to 2)
c4=cosd(angle(4)); 
s4=sind(angle(4)); 
cs4=c4*s4;
k4=((A(4)*E)/b)*[c4^2 cs4 -c4^2 -cs4;
                 cs4 s4^2 -cs4 -s4^2;
                 -c4^2 -cs4 c4^2 cs4;
                -cs4 -s4^2 cs4 s4^2];
% Element 5 (nodes 3 to 4)
c5=cosd(angle(5)); 
s5=sind(angle(5)); 
cs5=c5*s5;
k5=((A(5)*E)/b)*[c5^2 cs5 -c5^2 -cs5;
                 cs5 s5^2 -cs5 -s5^2;
                 -c5^2 -cs5 c5^2 cs5;
                -cs5 -s5^2 cs5 s5^2];
% Element 6 (nodes 1 to 2)
c6=cosd(angle(6)); 
s6=sind(angle(6)); 
cs6=c6*s6;
k6=((A(6)*E)/b)*[c6^2 cs6 -c6^2 -cs6;
                 cs6 s6^2 -cs6 -s6^2;
                 -c6^2 -cs6 c6^2 cs6;
                -cs6 -s6^2 cs6 s6^2];
% Element 7 (nodes 4 to 5)
c7=cosd(angle(7)); 
s7=sind(angle(7)); 
cs7=c7*s7;
k7=((A(7)*E)/b2)*[c7^2 cs7 -c7^2 -cs7;
                  cs7 s7^2 -cs7 -s7^2;
                  -c7^2 -cs7 c7^2 cs7;
                 -cs7 -s7^2 cs7 s7^2];
% Element 8 (nodes 3 to 6)
c8=cosd(angle(8)); 
s8=sind(angle(8)); 
cs8=c8*s8;
k8=((A(8)*E)/b2)*[c8^2 cs8 -c8^2 -cs8;
                  cs8 s8^2 -cs8 -s8^2;
                  -c8^2 -cs8 c8^2 cs8;
                 -cs8 -s8^2 cs8 s8^2];
% Element 9 (nodes 2 to 3)
c9=cosd(angle(9)); 
s9=sind(angle(9)); 
cs9=c9*s9;
k9=((A(9)*E)/b2)*[c9^2 cs9 -c9^2 -cs9;
                  cs9 s9^2 -cs9 -s9^2;
                  -c9^2 -cs9 c9^2 cs9;
                 -cs9 -s9^2 cs9 s9^2];
% Element 10 (nodes 1 to 4)
c10=cosd(angle(10)); 
s10=sind(angle(10)); 
cs10=c10*s10;
k10=((A(10)*E)/b2)*[c10^2 cs10 -c10^2 -cs10;
                    cs10 s10^2 -cs10 -s10^2;
                    -c10^2 -cs10 c10^2 cs10;
                   -cs10 -s10^2 cs10 s10^2];

%% Initial Global K Matrix Calculations:
% Assemble global k matrix from local k matrices
% The global matrix reduced to a 8x8 matrix due to boundary conditions
% Boundary Conditions: u5,v5,u6,v6 = 0
% Finding the value of each position of the 8x8 matrix using superposition:

k11 = k2(1:2,1:2)+k6(1:2,1:2)+k10(1:2,1:2); % Location (u1,u1)
k12 = k6(1:2,3:4); % Location (u1,v2)
k13 = k2(1:2,3:4); % Location (u1,v3)
k14 = k10(1:2,3:4); % Location (u1,v4)
k22 = k4(1:2,1:2)+k6(3:4,3:4)+k9(1:2,1:2); % Location (u2,v2)
k23 = k9(1:2,3:4); % Location (u2,v3)
k24 = k4(1:2,3:4); % Location (u2,v4)
k33 = k1(1:2,1:2)+k2(3:4,3:4)+k5(1:2,1:2)+k8(1:2,1:2)+k9(3:4,3:4); % Location (u3,v3)
k34 = k5(1:2,3:4); % Location (u3,v4)
k44 = k3(1:2,1:2)+k4(3:4,3:4)+k5(3:4,3:4)+k7(1:2,1:2)+k10(3:4,3:4); % Location (u4,v4)

% Symmetrical K matrix: k21 = k12, k31 = k13, k41 = k14, etc.
k21 = k12; % Location (u2,v1)
k31 = k13; % Location (u3,v1)
k32 = k23; % Location (u3,v2)
k41 = k14; % Location (u4,v1)
k42 = k24; % Location (u4,v2)
k43 = k34; % Location (u4,v3)

% Global K Matrix:
K = [k11 k12 k13 k14;
     k21 k22 k23 k24;
     k31 k32 k33 k34;
     k41 k42 k43 k44];

%% Initial Displacement Calculations: %%
% solve for displacement with global K matrix and Force matrix

d = K\F;                     % Solving the displacements (u1,v1,u2,v3,u3,v3,u4,v4)
d(12,1) = 0;                 % New d which the zeros for K(12,12)=0

%% Initial Stress Calculations: %%
% Solve for stresses in each element with calculated displacement

% Stress 1
S1  = (E/b)*[-c1 -s1 c1 s1]*[d(5:6); d(9:10)];

% Stress 2
S2  = (E/b)*[-c2 -s2 c2 s2]*[d(1:2); d(5:6)];

% Stress 3
S3  = (E/b)*[-c3 -s3 c3 s3]*[d(7:8); d(11:12)];

% Stress 4
S4  = (E/b)*[-c4 -s4 c4 s4]*[d(3:4); d(7:8)];

% Stress 5
S5  = (E/b)*[-c5 -s5 c5 s5]*[d(5:6); d(7:8)];

% Stress 6
S6  = (E/b)*[-c6 -s6 c6 s6]*[d(1:2); d(3:4)];

% Stress 7
S7  = (E/b2)*[-c7 -s7 c7 s7]*[d(7:8); d(9:10)];

% Stress 8
S8  = (E/b2)*[-c8 -s8 c8 s8]*[d(5:6); d(11:12)];

% Stress 9
S9  = (E/b2)*[-c9 -s9 c9 s9]*[d(3:4); d(5:6)];

% Stress 10
S10 = (E/b2)*[-c10 -s10 c10 s10]*[d(1:2); d(7:8)];

%% Initial Area Calculations: %%
% Initialize area in each element for iterative process

A1  = A(1)  * abs(S1/S_all);
A2  = A(2)  * abs(S2/S_all);
A3  = A(3)  * abs(S3/S_all);
A4  = A(4)  * abs(S4/S_all);
A5  = A(5)  * abs(S5/S_all);
A6  = A(6)  * abs(S6/S_all);
A7  = A(7)  * abs(S7/S_all);
A8  = A(8)  * abs(S8/S_all);
A9  = A(9)  * abs(S9/S_all9);
A10 = A(10) * abs(S10/S_all);

% Area matrix
A = [A1;A2;A3;A4;A5;A6;A7;A8;A9;A10];

%% New Area Calculations: %%
% Iteration process to minimize cross sectional area in each element
% Repeats previous process until cross sectional area is minimized
% The iterations continue until the stress in one of the elements reaches:
    % allowable stress for elements 1,2,3,4,5,6,7,8,10 of 25 kips
    % or allowable stress for element 9 of 75 kips

% new local stiffness matrix calculations:
iteration = 1;
while abs(S1)>S_all||abs(S2)>S_all||abs(S3)>S_all||abs(S4)>S_all||abs(S5)>S_all||abs(S6)>S_all||abs(S7)>S_all||abs(S8)>S_all||abs(S9)>S_all9||abs(S10)>S_all
    if abs(S1)>S_all 
        k1=((A(1)*E)/b)*[c1^2 cs1 -c1^2 -cs1;
                         cs1 s1^2 -cs1 -s1^2;
                         -c1^2 -cs1 c1^2 cs1;
                        -cs1 -s1^2 cs1 s1^2];
    end
    if abs(S2)>S_all 
        k2=((A(2)*E)/b)*[c2^2 cs2 -c2^2 -cs2;
                         cs2 s2^2 -cs2 -s2^2;
                         -c2^2 -cs2 c2^2 cs2;
                        -cs2 -s2^2 cs2 s2^2];
    end
    if abs(S3)>S_all
        k3=((A(3)*E)/b)*[c3^2 cs3 -c3^2 -cs3;
                         cs3 s3^2 -cs3 -s3^2;
                         -c3^2 -cs3 c3^2 cs3;
                        -cs3 -s3^2 cs3 s3^2];
    end
    if abs(S4)>S_all
        k4=((A(4)*E)/b)*[c4^2 cs4 -c4^2 -cs4;
                         cs4 s4^2 -cs4 -s4^2;
                         -c4^2 -cs4 c4^2 cs4;
                        -cs4 -s4^2 cs4 s4^2];
    end
    if abs(S5)>S_all
        k5=((A(5)*E)/b)*[c5^2 cs5 -c5^2 -cs5;
                         cs5 s5^2 -cs5 -s5^2;
                         -c5^2 -cs5 c5^2 cs5;
                        -cs5 -s5^2 cs5 s5^2];
    end
    if abs(S6)>S_all
        k6=((A(6)*E)/b)*[c6^2 cs6 -c6^2 -cs6;
                         cs6 s6^2 -cs6 -s6^2;
                         -c6^2 -cs6 c6^2 cs6;
                        -cs6 -s6^2 cs6 s6^2];
    end
    if abs(S7)>S_all
        k7=((A(7)*E)/b2)*[c7^2 cs7 -c7^2 -cs7;
                          cs7 s7^2 -cs7 -s7^2;
                          -c7^2 -cs7 c7^2 cs7;
                         -cs7 -s7^2 cs7 s7^2];
    end
    if abs(S8)>S_all
        k8=((A(8)*E)/b2)*[c8^2 cs8 -c8^2 -cs8;
                          cs8 s8^2 -cs8 -s8^2;
                          -c8^2 -cs8 c8^2 cs8;
                         -cs8 -s8^2 cs8 s8^2];
    end
    if abs(S9)>S_all9
        k9=((A(9)*E)/b2)*[c9^2 cs9 -c9^2 -cs9;
                          cs9 s9^2 -cs9 -s9^2;
                          -c9^2 -cs9 c9^2 cs9;
                         -cs9 -s9^2 cs9 s9^2];
    end
    if abs(S10)>S_all
        k10=((A(10)*E)/b2)*[c10^2 cs10 -c10^2 -cs10;
                            cs10 s10^2 -cs10 -s10^2;
                            -c10^2 -cs10 c10^2 cs10;
                           -cs10 -s10^2 cs10 s10^2];
    end

% New Global K Calculations:

k11 = k2(1:2,1:2)+k6(1:2,1:2)+k10(1:2,1:2); % Location (u1,u1)
k12 = k6(1:2,3:4); % Location (u1,v2)
k13 = k2(1:2,3:4); % Location (u1,v3)
k14 = k10(1:2,3:4); % Location (u1,v4)
k22 = k4(1:2,1:2)+k6(3:4,3:4)+k9(1:2,1:2); % Location (u2,v2)
k23 = k9(1:2,3:4); % Location (u2,v3)
k24 = k4(1:2,3:4); % Location (u2,v4)
k33 = k1(1:2,1:2)+k2(3:4,3:4)+k5(1:2,1:2)+k8(1:2,1:2)+k9(3:4,3:4); % Location (u3,v3)
k34 = k5(1:2,3:4); % Location (u3,v4)
k44 = k3(1:2,1:2)+k4(3:4,3:4)+k5(3:4,3:4)+k7(1:2,1:2)+k10(3:4,3:4); % Location (u4,v4)

% Symmetrical K Matrix: k21 = k12, k31= k13, k41 = k14, etc.
k21 = k12; % Location (u2,v1)
k31 = k13; % Location (u3,v1)
k32 = k23; % Location (u3,v2)
k41 = k14; % Location (u4,v1)
k42 = k24; % Location (u4,v2)
k43 = k34; % Location (u4,v3)

% New Global K Matrix:
K = [k11 k12 k13 k14;
     k21 k22 k23 k24;
     k31 k32 k33 k34;
     k41 k42 k43 k44];

% New displacements
d = K\F;                     % Solving the displacements (u1,v1,u2,v3,u3,v3,u4,v4)
d(12,1) = 0;                 % New d which the zeros for 

% New stress in each Element Calculations:

% Stress 1
S1  = (E/b)*[-c1 -s1 c1 s1]*[d(5:6); d(9:10)];

% Stress 2
S2  = (E/b)*[-c2 -s2 c2 s2]*[d(1:2); d(5:6)];

% Stress 3
S3  = (E/b)*[-c3 -s3 c3 s3]*[d(7:8); d(11:12)];

% Stress 4
S4  = (E/b)*[-c4 -s4 c4 s4]*[d(3:4); d(7:8)];

% Stress 5
S5  = (E/b)*[-c5 -s5 c5 s5]*[d(5:6); d(7:8)];

% Stress 6
S6  = (E/b)*[-c6 -s6 c6 s6]*[d(1:2); d(3:4)];

% Stress 7
S7  = (E/b2)*[-c7 -s7 c7 s7]*[d(7:8); d(9:10)];

% Stress 8
S8  = (E/b2)*[-c8 -s8 c8 s8]*[d(5:6); d(11:12)];

% Stress 9
S9  = (E/b2)*[-c9 -s9 c9 s9]*[d(3:4); d(5:6)];

% Stress 10
S10 = (E/b2)*[-c10 -s10 c10 s10]*[d(1:2); d(7:8)];

% New Stress Matrix:
S = [S1;S2;S3;S4;S5;S6;S7;S8;S9;S10];

% New Area Calculations:
A1  = A(1)  * abs(S1/S_all);
A2  = A(2)  * abs(S2/S_all);
A3  = A(3)  * abs(S3/S_all);
A4  = A(4)  * abs(S4/S_all);
A5  = A(5)  * abs(S5/S_all);
A6  = A(6)  * abs(S6/S_all);
A7  = A(7)  * abs(S7/S_all);
A8  = A(8)  * abs(S8/S_all);
A9  = A(9)  * abs(S9/S_all9);
A10 = A(10) * abs(S10/S_all);

% New Area Matrix Correction:
A = [A1;A2;A3;A4;A5;A6;A7;A8;A9;A10];

% Ensures that the cross sectional area of each element is above minimum
iteration=iteration+1;
for i=1:length(A)
    if A(i)<CSA_Min
        A(i)=CSA_Min;
    end
end

end

%% Weight Calculations:

% Weight of structure with factor of safety
W = SF*density*(b*A(1)+b*A(2)+b*A(3)+b*A(4)+b*A(6)+b2*A(7)+b2*A(8)+b2*A(9)+b2*A(10));

%% Results:

fprintf('Number of iterations: %.5f iterations\n', iteration)
fprintf('The optimal weight: %.5f lbs\n', W)
fprintf('Stress in Element 1: %.5f psi\n', S1)
fprintf('Stress in Element 2: %.5f psi\n', S2)
fprintf('Stress in Element 3: %.5f psi\n', S3)
fprintf('Stress in Element 4: %.5f psi\n', S4)
fprintf('Stress in Element 5: %.5f psi\n', S5)
fprintf('Stress in Element 6: %.5f psi\n', S6)
fprintf('Stress in Element 7: %.5f psi\n', S7)
fprintf('Stress in Element 8: %.5f psi\n', S8)
fprintf('Stress in Element 9: %.5f psi\n', S9)
fprintf('Stress in Element 10: %.5f psi\n', S10)
fprintf('The optimized area in Element 1 is: %.5f in^2\n',A(1)*SF)
fprintf('The optimized area in Element 2 is: %.5f in^2\n',A(2)*SF)
fprintf('The optimized area in Element 3 is: %.5f in^2\n',A(3)*SF)
fprintf('The optimized area in Element 4 is: %.5f in^2\n',A(4)*SF)
fprintf('The optimized area in Element 5 is: %.5f in^2\n',A(5)*SF)
fprintf('The optimized area in Element 6 is: %.5f in^2\n',A(6)*SF)
fprintf('The optimized area in Element 7 is: %.5f in^2\n',A(7)*SF)
fprintf('The optimized area in Element 8 is: %.5f in^2\n',A(8)*SF)
fprintf('The optimized area in Element 9 is: %.5f in^2\n',A(9)*SF)
fprintf('The optimized area in Element 10 is: %.5f in^2\n',A(10)*SF)