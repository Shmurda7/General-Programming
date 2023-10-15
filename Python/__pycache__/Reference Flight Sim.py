from re import X
import matplotlib.pyplot as plt

#Freedom Units

DryWeight =250  # lb
PropWeight = 75  # lb     typical prop weight is much larger than the dry weight
TotalWeight = DryWeight + PropWeight
Time = 0
TimeStep = 0.01

TargetVelocity = 30  # ft/s
#Altitude & Hover
TargetHoverAltitude = 200  # ft
TargetHoverTime = 10 #s
Altitude = 0   #z axis ft
#Foward & Backward
TargetFNB = 200 #ft
TargetFNBTime = 20 #s
DistanceX = 0  #x axis ft
#Left & Right
TargetLNR = 350 #ft
TargetLNRTime = 20 #s
DistanceY = 0  #y axis ft
MinThrust = 200  # lbf
MaxThrust = 400  # lbf
Thrust = 0
ISP = 200  # s
GRAVITY = 32.174  # ft/s^2
HoverTime = 10  # s
AdjustmentTime = 1  # s # Arbitrary time to get math to close
Velocity = 0  # Initial Velocity
HoverStartTime = 0
FNBStartTime = 0


AltitudeArray = []
DistanceXArray = []
DistanceYArray = []
VelocityArray = []
ThrustArray = []
targetArray = []
targetArrayX = []
targetArrayY = []
state = "GoingUP"
while True:
    if PropWeight < 0:
        break
    if state == "GoingUP":
        #append is inputing the Alt variables int the Alt array
        AltitudeArray.append(Altitude)
        VelocityArray.append(Velocity)
        ThrustArray.append(Thrust)
        targetArray.append(TargetHoverAltitude)
        # Figure out how much your gravity loss is
        Fg = TotalWeight
        # Calc Force Needed to get up to speed to the desired Alt
        AccelerationNeeded = (TargetVelocity - Velocity) / AdjustmentTime
        Thrust = TotalWeight * (AccelerationNeeded / GRAVITY + 1)
        if Thrust < MinThrust:
            Thrust = MinThrust
        if Thrust > MaxThrust:
            Thrust = MaxThrust
            # += means the V = V +....
        Velocity += GRAVITY * (Thrust / Fg - 1) * TimeStep
        Altitude += Velocity * TimeStep
        #interval, time in steps over that period
        Time += TimeStep
        #equation for propulsion weight
        PropWeight -= Thrust/ISP*TimeStep
        #total weight for typical rocket
        TotalWeight = DryWeight + PropWeight
        #once the Alt reaches the target Alt it runs in to Hover state, where it tell it to hover
        if Altitude > TargetHoverAltitude:
            HoverStartTime = Time
            state = "Hover"
    if state == "Hover":
        #starting a new input of alt in the alt array
        AltitudeArray.append(Altitude)
        VelocityArray.append(Velocity)
        ThrustArray.append(Thrust)
        # Figure out how much your gravity loss is
        Fg = TotalWeight
        # Calc Force Needed to get up to speed to stay at that Alt
        AccelerationNeeded = (- Velocity) / AdjustmentTime
        Thrust = TotalWeight * (AccelerationNeeded / GRAVITY + 1)
        if Thrust < MinThrust:
            Thrust = MinThrust
        if Thrust > MaxThrust:
            Thrust = MaxThrust
        Velocity += GRAVITY * (Thrust / Fg - 1) * TimeStep
        Altitude += Velocity * TimeStep
        Time += TimeStep
        PropWeight -= Thrust / ISP * TimeStep
        TotalWeight = DryWeight + PropWeight
        #once reaches certain amount of time at the hover Alt it runs next state where it goes down
        if Time - HoverStartTime > TargetHoverTime:
            state = "GoingDOWN"
    if state == "GoingDOWN":
        AltitudeArray.append(Altitude)
        VelocityArray.append(Velocity)
        ThrustArray.append(Thrust)
        # Figure out how much your gravity loss is
        Fg = TotalWeight
        # Calc Force Needed to get up to speed
        AccelerationNeeded = (-TargetVelocity - Velocity) / AdjustmentTime
        Thrust = TotalWeight * (AccelerationNeeded / GRAVITY + 1)
        if Thrust < MinThrust:
            Thrust = MinThrust
        if Thrust > MaxThrust:
            Thrust = MaxThrust
        Velocity += GRAVITY * (Thrust / Fg - 1) * TimeStep
        Altitude += Velocity * TimeStep
        #intervals of increasing time
        Time += TimeStep
        PropWeight -= Thrust/ISP*TimeStep
        TotalWeight = DryWeight + PropWeight
        #once it reaches Alt 0(lands) it stops the entire while loop
        if Altitude < 0:
            break

