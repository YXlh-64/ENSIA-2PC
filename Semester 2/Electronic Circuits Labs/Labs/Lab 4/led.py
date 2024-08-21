import RPi.GPIO as GPIO         # Import Raspberry Pi GPIO library
from time import sleep          # Import the sleep function 

pinLED = 7                      # LED GPIO Pin LED

GPIO.setmode(GPIO.BOARD)          # Use GPIO pin number
GPIO.setwarnings(False) 
#sleep(5)        # Ignore warnings in our case
GPIO.setup(pinLED, GPIO.OUT)    # GPIO pin as output pi
GPIO.output(pinLED, GPIO.LOW)
