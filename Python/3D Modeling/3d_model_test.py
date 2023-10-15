from vpython import *
import numpy as np

x=box(length=6,width=2,height=0.2,opacity=0.2)
y=cylinder(length=6,radius=0.5,pos=vector(-3, 0, 0),color=color.red,opacity=0.2)
z=sphere(radius=0.75,pos=vector(-3,0,0),color=color.red,opacity=0.2)

#reference frame
xArrow=arrow(length=2,axis=vector(1,0,0),color=color.red)
yArrow=arrow(length=2,axis=vector(0,1,0),color=color.green)
zArrow=arrow(length=2,axis=vector(0,0,1),color=color.blue)


#needed for platform.io IDE bc it's shit
while True: 
    for j in np.arange(1,6,0.05):
        rate(60)
        y.length=j
    for j in np.arange(6,1,-0.05):
        rate(60)
        y.length=j