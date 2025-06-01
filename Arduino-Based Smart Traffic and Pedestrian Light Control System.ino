// === Pin Assignments ===
const byte carStopLED = 12;
const byte carReadyLED = 11;
const byte carGoLED = 10;

const byte pedWaitLED = 9;
const byte pedWalkLED = 8;

const byte pedButtonPin = 2;

// === Timing Settings ===
const unsigned long walkDuration = 5000;
const unsigned long debounceTime = 50;
const unsigned long minWaitTime = 5000; // minimum time between button presses

// === State Variables ===
unsigned long lastChangeTimestamp = 0;
unsigned long lastButtonPress = 0;
bool waitingToCross = false;

void setup() {
  // Car lights
  pinMode(carStopLED, OUTPUT);
  pinMode(carReadyLED, OUTPUT);
  pinMode(carGoLED, OUTPUT);

  // Pedestrian lights
  pinMode(pedWaitLED, OUTPUT);
  pinMode(pedWalkLED, OUTPUT);

  // Button input
  pinMode(pedButtonPin, INPUT_PULLUP); // Use internal pull-up resistor

  // Initial state: cars go, pedestrians stop
  activateCarGo();
  activatePedWait();
  
  Serial.begin(9600);
}

void loop() {
  handleButtonPress();

  // Check if pedestrian request has been made and allowed by timer
  if (waitingToCross && (millis() - lastChangeTimestamp > minWaitTime)) {
    Serial.println("Changing lights for pedestrian crossing...");
    executeCrossingSequence();
    waitingToCross = false;
  }
}

// === Handle Button with Debounce ===
void handleButtonPress() {
  static bool lastButtonState = HIGH;
  static unsigned long lastDebounce = 0;

  bool currentButton = digitalRead(pedButtonPin);

  if (currentButton != lastButtonState) {
    lastDebounce = millis();
    lastButtonState = currentButton;
  }

  if ((millis() - lastDebounce) > debounceTime && currentButton == LOW) {
    if (!waitingToCross) {
      waitingToCross = true;
      Serial.println("Pedestrian requested to cross.");
    }
  }
}

// === Crossing Sequence Function ===
void executeCrossingSequence() {
  deactivateCarGo();
  activateCarReady();
  delay(2000);

  deactivateCarReady();
  activateCarStop();
  delay(1000); // Safety wait before pedestrians cross

  deactivatePedWait();
  activatePedWalk();
  delay(walkDuration);

  flashPedWalk(6); // Flashing countdown for pedestrians

  activatePedWait();
  delay(500);

  activateCarReady();
  deactivateCarStop();
  delay(1000);

  activateCarGo();
  deactivateCarReady();

  lastChangeTimestamp = millis();
}

// === Helper Functions ===
void activateCarGo() {
  digitalWrite(carGoLED, HIGH);
}

void deactivateCarGo() {
  digitalWrite(carGoLED, LOW);
}

void activateCarReady() {
  digitalWrite(carReadyLED, HIGH);
}

void deactivateCarReady() {
  digitalWrite(carReadyLED, LOW);
}

void activateCarStop() {
  digitalWrite(carStopLED, HIGH);
}

void deactivateCarStop() {
  digitalWrite(carStopLED, LOW);
}

void activatePedWait() {
  digitalWrite(pedWaitLED, HIGH);
}

void deactivatePedWait() {
  digitalWrite(pedWaitLED, LOW);
}

void activatePedWalk() {
  digitalWrite(pedWalkLED, HIGH);
}

void deactivatePedWalk() {
  digitalWrite(pedWalkLED, LOW);
}

void flashPedWalk(int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(pedWalkLED, HIGH);
    delay(300);
    digitalWrite(pedWalkLED, LOW);
    delay(300);
  }
}
