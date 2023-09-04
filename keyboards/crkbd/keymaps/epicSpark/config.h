#pragma once

#define MASTER_LEFT

// #define EE_HANDS
// #define SPLIT_USB_DETECT

// #undef USE_I2C
// #undef SSD1306OLED

// #define USE_SERIAL_PD2

// default but used in macros
#undef TAPPING_TERM
#define TAPPING_TERM 200

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

// Auto Shift
#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_TIMEOUT TAPPING_TERM
#define AUTO_SHIFT_NO_SETUP

// Mouse key speed and acceleration.
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      6
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    64

// Thumb Combos
#if defined (MIRYOKU_KLUDGE_THUMBCOMBOS)
  #define COMBO_COUNT 8
  #define COMBO_TERM 200
  #define EXTRA_SHORT_COMBOS
#endif

// Oled
#ifdef OLED_ENABLE
#    define SPLIT_LAYER_STATE_ENABLE
#    define SPLIT_LED_STATE_ENABLE
#    define SPLIT_MODS_ENABLE
#    define SPLIT_WPM_ENABLE
#    define SPLIT_OLED_ENABLE
#    define OLED_FONT_H "keyboards/crkbd/keymaps/gotham/glcdfont.c"
#    define OLED_DISABLE_TIMEOUT
#    undef  OLED_TIMEOUT
// #    define OLED_TIMEOUT 60000
#    define OLED_KEY_TIMEOUT 30000
#    define OLED_BRIGHTNESS 255
// #    define OLED_FADE_OUT
// #    define OLED_FADE_OUT_INTERVAL 13
#endif