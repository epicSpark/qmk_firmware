#pragma once

#define COMBO_COUNT 4
#define COMBO_TERM 200
#define TAPPING_TOGGLE 2
#define TAPPING_TERM 200

#ifdef RGB_MATRIX_ENABLE
    
    #define RGB_MATRIX_KEYPRESSES 
    #define RGB_MATRIX_FRAMEBUFFER_EFFECTS // Heatmap, Rain
    #define RGB_DISABLE_TIMEOUT 1200000
    #define RGB_DISABLE_WHEN_USB_SUSPENDED

    #define RGB_MATRIX_STARTUP_HUE 106
    #define RGB_MATRIX_STARTUP_SAT 255
    #define RGB_MATRIX_STARTUP_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS
    #define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE

// Soon we need to ENABLE modes by DEFAULT soon as per: https://github.com/qmk/qmk_firmware/pull/13758 Thanks @noroadsleft
    //  #define DISABLE_RGB_MATRIX_SOLID_COLOR               // BUILT IN (MAPPED!) Static single color.
     #define DISABLE_RGB_MATRIX_ALPHAS_MODS               // Accenting various keys on the keyboard.
    //  #define DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN          // Top down rainbow!
     #define DISABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT       // Left Right Rainbow (the top-down is better imho).
    //  #define DISABLE_RGB_MATRIX_BREATHING                 // Built in (MAPPED!)
     #define DISABLE_RGB_MATRIX_BAND_SAT                  // Single hue band fading saturation scrolling left to right (with white)
    //  #define DISABLE_RGB_MATRIX_BAND_VAL                  // Single hue band fading brightness scrolling left to right (with black)
     #define DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT         // Single hue 3 blade spinning pinwheel fades sat (RGB_MATRIX_CYCLE_PINWHEEL)
    //  #define DISABLE_RGB_MATRIX_BAND_PINWHEEL_VAL         // See above
     #define DISABLE_RGB_MATRIX_BAND_SPIRAL_SAT           // See above
    //  #define DISABLE_RGB_MATRIX_BAND_SPIRAL_VAL           // Single hue spinning spiral fades brightness (with black)
     #define DISABLE_RGB_MATRIX_CYCLE_ALL                 // Full keyboard cycling through rainbow
    //  #define DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT          // BUILT IN (MAPPED!) Full Rainbow Left to Right
     #define DISABLE_RGB_MATRIX_CYCLE_UP_DOWN             // Full gradient scrolling top to bottom
    //  #define DISABLE_RGB_MATRIX_CYCLE_OUT_IN              // Rainbow circles coming to center.
     #define DISABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL         // Two Rainbow circles coming to 1/3 and 2/3 points.
    //  #define DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON    // Full gradent Chevron shapped scrolling left to right
    //  #define DISABLE_RGB_MATRIX_CYCLE_PINWHEEL            // BUILT IN (MAPPED!) - Consider disabling this - my poor eyes.
    //  #define DISABLE_RGB_MATRIX_CYCLE_SPIRAL              // Full gradient spinning spiral around center of keyboard
     #define DISABLE_RGB_MATRIX_DUAL_BEACON               // Two rainbows spinning around keyboards
     #define DISABLE_RGB_MATRIX_RAINBOW_BEACON            // Similar to above.
     #define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS         // Enough of the spinning rainbows - we get it! :-)
     #define DISABLE_RGB_MATRIX_RAINDROPS                 // Jellybeans are better.
     #define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS       // Randomly changes a single key's hue and saturation - better than above.
     #define DISABLE_RGB_MATRIX_HUE_BREATHING             // Hue shifts up a slight ammount at the same time, then shifts back
     #define DISABLE_RGB_MATRIX_HUE_PENDULUM              // Hue shifts up a slight ammount in a wave to the right, then back to the left
     #define DISABLE_RGB_MATRIX_HUE_WAVE                  // Hue shifts up a slight ammount and then back down in a wave to the right
    //  #define DISABLE_RGB_MATRIX_TYPING_HEATMAP            // Hot keys!
    //  #define DISABLE_RGB_MATRIX_DIGITAL_RAIN              // The Matrix!
     #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE     // Key hits shown in current hue - all other keys black: wide slightly better imo
     #define DISABLE_RGB_MATRIX_SOLID_REACTIVE            // Key hits shown in current hue - all other keys shifted hue
     #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE       // Hue & value pulse around a single key hit then fades value out (black otherwise)
    //  #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE  // same as above but a bit too intense imo.
     #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS      // Column and Row single color fade.
     #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS // Column and Row single color fade. (Multi-keys)
     #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS      // Hue & value pulse away on the same column and row of key hit then fades
     #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS // Hue & value pulse away on the same column and row of multi-key hit then fades
     #define DISABLE_RGB_MATRIX_SPLASH                    // Full rainbow pulses from key hit. All else black.
    //  #define DISABLE_RGB_MATRIX_MULTISPLASH               // Full rainbow pulses from multi-keys. All else black.
     #define DISABLE_RGB_MATRIX_SOLID_SPLASH              // Single color pulses from key hit. All else black. (Using solid_reactive_wide instead).
     #define DISABLE_RGB_MATRIX_SOLID_MULTISPLASH         // Single color pulses from muli-keys. All else black. (Using solid_reactive_wide instead).

#endif