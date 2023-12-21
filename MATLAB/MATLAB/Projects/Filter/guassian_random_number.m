clear;clc;close all;

signoise = 1;
count = 0;
for I = 1:1000
    X = signoise*randn;
    count = count + 1;
    arrayI(count) = I;
    arrayX(count) = X;
end
output = [arrayI',arrayX'];
disp ' simulation finished'

plot(arrayI,arrayX)