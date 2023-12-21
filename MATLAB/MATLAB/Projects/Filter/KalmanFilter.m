function rcs_dot = KalmanFilter(A, q)
%
%
persistent H Q R 
persistent x P 
persistent firstRun

if isempty(firstRun)
      H = eye(4);
    
      Q = 0.0001*eye(4); 
      R = 10*eye(4);
    
      x = [1 0 0 0]';  
      P = 1*eye(4);

    firstRun = 1;
end

xp = A * x;
Pp = A * P * A' + Q;

K = Pp * H' * inv(H * Pp * H' + R);

x = xp + K * (q - H * xp);
P = Pp - K * H * Pp;

rcs_dot = [phi, theta, psi]';
