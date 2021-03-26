#include "keymap.h"
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [L_DVORAK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        MO(5), KC_QUOT, KC_COMM,  KC_DOT,    KC_P,    KC_Y,                         KC_F,    KC_G,    KC_C,    KC_R,    KC_L, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, C_ALT_A, C_GUI_O, C_CTL_E, C_SFT_U,    KC_I,                         KC_D, C_SFT_H, C_CTL_T, C_GUI_N, C_ALT_S, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_SCLN,    KC_Q,    KC_J,    KC_K,    KC_X,                         KC_B,    KC_M,    KC_W,    KC_V,    KC_Z, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          C_BSP_3, C_TAB_1, C_ESC_4,    C_OSSFT, C_SPC_2,  KC_ENT
                                      //`--------------------------'  `--------------------------'

  ),

  [L_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX,                      XXXXXXX,    KC_7,    KC_8,    KC_9, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, KC_PPLS, KC_PAST, XXXXXXX,                      XXXXXXX,    KC_4,    KC_5,    KC_6, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, KC_MINS, KC_SLSH, XXXXXXX,                      XXXXXXX,    KC_1,    KC_2,    KC_3, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, C_TAB_1, _______,    KC_PERC,    KC_0,  KC_EQL
                                      //`--------------------------'  `--------------------------'
  ),

  [L_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, KC_PIPE, KC_ASTR, KC_AMPR, KC_PLUS,                      KC_MINS, KC_LBRC, KC_CIRC, KC_RBRC, KC_QUES, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_TILD, KC_EXLM,  KC_EQL,   KC_AT,                      KC_UNDS, KC_LPRN, KC_DLR,  KC_RPRN, KC_MINS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX,   KC_LT,   KC_GT,  KC_GRV, KC_PERC,                      KC_BSLS, KC_LCBR, KC_HASH, KC_RCBR, KC_SLSH, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, C_SPC_2, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [L_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, KC_PGDN, KC_PGUP, XXXXXXX,                      XXXXXXX, KC_HOME,  KC_END, XXXXXXX, XXXXXXX, XXXXXXX,
  //|---------+--------+-------+--------+--------|--------+                    |--------+--------|--------+-------+--------+--------+-
      XXXXXXX, XXXXXXX, XXXXXXX, KC_DOWN,   KC_UP, XXXXXXX,                      XXXXXXX, KC_LEFT, KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX,
  //|---------+--------|-------+--------+ -------+--------+-                   |--------+--------|--------+-------+--------+--------+-
      XXXXXXX, XXXXXXX, XXXXXXX, C_SCR_L, C_SCR_R, XXXXXXX,                      XXXXXXX, C_SCR_L, C_SCR_R, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          C_BSP_3, _______, _______,   _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [L_MEDIA] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, C_LAN_P, C_LAN_N, XXXXXXX,                      XXXXXXX, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, C_ESC_4,    KC_MPRV, KC_MPLY, KC_MNXT
                                      //`--------------------------'  `--------------------------'
  ),

  [L_RGB] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        MO(5),   RESET, EEP_RST, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, RGB_SPD, RGB_SPI, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      RGB_SAI, RGB_VAD, RGB_VAI, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      RGB_SAD, RGB_HUD, RGB_HUI, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,   RGB_RMOD, RGB_TOG, RGB_MOD
                                      //`--------------------------'  `--------------------------'
  )
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case C_BSP_3:
    case C_TAB_1:
    case C_ESC_4:
      return 175;
  default:
      return TAPPING_TERM;
  }
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
  return keycode != C_OSSFT && keycode != C_BSP_3;
}

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
  return keycode == C_SPC_2;
}
