#include "Voltage.h"
#include <Arduino.h>
#include "Config.h"  // For R1, R2, VOLTAGE_PIN

float readVoltage() {
  int raw = analogRead(VOLTAGE_PIN);
  float v = (raw / 1023.0) * 5.0;
  return v * ((R1 + R2) / R2);
}
