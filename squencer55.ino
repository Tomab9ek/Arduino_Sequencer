#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>
#include <Arduino.h>

#include "Config.h"
#include "Display.h"
#include "Encoder.h"
#include "RelayControl.h"
#include "Sequence.h"
#include "Voltage.h"
#include "SerialCommands.h"

void setup() {
  pinMode(WRAP_LED, OUTPUT);
  digitalWrite(WRAP_LED, LOW);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("EME Relay Ctrl");

  pinMode(RELAY_TX, OUTPUT);
  pinMode(RELAY_RX, OUTPUT);
  pinMode(RELAY_LNA, OUTPUT);
  pinMode(RELAY_OPT, OUTPUT);

  pinMode(ENCODER_CLK, INPUT);
  pinMode(ENCODER_DT, INPUT);
  pinMode(ENCODER_SW, INPUT_PULLUP);

  EEPROM.get(rxAddr, rxDuration);
  EEPROM.get(txAddr, txDuration);
  if (rxDuration < 500 || rxDuration > 60000) rxDuration = 5000;
  if (txDuration < 500 || txDuration > 60000) txDuration = 3000;

  Serial.begin(9600);
}

void loop() {
  handleEncoderRotation();
  handleEncoderButton();
  updateLCD();
  checkSerialCommands();

  if (millis() - lastVoltageReport > 500) {
    float v = readVoltage();
    Serial.print("VOLT:");
    Serial.println(v, 1);
    lastVoltageReport = millis();
  }
}
