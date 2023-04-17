#include QMK_KEYBOARD_H


// カナ, CAPS is locking
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
	QK_BOOT,KC_COPY,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,                          KC_PGUP,KC_PGDN,
	QK_GESC,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_MINS,KC_EQL ,KC_INT3,KC_BSPC,  KC_INS ,KC_DEL ,  KC_HOME,KC_HELP,KC_PMNS,KC_PSLS,
	KC_TAB ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_LBRC,KC_RBRC,KC_ENT,                             KC_P7  ,KC_P8  ,KC_P9  ,KC_PAST,
	KC_LCTL,KC_NO  ,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_SCLN,KC_QUOT,KC_NUHS,              KC_UP  ,      KC_P4  ,KC_P5  ,KC_P6  ,KC_PPLS,
	KC_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,KC_INT1,                          KC_LEFT,KC_RGHT,  KC_P1  ,KC_P2  ,KC_P3  ,KC_PEQL,
	        MO(1)  ,KC_LGUI,KC_LALT,                KC_SPC ,                        KC_RALT,                                      KC_DOWN,      KC_P0  ,KC_PCMM,KC_PDOT
    ),
    [1] = LAYOUT(
	_______,NK_TOGG,KC_F11 ,KC_F12 ,KC_F13 ,KC_F14 ,KC_F15 ,KC_F16 ,KC_F17 ,KC_F18 ,KC_F19 ,KC_F20 ,                          _______,_______,
	_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,  _______,_______,  KC_NUM ,_______,_______,_______,
	_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,                            _______,_______,_______,_______,
	_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,              _______,      _______,_______,_______,_______,
	KC_RSFT,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,                          _______,_______,  _______,_______,_______,_______,
	        _______,_______,_______,                _______,                        _______,                                      _______,      _______,_______,_______
    )
};
