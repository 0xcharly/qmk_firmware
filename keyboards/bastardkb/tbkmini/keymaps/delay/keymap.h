#pragma once

#include QMK_KEYBOARD_H

enum layer_names {
    L_DVORAK,
    L_NUM,
    L_SYM,
    L_NAV,
    L_MEDIA,
    L_RGB,
};

// home row mods
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

// layers
#define C_TAB_1 LT(1, KC_TAB)
#define C_SPC_2 LT(2, KC_SPC)
#define C_BSP_3 LT(3, KC_BSPC)
#define C_ESC_4 LT(4, KC_ESC)

// tap dances
#define C_OSSFT OSM(MOD_LSFT)
