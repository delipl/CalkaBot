#function for generating random values like angle and speed
import random

#values ranges
maxSpeed = 1.5
minSpeed = 0.5
maxAngle = 360
minAngle = 1

#change for go forward
chance = 20

def getAngle(angle):
    #random.seed()
    if(random.randint(0, 100)< chance):
        angle = 0
    else:
        angle = random.randint(minAngle, maxAngle)
    return angle

def getSpeed(speed):  
    speed = random.uniform(minSpeed, maxSpeed)
    return speed



