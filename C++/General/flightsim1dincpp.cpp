//Note all units are imperial unless otherwise noted
#include <stdio.h>
#include <iostream>
#include <vector>
#include "C:\Users\jaime\OneDrive\Documents\Codes\.vscode\C++ codes\matplotlibcpp.h"

//to save you from pain and suffering running flight sim
//gcc "flightsim1dincpp.cpp" -lstdc++ -o "flightsim.exe" -I "C:\Users\jaime\AppData\Local\Programs\Python\Python310\include" -I "C:\Users\jaime\AppData\Local\Programs\Python\Python310\Lib\site-packages\numpy\core\include" -L "C:\Users\jaime\AppData\Local\Programs\Python\Python310\libs" -lpython310
// to run code open new vscode and make sure directory is correct
    //open folder with all the codes
    //then you go with start "flightsim"
using namespace std;
namespace plt = matplotlibcpp;


//weights are expressed in lb`
float 
DryWeight = 250,
PropWeight = 75,
TotalWeight = DryWeight+PropWeight;

//hover parameters
float TragetHovertime=10,
HoverStartTime = 0, //
TargetHoverAltitude = 200,
HoverTime = 10,
TargetVelocity =30;

//Thrust parms
float MinThrust = 200,
MaxThrust = 400,
Thrust = 0,
ISP = 200;

//time settings
float
Time = 0,
TimeStep =0.1,
TimeMax =60,
AdjustmentTime = 1;

//Misc. parms
float
Altitude = 0,
Velocity = 0,
AccelerationNeeded,
gravity = 32.174;

//array bs
vector<float> AltitudeArray;
vector<float> VelocityArray;
vector<float> ThrustArray;
vector<float> TargetArray;
vector<float> TimeAarry;



//calculations
void BookKeeping(float GravityLoss,float a) // gravity loss, a are varaibles in the void loop
{
    //add all current values to the array before doing any math on them
    printf("%f",Thrust);
    AltitudeArray.push_back(Altitude); //push_back put values into the last slot of the array
    VelocityArray.push_back(Velocity);
    ThrustArray.push_back(Thrust);
    TargetArray.push_back(TargetHoverAltitude);
    TimeAarry.push_back(Time);

    Thrust = TotalWeight * (a / gravity + 1);

    if (Thrust < MinThrust) {Thrust = MinThrust;} //engine can only throttle so high
    if (Thrust > MaxThrust) {Thrust = MaxThrust;}
    //do math to values to be prepped for the next cycle
    Velocity += gravity * ((Thrust/TotalWeight)-1)*TimeStep;
    Altitude += Velocity * TimeStep;
    Time += TimeStep;
    PropWeight -= Thrust/ISP*TimeStep;
    TotalWeight = DryWeight + PropWeight;
    
    return;
}
/** This function checks to see if the rocket engine will fire and the governing logic for hover and decent
 * 
 * @param is above and can be edited
 * 
 * @returns an array of postion velocity and thrust to be graphed over time
 */
int main()
{
    float Fg;
    Fg = TotalWeight;
    int Status = 0;

    int MaxSteps = TimeMax/TimeStep;

    AltitudeArray.reserve(MaxSteps);
    VelocityArray.reserve(MaxSteps);
    ThrustArray.reserve(MaxSteps);
    TargetArray.reserve(MaxSteps);
//logic 
    while (!(Altitude <= 0 && Time != 0) && PropWeight > 0)
        {
         printf("%f,%f,%f,%f,%i \n",Altitude,Time,PropWeight,AccelerationNeeded,Status);
          switch (Status)
          {
          case 0:
            Fg = TotalWeight;
            AccelerationNeeded = (TargetVelocity - Velocity) / AdjustmentTime;
            BookKeeping(Fg,AccelerationNeeded); //gets inputted in as gravity loss, and a  (Fg=Gravity loss, a=AccerlerationNeeded)
                if (Altitude >= TargetHoverAltitude) //switch states if our boundary conditions are correct
                {
                    HoverStartTime = Time;
                    Status = 1;
                }
            break;
           case 1:
                Fg = TotalWeight;
                AccelerationNeeded = (- Velocity) / AdjustmentTime;
                BookKeeping(Fg,AccelerationNeeded);
                    if (Time - HoverStartTime > TragetHovertime){Status = 2;} //switch states if our boundary conditions are correct
            break;
          default:
                Fg = TotalWeight;
                AccelerationNeeded = (-TargetVelocity - Velocity) / AdjustmentTime; //find the need acceleration approach our desired velocity 
                BookKeeping(Fg,AccelerationNeeded);
            break;
          }   
        }




    plt::figure(); // declare a new figure (optional if only one is used)

    plt::plot(TimeAarry, AltitudeArray,{{"label", "Altitude"}});                        // automatic coloring: tab:blue
    plt::plot(TimeAarry, VelocityArray,{{"label", "Velocity"}});
    plt::plot(TimeAarry, ThrustArray,{{"label", "Thrust"}});
    plt::plot(TimeAarry,TargetArray,{{"label", "Target"}});   // x-axis interval: [0, 1e6]
    plt::title("Standard usage"); // set a title
    plt::legend();                // enable the legend

    plt::show(); // save the figure
        return(0); 
    }

