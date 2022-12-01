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

#include QMK_KEYBOARD_H
#include "users/delay/delay.h"

#define LAYOUT_charybdis_3x5_delay(...) LAYOUT_split_3x5_3(__VA_ARGS__)
#define DRAGSCROLL_PADDING 6

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_charybdis_3x5_delay(DVORAK_split_3x5_3),
  [_NAVL] = LAYOUT_charybdis_3x5_delay(NAVL_split_3x5_2),
  [_NAVR] = LAYOUT_charybdis_3x5_delay(NAVR_split_3x5_2),
  [_SYML] = LAYOUT_charybdis_3x5_delay(SYML_split_3x5_2),
  [_SYMR] = LAYOUT_charybdis_3x5_delay(SYMR_split_3x5_2),
  [_NUM] = LAYOUT_charybdis_3x5_delay(NUM_split_3x5_3),
  [_SPEC] = LAYOUT_charybdis_3x5_delay(SPEC_split_3x5_3),
};
// clang-format on

void keyboard_post_init_keymap(void) {
    pointing_device_set_cpi_on_side(true, 100);  // Left side, drag-scroll.
    pointing_device_set_cpi_on_side(false, 800); // Right side, pointer motion.
}

report_mouse_t pointing_device_task_combined_user(report_mouse_t left_report, report_mouse_t right_report) {
    static int16_t scroll_buffer_x = 0;
    static int16_t scroll_buffer_y = 0;
    scroll_buffer_x -= left_report.x;
    scroll_buffer_y -= left_report.y;
    left_report.x = 0;
    left_report.y = 0;
    left_report.h = 0;
    left_report.v = 0;
    if (abs(scroll_buffer_x) > DRAGSCROLL_PADDING) {
        left_report.h   = scroll_buffer_x > 0 ? 1 : -1;
        scroll_buffer_x = 0;
    }
    if (abs(scroll_buffer_y) > DRAGSCROLL_PADDING) {
        left_report.v   = scroll_buffer_y > 0 ? 1 : -1;
        scroll_buffer_y = 0;
    }
#ifdef POINTING_DEVICE_INVERT_X
    right_report.x = -right_report.x;
#endif // POINTING_DEVICE_INVERT_X
#ifdef POINTING_DEVICE_INVERT_Y
    right_report.y = -right_report.y;
#endif // POINTING_DEVICE_INVERT_Y
    return pointing_device_combine_reports(left_report, right_report);
}
