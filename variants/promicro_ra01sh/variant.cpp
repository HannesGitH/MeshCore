#include "variant.h"
#include "wiring_constants.h"
#include "wiring_digital.h"

// Arduino pin index -> nRF52840 port-pin encoding (P0.x = x, P1.x = 32 + x)
// The map matches the standard nRF52 Pro Micro pinout; this variant just
// assigns different Arduino pins to LoRa / GPS roles via variant.h defines.
const uint32_t g_ADigitalPinMap[] = {
  8,  6,  17, 20, 22, 24, 32, 11, 36, 38,
  9,  10, 43, 45, 47, 2,  29, 31,
  33, 34, 37,
  13, 15
};

void initVariant()
{
}
