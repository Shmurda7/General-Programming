clear;clc;

%% Dimensions %%
b = 360; %in
Sf = 1.5;
P1 = 66.67; %kips
P2 = 66.67; %kips
rho = 0.1; %lb/in3
E = 10^4; %ksi
stress_all = 25; %ksi
Ai = 1; %in2
Across = 0.1;
% member 9
nine_stress_all = 75; %ksi

%force matrix
F = [ 0; %1
      0;
      0; %2
    -P2;
      0; %3
      0;
      0; %4
    -P1;
      0; %5
      0;
      0; %6
      0];

%displacement
d =[0;
   0;
   0;
   0;
   0;
   0;
   0;
   0;
   0;
   0;
   0;
   0]; 


%element 1 
%u5 v5 u3 v3
angle = 0;
C = cos(angle);
S = sin(angle);

k1 = [ C S -C -S;
              S C -S -C;
              -C -S C S;
              -S -C S C];

%element 2
%u3 v3 u1 v1
angle = 0;
C = cos(angle);
S = sin(angle);

k2 = [ C S -C -S;
              S C -S -C;
              -C -S C S;
              -S -C S C];

%element 3
%u6 v6 u4 v4
angle = 0;
C = cos(angle);
S = sin(angle);

k3 = [ C S -C -S;
              S C -S -C;
              -C -S C S;
              -S -C S C];

%element 4
%u4 v4 u2 v2
angle = 0;
C = cos(angle);
S = sin(angle);

k4 = [ C S -C -S;
              S C -S -C;
              -C -S C S;
              -S -C S C];

%element 5
%u3 v3 u4 v4
angle = 90;
C = cos(angle);
S = sin(angle);

k5 = [ C S -C -S;
              S C -S -C;
              -C -S C S;
              -S -C S C];

%element 6
%u1 v1 u2 v2
angle = 90;
C = cos(angle);
S = sin(angle);

k6 = [ C S -C -S;
              S C -S -C;
              -C -S C S;
              -S -C S C];

%element 7
%u5 v5 u4 v4
angle = 135;
C = cos(angle);
S = sin(angle);

k7 = [ C S -C -S;
              S C -S -C;
              -C -S C S;
              -S -C S C];

%element 8
%u6 v6 u3 v3
angle = 45;
C = cos(angle);
S = sin(angle);

k8 = [ C S -C -S;
              S C -S -C;
              -C -S C S;
              -S -C S C];

%element 9
%u3 v3 u2 v2
angle = 135;
C = cos(angle);
S = sin(angle);

k9 = [ C S -C -S;
              S C -S -C;
              -C -S C S;
              -S -C S C];

%elemnt 10
%u4 v4 u1 v1
angle = 45;
C = cos(angle);
S = sin(angle);
              
k10 = [ C S -C -S;
              S C -S -C;
              -C -S C S;
              -S -C S C];

%global k matrix
           %               u1,                   v1,                  u2,                     v2,                        u3,                             	 v3,     		     u4,     v4,    u5, v5, u6, v6
global_k = [ k2(3,3)+k6(1,1)+k10(3,3), k2(3,4)+k6(1,2)+k10(3,4), k6(1,3)		       , k6(1,4)			  , k2(3,1) 			     , k2(3,2) 			, k10(1,1), k10(1,2), 0, 0, 0, 0;      
             k2(4,3)+k6(2,1)+k10(4,3), k2(4,4)+k6(2,2)+k10(4,4), k6(2,3)		       , k6(3,4)		  	  , k2(4,1) 			     , k2(4,2) 			, k10(3,1), k10(3,2), 0, 0, 0, 0; 
             k6(1,3)                 ,  k6(2,3)                , k4(3,3)+k6(3,3)+k9(3,3), k4(3,4)+k6(3,4)+k9(3,4), k9(1,1) 			     , k9(1,2) 			, k4(1,1), k4(1,2),   0, 0, 0, 0;
             k6(1,4)                 ,  k6(3,4)			, k4(4,3)+k6(4,3)+k9(4,3), k4(4,4)+k6(4,4)+k9(4,4), k9(2,1)				     , k9(2,2) 			, k4(2,1), k4(2,2),   0, 0, 0, 0;
             k2(3,1)                 ,  k2(4,1)			,  k9(1,3)               ,  k9(1,4)               , k1(3,3)+k2(1,1)+k5(1,1)+k8(3,3), k1(3,4)+k5(1,2)+k8(3,4), k5(1,3), k5(1,4),   0, 0, 0, 0;
             k2(3,2)		          ,  k2(4,2)			,  k9(2,3)			 ,  k9(2,4)			  , k1(4,3)+k2(2,1)+k5(2,1)+k8(4,3), k1(4,4)+k5(2,2)+k8(4,4), k5(2,3), k5(2,4),   0, 0, 0, 0;
             k10(1,1)                ,  k10(3,1)		      ,  k4(1,3)			 ,  k4(1,4)			  , k5(3,1)				     , k5(3,2)			, k3(3,3)+k4(1,1)+k5(3,3)+k7(3,3)+k10(1,1), k3(3,4)+k4(1,2)+k5(3,4)+k7(3,4)+k10(1,2), 0, 0, 0,0;
            k10(1,2)		    ,  k10(3,2)			,  k4(2,3)			 ,  k4(2,4)			  , k5(4,1)				     , k5(4,2)			, k3(4,3)+k4(2,1)+k5(4,3)+k7(4,3)+k10(2,1), k3(4,4)+k4(2,2)+k5(4,4)+k7(4,4)+k10(2,2), 0, 0, 0,0;
                        0            ,           0             ,     0      		 ,	  0      		  ,		 0      		     ,	 0    		,    0   ,      0 ,   0, 0, 0, 0;
                      0            ,           0             ,     0   		       ,	  0       		  ,		 0      		     ,	 0      		,    0   ,      0 ,   0, 0, 0, 0;
                       0            ,           0             ,     0   		       ,	  0        		  ,		 0     		     ,	 0     		,    0   ,      0 ,   0, 0, 0, 0;
                        0            ,           0             ,     0  		       ,	  0       		  ,		 0    		     ,	 0     		,    0   ,      0 ,   0, 0, 0, 0];
%force, stiff, displacement
%F = kx

d = F.*pinv(global_k);



