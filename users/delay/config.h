/**
 * Copyright 2021-2022 Charly Delay <charly@codesink.dev> (@0xcharly)
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

#ifdef SPLIT_KEYBOARD
#    ifndef SPLIT_HAND_PIN
/**
 * \brief Flash each side with `-bl dfu-split-*` to set handedness in memory eg.
 *
 *     `qmk flash -bl uf2-split-left -kb <keyboard> -km delay`
 *     `qmk flash -bl uf2-split-right -kb <keyboard> -km delay`
 *
 * The handedness needs only be set once.  The actual firmware image is
 * unchanged.  This means that even though the commands above will keep working,
 * the flashing process can be simplified by using the same flash command for
 * both halves once the handedness has been set once to EEPROM, ie.
 *
 *     `qmk flash -kb <keyboard> -km delay`
 */
#        define EE_HANDS
#    endif // SPLIT_HAND_PIN

// Enable split keyboards extensions, in order to sync state between the halves.
#    define SPLIT_MODS_ENABLE
#    define SPLIT_LED_STATE_ENABLE
#    define SPLIT_LAYER_STATE_ENABLE
#endif // SPLIT_KEYBOARD

/** \brief Only uses 16 bits for layers. Limits available layers to 16.  */
#define LAYER_STATE_16BIT

/**
 * \brief Tapping this number of times holds the key until tapped once again.
 *
 * https://beta.docs.qmk.fm/using-qmk/software-features/one_shot_keys
 */
#define ONESHOT_TAP_TOGGLE 2

/**
 * \brief Time (in ms) before the one shot key is released.
 *
 * https://beta.docs.qmk.fm/using-qmk/software-features/one_shot_keys
 */
#define ONESHOT_TIMEOUT 1500

/**
 * \brief Configure the global combo term (default: 50ms).
 */
#ifndef COMBO_TERM
#    define COMBO_TERM 25
#endif // COMBO_TERM

/**
 * \brief Configure the global tapping term (default: 200ms).
 *
 * If you have a lot of accidental mod activations, crank up the tapping term.
 *
 * See
 *   https://beta.docs.qmk.fm/using-qmk/software-features/tap_hold#tapping-term
 *   https://precondition.github.io/home-row-mods#tapping-term
 */
#ifndef TAPPING_TERM
#    define TAPPING_TERM 175
#endif // !TAPPING_TERM

#ifndef QUICK_TAP_TERM
#    define QUICK_TAP_TERM 75
#endif // QUICK_TAP_TERM

/**
 * \brief Customize the TAPPING_TERM for specific keys.
 */
#define TAPPING_TERM_PER_KEY

/**
 * \brief Enable rapid switch from tap to hold.
 *
 * Note that a side-effect of this setting is to disable auto-repeat when
 * pressing key twice, except for one-shot keys.
 *
 * See
 *   https://beta.docs.qmk.fm/using-qmk/software-features/tap_hold#tapping-force-hold
 *   https://precondition.github.io/home-row-mods#tapping-force-hold
 */
// #define TAPPING_FORCE_HOLD_PER_KEY

/*
 * Tap-or-Hold decision modes, per keymap.
 *
 * Note that the following flags behave differently when combined (ie. when 2 or
 * more are enabled).
 *
 * See bit.ly/tap-or-hold for a visual explanation of the following tap-or-hold
 * decision modes.
 */

/**
 * \brief Faster layer-tap hold trigger.
 *
 * Without `HOLD_ON_OTHER_KEY_PRESS`, within `TAPPING_TERM`:
 *     LT(2, a)🠗 e🠗 LT(2, a)🠕 e🠕 ➞ ae
 * With `HOLD_ON_OTHER_KEY_PRESS`, within `TAPPING_TERM`:
 *     LT(2, a)🠗 e🠗 LT(2, a)🠕 e🠕 ➞ <mapping of e on layer>
 */
#define HOLD_ON_OTHER_KEY_PRESS

