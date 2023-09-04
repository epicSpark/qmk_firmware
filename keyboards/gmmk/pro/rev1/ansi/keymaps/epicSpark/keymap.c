/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

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
#include "rgb_matrix_ledmaps.h"

enum gmmk_pro_layers {
    _QWERTY,
    _GAME,
    _FN1,
    _FN2,
    _COLEMAKDH,
};

enum combo_events {
  BASE_LAYER,
  FN2_LAYER,
  GAMES_LAYER,
  COLE_LAYER,
};

enum custom_keycodes {
  KC_00 = SAFE_RANGE,
  KC_WINLCK,    //Toggles Win key on and off
  LED_REACT,
  LED_RED,
  LED_ORANGE,
  LED_YELLOW,
  LED_GREEN,
  LED_SPRINGGREEN,
  LED_AZURE,
  LED_BLUE,
  LED_MAGENTA
};

typedef enum {
    TD_NONE,
    TD_SINGLE_HOLD,
    TD_DOUBLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

enum {
    MO_RCTRL,
};

td_state_t cur_dance(qk_tap_dance_state_t *state);

void x_finished(qk_tap_dance_state_t *state, void *user_data);
void x_reset(qk_tap_dance_state_t *state, void *user_data);

const uint16_t PROGMEM base_layer_combo[] = {KC_PGDOWN, KC_HOME, COMBO_END};
const uint16_t PROGMEM fn2_layer_combo[] = {KC_PGDOWN, KC_END, COMBO_END};
const uint16_t PROGMEM game_layer_combo[] = {KC_PGDOWN, KC_PGUP, COMBO_END};
const uint16_t PROGMEM cole_layer_combo[] = {KC_PGUP, KC_HOME, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [BASE_LAYER] = COMBO_ACTION(base_layer_combo),
  [FN2_LAYER] = COMBO_ACTION(fn2_layer_combo),
  [GAMES_LAYER] = COMBO_ACTION(game_layer_combo),
  [COLE_LAYER] = COMBO_ACTION(cole_layer_combo),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Del           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Home
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 End
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgUp
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       PgDn
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the RESET key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backslash. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    [_QWERTY] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,          KC_MPLY,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_END,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGUP,
        KC_LSPO,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSPC, KC_UP,   KC_PGDOWN,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                         TD(MO_RCTRL), MO(_FN2),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_FN2] = LAYOUT(
        KC_ESC, KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,   KC_F22,      KC_F23,  KC_F24,  KC_INS,            KC_MPLY,
        KC_GRV, TG(_FN1), _______, _______, _______, _______, _______, KC_P7,    KC_P8,   KC_P9,    KC_P0,     KC_PMNS, KC_PPLS, _______,            KC_HOME,
        KC_TAB, _______,   KC_UP, _______, _______, _______,  KC_TAB, KC_P4,    KC_P5,   KC_P6,  KC_PDOT,     _______, EEP_RST,   RESET,             KC_END,
        KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, KC_P1,    KC_P2,   KC_P3,    KC_NO,     KC_PAST,          KC_PENT,            KC_PGUP,
        _______, XXXXXXX, KC_DEL,  KC_INS, XXXXXXX, KC_MPLY, XXXXXXX,  KC_P0,   KC_00,  KC_PDOT,   KC_PSLS,     _______, KC_MFFD, KC_PGDOWN,
        _______, KC_WINLCK, _______,                          KC_BSPC,                          _______, TG(_QWERTY), _______, KC_MPRV, KC_MRWD,   KC_MNXT
    ),

    [_FN1] = LAYOUT(
        _______, KC_MYCM, KC_WHOM, KC_CALC, KC_MSEL, KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP, KC_MUTE, KC_VOLD, KC_VOLU, _______, KC_CALC,          _______,
        _______, LED_RED, LED_ORANGE, LED_YELLOW, LED_GREEN, LED_SPRINGGREEN, LED_AZURE, LED_BLUE, LED_MAGENTA, _______, _______, _______, _______, _______,          RGB_TOG,
        _______, _______, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, KC_NLCK, _______, _______, RESET,            KC_HOME,
        KC_CAPS, _______, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, _______, _______, _______, _______, _______,          _______,          KC_END,
        _______,          RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, LED_REACT, NK_TOGG, _______, _______, _______, _______,          _______, RGB_MOD, KC_PGDOWN,
        _______, KC_WINLCK, _______,                            _______,                          _______, TG(_QWERTY), _______, RGB_SPD, RGB_RMOD, RGB_SPI
    ),

    [_GAME] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_MPLY,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_END,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGUP,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_PGDN,
        KC_LCTL, XXXXXXX, KC_LALT,                            KC_SPC,                             KC_RALT, MO(_FN2), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_COLEMAKDH] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_MPLY,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_END,
        KC_BSPC, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O, KC_QUOT,          KC_ENT,           KC_PGUP,
        KC_LSFT,          KC_X,    KC_C,    KC_D,    KC_V,    KC_Z,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_PGDN,
        KC_LCTL, XXXXXXX, KC_LALT,                            KC_SPC,                             KC_RALT, MO(_FN2), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

};

