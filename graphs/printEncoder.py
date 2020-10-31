import serial
import string
import re
import matplotlib.pyplot as plt 
true = 1
false = 0

# config
serialRead  = false
fileRead    = true
debug       = true
toRead      = 2     # how many values are to read
till        = 1000  # how many times read this values
diameter    = 30    # wheel diameter
noise       = 10

def main():
    if serialRead:
        ser = serial.Serial('/dev/ttyACM0')
    if fileRead:
        f = open("data.txt", "r")

    ind = 0
    encoderValues   = []
    times           = []  

    
    while ind < till:   
        if(serialRead):
            line = ser.readline()
            line = str(line)
            for val in range(0, toRead):
                value = (line.split('\\t')[val])
                value = int(value[val])
                if val == 0:
                    times = times + [value]
                if val == 1:
                    encoderValues = encoderValues + [value]   
        if(fileRead):
            line = f.readline()
            line = str(line)
            for val in range(0, toRead):
                value = (line.split('\t')[val])
                if debug:
                    print("value:", value)
                value = int(value)
                if val == 0:
                    times = times + [value]
                if val == 1:
                    encoderValues = encoderValues + [value]   
        ind += 1
    if debug:
        print("times:", times, "\n\nencodervalue:", encoderValues)

    # extremas cords and looking for extremas
    extraX = []
    extraY = []
    for i in range(1, till - 1):
        if i >= 3:
            if((encoderValues[i] > encoderValues[i-1]) & (encoderValues[i] > encoderValues[i+1])):
                extraX += [times[i]]
                extraY += [encoderValues[i]]
                if debug:
                    print("extra")
            if((encoderValues[i] == encoderValues[i-1])):
                if((encoderValues[i-1] > encoderValues[i-2]) & (encoderValues[i] > encoderValues[i+1])):
                    extraX += [times[i]]
                    extraY += [encoderValues[i]]
                    if debug:
                        print("extra") 

    # filtracja danych
    exToPrintX = [] 
    exToPrintY = []
    for j in range(0, len(extraX)-1):
        diff = extraY[j] - extraY[j+1]
        if((diff > noise) | (diff < -noise)):
            exToPrintX += [extraX[j]]
            exToPrintY += [extraY[j]]

    # velocity
    speeds  = []
    asiX    = []
    if debug:
        print(extraX, extraY)
    for i in range(0, len(exToPrintX), 2):
            dt = exToPrintX[i] - exToPrintX[i-1]
            distance =  2 * 3.14 * (diameter/2)/8
            speeds = speeds + [distance/dt]
            asiX += [exToPrintX[i]]

    # plotting
    plt.plot(times, encoderValues,          label = "odczyt czujnika" ) 
    plt.plot(extraX, extraY, 'b^',          label = "nieprzefiltrowane extrema")
    plt.plot(exToPrintX, exToPrintY, 'r^',  label = "przefiltrowane extrema")
    plt.xlabel('time') 
    plt.ylabel('value') 
    plt.title('Dane z enkodera') 
    plt.legend()
    plt.show()  

    plt.plot(asiX, speeds, 'g-',            label = "predkosc chwilowa")
    plt.xlabel('time') 
    plt.ylabel('speed') 
    plt.title('Prędkość robota') 
    plt.legend()
    plt.show() 

if __name__ == "__main__":
    main()