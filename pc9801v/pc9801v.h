#include "quantum.h"

// LSHIFT = RSHIFT
// ENTER = PAD ENTER
#define LAYOUT( \
        k0b, k0c,  k65, k66, k67, k68, k69, k6a, k6b, k6c, k6d, k6e,   k2c,k2d, \
        k0d, k00,k01,k02,k03,k04,k05,k06,k07,k08,k09,k0a,k10,k11,k0e,  k7e,k2b,  k4b,k4c,k4d,k4e, \
        k1e, k22,k21,k20,k1a,k19,k18,k17,k16,k15,k14,k13,k12,  k1b,              k45,k46,k47,k5e, \
        k60,k61,k23,k24,k25,k26,k27,k28,k29,k2a,k30,k31,k32,k33,         k2e,    k4a,k49,k48,k5a, \
        k62,  k43,k42,k41,k40,k3a,k39,k38,k37,k36,k35,k34,             k3e,k3c,  k50,k51,k52,k5b, \
            k63,k64, k1c,            k44,            k1d,                k3d,    k55,k54,k53     \
) { \
    { k00  , k01  , k02  , k03  , k04  , k05  , k06  , k07  , k08  , k09  , k0a  , k0b  , k0c  , k0d  , k0e   }, \
    { k10  , k11  , k12  , k13  , k14  , k15  , k16  , k17  , k18  , k19  , k1a  , k1b  , k1c  , k1d  , k1e   }, \
    { k20  , k21  , k22  , k23  , k24  , k25  , k26  , k27  , k28  , k29  , k2a  , k2b  , k2c  , k2d  , k2e   }, \
    { k30  , k31  , k32  , k33  , k34  , k35  , k36  , k37  , k38  , k39  , k3a  , KC_NO, k3c  , k3d  , k3e   }, \
    { k40  , k41  , k42  , k43  , k44  , k45  , k46  , k47  , k48  , k49  , k4a  , k4b  , k4c  , k4d  , k4e   }, \
    { k50  , k51  , k52  , k53  , k54  , k55  , KC_NO, KC_NO, KC_NO, KC_NO, k5a  , k5b  , KC_NO, KC_NO, k5e   }, \
    { k60  , k61  , k62  , k63  , k64  , k65  , k66  , k67  , k68  , k69  , k6a  , k6b  , k6c  , k6d  , k6e   }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, k7e   } \
}
#define kEYMAP LAYOUT
