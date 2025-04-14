/* Copyright 2017 Wunder
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

enum layer_names {
    _QW,
    _FN,
    _FNX,
    _FSMB
};

#define CTLL LCTL(KC_LEFT)
#define CTLR LCTL(KC_RIGHT)
#define LANG LSFT(KC_LALT)
#define SMTAB LT(_FSMB, KC_TAB)
#define ATAB LALT(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {



    [_QW] = LAYOUT_ortho_5x15( /* QWERTY */
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_MINS, KC_EQL,  KC_BSPC, KC_0,    KC_MINS, KC_EQL,
        SMTAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, KC_7,    KC_8,    KC_9,
        KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_4,    KC_5,    KC_6,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_1,    KC_2,    KC_3,
        KC_LCTL, KC_LGUI, KC_LPRN, KC_RPRN, MO(_FN), KC_SPC,  KC_ENT,  MO(_FN), KC_LBRC, KC_RBRC, KC_RALT, KC_APP,  MO(_FNX),KC_0,    KC_DOT
    ),
    [_FN] = LAYOUT_ortho_5x15( /* NAVIGATION AND NUMBERS */
        KC_GRV,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,  _______, KC_MINS, KC_EQL,
        ATAB,    _______, KC_HOME, KC_UP,   KC_END,  _______, _______, KC_7,    KC_8,    KC_9,    _______, _______, _______, _______, _______,
        KC_DEL,  CTLL,    KC_LEFT, KC_DOWN, KC_RIGHT,CTLR,    _______, KC_4,    KC_5,    KC_6,    _______, _______, _______, _______, _______,
        _______, _______, KC_PGUP, _______, KC_PGDN, _______, _______, KC_1,    KC_2,    KC_3,    _______, _______, _______, _______, _______,
        _______, _______, KC_VOLD, KC_VOLU, MO(_FNX),LANG,    LANG,    MO(_FNX),KC_0,    KC_DOT,  _______, KC_PSCR, _______, _______, _______
    ),
    [_FNX] = LAYOUT_ortho_5x15( /* FUNCTION */
        RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, KC_F10,  KC_F11,  KC_F12,
        _______, _______, _______, _______, _______, RGB_HUD, RGB_HUI, KC_F7,   KC_F8,   KC_F9,   _______, _______, KC_F7,   KC_F8,   KC_F9,
        KC_DEL,  _______, _______, _______, _______, RGB_SAD, RGB_SAI, KC_F4,   KC_F5,   KC_F6,   _______, _______, KC_F4,   KC_F5,   KC_F6,
        _______, _______, _______, _______, _______, RGB_VAD, RGB_VAI, KC_F1,   KC_F2,   KC_F3,   _______, _______, KC_F1,   KC_F2,   KC_F3,
        _______, _______, _______, RGB_TOG, _______, RGB_RMOD,RGB_MOD, _______, RGB_TOG, _______, _______, KC_PSCR, _______, _______, _______
    ),
    [_FSMB] = LAYOUT_ortho_5x15( /* SYMBOLS */
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
        _______, _______, _______, _______, _______, _______, _______, KC_AMPR, KC_ASTR, _______, _______, _______, _______, _______, _______, 
        _______, _______, _______, _______, _______, _______, _______, KC_DLR,  KC_PERC, KC_CIRC, _______, _______, _______, _______, _______, 
        _______, _______, _______, _______, _______, _______, _______, KC_EXLM, KC_AT,   KC_HASH, _______, _______, _______, _______, _______, 
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )



};
