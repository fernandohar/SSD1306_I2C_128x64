// Simple I2C test for ebay 128x64 oled.

#include <Wire.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"

#include "oled_debugger.h"
// 0X3C+SA0 - 0x3C or 0x3D
#define I2C_ADDRESS 0x3C

// Define proper RST_PIN if required.
#define RST_PIN -1

SSD1306AsciiWire oled;
//OledDebugger debugger(&Serial); //Print to Serial 
OledDebugger debugger(&oled); //Print to OLED


//------------------------------------------------------------------------------
void setup() {
  Wire.begin();
  Wire.setClock(400000L);
  
#if RST_PIN >= 0
  oled.begin(&Adafruit128x64, I2C_ADDRESS, RST_PIN);
#else // RST_PIN >= 0
  oled.begin(&Adafruit128x64, I2C_ADDRESS);
#endif // RST_PIN >= 0
  Serial.begin(9600);
  
  oled.setFont(SystemFont5x7);
  debugger.debugPrint("testing");
  debugger.debugPrintln("testing");
  debugger.debugPrint("testing");
}
//------------------------------------------------------------------------------
void loop() {}
