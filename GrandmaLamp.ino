//Connect a switch between pin 1 and ground and pin 2 and ground. 
//If connection between 1 and ground, then it'll make a white lamp. 
//If connection between 2 and ground, it'll make a rainbow
//If no connection, it'll be off

#include <Adafruit_CircuitPlayground.h>
#include <Wire.h>
#include <SPI.h>
#define SWITCHA 1
#define SWITCHB 2

// we light one pixel at a time, this is our counter
uint8_t pixeln = 0;
boolean docolor = true;
boolean dowhite = false;


void setup() {
  //while (!Serial);
  Serial.begin(9600);
  Serial.println("Circuit Playground test!");
  CircuitPlayground.begin();
  pinMode(SWITCHA, INPUT_PULLUP);
  pinMode(SWITCHB, INPUT_PULLUP);

}


void loop() {
  // test Red #13 LED
 // CircuitPlayground.redLED(HIGH);
  delay(400);
  //CircuitPlayground.redLED(LOW);
  /************* TEST CAPTOUCH */
  /*Serial.print("Capsense #3: "); Serial.println(CircuitPlayground.readCap(3));
  Serial.print("Capsense #2: "); Serial.println(CircuitPlayground.readCap(2));
  Serial.print("Capsense #0: "); Serial.println(CircuitPlayground.readCap(0));
  Serial.print("Capsense #1: "); Serial.println(CircuitPlayground.readCap(1));
  Serial.print("Capsense #12: "); Serial.println(CircuitPlayground.readCap(12));
  Serial.print("Capsense #6: "); Serial.println(CircuitPlayground.readCap(6));
  Serial.print("Capsense #9: "); Serial.println(CircuitPlayground.readCap(9));
 Serial.print("Capsense #10: "); Serial.println(CircuitPlayground.readCap(10));*/
  
  /************* TEST SLIDE SWITCH */
 /* if (CircuitPlayground.slideSwitch()) {
    Serial.println("Slide to the left");
  } else {
    Serial.println("Slide to the right");
    CircuitPlayground.playTone(500 + pixeln * 500, 250);
  }
*/
  /************* TEST 10 NEOPIXELS */
  if (docolor) {
    CircuitPlayground.setPixelColor(pixeln++, CircuitPlayground.colorWheel(25 * pixeln));
    if(pixeln >3) {
      CircuitPlayground.setPixelColor(pixeln-4, 0, 0, 0);
    }
    if(pixeln == 2) {
       CircuitPlayground.setPixelColor(8, 0, 0, 0); 
    }
     if(pixeln == 3) {
       CircuitPlayground.setPixelColor(9, 0, 0, 0);
     
    }
    
    if (pixeln >= 11) {
     pixeln = 0;
   //   CircuitPlayground.clearPixels();
    }
  } 
 if(dowhite) {
      CircuitPlayground.setPixelColor(pixeln++, 255, 255, 255);
     if (pixeln >= 11) {
      pixeln = 0;
     }
  }
  /************* TEST BOTH BUTTONS */
  if (CircuitPlayground.leftButton() | digitalRead(SWITCHB)==LOW) {
    docolor = true;
    dowhite = false;
    //CircuitPlayground.clearPixels();
    //pixeln = 0;
  }
  if (CircuitPlayground.rightButton() | digitalRead(SWITCHA)==LOW) {
    docolor = false;
    dowhite = true;
   // pixeln = 0;

  }
  if (digitalRead(SWITCHB)==HIGH && digitalRead(SWITCHA)==HIGH) {
    CircuitPlayground.clearPixels();
    pixeln = 0;
    docolor = false;
    dowhite = false;
  }

 
}
