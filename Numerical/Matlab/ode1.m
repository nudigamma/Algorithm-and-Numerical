function yout = ode1(F,t0,h,tfinal,yo)
% ODE1 A simple ODE solver.
%   yout = ode1(F,t0,h,tfinal,yo) uses Euler's 
%   method with fixed step size h on the interval 
%   to <= t <= tfinal to solve dy/dy = F(t,y)
%   with y(t0) = y0

    y = y0;
    yout = y;
    for t = t0 : h : tfinal-h
        s = F(t,y);
        y = y + h*s;
        yout = [yout; y];
    end
end
