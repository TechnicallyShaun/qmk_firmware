/* Copyright 2025 @ Keychron(https://www.keychron.com)
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
#include "eeconfig_kb.h"

/* OS indication LEDs */
#define LED_MAC_OS_PIN C4
#define LED_WIN_OS_PIN B0
#define LED_OS_PIN_ON_STATE 1

#ifdef RGB_MATRIX_ENABLE
#    define SPI_DRIVER SPID1
#    define SPI_SCK_PIN A5
#    define SPI_MOSI_PIN A7
#    define SN27351_SDB_PIN C10
#    define SNLED23751_SPI_DIVISOR 64
#endif

/* Custom keycodes */
#define CUSTOM_KEYCODES_ENABLE

/*  OS Toggle */
#define KEYCOMBO_OS_TOGGLE_ENABLE
#define KEYCOMBO_OS_TOGGLE_INDICATION_ENABLE
#define MAC_BASE_LAYER 0
#define WIN_BASE_LAYER 2

/* Factory test keys */
#define FN_KEY_1 MO(1)
#define FN_KEY_2 MO(3)

