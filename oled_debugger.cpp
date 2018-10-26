#include "oled_debugger.h"
OledDebugger::OledDebugger(){
  initObject(NULL, NULL);
}
OledDebugger::OledDebugger(HardwareSerial *hsDebug){
  initObject(hsDebug, NULL);
}
OledDebugger::OledDebugger(SSD1306AsciiWire *oled){
  initObject(NULL, oled);
}


void OledDebugger::initObject(HardwareSerial *hsDebug, SSD1306AsciiWire *oled) {
  _dbg = hsDebug;
   _oled = oled;
  _enableDebug = (_dbg != NULL || _oled != NULL);
}

OledDebugger::~OledDebugger(){
  _dbg = NULL;
  _oled = NULL;
}

bool OledDebugger::setDebug(bool debug){
  if(_dbg == NULL) return false;
  _enableDebug = debug;
  return _enableDebug;
}

void OledDebugger::debugPrintln(const char *message){
  debugPrint(message);
  debugPrint("\n");
}
void OledDebugger::debugPrint(const char *message){
  if(!_enableDebug) return;
  print(message);
}

void OledDebugger::println(const char *message){
  print(message);
  println("\n");
}
void OledDebugger::print(const char *message){
   if(_oled != NULL){
    _oled->print(message);
  }else if (_dbg != NULL){
    _dbg->print(message);
  }
}
