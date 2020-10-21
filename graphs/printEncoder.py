import serial
import string
import re
import matplotlib.pyplot as plt 
true = 1
false = 0

# config
serialRead  = true
fileRead    = false
toRead      = 2     # how many values are to read
till        = 2000  # how many times read this values
diameter    = 30    # wheel diameter
maxSpeed    = 10
noise       = 10

def main():
    if serialRead:
        ser = serial.Serial('/dev/ttyACM0')
    if fileRead:
        f = open("data.txt", "r")

    ind = 0

    # read variables 
    encoderValues   = []
    times           = []  

    
    while ind < till:   
        if(serialRead):
            line = ser.readline()
            line = str(line)
            for val in range(0, toRead):
                value = (line.split('\\t')[val])
                value = re.findall("\d+", value) 
                value = int(value[0])
                if val == 0:
                    times = times + [value]
                if val == 1:
                    encoderValues = encoderValues + [value]   
        ind += 1

    # extremas cords
    extraX = []
    extraY = []
    # find extremas
    for i in range(1, till - 1):
        if i >= 3:
                if((encoderValues[i] < encoderValues[i-1]) & (encoderValues[i] < encoderValues[i+1])):
                    extraX += [times[i]]
                    extraY += [encoderValues[i]]
                    print("extra")
                if((encoderValues[i] > encoderValues[i-1]) & (encoderValues[i] > encoderValues[i+1])):
                    extraX += [times[i]]
                    extraY += [encoderValues[i]]
                    print("extra")
                if((encoderValues[i] == encoderValues[i-1])):
                        if((encoderValues[i-1] > encoderValues[i-2]) & (encoderValues[i] > encoderValues[i+1])):
                            extraX += [times[i]]
                            extraY += [encoderValues[i]]
                            print("extra")
                        if((encoderValues[i-1] < encoderValues[i-2]) & (encoderValues[i] < encoderValues[i+1])):
                            extraX += [times[i]]
                            extraY += [encoderValues[i]]
                            print("extra")      

    exToPrintX = [] 
    exToPrintY = []
    for j in range(0, len(extraX)-1):
        diff = extraY[j] - extraY[j+1]
        if((diff > noise) | (diff < -noise)):
            # diff 
            exToPrintX += [extraX[j]]
            exToPrintY += [extraY[j]]

    # velocity
    speeds  = []
    asiX    = []
    start   = 0
    if(exToPrintY[0] > exToPrintY[1]):
        start = 0
    else:
        start = 1
    for i in range(start, len(exToPrintX), 2):
            dt = exToPrintX[i] - exToPrintX[i-1]
            distance =  2 * 3.14 * (diameter/2)/8
            distance *= 100
            speeds = speeds + [distance/dt]
            asiX += [exToPrintX[i]]
    speeds = speeds
    # for i in range(1, till - 1):
    plt.plot(asiX, speeds, label = "prędkość chwilowa")
    plt.plot(times, encoderValues, label = "odczyt czujnika") 
    plt.plot(extraX, extraY, 'b^')
    plt.plot(exToPrintX, exToPrintY, 'r^')
    

    plt.xlabel('time') 
    plt.ylabel('value') 
    plt.title('Values of encoder') 
    plt.legend()
    plt.show()  
   # plt.clear()

if __name__ == "__main__":
    main()