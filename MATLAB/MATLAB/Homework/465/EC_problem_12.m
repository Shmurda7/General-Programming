clc; clear;
% problem 12

% givens
E=200e9; 
t=0.01; 
v=0.3;  
C=(E/(1-(v.^2)))*[1 v 0; v 1 0; 0 0 ((1-v)/2)];
A=0.5*1*1;

% step 1
% solve for [k] matrix for each element in order to find global [K] matrix
% k = tA[B]^T[C][B]

% element 1
ix1=0;
iy1=0;
jx1=1;
jy1=0;
mx1=0;
my1=1;
bi1=jy1-my1;
bj1=my1-iy1;
bm1=iy1-jy1;
gi1=mx1-jx1;
gj1=ix1-mx1;
gm1=jx1-ix1;
B1=(1/(2*A))*[bi1, 0, bj1, 0, bm1, 0;
              0, gi1, 0, gj1, 0, gm1;
              gi1 bi1 gj1 bj1 gm1 bm1];
Bt1=B1.';
k1=(t*A)*(Bt1)*(C)*(B1);

% element 2
ix2=1;
iy2=0;
jx2=1;
jy2=1;
mx2=0;
my2=1;
bi2=jy2-my2;
bj2=my2-iy2;
bm2=iy2-jy2;
gi2=mx2-jx2;
gj2=ix2-mx2;
gm2=jx2-ix2;
B2=(1/(2*A))*[bi2, 0, bj2, 0, bm2, 0;
                 0, gi2, 0, gj2, 0, gm2;
               gi2, bi2, gj2, bj2, gm2, bm2];
Bt2=B2.';
k2=(t*A)*(Bt2)*(C)*(B2);

% element 3
ix3=1;
iy3=0;
jx3=2;
jy3=0;
mx3=1;
my3=1;
bi3=jy3-my3;
bj3=my3-iy3;
bm3=iy3-jy3;
gi3=mx3-jx3;
gj3=ix3-mx3;
gm3=jx3-ix3;
B3=(1/(2*A))*[bi3, 0, bj3, 0, bm3, 0;
              0, gi3, 0, gj3, 0, gm3;
              gi3 bi3 gj3 bj3 gm3 bm3];
Bt3=B3.';
k3=(t*A)*(Bt3)*(C)*(B3);

% element 4
ix4=2;
iy4=0;
jx4=2;
jy4=1;
mx4=1;
my4=1;
bi4=jy4-my4;
bj4=my4-iy4;
bm4=iy4-jy4;
gi4=mx4-jx4;
gj4=ix4-mx4;
gm4=jx4-ix4;
B4=(1/(2*A))*[bi4, 0, bj4, 0, bm4, 0;
              0, gi4, 0, gj4, 0, gm4;
              gi4 bi4 gj4 bj4 gm4 bm4];
Bt4=B4.';
k4=(t*A)*(Bt4)*(C)*(B4);

% element 5
ix5=2;
iy5=0;
jx5=3;
jy5=0;
mx5=2;
my5=1;
bi5=jy5-my5;
bj5=my5-iy5;
bm5=iy5-jy5;
gi5=mx5-jx5;
gj5=ix5-mx5;
gm5=jx5-ix5;
B5=(1/(2*A))*[bi5, 0, bj5, 0, bm5, 0;
              0, gi5, 0, gj5, 0, gm5;
              gi5 bi5 gj5 bj5 gm5 bm5];
Bt5=B5.';
k5=(t*A)*(Bt5)*(C)*(B5);

% element 6
ix6=3;
iy6=0;
jx6=3;
jy6=1;
mx6=2;
my6=1;
bi6=jy6-my6;
bj6=my6-iy6;
bm6=iy6-jy6;
gi6=mx6-jx6;
gj6=ix6-mx6;
gm6=jx6-ix6;
B6=(1/(2*A))*[bi6, 0, bj6, 0, bm6, 0;
              0, gi6, 0, gj6, 0, gm6;
              gi6 bi6 gj6 bj6 gm6 bm6];
Bt6=B6.';
k6=(t*A)*(Bt6)*(C)*(B6);

% element 7
ix7=3;
iy7=0;
jx7=4;
jy7=0;
mx7=3;
my7=1;
bi7=jy7-my7;
bj7=my7-iy7;
bm7=iy7-jy7;
gi7=mx7-jx7;
gj7=ix7-mx7;
gm7=jx7-ix7;
B7=(1/(2*A))*[bi7, 0, bj7, 0, bm7, 0;
              0, gi7, 0, gj7, 0, gm7;
              gi7 bi7 gj7 bj7 gm7 bm7];
Bt7=B7.';
k7=(t*A)*(Bt7)*(C)*(B7);

