#include "arduino_secrets.h"
/* 
  Sketch generated by the Arduino IoT Cloud Thing "Runoff"
  https://create.arduino.cc/cloud/things/35345192-52ae-433c-ba24-4155d0313c85 

  Arduino IoT Cloud Properties description

  The following variables are automatically generated and updated when changes are made to the Thing properties

  float distance;
  float temp;
  float volume;

  Properties which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/
//rilay trigger at specific time https://www.viralsciencecreativity.com/post/arduino-relay-trigger-at-specific-time-ds3231-rtc-module
//DS3231 examples https://github.com/NorthernWidget/DS3231/blob/master/examples/now/now.pde
 // Loggerhttps://howtomechatronics.com/tutorials/arduino/arduino-sd-card-data-logging-excel-tutorial/ 
//https://www.youtube.com/watch?v=ioSYlxHlYdI rilay
//https://bc-robotics.com/tutorials/controlling-a-solenoid-valve-with-arduino/ selenoid valve
#include <Wire.h>
#include <DS3231.h>
#include <SD.h>
#include <SPI.h>
RTClib myRTC;
File myFile1;
#include "thingProperties.h"

int pinCS = 7;//7 in mkr1010
const int OnHour = 15; //SET TIME TO ON RELAY (24 HOUR FORMAT)
const int OnMin = 0;
const int OffHour = 15; //SET TIME TO OFF RELAY
const int OffMin = 6;
const float OffVol = 8.00;

const int buttonPin = 2;     // the number of the pushbutton pin
int Relay = 1;//valve
int echoPin = 4;
int trigPin = 5;
//const int temperaturePin = 0;
float distance;
float temp;
float volume;
int buttonState = 0;


void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
    Wire.begin();
    delay(500);
    Serial.println("Nano Ready!");
     delay(1500); 
   pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
     pinMode(Relay, OUTPUT);
      pinMode(buttonPin, INPUT);

  Serial.println("HC-SR04 Test");
    pinMode(pinCS, OUTPUT);

if (SD.begin(5))
 {
    Serial.println("SD card is ready to use.");
  } else
  {
    Serial.println("SD card initialization failed");
//    return;
  }
  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();

}

void loop() {
  buttonState = digitalRead(buttonPin);

float voltage, degreesC;
 
//    voltage = getVoltage(temperaturePin);
//   degreesC = (voltage - 0.5) * 100.0;
//   temp = degreesC;
      
//  Serial.print("Temperature: ");
//  Serial.print(degreesC);
//  Serial.println(" degrees C");
//   delay(3600);
   float duration, distance1, volume1;


 DateTime now = myRTC.now();
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(' ');
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();

digitalWrite(trigPin, LOW);
  delay(2);
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance1 = duration * 0.034 / 2.00;
    distance = distance1;
    volume1 = (44.45 - distance1) * 410.43 / 1000.00;
    volume = volume1;
    
     Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
   Serial.print("Volume: ");
  Serial.print(volume1, 2);
  Serial.println(" lt");
  Serial.println(" ");
//  delay(3600000);
  
  

    
//    delay(3600000);
    

//  if(now.hour() == OnHour && now.minute() == OnMin  && volume1 > 10){

////////////////////////////////////////////////////
  if(now.hour() == OnHour && now.minute() > OnMin && now.minute() < OffMin && volume1 > OffVol ){

    digitalWrite(Relay,HIGH);
    Serial.println("VALVE OPEN");
    }
    
//    else if(now.hour() == OffHour && now.minute() == OffMin && volume1 < 5){
          else if(now.hour() == OffHour && now.minute() > OffMin ){

      
      digitalWrite(Relay,LOW);
      Serial.println("VALVE CLOSE");
    }
//    //////////////////////////////////////////////////


    //  delay(3000);///addedddddd


myFile1 = SD.open("logg.txt", FILE_WRITE);
  if (myFile1) {    
    myFile1.print("Date: ");
    myFile1.print(now.year());
    myFile1.print("/");
    myFile1.print(now.month());
    myFile1.print("/");
    myFile1.print(now.day());
    myFile1.print(",");
    myFile1.print(" Time: ");
    myFile1.print(now.hour());
    myFile1.print(":");
    myFile1.print(now.minute());
    myFile1.print(". Vol:");    
    myFile1.print(float(volume1));
    myFile1.println(" l.");    
    myFile1.close(); // close the file
  }
  // if the file didn't open, print an error:
  else {
    Serial.println("error opening logg.txt");
  }
//  delay(900000);

 
 delay(3000);


  ArduinoCloud.update(); 

  
}
float getVoltage(int pin)
{  return (analogRead(pin) * 0.003222);}
