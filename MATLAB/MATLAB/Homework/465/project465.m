clc
clear
A = ones(10,1); %initial area in inches
L = [360; 360; 360; 360; 360; 360; 509.12; 509.12; 509.12; 509.12];% length to inplement
E = 10^7 ;%psi
sigma_all =[25000; 25000; 25000; 25000; 25000; 25000; 25000; 25000; 75000; 25000];
sigma = zeros(10,1);
Anew = zeros(10,1);
difference = sigma_all-sigma;
w = 0
while w ~= 100 
    Element_table = [1 5 3 A(1,1)*E/L(1,1) 1 0; 2 3 1 A(2,1)*E/L(2,1) 1 0; 3 6 4 A(3,1)*E/L(3,1) 1 0; 4 4 2 A(4,1)*E/L(4,1) 1 0; 5 4 3 A(5,1)*E/L(5,1) 0 1; 6 2 1 A(6,1)*E/L(6,1) 0 1; 7 5 4 A(7,1)*E/L(7,1) sqrt(2)/2 -sqrt(2)/2; 8 6 3 A(8,1)*E/L(8,1) sqrt(2)/2 sqrt(2)/2; 9 3 2 A(9,1)*E/L(9,1) sqrt(2)/2 -sqrt(2)/2; 10 4 1 A(10,1)*E/L(10,1) sqrt(2)/2 sqrt(2)/2];
    r = height(Element_table); %number of times we will iterate is depending on the number of elements
    sym C; %cosin
    sym S; %sin
    K = zeros(12,12);
    for i=1:r
        C = Element_table(i,5);
        S = Element_table(i,6);
        Constant = Element_table(i,4);
        k = Constant.*[C^2 C*S -(C^2) -(C*S); C*S S^2 -(C*S) -(S^2);-(C^2) -(C*S) (C^2) (C*S);-(C*S) -(S^2) (C*S) (S^2)];
        % we now jhave all the different ks we need to put them in the big K
        % matrix
        a = Element_table(i,2);%first node
        b = Element_table(i,3); %second node
        K(2*a-1:2*a,2*a-1:2*a) =  K(2*a-1:2*a,2*a-1:2*a) + k(1:2,1:2); %that is for element (a,a) 
        K(2*a-1:2*a,2*b-1:2*b) =  K(2*a-1:2*a,2*b-1:2*b) + k(1:2,3:4); %element (b,a)worrry
        K(2*b-1:2*b,2*a-1:2*a) =  K(2*b-1:2*b,2*a-1:2*a) + k(3:4,1:2); %element (a,b)worry
        K(2*b-1:2*b,2*b-1:2*b) =  K(2*b-1:2*b,2*b-1:2*b) + k(3:4,3:4); %element (b,b)
    end
    disp(K);
    K2 = K(1:8,1:8); %truncate the ones that are gonna be 0
    P1 = 66.67*10^3;
    P2 = 66.67*10^3;
    F = [0; 0; 0; -P2; 0; 0; 0; -P1]
    u = K2\F;
    u = [u;zeros(4,1)] %add the u and v that are 0
    for i=1:r
        C = Element_table(i,5);
        S = Element_table(i,6);
        a = Element_table(i,2);%first node
        b = Element_table(i,3); %second node
        sigma(i,1)= (E/L(i,1))*(C*(u(2*b-1,1)-u(2*a-1,1))-S*(u(2*b,1)-u(2*a,1)));

        Anew(i,1) = A(i,1)*abs(sigma(i,1)/sigma_all(i,1));
        if Anew(i,1)>0.1
            A(i,1) = Anew(i,1);
        end
        difference(i,1) = sigma_all(i,1)-sigma(i,1);
    end
    disp(sigma)
    disp(A)
    disp(difference)
    w = w+1
end

