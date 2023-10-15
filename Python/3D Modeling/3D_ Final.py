from vpython import *
from time import *
import numpy as np
import math
import serial

#serial stuff

te=serial.Serial('COM4',115200)
sleep(1)

scene.range=5

#v python wants to do angle with radians
toRad=2*np.pi/360
toDeg=1/toRad

scene.forward=vector(-1,-1,-1)
scene.width=600 #size of scene
scene.height=600

#reference frame
xArrow=arrow(length=1,shaftwidth=0.1,color=color.red,axis=vector(1,0,0))
yArrow=arrow(length=1,shaftwidth=0.1,color=color.green,axis=vector(0,1,0))
zArrow=arrow(length=1,shaftwidth=0.1,color=color.blue,axis=vector(0,0,1))

#frame of fight computer
frontArrow=arrow(length=4,shaftwidth=0.1,color=color.purple,axis=vector(1,0,0))
upArrow=arrow(length=1,shaftwidth=0.1,color=color.magenta,axis=vector(0,1,0))
sideArrow=arrow(length=2,shaftwidth=0.1,color=color.orange,axis=vector(0,0,1))

#objects
bBoard=box(length=6,width=2,height=0.2,opacity=0.8,pos=vector(0,0,0))
bn=box(length=1,width=0.75,height=0.1,pos=vector(-0.5,0.1+0.05,0),color=color.blue)
nano=box(length=1.75,width=0.6,height=0.1,pos=vector(-2,0.1+0.05,0),color=color.green)


#compound object
myObj=compound([bBoard,bn,nano])

while True:
    while (te.inWaiting()==0):
        pass
    dataPacket=te.readline()
    dataPacket=str(dataPacket,'utf-8')
    splitPacket=dataPacket.strip().split("\t")  # Remove whitespace and split by tab
    if len(splitPacket) >= 3:
        pitch=float(splitPacket[0])*toRad
        roll=float(splitPacket[1])*toRad
        yaw=float(splitPacket[2])*toRad
        print("pitch= ",pitch,"roll= ",roll,"yaw= ",yaw)
        rate(2000)
        k=vector(cos(yaw)*cos(pitch),sin(pitch),sin(yaw)*cos(pitch))
        y=vector(0,1,0)
        s=cross(k,y)
        v=cross(s,k)
        #size
        frontArrow.length=4
        sideArrow.length=2
        upArrow.length=1
        #setting
        myObj.axis=k
        myObj.up=v#have to tell compound objects their up
        frontArrow.axis=k
        sideArrow.axis=s
        upArrow.axis=v