#ifdef ENCODER_ENABLE       // Encoder Functionality
    bool encoder_update_user(uint8_t index, bool clockwise) {
        uint8_t mods_state = get_mods();
        if ( clockwise ) {
            if (mods_state & MOD_BIT(KC_LSFT) ) { // If you are holding L shift, Page up
                unregister_mods(MOD_BIT(KC_LSFT));
                tap_code16(RCTL(KC_PGDN));
                register_mods(MOD_BIT(KC_LSFT));
            } else if (mods_state & MOD_BIT(KC_LCTL)) {  // if holding Left Ctrl, navigate next word
                tap_code16(LCTL(KC_RGHT));
            } else if (mods_state & MOD_BIT(KC_LALT)) {  // if holding Left Alt, change media next track
                tap_code(KC_MEDIA_NEXT_TRACK);
            } else if (mods_state & MOD_BIT(KC_RCTL)) {  // if holding Right Ctrl, change media next track
                tap_code(KC_MEDIA_NEXT_TRACK);
            } else if (mods_state & MOD_BIT(KC_RALT)) {  // if holding Right Alt, fast forward media
                tap_code(KC_MEDIA_FAST_FORWARD);
            } else  {
                tap_code(KC_VOLU);                                                   // Otherwise it just changes volume
            }
        } else {
            if (mods_state & MOD_BIT(KC_LSFT) ) {
                unregister_mods(MOD_BIT(KC_LSFT));
                tap_code16(RCTL(KC_PGUP));
                register_mods(MOD_BIT(KC_LSFT));
            } else if (mods_state & MOD_BIT(KC_LCTL)) {  // if holding Left Ctrl, navigate previous word
                tap_code16(LCTL(KC_LEFT));
            } else if (mods_state & MOD_BIT(KC_LALT)) {  // if holding Left Alt, change media previous track
                tap_code(KC_MEDIA_PREV_TRACK);
            } else if (mods_state & MOD_BIT(KC_RCTL)) {  // if holding Right Ctrl, change media previous track
                tap_code(KC_MEDIA_PREV_TRACK);
            } else if (mods_state & MOD_BIT(KC_RALT)) {  // if holding Right Alt, rewind media
                tap_code(KC_MEDIA_REWIND);
            } else {
                tap_code(KC_VOLD);
            }
        }
        return true;

    }
#endif

void keyboard_post_init_user(void){
    rgb_matrix_enable_noeeprom();
    // rgb_matrix_sethsv_noeeprom(HSV_SPRINGGREEN);
    // rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE);
}

