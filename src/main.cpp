#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Servo.h>
#include "CoatingProcesses.h"
#include "Stage.h"

const int ESC_PWM_PIN = 9, LCD_RS_PIN = 12, LCD_ENABLE_PIN = 11, LCD_D4_PIN = 5, LCD_D5_PIN = 4, LCD_D6_PIN = 3, LCD_D7_PIN = 2;

Stage _stage;                                                                                   // Stage of program
CoatingProcess _coatingProcess;                                                                 // Stage of coating process
Servo _ESC;                                                                                     // Object for Electronic Servo Controller (ESC)
LiquidCrystal _LCD(LCD_RS_PIN, LCD_ENABLE_PIN, LCD_D4_PIN, LCD_D5_PIN, LCD_D6_PIN, LCD_D7_PIN); // Object for Liquid Crystal Display (LCD)

unsigned int _potentiometerValue;

// put function declarations here:
int myFunction(int, int);

void setup()
{
  // put your setup code here, to run once:
  _coatingProcess = PLACE;
  _stage = Stage::STARTING;
  _ESC.attach(ESC_PWM_PIN);
  _LCD.begin(16, 2);
  pinMode(A0, INPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
}

boolean hasPotentiometerValueChanged() {
  unsigned int actualValue = analogRead(A0);
  if(_potentiometerValue != actualValue) {
    _potentiometerValue = actualValue;
    return true;
  }
  return false;
}

// put function definitions here:
int myFunction(int x, int y)
{
  return x + y;
}

void displayLoop()
{
  static unsigned long timestamp;
  if(timestamp > millis()) return;

  _LCD.home();
}

void movementLoop()
{
}
