/*        Morse Code Taillight Project version 2
 * 
 * This code will loop through a string of characters and convert these
 * to morse code. It will make a led taillight blink.
 * 
 * Flashing taillights stand out more than steady state lights.
 * 
 * 
 *        AtTiny85   ledPin
 *  Vcc      8
 *  Gnd      4
 *           6          +      // 330 ohm resistance to drive 2N2222 base
 * 
 * 
 * LICENCE
 * Copyright may 2021 Robert de Beer
 * 
 * Licensed under the Apache License, Version 2.0 ( the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
 * For an AtTiny85:
 *    program uses 1270 ( 15%) bytes program space
 *    variables use 399 ( 77%) bytes of dynamic memory
*/

#define ledPin A2                                     // assign name to pin

char readChar;

char *letters[] = {                                   // letters a-z in morse code  
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
  "....", "..", ".---", "-.-", ".-..", "--", "-.",
  "---", ".--.", "--.-", ".-.", "...", "-", "..-",
  "...-", ".--", "-..-", "-.--", "--.." };

char *numbers[] = {                                   // numbers 0-9 in morse code  
  "-----", ".----", "..---", "...--", "....-",
  ".....", "-....", "--...", "---..", "----." };

char *symbols[] = {                                   // symbols !-/ in morse code
  "-.-.--", ".-..-.", " ", "...-..-", " ", ".-...", ".----.",
  "-.--.", "-.--.-", " ", ".-.-.", "--..--", "-...-", ".-.-.-"};

char textToMorseCode[] = "Canego stand-up e-scooters ROCK! "
                          "Give us a call at 0033 670 130 931 for your next adventure. "
                          "Please do not hit me, I am fragile. Thank you and drive safe!";

unsigned int dotMillis = 80;                          // 80 = 15 words per minute, 100 = 12wpm


void setup() {
  pinMode( ledPin, OUTPUT);
}


void loop() {
  for( int i = 0; i < sizeof( textToMorseCode) - 1; i++){
    readChar = toLowerCase( textToMorseCode[i]);
    if( readChar >= 'a' && readChar <= 'z'){          // check for alphabet
      flashMorseCode( letters[ readChar - 'a']);
    } else if ( readChar >= '0' && readChar <= '9'){  // check for numbers
      flashMorseCode( numbers[ readChar - '0']);
    } else if ( readChar >= '!' && readChar <= '.'){  // check for symbols
      flashMorseCode( symbols[ readChar - '!']);
    } else if ( readChar == ' ') {                    // check for space
      delay( dotMillis * 7);                          // pause between words
    }
  }
  delay( 4000);                                       // delay before restarting the text
}


void flashMorseCode( char *morseCode) {               // read the morse elements for the character
  unsigned int i = 0;
  while( morseCode[i] != NULL){                       // as long as there are morse elements
    flashMorseElement( morseCode[i]);
    i++;
  }
  delay( dotMillis * 3);                              // pause between two letters
}

void flashMorseElement( char morseElement){
  digitalWrite( ledPin, HIGH);                        // turn LED on
  if ( morseElement == '.') delay( dotMillis);        // timing for a dot
  else delay( dotMillis * 3);                         // timing for a dash
  digitalWrite( ledPin, LOW);                         // turn LED off
  delay( dotMillis);                                  // pause between morse elements
}
