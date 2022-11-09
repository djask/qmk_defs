#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
    KC_PAUS,      KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_BSPC,  KC_INS, KC_END,      KC_NUM, KC_PSLS, KC_PAST, KC_PMNS,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC,                   MO(1),  KC_NO,       KC_P7, KC_P8, KC_P9, KC_PPLS,
    KC_LCTL, KC_A,KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,        KC_DEL, KC_COPY,     KC_P4, KC_P5, KC_P6, KC_EQL,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RO, KC_RSFT,            KC_UP,  KC_HOME,     KC_P1, KC_P2, KC_P3,
        KC_LGUI, KC_LALT,            KC_SPC,                     KC_RALT, KC_KANA,                 KC_LEFT, KC_DOWN, KC_RGHT,    KC_P0,   KC_PDOT,  KC_PENT,
                       KC_MHEN, KC_HENK
    ),
    [1] = LAYOUT(
    QK_BOOT,      _______, _______, _______, _______, _______, _______, _______, _______, KC_F11, KC_F12,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______,  _______, _______,  _______, NK_TOGG,      _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______,                     _______, _______,      _______, _______, _______, _______,
    _______, _______,_______, _______, _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______,            _______, _______,      _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______,                     KC_PGUP, _______,      _______, _______, _______,
        KC_CAPS, _______,            _______,                     _______, _______,                                                     KC_HOME, KC_PGDN, KC_END,      _______,   _______,  _______,
                       _______, _______
    )
};
