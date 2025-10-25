// Copyright 2025 Dasky (@daskygit)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_uk.h"

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    UK_GRV,  UK_1,    UK_2,    UK_3,    UK_4,    UK_5,                             UK_6,    UK_7,    UK_8,    UK_9,   UK_0,    UK_GRV,
    KC_ESC,  UK_Q,    UK_W,    UK_E,    UK_R,    UK_T,                             UK_Y,    UK_U,    UK_I,    UK_O,   UK_P,    KC_BSPC,
    KC_TAB,  UK_A,    UK_S,    UK_D,    UK_F,    UK_G,                             UK_H,    UK_J,    UK_K,    UK_L,   UK_SCLN, UK_QUOT,
    KC_LSFT, UK_Z,    UK_X,    UK_C,    UK_V,    UK_B,    KC_MUTE,        KC_PAUS, UK_N,    UK_M,    UK_COMM, UK_DOT, UK_SLSH, KC_RSFT,
                      KC_LGUI, KC_LALT, KC_LCTL, MO(1),   KC_ENT,         KC_SPC,  MO(2),   KC_RCTL, KC_RALT, KC_RGUI
  ),
  [1] = LAYOUT(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    UK_GRV,  UK_1,    UK_2,    UK_3,    UK_4,    UK_5,                             UK_6,    UK_7,    UK_8,    UK_9,    UK_0,    KC_F12,
    _______, UK_EXLM, UK_AT,   UK_HASH, UK_DLR,  UK_PERC,                          UK_CIRC, UK_AMPR, UK_ASTR, UK_LPRN, UK_RPRN, UK_PIPE,
    _______, UK_EQL,  UK_MINS, UK_PLUS, UK_LCBR, UK_RCBR, _______,        _______, UK_LBRC, UK_RBRC, UK_SCLN, UK_COLN, UK_BSLS, _______,
                      _______, _______, _______, _______, _______,        _______, MO(3),   _______, _______, _______
  ),
  [2] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______ ,_______,
    _______, KC_INS,  KC_PSCR, KC_APP,  XXXXXXX, XXXXXXX,                          KC_PGUP, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, KC_BSPC,
    _______, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, KC_CAPS,                          KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,  XXXXXXX,
    _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), XXXXXXX, _______,        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                      _______, _______, _______, MO(3),   _______,        _______, _______, _______, _______, _______
  ),
    [3] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX ,XXXXXXX, XXXXXXX, XXXXXXX,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, XXXXXXX, XXXXXXX,                          XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
    RM_NEXT, RM_HUED, RM_SATD, RM_VALD, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
                      _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______
  )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
[0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLU, MS_WHLD)},
[1] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)},
[2] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)},
[3] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)}
};
#endif
// clang-format on

#ifdef OLED_ENABLE
static uint16_t current_keycode = 0xFF;
static uint16_t loop_rate = 0;

// Track loop rate
void housekeeping_task_user(void) {
    static uint32_t loop_count = 0;
    static fast_timer_t loop_time = 0;
    loop_count++;
    if (timer_elapsed_fast(loop_time) > 1000) {
        loop_time = timer_read_fast();
        loop_rate = loop_count > UINT16_MAX ? UINT16_MAX : loop_count;
        loop_count = 0;
    }
}

// Custom keycode to string with proper modifier names
const char* custom_keycode_string(uint16_t keycode) {
    switch (keycode) {
        case KC_LCTL: return "LCtrl";
        case KC_RCTL: return "RCtrl";
        case KC_LSFT: return "LShft";
        case KC_RSFT: return "RShft";
        case KC_LALT: return "LAlt";
        case KC_RALT: return "RAlt";
        case KC_LGUI: return "LGui";
        case KC_RGUI: return "RGui";
        case KC_ESC: return "Esc";
        case KC_TAB: return "Tab";
        case KC_ENT: return "Enter";
        case KC_SPC: return "Space";
        case KC_BSPC: return "Bksp";
        case KC_DEL: return "Del";
        case KC_CAPS: return "Caps";
        case KC_MUTE: return "Mute";
        case KC_VOLU: return "Vol+";
        case KC_VOLD: return "Vol-";
        case KC_MPLY: return "Play";
        case KC_PAUS: return "Pause";
        case MO(1): return "MO(1)";
        case MO(2): return "MO(2)";
        case MO(3): return "MO(3)";
        default:
            if (keycode >= KC_A && keycode <= KC_Z) {
                static char key[2];
                key[0] = 'A' + (keycode - KC_A);
                key[1] = '\0';
                return key;
            }
            if (keycode >= KC_1 && keycode <= KC_0) {
                static char num[2];
                num[0] = (keycode == KC_0) ? '0' : '1' + (keycode - KC_1);
                num[1] = '\0';
                return num;
            }
            return "?";
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        current_keycode = keycode;
    }
    return true;
}

bool oled_task_user(void) {
    oled_set_cursor(0, 0);
    oled_write("Layer: ", false);
    oled_write_ln(get_u8_str(get_highest_layer(layer_state), ' '), false);

    oled_advance_page(false);

    oled_write("Key: ", false);
    oled_write_ln(custom_keycode_string(current_keycode), false);

    oled_advance_page(false);

    oled_write("Rate: ", false);
    oled_write_ln(get_u16_str(loop_rate, ' '), false);

    return false;
}
#endif
