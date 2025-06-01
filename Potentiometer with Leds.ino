// === LED Chase with Speed Control and Fading ===

// Define new LED pins (PWM-capable for fading)
const byte lightPins[] = {3, 5, 6, 9, 10, 11}; 
const byte totalLights = sizeof(lightPins) / sizeof(lightPins[0]);

// Potentiometer connected to analog pin A0
const byte potentiometerPin = A0;

// State variables
int brightness = 255;              // Max brightness (0-255)
int activeLED = 0;                 // Current active LED index
int chaseDirection = 1;           // Direction of movement
unsigned long previousMillis = 0; // Last update time
int speedDelay = 0;               // Delay based on potentiometer

void setup() {
  Serial.begin(9600); // Debugging output

  // Set all LED pins to OUTPUT
  for (byte i = 0; i < totalLights; i++) {
    pinMode(lightPins[i], OUTPUT);
    analogWrite(lightPins[i], 0); // Start all LEDs off
  }

  Serial.println("LED Chase System Ready");
}

void loop() {
  // Read potentiometer and map it to delay (10 to 500 ms)
  int potValue = analogRead(potentiometerPin);
  speedDelay = map(potValue, 0, 1023, 10, 500);

  // Update LED state based on timing
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= speedDelay) {
    previousMillis = currentMillis;
    updateLEDs();
  }
}

void updateLEDs() {
  // Turn off all LEDs
  for (byte i = 0; i < totalLights; i++) {
    analogWrite(lightPins[i], 0);
  }

  // Fade the previous LED slightly (ghost effect)
  int previousLED = activeLED - chaseDirection;
  if (previousLED >= 0 && previousLED < totalLights) {
    analogWrite(lightPins[previousLED], brightness / 4);
  }

  // Light the current LED
  analogWrite(lightPins[activeLED], brightness);

  // Move to the next LED
  activeLED += chaseDirection;

  // Reverse direction if we reach the end
  if (activeLED >= totalLights) {
    activeLED = totalLights - 2;
    chaseDirection = -1;
  } else if (activeLED < 0) {
    activeLED = 1;
    chaseDirection = 1;
  }

  // Debugging info
  Serial.print("LED: ");
  Serial.print(activeLED);
  Serial.print(" | Delay: ");
  Serial.println(speedDelay);
}
