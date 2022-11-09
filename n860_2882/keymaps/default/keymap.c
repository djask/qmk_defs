#include QMK_KEYBOARD_H

// cisco 
enum custom_keycodes {
    M_WRER = SAFE_RANGE,
    M_CPRG
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case M_WRER:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("write erase\n");
        }
        break;
    case M_CPRG:
        if (record->event.pressed) {
            SEND_STRING("copy run start\n");
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
    KC_PAUS, _______,      KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,    _______, _______, _______,        M_CPRG  , M_WRER , KC_F15 , KC_F16 ,
                                                                                                                     KC_INS , KC_HOME, KC_PGUP,        KC_F17  , KC_F18 , KC_F19 , KC_F20 ,
    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_JYEN, KC_BSPC,           KC_DEL , KC_END , KC_PGDN, 
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC,      KC_ENT,                                                 KC_PAST , KC_PSLS, KC_PPLS, KC_PMNS,
    KC_LCTL, KC_A,KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_NUHS,                                  KC_UP  ,                 KC_P7   , KC_P8  , KC_P9  , KC_PEQL,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RO,                              KC_LEFT, KC_DOWN, KC_RGHT ,       KC_P4   , KC_P5  , KC_P6  , KC_PDOT, 
        KC_LGUI, KC_LALT,            KC_SPC,                     KC_RALT, KC_KANA, KC_RCTL,                                                            KC_P1   , KC_P2  , KC_P3  , KC_PENT,
                       KC_MHEN, KC_HENK,                                                                                      MO(1)   ,                       KC_P0,      _______
    ), 
    [1] = LAYOUT(
    QK_BOOT, _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______,   _______, _______, _______, _______,
                                                                                                                                               _______, _______, _______,   _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______, NK_TOGG, _______, 
    _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______, _______, _______, _______, _______, _______, _______, _______,      _______,                                      KC_NUM , _______, _______, _______,
    _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, _______, _______, _______, _______, _______, _______, _______,                              KC_WH_U,              KC_BTN1, KC_MS_U, KC_BTN2, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                              KC_WH_L, KC_WH_D, KC_WH_R,     KC_MS_L, KC_MS_D, KC_MS_R, _______, 
        _______, _______,            _______,                     _______, _______, _______,                                                                                _______, _______, _______, _______,
                       _______, _______,                                                                                                                  _______,          _______,      _______
    )
};

