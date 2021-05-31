#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../config.h"

#define STARTUP_SONG SONG(PREONIC_SOUND)

/// Feature: RGB Layer Lighting
/// Description: Light up specific RGB LEDs per active layer.
/// from https://beta.docs.qmk.fm/using-qmk/hardware-features/lighting/feature_rgblight
#define RGBLIGHT_LAYERS
// allow RGB lighting per layer even if RGB lighting is switched off:
#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF

/// Feature: Auto Shift
/// Description: Automatically send capital letter on long press.
/// Requires: in rules.mk: AUTO_SHIFT_ENABLE = yes
/// from https://beta.docs.qmk.fm/using-qmk/software-features/feature_auto_shift
// min duration for a long press / max duration for a short press
#define AUTO_SHIFT_TIMEOUT 140 // in ms
// don't do auto shifting on special keys
#define NO_AUTO_SHIFT_SPECIAL
// don't do auto shifting on numeric keys
#define NO_AUTO_SHIFT_NUMERIC

/// Feature: Leader Key
/// Description: Special key to enable selection of a hard coded macro
/// Requiles: in rules.mk: LEADER_ENABLE = yes
// how long after pressing the lead key that the action is cancled
#define LEADER_TIMEOUT 200 // in ms
// reset the timeout after each key press of a sequence
#define LEADER_PER_KEY_TIMING


#endif /* CONFIG_USER_H */