/**
 * \brief Faster layer-tap hold trigger.
 *
 * Without `HOLD_ON_OTHER_KEY_PRESS`, within `TAPPING_TERM`:
 *     LT(2, a)🠗 e🠗 LT(2, a)🠕 e🠕 ➞ ae
 * With `HOLD_ON_OTHER_KEY_PRESS`, within `TAPPING_TERM`:
 *     LT(2, a)🠗 e🠗 LT(2, a)🠕 e🠕 ➞ <mapping of e on layer>
 */
// #define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

/**
 * \brief Faster tap-hold trigger.
 *
 * Without `PERMISSIVE_HOLD`, within `TAPPING_TERM`:
 *   Mod(a)🠗 e🠗 e🠕 Mod(a)🠕 ➞ ae
 * With `PERMISSIVE_HOLD`, within `TAPPING_TERM`:
 *   Mod(a)🠗 e🠗 e🠕 Mod(a)🠕 ➞ Mod+e
 *
 * See precondition.github.io/home-row-mods#permissive-hold.
 */
// #define PERMISSIVE_HOLD

/**
 * \brief Prevent normal rollover on alphas from accidentally triggering mods.
 *
 * Ignores key presses that interrupt a mod-tap.  Must-have for Home Row mod.
 *
 * Without `IGNORE_MOD_TAP_INTERRUPT`, within `TAPPING_TERM`:
 *   Mod(a)🠗 e🠗 Mod(a)🠕 e🠕 ➞ Mod+e
 * With `IGNORE_MOD_TAP_INTERRUPT`, within `TAPPING_TERM`:
 *   Mod(a)🠗 e🠗 Mod(a)🠕 e🠕 ➞ ae
 *
 * https://beta.docs.qmk.fm/using-qmk/software-features/tap_hold#ignore-mod-tap-interrupt
 */
// #define IGNORE_MOD_TAP_INTERRUPT

#ifdef RGB_MATRIX_ENABLE
// Enable all animations, assume enough memory.
#    define ENABLE_RGB_MATRIX_ALPHAS_MODS
#    define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#    define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#    define ENABLE_RGB_MATRIX_BREATHING
#    define ENABLE_RGB_MATRIX_BAND_SAT
#    define ENABLE_RGB_MATRIX_BAND_VAL
#    define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#    define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#    define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#    define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#    define ENABLE_RGB_MATRIX_CYCLE_ALL
#    define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#    define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#    define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#    define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#    define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#    define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#    define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#    define ENABLE_RGB_MATRIX_DUAL_BEACON
#    define ENABLE_RGB_MATRIX_RAINBOW_BEACON
#    define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#    define ENABLE_RGB_MATRIX_RAINDROPS
#    define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#    define ENABLE_RGB_MATRIX_HUE_BREATHING
#    define ENABLE_RGB_MATRIX_HUE_PENDULUM
#    define ENABLE_RGB_MATRIX_HUE_WAVE
#    define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#    define ENABLE_RGB_MATRIX_DIGITAL_RAIN
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#    define ENABLE_RGB_MATRIX_SPLASH
#    define ENABLE_RGB_MATRIX_MULTISPLASH
#    define ENABLE_RGB_MATRIX_SOLID_SPLASH
#    define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH

// Limit maximum brightness to keep power consumption reasonable, and avoid disconnects.
#    undef RGB_MATRIX_MAXIMUM_BRIGHTNESS
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 64

// Rainbow swirl as startup mode.
#    define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_RAINBOW_MOVING_CHEVRON

// Slow swirl at startup.
#    undef RGB_MATRIX_DEFAULT_SPD
#    define RGB_MATRIX_DEFAULT_SPD 32

// Startup values.
#    undef RGB_MATRIX_DEFAULT_HUE
#    define RGB_MATRIX_DEFAULT_HUE 0
#    undef RGB_MATRIX_DEFAULT_SAT
#    define RGB_MATRIX_DEFAULT_SAT 255
#    undef RGB_MATRIX_DEFAULT_VAL
#    define RGB_MATRIX_DEFAULT_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS
#    undef RGB_MATRIX_DEFAULT_HSV
#    define RGB_MATRIX_DEFAULT_HSV RGB_MATRIX_DEFAULT_HUE, RGB_MATRIX_DEFAULT_SAT, RGB_MATRIX_DEFAULT_VAL
#endif // RGB_MATRIX_ENABLE
