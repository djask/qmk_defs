/* Copyright 2023 djask
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = LAYOUT(
    KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,     KC_7,     KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,    KC_BSLS,
    KC_LCTL,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_GRV,   KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    QK_BOOT,  QK_BOOT, KC_N,     KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                      MO(2),   KC_LGUI, KC_LALT, KC_LSFT, MO(1),    MO(2),   KC_RSFT,  KC_SPC,   MO(1),   KC_RGUI
),

[1] = LAYOUT(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______,                    KC_PSCR, KC_SCRL, KC_BRK,  KC_MINS, KC_EQL,  _______,
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______,                    KC_INS,  KC_HOME, KC_PGUP, KC_LBRC, KC_RBRC, _______,
    KC_CAPS, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,                    KC_DEL,  KC_END,  KC_PGDN, KC_LPRN, KC_RPRN, _______,
    _______, _______, _______, _______, _______, _______, NK_TOGG,  _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
                      _______, _______, _______, _______, _______,  _______, _______, KC_MINS, _______, _______
),
[2] = LAYOUT(
    _______, KC_BTN3, _______, _______, _______, _______,                    KC_BTN3, KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS, _______,
    _______, KC_BTN2, _______, KC_MS_U, _______, _______,                    KC_BTN2, KC_P7,   KC_P8,   KC_P9,   KC_PEQL, _______,
    _______, KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, _______,                    KC_BTN1, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, _______,
    _______, _______, _______, _______, _______, _______, _______,  _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______,
                      _______, _______, _______, _______, _______,  _______, _______, KC_P0,   _______, KC_PDOT
),

};


#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(KC_WH_U,KC_WH_D), ENCODER_CCW_CW(KC_WH_L, KC_WH_R) },
    [1] =   { ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [2] =   { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
};
#endif

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

void write_int_ln(const char* prefix, uint8_t value) {
    oled_write_P(prefix, false);
    oled_write(get_u8_str(value, ' '), false);
}

static void print_status_narrow(void) {
    oled_write_ln_P(PSTR("KB   Stat _____"), false);

    oled_write_P(PSTR("\n\n\n\n\n"), false);

    // led states
    led_t led_usb_state = host_keyboard_led_state();
    if (led_usb_state.caps_lock) {
        oled_write_ln_P(PSTR(" CAP "), true);
    } else {
        oled_write_ln_P(PSTR("     "), false);
    }

    if (led_usb_state.num_lock) {
        oled_write_ln_P(PSTR(" NUM "), true);
    } else {
        oled_write_ln_P(PSTR("     "), false);
    }

    if (led_usb_state.scroll_lock) {
        oled_write_ln_P(PSTR(" SCR "), true);
    } else {
        oled_write_ln_P(PSTR("     "), false);
    }

    // Print current layer
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("MAIN "), false);
            break;
        case 1:
            oled_write_P(PSTR("MOD  "), false);
            break;
        case 2:
            oled_write_P(PSTR("EXTRA"), false);
            break;
        default:
            oled_write_P(PSTR("???  "), false);
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }

    return false;
}

#endif
