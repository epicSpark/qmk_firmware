#pragma once
#include QMK_KEYBOARD_H

#pragma once

enum layers {
    BASE = 0, 
    NAV, 
    MOUSE, 
    MEDIA,
    NUM,
    SYM,
    FUN,
    BUTTON,
    MACRO_BASE,
    MACRO_NUM,
    MACRO_FN1,
    MACRO_FN2
};

enum custom_keycodes {
    MACRO = SAFE_RANGE,
    NORMAL
};

#define U_NP KC_NO // key is not present
#define U_NA KC_NO // present but not available for use
#define U_NU KC_NO // available but not used

// Left-hand home row mods - Base Layer
#define GUI_A             LGUI_T(KC_A)
#define ALT_S             LALT_T(KC_S)
#define CTRL_D            LCTL_T(KC_D)
#define SHIFT_F           LSFT_T(KC_F)

// Right-hand home row mods  - Base Layer
#define SHIFT_J           RSFT_T(KC_J)
#define CTRL_K            RCTL_T(KC_K)
#define ALT_L             LALT_T(KC_L)
#define GUI_QU         RGUI_T(KC_QUOT)

// left-hand extras
#define BUT_Z         LT(BUTTON, KC_Z)
#define GR_X              ALGR_T(KC_X)

// Right-hand extras
#define BUT_SLSH   LT(BUTTON, KC_SLSH)
#define GR_DOT          ALGR_T(KC_DOT)

// left-hand layers
#define MED_ESC      LT(MEDIA, KC_ESC)
#define NAV_SPC        LT(NAV, KC_SPC)
#define MOU_TAB      LT(MOUSE, KC_TAB)

// Right-hand layers
#define SYM_ENT        LT(SYM, KC_ENT)
#define NUM_BSP       LT(NUM, KC_BSPC)
#define FUN_DEL        LT(FUN, KC_DEL)

// Miryoku clipboard win
#define U_RDO                  C(KC_Y)
#define U_PST                  C(KC_V)
#define U_CPY                  C(KC_C)
#define U_CUT                  C(KC_X)
#define U_UND                  C(KC_Z)

// Custom keys
#define U_FILE                 G(KC_E)
#define U_SAVE                 C(KC_S)
#define U_CTRW                 C(KC_W)
#define U_CTRT                 C(KC_T)
#define U_CLOSE               A(KC_F4)
#define U_SSW                MEH(KC_W)
#define U_SSR                MEH(KC_R)
