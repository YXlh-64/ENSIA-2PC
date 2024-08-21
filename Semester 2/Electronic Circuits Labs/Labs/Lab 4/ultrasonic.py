import RPi.GPIO as GPIO
import time

# Set GPIO numbering mode
GPIO.setmode(GPIO.BCM)

# Define GPIO pins
TRIG_PIN = 18
ECHO_PIN = 24
pinLED = 26  # Assuming you are using GPIO pin 22 for the LED

# Set up GPIO pins
GPIO.setup(TRIG_PIN, GPIO.OUT)
GPIO.setup(ECHO_PIN, GPIO.IN)
GPIO.setup(pinLED, GPIO.OUT)

def measure_distance():
    # Ensure the trigger pin is low
    GPIO.output(TRIG_PIN, False)
    time.sleep(0.001)

    # Generate 10us pulse on TRIG_PIN
    # Generate 10us pulse on TRIG_PIN
    GPIO.output(TRIG_PIN, True)
    time.sleep(0.000dd001)
    GPIO.output(TRIG_PIN, False)

    # Measure the duration of the echo pulse
    while GPIO.input(ECHO_PIN) == 0:
        pulse_start = time.time()
    while GPIO.input(ECHO_PIN) == 1:
        pulse_end = time.time()

    # Calculate distance in centimeters
    pulse_duration = pulse_end - pulse_start
    distance = pulse_duration * 17150
    distance = round(distance, 2)

    return distance

try:
    while True:
        dist = measure_distance()
        print("Distance:", dist, "cm")

        if dist < 20:
            GPIO.output(pinLED, GPIO.HIGH)  # Turn on LED
        else:
            GPIO.output(pinLED, GPIO.LOW)   # Turn off LED

        time.sleep(1)

except KeyboardInterrupt:
    GPIO.cleanup()
