import serial
import string
import matplotlib.pyplot as plt 


def main():
    ser = serial.Serial('/dev/ttyACM0')  # open serial port
    sensorValues = []
    ind = 0
    indexs = []
    lineX = []
    lineY = []

    extraX = []
    extraY = []
    oldValue = 0
    mon = 0 #-1 , 0 ,1
    oldMon = 0

    while ind < 100:
        line = ser.readline()  
        line = int(line)
        sensorValues = sensorValues + [line]
        ind = ind + 1
        indexs = indexs + [ind]
        print(line)    

        if ind >= 3:
            if((sensorValues[ind - 3] < sensorValues[ind - 2]) & (sensorValues[ind - 2] < sensorValues[ind - 1])):
                extraX += [ind]
                extraY += [sensorValues[ind-1]]
                print("extra")
     

    # print(ex)
    plt.plot(indexs, sensorValues) 
    plt.plot(extraX, extraY, 'r^')
    #plt.plot(lineX, lineY, label = "line 1")  
    plt.xlabel('time') 
    plt.ylabel('value') 
    plt.title('Values of encoder') 
    plt.show()  
   # plt.clear()

if __name__ == "__main__":
    main()