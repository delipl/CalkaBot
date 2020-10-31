import serial
import string
import re

# how many vals you want to read
toRead = 2
till   = 1000

def main():
    ser = serial.Serial('/dev/ttyACM0')  # open serial port
    f = open("data.txt", "w")
   
    for x in range(till):
        line = ser.readline()  
        line = str(line)

        vals = []
        for val in range(0, toRead):
            val = (line.split('\\t')[val])
            val = re.findall("\d+", val)
            vals = vals + [val]
            val = str(val[0])
            f.write(val)

            # do not write \t after last value
            if val != toRead:
                f.write("\t")
            
        print(vals)
        f.write("\n")
    f.close()

if __name__ == "__main__":
    main()