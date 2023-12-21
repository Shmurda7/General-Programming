function [BfieldNav,pqrNav,ptpNav] = Navigation(BfieldMeasured,pqrMeasured,ptpMeasured)
global BfieldNavPrev pqrNavPrev ptpNavPrev

%gain for comp filter
s = 0.3;

if  BfieldNavPrev(1,1) == -99
%if sum(BfieldNavPrev) + sum(pqrNavPrev) + sum(ptpNavPrev) == 0 %removed
%for optimization in main theres a -99
    BfieldNav = BfieldMeasured;
    pqrNav = pqrMeasured;
    ptpNav = ptpMeasured;
else
    BfieldBiasEstimate = [0;0;0];
    %complimentary filter
    BfieldNav = BfieldNavPrev*(1-s) + s*(BfieldMeasured-BfieldBiasEstimate);
    pqrBiasEstimate = [0;0;0];
    pqrNav = pqrNavPrev*(1-s) + s*(pqrMeasured-pqrBiasEstimate);
    ptpBiasEstimate = [0;0;0];
    ptpNav = ptpNavPrev*(1-s) + s*(ptpMeasured-ptpBiasEstimate);
end

BfieldNavPrev = BfieldNav;
pqrNavPrev = pqrNav;
ptpNavPrev = ptpNav;
