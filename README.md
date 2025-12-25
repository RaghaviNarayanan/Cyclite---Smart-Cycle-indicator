# Cyclite---Smart-Cycle-indicator
Cyclite is a smart, gesture-controlled cycle indicator system designed to improve cyclist safety by providing a hands-free way to signal turns. The system allows cyclists to indicate left and right turns without removing their hands from the handlebar, reducing the risk of imbalance and accidents.

The project flow begins with a wearable glove worn by the cyclist. This glove contains an Arduino Nano, an MPU6050 sensor, and an HC-05 Bluetooth module. The MPU6050 continuously measures the tilt of the cyclist’s hand using acceleration and gyroscope data. When the cyclist tilts their hand to the left or right, the sensor detects this movement and converts it into digital values.

These sensor values are processed by the Arduino on the glove, which checks whether the hand movement corresponds to a left or right turn gesture. Once a valid gesture is detected, the Arduino sends a simple command wirelessly using Bluetooth. The Bluetooth module on the glove acts as the master and transmits this command to the bicycle-mounted unit.

The second part of the system is mounted on the bicycle. This slave unit also uses an Arduino Nano and an HC-05 Bluetooth module, along with LED indicators. When the slave unit receives the gesture command from the glove, it decodes the message and activates the corresponding LED indicator. If a left turn is detected, the left-side LEDs blink, and if a right turn is detected, the right-side LEDs blink. The LEDs blink for a fixed duration and then turn off automatically.

The entire system operates wirelessly and in real time. The cyclist only needs to tilt their hand slightly to activate the indicator, while maintaining full control of the bicycle. This makes the signaling process safer, more visible, and more reliable, especially during night-time riding or in heavy traffic.

Overall, the project flow starts with gesture detection using an IMU sensor, followed by wireless transmission using Bluetooth, and ends with clear visual indication using LEDs on the bicycle. This flow demonstrates how embedded systems, sensors, and wireless communication can be combined to enhance road safety for cyclists.
