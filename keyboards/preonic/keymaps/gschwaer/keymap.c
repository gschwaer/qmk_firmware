/// Keymap file for OLKB Preonic v3 from gschwaer
#include "config.h"
#include "audio.h"

/// Using german keyboard layout for umlauts.
#include "keymap_german.h"

/// 1) Get a json config from: https://config.qmk.fm/#/preonic/rev3/LAYOUT_preonic_1x2uL
/// 2) Then use convert_heymap.sh to fill in german key codes and convert to C header.
/// 3) This .h file will then be included here:
#include "keymap_from_json.h"

///
/// Feature: RGB Layer Lighting
/// from https://beta.docs.qmk.fm/using-qmk/hardware-features/lighting/feature_rgblight
///

#define NUM_RGB_LAYERS 9

#define DISABLE_LIGHTING_LAYER_0 1


/* (from pcurt854)
 * Preonic LEDs visible from the top:
 *   6 5 4 3
 *   7 8 1 2
 * The two numbers: starting LED number, number of LEDs
 * Colors: https://beta.docs.qmk.fm/using-qmk/hardware-features/lighting/feature_rgblight#colors
 */
// Light LEDs 1 to 8 in red when keyboard layer 0 is active.
const rgblight_segment_t PROGMEM my_layer0_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 8, HSV_ORANGE}
);
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 8, HSV_CYAN}
);
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 8, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 8, HSV_GOLD}
);
const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 8, HSV_WHITE}
);
const rgblight_segment_t PROGMEM my_layer5_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 8, HSV_ORANGE}
);
const rgblight_segment_t PROGMEM my_layer6_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 8, HSV_CYAN}
);
const rgblight_segment_t PROGMEM my_layer7_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 8, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM my_layer8_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 8, HSV_GOLD}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_layer0_layer,
    my_layer1_layer,
    my_layer2_layer,
    my_layer3_layer,
    my_layer4_layer,
    my_layer5_layer,
    my_layer6_layer,
    my_layer7_layer,
    my_layer8_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    int i, highest_layer = get_highest_layer(state);

    // switch off lights of all layer
    for (i = 0; i < NUM_RGB_LAYERS; ++i) {
        rgblight_set_layer_state(i, false);
    }

    // switch on lights of highest layer
    if (!DISABLE_LIGHTING_LAYER_0 || highest_layer > 0) {
        rgblight_set_layer_state(highest_layer, true);
    }

    dprintf("Highest active layer: %u\n", highest_layer);

    return state;
}
