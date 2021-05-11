#pragma once

#include QMK_KEYBOARD_H

enum layer_names {
    BASE,
    NAVR,
    DEVR,
    MEDR,
    NUMR,
    SYMR,
    FUNR,
};

// Home row mods.
#define C_ALT_A LALT_T(KC_A)
#define C_CTL_E LCTL_T(KC_E)
#define C_GUI_O LGUI_T(KC_O)
#define C_SFT_U LSFT_T(KC_U)

#define C_SFT_H RSFT_T(KC_H)
#define C_GUI_N RGUI_T(KC_N)
#define C_CTL_T RCTL_T(KC_T)
#define C_ALT_S LALT_T(KC_S)

#define C_SCR_L LGUI(KC_LEFT)
#define C_SCR_R LGUI(KC_RIGHT)
#define C_LAN_P KC_F18
#define C_LAN_N KC_F19

// Layers.
#define TAB_NAV LT(NAVR, KC_TAB)
#define BSP_DEV LT(DEVR, KC_BSPC)
#define ESC_MED LT(MEDR, KC_ESC)
#define SPC_NUM LT(NUMR, KC_SPC)
#define ENT_SYM LT(SYMR, KC_ENT)

// Tap dances.
#define C_OSSFT OSM(MOD_LSFT)

// Custom NAVR, for Apple macOS.
#define U_UNDO  LCMD(KC_Z)
#define U_REDO  SCMD(KC_Z)
#define U_CUT   LCMD(KC_X)
#define U_COPY  LCMD(KC_C)
#define U_PASTE LCMD(KC_V)
