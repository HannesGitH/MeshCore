#pragma once

#include <MeshCore.h>
#include <Arduino.h>
#include <helpers/NRF52Board.h>

// RA-01SH (SX1262) wiring on nRF52 Pro Micro – old pinout
// (numbers after "//" are the Arduino pin index / nRF52 port-pin encoding)
#define P_LORA_NSS    8   // P1.04  (36)
#define P_LORA_MOSI   7   // P0.11  (11)
#define P_LORA_MISO   6   // P1.00  (32)
#define P_LORA_SCLK   5   // P0.24  (24)
#define P_LORA_BUSY   4   // P0.22  (22)
#define P_LORA_DIO_1  14  // P1.15  (47)
#define P_LORA_RESET  13  // P1.13  (45)

// RA-01SH has on-board TCXO and built-in RF switch controlled via DIO2.
// No PA enable / RXEN / TXEN lines are wired in this variant.
#define SX126X_RXEN               RADIOLIB_NC
#define SX126X_TXEN               RADIOLIB_NC
#define SX126X_DIO2_AS_RF_SWITCH  true
#define SX126X_DIO3_TCXO_VOLTAGE  (1.8f)

// Battery sense (same wiring as stock Pro Micro - optional external divider)
#define PIN_VBAT_READ     17
#define ADC_MULTIPLIER    (1.758f) // 1M:1M voltage divider, 3.6V ref, 12-bit ADC

class PromicroRA01SHOldBoard : public NRF52BoardDCDC {
protected:
  uint8_t btn_prev_state;
  float   adc_mult = ADC_MULTIPLIER;

public:
  PromicroRA01SHOldBoard() : NRF52Board("ProMicro_RA01SHOld_OTA") {}
  void begin();

  #define BATTERY_SAMPLES 8

  uint16_t getBattMilliVolts() override {
    analogReadResolution(12);

    uint32_t raw = 0;
    for (int i = 0; i < BATTERY_SAMPLES; i++) {
      raw += analogRead(PIN_VBAT_READ);
    }
    raw = raw / BATTERY_SAMPLES;
    return (adc_mult * raw);
  }

  bool setAdcMultiplier(float multiplier) override {
    if (multiplier == 0.0f) {
      adc_mult = ADC_MULTIPLIER;
    } else {
      adc_mult = multiplier;
    }
    return true;
  }

  float getAdcMultiplier() const override {
    if (adc_mult == 0.0f) {
      return ADC_MULTIPLIER;
    } else {
      return adc_mult;
    }
  }

  const char* getManufacturerName() const override {
    return "ProMicro DIY (RA-01SH old)";
  }

  int buttonStateChanged() {
    #ifdef BUTTON_PIN
      uint8_t v = digitalRead(BUTTON_PIN);
      if (v != btn_prev_state) {
        btn_prev_state = v;
        return (v == LOW) ? 1 : -1;
      }
    #endif
    return 0;
  }

  void powerOff() override {
    sd_power_system_off();
  }
};
