#include "keymap.h"
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT_split_3x6_3(
  // ╭─────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────╮
       XXXXXXX, KC_QUOT, C_COMMA,   C_DOT,    KC_P,    KC_Y,      KC_F,    KC_G,    KC_C,    KC_R,    KC_L, XXXXXXX,
  // |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
       XXXXXXX, C_GUI_A, C_ALT_O, C_CTL_E, C_SFT_U,    KC_I,      KC_D, C_SFT_H, C_CTL_T, C_ALT_N, C_GUI_S, XXXXXXX,
  // |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
       XXXXXXX,  C_SCLN,    KC_Q,    KC_J,    KC_K,    KC_X,      KC_B,    KC_M,    KC_W,    KC_V,    KC_Z, XXXXXXX,
  // ╰─────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────╯
                                  BSP_DEV, TAB_NAV,  KC_ESC,   C_OSSFT, SPC_NUM, ENT_SYM
  //                            ╰──────────────────────────╯ ╰──────────────────────────╯
  ),

  [DEVR] = LAYOUT_split_3x6_3(
  // ╭─────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────╮
       XXXXXXX,   RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, KC_LCBR, KC_AMPR, KC_RCBR, KC_PIPE, XXXXXXX,
  // |--------+--------+--------+--------+--------|--------| |--------+--------+--------+--------+--------+--------|
       XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,   KC_CIRC, KC_LPRN, KC_ASTR, KC_RPRN,  KC_DLR, XXXXXXX,
  // |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   C_BSLSH,   C_DOT, C_SLASH, KC_TILD, KC_QUES, XXXXXXX,
  // ╰─────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────╯
                                  BSP_DEV, XXXXXXX, XXXXXXX,   XXXXXXX,  KC_SPC,  KC_ENT
  //                            ╰──────────────────────────╯ ╰──────────────────────────╯
  ),

  [NAVR] = LAYOUT_split_3x6_3(
  // ╭─────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────╮
       XXXXXXX,   RESET, U_PASTE,  U_COPY,   U_CUT, XXXXXXX,   XXXXXXX,   U_CUT,  U_COPY, U_PASTE, XXXXXXX, XXXXXXX,
  // |--------+--------+--------+--------+--------|--------| |--------+--------+--------+--------+--------+--------|
       XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,   XXXXXXX, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX,
  // |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
       XXXXXXX, XXXXXXX, XXXXXXX, C_SCR_L, C_SCR_R, XXXXXXX,   XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX,
  // ╰─────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────╯
                                  XXXXXXX, TAB_NAV, XXXXXXX,   XXXXXXX,  KC_SPC,  KC_ENT
  //                            ╰──────────────────────────╯ ╰──────────────────────────╯
  ),

  [NUMR] = LAYOUT_split_3x6_3(
  // ╭─────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────╮
       XXXXXXX, KC_PEQL,    KC_7,    KC_8,    KC_9, KC_PERC,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   RESET, XXXXXXX,
  // |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
       XXXXXXX, KC_PMNS,    KC_4,    KC_5,    KC_6, KC_PPLS,   XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
  // |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
       XXXXXXX, KC_PSLS,    KC_1,    KC_2,    KC_3, KC_PAST,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────╯
                                  KC_BSPC,    KC_0, KC_PDOT,   XXXXXXX, SPC_NUM, XXXXXXX
  //                            ╰──────────────────────────╯ ╰──────────────────────────╯
  ),

  [SYMR] = LAYOUT_split_3x6_3(
  // ╭─────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────╮
       XXXXXXX, C_GRAVE,   KC_LT, C_SLASH,   KC_GT, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   RESET, XXXXXXX,
  // |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
       XXXXXXX, KC_COLN,  C_LBRC, KC_UNDS,  C_RBRC, XXXXXXX,   XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
  // |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
       XXXXXXX, KC_PERC, KC_EXLM,   KC_AT, KC_HASH, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────╯
                                  KC_BSPC, KC_MINS, XXXXXXX,   XXXXXXX, XXXXXXX, ENT_SYM
  //                            ╰──────────────────────────╯ ╰──────────────────────────╯
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case C_BSLSH: {
      if (record->event.pressed) {
        register_code(KC_BSLASH);
      }
      break;
    }
    case C_COMMA: {
      if (record->event.pressed) {
        register_code(KC_COMMA);
      }
      break;
    }
    case C_DOT: {
      if (record->event.pressed) {
        register_code(KC_DOT);
      }
      break;
    }
    case C_GRAVE: {
      if (record->event.pressed) {
        register_code(KC_GRAVE);
      }
      break;
    }
    case C_LBRC: {
      if (record->event.pressed) {
        register_code(KC_LBRC);
      }
      break;
    }
    case C_RBRC: {
      if (record->event.pressed) {
        register_code(KC_RBRC);
      }
      break;
    }
    case C_SCLN: {
      if (record->event.pressed) {
        register_code(KC_SCOLON);
      }
      break;
    }
    case C_SLASH: {
      if (record->event.pressed) {
        register_code(KC_SLASH);
      }
      break;
    }
  }
  return true;
};

#if 0
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case BSP_DEV:
    case TAB_NAV:
    case ESC_MED:
    case SPC_NUM:
    case ENT_SYM:
      return 175;
    default:
      return TAPPING_TERM;
  }
}
#endif

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
  return keycode != C_OSSFT;
}

#if 0
bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
  return keycode == SPC_NUM;
}
#endif
