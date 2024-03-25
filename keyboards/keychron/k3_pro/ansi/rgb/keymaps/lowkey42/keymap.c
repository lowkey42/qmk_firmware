/* Copyright 2023 @ Keychron (https://www.keychron.com)
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

// clang-format off
enum layers{
  MAC_BASE,
  MAC_FN,
  WIN_BASE,
  WIN_FN
};

enum custom_keycodes {
    MK_PARANS = SAFE_RANGE,
    MK_BRACKETS,
    MK_ABRC,
    MK_BRACES,
    MK_QUOTES
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[MAC_BASE] = LAYOUT_ansi_84(
     KC_ESC,   KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_SNAP,  KC_DEL,   RGB_MOD,
     KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
     KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
     KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,    KC_END,
     KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                                 KC_RCMMD,MO(MAC_FN),KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

[MAC_FN] = LAYOUT_ansi_84(
     KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_TRNS,  KC_TRNS,  RGB_TOG,
     KC_TRNS,  BT_HST1,  BT_HST2,  BT_HST3,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
     RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
     KC_TRNS,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,            KC_TRNS,
     KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  BAT_LVL,  NK_TOGG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),

[WIN_BASE] = LAYOUT_ansi_84(
     KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_DEL,   KC_INS,
     KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Z,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
   MO(WIN_FN), KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
     KC_LSFT,            KC_Y,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,    KC_END,
     KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT, MO(WIN_FN),KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

[WIN_FN] = LAYOUT_ansi_84(
     KC_SLEP,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_MYCM,  KC_TRNS,  KC_TRNS,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  AC_TOGG,  KC_TRNS,  RGB_TOG,
     KC_TRNS,  BT_HST1,  BT_HST2,  BT_HST3,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  MK_PARANS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_CALC,
     RGB_TOG,  KC_HOME,  KC_UP,    KC_END,   KC_PGUP,  RGB_SPI,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  MK_BRACKETS,  MK_BRACES,  KC_TRNS,            G(KC_B), // G(KC_B) = broswer
     KC_TRNS,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_PGDN,  RGB_SPD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  MK_QUOTES,          KC_TRNS,            G(KC_T), // G(KC_T) = terminal
     KC_TRNS,   RCTL(KC_LEFT),  KC_TRNS,  RCTL(KC_RIGHT),  KC_TRNS,  BAT_LVL,  NK_TOGG,  KC_TRNS,  MK_ABRC,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_WBAK,  KC_TRNS,  KC_WFWD)
};


// overrides
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

const key_override_t a_umlaut_override = ko_make_basic(MOD_MASK_ALT, KC_A, RALT(KC_Q));
const key_override_t o_umlaut_override = ko_make_basic(MOD_MASK_ALT, KC_O, RALT(KC_P));
const key_override_t u_umlaut_override = ko_make_basic(MOD_MASK_ALT, KC_U, RALT(KC_Y));

const key_override_t eur_override = ko_make_basic(MOD_MASK_ALT, KC_4, RALT(KC_5));
const key_override_t degree_override = ko_make_basic(MOD_MASK_ALT, KC_GRV, RSA(KC_SCLN));
const key_override_t half_override = ko_make_basic(MOD_MASK_SA, KC_2, RALT(KC_7));

const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    &a_umlaut_override,
    &o_umlaut_override,
    &u_umlaut_override,
    &eur_override,
    &degree_override,
    &half_override,
    NULL
};

// TODO: custom keycode on FN+Shift + single keycode + 1-2 digits + return => press keycode N times

static void send_pair(keyrecord_t *record, const char* text) {
	if (record->event.pressed) {
		const uint8_t mods = get_mods();
		//const uint8_t oneshot_mods = get_oneshot_mods();

		clear_oneshot_mods();  // Temporarily disable mods.
		unregister_mods(MOD_MASK_CSAG);
		
		SEND_STRING(text);
		
		tap_code(KC_LEFT);  // Move cursor between braces.
		register_mods(mods);  // Restore mods.
	}
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case MK_PARANS:   send_pair(record, "()"); break;
		case MK_BRACKETS: send_pair(record, "[]"); break;
		case MK_ABRC:     send_pair(record, "<>"); break;
		case MK_BRACES:   send_pair(record, "{}"); break;
		case MK_QUOTES:   send_pair(record, "\"\"");  break;
		
	}
	return true;
}

void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_lowkey_reactive);
}

