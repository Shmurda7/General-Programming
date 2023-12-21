clear;clc;

%choose the points for each element
xi = -.25;
yi = -.125;

xj = .25;
yj = -.125;

xm = 0;
ym = 0;

Bi = yj-ym
Bj = ym-yi
Bm = yi-yj

Yi = xm-xj
Yj = xi-xm
Ym = xj-xi

b= .5;
h = .25;
t = .005;
v = 0.3;
A = (1/2)*(b/2)*h;

%find the B, C, and K matrix for that element
B = [Bi, 0, Bj, 0, Bm, 0;
     0, Yi, 0, Yj, 0, Ym;
     Yi, Bi, Yj, Bj, Ym, Bm];

B_Matrix = (1/(2*A))*B;

C = [1, v, 0;
     v, 1, 0;
     0, 0, (1-0.3)/2];

calc = (210*10^9)/(1-(v^2));
C_Matrix = calc*C;

K = t*A*transpose(B_Matrix)*C_Matrix*B_Matrix;

%Simplified K Matrix
K_mat = [3.125, 0.6348, -2.3438, -1.1718;
            0.6348, 2.7276, -1.3672, -4.248;
            -2.3438, -1.3672, 6.2501, 0.6348;
            -1.1718, -4.248, 0.6348, 14.1845];

K_matrix = K_mat * 10^4;

F = [34631.016;
    20000;
    0;
    0];

%solving for the displacement
%d = K_matrix^-1*F;

%put the diplacement for each element
d = [0;
    0;
    0;
    0;
    1.14;
    -1.03];

displacement = d*(10^-5);

%solves for the shear
shear = C_Matrix*B_Matrix*displacement;

sx = -1.061*10^7;
sy = -0.318*10^7;
txy = 0.334*10^7;

max = ((sx+sy)/2)+sqrt(((sx-sy)/2)^2+txy^2)
min = ((sx+sy)/2)-sqrt(((sx-sy)/2)^2+txy^2)

