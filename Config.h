#ifndef CONFIG_H
#define CONFIG_H

#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>

// --- Relay Pins ---
#define RELAY_TX   22
#define RELAY_RX   23
#define RELAY_LNA  24
#define RELAY_OPT  25

// --- Encoder Pins ---
#define ENCODER_CLK 2
#define ENCODER_DT  3
#define ENCODER_SW  4

// --- LED & Voltage ---
#define WRAP_LED    13
#define VOLTAGE_PIN A0
//const float R1 = 33000.0;
//const float R2 = 6800.0;
extern const float R1;
extern const float R2;

// --- EEPROM Addresses ---
extern const int rxAddr;
extern const int txAddr;

// --- Globals ---
extern unsigned int rxDuration;
extern unsigned int txDuration;
extern int mode;
extern bool sequenceRunning;
extern unsigned long lastVoltageReport;

// --- Shared LCD Instance ---
extern LiquidCrystal_I2C lcd;

#endif
