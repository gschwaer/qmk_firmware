#!/bin/env bash

# This is called by my build script before triggering the actual build.

set -e

# convert json to C header
qmk json2c preonic_rev3_layout_preonic_1x2ul_mine.json > keymap_from_json.h

# convert default key codes to german key codes
# Find all keycodes that are defined differently in keymap_german.h and create a
# sed command list to replace them with the german equivalent. We use `[5-9]` to
# not apply the conversion on layers 5 - 9. This way layers 5 - 9 are english
# layout. I have layers 0-3 set equal to layers 5-8 so when I am on a computer
# with english keyboard layout I can just switch to 5-8.
grep '#define ' ../../../../quantum/keymap_extras/keymap_german.h | \
	sed -e 's|#define DE_\(\S*\)\s*\(\S\+\).*|/^\\s*\\[[5-9]\\]/b; s/KC_\1\\b/DE_\1/g|' > sed_cmds.txt
# special case: left and right angle brackets currently have a different name:
#  KC_LT vs. DE_LABK, etc
echo '/^\s*\[[5-9]\]/b; s/KC_LT\b/DE_LABK/g' >> sed_cmds.txt
echo '/^\s*\[[5-9]\]/b; s/KC_GT\b/DE_RABK/g' >> sed_cmds.txt
sed -i -f sed_cmds.txt keymap_from_json.h
