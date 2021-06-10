#include "keymap.h"
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT_split_3x6_3(
  // ╭─────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────╮
       XXXXXXX, KC_QUOT, KC_COMM,  KC_DOT,    KC_P,    KC_Y,      KC_F,    KC_G,    KC_C,    KC_R,    KC_L, XXXXXXX,
  // |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
       XXXXXXX, C_GUI_A, C_ALT_O, C_CTL_E, C_SFT_U,    KC_I,      KC_D, C_SFT_H, C_CTL_T, C_ALT_N, C_GUI_S, XXXXXXX,
  // |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
       XXXXXXX, KC_SCLN,    KC_Q,    KC_J,    KC_K,    KC_X,      KC_B,    KC_M,    KC_W,    KC_V,    KC_Z, XXXXXXX,
  // ╰─────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────╯
                                  BSP_DEV, TAB_NAV, ESC_MED,   C_OSSFT, SPC_NUM, ENT_SYM
  //                            ╰──────────────────────────╯ ╰──────────────────────────╯
  ),

  [NAVR] = LAYOUT_split_3x6_3(
  // ╭─────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────╮
       XXXXXXX,   RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    U_UNDO,   U_CUT,  U_COPY, U_PASTE,  U_REDO, XXXXXXX,
  // |---------+--------+-------+--------+--------|--------| |--------+--------+--------+--------+--------+--------|
       XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,   KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX, XXXXXXX,
  // |---------+--------+-------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
       XXXXXXX, XXXXXXX, KC_ALGR, C_SCR_L, C_SCR_R, XXXXXXX,   KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────╯
                                  XXXXXXX, TAB_NAV, XXXXXXX,   XXXXXXX,  KC_SPC,  KC_ENT
  //                            ╰──────────────────────────╯ ╰──────────────────────────╯
  ),

  [DEVR] = LAYOUT_split_3x6_3(
  // ╭─────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────╮
       XXXXXXX,   RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_EXLM, KC_LCBR, KC_HASH, KC_RCBR, KC_AMPR, XXXXXXX,
  // |---------+--------+-------+--------+--------|--------| |--------+--------+--------+--------+--------+--------|
       XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,   KC_UNDS, KC_LPRN, KC_ASTR, KC_RPRN, KC_MINS, XXXXXXX,
  // |---------+--------+-------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
       XXXXXXX, XXXXXXX, KC_ALGR, XXXXXXX, XXXXXXX, XXXXXXX,   KC_SLSH,   KC_LT, KC_TILD,   KC_GT, KC_QUES, XXXXXXX,
  // ╰─────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────╯
                                  BSP_DEV, XXXXXXX, XXXXXXX,  MO(FUNR),  KC_SPC,  KC_ENT
  //                            ╰──────────────────────────╯ ╰──────────────────────────╯
  ),

  [MEDR] = LAYOUT_split_3x6_3(
  // ╭─────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────╮
       XXXXXXX,   RESET, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG,   RGB_MOD, RGB_SPI, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX,
  // |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
       XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,   KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX, XXXXXXX,
  // |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
       XXXXXXX, XXXXXXX, KC_ALGR, C_LAN_P, C_LAN_N, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────╯
                                  XXXXXXX, XXXXXXX, ESC_MED,   KC_MSTP, KC_MPLY, KC_MUTE
  //                            ╰──────────────────────────╯ ╰──────────────────────────╯
  ),

  [NUMR] = LAYOUT_split_3x6_3(
  // ╭─────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────╮
       XXXXXXX, KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   RESET, XXXXXXX,
  // |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
       XXXXXXX, KC_SCLN,    KC_4,    KC_5,    KC_6, KC_PEQL,   XXXXXXX, KC_PPLS, KC_PAST, KC_PMNS, KC_PSLS, XXXXXXX,
  // |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
       XXXXXXX,  KC_GRV,    KC_1,    KC_2,    KC_3, KC_BSLS,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────╯
                                  KC_PDOT,    KC_0, KC_PMNS,   XXXXXXX, SPC_NUM, XXXXXXX
  //                            ╰──────────────────────────╯ ╰──────────────────────────╯
  ),

  [SYMR] = LAYOUT_split_3x6_3(
  // ╭─────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────╮
       XXXXXXX, KC_LBRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RBRC,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   RESET, XXXXXXX,
  // |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
       XXXXXXX, KC_COLN,  KC_DLR, KC_PERC, KC_CIRC, KC_PLUS,   XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
  // |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
       XXXXXXX, KC_TILD, KC_EXLM,   KC_AT, KC_HASH, KC_PIPE,   XXXXXXX, XXXXXXX, XXXXXXX, KC_ALGR, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────╯
                                  KC_BSPC,  KC_TAB, XXXXXXX,   XXXXXXX, XXXXXXX, ENT_SYM
  //                            ╰──────────────────────────╯ ╰──────────────────────────╯
  ),

  [FUNR] = LAYOUT_split_3x6_3(
  // ╭─────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────╮
       XXXXXXX,  KC_F12,   KC_F7,   KC_F8,   KC_F9, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   RESET, XXXXXXX,
  // |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
       XXXXXXX,  KC_F11,   KC_F4,   KC_F5,   KC_F6, XXXXXXX,   XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
  // |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
       XXXXXXX,  KC_F10,   KC_F1,   KC_F2,   KC_F3, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, KC_ALGR, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────╯
                                  KC_BSPC,  KC_TAB, XXXXXXX,  MO(FUNR), XXXXXXX, XXXXXXX
  //                            ╰──────────────────────────╯ ╰──────────────────────────╯
  ),

  #if 0
  [SYMR] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------. ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, KC_PIPE, KC_ASTR, KC_AMPR, KC_PLUS,   KC_MINS, KC_LBRC, KC_CIRC, KC_RBRC, KC_QUES, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_TILD, KC_EXLM,  KC_EQL,   KC_AT,   KC_UNDS, KC_LPRN, KC_DLR,  KC_RPRN, KC_MINS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX,   KC_LT,   KC_GT,  KC_GRV, KC_PERC,   KC_BSLS, KC_LCBR, KC_HASH, KC_RCBR, KC_SLSH, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
                                 _______, _______, _______,   _______, C_SPC_2, _______
  //                           `--------------------------' `--------------------------'
  )
  #endif
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
