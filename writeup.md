# **PID Control Project** 

## Writeup

---

**In this project, the goal was to tune a PID controller for steering angle
to keep a car on the road while traveling a constant speed on a circular track.**


[//]: # (Image References)

## Rubric Points
### Here I will consider the [rubric points](https://review.udacity.com/#!/rubrics/1972/view) individually and describe how I addressed each point in my implementation.  

---
### Compilation

#### 1. The code compiles correctly.

The code does successfully compile without errors.

### Implementation

#### 1. The PID procedure follows what was taught in the lessons.

The PID controller is implemented as shown in the lessons: steering angle
is computed to be negative total error computed by controller according to
instantaneous, discrete difference, and discrete integral of cross-track error.

### Reflection
#### 1. Describe the effect each of the P, I, D components had in your implementation.

The P component makes the controller sensitive particularly to the absolute distance 
of the car from the center of the lane. This component is perhaps most "active" 
throughout a lap because it contributes to center-of-lane tracking on straight-aways
as well as on sharp turns.
The I component makes the controller sensitive to perturbations of the center line
that the controller is tracking, aka it contributes heavily on sharp turns in which
the car can suddenly overshoot the "center" is was previously tracking that forks
away from the actual center as the lane turns out from under the car. The I 
component in this case contributes to (by amplifying) the effect of the P component.
Under normal straight conditions, the I component helps to dampen the 
cross-track error produced by the P component by accumulating small total error.
Lastly, the D component is useful for dampening the P component's steering signal
on straight-aways. Without the D component, the car would surely oscillate on the 
straightaways. The D component perhaps more weakly (therefore requiring a greater
constant value) contributes to dampening the cross-track error on sharp turns than
the I component, but it contributes nonetheless proportional to the curvature of
the turn.

#### 2. Describe how the final hyperparameters were chosen.

The hyperparameters were tuned by hand, and only hardcoded into my implementation
after successfully completing 1 lap over several trials (since the height at which
the car begins the trial appears to be non-deterministic). For hand-tuning,
I began by first tuning the P parameter to dampen the cross-track error on the starting
straightaway. I reduced the value to around ~0.1 for this to occur, and at this
value some oscillations were visible before the first turn. To dampen these oscillations
before the turn, I increased the D value to a value around ~2. This allowed the 
car to at least cross the bridge after the first turn. Further tuning of the P
and D values showed me that the stability of the car's driving was quite sensitive
to these values, especially after starting the 2nd turn (first after the bridge).
In order to tackle turns better, I started tuning the I value and started with tiny
values so as not to affect the car's driving stability *before* the bridge.
From here, the tuning of all parameters was within a single order of magnitude
and was with the objective of reliably passing the sharp turns after the bridge.

The final values I decided upon were:
Kp=1.22e-1
Ki=1.5e-4
Kd=2.1

### Simulation
#### 1. The vehicle must successfully drive a lap around the track.

The car safely completes a lap around the track with a speed of 30 mph.

