#include "BuzzerFunctions.h"

const int buzzerPin = 12; 

void playPhoneRing() {
  tone(buzzerPin, 1000, 150);  //  1000 Hz for 150ms
  delay(200);
  tone(buzzerPin, 1200, 150);  //  1200 Hz for 150ms
  delay(200);
  tone(buzzerPin, 1000, 150);  //  1000 Hz again for 150ms
  delay(300);
}