bool _isWinKeyDisabled = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_00:
            if (record->event.pressed) {
                // when keycode KC_00 is pressed
                SEND_STRING("00");
            } else {
                // when keycode KC_00 is released
            }
            break;

        case KC_WINLCK:
            if (record->event.pressed) {
                _isWinKeyDisabled = !_isWinKeyDisabled; //toggle status
                if(_isWinKeyDisabled) {
                    process_magic(GUI_OFF, record);
                } else {
                    process_magic(GUI_ON, record);
                }
            } else  { unregister_code16(keycode); }
            break;
        // I could've made a function for this but oh well :)
        case LED_REACT:
            rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE);
            break;
        case LED_RED:
            rgb_matrix_sethsv_noeeprom(0, rgb_matrix_get_sat(), rgb_matrix_get_val());
            break;
        case LED_ORANGE:
            rgb_matrix_sethsv_noeeprom(28, rgb_matrix_get_sat(), rgb_matrix_get_val());
            break;
        case LED_YELLOW:
            rgb_matrix_sethsv_noeeprom(43, rgb_matrix_get_sat(), rgb_matrix_get_val());
            break;
        case LED_GREEN:
            rgb_matrix_sethsv_noeeprom(85, rgb_matrix_get_sat(), rgb_matrix_get_val());
            break;
        case LED_SPRINGGREEN:
            rgb_matrix_sethsv_noeeprom(106, rgb_matrix_get_sat(), rgb_matrix_get_val());
            break;
        case LED_AZURE:
            rgb_matrix_sethsv_noeeprom(132, rgb_matrix_get_sat(), rgb_matrix_get_val());
            break;
        case LED_BLUE:
            rgb_matrix_sethsv_noeeprom(170, rgb_matrix_get_sat(), rgb_matrix_get_val());
            break;
        case LED_MAGENTA:
            rgb_matrix_sethsv_noeeprom(213, rgb_matrix_get_sat(), rgb_matrix_get_val());
            break;
    }
    return true;
}

td_state_t cur_dance(qk_tap_dance_state_t *state) {

    if (state->count == 1){
        if (state->pressed) return TD_SINGLE_HOLD;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_NONE;
    } else if (state->count == 2) {
        if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_NONE;
    } else return TD_NONE;
}

static td_tap_t xtap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void x_finished(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) { 
        case TD_SINGLE_HOLD: 
            register_mods(MOD_BIT(KC_RALT));
            break;
        case TD_DOUBLE_HOLD: 
            layer_on(_FN1);
            break;
        default:
            break;
    }
}

void x_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case TD_SINGLE_HOLD: unregister_code(KC_RALT); break;
        case TD_DOUBLE_HOLD: layer_off(_FN1);
        default:
            break;
    }
    xtap_state.state = TD_NONE;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [MO_RCTRL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_finished, x_reset)
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        case GAMES_LAYER:
            if (pressed) {
                layer_off(_QWERTY);
                layer_off(_FN1);
                layer_off(_FN2);
                layer_off(_COLEMAKDH);
                layer_on(_GAME);
            }
            break;
        case FN2_LAYER:
            if (pressed) {
                layer_off(_QWERTY);
                layer_off(_GAME);
                layer_off(_FN1);
                layer_off(_COLEMAKDH);
                layer_on(_FN2);
            }
            break;
        case BASE_LAYER:
            if (pressed) { 
                layer_off(_FN1);
                layer_off(_FN2);
                layer_off(_GAME);
                layer_off(_COLEMAKDH);
                layer_on(_QWERTY);
            }
            break;
        case COLE_LAYER:
            if (pressed) { 
                layer_off(_FN2);
                layer_off(_GAME);
                layer_off(_QWERTY);
                layer_off(_FN1);
                layer_on(_COLEMAKDH);
            }
            break;
    }
}

// void suspend_power_down_user(void) {
// #ifdef RGB_MATRIX_ENABLE
//     rgb_matrix_set_suspend_state(true);
// #endif  // RGB_MATRIX_ENABLE
// }

// void suspend_wakeup_init_user(void) {
// #ifdef RGB_MATRIX_ENABLE
//     rgb_matrix_set_suspend_state(false);
// #endif  // RGB_MATRIX_ENABLE
// }

#ifdef RGB_MATRIX_LEDMAPS_ENABLED

#define ______ {0, 0, 0}

