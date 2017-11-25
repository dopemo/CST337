#include <stdio.h>
#include <string.h>

/* This is the code for the Morse code encoder project being used
 * as the main project for Team 3's Arduino project for CST337.
 * Team 3 is David Wong, Mohamad Khalifa, Rosa Garza, and Sean Trehy.
 */

const int END_WORD = 0;
const int END_LETTER = 1;
const int DOT = 2;
const int DASH = 3;
const int END_SEQUENCE = 4;
const int LED_A = 6;
const int BUZZER = 9;
const int ONE_MORSE = 50;
const int TWO_MORSE = 100;
const int THREE_MORSE = 150;
const int FOUR_MORSE = 200;
const int FORTY_MORSE = 2000; // Debugging code.
String comdata = "";

void outputMorseMessage(const char*);

void setup() {
  Serial.begin(9600);
  Serial.print("Please input a message to be displayed in Morse Code:\n");
  // put your setup code here, to run once:

  //Set the LED to display the Morse code as a light to output mode.
  pinMode(LED_A, OUTPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    comdata = "";
    while(Serial.available() > 0) {
        comdata += char(Serial.read());
    }
    Serial.print(comdata);
    Serial.println();
  }
  outputMorseMessage(comdata);
}

void outputMorseMessage(String message) {
 int message_length = strlen(message.c_str());
 for (int i = 0; i <= message_length; i++) {
  if (i == message_length)  {
    outputMorseSequence(END_SEQUENCE);
  }
  else {
    char current_letter = static_cast<char>(tolower(message[i]));
    if (current_letter == ' ') {
      outputMorseSequence(END_WORD);
    }
    else {
      outputMorseLetter(current_letter);
      outputMorseSequence(END_LETTER);
    }
  }
 }
}
void outputMorseLetter(const char letter) {
    if (letter == 'a') {
      outputMorseSequence(DOT);
      outputMorseSequence(DASH);
    }
    else if (letter == 'b') {
      outputMorseSequence(DASH);
      outputMorseSequence(DOT);
      outputMorseSequence(DOT);
      outputMorseSequence(DOT);
    }
    else if (letter == 'c') {
      outputMorseSequence(DASH);
      outputMorseSequence(DOT);
      outputMorseSequence(DASH);
      outputMorseSequence(DOT);
    }
    else if (letter == 'd') {
      outputMorseSequence(DASH);
      outputMorseSequence(DOT);
      outputMorseSequence(DOT);
    }
    else if (letter == 'e') {
      outputMorseSequence(DOT);
    }
    else if (letter == 'f') {
      outputMorseSequence(DOT);
      outputMorseSequence(DOT);
      outputMorseSequence(DASH);
      outputMorseSequence(DOT);
    }
    else if (letter == 'g') { 
      outputMorseSequence(DASH);
      outputMorseSequence(DASH);
      outputMorseSequence(DOT);
    }
    else if (letter == 'h') {
      outputMorseSequence(DOT);
      outputMorseSequence(DOT);
      outputMorseSequence(DOT);
      outputMorseSequence(DOT);
    }
    else if (letter == 'i') {
      outputMorseSequence(DOT);
      outputMorseSequence(DOT);
    }
    else if (letter == 'j') {
      outputMorseSequence(DOT);
      outputMorseSequence(DASH);
      outputMorseSequence(DASH);
      outputMorseSequence(DASH);
    }
    else if (letter == 'k') {
      outputMorseSequence(DASH);
      outputMorseSequence(DOT);
      outputMorseSequence(DASH);
    }
    else if (letter == 'l') {
      outputMorseSequence(DOT);
      outputMorseSequence(DASH);
      outputMorseSequence(DOT);
      outputMorseSequence(DOT);
    }
    else if (letter == 'm') {
      outputMorseSequence(DASH);
      outputMorseSequence(DASH);
    }
    else if (letter == 'n') {
      outputMorseSequence(DASH);
      outputMorseSequence(DOT);
    }
    else if (letter == 'o') {
      outputMorseSequence(DASH);
      outputMorseSequence(DASH);
      outputMorseSequence(DASH);
    }
    else if (letter == 'p') {
      outputMorseSequence(DOT);
      outputMorseSequence(DASH);
      outputMorseSequence(DASH);
      outputMorseSequence(DOT);
    }
    else if (letter == 'q') {
      outputMorseSequence(DASH);
      outputMorseSequence(DASH);
      outputMorseSequence(DOT);
      outputMorseSequence(DASH);
    }
    else if (letter == 'r') {
      outputMorseSequence(DOT);
      outputMorseSequence(DASH);
      outputMorseSequence(DOT);
    }
    else if (letter == 's') {
      outputMorseSequence(DOT);
      outputMorseSequence(DOT);
      outputMorseSequence(DOT);
    }
    else if (letter == 't') {
      outputMorseSequence(DASH);
    }
    else if (letter == 'u') {
      outputMorseSequence(DOT);
      outputMorseSequence(DOT);
      outputMorseSequence(DASH);
    }
    else if (letter == 'v') {
      outputMorseSequence(DOT);
      outputMorseSequence(DOT);
      outputMorseSequence(DOT);
      outputMorseSequence(DASH);
    }
    else if (letter == 'w') {
      outputMorseSequence(DOT);
      outputMorseSequence(DASH);
      outputMorseSequence(DASH);
    }
    else if (letter == 'x') {
      outputMorseSequence(DASH);
      outputMorseSequence(DOT);
      outputMorseSequence(DOT);
      outputMorseSequence(DASH);
    }
    else if (letter == 'y') {
      outputMorseSequence(DASH);
      outputMorseSequence(DOT);
      outputMorseSequence(DASH);
      outputMorseSequence(DASH);
    }
    else if (letter == 'z') {
      outputMorseSequence(DASH);
      outputMorseSequence(DASH);
      outputMorseSequence(DOT);
      outputMorseSequence(DOT);
    }
    else if (letter == '1') {
      outputMorseSequence(DOT);
      outputMorseSequence(DASH);
      outputMorseSequence(DASH);
      outputMorseSequence(DASH);
      outputMorseSequence(DASH);
    }
    else if (letter == '2') {
      outputMorseSequence(DOT);
      outputMorseSequence(DOT);
      outputMorseSequence(DASH);
      outputMorseSequence(DASH);
      outputMorseSequence(DASH);
    }
    else if (letter == '3') {
      outputMorseSequence(DOT);
      outputMorseSequence(DOT);
      outputMorseSequence(DOT);
      outputMorseSequence(DASH);
      outputMorseSequence(DASH);
    }
    else if (letter == '4') {
      outputMorseSequence(DOT);
      outputMorseSequence(DOT);
      outputMorseSequence(DOT);
      outputMorseSequence(DOT);
      outputMorseSequence(DASH);
    }
    else if (letter == '5') {
      outputMorseSequence(DOT);
      outputMorseSequence(DOT);
      outputMorseSequence(DOT);
      outputMorseSequence(DOT);
      outputMorseSequence(DOT);
    }
    else if (letter == '6') {
      outputMorseSequence(DASH);
      outputMorseSequence(DOT);
      outputMorseSequence(DOT);
      outputMorseSequence(DOT);
      outputMorseSequence(DOT);
    }
    else if (letter == '7') {
      outputMorseSequence(DASH);
      outputMorseSequence(DASH);
      outputMorseSequence(DOT);
      outputMorseSequence(DOT);
      outputMorseSequence(DOT);
    }
    else if (letter == '8') {
      outputMorseSequence(DASH);
      outputMorseSequence(DASH);
      outputMorseSequence(DASH);
      outputMorseSequence(DOT);
      outputMorseSequence(DOT);
    }
    else if (letter == '9') {
      outputMorseSequence(DASH);
      outputMorseSequence(DASH);
      outputMorseSequence(DASH);
      outputMorseSequence(DASH);
      outputMorseSequence(DOT);
    }
    else if (letter == '0') {
      outputMorseSequence(DASH);
      outputMorseSequence(DASH);
      outputMorseSequence(DASH);
      outputMorseSequence(DASH);
      outputMorseSequence(DASH);
    }
    else if (letter == '.') {
      outputMorseSequence(DOT);
      outputMorseSequence(DASH);
      outputMorseSequence(DOT);
      outputMorseSequence(DASH);
      outputMorseSequence(DOT);
      outputMorseSequence(DASH);
    }
    else if (letter == ',') {
      outputMorseSequence(DASH);
      outputMorseSequence(DASH);
      outputMorseSequence(DOT);
      outputMorseSequence(DOT);
      outputMorseSequence(DASH);
      outputMorseSequence(DASH);
    }
    else if (letter == '?') {
      outputMorseSequence(DOT);
      outputMorseSequence(DOT);
      outputMorseSequence(DASH);
      outputMorseSequence(DASH);
      outputMorseSequence(DOT);
      outputMorseSequence(DOT);
    }
    else if (letter == '\'') {
      outputMorseSequence(DOT);
      outputMorseSequence(DASH);
      outputMorseSequence(DASH);
      outputMorseSequence(DASH);
      outputMorseSequence(DASH);
      outputMorseSequence(DOT);
    }
    else if (letter == '!') {
      outputMorseSequence(DASH);
      outputMorseSequence(DOT);
      outputMorseSequence(DASH);
      outputMorseSequence(DOT);
      outputMorseSequence(DASH);
      outputMorseSequence(DASH);
    }
    else if (letter == '/') {
      outputMorseSequence(DASH);
      outputMorseSequence(DOT);
      outputMorseSequence(DOT);
      outputMorseSequence(DASH);
      outputMorseSequence(DOT);
    }
    else if (letter == '(') {
      outputMorseSequence(DASH);
      outputMorseSequence(DOT);
      outputMorseSequence(DASH);
      outputMorseSequence(DASH);
      outputMorseSequence(DOT);
    }
    else if (letter == ')') {
      outputMorseSequence(DASH);
      outputMorseSequence(DOT);
      outputMorseSequence(DASH);
      outputMorseSequence(DASH);
      outputMorseSequence(DOT);
      outputMorseSequence(DASH);
    }
    else if (letter == '&') {
      outputMorseSequence(DOT);
      outputMorseSequence(DASH);
      outputMorseSequence(DOT);
      outputMorseSequence(DOT);
      outputMorseSequence(DOT);
    }
    else if (letter == ':') {
      outputMorseSequence(DASH);
      outputMorseSequence(DASH);
      outputMorseSequence(DASH);
      outputMorseSequence(DOT);
      outputMorseSequence(DOT);
      outputMorseSequence(DOT);
    }
    else if (letter == ';') {
      outputMorseSequence(DASH);
      outputMorseSequence(DOT);
      outputMorseSequence(DASH);
      outputMorseSequence(DOT);
      outputMorseSequence(DASH);
      outputMorseSequence(DOT);
    }
    else if (letter == '=') {
      outputMorseSequence(DASH);
      outputMorseSequence(DOT);
      outputMorseSequence(DOT);
      outputMorseSequence(DOT);
      outputMorseSequence(DASH);
    }
    else if (letter == '+') {
      outputMorseSequence(DOT);
      outputMorseSequence(DASH);
      outputMorseSequence(DOT);
      outputMorseSequence(DASH);
      outputMorseSequence(DOT);
    }
    else if (letter == '-') {
      outputMorseSequence(DASH);
      outputMorseSequence(DOT);
      outputMorseSequence(DOT);
      outputMorseSequence(DOT);
      outputMorseSequence(DOT);
      outputMorseSequence(DASH);
    }
    else if (letter == '_') {
      outputMorseSequence(DOT);
      outputMorseSequence(DOT);
      outputMorseSequence(DASH);
      outputMorseSequence(DASH);
      outputMorseSequence(DOT);
      outputMorseSequence(DASH);
    }
    else if (letter == '\"') {
      outputMorseSequence(DOT);
      outputMorseSequence(DASH);
      outputMorseSequence(DOT);
      outputMorseSequence(DOT);
      outputMorseSequence(DASH);
      outputMorseSequence(DOT);
    }
    else if (letter == '$') {
      outputMorseSequence(DOT);
      outputMorseSequence(DOT);
      outputMorseSequence(DOT);
      outputMorseSequence(DASH);
      outputMorseSequence(DOT);
      outputMorseSequence(DOT);
      outputMorseSequence(DASH);
    }
    else if (letter == '@') {
      outputMorseSequence(DOT);
      outputMorseSequence(DASH);
      outputMorseSequence(DASH);
      outputMorseSequence(DOT);
      outputMorseSequence(DASH);
      outputMorseSequence(DOT);
    }
}

void outputResults(int on_off) {
  digitalWrite(BUZZER, on_off);
  digitalWrite(LED_A, on_off);
}

void outputMorseSequence(int action) {
  switch(action){
    case DOT:
      outputResults(HIGH);
      delay(ONE_MORSE);
      outputResults(LOW);
      delay(ONE_MORSE);
      break;
    case DASH:
      outputResults(HIGH);
      delay(THREE_MORSE);
      outputResults(LOW);
      delay(ONE_MORSE);
      break;
    case END_LETTER:
      delay(TWO_MORSE);
      break;
    case END_WORD:
      delay(FOUR_MORSE);
      break;
    case END_SEQUENCE:
      delay(FORTY_MORSE);
      break;
  }
}

