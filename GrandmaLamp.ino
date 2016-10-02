// Demo program for testing library and board - flip the switch to turn on/off buzzer

#include <Adafruit_CircuitPlayground.h>
#include <Wire.h>
#include <SPI.h>

// we light one pixel at a time, this is our counter
uint8_t pixeln = 0;
boolean docolor = true;

void setup() {
  //while (!Serial);
  Serial.begin(9600);
  Serial.println("Circuit Playground test!");

  CircuitPlayground.begin();
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
    
    if (pixeln == 11) {
     pixeln = 0;
   //   CircuitPlayground.clearPixels();
    }
  } else {
      CircuitPlayground.setPixelColor(pixeln++, 255, 255, 255);
     if (pixeln == 11) {
      pixeln = 0;
     }
  }
  /************* TEST BOTH BUTTONS */
  if (CircuitPlayground.leftButton()) {
    docolor = true;
    //CircuitPlayground.clearPixels();
    pixeln = 0;
  }
  if (CircuitPlayground.rightButton()) {
    docolor = false;
    pixeln = 0;

  }

  /************* TEST LIGHT SENSOR */
  Serial.print("Light sensor: ");
  Serial.println(CircuitPlayground.lightSensor());

  /************* TEST SOUND SENSOR */
  Serial.print("Sound sensor: ");
  Serial.println(CircuitPlayground.soundSensor());

  /************* TEST ACCEL */
  // Display the results (acceleration is measured in m/s*s)
  Serial.print("X: "); Serial.print(CircuitPlayground.motionX());
  Serial.print(" \tY: "); Serial.print(CircuitPlayground.motionY());
  Serial.print(" \tZ: "); Serial.print(CircuitPlayground.motionZ());
  Serial.println(" m/s^2");

  /************* TEST THERMISTOR */
  Serial.print("Temperature ");
  Serial.print(CircuitPlayground.temperature());
  Serial.println(" *C");
}
