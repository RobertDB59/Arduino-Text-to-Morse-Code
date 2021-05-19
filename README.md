# Arduino-Text-to-Morse-Code

Morse Code Taillight Project version 2

This code will loop through a string of characters and convert these
to morse code. It will make a led taillight blink.

Flashing taillights stand out more than steady state lights.

The taillight is a 3W red LED. 
Any text can be converted to morse code within the limits of the Arduino used. 
In my case I used an ATtiny85. 
Pin 8 to 5V pin 4 to GND and pin 6 to a 330 ohm resistor that is connected to the base of an 2N2222. 
The + of the LED is connected to a 12V rail and the - LED to the collector of the 2N2222. 
The emiter is connected to GND. 

Youtube video can be found here:
https://youtu.be/ttICuJwOsLM
