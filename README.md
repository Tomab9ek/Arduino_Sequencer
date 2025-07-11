                          +-------------------------+
                          |      Arduino Uno/Nano   |
                          |                         |
                          |  Pin 2  → Encoder CLK ←─┬────┐
                          |  Pin 3  → Encoder DT  ←─┘    │
                          |                             10kΩ Pull-ups
                          |  Pin 4  → Encoder SW       → Vcc
                          |  A0     → Voltage Divider ←─┐
                          |                             ├── R1
                          |                             └── R2 → GND
                          |  SDA (A4) → LCD I²C SDA
                          |  SCL (A5) → LCD I²C SCL
                          |  Pin 13 → Wrap LED (via 330Ω → GND)
                          |  Pin 22 → TX Relay IN
                          |  Pin 23 → RX Relay IN
                          |  Pin 24 → LNA Relay IN
                          |  Pin 25 → R4 Relay IN (optional)
                          +-------------------------+

Relay Modules:
  Vcc and GND to external 5V supply
  INx pins connected to Arduino digital pins

Signal Flow:
  • RX Phase: RX Relay + LNA Relay activated
  • Short delay
  • TX Phase: TX Relay activated (RX + LNA deactivated)
  • Wrap LED pulses on completion

LCD Display:
  - Line 1: Phase status ("RX Phase Active", "TX Phase Active")
  - Line 2: Countdown timer + Voltage readout (e.g., "RX: 3s 13.2V")
