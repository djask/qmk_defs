#include QMK_KEYBOARD_H

/*
Default layout to match a normal keyboard closely (some keys will not match the legends)

Notes:

Missing the [] keys on P row , the backtick goes there in it's place and quote replaces 後退
シフト左mapped to RSHIFT (for right hand space, so left key is unused)
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
    KC_PAUS, KC_ESC ,      KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,   KC_F6  , KC_F7  , KC_F8  ,   KC_F9  , KC_F10  ,                      _______, _______, _______,   _______, _______, _______, _______,
                                                                                                                                               KC_INS , KC_HOME, KC_PGUP,   _______, _______, _______, _______,
         KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8    , KC_9  , KC_0   , KC_MINS, KC_EQL , KC_BSPC,                  KC_DEL , KC_END , KC_PGDN, 
    KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_GRV , KC_BSLS,                                                    _______, _______, _______, _______,
    KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, KC_ENT ,                                   KC_UP  ,         _______, _______, _______, _______,
    KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,                                         KC_LEFT, KC_DOWN, KC_RGHT ,  _______, _______, _______, _______, 
        KC_LGUI, KC_LALT,            KC_RSFT, KC_SPC,                     KC_SPC,                                                                                           _______, _______, _______, _______,
                               KC_MHEN, KC_HENK,                                                                                                       MO(1)  ,             _______, _______ 
    ),
    [1] = LAYOUT(
    QK_BOOT, _______,      KC_F11  , KC_F12  , _______, _______, _______, _______, _______, _______, _______, _______,                         _______, _______, _______,   _______, _______, _______, _______,
                                                                                                                                               _______, _______, _______,   _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, NK_TOGG, _______, 
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                                                    _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                                _______,            _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                                         _______, _______, _______,   _______, _______, _______, _______, 
        _______, _______,            _______, _______,                 _______,                                                                                             _______, _______, _______, _______,
                       _______, _______,                                                                                                                  _______,          _______,      _______
    )
};

