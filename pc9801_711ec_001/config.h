// Copyright 2022 djask (@djask)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

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

/* 2x SN74159N 4-16 BCD Decoders, with 4 unused rows.
 * 28 Rows total

Warnings will be encountered on MATRIX_ROWS as there is a mismatch between the ROW pin count
and the total rows in the MATRIX*/
#define MATRIX_ROW_SEL_BITS 5
#define MATRIX_ROWS 28
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
// Flip pin assignments to save scanning 4 unused rows
// A, B, C, D, G_(strobe)
#define MATRIX_ROW_SEL_PINS { B5, B4, E6, D7, D1 }
#define MATRIX_COL_PINS { B6, B2, B3, B1, F7, F6, F5, F4 }

#define UNUSED_PINS

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* define if matrix has ghost (lacks anti-ghosting diodes) */
#define MATRIX_HAS_GHOST

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define USB_POLLING_INTERVAL_MS 1
