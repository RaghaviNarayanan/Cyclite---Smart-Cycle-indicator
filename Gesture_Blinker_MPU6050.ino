#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050.h"

MPU6050 mpu;
int16_t ax, ay, az;
int16_t gx, gy, gz;

struct MyData {
  byte X;
  byte Y;
  byte Z;
};

MyData data;

const int leftLED = 8;
const int rightLED = 9;

unsigned long lastBlinkTime = 0;
bool ledState = false;

bool leftBlinking = false;
bool rightBlinking = false;

const unsigned long blinkInterval = 500;  // ms

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu.initialize();

  pinMode(leftLED, OUTPUT);
  pinMode(rightLED, OUTPUT);
}

void loop() {
  // Read sensor values
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  data.X = map(ax, -17000, 17000, 0, 255);
  data.Y = map(ay, -17000, 17000, 0, 255);
  data.Z = map(az, -17000, 17000, 0, 255);

  Serial.print("X: ");
  Serial.print(data.X);
  Serial.print(" | Y: ");
  Serial.print(data.Y);
  Serial.print(" | Z: ");
  Serial.println(data.Z);

  // Define tilt ranges
  bool isLeftTilt = (data.X < 40);
  bool isRightTilt = (data.X > 220);
  bool isStraight = (data.X >= 100 && data.X <= 160);

  unsigned long currentMillis = millis();

  // LEFT tilt detected
  if (isLeftTilt) {
    leftBlinking = true;
    rightBlinking = false;
    digitalWrite(rightLED, LOW); // stop right if it was on
  }

  // RIGHT tilt detected
  else if (isRightTilt) {
    rightBlinking = true;
    leftBlinking = false;
    digitalWrite(leftLED, LOW); // stop left if it was on
  }

  // STRAIGHT position
  else if (isStraight) {
    leftBlinking = false;
    rightBlinking = false;
    digitalWrite(leftLED, LOW);
    digitalWrite(rightLED, LOW);
  }

  // Blinking logic
  if (leftBlinking || rightBlinking) {
    if (currentMillis - lastBlinkTime >= blinkInterval) {
      lastBlinkTime = currentMillis;
      ledState = !ledState;

      if (leftBlinking) {
        digitalWrite(leftLED, ledState);
      }
      if (rightBlinking) {
        digitalWrite(rightLED, ledState);
      }
    }
  }

  delay(100);
}
