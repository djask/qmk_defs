/* Copyright 2022 Brian Low
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

#pragma once

// Wiring of each half
#define MATRIX_ROW_PINS { GP5, GP6, GP7, GP8, GP9 }
#define MATRIX_COL_PINS { GP27, GP26, GP22, GP20, GP23, GP21 }
#define DIODE_DIRECTION COL2ROW

// SOFT_SERIAL_PIN is used for the SERIAL_USART_TX_PIN def
#define SOFT_SERIAL_PIN GP1

#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP2
#define I2C1_SCL_PIN GP3

// Encoder support
#define ENCODERS_PAD_A { GP29 }
#define ENCODERS_PAD_B { GP28 }
#define ENCODERS_PAD_A_RIGHT { GP28 }
#define ENCODERS_PAD_B_RIGHT { GP29 }

#define SPLIT_WATCHDOG_ENABLE

/*
#ifdef RGB_MATRIX_ENABLE
#define WS2812_DI_PIN D3
#define RGBLED_NUM 29
#define RGB_MATRIX_LED_COUNT 58
#define RGB_MATRIX_SPLIT { 29, 29 }
#endif
*/
