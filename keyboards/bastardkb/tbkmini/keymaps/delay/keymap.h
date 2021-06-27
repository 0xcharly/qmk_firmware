#pragma once

#include QMK_KEYBOARD_H

enum layer_names {
    BASE,
    DEVR,
    NAVR,
    NUMR,
    SYMR,
};

enum custom_keycodes {
  // Custom version of these keycode that don't produce shifted symbols.
  C_BSLSH = SAFE_RANGE,
  C_COMMA,
  C_DOT,
  C_GRAVE,
  C_LBRC,
  C_RBRC,
  C_SCLN,
  C_SLASH,
};

// Home row mods.
#define C_GUI_A LGUI_T(KC_A)
#define C_ALT_O LALT_T(KC_O)
#define C_CTL_E LCTL_T(KC_E)
#define C_SFT_U LSFT_T(KC_U)

#define C_SFT_H RSFT_T(KC_H)
#define C_CTL_T RCTL_T(KC_T)
#define C_ALT_N LALT_T(KC_N)
#define C_GUI_S RGUI_T(KC_S)

// Layers.
#define TAB_NAV LT(NAVR, KC_TAB)
#define BSP_DEV LT(DEVR, KC_BSPC)
#define SPC_NUM LT(NUMR, KC_SPC)
#define ENT_SYM LT(SYMR, KC_ENT)

// Tap dances.
#define C_OSSFT OSM(MOD_LSFT)

// Custom NAV keycodes, for Apple macOS.
#define U_CUT   LCMD(KC_X)
#define U_COPY  LCMD(KC_C)
#define U_PASTE LCMD(KC_V)

// Spaces navigation.
#define C_SCR_L LGUI(KC_LEFT)
#define C_SCR_R LGUI(KC_RIGHT)