const ledmap PROGMEM ledmaps[] = {
         //  LU = Left Underglow, RU = Right Underglow
         //  LU_1    ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)  RU_1
         //  LU_2    ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del       RU_2
         //  LU_3    Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp         RU_3
         //  LU_4    Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn         RU_4
         //  LU_5    Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End          RU_5
         //  LU_6    Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right        RU_6
    [_QWERTY] = RGB_MATRIX_LAYOUT_LEDMAP(
          ______,    SPRING, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______,    ______,
          ______,    ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______,    ______,
          ______,    ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______,    ______,
          ______,    ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______,         ______,    ______,
          ______,    ______,         ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______, ______, ______,    ______,
          ______,    ______, ______, ______,                         ______,                         ______, ______, ______, ______, ______, ______,    ______
    ),
    [_FN2] = RGB_MATRIX_LAYOUT_LEDMAP(
          SPRING,    ______, SPRING, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ORANGE,    ORANGE,
          SPRING,    ______, SPRING, ______, ______, ______, ______, ______, SPRING, SPRING, SPRING, ______, ______, ______, ______,         ORANGE,    ORANGE,
          SPRING,    ______, ______, ______, ______, ______, ______, ______, SPRING, SPRING, SPRING, ______, ______, ______, SPRING,         ORANGE,    ORANGE,
          SPRING,    ______, ______, ______, ______, ______, ______, ______, SPRING, SPRING, SPRING, ______, ______,         ______,         ______,    ______,
          SPRING,    ______,         ______, ______, ______, ______, ______, ______, SPRING, SPRING, ______, ______,         ______, ______, ______,    ______,
          SPRING,    ______, ______, ______,                         ______,                         ______, SPRING, ______, ______, ______, ______,    ______
    ),
    [_FN1] = RGB_MATRIX_LAYOUT_LEDMAP(
          SPRING,    ______, ______, ______, ______, SPRING, ______, ______, ______, ______, ______, ______, ______, ______, MAGENT,         MAGENT,    MAGENT,
          SPRING,    ______, RED, ORANGE, YELLOW, GREEN, SPRING, AZURE, BLUE, MAGENT, ______, ______, ______, ______, ______,         MAGENT,    MAGENT,
          SPRING,    ______, ______, ______, ______, ______, ______, ______, SPRING, SPRING, SPRING, ______, ______, ______, ______,         MAGENT,    MAGENT,
          SPRING,    ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______,         ______,    ______,
          SPRING,    ______,         ______, ______, ______, ______, ______, SPRING, ______, ______, ______, ______,         ______, ______, ______,    ______,
          SPRING,    ______, ______, ______,                         ______,                         ______, ______, ______, ______, ______, ______,    ______
    ),
    [_GAME] = RGB_MATRIX_LAYOUT_LEDMAP(
          MAGENT,    ______, ______, MAGENT, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ORANGE,    ORANGE,
          MAGENT,    ______, ______, MAGENT, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ORANGE,    ORANGE,
          MAGENT,    ______, ______, MAGENT, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ORANGE,    ORANGE,
          MAGENT,    ______, MAGENT, MAGENT, MAGENT, ______, ______, ______, ______, ______, ______, ______, ______,         ______,         ORANGE,    ORANGE,
          MAGENT,    ______,         ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______, ______, ______,    ______,
          MAGENT,    ______, ______, ______,                         ______,                         ______, ______, ______, ______, ______, ______,    ______
    ),
    [_COLEMAKDH] = RGB_MATRIX_LAYOUT_LEDMAP(
          ORANGE,    ______, ______, ______, ORANGE, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ORANGE,    ORANGE,
          ORANGE,    ______, ______, ______, ORANGE, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ORANGE,    ORANGE,
          ORANGE,    ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______,    ______,
          ORANGE,    ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______,         ORANGE,    ORANGE,
          ORANGE,    ______,         ______, ______, ORANGE, ______, ______, ______, ______, ______, ______, ______,         ______, ______, ______,    ______,
          ORANGE,    ______, ______, ______,                         ______,                         ______, ______, ______, ______, ______, ______,    ______
    ),
};

#endif // RGB_MATRIX_LEDMAPS_ENABLED
