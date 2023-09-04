/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
// #include "keycodes.h"
#include "epicSpark.h"
#include <stdio.h>

#ifdef OLED_ENABLE
#    include "oled.c"
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   GUI_A,   ALT_S,  CTRL_D, SHIFT_F,    KC_G,                         KC_H, SHIFT_J,  CTRL_K,   ALT_L,  GUI_QU, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   BUT_Z,    GR_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  GR_DOT,BUT_SLSH, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                 FUN_DEL, NUM_BSP, SYM_ENT,                      MOU_TAB, NAV_SPC, MED_ESC
                                      //`--------------------------'  `--------------------------'
  ),

  [NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_PGUP, KC_HOME,   KC_UP,  KC_END,  KC_INS,                         U_NA,    U_NA,    U_NA,    U_NA,   RESET, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_CAPS,                         U_NA, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   U_UND,   U_CUT,   U_CPY,   U_PST,   U_RDO,                         U_NA,    U_NA,    U_NA, KC_ALGR,    U_NA, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                  KC_DEL, KC_BSPC,  KC_ENT,                         U_NA,    U_NA,    U_NA
                                      //`--------------------------'  `--------------------------'
  ),

  [MOUSE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_WH_U, KC_WH_L, KC_MS_U, KC_WH_R,    U_NU,                         U_NA,    U_NA,    U_NA,    U_NA,   RESET, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R,    U_NU,                         U_NA, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   U_UND,   U_CUT,   U_CPY,   U_PST,   U_RDO,                         U_NA,    U_NA,    U_NA, KC_ALGR,    U_NA, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                 KC_BTN2, KC_BTN3, KC_BTN1,                         U_NA,    U_NA,    U_NA
                                      //`--------------------------'  `--------------------------'
  ),

  [MEDIA] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, RGB_SAI, RGB_HUI, KC_VOLU, RGB_MOD, RGB_TOG,                         U_NA,    U_NA,    U_NA,    U_NA,   RESET, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, RGB_VAI, KC_MPRV, KC_VOLD, KC_MNXT,OUT_AUTO,                         U_NA, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    U_NU,    U_NU,    U_NU,    U_NU,    U_NU,                         U_NA,    U_NA,    U_NA, KC_ALGR,    U_NA, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                 KC_MUTE, KC_MPLY, KC_MSTP,                         U_NA,    U_NA,    U_NA
                                      //`--------------------------'  `--------------------------'
  ),

  [NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,   RESET,    U_NA,    U_NA,    U_NA,    U_NA,                      KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,    U_NA,                       KC_EQL,    KC_4,    KC_5,    KC_6, KC_SCLN, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    U_NA, KC_ALGR,    U_NA,    U_NA,    U_NA,                      KC_BSLS,    KC_1,    KC_2,    KC_3,  KC_GRV, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                    U_NA,    U_NA,    U_NA,                      KC_MINS,    KC_0,  KC_DOT
                                      //`--------------------------'  `--------------------------'
  ),

  [SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,   RESET,    U_NA,    U_NA,    U_NA,    U_NA,                      KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,    U_NA,                      KC_PLUS,  KC_DLR, KC_PERC, KC_CIRC, KC_COLN, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    U_NA, KC_ALGR,    U_NA,    U_NA,    U_NA,                      KC_PIPE, KC_EXLM,   KC_AT, KC_HASH, KC_TILD, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                    U_NA,    U_NA,    U_NA,                      KC_UNDS, KC_LPRN, KC_RPRN
                                      //`--------------------------'  `--------------------------'
  ),

  [FUN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,   RESET,    U_NA,    U_NA,    U_NA,    U_NA,                      KC_PSCR,   KC_F7,   KC_F8,   KC_F9,  KC_F12, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,    U_NA,                      KC_SLCK,   KC_F4,   KC_F5,   KC_F6,  KC_F11, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MACRO,    U_NA, KC_ALGR,    U_NA,    U_NA,    U_NA,                      KC_PAUS,   KC_F1,   KC_F2,   KC_F3,  KC_F10, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                    U_NA,    U_NA,    U_NA,                       KC_TAB,  KC_SPC,  KC_APP
                                      //`--------------------------'  `--------------------------'
  ),
  
  [BUTTON] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,   U_UND,   U_CUT,   U_CPY,   U_PST,   U_RDO,                        U_RDO,   U_PST,   U_CPY,   U_CUT,   U_UND, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,   KC_NO,                        KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   U_UND,   U_CUT,   U_CPY,   U_PST,   U_RDO,                        U_RDO,   U_PST,   U_CPY,   U_CUT,   U_UND, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                 KC_BTN2, KC_BTN3, KC_BTN1,                      KC_BTN1, KC_BTN3, KC_BTN2
                                      //`--------------------------'  `--------------------------'
  ),

  [MACRO_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
TO(MACRO_FN2),  U_FILE,   U_SSW, KC_MPRV, KC_MPLY, KC_MNXT,                         U_NA,    U_NA,    U_NA,    U_NA,    U_NA, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       NORMAL, U_CLOSE,   U_SSR,  U_CTRW,  U_CTRT,  U_SAVE,                         U_NA,    U_NA,    U_NA,    U_NA,    U_NA, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
TO(MACRO_NUM),   U_UND,   U_CUT,   U_CPY,   U_PST,   U_RDO,                         U_NA,    U_NA,    U_NA,    U_NA,    U_NA, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                    U_NU,  KC_F21,  KC_F22,                         U_NA,    U_NA,    U_NA
                                      //`--------------------------'  `--------------------------'
  ),

  [MACRO_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
TO(MACRO_BASE),  KC_NUM,   KC_P7,   KC_P8,   KC_P9, KC_PEQL,                         U_NA,    U_NA,    U_NA,    U_NA,    U_NA, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       NORMAL, KC_PSLS,   KC_P4,   KC_P5,   KC_P6, KC_PMNS,                         U_NA,    U_NA,    U_NA,    U_NA,    U_NA, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
TO(MACRO_FN1), KC_PAST,   KC_P1,   KC_P2,   KC_P3, KC_PPLS,                         U_NA,    U_NA,    U_NA,    U_NA,    U_NA, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                   KC_P0, KC_PDOT, KC_PENT,                         U_NA,    U_NA,    U_NA
                                      //`--------------------------'  `--------------------------'
  ),

  [MACRO_FN1] = LAYOUT_split_3x6_3(
  //,---------------------------------------------------------------------------.                    ,-----------------------------------------------------.
  TO(MACRO_NUM), MEH(KC_F11), MEH(KC_F12), MEH(KC_F13), MEH(KC_F14), MEH(KC_F15),                         U_NA,    U_NA,    U_NA,    U_NA,    U_NA, XXXXXXX,
  //|----------+------------+------------+------------+------------+------------|                    |--------+--------+--------+--------+--------+--------|
         NORMAL,  MEH(KC_F6),  MEH(KC_F7),  MEH(KC_F8),  MEH(KC_F9), MEH(KC_F10),                         U_NA,    U_NA,    U_NA,    U_NA,    U_NA, XXXXXXX,
  //|----------+------------+------------+------------+------------+------------|                    |--------+--------+--------+--------+--------+--------|
  TO(MACRO_FN2),  MEH(KC_F1),  MEH(KC_F2),  MEH(KC_F3),  MEH(KC_F4),  MEH(KC_F5),                         U_NA,    U_NA,    U_NA,    U_NA,    U_NA, XXXXXXX,
  //|----------+------------+------------+------------+------------+------------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                  U_NU,      U_CPY,        U_PST,                         U_NA,    U_NA,    U_NA
                                                    //`----------------------------------'  `--------------------------'
  ),

  [MACRO_FN2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
TO(MACRO_FN1),  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,                         U_NA,    U_NA,    U_NA,    U_NA,    U_NA, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       NORMAL,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,                         U_NA,    U_NA,    U_NA,    U_NA,    U_NA, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
TO(MACRO_BASE), KC_F10,  KC_F11,  KC_F12,  KC_F13,  KC_F14,                         U_NA,    U_NA,    U_NA,    U_NA,    U_NA, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                    U_NU,   U_CPY,   U_PST,                         U_NA,    U_NA,    U_NA
                                      //`--------------------------'  `--------------------------'
  ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef OLED_ENABLE
    if (record->event.pressed) {
        oled_timer = timer_read();
        is_key_processed = true;
    }
#endif

    switch (keycode) {
        case MACRO:
            if (record->event.pressed) {
                layer_move(MACRO_BASE);
                macro_mode = true;
                return false;
            }
            break;
        case NORMAL:
            if (record->event.pressed){
                layer_move(BASE);
                macro_mode = false;
                return false;
            }
            break;
    }
    return true;
}