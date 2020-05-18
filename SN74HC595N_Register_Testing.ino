//Program that uses 2 Texas Instruments SN74HC595N 8 bit shift registers and utilizes them to control 16 LED's



// Globals
const int dataPin = 12;  
const int latchPin = 10; 
const int clockPin = 11;

 
void setup() {
  // initialize I/O pins
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() {
int steps;
  // generate characters to display for hexidecimal numbers 0 to F
  for (steps = 0; steps <= 9; steps++) {
   
  digitalWrite(latchPin, LOW);  // prepare shift register for data
  shiftOut(dataPin, clockPin, LSBFIRST, myfnNumToBits(steps)); // send data  
shiftOut(dataPin, clockPin, LSBFIRST, myfnNumToBits(steps-1)); // send data  


  digitalWrite(latchPin, HIGH); // update display    // display alphanumeric digit
    delay(500);                 // pause for 1/2 second
  }
}



byte myfnNumToBits(int someNumber) {

  
  switch (someNumber) {
    case 0:
      return B10000000;
      break;
    case 1:
      return B11000000;
      break;
    case 2:
      return B11100000;
      break;
    case 3:
      return B11110000;
      break;
    case 4:
      return B11111000;
      break;
    case 5:
      return B11111100;
      break;
    case 6:
      return B11111110;
      break;
    case 7:
      return B11111111;
      break;
    case 8:
      return B00000000;
      break;
    case 9:
      return B11111111;
      break;
  }
}

void shift
