clc; clear;
%problem 24

%givens
E=200e9; 
t=0.01; 
v=0.3;   
C=(E/(1-(v.^2)))*[1 v 0; v 1 0; 0 0 ((1-v)/2)];
b=1;
h=1;

%step 1
%solve for all the [k]
%luckily the [k] is the same for all 5 elements

kq1=[((3-v)/6), ((1+v)/8), -((3+v)/12), (-1+(3*v))/8;
     ((1+v)/8), ((3-v)/6), ((1-(3*v))/8), (v/6);
     -((3+v)/12), ((1-(3*v))/8), ((3-v)/6), -((1+v)/8);
     (-1+(3*v))/8, (v/6), -((1+v)/8), ((3-v)/6)];

kq2=[(-3+v)/12, -(1+v)/8, (v/6), (1-(3*v))/8;
     -(1+v)/8, (-3+v)/12, -(1+(3*v))/8, -(3+v)/12;
     (v/6), -(1+(3*v))/8, (-3+v)/12, (1+v)/8;
     (1-(3*v))/8, -(3+v)/12, (1+v)/8, (-3+v)/12];


k=((E*t)/(1-(v^2)))*[kq1(1:4,1:4), kq2(1:4,1:4);
                  kq2(1:4,1:4), kq1(1:4,1:4)];
                  k1=k; k2=k; k3=k; k4=k; k5=k;

% step 2 assembliage of the global [k] matrix
k0=[0,0; 0,0];
ku2u2=k1(3:4,3:4)+k2(1:2,1:2);
ku2u3=k2(1:2,3:4);
ku2u4=k0;
ku2u5=k0;
ku2u6=k0;
ku2u7=k0;
ku2u8=k0;
ku2u9=k0;
ku2u10=k2(1:2,5:6);
ku2u11=k2(1:2,7:8)+k1(3:4,5:6);
ku2v12=k1(8,3);
kv2v12=k1(8,4);
ku3u3=k2(3:4,3:4)+k3(1:2,1:2);
ku3u4=k3(1:2,3:4);
ku3u5=k0;
ku3u6=k0;
ku3u7=k0;
ku3u8=k0;
ku3u9=k3(1:2,5:6);
ku3u10=k2(3:4,5:6)+k3(1:2,7:8);
ku3u11=k2(3:4,7:8);
ku3v12=k0(1,1:2);
ku4u4=k3(3:4,3:4)+k4(1:2,1:2);
ku4u5=k4(1:2,3:4);
ku4u6=k0;
ku4u7=k0;
ku4u8=k4(1:2,5:6);
ku4u9=k3(3:4,5:6)+k4(1:2,7:8);
ku4u10=k3(3:4,7:8);
ku4u11=k0;
ku4v12=k0(1,1:2);
ku5u5=k4(3:4,3:4)+k5(1:2,1:2);
ku5u6=k5(1:2,3:4);
ku5u7=k5(1:2,5:6);
ku5u8=k4(3:4,5:6)+k5(1:2,7:8);
ku5u9=k4(3:4,7:8);
ku5u10=k0;
ku5u11=k0;
ku5v12=k0(1,1:2);
ku6u6=k5(3:4,3:4);
ku6u7=k5(3:4,5:6);
ku6u8=k5(3:4,7:8);
ku6u9=k0;
ku6u10=k0;
ku6u11=k0;
ku6v12=k0(1,1:2);
ku7u7=k5(5:6,5:6);
ku7u8=k5(5:6,7:8);
ku7u9=k0;
ku7u10=k0;
ku7u11=k0;
ku7v12=k0(1,1:2);
ku8u8=k4(5:6,5:6)+k5(7:8,7:8);
ku8u9=k4(5:6,7:8);
ku8u10=k0;
ku8u11=k0;
ku8v12=k0(1,1:2);
ku9u9=k3(5:6,5:6)+k4(7:8,7:8);
ku9u10=k3(5:6,7:8);
ku9u11=k0;
ku9v12=k0(1,1:2);
ku10u10=k2(5:6,5:6)+k3(7:8,7:8);
ku10u11=k2(5:6,7:8);
ku10v12=k0(1,1:2);
ku11u11=k1(5:6,5:6)+k2(7:8,7:8);
ku11v12=k1(8,5:6);
kv12u2=k1(3:4,8);
kv12u3=k0(1:2,1);
kv12u4=k0(1:2,1);
kv12u5=k0(1:2,1);
kv12u6=k0(1:2,1);
kv12u7=k0(1:2,1);
kv12u8=k0(1:2,1);
kv12u9=k0(1:2,1);
kv12u10=k0(1:2,1);
kv12u11=k2(5:6,8);
kv12v12=k1(8,8);

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

