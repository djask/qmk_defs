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

enum custom_keycodes {
	GC_LSU = SAFE_RANGE,
	GC_LSD,
	GC_LSL,
	GC_LSR,
	GC_RSU,
	GC_RSD,
	GC_RSL,
	GC_RSR,
	GC_DPU,
	GC_DPD,
	GC_DPL,
	GC_DPR,
	GC_SQU,
	GC_CRO,
	GC_CIR,
	GC_TRI,
	GC_L1,
	GC_L2,
	GC_L3,
	GC_R1,
	GC_R2,
	GC_R3,
	GC_STA,
	GC_SEL,
	GC_HOM
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = LAYOUT(
    KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,     KC_7,     KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,    KC_BSLS,
    KC_LCTL,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_GRV,   KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    QK_BOOT,  QK_BOOT, KC_N,     KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                      MO(2),   KC_LGUI, KC_LALT, KC_LSFT, MO(1),    MO(2),   KC_RSFT,  KC_SPC,   MO(1),   KC_RGUI
),

[1] = LAYOUT(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   TO(0)  ,                    KC_PSCR, KC_SCRL, KC_BRK,  KC_MINS, KC_EQL,  _______,
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   TO(3)  ,                    KC_INS,  KC_HOME, KC_PGUP, KC_LBRC, KC_RBRC, _______,
    KC_CAPS, KC_F9,   KC_F10,  KC_F11,  KC_F12,  TO(4)  ,                    KC_DEL,  KC_END,  KC_PGDN, KC_LPRN, KC_RPRN, _______,
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
//game1
[3] = LAYOUT(
    GC_HOM , GC_SEL , GC_STA , _______, _______, _______,                    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                    _______, GC_SQU,  GC_TRI,  GC_R1,   GC_L1,   _______,
    _______, _______, GC_DPL , GC_DPD , GC_DPR , _______,                    _______, GC_CRO,  GC_CIR,  GC_R2,   GC_L2,   _______,
    _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______,
                      _______, _______, GC_DPU , _______, _______,  MO(1)  , _______, GC_DPU , _______, _______
),
//game2
[4] = LAYOUT(
    GC_HOM , GC_SEL , GC_STA , _______, _______, _______,                    _______, _______, _______, _______, _______, _______,
    GC_R1  , _______, _______, _______, GC_LSU , _______,                    _______, GC_RSU,  _______,  GC_SQU,  GC_SQU,  GC_L1,
    GC_R2  , _______, _______, GC_LSL , GC_LSD , GC_LSL ,                    GC_RSL , GC_RSD,   GC_RSR,  GC_CRO,  GC_CRO,  GC_L2,
    _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______,
                      _______, _______, GC_R2  , GC_R1  , _______,  MO(1)  , GC_L1  , GC_L2  , _______, _______
),

};

joystick_config_t joystick_axes[JOYSTICK_AXIS_COUNT] = {
	JOYSTICK_AXIS_VIRTUAL,
	JOYSTICK_AXIS_VIRTUAL,
	JOYSTICK_AXIS_VIRTUAL,
	JOYSTICK_AXIS_VIRTUAL,
	JOYSTICK_AXIS_VIRTUAL,
	JOYSTICK_AXIS_VIRTUAL,
};

bool LSU_STATE = false;
bool LSD_STATE = false;
bool LSL_STATE = false;
bool LSR_STATE = false;
bool RSU_STATE = false;
bool RSD_STATE = false;
bool RSL_STATE = false;
bool RSR_STATE = false;
bool DPU_STATE = false;
bool DPD_STATE = false;
bool DPL_STATE = false;
bool DPR_STATE = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case GC_LSU:
			if (record->event.pressed) {
				LSU_STATE = true;
				joystick_set_axis(1, -127);
			} else {
				LSU_STATE = false;
				if (LSD_STATE) {
					joystick_set_axis(1, 127);
				} else {
					joystick_set_axis(1, 0);
				}
			}
			return false;
		case GC_LSD:
			if (record->event.pressed) {
				LSD_STATE = true;
				if (!LSU_STATE) {
					joystick_set_axis(1, 127);
				}
			} else {
				LSD_STATE = false;
				if (!LSU_STATE) {
					joystick_set_axis(1, 0);
				}
			}
			return false;
		case GC_LSL:
			if (record->event.pressed) {
				LSL_STATE = true;
				joystick_set_axis(0, -127);
			} else {
				LSL_STATE = false;
				if (LSR_STATE) {
					joystick_set_axis(0, 127);
				} else {
					joystick_set_axis(0, 0);
				}
			}
			return false;
		case GC_LSR:
			if (record->event.pressed) {
				LSR_STATE = true;
				joystick_set_axis(0, 127);
			} else {
				LSR_STATE = false;
				if (LSL_STATE) {
					joystick_set_axis(0, -127);
				} else {
					joystick_set_axis(0, 0);
				}
			}
			return false;
		case GC_DPU:
			if (record->event.pressed) {
				DPU_STATE = true;
				if (DPD_STATE) {
					unregister_joystick_button(16);
				}
				register_joystick_button(18);
			} else {
				DPU_STATE = false;
				unregister_joystick_button(18);
			}
			return false;
		case GC_DPD:
			if (record->event.pressed) {
				DPD_STATE = true;
				if (!DPU_STATE) {
					register_joystick_button(16);
				}
			} else {
				DPD_STATE = false;
				unregister_joystick_button(16);
			}
			return false;
		case GC_DPL:
			if (record->event.pressed) {
				DPL_STATE = true;
				if (DPR_STATE) {
					unregister_joystick_button(17);
				} else {
					register_joystick_button(15);
				}
			} else {
				DPL_STATE = false;
				unregister_joystick_button(15);
				if (DPR_STATE) {
					register_joystick_button(17);
				}
			}
			return false;
		case GC_DPR:
			if (record->event.pressed) {
				DPR_STATE = true;
				if (DPL_STATE) {
					unregister_joystick_button(15);
				} else {
					register_joystick_button(17);
				}
			} else {
				DPR_STATE = false;
				unregister_joystick_button(17);
				if (DPL_STATE) {
					register_joystick_button(15);
				}
			}
			return false;
		case GC_RSU:
			if (record->event.pressed) {
				RSU_STATE = true;
				joystick_set_axis(4, -127);
			} else {
				RSU_STATE = false;
				if (RSD_STATE) {
					joystick_set_axis(4, 127);
				} else {
					joystick_set_axis(4, 0);
				}
			}
			return false;
		case GC_RSD:
			if (record->event.pressed) {
				RSD_STATE = true;
				if (!RSU_STATE) {
					joystick_set_axis(4, 127);
				}
			} else {
				RSD_STATE = false;
				if (RSU_STATE) {
					joystick_set_axis(4, -127);
				} else {
					joystick_set_axis(4, 0);
				}
			}
			return false;
		case GC_RSL:
			if (record->event.pressed) {
				RSL_STATE = true;
				joystick_set_axis(3, -127);
			} else {
				RSL_STATE = false;
				if (RSR_STATE) {
					joystick_set_axis(3, 127);
				} else {
					joystick_set_axis(3, 0);
				}
			}
			return false;
		case GC_RSR:
			if (record->event.pressed) {
				RSR_STATE = true;
				joystick_set_axis(3, 127);
			} else {
				RSR_STATE = false;
				if (RSL_STATE) {
					joystick_set_axis(3, -127);
				} else {
					joystick_set_axis(3, 0);
				}
			}
			return false;
		case GC_SQU:
			if (record->event.pressed) {
				register_joystick_button(0);
			} else {
				unregister_joystick_button(0);
			}
			return false;
		case GC_CRO:
			if (record->event.pressed) {
				register_joystick_button(1);
			} else {
				unregister_joystick_button(1);
			}
			return false;
		case GC_CIR:
			if (record->event.pressed) {
				register_joystick_button(2);
			} else {
				unregister_joystick_button(2);
			}
			return false;
		case GC_TRI:
			if (record->event.pressed) {
				register_joystick_button(3);
			} else {
				unregister_joystick_button(3);
			}
			return false;
		case GC_L1:
			if (record->event.pressed) {
				register_joystick_button(4);
			} else {
				unregister_joystick_button(4);
			}
			return false;
		case GC_R1:
			if (record->event.pressed) {
				register_joystick_button(5);
			} else {
				unregister_joystick_button(5);
			}
			return false;
		case GC_L2:
			if (record->event.pressed) {
				register_joystick_button(6);
			} else {
				unregister_joystick_button(6);
			}
			return false;
		case GC_R2:
			if (record->event.pressed) {
				register_joystick_button(7);
			} else {
				unregister_joystick_button(7);
			}
			return false;
		case GC_SEL:
			if (record->event.pressed) {
				register_joystick_button(8);
			} else {
				unregister_joystick_button(8);
			}
			return false;
		case GC_STA:
			if (record->event.pressed) {
				register_joystick_button(9);
			} else {
				unregister_joystick_button(9);
			}
			return false;
		case GC_L3:
			if (record->event.pressed) {
				register_joystick_button(10);
			} else {
				unregister_joystick_button(10);
			}
			return false;
		case GC_R3:
			if (record->event.pressed) {
				register_joystick_button(11);
			} else {
				unregister_joystick_button(11);
			}
			return false;
		case GC_HOM:
			if (record->event.pressed) {
				register_joystick_button(12);
			} else {
				unregister_joystick_button(12);
			}
			return false;
		default:
			return true;
	}
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(KC_WH_U,KC_WH_D), ENCODER_CCW_CW(KC_WH_L, KC_WH_R) },
    [1] =   { ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [2] =   { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [3] =   { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [4] =   { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
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