% element 8
ix8=4;
iy8=0;
jx8=4;
jy8=1;
mx8=3;
my8=1;
bi8=jy8-my8;
bj8=my8-iy8;
bm8=iy8-jy8;
gi8=mx8-jx8;
gj8=ix8-mx8;
gm8=jx8-ix8;
B8=(1/(2*A))*[bi8, 0, bj8, 0, bm8, 0;
              0, gi8, 0, gj8, 0, gm8;
              gi8 bi8 gj8 bj8 gm8 bm8];
Bt8=B8.';
k8=(t*A)*(Bt8)*(C)*(B8);

% element 9
ix9=4;
iy9=0;
jx9=5;
jy9=0;
mx9=4;
my9=1;
bi9=jy9-my9;
bj9=my9-iy9;
bm9=iy9-jy9;
gi9=mx9-jx9;
gj9=ix9-mx9;
gm9=jx9-ix9;
B9=(1/(2*A))*[bi9, 0, bj9, 0, bm9, 0;
              0, gi9, 0, gj9, 0, gm9;
              gi9 bi9 gj9 bj9 gm9 bm9];
Bt9=B9.';
k9=(t*A)*(Bt9)*(C)*(B9);

% element 10
ix10=5;
iy10=0;
jx10=5;
jy10=1;
mx10=4;
my10=1;
bi10=jy10-my10;
bj10=my10-iy10;
bm10=iy10-jy10;
gi10=mx10-jx10;
gj10=ix10-mx10;
gm10=jx10-ix10;
B10=(1/(2*A))*[bi10, 0, bj10, 0, bm10, 0;
              0, gi10, 0, gj10, 0, gm10;
              gi10 bi10 gj10 bj10 gm10 bm10];
Bt10=B10.';
k10=(t*A)*(Bt10)*(C)*(B10);

% matrix for nodes
k0=[0,0; 0,0];

% step 2 
% solve for global [K]
% node numbers start at 1 at the bottom left and move counter clockwise 
% ending at node 12 at the roller 
% node 1 is static on both axis (u=0, v=0) and node 12 is static on the x 
% axis (u=0)

