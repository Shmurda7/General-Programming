function avg = MovAvgFilter(x)
%
%
persistent n xbuf
persistent firstRun

if isempty(firstRun)
    %increasing n, makes it smoother, but could offset it a bit
    n = 100;
    xbuf = x * ones(n, 1);

    firstRun = 1;
end

for m = 1:n - 1
    xbuf(m) = xbuf(m+1);
end
xbuf(n) = x;

avg = sum(xbuf) / n;

