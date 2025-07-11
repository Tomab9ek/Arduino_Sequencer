#include "RelayControl.h"
#include <Arduino.h>

#define RELAY_RX 23
#define RELAY_LNA 24
#define RELAY_TX 22
#define RELAY_OPT 25
#ifndef RELAY_CONTROL_H
#define RELAY_CONTROL_H

void relayRXOn();
void relayRXOff();
void relayTXOn();
void relayTXOff();
void relayOptToggle();

#endif

void relayRXOn() {
  digitalWrite(RELAY_RX, HIGH);
  digitalWrite(RELAY_LNA, HIGH);
}

void relayRXOff() {
  digitalWrite(RELAY_RX, LOW);
  digitalWrite(RELAY_LNA, LOW);
}

void relayTXOn() {
  digitalWrite(RELAY_TX, HIGH);
}

void relayTXOff() {
  digitalWrite(RELAY_TX, LOW);
}

void relayOptToggle() {
  digitalWrite(RELAY_OPT, !digitalRead(RELAY_OPT));
}