ku2u2=k1(3:4,3:4)+k2(1:2,1:2)+k3(1:2,1:2);
ku2u3=k3(1:2,3:4);
ku2u4=k0;
ku2u5=k0;
ku2u6=k0;
ku2u7=k0;
ku2u8=k0;
ku2u9=k0;
ku2u10=k0;
ku2u11=k2(1:2,3:4)+k3(1:2,5:6);
ku2v12=k1(6,3)+k2(6,1);
kv2v12=k1(6,4)+k2(6,2);
ku3u3=k3(3:4,3:4)+k4(1:2,1:2)+k5(1:2,1:2);
ku3u4=k5(1:2,3:4);
ku3u5=k0;
ku3u6=k0;
ku3u7=k0;
ku3u8=k0;
ku3u9=k0;
ku3u10=k4(1:2,3:4)+k5(1:2,5:6);
ku3u11=k3(3:4,5:6)+k4(1:2,5:6);
ku3v12=k0(1,1:2);
ku4u4=k5(3:4,3:4)+k6(1:2,1:2)+k7(1:2,1:2);
ku4u5=k7(1:2,3:4);
ku4u6=k0;
ku4u7=k0;
ku4u8=k0;
ku4u9=k6(1:2,3:4)+k7(1:2,5:6);
ku4u10=k5(3:4,5:6)+k6(1:2,5:6);
ku4u11=k0;
ku4v12=k0(1,1:2);
ku5u5=k7(3:4,3:4)+k8(1:2,1:2)+k9(1:2,1:2);
ku5u6=k9(1:2,3:4);
ku5u7=k0;
ku5u8=k8(1:2,3:4)+k9(1:2,5:6);
ku5u9=k7(3:4,5:6)+k8(1:2,5:6);
ku5u10=k0;
ku5u11=k0;
ku5v12=k0(1,1:2);
ku6u6=k9(3:4,3:4)+k10(1:2,1:2);
ku6u7=k10(1:2,3:4);
ku6u8=k9(3:4,5:6)+k10(1:2,5:6);
ku6u9=k0;
ku6u10=k0;
ku6u11=k0;
ku6v12=k0(1,1:2);
ku7u7=k10(3:4,3:4);
ku7u8=k10(3:4,5:6);
ku7u9=k0;
ku7u10=k0;
ku7u11=k0;
ku7v12=k0(1,1:2);
ku8u8=k8(3:4,3:4)+k9(5:6,5:6)+k10(5:6,5:6);
ku8u9=k8(3:4,5:6);
ku8u10=k0;
ku8u11=k0;
ku8v12=k8(1,1:2);
ku9u9=k6(3:4,3:4)+k7(5:6,5:6)+k8(5:6,5:6);
ku9u10=k6(3:4,5:6);
ku9u11=k0;
ku9v12=k0(1,1:2);
ku10u10=k4(3:4,3:4)+k5(5:6,5:6)+k6(5:6,5:6);
ku10u11=k4(3:4,5:6);
ku10v12=k0(1,1:2);
ku11u11=k2(3:4,3:4)+k3(5:6,5:6)+k4(5:6,5:6);
ku11v12=k2(6,3:4);
kv12u2=k1(3:4,6)+k2(1:2,6);
kv12u3=k0(1:2,1);
kv12u4=k0(1:2,1);
kv12u5=k0(1:2,1);
kv12u6=k0(1:2,1);
kv12u7=k0(1:2,1);
kv12u8=k0(1:2,1);
kv12u9=k0(1:2,1);
kv12u10=k0(1:2,1);
kv12u11=k2(3:4,6);
kv12v12=k1(6,6)+k2(6,6);
K=[ku2u2 ku2u3 ku2u4 ku2u5 ku2u6 ku2u7 ku2u8 ku2u9 ku2u10 ku2u11 ;
   ku2u3.' ku3u3 ku3u4 ku3u5 ku3u6 ku3u7 ku3u8 ku3u9 ku3u10 ku3u11 ;
   ku2u4.' ku3u4.' ku4u4 ku4u5 ku4u6 ku4u7 ku4u8 ku4u9 ku4u10 ku4u11 ;
   ku2u5.' ku3u5.' ku4u5.' ku5u5 ku5u6 ku5u7 ku5u8 ku5u9 ku5u10 ku5u11 ;
   ku2u6.' ku3u6.' ku4u6.' ku5u6.' ku6u6 ku6u7 ku6u8 ku6u9 ku6u10 ku6u11 ;
   ku2u7.' ku3u7.' ku4u7.' ku5u7.' ku6u7.' ku7u7 ku7u8 ku7u9 ku7u10 ku7u11 ;
   ku2u8.' ku3u8.' ku4u8.' ku5u8.' ku6u8.' ku7u8.' ku8u8 ku8u9 ku8u10 ku8u11 ;
   ku2u9.' ku3u9.' ku4u9.' ku5u9.' ku6u9.' ku7u9.' ku8u9.' ku9u9 ku9u10 ku9u11 ;
   ku2u10.' ku3u10.' ku4u10.' ku5u10.' ku6u10.' ku7u10.' ku8u10.' ku9u10.' ku10u10 ku10u11;
   ku2u11.' ku3u11.' ku4u11.' ku5u11.' ku6u11.' ku7u11.' ku8u11.' ku9u11.' ku10u11.' ku11u11];
K(21,1)=ku2v12; K(21,2)=kv2v12; K(21,2:18)=0; K(21,19:20)=ku11v12;
K(1,21)=ku2v12; K(2,21)=kv2v12; K(2:18,21)=0; K(19:20,21)=kv12u11; K(21,21)=kv12v12;

% step 3 
% solve for displacement vector {d} in order to find displacement vector to
% find stresses by first establishing force vector {F}
F=zeros(21,1); F(9,1)=-100000; F(11,1)=100000; 
d=K\F;

% step 4 
% solve for stresses on each element using the equation sigma = [C][B]{d}
d1=[0; 0; d(1,1); d(2,1); 0; d(21,1)];
d2=[d(1,1); d(2,1); d(19,1); d(20,1); 0; d(21,1)];
d3=[d(1,1); d(2,1); d(3,1); d(4,1); d(19,1); d(20,1)];
d4=[d(3,1); d(4,1); d(17,1); d(18,1); d(19,1); d(20,1)];
d5=[d(3,1); d(4,1); d(5,1); d(6,1); d(17,1); d(18,1)];
d6=[d(5,1); d(6,1); d(15,1); d(16,1); d(17,1); d(18,1)];
d7=[d(5,1); d(6,1); d(7,1); d(8,1); d(15,1); d(16,1)];
d8=[d(7,1); d(8,1); d(13,1); d(14,1); d(15,1); d(16,1)];
d9=[d(7,1); d(8,1); d(9,1); d(10,1); d(13,1); d(14,1)];
d10=[d(9,1); d(10,1); d(11,1); d(12,1); d(13,1); d(14,1)];
sig_1=C*B1*d1;
sig_2=C*B2*d2;
sig_3=C*B3*d3;
sig_4=C*B4*d4;
sig_5=C*B5*d5;
sig_6=C*B6*d6;
sig_7=C*B7*d7;
sig_8=C*B8*d8;
sig_9=C*B9*d9;
sig_10=C*B10*d10;
fprintf('Displacement (m), Stress (Pa)')
fprintf('Stresses for element 1:')
sig_1
fprintf('Stresses for element 2:')
sig_2
fprintf('Stresses for element 3:')
sig_3
fprintf('Stresses for element 4:')
sig_4
fprintf('Stresses for element 5:')
sig_5
fprintf('Stresses for element 6:')
sig_6
fprintf('Stresses for element 7:')
sig_7
fprintf('Stresses for element 8:')
sig_8
fprintf('Stresses for element 9:')
sig_9
fprintf('Stresses for element 10:')
sig_10