%solve for displacement 
F=zeros(21,1); F(9,1)=100000; F(11,1)=-100000; 
d=K^1*F;

%solve element displacements
d1=[0; 0; d(1,1); d(2,1); d(19,1); d(20,1); 0; d(21,1)];
d2=[d(1,1); d(2,1); d(3,1); d(4,1); d(17,1); d(18,1); d(19,1); d(20,1)];
d3=[d(3,1); d(4,1); d(5,1); d(6,1); d(15,1); d(16,1); d(17,1); d(18,1)];
d4=[d(5,1); d(6,1); d(7,1); d(8,1); d(13,1); d(14,1); d(15,1); d(16,1)];
d5=[d(7,1); d(8,1); d(9,1); d(10,1); d(11,1); d(12,1); d(13,1); d(14,1)];

%solve element B matrices
%element 1
x1c=0.5; y1c=0.5;
bx1=b+x1c;
bx1_=b-x1c;
hy1_=h-y1c;
hy1=h+y1c;
B1=(1/(b*h))*[-hy1_ 0 hy1_ 0 hy1 0 -hy1 0;
               0 -bx1_ 0 -bx1 0 bx1 0 bx1_;
              -bx1_ -hy1_ -bx1 hy1_ bx1 hy1 bx1_ -hy1];
%element 2
x2c=1.5; y2c=0.5;
bx2=b+x2c;
bx2_=b-x2c;
hy2_=h-y2c;
hy2=h+y2c;
B2=(1/(b*h))*[-hy2_ 0 hy2_ 0 hy2 0 -hy2 0;
               0 -bx2_ 0 -bx2 0 bx2 0 bx2_;
              -bx2_ -hy2_ -bx2 hy2_ bx2 hy2 bx2_ -hy2];
%element 3
x3c=2.5; y3c=0.5;
bx3=b+x3c;
bx3_=b-x3c;
hy3_=h-y3c;
hy3=h+y3c;
B3=(1/(b*h))*[-hy3_ 0 hy3_ 0 hy3 0 -hy3 0;
               0 -bx3_ 0 -bx3 0 bx3 0 bx3_;
              -bx3_ -hy3_ -bx3 hy3_ bx3 hy3 bx3_ -hy3];
%element 4
x4c=3.5; y4c=0.5;
bx4=b+x4c;
bx4_=b-x4c;
hy4_=h-y4c;
hy4=h+y4c;
B4=(1/(b*h))*[-hy4_ 0 hy4_ 0 hy4 0 -hy4 0;
               0 -bx4_ 0 -bx4 0 bx4 0 bx4_;
              -bx4_ -hy4_ -bx4 hy4_ bx4 hy4 bx4_ -hy4];
%element 5
x5c=4.5; y5c=0.5;
bx5=b+x5c;
bx5_=b-x5c;
hy5_=h-y5c;
hy5=h+y5c;
B5=(1/(b*h))*[-hy5_ 0 hy5_ 0 hy5 0 -hy5 0;
               0 -bx5_ 0 -bx5 0 bx5 0 bx5_;
              -bx5_ -hy5_ -bx5 hy5_ bx5 hy5 bx5_ -hy5];

%calculating the stress
sig_1=C*B1*d1;
sig_2=C*B2*d2;
sig_3=C*B3*d3;
sig_4=C*B4*d4;
sig_5=C*B5*d5;
fprintf('Stress (Pa)')
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

