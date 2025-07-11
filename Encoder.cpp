#include "Encoder.h"
#include <Arduino.h>
#include "Config.h"
#include "Display.h"
#include "Sequence.h"
#include <EEPROM.h>
#include "Sequence.h"
#include <Arduino.h>        // Always include this for core functions like digitalRead
#include "Config.h"         // For mode, rxDuration, etc.
#include "Display.h"        // If lcd.clear() is used
#include "RelayControl.h"   // For relayOptToggle()
#include "Sequence.h"       // For runTXRXsequence() and pulseWrapLED()
#include <EEPROM.h>         // For EEPROM.put()

extern unsigned int rxDuration;
extern unsigned int txDuration;
extern int mode;
extern bool sequenceRunning;

void handleEncoderRotation() {
  static int lastCLK = HIGH;
  int currentCLK = digitalRead(ENCODER_CLK);

  if (currentCLK != lastCLK && currentCLK == HIGH) {
    if (digitalRead(ENCODER_DT) != currentCLK) mode++;
    else mode--;
    if (mode < 1) {
      mode = 4;
      pulseWrapLED();
    }
    if (mode > 4) {
      mode = 1;
      pulseWrapLED();
    }
    lcd.clear();
  }
  lastCLK = currentCLK;
}

void handleEncoderButton() {
  static bool prevState = HIGH;
  static unsigned long lastDebounceTime = 0;
  const unsigned long debounceDelay = 50;
static unsigned long pressStartTime = 0;
static bool longPressTriggered = false;
const unsigned long longPressThreshold = 2000;  // 2 seconds

  bool currentState = digitalRead(ENCODER_SW);
  if (currentState != prevState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (prevState == HIGH && currentState == LOW) {
      switch (mode) {
        case 1:
          relayOptToggle();
          break;
        case 2:
          if (!sequenceRunning) runTXRXsequence();
          break;
        case 3:
          rxDuration += 1000;
          if (rxDuration > 60000) rxDuration = 60000;
          EEPROM.put(rxAddr, rxDuration);
          break;
        case 4:
          txDuration += 1000;
          if (txDuration > 60000) txDuration = 60000;
          EEPROM.put(txAddr, txDuration);
          break;
      }
    }
  }
  prevState = currentState;
}
