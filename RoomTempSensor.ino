// Code by Yuvi Gill
// Arduino Room TEMP Sensor Code

// LCD Display Library
#include <LiquidCrystal.h>

// Temperature & Humidity Sensor Library
#include <DHT.h>
#include <DHT_U.h>
#include "DHT.h"

// Defining DHT Data Pin
#define DHTPIN A0

// Defining DHT Sensor Type
#define DHTTYPE DHT11

// Setting up LCD display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Setting up DHT sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);

  // Setting Up LED output
  for (int DigitalPin = 7; DigitalPin <=8; DigitalPin++){
    pinMode(DigitalPin, OUTPUT);
  }

  // Setting LCD Display up as a 16X2 Charachter Display
  lcd.begin(16,2);

  // Setting DHT up
  dht.begin();

}

void loop() {
  // Initial Temperature & Humidity Input takes 250 milliseconds
  delay(1000);

  // Initialize values for humidity and temperature
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  //LCD initiation
  lcd.clear();
  lcd.setCursor(0,0);

  // Printing Temperature
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print("'C");

  // Setting next line
  lcd.setCursor(0,1);

  // Printing Humidity
  lcd.print("Humid: ");
  lcd.print(h);
  lcd.print("%");

  // Initialising values for low and high LED output cutoffs.
  float low = 16;
  float high = 22;
  
  //LED light setup
  if (t <= low){
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
  }
  else if (t > low && t < high){
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
  }
  else if (t >= high ){
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
  }

}
