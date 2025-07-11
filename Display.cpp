#include "Display.h"
#include <LiquidCrystal_I2C.h>
#include "Voltage.h"
#include "Config.h"       // Contains shared variables like rxDuration, txDuration, mode
#include "RelayControl.h" // If display shows relay states
#include <Arduino.h>

extern LiquidCrystal_I2C lcd;

void updateLCD() {
  float vin = readVoltage();
  switch (mode) {
    case 1: lcdMode1(vin); break;
    case 2: lcdMode2(); break;
    case 3: lcdMode3(vin); break;
    case 4: lcdMode4(vin); break;
  }
}

void lcdMode1(float vin) {
  lcd.setCursor(0, 0);
  lcd.print("Manual R4 Toggle ");
  lcd.setCursor(0, 1);
  lcd.print("R4: ");
  lcd.print(digitalRead(RELAY_OPT) ? "ON " : "OFF");
  lcd.print(" ");
  lcd.print(vin, 1);
  lcd.print("V");
}

void lcdMode2() {
  lcd.setCursor(0, 0);
  lcd.print("TX/RX Sequence   ");
  lcd.setCursor(0, 1);
  lcd.print("Press ▶ to Start ");
}

void lcdMode3(float vin) {
  lcd.setCursor(0, 0);
  lcd.print("Edit RX Duration ");
  lcd.setCursor(0, 1);
  lcd.print("RX: ");
  lcd.print(rxDuration / 1000);
  lcd.print("s ");
  lcd.print(vin, 1);
  lcd.print("V");
}

void lcdMode4(float vin) {
  lcd.setCursor(0, 0);
  lcd.print("Edit TX Duration ");
  lcd.setCursor(0, 1);
  lcd.print("TX: ");
  lcd.print(txDuration / 1000);
  lcd.print("s ");
  lcd.print(vin, 1);
  lcd.print("V");
}
