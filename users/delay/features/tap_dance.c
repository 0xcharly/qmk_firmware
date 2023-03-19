/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
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

#include "quantum.h"
#include "tap_dance.h"

static td_state_t get_current_state(tap_dance_state_t *state) {
    if (state->count == 1) {
        return state->interrupted || !state->pressed ? TD_SINGLE_TAP : TD_SINGLE_HOLD;
    }
    if (state->count == 2) {
        return state->interrupted || !state->pressed ? TD_DOUBLE_TAP : TD_DOUBLE_HOLD;
    }
    if (state->count == 3) {
        return state->interrupted || !state->pressed ? TD_TRIPLE_TAP : TD_TRIPLE_HOLD;
    }
    return TD_UNKNOWN;
}

void oneshot_shift_td_on_dance_finished(tap_dance_state_t *state, void *user_data) {
    oneshot_shift_td_state_t *const oneshot_shift_td_state = user_data;
    oneshot_shift_td_state->td_state = get_current_state(state);

    const uint8_t mod = MOD_LSFT;
    switch (oneshot_shift_td_state->td_state) {
        case TD_SINGLE_TAP:
            if (get_oneshot_locked_mods() & mod) {
                clear_oneshot_locked_mods();
                clear_oneshot_mods();
                del_mods(mod);
            } else {
                set_oneshot_mods(mod);
            }
            break;
        case TD_SINGLE_HOLD:
            add_mods(mod);
            break;
        case TD_DOUBLE_TAP:
        case TD_DOUBLE_HOLD:
            clear_oneshot_mods();
            caps_word_on();
            break;
        case TD_TRIPLE_TAP:
        case TD_TRIPLE_HOLD:
            clear_oneshot_mods();
            set_oneshot_locked_mods(mod);
            add_mods(mod);
            break;
        default:
            break;
    }
}

void oneshot_shift_td_on_dance_reset(tap_dance_state_t *state, void *user_data) {
    oneshot_shift_td_state_t *const oneshot_shift_td_state = user_data;
    if (oneshot_shift_td_state->td_state == TD_SINGLE_HOLD) {
        del_mods(MOD_LSFT);
    }
    oneshot_shift_td_state->td_state = TD_NONE;
}

void tap_dance_layer_mod_finished(tap_dance_state_t *state, void *user_data) {
    oneshot_layer_mod_td_state_t *const data = user_data;
    data->td_state = get_current_state(state);

    switch (data->td_state) {
        case TD_SINGLE_TAP:
            if (IS_LAYER_ON(data->layer)) {
                reset_oneshot_layer();
            } else {
                set_oneshot_layer(data->layer, ONESHOT_START);
            }
            break;
        case TD_SINGLE_HOLD:
            add_mods(data->mod);
            break;
        default:
            break;
    }
}

void tap_dance_layer_mod_reset(tap_dance_state_t *state, void *user_data) {
    oneshot_layer_mod_td_state_t *const data = user_data;
    if (data->td_state == TD_SINGLE_TAP) {
        clear_oneshot_layer_state(ONESHOT_PRESSED);
    } else if (data->td_state == TD_SINGLE_HOLD) {
        // TODO(delay): add support for toggling the layer if no other key has
        // been tapped in ~200ms.
        del_mods(data->mod);
    }
    data->td_state = TD_NONE;
}
