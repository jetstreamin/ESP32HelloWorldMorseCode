#include <Arduino.h>
#include <string.h>

int shortDelay = 200;
int longDelay = 800;
int waitDelay = 2000;
String message = "Hello IoT World!";
// Morse code for each letter of "Hello IoT World"
extern String morseCode[] = {
"....", // H
".", // E
".-..", // L
".-..", // L
"---", // O
" ", // SPACE
"..", // I
"---", // O
" - ", // T
".", // E
"--.", // N
"--.", // N
"---", // O
" ", // SPACE
".--", // W
".-", // O
".-..", // L
".-..", // L
"--", // D
};

// Length of the morseCode array
const int messageLength = 17;

void blinkMorseCode(String morseCode[], int length) {
  // Iterate through each letter of the message
  for (int i = 0; i < length; i++) {
    // Get the current letter
    String letter = morseCode[i];
    // Iterate through each dot or dash in the letter
    for (int j = 0; j < letter.length(); j++) {
      // Turn the LED on
      digitalWrite(LED_BUILTIN, HIGH);

      // Set the delay based on the dot or dash
      int delayTime;
      if (letter == ".") {
        delayTime = shortDelay;
      } else {
        delayTime = longDelay;
      }

      // Wait for the appropriate amount of time
      delay(delayTime);

      // Turn the LED off
      digitalWrite(LED_BUILTIN, LOW);

      // Wait a short delay between dots and dashes
      delay(waitDelay);
    }
  }
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(921600);
  Serial.println(message);
}

void loop() {
  delay(waitDelay);
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println(message);
  blinkMorseCode(morseCode, messageLength);
  delay(waitDelay);
  digitalWrite(LED_BUILTIN, LOW);
}