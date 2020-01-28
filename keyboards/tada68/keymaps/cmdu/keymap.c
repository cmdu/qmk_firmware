#include "quantum.h"
#include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define _BL 0
#define _FL 1

#define _______ KC_TRNS

#define M_BACKL             M(MACRO_BACKLIGHT)
#define M_BRTOG             M(MACRO_BREATH_TOGGLE)
#define M_BSPDU             M(MACRO_BREATH_SPEED_INC)
#define M_BSPDD             M(MACRO_BREATH_SPEED_DEC)
#define M_BDFLT             M(MACRO_BREATH_DEFAULT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Keymap _BL: (Base Layer) Default Layer
   * ,----------------------------------------------------------------.
   * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |Del |
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Slp |
   * |----------------------------------------------------------------|
   * |MT-LCtrl-Esc| A| S| D|  F|  G|  H|  J|  K|  L|  ;| '|Return|Mute|
   * |----------------------------------------------------------------|
   * |LS-PO   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|RS-PC  |BUp| V+|
   * |----------------------------------------------------------------|
   * |Hyper|Alt|Cmd|           Space           |Alt|FN|RWD|FFW|BDn| V-|
   * `----------------------------------------------------------------'
   */

[_BL] = LAYOUT_ansi(
  KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_DEL, \
  KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_SLEP, \
  MT(KC_LCTRL, KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC__MUTE, \
  KC_LSPO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSPC, _______, KC__VOLUP, \
  MOD_HYPR, KC_LALT, KC_LGUI, KC_SPC, KC_RALT, MO(_FL), KC_MRWD, KC_MFFD, _______, KC__VOLDOWN),

  /* Keymap _FL: Function Layer
   * ,----------------------------------------------------------------.
   * |   | F1|F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Del    |    |
   * |----------------------------------------------------------------|
   * |     |   |Up |   |   |   |   |   |   |   |   |   |   |     |    |
   * |----------------------------------------------------------------|
   * |      |<- |Dn | ->|   |   |<- |Dn |Up | ->|   |   |        |    |
   * |----------------------------------------------------------------|
   * |       |Bl-br|Bl-st|Bl-|Bl|Bl+|   |  |  |   |   |      |   |    |
   * |----------------------------------------------------------------|
   * |    |    |    |                       |   |   |    |   |   |    |
   * `----------------------------------------------------------------'
   */

[_FL] = LAYOUT_ansi(
  _______, KC_F1 ,KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, _______,  \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______ ,_______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______, _______, _______, \
  _______, BL_BRTG, BL_STEP, BL_DEC, BL_TOGG, BL_INC, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______ ,_______, _______, _______, _______, _______, _______, _______, _______, _______),
};