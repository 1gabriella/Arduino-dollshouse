#include "OLEDAnimations.h"
#include "SensorFunctions.h"
#include "BuzzerFunctions.h"  
#include "OLED_Driver.h"
#include "GUI_Paint.h"
#include "DEV_Config.h"
#include "Debug.h"

// Timing variables
unsigned long lastDisplayUpdate = 0;
const unsigned long displayInterval = 2000;  
unsigned long lastSensorPrint = 0;
const unsigned long sensorPrintInterval = 1000;  


UBYTE *BlackImage = NULL;

// Animation state and positions for animation
int animationState = 0;
int positions[][2] = {
  {OLED_1in5_RGB_WIDTH / 4,         OLED_1in5_RGB_HEIGHT / 4},
  {OLED_1in5_RGB_WIDTH * 3 / 4,     OLED_1in5_RGB_HEIGHT / 4},
  {OLED_1in5_RGB_WIDTH * 3 / 4,     OLED_1in5_RGB_HEIGHT * 3 / 4},
  {OLED_1in5_RGB_WIDTH / 4,         OLED_1in5_RGB_HEIGHT * 3 / 4},
  {OLED_1in5_RGB_WIDTH / 2,         OLED_1in5_RGB_HEIGHT / 2}
};
const int numPositions = sizeof(positions) / sizeof(positions[0]);

// Pin definitions
const int ledPin = 13;          
const float sensorThreshold = 20.0;  // Distance threshold (cm)

void setup() {
  System_Init();
  if (USE_IIC) {
    Serial.print("Only USE_SPI_4W, Please revise DEV_Config.h !!!");
    return;
  }
  
  Serial.begin(9600);
  OLED_1in5_rgb_Init();
  delay(5);
  OLED_1in5_rgb_Clear();
  
  // Allocate the image buffer for the OLED
  Paint_NewImage(BlackImage, OLED_1in5_RGB_WIDTH, OLED_1in5_RGB_HEIGHT, 270, BLACK);
  Paint_SetScale(65);
  
  // Initialize sensor pins and buzzer pin:

  pinMode(9, OUTPUT);  // trigPin
  pinMode(4, INPUT);   // echoPin
  
  // Initialize buzzer pin 
  pinMode(12, OUTPUT);
  

  pinMode(ledPin, OUTPUT);
  
  // where my phone message 
  Paint_Clear(BlackImage);
  Paint_DrawString_EN(0, 50, "where's my phone!", &Font16, PINK, BLACK);
  OLED_1in5_rgb_Display(BlackImage);
  delay(3000);
}

void loop() {
  unsigned long currentMillis = millis();
  
  // Read sensor distance
  float distance = readDistance();
  
  
  if (distance > 0 && distance < sensorThreshold) {
    digitalWrite(ledPin, HIGH);
    playPhoneRing();  // Call the phone ring 
  } else {
    digitalWrite(ledPin, LOW);
  }
  
  // Update the OLED display every displayInterval
  if (currentMillis - lastDisplayUpdate >= displayInterval) {
    lastDisplayUpdate = currentMillis;
    char buf[20];
    sprintf(buf, "Dist: %.1f cm", distance);
    updateDisplay(BlackImage, animationState, positions, numPositions, buf);
  }
  
  // Print sensor reading to Serial Monitor 
  if (currentMillis - lastSensorPrint >= sensorPrintInterval) {
    lastSensorPrint = currentMillis;
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  }
}
