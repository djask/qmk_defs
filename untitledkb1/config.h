// Copyright 2022 djask (@djask)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include <config_common.h>

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

/* key matrix size */

#define MATRIX_ROWS 10 
#define MATRIX_COLS 7

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *         ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
*/
// #define MATRIX_ROW_SEL_PINS { B1, B2, B3, B7 }
// #define MATRIX_COL_PINS { F4, F5, F6, F7, D0, D1, D2 }
// #define UNUSED_PINS

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE


#define AUTO_SHIFT_TIMEOUT 135
#define NO_AUTO_SHIFT_ALPHA
#define MK_KINETIC_SPEED
