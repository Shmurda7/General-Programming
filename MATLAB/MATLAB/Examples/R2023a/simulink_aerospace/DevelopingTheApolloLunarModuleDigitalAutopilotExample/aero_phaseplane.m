function aero_phaseplane(u)
%aero_phaseplane plot for lunar module digital autopilot

% Copyright 1990-2021 The MathWorks, Inc.

e=u(1);
edot=u(2);
t=u(3);
alph=u(4);
alphs=u(5);
DB=u(6);

if t == 0
    granularity = .001;
    largestxdot = .05;

    % Switch curve for jets off:
    xs1dot = 0:granularity:largestxdot;
    xs1 = -xs1dot.^2/(4*alphs) - DB;
    xs2dot = -xs1dot;
    xs2 =  xs2dot.^2/(4*alphs) + DB;

    % Switch curve for jets on:
    xs3dot = 0:granularity:2*largestxdot;
    xs3 = -xs3dot.^2/(4*alph) + DB;
    xs4dot = -xs3dot;
    xs4 =  xs4dot.^2/(4*alph) - DB;

    if isempty(findobj('type','figure','Name','aero_dap3dof'))
        % give demo it's own figure window on initial start
        figure('Name','aero_dap3dof');
    end
    % Plot switch curves
    clf
    emax = 20*DB; edotmax=0.1;
    axis([-emax emax -edotmax edotmax])
    hold on
    plot(xs1,xs1dot,'b'); plot(xs2,xs2dot,'b')
    plot(xs3,xs3dot,'r'); plot(xs4,xs4dot,'r')
    legend('Switch Curves for', 'Turning Jets Off','Switch Curves for', ...
        'Turning Jets On','Location','NorthWest','AutoUpdate','off');
    % Add error and error rate principle axes
    plot([-emax emax],[0 0],'k',[0 0],[-edotmax edotmax],'k')
    grid;xlabel('Yaw Attitude Error'),ylabel('Yaw Attitude Rate Error')
    title('Phase Plane Plot for LM Yaw Axis Digital Control')

end

if ~isempty(findobj('type','figure','Name','aero_dap3dof'))
    % Plot the current error and error dot points in the phase plane
    plot(e,edot,'r.')
end

end







