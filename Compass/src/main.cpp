#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Drive/Drive.h>
#include <Compass/Compass.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64 
#define OLED_RESET     4 

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
Drive drive = Drive();
Compass compass = Compass(34);

#define  LED 22

int value;


void setup() {
  drive.AFMS.begin();
  drive.StartAllMotors();
  // put your setup code here, to run once:
  Serial.begin(9600);
  

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) 
  {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  pinMode(LED,OUTPUT);
  digitalWrite(LED,HIGH);
  
}



void loop() 
{
  value = compass.GetValue();

  int motorSpeed = map(abs(value),0,180,32,210);
  

  if(value < 0)
  {
    drive.RotateClockwise(motorSpeed);
  }
  else if(value > 0)
  {
    drive.RotateCounterClockwise(motorSpeed);
  }
  else
  {
    drive.Stop();
  }
  
  

  Serial.println(value);

  display.setCursor(0,0);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println(value);

  display.display();
  display.clearDisplay();
}



