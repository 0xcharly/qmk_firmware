/**
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

#include "dilemma.h"
#include QMK_KEYBOARD_H
#include "users/delay/delay.h"

#ifdef OLED_ENABLE
#include "oled_driver.h"
#endif  // OLED_ENABLE

#define LAYOUT_dilemma(...) LAYOUT_split_3x5_2(__VA_ARGS__)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DVORAK] = LAYOUT_dilemma(DVORAK_split_3x5_2),
  [_APTv3] = LAYOUT_dilemma(APTv3_split_3x5_2),
  [_RSTHD] = LAYOUT_dilemma(RSTHD_split_3x5_2),
  [_MOTION] = LAYOUT_dilemma(MOTION_split_3x5_2),
  [_SYMBOL] = LAYOUT_dilemma(SYMBOL_split_3x5_2),
  [_NUMBER] = LAYOUT_dilemma(NUMBER_split_3x5_2),
  [_SYSTEM] = LAYOUT_dilemma(SYSTEM_split_3x5_2),
};
// clang-format on

#ifdef OLED_ENABLE
#include "oled_driver.h"

void oled_pan_section(bool left, uint16_t y_start, uint16_t y_end,
                      uint16_t x_start, uint16_t x_end);

#if defined(OLED_DISPLAY_128X128) || defined(OLED_DISPLAY_128X64)
#define OLED_DISPLAY_VERBOSE

#define OLED_RENDER_KEYLOGGER "Keylogger: "
#ifndef OLED_KEYLOGGER_LENGTH
#define OLED_KEYLOGGER_LENGTH 9
#endif
#define OLED_RENDER_LAYOUT_NAME "Layout: "
#define OLED_RENDER_LAYOUT_QWERTY "Qwerty"
#define OLED_RENDER_LAYOUT_COLEMAK_DH "Colemak DH"
#define OLED_RENDER_LAYOUT_COLEMAK "Colemak"
#define OLED_RENDER_LAYOUT_DVORAK "Dvorak"
#define OLED_RENDER_LAYOUT_WORKMAN "Workman"
#define OLED_RENDER_LAYOUT_NORMAN "Norman"
#define OLED_RENDER_LAYOUT_MALTRON "Matron"
#define OLED_RENDER_LAYOUT_EUCALYN "Eucalyn"
#define OLED_RENDER_LAYOUT_CARPLAX "Carplax"

#define OLED_RENDER_LAYER_NAME "Layer:"
#define OLED_RENDER_LAYER_LOWER "Lower"
#define OLED_RENDER_LAYER_RAISE "Raise"
#define OLED_RENDER_LAYER_ADJUST "Adjust"
#define OLED_RENDER_LAYER_MODS "Mods"

#define OLED_RENDER_LOCK_NAME "Lock: "
#define OLED_RENDER_LOCK_NUML "NUM"
#define OLED_RENDER_LOCK_CAPS "CAPS"
#define OLED_RENDER_LOCK_SCLK "SCLK"

#define OLED_RENDER_MODS_NAME "Mods"
#define OLED_RENDER_MODS_SFT "Sft"
#define OLED_RENDER_MODS_CTL "Ctl"
#define OLED_RENDER_MODS_ALT "Alt"
#define OLED_RENDER_MODS_GUI "GUI"

#define OLED_RENDER_BOOTMAGIC_NAME "Boot  "
#define OLED_RENDER_BOOTMAGIC_NKRO "NKRO"
#define OLED_RENDER_BOOTMAGIC_NOGUI "nGUI"
#define OLED_RENDER_BOOTMAGIC_GRV "GRV"
#define OLED_RENDER_BOOTMAGIC_ONESHOT "1SHT"
#define OLED_RENDER_BOOTMAGIC_SWAP "SWAP"
#define OLED_RENDER_BOOTMAGIC_CAPS "CAPS"

#define OLED_RENDER_USER_NAME "USER:"
#define OLED_RENDER_USER_ANIM "Anim"
#define OLED_RENDER_USER_LAYR "Layr"
#define OLED_RENDER_USER_NUKE "Nuke"

#define OLED_RENDER_WPM_COUNTER "WPM: "
#else
#define OLED_RENDER_KEYLOGGER "KLogr"
#ifndef OLED_KEYLOGGER_LENGTH
#define OLED_KEYLOGGER_LENGTH 5
#endif

#define OLED_RENDER_LAYOUT_NAME "Lyout"
#define OLED_RENDER_LAYOUT_QWERTY " QRTY"
#define OLED_RENDER_LAYOUT_COLEMAK_DH " cmDH"
#define OLED_RENDER_LAYOUT_COLEMAK " COLE"
#define OLED_RENDER_LAYOUT_DVORAK " DVRK"
#define OLED_RENDER_LAYOUT_WORKMAN " WKMN"
#define OLED_RENDER_LAYOUT_NORMAN " NORM"
#define OLED_RENDER_LAYOUT_MALTRON " MLTN"
#define OLED_RENDER_LAYOUT_EUCALYN " ECLN"
#define OLED_RENDER_LAYOUT_CARPLAX " CRPX"

#define OLED_RENDER_LAYER_NAME "LAYER"
#define OLED_RENDER_LAYER_LOWER "Lower"
#define OLED_RENDER_LAYER_RAISE "Raise"
#define OLED_RENDER_LAYER_ADJUST "Adjst"
#define OLED_RENDER_LAYER_MODS " Mods"

#define OLED_RENDER_LOCK_NAME "Lock:"
#define OLED_RENDER_LOCK_NUML "NumL"
#define OLED_RENDER_LOCK_CAPS "CapL"
#define OLED_RENDER_LOCK_SCLK "ScrL"

#define OLED_RENDER_MODS_NAME "Mods: "
#define OLED_RENDER_MODS_SFT "Shft"
#define OLED_RENDER_MODS_CTL "Ctrl"
#define OLED_RENDER_MODS_ALT "Alt\n"
#define OLED_RENDER_MODS_GUI "GUI\n"

#define OLED_RENDER_BOOTMAGIC_NAME "BTMGK"
#define OLED_RENDER_BOOTMAGIC_NKRO "NKRO"
#define OLED_RENDER_BOOTMAGIC_NOGUI "nGUI"
#define OLED_RENDER_BOOTMAGIC_GRV "GRV"
#define OLED_RENDER_BOOTMAGIC_ONESHOT "1SHT"
#define OLED_RENDER_BOOTMAGIC_SWAP "SWAP"
#define OLED_RENDER_BOOTMAGIC_CAPS "CAPS"

#define OLED_RENDER_USER_NAME "USER:"
#define OLED_RENDER_USER_ANIM "Anim"
#define OLED_RENDER_USER_LAYR "Layr"
#define OLED_RENDER_USER_NUKE "Nuke"

#define OLED_RENDER_WPM_COUNTER "WPM: "
#endif

#ifndef OLED_WPM_GRAPH_MAX_WPM
#define OLED_WPM_GRAPH_MAX_WPM 120
#endif
#ifndef OLED_WPM_GRAPH_REFRESH_INTERVAL
#define OLED_WPM_GRAPH_REFRESH_INTERVAL 300
#endif
#ifndef OLED_WPM_GRAPH_AREA_FILL_INTERVAL
#define OLED_WPM_GRAPH_AREA_FILL_INTERVAL 3
#endif
#ifndef OLED_WPM_GRAPH_VERTCAL_LINE_INTERVAL
#define OLED_WPM_GRAPH_VERTCAL_LINE_INTERVAL 3
#endif
#ifndef OLED_WPM_GRAPH_GRAPH_LINE_THICKNESS
#define OLED_WPM_GRAPH_GRAPH_LINE_THICKNESS 2
#endif

static uint16_t splash_screen_timer;
static deferred_token kittoken;

static void render_logo(void) {
  static const char PROGMEM raw_logo[] = {
      // Bastard Keyboards, 128x32px
      0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0xf0, 0xf8, 0xf8, 0x3c, 0x1c,
      0x1e, 0x1e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x1e, 0x1c, 0x3c,
      0x3c, 0x78, 0xf0, 0xe0, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0xf8, 0xf8, 0x98, 0xf8, 0x70, 0x00, 0x00, 0xf0, 0xf8, 0xf8, 0xe0,
      0x00, 0x00, 0xf0, 0xf8, 0x98, 0xb8, 0x30, 0x00, 0x18, 0xf8, 0xf8, 0x18,
      0x18, 0x00, 0xf0, 0xf8, 0xf8, 0xe0, 0x00, 0x00, 0x60, 0xf0, 0x98, 0x98,
      0xf8, 0xf8, 0x00, 0xf8, 0xf8, 0x18, 0xf8, 0xf0, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xfe,
      0xff, 0x3f, 0x07, 0xff, 0xff, 0xff, 0x60, 0x70, 0x70, 0x70, 0xe0, 0xc0,
      0x80, 0x00, 0x00, 0xff, 0xff, 0xff, 0xc0, 0xe0, 0xf0, 0x30, 0x10, 0x03,
      0x07, 0xff, 0xff, 0xfc, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x09,
      0x0f, 0x0f, 0x00, 0x0e, 0x0f, 0x06, 0x07, 0x0f, 0x0c, 0x00, 0x0c, 0x0c,
      0x09, 0x0f, 0x0f, 0x00, 0x00, 0x0f, 0x0f, 0x00, 0x00, 0x0e, 0x0f, 0x06,
      0x07, 0x0f, 0x0c, 0x00, 0x0e, 0x0f, 0x01, 0x01, 0x0f, 0x0f, 0x00, 0x0f,
      0x0f, 0x08, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x7f, 0xff, 0xfc, 0xe0, 0x83,
      0x0f, 0x1f, 0x18, 0x38, 0x38, 0x18, 0x1f, 0x0f, 0x07, 0x00, 0x00, 0x3f,
      0x3f, 0x3f, 0x03, 0x07, 0x3f, 0xfe, 0xf0, 0xc0, 0xf0, 0xff, 0xff, 0x3f,
      0x03, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xf8, 0xe0, 0xf8, 0x18, 0x00, 0xf8,
      0xf8, 0xc8, 0xc8, 0xc8, 0x00, 0x08, 0x38, 0xf0, 0xe0, 0x78, 0x08, 0x00,
      0xf8, 0xf8, 0xc8, 0xf8, 0xf8, 0x00, 0xf0, 0xf8, 0x18, 0x0c, 0xf8, 0xf8,
      0x00, 0x80, 0xf8, 0x38, 0xf8, 0xe0, 0x00, 0x00, 0xf8, 0xf8, 0xc8, 0xf8,
      0xf8, 0x00, 0xf8, 0xf8, 0x08, 0x08, 0xf8, 0xf8, 0x00, 0x78, 0xf8, 0xcc,
      0xd8, 0x98, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x0f, 0x1f, 0x1e, 0x3c, 0x3c,
      0x38, 0x78, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x78, 0x38, 0x3c,
      0x1c, 0x1e, 0x0f, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x0f, 0x0f, 0x00, 0x07, 0x0f, 0x08, 0x0f, 0x0f, 0x0c, 0x0c, 0x0c,
      0x00, 0x00, 0x00, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0c, 0x0c,
      0x07, 0x03, 0x03, 0x07, 0x0c, 0x0c, 0x0f, 0x07, 0x00, 0x0f, 0x07, 0x03,
      0x03, 0x0f, 0x0c, 0x00, 0x0f, 0x0f, 0x00, 0x0f, 0x0f, 0x00, 0x0f, 0x0f,
      0x0c, 0x0c, 0x07, 0x07, 0x00, 0x06, 0x0e, 0x0c, 0x0f, 0x07, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  };
  oled_write_raw_P(raw_logo, sizeof(raw_logo));
}

// WPM-responsive animation stuff here
#define OLED_SLEEP_FRAMES 2
#define OLED_SLEEP_SPEED 10  // below this wpm value your animation will idle

#define OLED_WAKE_FRAMES 2  // uncomment if >1
#define OLED_WAKE_SPEED \
  OLED_SLEEP_SPEED  // below this wpm value your animation will idle

#define OLED_KAKI_FRAMES 3
#define OLED_KAKI_SPEED 40  // above this wpm value typing animation to triggere

#define OLED_RTOGI_FRAMES 2
// #define OLED_LTOGI_FRAMES 2

// #define ANIM_FRAME_DURATION 500 // how long each frame lasts in ms
//  #define SLEEP_TIMER 60000 // should sleep after this period of 0 wpm, needs
//  fixing
#define OLED_ANIM_SIZE 36
#define OLED_ANIM_ROWS 4
#define OLED_ANIM_MAX_FRAMES 3
#if (OLED_SLEEP_FRAMES > OLED_ANIM_MAX_FRAMES) || \
    (OLED_WAKE_FRAMES > OLED_ANIM_MAX_FRAMES) ||  \
    (OLED_KAKI_FRAMES > OLED_ANIM_MAX_FRAMES) ||  \
    (OLED_RTOGI_FRAMES > OLED_ANIM_MAX_FRAMES)
#error frame size too large
#endif

static uint8_t animation_frame = 0;
static uint8_t animation_type = 0;

static void render_kitty(uint8_t col, uint8_t line) {
  // Images credit j-inc(/James Incandenza) and pixelbenny.
  // Credit to obosob for initial animation approach.
  // heavily modified by drashna because he's a glutton for punishment

  // clang-format off
    static const char PROGMEM animation[4][OLED_ANIM_MAX_FRAMES][OLED_ANIM_ROWS][OLED_ANIM_SIZE] = {
        // sleep frames
        {
            {
                { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0xa8, 0x48, 0xa8, 0x18, 0x08, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
                { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x03, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 0x80, 0x44, 0x84, 0x06, 0x05, 0x04, 0x80, 0x40, 0x20, 0x10, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
                { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x20, 0x18, 0x04, 0x04, 0x02, 0x7a, 0x86, 0x01, 0x80, 0x80, 0x01, 0x03, 0x05, 0x07, 0x01, 0x00, 0x00, 0x80, 0x83, 0x45, 0xfa, 0x3c, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
                { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0x10, 0x10, 0x10, 0x10, 0x10, 0x33, 0x24, 0x28, 0x28, 0x29, 0x29, 0x29, 0x3a, 0x18, 0x1c, 0x39, 0x24, 0x24, 0x3a, 0x2d, 0x26, 0x31, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00 }
            },
            {
                { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
                { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x22, 0x22, 0x3a, 0x2a, 0x26, 0x22, 0x80, 0xc0, 0x80, 0x00, 0x24, 0x34, 0x2c, 0xe4, 0x60, 0x10, 0x70, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
                { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x38, 0x04, 0x02, 0x02, 0x01, 0x79, 0x87, 0x01, 0x80, 0x81, 0x83, 0x05, 0x05, 0x03, 0x01, 0x00, 0x00, 0x80, 0x43, 0x05, 0xfa, 0x3c, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
                { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0x10, 0x10, 0x10, 0x10, 0x10, 0x33, 0x24, 0x28, 0x28, 0x28, 0x29, 0x29, 0x3a, 0x18, 0x1c, 0x39, 0x24, 0x24, 0x3a, 0x2d, 0x26, 0x31, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00 }
            }
        },
        // wake frames
        {
            {
                { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x30, 0x08, 0x10, 0x60, 0x80, 0x00, 0x80, 0x60, 0x10, 0x08, 0x30, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
                { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x80, 0x40, 0x40, 0x5c, 0x00, 0x01, 0x41, 0x01, 0x00, 0x5c, 0x40, 0x40, 0x80, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
                { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x80, 0xe1, 0x12, 0x0a, 0x06, 0x00, 0x80, 0x00, 0x06, 0x0a, 0x12, 0xe1, 0x80, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
                { 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x1f, 0x14, 0x14, 0x10, 0x10, 0x11, 0x1f, 0x10, 0x10, 0x18, 0x0f, 0x18, 0x10, 0x10, 0x1f, 0x11, 0x10, 0x10, 0x14, 0x14, 0x1f, 0x1c, 0x14, 0x14, 0x14, 0x08, 0x00, 0x00, 0x00, 0x00 }
            },
            {
                { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x30, 0x08, 0x10, 0x60, 0x80, 0x00, 0x80, 0x60, 0x10, 0x08, 0x30, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
                { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x90, 0x12, 0x0a, 0x02, 0xf4, 0x09, 0x0d, 0xf1, 0x04, 0x02, 0x0a, 0x12, 0x90, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
                { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x80, 0xe1, 0x12, 0x0a, 0x06, 0x01, 0x81, 0x00, 0x06, 0x0a, 0x12, 0xe1, 0x80, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
                { 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x1f, 0x14, 0x14, 0x10, 0x10, 0x11, 0x1f, 0x10, 0x10, 0x18, 0x0f, 0x18, 0x10, 0x10, 0x1f, 0x11, 0x10, 0x10, 0x14, 0x14, 0x1f, 0x1c, 0x14, 0x14, 0x14, 0x08, 0x00, 0x00, 0x00, 0x00 }
            }
        },
        // kaki frames
        {
            {
                { 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x40, 0x40, 0x80, 0x80, 0x80, 0x00, 0xfc, 0x84, 0x08, 0x08, 0x10, 0x20, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
                { 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x1e, 0x60, 0x80, 0x00, 0x00, 0x91, 0xa1, 0x80, 0x00, 0x00, 0x22, 0x84, 0x40, 0x50, 0x48, 0xc1, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
                { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x41, 0x82, 0xe2, 0x12, 0x0a, 0x06, 0x00, 0x80, 0x88, 0x4f, 0x02, 0x22, 0xe2, 0x9f, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
                { 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x1f, 0x14, 0x14, 0x10, 0x10, 0x11, 0x1f, 0x10, 0x10, 0x18, 0x0f, 0x18, 0x14, 0x10, 0x10, 0x10, 0x10, 0x10, 0x14, 0x14, 0x1f, 0x1a, 0x0a, 0x0a, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00 }
            },
            {
                { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x10, 0x20, 0x20, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
                { 0x00, 0x00, 0x06, 0x1a, 0x22, 0xc2, 0x04, 0x04, 0x04, 0x07, 0x00, 0xc0, 0x20, 0x10, 0x80, 0x80, 0x01, 0x01, 0x02, 0xfc, 0xfe, 0x02, 0x3c, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
                { 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x0d, 0x8d, 0x55, 0x50, 0x94, 0xf0, 0x10, 0x09, 0x08, 0x00, 0x80, 0x00, 0x06, 0x09, 0x1b, 0xee, 0x00, 0x00, 0x00, 0x00, 0x81, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
                { 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x1f, 0x14, 0x14, 0x10, 0x10, 0x11, 0x1f, 0x10, 0x10, 0x18, 0x0f, 0x18, 0x10, 0x10, 0x1f, 0x19, 0x18, 0x1c, 0x14, 0x16, 0x15, 0x14, 0x14, 0x14, 0x14, 0x08, 0x00, 0x00, 0x00, 0x00 }
            },
            {
                { 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
                { 0x00, 0x00, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x01, 0x02, 0x04, 0x04, 0x03, 0x80, 0x40, 0x40, 0x20, 0x00, 0x01, 0x02, 0x8c, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
                { 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x0d, 0x8d, 0x55, 0x50, 0x94, 0xf0, 0x10, 0x0a, 0x0e, 0x1d, 0x95, 0x24, 0x24, 0x27, 0x13, 0xe1, 0x01, 0x01, 0x01, 0x01, 0x02, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
                { 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x1f, 0x14, 0x14, 0x10, 0x10, 0x11, 0x1f, 0x10, 0x10, 0x18, 0x0f, 0x18, 0x10, 0x10, 0x1f, 0x19, 0x18, 0x1c, 0x14, 0x14, 0x17, 0x14, 0x14, 0x14, 0x14, 0x08, 0x00, 0x00, 0x00, 0x00 }
            }
        },
        // rtogi frames
        {
            {
                { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x20, 0x10, 0x10, 0x08, 0x04, 0x02, 0x01, 0x0f, 0x90, 0x10, 0x20, 0xf0, 0xf8, 0xf8, 0x00, 0x00, 0x00, 0x00 },
                { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x10, 0x08, 0x08, 0x08, 0x08, 0x48, 0x47, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x88, 0xc7, 0xc4, 0x62, 0x23, 0x11, 0x3f, 0x00, 0x00, 0x00, 0x00 },
                { 0x80, 0x40, 0x20, 0x10, 0x88, 0xcc, 0x43, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xc0, 0x80, 0x80, 0xc0, 0xe1, 0xfe, 0xb8, 0x88, 0x0c, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
                { 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x06, 0x04, 0x04, 0x04, 0x04, 0x05, 0x04, 0x04, 0x04, 0x07, 0x07, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }
            },
            {
                { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x20, 0x10, 0x10, 0x08, 0x04, 0x02, 0x01, 0x1f, 0xa0, 0x20, 0x40, 0x80, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00 },
                { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x10, 0x08, 0x08, 0x08, 0x08, 0x48, 0x47, 0x88, 0x00, 0x00, 0x00, 0x00, 0x24, 0x24, 0x28, 0x6b, 0x40, 0xa0, 0x99, 0x86, 0xff, 0x00, 0x00, 0x00, 0x00 },
                { 0x0f, 0x11, 0x22, 0x44, 0x48, 0x4c, 0x43, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xc0, 0x80, 0x80, 0xc0, 0xe1, 0xfe, 0xb8, 0x88, 0x0c, 0x04, 0x06, 0x06, 0x06, 0x0e, 0x0e, 0x06, 0x01, 0x00, 0x00, 0x00, 0x00 },
                { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x06, 0x04, 0x04, 0x04, 0x04, 0x05, 0x04, 0x04, 0x04, 0x07, 0x07, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }
            }
        }
    };
  // clang-format on

  for (uint8_t i = 0; i < 4; i++) {
    oled_set_cursor(col, line + i);
    oled_write_raw_P(animation[animation_type][animation_frame][i],
                     OLED_ANIM_SIZE);
  }
}

uint32_t kitty_animation_phases(uint32_t triger_time, void *cb_arg) {
  static uint32_t anim_frame_duration = 500;
#ifdef WPM_ENABLE
  if (get_current_wpm() <= OLED_SLEEP_SPEED) {
#endif
    animation_frame = (animation_frame + 1) % OLED_SLEEP_FRAMES;
    animation_type = 0;
    anim_frame_duration = 500;
#ifdef WPM_ENABLE
  } else if (get_current_wpm() > OLED_WAKE_SPEED) {
    animation_frame = (animation_frame + 1) % OLED_WAKE_FRAMES;
    animation_type = 1;
    anim_frame_duration = 800;
  } else if (get_current_wpm() >= OLED_KAKI_SPEED) {
    animation_frame = (animation_frame + 1) % OLED_KAKI_FRAMES;
    animation_type = 2;
    anim_frame_duration = 500;
  }
#endif
  return anim_frame_duration;
}

static void render_wpm(uint8_t padding, uint8_t col, uint8_t line) {
#ifdef WPM_ENABLE
  oled_set_cursor(col, line);
  oled_write_P(PSTR(OLED_RENDER_WPM_COUNTER), false);
  if (padding) {
    for (uint8_t n = padding; n > 0; n--) {
      oled_write_P(PSTR(" "), false);
    }
  }
  oled_write(get_u8_str(get_current_wpm(), ' '), false);
#endif
}

//=============  USER CONFIG PARAMS  ===============
// wpm graph originally designed by john-ezra

// for 128x128:
// max_lines_graph          = 54;
// vertical_offset          = 64;
// for 128x64:
// max_lines_graph          = 64;
// vertical_offset          = 0;

static void render_wpm_graph(uint8_t max_lines_graph, uint8_t vertical_offset) {
#ifdef WPM_ENABLE
  static uint16_t timer = 0;
  static uint8_t x = OLED_DISPLAY_HEIGHT - 1;
  uint8_t currwpm = get_current_wpm();
  float max_wpm = OLED_WPM_GRAPH_MAX_WPM;

  if (timer_elapsed(timer) >
      OLED_WPM_GRAPH_REFRESH_INTERVAL) {  // check if it's been long enough
                                          // before refreshing graph
    x = (max_lines_graph - 1) -
        ((currwpm / max_wpm) *
         (max_lines_graph - 1));  // main calculation to plot graph line
    for (uint8_t i = 0; i <= OLED_WPM_GRAPH_GRAPH_LINE_THICKNESS - 1;
         i++) {  // first draw actual value line
      oled_write_pixel(3, x + i + vertical_offset, true);
    }
#ifdef OLED_WPM_GRAPH_VERTICAL_LINE
    static uint8_t vert_count = 0;
    if (vert_count == OLED_WPM_GRAPH_VERTCAL_LINE_INTERVAL) {
      vert_count = 0;
      while (x <= (max_lines_graph - 1)) {
        oled_write_pixel(3, x + vertical_offset, true);
        x++;
      }
    } else {
      for (uint8_t i = (max_lines_graph - 1); i > x; i--) {
        if (i % OLED_WPM_GRAPH_AREA_FILL_INTERVAL == 0) {
          oled_write_pixel(3, i + vertical_offset, true);
        }
      }
      vert_count++;
    }
#else
    for (int i = (max_lines_graph - 1); i > x; i--) {
      if (i % OLED_WPM_GRAPH_AREA_FILL_INTERVAL == 0) {
        oled_write_pixel(3, i + vertical_offset, true);
      }
    }
#endif
#include <math.h>
    uint8_t y_start = ceil(vertical_offset / 8);
    uint8_t y_length = y_start + ceil(max_lines_graph / 8);
    oled_pan_section(false, y_start, y_length, 3,
                     125);  // then move the entire graph one pixel to the right
    timer = timer_read();   // refresh the timer for the next iteration
  }
#endif
}

#if defined(POINTING_DEVICE_ENABLE)
void render_pointing_dpi_status(uint16_t cpi, uint8_t padding, uint8_t col,
                                uint8_t line) {
  oled_set_cursor(col, line);
  oled_write_P(PSTR("CPI:"), false);
  if (padding) {
    for (uint8_t n = padding - 1; n > 0; n--) {
      oled_write_P(PSTR(" "), false);
    }
  }

  oled_write(get_u16_str(cpi, ' '), false);
}
#endif

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  kittoken = defer_exec(3000, kitty_animation_phases, NULL);
  splash_screen_timer = timer_read();

  oled_clear();
  oled_render();
  return rotation;
}

bool oled_task_user(void) {
  static bool display_splash_screen = true;

#if defined(OLED_DISPLAY_128X128)
  oled_render_large_display(true);
#endif

  if (display_splash_screen) {
    if (timer_elapsed(splash_screen_timer) > 3000) {
      display_splash_screen = false;
      oled_clear();
    }
    render_logo();
  } else {
    // Layer status.
    layer_state_t current_layer = get_highest_layer(layer_state);
    oled_write_P(PSTR("NAV"), /* inverted = */ current_layer == _MOTION);
    oled_write_P(PSTR(" "), /* inverted = */ false);
    oled_write_P(PSTR("SYM"), /* inverted = */ current_layer == _SYMBOL);
    oled_write_P(PSTR(" "), /* inverted = */ false);
    oled_write_P(PSTR("NUM"), /* inverted = */ current_layer == _NUMBER);
    oled_write_P(PSTR(" "), /* inverted = */ false);
    oled_write_P(PSTR("SYS"), /* inverted = */ current_layer == _SYSTEM);
    oled_write_P("\n", false);

    oled_write_P(PSTR("Caps:   "), /* inverted = */ false);
    oled_write_P(PSTR("OSM"),
                 /* inverted = */ get_oneshot_mods() & MOD_MASK_SHIFT);
    oled_write_P(PSTR(" "), /* inverted = */ false);
    oled_write_P(PSTR("WRD"), /* inverted = */ is_caps_word_on());
    oled_write_P(PSTR(" "), /* inverted = */ false);
    oled_write_P(PSTR("LCK"),
                 /* inverted = */ get_oneshot_locked_mods() & MOD_MASK_SHIFT);

    oled_write_P("\n\n", false);
#ifdef POINTING_DEVICE_ENABLE
    oled_write_P("\n  DPI: ", false);
    const int8_t default_dpi = (dilemma_get_pointer_default_dpi() - 400) / 200;
    for (int i = 0; i < default_dpi; ++i) {
      oled_write_P(" ", /* inverted = */ true);
    }
    for (int i = default_dpi; i < 12; ++i) {
      oled_write_P("_", /* inverted = */ false);
    }

    oled_write_P("\n+ DPI: ", false);
    const int8_t sniping_dpi = (dilemma_get_pointer_sniping_dpi() - 200) / 100;
    for (int i = 0; i < sniping_dpi; ++i) {
      oled_write_P(" ", /* inverted = */ true);
    }
    for (int i = sniping_dpi; i < 4; ++i) {
      oled_write_P("_", /* inverted = */ false);
    }
    oled_write_P("\n", false);
#endif

    render_wpm_graph(54, 64);
    render_wpm(1, 7, 15);
    render_kitty(0, 12);
  }

  return false;
}
#endif
