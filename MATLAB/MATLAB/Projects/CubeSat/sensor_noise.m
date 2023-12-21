%%%sensor noise parameters
global fsensor

MagscaleNoise = (1e-5)*fsensor; %T
MagFieldNoise = MagscaleNoise*(2*rand()-1);

AngscaleNoise = (0.001)*fsensor; %rad/s
AngFieldNoise = AngscaleNoise*(2*rand()-1);

EulerScaleNoise = (1*pi/180)*fsensor; %rad
EulerNoise = EulerScaleNoise*(2*rand()-1);