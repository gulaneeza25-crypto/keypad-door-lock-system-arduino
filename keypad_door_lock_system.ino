#include <Keypad.h>
#include <Servo.h>

Servo myServo;

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {6, 7, 8, 9};
byte colPins[COLS] = {2, 3, 4, 5};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

String password = "1234";
String input = "";

bool entryMode = false;
bool doorUnlocked = false;

unsigned long unlockedAt = 0;                 // time when door was opened
const unsigned long autoLockDelay = 4000UL;   // auto-lock delay in milliseconds (4000 = 4 seconds)

void setup() {
  Serial.begin(9600);

  myServo.attach(10);

  // Start with DOOR LOCKED
  myServo.write(90);
  Serial.println("Door Locked.");
  Serial.println("Press # to start entering password.");
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    Serial.print("Key: ");
    Serial.println(key);

    // Start entering password
    if (key == '#' && !entryMode) {
      entryMode = true;
      input = "";
      Serial.println("Enter password, then press # again.");
      return;
    }

    // Submit password
    if (key == '#' && entryMode) {
      entryMode = false;
      if (input == password) {
        Serial.println("Correct Password!");
        myServo.write(0);   // OPEN DOOR
        Serial.println("Door OPENED.");
        doorUnlocked = true;
        unlockedAt = millis(); // start auto-lock timer
      } else {
        Serial.println("Wrong Password!");
      }
      input = "";
      return;
    }

    // Clear input
    if (key == '*') {
      input = "";
      Serial.println("Input Cleared.");
      return;
    }

    // Lock door manually using D
    if (key == 'D') {
      myServo.write(90);  // LOCK DOOR
      Serial.println("Door LOCKED manually.");
      doorUnlocked = false;
      unlockedAt = 0;
      return;
    }

    // Add number keys
    if (entryMode) {
      if (key >= '0' && key <= '9') {
        input += key;
        Serial.print("Typed: ");
        Serial.println(input);
      }
    }
  }

  // Auto-lock logic (non-blocking)
  if (doorUnlocked) {
    if (millis() - unlockedAt >= autoLockDelay) {
      myServo.write(90);       // LOCK DOOR
      Serial.println("Auto-lock: Door LOCKED.");
      doorUnlocked = false;
      unlockedAt = 0;
    }
  }
}
