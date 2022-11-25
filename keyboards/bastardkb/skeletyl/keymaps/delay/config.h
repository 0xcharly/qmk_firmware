/*
 * Copyright 2022 Charly Delay <charly@codesink.dev> (@0xcharly)
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

#ifdef MCU_RP
/* Handedness.  Assume adapter v2 for personal boards. */
#    undef MASTER_RIGHT

// To use the handedness pin, resistors need to be installed on the adapter PCB.
#ifdef KEYBOARD_bastardkb_skeletyl_v2_splinky_2
#    define SPLIT_HAND_PIN GP13
#else
#    define SPLIT_HAND_PIN GP15
#endif // KEYBOARD_bastardkb_skeletyl_v2_splinky_2
#    define SPLIT_HAND_PIN_LOW_IS_LEFT // High -> right, Low -> left.

#    undef SOFT_SERIAL_PIN
#    define SERIAL_USART_FULL_DUPLEX // Enable full duplex operation mode.
#    define SERIAL_USART_TX_PIN GP1  // USART TX pin
#ifdef KEYBOARD_bastardkb_skeletyl_v2_splinky_2
#    define SERIAL_USART_RX_PIN GP12 // USART RX pin
#else
#    define SERIAL_USART_RX_PIN GP14 // USART RX pin
#endif // KEYBOARD_bastardkb_skeletyl_v2_splinky_2
#    define SERIAL_USART_PIN_SWAP
#endif
