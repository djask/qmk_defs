#include QMK_KEYBOARD_H


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = LAYOUT(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   _______, _______,KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_INS , KC_DEL ,KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_HOME, KC_PGUP,KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_END , KC_PGDN,KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  KC_NO ,  KC_CAPS, KC_LGUI, KC_LALT, MO(1),           MO(2)  , MO(2)   ,KC_SPC,           KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),
[1] = LAYOUT(
  KC_GRV , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_WH_U, QK_BOOT, KC_ACL0,_______,KC_BTN2, _______, KC_MINS, KC_EQL , _______, 
  _______, KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_WH_D, _______, KC_ACL1,KC_WH_U,KC_BTN1, KC_MS_U, KC_LBRC, KC_RBRC, _______, 
  _______, KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_WH_L, _______, KC_ACL2,KC_WH_D,KC_MS_L, KC_MS_D, KC_MS_R, _______, KC_QUOT,
  _______, _______, _______, _______, _______, _______, _______, KC_WH_L,KC_WH_R,_______, _______, _______, _______, _______, 
  _______, _______, _______, _______, _______,          AS_TOGG, NK_TOGG,KC_MINS,         _______, _______, _______, _______
),
[2] = LAYOUT(
  _______, _______, _______, _______, _______, _______, _______, _______, KC_NUM , KC_PSLS, KC_PAST, KC_PMNS, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_P7  , KC_P8  , KC_P9  , KC_PPLS, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_P4  , KC_P5  , KC_P6  , _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_P1  , KC_P2  , KC_P3  , KC_PENT, _______, _______,
  _______, _______, _______, _______, _______,          _______, _______, KC_P0  ,          KC_PDOT, _______, _______, _______
)
};

