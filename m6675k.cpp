#include "m6675k.h"
#include "Arduino.h"
#define CS 13
#define MISO 12
#define CLK 10

float seeFahrenheit(){
    float fahrenheit = seeCelc() *1.8+32;
    return fahrenheit;
}

float seeKelvin(){
    float kelvin = seeCelc() +273.15;
    return kelvin;
}

float seeCelc(){
  
    digitalWrite(chip_select, LOW);
    delay(10);
    float amb_temp;
    float decimal=0;
    int data_incoming[16]; 
    for(int j=15;j>=0;j--){
    digitalWrite(serial_clock,LOW);
    digitalWrite(serial_clock,HIGH);
    data_incoming[j] = digitalRead(miso);
   }
    Serial.println(" ");
  digitalWrite(chip_select,HIGH);
  delay(1000);
   for(int i=3;i<14;i++){
      decimal += data_incoming[i]* pow(2,i-3);
  }
    amb_temp = decimal/4.00097680098;
   return amb_temp;
}
