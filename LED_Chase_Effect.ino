// Project: Advanced LED Chase with Multiple Modes
// Same pins: LEDs on digital pins 4 to 13

const byte ledPins[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
const int numLeds = sizeof(ledPins);
int currentLED = 0;
int direction = 1;
unsigned long lastUpdate = 0;
int baseDelay = 80;
int mode = 0;           // 0 = classic, 1 = bounce, 2 = fill, 3 = blink-all, 4 = sparkle
unsigned long modeSwitchTime = 0;
const int modeInterval = 8000;  // switch modes every 8 seconds

void setup() {
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  randomSeed(analogRead(0)); // for sparkle randomness
}

void loop() {
  unsigned long currentTime = millis();

  // Change mode every 8 seconds
  if (currentTime - modeSwitchTime > modeInterval) {
    mode = (mode + 1) % 5;
    modeSwitchTime = currentTime;
    clearAllLeds();
  }

  // LED update based on current mode
  if (currentTime - lastUpdate > baseDelay) {
    lastUpdate = currentTime;

    switch (mode) {
      case 0: classicChase(); break;
      case 1: bounceChase(); break;
      case 2: fillChase(); break;
      case 3: blinkAll(); break;
      case 4: sparkle(); break;
    }
  }
}

// ==== Mode Functions ====

void classicChase() {
  clearAllLeds();
  digitalWrite(ledPins[currentLED], HIGH);
  currentLED = (currentLED + 1) % numLeds;
}

void bounceChase() {
  clearAllLeds();
  digitalWrite(ledPins[currentLED], HIGH);
  currentLED += direction;
  if (currentLED == numLeds - 1 || currentLED == 0) direction *= -1;
}

void fillChase() {
  digitalWrite(ledPins[currentLED], HIGH);
  currentLED++;
  if (currentLED >= numLeds) {
    currentLED = 0;
    clearAllLeds();
  }
}

void blinkAll() {
  static bool on = false;
  on = !on;
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], on ? HIGH : LOW);
  }
}

void sparkle() {
  clearAllLeds();
  for (int i = 0; i < 3; i++) {
    int randLed = random(numLeds);
    digitalWrite(ledPins[randLed], HIGH);
  }
}

// ==== Utility ====
void clearAllLeds() {
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}
