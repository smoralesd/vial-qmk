#pragma once

#include "quantum.h"

#define LAYOUT_3x5_3(\
  L00, L01, L02, L03, L04,                          R00, R01, R02, R03, R04, \
  L10, L11, L12, L13, L14,                          R10, R11, R12, R13, R14, \
  L20, L21, L22, L23, L24,                          R20, R21, R22, R23, R24, \
            L32, L33, L34,                          R30, R31, R32            \
  ) \
  { \
    { L00,   L01,   L02, L03, L04 }, \
    { L10,   L11,   L12, L13, L14 }, \
    { L20,   L21,   L22, L23, L24 }, \
    { KC_NO, KC_NO, L32, L33, L34 }, \
                                          \
    { R00, R01, R02, R03,   R04   }, \
    { R10, R11, R12, R13,   R14   }, \
    { R20, R21, R22, R23,   R24   }, \
    { R30, R31, R32, KC_NO, KC_NO }, \
}
