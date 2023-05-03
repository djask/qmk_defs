/* Copyright 2015-2017 Jack Humbert
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
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    TO(0)  , TO(3)  , KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_INS , KC_UP  , KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HOME, KC_DOWN, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LEFT, KC_RGHT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  _______, _______, _______, KC_LALT , MO(1),            MO(2)  , KC_RGUI, KC_SPC,           _______, _______, _______, _______
),
[1] = LAYOUT(
  KC_GRV , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_BTN1, QK_BOOT, _______, _______,KC_BTN2, KC_BTN3, KC_MINS, KC_EQL , _______, 
  _______, KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_BTN2, KC_INS , KC_DEL , KC_WH_U,KC_BTN1, KC_MS_U, KC_LBRC, KC_RBRC, _______, 
  _______, KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_BTN3, KC_HOME, KC_PGUP, KC_WH_D,KC_MS_L, KC_MS_D, KC_MS_R, _______, KC_QUOT,
  _______, _______, _______, _______, _______, _______, KC_END , KC_PGDN, KC_WH_L,KC_WH_R, _______, _______, _______, _______, 
  _______, _______, _______, _______, _______,          AS_TOGG, NK_TOGG, KC_MINS,         _______, _______, _______, _______
),
[2] = LAYOUT(
  _______, _______, _______, _______, _______, _______, _______, _______, KC_NUM , KC_PSLS, KC_PAST, KC_PMNS, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_P7  , KC_P8  , KC_P9  , KC_PPLS, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_P4  , KC_P5  , KC_P6  , _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_P1  , KC_P2  , KC_P3  , KC_PENT, _______, _______,
  _______, _______, _______, _______, _______,          _______, _______, KC_P0  ,          KC_PDOT, _______, _______, _______
),
// Gamepad layer
[3] = LAYOUT(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP  , _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, KC_SPC ,          MO(1)  , MO(2)  , _______,          _______, _______, _______, _______
)
};

