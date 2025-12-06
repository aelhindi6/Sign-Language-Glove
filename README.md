# Sign-Language-Glove
A wearable Arduino device that translates hand gestures into text using five flex sensors and an LCD. It recognizes gestures like “thumbs up” and displays corresponding messages. The prototype works on a breadboard; final integration will mount sensors on a glove and add audio output.


# Understanding and Explanation of Hardware Components
For our prototype, we used 5 flex sensors to resemble each finger on a human hand.
- Input/Output: Each flex sensor provides analog input. The analog values will be
sent to the Arduino, where they (the values) are read and processed in real-time.

- How it works: The values from flex sensors will be changed when the sensor is
bending. A large bend (such as 180 degrees) will increase the resistance, which
gives changes in the voltage across the sensor.

- Why it was chosen: Flex sensors are thin, flexible, easy to mount on a glove, and
provide consistent continuous values representing finger movement - ideal for
detecting hand gestures.

# The output device is a 16x2 LCD display:
- Input/Output: values read and processed from the flex sensor through Arduino. It
will display the correspondence text that matches the detected gesture on the LCD.

- How it works: After reading the analog values from the flex sensors, the Arduino
runs logic to classify the gesture. The resulting text output (e.g., a letter or phrase) is
sent to the LCD using digital control pins. The LCD then prints the message on its
screen.

- Why was it chosen: It is useful when you want to debug/see if the output values
match the expectation or not. When doing on breadboard, we can see the output on
the Serial Monitor, but when we have the actual hardware, it is easier to look at
Basic Functionality:

# We successfully make the hardware work as expected:
- Reading analog values from flex sensors to Arduino
- The Arduino processes the signal to determine the hand gesture, finger position
- The results are displayed on the 16x2 LCD screen as text output

- **Program Flow & Testing**

**Main Program Loop:** Continuously reads analog values from all five flex sensors. The code compares each reading against a calibrated threshold to determine if a finger is "bent" or "straight." Based on the specific combination of bent fingers, it identifies a gesture and outputs the corresponding message to the LCD.

**Testing & Debugging:** Utilized the serial monitor extensively to calibrate sensor thresholds and debug hardware issues.

**Component Verification:** Tested every individual component by executing four core gesture tests: standby, thumbs up, rock on, and pointing.

**Validation:** These tests confirmed the correct functionality of each flex sensor and the LCD display system.

<img width="700" height="931" alt="image" src="https://github.com/user-attachments/assets/cf0532ea-cf88-4913-85de-835f58a60009" />


