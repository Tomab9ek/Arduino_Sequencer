#include "Sequence.h"
#include "RelayControl.h"
#include "Display.h"
#include "Voltage.h"
#include "Config.h"
#include <Arduino.h>

void runTXRXsequence() {
  sequenceRunning = true;
  lcd.clear();

  relayRXOn();
  for (int i = rxDuration / 1000; i > 0; i--) {
    lcd.setCursor(0, 0);
    lcd.print("RX Phase Active  ");
    lcd.setCursor(0, 1);
    lcd.print("RX: ");
    lcd.print(i);
    lcd.print("s ");
    lcd.print(readVoltage(), 1);
    lcd.print("V");
    delay(1000);
  }

  relayRXOff();
  delay(200);
  relayTXOn();
  for (int i = txDuration / 1000; i > 0; i--) {
    lcd.setCursor(0, 0);
    lcd.print("TX Phase Active  ");
    lcd.setCursor(0, 1);
    lcd.print("TX: ");
    lcd.print(i);
    lcd.print("s ");
    lcd.print(readVoltage(), 1);
    lcd.print("V");
    delay(1000);
  }

  relayTXOff();
  lcd.setCursor(0, 0);
  lcd.print("Cycle Complete   ");
  lcd.setCursor(0, 1);
  lcd.print("Ready for next   ");
  sequenceRunning = false;
  Serial.println("SEQUENCE_DONE");
  pulseWrapLED();
}

void pulseWrapLED() {
  int totalDuration = rxDuration + txDuration;
  int blinkTime = constrain(totalDuration / 100, 100, 500);
  digitalWrite(WRAP_LED, HIGH);
  delay(blinkTime);
  digitalWrite(WRAP_LED, LOW);
}
