import matplotlib.pyplot as plt

#flight sim function
def simulate_rocket(target_altitude, thrust):
    #givens
    time = 0 #s
    altitude = 0 #m
    velocity = 0 #m/s
    mass_dry = 20 #kg
    mass_fuel_start = 5 #kg
    mass_fuel_current = mass_fuel_start
    mass_total = mass_dry + mass_fuel_current
    mass_flow_rate = 2 #kg/s
    gravity = -9.81 #m/s^2
    dt = 0.1 #time step

    #initialize data lists (data I want to save)
    time_list = [time]
    altitude_list = [altitude]
    mass_list = [mass_total]
    velocity_list = [velocity]
    acceleration_list = [gravity]

    #loss of mass
    mass_fuel_current -= mass_flow_rate*dt
    mass_total = mass_dry + mass_fuel_current

    #start
    while time < 1000:
        F_g = mass_total * gravity
        if mass_fuel_current > 0: 
            acceleration = (thrust - F_g) / mass_total
            mass_fuel_current -= mass_flow_rate*dt
            mass_total = mass_dry + mass_fuel_current
        else:
            acceleration = gravity
            mass_total = mass_dry
        
        velocity += acceleration*dt
        altitude += (velocity*(dt*dt))/2
        time += dt

        if altitude < 0:
            altitude = 0
            velocity = 0
            break

        #storing values
        time_list.append(time)
        altitude_list.append(altitude)
        mass_list.append(mass_total)
        velocity_list.append(velocity)
        acceleration_list.append(acceleration)

    #what is wanted to be taken out of the loop
    return time_list, altitude_list, mass_list, velocity_list, acceleration_list


######################## Run the simulation #########################
#values we choose
target_altitude = 100 #m
thrust = 30 #N
#running the function
time_list, altitude_list, mass_list, velocity_list, acceleration_list = simulate_rocket( 100, 3692)

# Create the plot

fig, ax1 = plt.subplots()

#plotting altitude vs time
color = 'tab:red'
ax1.set_ylabel('Altitude (m)', color=color)
ax1.plot(time_list, altitude_list, color=color)
ax1.tick_params(axis='y', labelcolor=color)

#combining the 2 plots into 1
ax2 = ax1.twinx()

#plotting mass vs time
color = 'tab:blue'
ax2.set_ylabel('Mass (kg)', color=color)
ax2.plot(time_list, mass_list, color=color)
ax2.tick_params(axis='y', labelcolor=color)

#ignore this plot
fig,ax4 = plt.subplots()
color = 'tab:green'
ax4.set_ylabel('Velocity (m/s)', color=color)
ax4.plot(time_list, velocity_list, color=color)
ax4.tick_params(axis='y', labelcolor=color)

ax6 = ax4.twinx()

color = 'tab:blue'
ax6.set_ylabel('Mass (kg)', color=color)
ax6.plot(time_list, mass_list, color=color)
ax6.tick_params(axis='y', labelcolor=color)

fig,ax5 = plt.subplots()
color = 'tab:orange'
ax5.set_ylabel('Acceleration (m/s)', color=color)
ax5.plot(time_list, acceleration_list, color=color)
ax5.tick_params(axis='y', labelcolor=color)

ax7 = ax5.twinx()

color = 'tab:blue'
ax7.set_ylabel('Mass (kg)', color=color)
ax7.plot(time_list, mass_list, color=color)
ax7.tick_params(axis='y', labelcolor=color)



plt.title('Rocket Simulation')
fig.tight_layout()
plt.show()
