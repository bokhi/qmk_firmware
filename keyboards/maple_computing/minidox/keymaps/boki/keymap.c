#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _LOWER 2
#define _RAISE 3
#define _MOUSE 4
#define _FUN 5
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  LOWER,
  RAISE,
  MOUSE,
  FUN,
  ADJUST,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define TAPPING_TERM 200


//Tap Dance Declarations
enum {
      TD_ESC_CAPS = 0
};

#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_TIME_TO_MAX 60
#define MOUSEKEY_MAX_SPEED 7
#define MOUSEKEY_WHEEL_DELAY 0

/* LGUI_T(KC_A),    LALT_T(KC_S),    LCTL_T(KC_D),    LSFT_T(KC_F),    KC_G,    KC_H,    RSFT_T(KC_J),    RCTL_T(KC_K),    RALT_T(KC_L),    RGUI_T(KC_SCLN), \ */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      | LOWER|      |    |      | RAISE|      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_QWERTY] = LAYOUT( \
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    \
  LGUI_T(KC_A),    LALT_T(KC_S),    LCTL_T(KC_D),    LSFT_T(KC_F),    KC_G,    KC_H,    RSFT_T(KC_J),    RCTL_T(KC_K),    RALT_T(KC_L),    RGUI_T(KC_SCLN), \
  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, \
  /* LSFT_T(KC_TAB), LT(_LOWER, KC_ESC), KC_BSPC,         KC_SPC, LT(_RAISE, KC_ENT), LCTL_T(KC_DEL) \ */
  LSFT_T(KC_TAB), LT(_LOWER, KC_ESC), KC_BSPC,         KC_SPC, LT(_RAISE, KC_ENT), LT(_MOUSE, KC_DEL) \
),

/* Colemak
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   F  |   P  |   G  |           |   J  |   L  |   U  |   Y  |   ;  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   R  |   S  |   T  |   D  |           |   H  |   N  |   E  |   I  |   S  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |           |   K  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  | LOWER| Gui  |      |    |      | Ent  |RAISE |
 *                  `-------------| BSpc |    | Spc  |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_COLEMAK] = LAYOUT ( \
  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, \
  LGUI_T(KC_A),    LALT_T(KC_R),    LCTL_T(KC_S),    LSFT_T(KC_T),    KC_D,       KC_H,    RSFT_T(KC_N),    RCTL_T(KC_E),    RALT_T(KC_I),    RGUI_T(KC_O), \
  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, \
  LSFT_T(KC_TAB), LT(_LOWER, KC_ESC), KC_BSPC,         KC_SPC, LT(_RAISE, KC_ENT), LCTL_T(KC_DEL) \
),





/* Raise
*
 * ,----------------------------------.           ,----------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |           |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      | Left | Down |  Up  | Right|           |      |   -  |   =  |   [  |   ]  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |   `  |      |      |      |           |      |      |      |   \  |   '  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      | LOWER|      |    |      | RAISE|      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_RAISE] = LAYOUT( \
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    \
  _______,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,      _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, \
  _______, KC_GRV,  _______, _______, _______,      _______, _______, _______, KC_BSLS,  KC_QUOT, \
                    _______, _______, _______,      _______, _______, _______                    \
),

/* Lower
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |           |   ^  |   &  |   *  |   (  |   )  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |      |   _  |   +  |   {  |   }  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Caps|   ~  |      |      |      |           |      |      |      |   |  |   "  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      |      |      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_LOWER] = LAYOUT( \
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, \
  _______,  _______, _______, _______, _______,      _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, \
  KC_CAPS, KC_TILD, _______, _______, _______,      _______, _______, _______, KC_PIPE,  KC_DQT, \
                    _______, _______, _______,      _______, _______, _______                    \
),

/* Adjust (Lower + Raise)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |           |   F6 |  F7  |  F8  |  F9  |  F10 |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  F11 |  F12 |      |      |      |           |      |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |      |      |      |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      | LOWER|      |    |      | RAISE|      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_ADJUST] =  LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, \
  KC_F11,  KC_F12,  _______, _______, _______,      _______, _______, _______, _______, _______, \
  _______,   QWERTY, COLEMAK, _______, _______,      _______, _______, _______, _______,  _______, \
                    _______, _______, _______,      _______,  _______, _______                    \
                     ),
[_MOUSE] =  LAYOUT( \
                    _______,   _______, _______, _______, _______,      _______, _______, _______, _______,  _______, \
                    KC_MS_L,   KC_MS_D, KC_MS_U, KC_MS_R, _______,      _______, KC_BTN1, KC_BTN2, KC_BTN3,  _______, \
                    _______,   _______, _______, _______, _______,      _______, _______, _______, _______,  _______, \
                    _______, _______, _______,      _______,  _______, _______                    \
                    )

/* Function layer
 *
 * ,----------------------------------.           ,---------------------------------.
 * |      |  del |⌃←  |  ⌃→ |      |           | mute | vol- | vol+ | ⌘⌃p |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   `  |  end | pgup | pgdn | home |           |  ←  |   ↓  |   ↑  |  →  |   '  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | ⌥⇥ |      |⇧⌃⇥| ⌃⇥  |       |           |      |  br- | ,    | br+  |  ^   |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,---------------------.
 *                 | tab   |      | enter|    |bckspc|      |   tab |
 *                 | shift |      | alt  |    |  gui |      | shift |
 *                 `-------+------+      |    |      |------+-------.
 *                                `------'    `------'
 */
 /* [_FUN] = LAYOUT( \ */
 /*    XXXXXXX, KC_DEL,  KC_C_LF, KC_C_RT, XXXXXXX,     KC_MUTE, KC_VOLD, KC_VOLU, KC_CCSP, XXXXXXX, \ */
 /*    KC_GRV,  KC_END,  KC_PGUP, KC_PGDN, KC_HOME,     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_QUOT, \ */
 /*    KC_OPTB, XXXXXXX, KC_CSTB, KC_C_TB, XXXXXXX,     XXXXXXX, KC_BRDN, KC_COMM, KC_BRUP, KC_CIRC, \ */
 /*                      KC_SHTB, XXXXXXX, KC_ENOP,     KC_BSCM, _______, KC_SHTB                    \ */
 /*  ) */



};




uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
                                             //Tap once for Esc, twice for Caps Lock
                                             [TD_ESC_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS)
                                             // Other declarations would go here, separated by commas, if you have them
};


void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            persistent_default_layer_set(1UL<<_QWERTY);
          }
          return false;
          break;
        case COLEMAK:
          if (record->event.pressed) {
            persistent_default_layer_set(1UL<<_COLEMAK);
          }
          return false;
          break;
  }
    return true;
};
