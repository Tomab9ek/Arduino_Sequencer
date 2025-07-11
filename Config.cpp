#include "Config.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int rxAddr = 0;
const int txAddr = sizeof(unsigned int);
unsigned int rxDuration = 5000;
unsigned int txDuration = 3000;
const float R1 = 33000.0;
const float R2 = 6800.0;

int mode = 1;
bool sequenceRunning = false;
unsigned long lastVoltageReport = 0;
