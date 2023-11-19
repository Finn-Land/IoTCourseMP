#include <M5StickCPlus.h>
unsigned long previous_time = 0;
int period = 2000;
int color[] = {
  0xfd79, 0xe8e4, 0xfbe4, 0xff80, 0x2589, 0x51d, 0x3a59, 0xa254, 0x7bef, 0xffff
};

void setup() {
  // Initialize the M5StickCPlus object. Initialize the M5StickCPlus object
  M5.begin();
  M5.Lcd.setRotation(1);
}

void loop() {
  int a = random(0, 9);
  if (millis() - previous_time >= period) {
    previous_time = millis();
    M5.Lcd.fillScreen(color[a]);
    M5.Lcd.setTextSize(2.5);
    M5.Lcd.drawString("Incoming Call", M5.Lcd.width()/6, M5.Lcd.height()/3, 2);
  }
}
