function out = skew(vec)

if length(vec) ~= 3
	error('Only 3x1 skew symmetric operator coded')
end

out = zeros(3,3);

out(1,3) = vec(2);
out(1,2) = -vec(3);
out(2,1) = vec(3);
out(2,3) = -vec(1);
out(3,1) = -vec(2);
out(3,2) = vec(1);