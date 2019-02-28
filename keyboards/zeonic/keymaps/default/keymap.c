/* Copyright 2015-2017 Jack Humbert
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
#include "audio.h"

#define CTL_ALT LALT(KC_LCTL)

#define CTL_LFT LCTL(KC_LEFT)
#define CTL_RGT LCTL(KC_RGHT)

#define SCT_LFT LSFT(LCTL(KC_LEFT))
#define SCT_RGT LSFT(LCTL(KC_RGHT))

#define TMUX_P LCTL(KC_B)

#define SFT_ALT LSFT(KC_LALT)

#define ALT_TAB LALT(KC_TAB)

#define L1_BSPC LT(1, KC_BSPC)
#define L2_SPC  LT(2, KC_SPC)
#define L3_ENT  LT(3, KC_ENT)

#define SUPER_1 LGUI(KC_1)
#define SUPER_2 LGUI(KC_2)
#define SUPER_3 LGUI(KC_3)
#define SUPER_4 LGUI(KC_4)

#define SUPER_Z LGUI(KC_Z)
#define SUPER_X LGUI(KC_X)

enum custom_keycodes {
  MUP_ON,
  MUP_OFF = SAFE_RANGE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case MUP_ON:
                enable_polyphony();
                return false;
            case MUP_OFF:
                disable_polyphony();
                return false;
        }
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = LAYOUT( \
  KC_ESC,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,   \
  L1_BSPC, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC,  \
  KC_DEL,  KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,  KC_BSLS,  \
  SFT_ALT, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,  KC_NO,    \
  TMUX_P, KC_LCTL, KC_LGUI, KC_LALT, L2_SPC,      KC_SPC,          KC_ENT,        L3_ENT,  KC_RALT, KC_RGUI, KC_RCTL,  KC_APP    \
),

[1] = LAYOUT( \
  _______,  MU_TOG,   MU_MOD,   _______,  _______,  _______,  _______,  _______,  KC_F10,   KC_F11,   KC_F12,   _______,  _______,  _______,  \
  _______,  MUV_DE,   MUV_IN,   _______,  KC_UP,    _______,  _______,  _______,  KC_F7,    KC_F8,    KC_F9,    _______,  _______,  _______,  \
  _______,  MUP_OFF,  MUP_ON,   KC_LEFT,  KC_DOWN,  KC_RGHT,  _______,  _______,  KC_F4,    KC_F5,    KC_F6,    _______,  _______,  _______,  \
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_F1,    KC_F2,    KC_F3,    _______,  _______,  _______,  \
  RESET,    _______,  CTL_ALT,  _______,  _______,       _______,            _______,       _______,  _______,  _______,  _______,  _______   \
),

[2] = LAYOUT( \
  _______,  _______,  SUPER_1,  SUPER_2,  SUPER_3,  SUPER_4,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  \
  _______,  _______,  _______,  KC_HOME,  KC_UP,    KC_END,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  \
  _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  _______,  SCT_LFT,  CTL_LFT,  _______,  CTL_RGT,  SCT_RGT,  _______,  _______,  \
  _______,  _______,  SUPER_Z,  KC_PGUP,  SUPER_X,  KC_PGDN,  KC_LPRN,  KC_RPRN,  _______,  _______,  _______,  _______,  _______,  _______,  \
  _______,  _______,  _______,  _______,  _______,        KC_UNDS,          _______,        SUPER_X,  _______,  _______,  _______,  _______   \
),

[3] = LAYOUT( \
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_NLCK,  KC_PSLS,  KC_PAST,  KC_PMNS,  _______,  _______,  \
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_KP_7,  KC_KP_8,  KC_KP_9,  KC_PPLS,  _______,  _______,  \
  _______,  _______,  _______,  _______,  _______,  _______,  KC_LBRC,  KC_RBRC,  KC_KP_4,  KC_KP_5,  KC_KP_6,  KC_PPLS,  _______,  _______,  \
  _______,  _______,  _______,  _______,  _______,  _______,  KC_LCBR,  KC_RCBR,  KC_KP_1,  KC_KP_2,  KC_KP_3,  KC_PENT,  _______,  _______,  \
  _______,  _______,  _______,  _______,  SUPER_Z,        KC_UNDS,            KC_P0,        _______,  KC_PDOT,  KC_PENT,  _______,  _______   \
)

};

