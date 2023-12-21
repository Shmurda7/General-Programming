function z = GetVolt()
%
% randn is a random scalar from -1 to 1
%so w is the measurement error
w = 0 + 4 * randn;
%then z is the measurement value
z = 14.4 + w;
