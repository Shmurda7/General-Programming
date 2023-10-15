import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

#prevously defined variables
g = -9.81 #gravity
m = 1 #mass
L = 2 #length
MI = 1 #moment of intertia

#target angle ofc
#target_angle = np.pi 
target_direction = [0, 4]

def animate_PID():
    #initializing these values
    global prev_err 
    global IE
    global angle,ang_velocity


    angle = 0


    #affects how fast the pendy goes firstly
    ang_velocity = 2  #rotation rate/angular velocity

    prev_err = 0
    IE = 0

    #process
    def yourmom(angle):
                                    #python dodo at squaring
        return (g*L*np.sin(angle))/((L*L)+(MI/m))




    #plotting the animation


    fig, ax = plt.subplots(1,2)
    pendulum_plot, = ax[0].plot([0, L*np.sin(angle)], [L, L-L*np.cos(angle)], "o-")
    ax[0].set_xbound(-L,L)
    ax[0].set_ybound(0,2*L)
    ax[0].set_aspect(1)

    angle0 = angle
    angle_list = [angle0]

    t = [0]
    angle_plot, = ax[1].plot(t,angle_list)


    #the PID error loop
    def update(num,ax,pendulum_plot,angle_plot,angle_list):
        global angle,ang_velocity
        dt = 1/60
        ang_accel = yourmom(angle)

        global prev_err 
        global IE
        diffangle = [np.cos(angle), np.sin(angle)]
        PE = -np.dot(target_direction, diffangle)
        #PE = angle - target_angle
        IE += PE*dt
        
        if num == 0:
            prev_err = PE
        DE = (PE - prev_err)/dt
        prev_err = PE


        P, I, D = 10e-0, 5e-0, 1e-0
        #, I, D = 5e-8, 0, 0

        #-= makes error smaller
        ang_accel -= P*PE + I*IE + D*DE

        

        ang_velocity += ang_accel*dt
        angle += ang_velocity*dt
        
        #replaces update
        '''
        angle = [0]
        ang_velocity = [2]
        for i in range(100):
        # a bunch of shit happens
            omega2 = ang_velocity[-1] + ang_accel*dt
            theta2 = angle[-1] + omega2*dt
            ang_velocity.append(omega2)
            angle.append(theta2)
        #prev_err[0] = PE
        '''
        pendulum_plot.set_xdata([0, L*np.sin(angle)])
        pendulum_plot.set_ydata([L, L-L*np.cos(angle)])
        #can switch with PE, or angle
        angle0 = PE
        angle_list.append(angle0)
        angle_plot.set_xdata(np.arange(len(angle_list)))
        angle_plot.set_ydata(angle_list)
        ax[1].relim()
        ax[1].autoscale_view()


        



    anim = FuncAnimation(fig, update, interval=1000/60, fargs = 
    (ax,pendulum_plot,angle_plot,angle_list))

    anglef = np.array(angle).T
    speed = np.array(ang_velocity).T
    #f1 = plt.figure("Figure 2")
    #plt.plot(anglef)
    #plt.plot(speed)


    plt.show()

def simulate_PID(P=1 ,I=2 ,D=1):
    #initializing these values

    angle = 0
    #affects how fast the pendy goes firstly
    ang_velocity = 2  #rotation rate/angular velocity

    prev_err = 0
    IE = 0

    #process
    def yourmom(angle):
                                    #python dodo at squaring
        return (g*L*np.sin(angle))/((L*L)+(MI/m))


    #plotting the animation
    angle0 = angle
    angle_list = [angle0]

    #the PID error loop
    for i in range(10000):
        dt = 1/60
        ang_accel = yourmom(angle)

        diffangle = [np.cos(angle), np.sin(angle)]
        PE = -np.dot(target_direction, diffangle)
        #PE = angle - target_angle
        IE += PE*dt
        
        if i == 0:
            prev_err = PE
        DE = (PE - prev_err)/dt
        prev_err = PE

        #P, I, D = 10e-0, 5e-0, 1e-0 
        #-= makes error smaller
        ang_accel -= P*PE + I*IE + D*DE

        ang_velocity += ang_accel*dt
        angle += ang_velocity*dt
        
        #replaces update
     
        #can switch with PE, or angle
        angle0 = PE
        angle_list.append(angle0)
       
    return np.array(angle_list)
#animate_PID()
graph = simulate_PID( 10e-0, 5e-0, 1e-0 )
plt.plot(graph)

graph = simulate_PID( 10e-0, 5e-0, 9e-1 )
plt.plot(graph)

graph = simulate_PID( 10e-0, 5e-0, 8e-1 )
plt.plot(graph)

plt.show()


#simlated annealing