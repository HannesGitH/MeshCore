/*
 * variant.h
 * nRF52 Pro Micro + RA-01SH (SX1262) custom wiring
 */

#pragma once

#include "WVariant.h"

////////////////////////////////////////////////////////////////////////////////
// Low frequency clock source

#define VARIANT_MCK       (64000000ul)

//#define USE_LFXO      // 32.768 kHz crystal oscillator
#define USE_LFRC    // 32.768 kHz RC oscillator

////////////////////////////////////////////////////////////////////////////////
// Power

#define PIN_EXT_VCC          (21)
#define EXT_VCC              (PIN_EXT_VCC)

#define BATTERY_PIN          (17)
#define ADC_RESOLUTION       12

////////////////////////////////////////////////////////////////////////////////
// Number of pins

#define PINS_COUNT           (23)
#define NUM_DIGITAL_PINS     (23)
#define NUM_ANALOG_INPUTS    (3)
#define NUM_ANALOG_OUTPUTS   (0)

////////////////////////////////////////////////////////////////////////////////
// UART pin definition
// Serial1 is routed to the optional GPS:
//   MCU TX -> P0.09 (Arduino pin 10) -> GPS RX
//   MCU RX -> P0.10 (Arduino pin 11) -> GPS TX

#define PIN_SERIAL1_TX       (10)
#define PIN_SERIAL1_RX       (11)

////////////////////////////////////////////////////////////////////////////////
// I2C pin definition
// Pins 0 (P0.08) and 1 (P0.06) are free on this wiring. Users can override
// with -D PIN_BOARD_SDA / -D PIN_BOARD_SCL in platformio.ini if needed.

#define WIRE_INTERFACES_COUNT 2

#define PIN_WIRE_SDA         (0)
#define PIN_WIRE_SCL         (1)
#define PIN_WIRE1_SDA        (18)
#define PIN_WIRE1_SCL        (19)

////////////////////////////////////////////////////////////////////////////////
// SPI pin definition
// Primary SPI goes to RA-01SH:
//   SCK  -> P0.22 (Arduino pin 4)
//   MISO -> P0.24 (Arduino pin 5)
//   MOSI -> P1.00 (Arduino pin 6)
//   NSS  -> P0.11 (Arduino pin 7)

#define SPI_INTERFACES_COUNT 2

#define PIN_SPI_SCK          (4)
#define PIN_SPI_MISO         (5)
#define PIN_SPI_MOSI         (6)

#define PIN_SPI_NSS          (7)

#define PIN_SPI1_SCK         (20)
#define PIN_SPI1_MISO        (16)
#define PIN_SPI1_MOSI        (21)

////////////////////////////////////////////////////////////////////////////////
// Builtin LEDs

#define PIN_LED              (22)
#define LED_PIN              PIN_LED
#define LED_BLUE             PIN_LED
#define LED_BUILTIN          PIN_LED
#define LED_STATE_ON         1

////////////////////////////////////////////////////////////////////////////////
// Builtin buttons
// No dedicated user button is wired in this variant; pin 12 (P1.11) is exposed
// and can be repurposed. Override PIN_USER_BTN in platformio.ini to enable.

#define PIN_BUTTON1          (2)   // P0.17
#define BUTTON_PIN           PIN_BUTTON1
