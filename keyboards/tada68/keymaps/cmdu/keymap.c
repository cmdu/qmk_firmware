#include "tada68.h"

#define _BL 0
#define _FL 1
#define _______ KC_TRNS
#define TAPPING_TOGGLE 2
enum keyboard_macros {
  MACRO_BACKLIGHT,
  MACRO_BREATH_TOGGLE,
  MACRO_BREATH_SPEED_INC,
  MACRO_BREATH_SPEED_DEC,
  MACRO_BREATH_DEFAULT,
};
#define M_BACKL             M(MACRO_BACKLIGHT)
#define M_BRTOG             M(MACRO_BREATH_TOGGLE)
#define M_BSPDU             M(MACRO_BREATH_SPEED_INC)
#define M_BSPDD             M(MACRO_BREATH_SPEED_DEC)
#define M_BDFLT             M(MACRO_BREATH_DEFAULT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * ,----------------------------------------------------------------.
   * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |~ ` |
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Del |
   * |----------------------------------------------------------------|
   * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgUp|
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|PgDn|
   * |----------------------------------------------------------------|
   * |Ctrl|Win |Alt |        Space          |Alt| TT|Ctrl|Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */

[_BL] = LAYOUT_ansi(
  KC_ESC,    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL, KC_BSPC,KC_GRV, \
  KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC,KC_BSLS,KC_DEL, \
  KC_CAPS, KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,         KC_ENT,KC_PGUP,  \
  KC_LSFT,         KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,   KC_RSFT,KC_UP,KC_PGDN, \
  KC_LCTL, KC_LGUI,KC_LALT,                KC_SPC,                        KC_RALT,TT(_FL),KC_RCTRL, KC_LEFT,KC_DOWN,KC_RGHT),

  /* Keymap _FL: Function Layer
   * ,----------------------------------------------------------------.
   * |   | F1|F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Del    |Ins |
   * |----------------------------------------------------------------|
   * |     |   |Up |   |   |   |   |   |   |   |   |   |   |     |Hme |
   * |----------------------------------------------------------------|
   * |      |<- |Dn | ->|   |   |   |   |   |   |   |   |        |End |
   * |----------------------------------------------------------------|
   * |        |   |   |Bl-|BL |BL+|   |VU-|VU+|MUT|   |   McL|MsU|McR |
   * |----------------------------------------------------------------|
   * |    |    |    |                       |   |   |    |MsL|MsD|MsR |
   * `----------------------------------------------------------------'
   */

[_FL] = LAYOUT_ansi(
  _______, KC_F1 ,KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, KC_INS ,  \
  _______,_______, KC_UP,_______,_______, _______,_______,_______,_______,_______,_______,_______,_______, _______,KC_HOME, \
  _______,KC_LEFT,KC_DOWN,KC_RIGHT,_______,_______,_______,_______,_______,_______,_______,_______,        _______,KC_END, \
  _______,_______,_______,BL_DEC, BL_TOGG,BL_INC, _______,KC_VOLD,KC_VOLU,KC_MUTE,_______,KC_BTN1, KC_MS_U, KC_BTN2, \
  _______,_______,_______,                 _______,               _______,_______,_______,KC_MS_L,KC_MS_D, KC_MS_R),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{

    // MACRODOWN only works in this function
    switch(id)
    {
        case MACRO_BREATH_TOGGLE:
            if (record->event.pressed)
            {
                breathing_toggle();
            }
            break;

        case MACRO_BREATH_SPEED_INC:
            if (record->event.pressed)
            {
                breathing_speed_inc(1);
            }
            break;

        case MACRO_BREATH_SPEED_DEC:
            if (record->event.pressed)
            {
                breathing_speed_dec(1);
            }
            break;

        case MACRO_BREATH_DEFAULT:
            if (record->event.pressed)
            {
                breathing_defaults();
            }
            break;

#ifdef BACKLIGHT_ENABLE
        case MACRO_BACKLIGHT:
            if (record->event.pressed)
            {
                backlight_step();
            }
#endif

        default:
            break;

    }
    return MACRO_NONE;
};