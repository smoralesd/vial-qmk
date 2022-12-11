#include QMK_KEYBOARD_H

enum layers {
    WRKMN,
    _NAVR,
    _MOUS,
    _MEDR,
    __NSL,
    _NSSL,
    _FUNL,
    _MACR
};

#define XXXXXXX KC_NO

// home row key definitions for WORKMAN layout
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_H LCTL_T(KC_H)
#define HOME_T LSFT_T(KC_T)
#define HOME_X RALT_T(KC_X)
#define HOME_G LT(_MACR, KC_G)

#define HOME_N LSFT_T(KC_N)
#define HOME_E LCTL_T(KC_E)
#define HOME_O LALT_T(KC_O)
#define HOME_I LGUI_T(KC_I)
#define HOME_DT RALT_T(KC_DOT)

// layer management
#define NAVR LT(_NAVR, KC_SPC)
#define MOUS LT(_MOUS, KC_TAB)
#define MEDR LT(_MEDR, KC_ESC)
#define NSL LT(__NSL, KC_BSPC)
#define NSSL LT(_NSSL, KC_ENT)
#define FUNL LT(_FUNL, KC_DEL)

// shortcuts
#define CUT LCTL(KC_X)
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)

enum custom_macros {
    LAMBDA = SAFE_RANGE,
    ARROW,
    FUNC
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode)
    {
    case LAMBDA:
        if (!record->event.pressed) {
            SEND_STRING("() => {}");
        }
        break;

    case ARROW:
        if (!record->event.pressed) {
            SEND_STRING("=>");
        }
        break;

    case FUNC:
        if (!record->event.pressed) {
            SEND_STRING("() {}");
        }
        break;

    default:
        break;
    }

    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [WRKMN] = LAYOUT_3x5_3(
        KC_Q   ,KC_D   ,KC_R   ,KC_W   ,KC_B   ,                       KC_J   ,KC_F   ,KC_U   ,KC_P   ,KC_QUOT,
        HOME_A ,HOME_S ,HOME_H ,HOME_T ,HOME_G ,                       KC_Y   ,HOME_N ,HOME_E ,HOME_O ,HOME_I ,
        KC_Z   ,HOME_X ,KC_M   ,KC_C   ,KC_V   ,                       KC_K   ,KC_L   ,KC_COMM,HOME_DT,KC_SLSH,
                        MEDR   ,NAVR   ,MOUS   ,                       NSSL   ,NSL    ,FUNL
    ),

    [_NAVR] = LAYOUT_3x5_3(
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                       KC_CAPS,KC_UNDO,CUT    ,COPY   ,PASTE  ,
        KC_LGUI,KC_LALT,KC_LCTL,KC_LSFT,XXXXXXX,                       KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,XXXXXXX,
        XXXXXXX,KC_RALT,XXXXXXX,XXXXXXX,XXXXXXX,                       KC_HOME,KC_PGDN,KC_PGUP,KC_END ,KC_INS ,
                        XXXXXXX,XXXXXXX,XXXXXXX,                       KC_ENT ,KC_BSPC,KC_DEL
    ),

    [_MOUS] = LAYOUT_3x5_3(
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                       XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
        KC_LGUI,KC_LALT,KC_LCTL,KC_LSFT,XXXXXXX,                       KC_MS_L,KC_MS_D,KC_MS_U,KC_MS_R,XXXXXXX,
        XXXXXXX,KC_RALT,XXXXXXX,XXXXXXX,XXXXXXX,                       KC_WH_L,KC_WH_D,KC_WH_U,KC_WH_R,XXXXXXX,
                        XXXXXXX,XXXXXXX,XXXXXXX,                       KC_BTN1,KC_BTN3,KC_BTN2
    ),

    [_MEDR] = LAYOUT_3x5_3(
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                       XXXXXXX,KC_BRID,KC_BRIU,XXXXXXX,XXXXXXX,
        KC_LGUI,KC_LALT,KC_LCTL,KC_LSFT,XXXXXXX,                       KC_MPRV,KC_VOLD,KC_VOLU,KC_MNXT,XXXXXXX,
        XXXXXXX,KC_RALT,XXXXXXX,XXXXXXX,XXXXXXX,                       XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
                        XXXXXXX,XXXXXXX,XXXXXXX,                       KC_MSTP,KC_MPLY,KC_MUTE
    ),

    [__NSL] = LAYOUT_3x5_3(
        KC_LBRC,KC_7   ,KC_8   ,KC_9   ,KC_RBRC,                      XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
        KC_SCLN,KC_4   ,KC_5   ,KC_6   ,KC_EQL ,                      XXXXXXX,KC_LSFT,KC_LCTL,KC_LALT,KC_LGUI,
        KC_GRV ,KC_1   ,KC_2   ,KC_3   ,KC_BSLS,                      XXXXXXX,XXXXXXX,XXXXXXX,KC_RALT,XXXXXXX,
                        KC_DOT ,KC_0   ,KC_MINS,                      XXXXXXX,XXXXXXX,XXXXXXX
    ),

    [_NSSL] = LAYOUT_3x5_3(
        KC_LCBR,KC_AMPR,KC_ASTR,KC_LPRN,KC_RCBR,                     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
        KC_COLN,KC_DLR ,KC_PERC,KC_CIRC,KC_PLUS,                     XXXXXXX,KC_LSFT,KC_LCTL,KC_LALT,KC_LGUI,
        KC_TILD,KC_EXLM,KC_AT  ,KC_HASH,KC_PIPE,                     XXXXXXX,XXXXXXX,XXXXXXX,KC_RALT,XXXXXXX,
                        KC_LPRN,KC_RPRN,KC_UNDS,                     XXXXXXX,XXXXXXX,XXXXXXX
    ),

    [_FUNL] = LAYOUT_3x5_3(
        KC_F12 ,KC_F7  ,KC_F8  ,KC_F9  ,XXXXXXX,                    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
        KC_F11 ,KC_F4  ,KC_F5  ,KC_F6  ,XXXXXXX,                    XXXXXXX,KC_LSFT,KC_LCTL,KC_LALT,KC_LGUI,
        KC_F10 ,KC_F1  ,KC_F2  ,KC_F3  ,XXXXXXX,                    XXXXXXX,XXXXXXX,XXXXXXX,KC_RALT,XXXXXXX,
                        KC_APP ,KC_SPC ,KC_TAB ,                    XXXXXXX,XXXXXXX,XXXXXXX
    ),

    [_MACR] = LAYOUT_3x5_3(
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                    XXXXXXX,ARROW  ,LAMBDA ,FUNC   ,XXXXXXX,
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
                        XXXXXXX,XXXXXXX,XXXXXXX,                    XXXXXXX,XXXXXXX,XXXXXXX
    )
};
