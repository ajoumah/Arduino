#include <Stepper.h>

// --- Motor Configuration ---
#define STEPS_PER_REV 200
const byte motorPin1 = 8;
const byte motorPin2 = 9;
const byte motorPin3 = 10;
const byte motorPin4 = 11;

Stepper stepperMotor(STEPS_PER_REV, motorPin1, motorPin2, motorPin3, motorPin4);

// --- Control Pins ---
const byte buttonPin = 2;
const byte ledPin = 13;

// --- State Variables ---
bool motorRunning = false;
bool lastButtonState = LOW;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

// --- Flash LED Timer ---
unsigned long lastFlashTime = 0;
const unsigned long flashInterval = 500;
bool ledState = LOW;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Uses internal pull-up resistor
  pinMode(ledPin, OUTPUT);

  stepperMotor.setSpeed(60); // RPM

  Serial.begin(9600);
  Serial.println("Stepper Motor Ready. Press button to start/stop.");
}

void loop() {
  handleButton();
  flashReadyLED();

  if (motorRunning) {
    stepperMotor.step(1); // Run slowly while ON
  }
}

// --- Button Handling with Debounce ---
void handleButton() {
  bool reading = digitalRead(buttonPin);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading == LOW && lastButtonState == HIGH) { // Button press detected
      motorRunning = !motorRunning;
      Serial.print("Motor State: ");
      Serial.println(motorRunning ? "RUNNING" : "STOPPED");
    }
  }

  lastButtonState = reading;
}

// --- Flash LED when motor is stopped ---
void flashReadyLED() {
  if (!motorRunning) {
    if (millis() - lastFlashTime >= flashInterval) {
      ledState = !ledState;
      digitalWrite(ledPin, ledState);
      lastFlashTime = millis();
    }
  } else {
    digitalWrite(ledPin, HIGH); // Constant ON when motor running
  }
}
