#include <Arduino.h>
#include <Wire.h>

#include "PromicroRA01SHBoard.h"

void PromicroRA01SHBoard::begin() {
  NRF52Board::begin();
  btn_prev_state = HIGH;

  pinMode(PIN_EXT_VCC, OUTPUT);
  digitalWrite(PIN_EXT_VCC, HIGH);

  pinMode(PIN_VBAT_READ, INPUT);

  #ifdef BUTTON_PIN
    pinMode(BUTTON_PIN, INPUT_PULLUP);
  #endif

  #if defined(PIN_BOARD_SDA) && defined(PIN_BOARD_SCL)
    Wire.setPins(PIN_BOARD_SDA, PIN_BOARD_SCL);
  #endif

  Wire.begin();

  #ifdef PIN_GPS_EN
    pinMode(PIN_GPS_EN, OUTPUT);
    digitalWrite(PIN_GPS_EN, HIGH);   // power the GPS module (if present)
  #endif
}
