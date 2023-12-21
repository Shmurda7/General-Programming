clear
clc
sym b; %b is the half width 
sym h; %h is the half height
sym E; %E is the Modulus of elasticity
sym nu;%nu is the  ___
sym t; %t is the thickness of the bars
syms x y
b = 0.25;
h = 0.125;
E = 210*10^9;
nu = 0.3;
t = 5*10^-3;
C = E/(1-nu^2).*[1 nu 0; nu 1 0; 0 0 (1-nu)/2];
B = (1/(4*b*h)).*[-(h-y) 0 (h-y) 0 h+y 0 -h-y 0; 0 -(b-x) 0 -b-x 0 b+x 0 b-x; -(b-x) -(h-y) -(b+x) (h-y) (b+x) h+y b-x -(h+y)];
K = t.*int(int(transpose(B)*C*B,x,-1*b,b),y,-1*h,h);
L = [K(3,3) K(3,4); K(4,3) K(4,4)]
F = [40000*cos(pi/3); -40000*sin(pi/3)];
D = inv(L)*F
%U= [16594901434795216431118166810695275/568975016902085927404411910059170660352;-310026255036993937248532144546275/8890234639095092615693936094674541568]
x = -0.167;
y = 0;

B = (1/(4*b*h)).*[-(h-y) 0 (h-y) 0 h+y 0 -h-y 0; 0 -(b-x) 0 -b-x 0 b+x 0 b-x; -(b-x) -(h-y) -(b+x) (h-y) (b+x) h+y b-x -(h+y)];

B = [B(1,3) B(1,4); B(2,3) B(2,4); B(3,3) B(3,4)]
epsilon = B*D
%epsilon = [16594901434795216431118166810695275/568975016902085927404411910059170660352;1029287166722819871665126719893633/44451173195475463078469680473372707840;-154303474375358178470842600066316313/2844875084510429637022059550295853301760]
sigma = C*epsilon
%sigma=[388440016518112709229826761769796050613071075406451/46610433384618879172969423672047260496035840;343182027183478800706672880401606862769328924593549/46610433384618879172969423672047260496035840;-816773393961280451903625253201523457355615338704091/186441733538475516691877694688189041984143360]