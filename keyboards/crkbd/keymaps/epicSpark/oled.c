#pragma once

#include "epicSpark.h"

extern uint8_t is_master;

static bool macro_mode = false;

void render_corne_logo(void) {
    static const char PROGMEM font_logo[16] = {0x80, 0x81, 0x82, 0x83, 0x84, 0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0};
    oled_write_P(font_logo, false);
};

void render_qmk_logo(void) {
    static const char PROGMEM font_qmk_logo[16] = {0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0};
    oled_write_P(font_qmk_logo, false);
};

void render_kb_split(void) {
    static const char PROGMEM font_kb_split[11] = {0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xda, 0xdb, 0xdc, 0xdd, 0xde, 0};
    oled_write_P(font_kb_split, false);
};

// 2x1 Ctrl, Alt, Shift, GUI, Mouse
void render_mod_ctrl(void) {
    static const char PROGMEM font_ctrl[3] = {0x93, 0x94, 0};
    oled_write_P(font_ctrl, false);
};

void render_mod_alt(void) {
    static const char PROGMEM font_alt[3] = {0xb3, 0xb4, 0};
    oled_write_P(font_alt, false);
};

void render_mod_shift(void) {
    static const char PROGMEM font_shift[3] = {0xd3, 0xd4, 0};
    oled_write_P(font_shift, false);
};

void render_mod_gui(void) {
    static const char PROGMEM font_gui[3] = {0x95, 0x96, 0};
    oled_write_P(font_gui, false);
};

#ifdef MOUSEKEY_ENABLE
void render_mod_mouse(void) {
    static const char PROGMEM font_mouse[3] = {0x97, 0x98, 0};
    oled_write_P(font_mouse, false);
};
#endif

// 5x2 Mod and feature indicator clusters

void render_mod_status(void) {
#ifdef NO_ACTION_ONESHOT
    uint8_t modifiers = get_mods();
#else
    uint8_t modifiers = get_mods() | get_oneshot_mods();
#endif

    (modifiers & MOD_MASK_CTRL) ? render_mod_ctrl() : oled_write_P(PSTR("  "), false);
    oled_write_P(PSTR(" "), false);
    (modifiers & MOD_MASK_SHIFT) ? render_mod_shift() : oled_write_P(PSTR("  "), false);

    (modifiers & MOD_MASK_ALT) ? render_mod_alt() : oled_write_P(PSTR("  "), false);
    oled_write_P(PSTR(" "), false);
    (modifiers & MOD_MASK_GUI) ? render_mod_gui() : oled_write_P(PSTR("  "), false);
}

void render_prompt(void) {
    bool blink = (timer_read() % 1000) < 500;

    if (!macro_mode) {
        if (layer_state_is(NAV)) {
            oled_write_ln_P(blink ? PSTR("> nav  _") : PSTR("> nav"), false);
        } else if (layer_state_is(MOUSE)) {
            oled_write_ln_P(blink ? PSTR("> mou  _") : PSTR("> mou"), false);
        } else if (layer_state_is(MEDIA)) {
            oled_write_ln_P(blink ? PSTR("> med  _") : PSTR("> med"), false);
        } else if (layer_state_is(NUM)) {
            oled_write_ln_P(blink ? PSTR("> num  _") : PSTR("> num"), false);
        } else if (layer_state_is(SYM)) {
            oled_write_ln_P(blink ? PSTR("> sym  _") : PSTR("> sym"), false);
        } else if (layer_state_is(FUN)) {
            oled_write_ln_P(blink ? PSTR("> fun  _") : PSTR("> fun"), false);
        } else if (layer_state_is(BUTTON)) {
            oled_write_ln_P(blink ? PSTR("> but  _") : PSTR("> but"), false);
        } else {
            oled_write_ln_P(blink ? PSTR("> _  ") : PSTR(">    "), false);
        }
    } else {
        if (layer_state_is(MACRO_NUM)){
            oled_write_ln_P(blink ? PSTR("> #_") : PSTR("> #"), false);
        } else if (layer_state_is(MACRO_FN1)){
            oled_write_ln_P(blink ? PSTR("> FN_") : PSTR("> FN"), false);
        } else if (layer_state_is(MACRO_FN2)){
            oled_write_ln_P(blink ? PSTR("> F2_") : PSTR("> F2"), false);
        } else {
            oled_write_ln_P(blink ? PSTR("> MP_") : PSTR("> MP"), false);
        }
    }
};

// Keylogger
// #define KEYLOGGER_LENGTH 5
// static char     keylog_str[KEYLOGGER_LENGTH + 1] = {"\n"};
static uint16_t oled_timer                       = 0;
static bool     is_key_processed                 = true;

void render_status_secondary(void) {
    oled_write_ln("", false);
    oled_write_ln("", false);

    render_kb_split();

    oled_write_ln("", false);
    oled_write_ln("", false);
    oled_write_ln("", false);

    render_qmk_logo();

    oled_write_ln("", false);
    oled_write_ln("", false);
    oled_write_ln("", false);
};

void render_status_main(void) {
    oled_write_ln("", false);
    oled_write_ln("", false);

    if (macro_mode){
        render_qmk_logo();
    } else {
        render_corne_logo();
    }

    oled_write_ln("", false);
    oled_write_ln("", false);
    oled_write_ln("", false);

    render_prompt();

    oled_write_ln("", false);
    oled_write_ln("", false);
    oled_write_ln("", false);

    render_mod_status();
    
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
};

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        if (is_key_processed && (timer_elapsed(oled_timer) < OLED_KEY_TIMEOUT)) {
            render_status_main();
        } else {
            is_key_processed = false;
            oled_off();
        }
    } else {
        render_status_secondary();
    }
    return false;
};