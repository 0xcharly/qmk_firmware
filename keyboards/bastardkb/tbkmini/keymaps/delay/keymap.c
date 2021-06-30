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
       XXXXXXX, C_RESET, EEP_RST, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, KC_LCBR, KC_AMPR, KC_RCBR, KC_PIPE, XXXXXXX,
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
       XXXXXXX, XXXXXXX, U_PASTE,  U_COPY,   U_CUT, XXXXXXX,   XXXXXXX,   U_CUT,  U_COPY, U_PASTE, XXXXXXX, XXXXXXX,
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
       XXXXXXX, KC_PEQL,    KC_7,    KC_8,    KC_9, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
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
       XXXXXXX, C_GRAVE,   KC_LT, C_SLASH,   KC_GT, KC_PERC,   XXXXXXX, XXXXXXX, XXXXXXX, EEP_RST, C_RESET, XXXXXXX,
  // |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
       XXXXXXX, KC_COLN,  C_LBRC, KC_UNDS,  C_RBRC, XXXXXXX,   XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
  // |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
       XXXXXXX, XXXXXXX, KC_EXLM,   KC_AT, KC_HASH, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────╯
                                  KC_BSPC, KC_MINS, XXXXXXX,   XXXXXXX, XXXXXXX, ENT_SYM
  //                            ╰──────────────────────────╯ ╰──────────────────────────╯
  ),
};

#ifndef NO_SHIFT_CODE
#define NO_SHIFT_CODE(keycode) \
{ \
  if (record->event.pressed) { \
    if (get_mods() & MOD_MASK_SHIFT) { \
      const uint8_t mods = get_mods() & MOD_MASK_SHIFT; \
      del_mods(mods); \
      register_code(keycode); \
      add_mods(mods); \
    } else { \
      register_code(keycode); \
    } \
  } \
  break; \
}
#endif // NO_SHIFT_CODE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case C_BSLSH:
      NO_SHIFT_CODE(KC_BSLASH);
    case C_COMMA:
      NO_SHIFT_CODE(KC_COMMA);
    case C_DOT:
      NO_SHIFT_CODE(KC_DOT);
    case C_GRAVE:
      NO_SHIFT_CODE(KC_GRAVE);
    case C_LBRC:
      NO_SHIFT_CODE(KC_LBRC);
    case C_RBRC:
      NO_SHIFT_CODE(KC_RBRC);
    case C_RESET: {
      rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
      rgblight_sethsv_noeeprom(0, 255, RGBLIGHT_LIMIT_VAL);
      reset_keyboard();
      break;
    }
    case C_SCLN:
      NO_SHIFT_CODE(KC_SCOLON);
    case C_SLASH:
      NO_SHIFT_CODE(KC_SLASH);
  }
  return true;
};

#ifndef UNREGISTER_CODE_IF_PRESSED
#define UNREGISTER_CODE_IF_PRESSED(keycode) { \
  if (!record->event.pressed) { \
    unregister_code(keycode); \
  } \
  break; \
}
#endif // UNREGISTER_CODE_IF_PRESSED

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case C_BSLSH:
      UNREGISTER_CODE_IF_PRESSED(KC_BSLASH);
    case C_COMMA:
      UNREGISTER_CODE_IF_PRESSED(KC_COMMA);
    case C_DOT:
      UNREGISTER_CODE_IF_PRESSED(KC_DOT);
    case C_GRAVE:
      UNREGISTER_CODE_IF_PRESSED(KC_GRAVE);
    case C_LBRC:
      UNREGISTER_CODE_IF_PRESSED(KC_LBRC);
    case C_RBRC:
      UNREGISTER_CODE_IF_PRESSED(KC_RBRC);
    case C_SCLN:
      UNREGISTER_CODE_IF_PRESSED(KC_SCOLON);
    case C_SLASH:
      UNREGISTER_CODE_IF_PRESSED(KC_SLASH);
  }
}

void oneshot_locked_mods_changed_user(uint8_t mods) {
  if (mods & MOD_MASK_SHIFT) {
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_sethsv_noeeprom(155, 80, RGBLIGHT_LIMIT_VAL);
  } else if (!mods) {
    rgblight_reload_from_eeprom(); // Load default mode.
  }
}

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
void keyboard_post_init_user(void) {
}
#endif

void eeconfig_init_user(void) {
  rgblight_mode(RGBLIGHT_DEFAULT_MODE);
  rgblight_set_speed(RGBLIGHT_DEFAULT_SPD);
}
