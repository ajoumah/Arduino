#include <Stepper.h>

// === Configuration Constants ===

// Number of steps per revolution (depends on your motor)
#define STEPS_PER_REV 200

// Motor control pins (connected to SN754410 or L293D)
const byte motorPinA1 = 8;
const byte motorPinA2 = 9;
const byte motorPinB1 = 10;
const byte motorPinB2 = 11;

// Create Stepper motor instance
Stepper myMotor(STEPS_PER_REV, motorPinA1, motorPinA2, motorPinB1, motorPinB2);

// Speed configuration
int minSpeed = 10;     // Minimum RPM
int maxSpeed = 100;    // Maximum RPM
int rampStep = 10;     // RPM increment during ramp-up/down

// Direction flags
bool rotateForward = true;

// === Setup Function ===
void setup() {
  Serial.begin(9600); // Debug output

  // Initial speed setup
  myMotor.setSpeed(minSpeed);

  Serial.println("Stepper Motor Initialized.");
  Serial.println("Ensure capacitors and resistor are placed for safety.");
}

/**
 * Gradually increase or decrease speed to simulate acceleration/deceleration
 */
void rampSpeed(bool rampUp) {
  if (rampUp) {
    for (int speed = minSpeed; speed <= maxSpeed; speed += rampStep) {
      myMotor.setSpeed(speed);
      myMotor.step(20); // Small step with current speed
    }
  } else {
    for (int speed = maxSpeed; speed >= minSpeed; speed -= rampStep) {
      myMotor.setSpeed(speed);
      myMotor.step(20);
    }
  }
}

// === Main Loop ===
void loop() {
  Serial.println("Rotating forward with ramp...");
  rampSpeed(true);
  myMotor.step(STEPS_PER_REV); // 1 full revolution
  delay(500);

  Serial.println("Rotating backward with ramp...");
  rampSpeed(false);
  myMotor.step(-STEPS_PER_REV / 2); // Half revolution in reverse
  delay(500);
}
