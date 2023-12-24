// Copyright 2022 djask (@djask)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once


//#include <config_common.h>

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

/* Fujitsu boards use a BCD Decoder and use a row selector as a matrix scanning method.
Result of this is that you need only 4 row selector pins to select one of 16 row outputs
The bad news is that you need a custom matrix scanner defined in order to use it.

Warnings will be encountered on MATRIX_ROWS as there is a mismatch between the ROW pin count
and the total rows in the MATRIX*/
#define MATRIX_ROWS 16 //row selector matrix
#define MATRIX_COLS 8

#define MATRIX_IO_DELAY 5

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
#define MATRIX_ROW_SEL_PINS { D1, D0, D4, C6 }
#define MATRIX_COL_SEL_PINS { D7, E6, B4 }

// Only one COL pin, col is determined by demux chip on board.
#define MATRIX_COL_PIN B6

// Break is wired directly to ground, extra input pin can be wired to switch to detect keypress
// #define MATRIX_BREAK_PIN B0
#define UNUSED_PINS

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* define if matrix has ghost (lacks anti-ghosting diodes) */
//#define MATRIX_HAS_GHOST

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define USB_POLLING_INTERVAL_MS 1

#define MK_KINETIC_SPEED
#define MOUSEKEY_INITIAL_SPEED 20
