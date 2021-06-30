#pragma once

/**
 * Forces NKRO during keyboard startup.
 */
#define FORCE_NKRO

/* RGB configuration. */

/**
 * The TBK Mini with per-key RGB has 21 LED on each split.
 */
#define RGBLIGHT_SPLIT { 21, 21 }

/**
 * Limit maximum brightness to keep power consumption reasonable, and avoid disconnects.
 */
#undef RGBLIGHT_LIMIT_VAL
#define RGBLIGHT_LIMIT_VAL 32

/**
 * Default RGB mode to use: relaxing mode.
 */
// Unload all animations but the rainbow swirl, reduces memory footprint.
#undef RGBLIGHT_ANIMATIONS
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL

#define RGBLIGHT_DEFAULT_SPD 0
#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT 4

/* One-Shot keys. */

/**
 * Tapping this number of times holds the key until tapped once again.
 * https://beta.docs.qmk.fm/using-qmk/software-features/one_shot_keys
 */
#define ONESHOT_TAP_TOGGLE 2

/**
 * Time (in ms) before the one shot key is released.
 * https://beta.docs.qmk.fm/using-qmk/software-features/one_shot_keys
 */
#define ONESHOT_TIMEOUT 1500

/* Tap dances. */

/**
 * If you have a lot of accidental mod activations, crank up the tapping term.
 * https://beta.docs.qmk.fm/using-qmk/software-features/tap_hold#tapping-term
 */
#define TAPPING_TERM 175

#if 0
/**
 * Customize the TAPPING_TERM for specific keys.
 */
#define TAPPING_TERM_PER_KEY
#endif

#if 0
/**
 * Send the tap anyway, even after TAPPING_TERM, if there was no other key
 * interruption between press and release.  Only enable for specific keys.
 */
#define RETRO_TAPPING_PER_KEY
#endif

/**
 * Disable auto-repeat when pressing key twice.
 * https://beta.docs.qmk.fm/using-qmk/software-features/tap_hold#tapping-force-hold
 */
#define TAPPING_FORCE_HOLD_PER_KEY

/*
 * Note that the following two flags, PERMISSIVE_HOLD and
 * IGNORE_MOD_TAP_INTERRUPT, behave differently when both enabled.
 */

/**
 * More permissive tap dances with Mod Tap keys.
 *   Mod🠗 K🠗 K🠕 Mod🠕 (within TAPPING_TERM) ➞ Mod+K
 * https://beta.docs.qmk.fm/using-qmk/software-features/tap_hold#permissive-hold
 */
#if 0
#define PERMISSIVE_HOLD
#endif

/**
 * More permissive tap dances with Mod Tap keys.
 *   Mod🠗 K🠗 Mod🠕 K🠕 (within TAPPING_TERM) ➞ Mod+K
 * https://beta.docs.qmk.fm/using-qmk/software-features/tap_hold#ignore-mod-tap-interrupt
 */
#define IGNORE_MOD_TAP_INTERRUPT
