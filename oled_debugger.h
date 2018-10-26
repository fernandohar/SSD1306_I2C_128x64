#ifndef OLED_DEBUGGER_H
#define OLED_DEBUGGER_H

#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"

class OledDebugger {
public:
  OledDebugger();
  OledDebugger(HardwareSerial *hsDebug);
  OledDebugger(SSD1306AsciiWire *oled);
  ~OledDebugger();
  bool setDebug(bool debug);
  void debugPrint(const char* message);
  void debugPrintln(const char* message);
  void print(const char* message);
  void println(const char* message);

private:
  HardwareSerial *_dbg;
  SSD1306AsciiWire *_oled;
  bool _enableDebug;

  void initObject(HardwareSerial *hsDebug, SSD1306AsciiWire *oled);
};
#endif
