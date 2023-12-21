function ptp = Quaternions2EulerAngles(q0123)

%%%save time by commenting this and transposeing it earlier
% s = size(q0123);
% if s(1) == 4 && s(2) == 1
%     q0123 = q0123';
% end
q0 = q0123(:,1);
q1 = q0123(:,2);
q2 = q0123(:,3);
q3 = q0123(:,4);

ptp(:,1) = (atan2(2.*(q0.*q1+q2.*q3),1-2.*(q1.^2+q2.^2))); %phi
ptp(:,2) = asin(2.*(q0.*q2-q3.*q1)); %theta
ptp(:,3) = atan2(2.*(q0.*q3+q1.*q2),1-2.*(q2.^2+q3.^2)); %psi

%again commenting for sim speed optimization
%ptp = real(ptp);