#New DOF Moving the X direction Foward
        state = "MoveUp"
while True:
    if PropWeight < 0:
        break
    if state == "MoveUp":
        #append is inputing the Alt variables int the Alt array
        DistanceXArray.append(DistanceX)
        VelocityArray.append(Velocity)
        ThrustArray.append(Thrust)
        targetArrayX.append(TargetFNBTime)
        # Figure out how much your gravity loss is
        Fg = TotalWeight
        # Calc Force Needed to get up to speed to the desired Alt
        AccelerationNeeded = (TargetVelocity - Velocity) / AdjustmentTime
        Thrust = TotalWeight * (AccelerationNeeded / GRAVITY + 1)
        if Thrust < MinThrust:
            Thrust = MinThrust
        if Thrust > MaxThrust:
            Thrust = MaxThrust
            # += means the V = V +....
        Velocity += GRAVITY * (Thrust / Fg - 1) * TimeStep
        DistanceX += Velocity * TimeStep
        #interval, time in steps over that period
        Time += TimeStep
        #equation for propulsion weight
        PropWeight -= Thrust/ISP*TimeStep
        #total weight for typical rocket
        TotalWeight = DryWeight + PropWeight
        #once the Alt reaches the target Alt it runs in to Hover state, where it tell it to hover
        if DistanceX > TargetFNBTime:
            FNBStartTime = Time
            state = "Desired Distance"
    if state == "Desired Distance":
        #starting a new input of alt in the alt array
        DistanceXArray.append(DistanceX)
        VelocityArray.append(Velocity)
        ThrustArray.append(Thrust)
        # Figure out how much your gravity loss is
        Fg = TotalWeight
        # Calc Force Needed to get up to speed to stay at that Alt
        AccelerationNeeded = (- Velocity) / AdjustmentTime
        Thrust = TotalWeight * (AccelerationNeeded / GRAVITY + 1)
        if Thrust < MinThrust:
            Thrust = MinThrust
        if Thrust > MaxThrust:
            Thrust = MaxThrust
        Velocity += GRAVITY * (Thrust / Fg - 1) * TimeStep
        DistanceX += Velocity * TimeStep
        Time += TimeStep
        PropWeight -= Thrust / ISP * TimeStep
        TotalWeight = DryWeight + PropWeight
        #once reaches certain amount of time at the hover Alt it runs next state where it goes down
        if Time - FNBStartTime > TargetFNBTime:
            state = "MoveBack"
    if state == "MoveBack":
        DistanceXArray.append(DistanceX)
        VelocityArray.append(Velocity)
        ThrustArray.append(Thrust)
        # Figure out how much your gravity loss is
        Fg = TotalWeight
        # Calc Force Needed to get up to speed
        AccelerationNeeded = (-TargetVelocity - Velocity) / AdjustmentTime
        Thrust = TotalWeight * (AccelerationNeeded / GRAVITY + 1)
        if Thrust < MinThrust:
            Thrust = MinThrust
        if Thrust > MaxThrust:
            Thrust = MaxThrust
        Velocity += GRAVITY * (Thrust / Fg - 1) * TimeStep
        DistanceX += Velocity * TimeStep
        #intervals of increasing time
        Time += TimeStep
        PropWeight -= Thrust/ISP*TimeStep
        TotalWeight = DryWeight + PropWeight
        #once it reaches Alt 0(lands) it stops the entire while loop
        if DistanceX < 0:
            break

f1 = plt.figure("Figure 1")
plt.plot(AltitudeArray, label="Altitude")
plt.plot(VelocityArray, label="Velocity")
plt.plot(ThrustArray, label="Thrust")
plt.plot(targetArray, label="Target Altitude")

f2 = plt.figure("Figure 2")
plt.plot(DistanceXArray, label="DistanceX")
plt.plot(VelocityArray, label="Velocity")
plt.plot(ThrustArray, label="Thrust")
plt.plot(targetArrayX, label="Target Distance")

print(PropWeight)
plt.legend(1)
plt.legend(2)
plt.show()