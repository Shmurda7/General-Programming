function avg = AvgFilter(x)
%
% persistent, anytime you call the function it remembers the same variable
persistent prevAvg k 
persistent firstRun

%initializes first time run
if isempty(firstRun)
    k = 1;
    prevAvg = 0;
    firstRun =1;
end

%equations learned
alpha = (k - 1) / k;
avg = alpha * prevAvg + (1 - alpha)*x;

%the looping and setting new values portion
prevAvg = avg;
k = k + 1;
