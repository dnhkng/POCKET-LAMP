#include "Adafruit_TCS34725.h"
 
#define UV_pin 16
  
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_16X);
 
void setup() {
  Serial.begin(115200);
  Serial.println("UV sample Test");
 
  if (tcs.begin()) {
    Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1); // halt!
  }
  
  // use this pins to drive the UV LED
  pinMode(UV_pin, OUTPUT);
 
}
 

int timer = 0;
uint16_t clear, red, green, blue;
void loop() {
  

  timer = timer + 1;
  Serial.print("Time: "); Serial.println(timer);;
  
  digitalWrite(UV_pin, HIGH);
  delay(100);  
  tcs.getRawData(&red, &green, &blue, &clear);
  Serial.print("UV On\t");
  Serial.print("C:\t"); Serial.print(clear);
  Serial.print("\tR:\t"); Serial.print(red);
  Serial.print("\tG:\t"); Serial.print(green);
  Serial.print("\tB:\t"); Serial.print(blue);
  Serial.println();
  
  digitalWrite(UV_pin, LOW);
  delay(100);  
  tcs.getRawData(&red, &green, &blue, &clear);
  Serial.print("UV Off\t");
  Serial.print("C:\t"); Serial.print(clear);
  Serial.print("\tR:\t"); Serial.print(red);
  Serial.print("\tG:\t"); Serial.print(green);
  Serial.print("\tB:\t"); Serial.print(blue);
  Serial.println();
  Serial.println();
  delay(800);  

}
