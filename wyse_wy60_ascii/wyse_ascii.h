#include "quantum.h"

#define LAYOUT( \
    k00, k01, k02, k03, k04, k05, k06, k10, k11, k12, k13, k14, k15, k16, k20, k21,       k07, k27, \
    k37, k18, k08, k39, k30, k31, k32, k33, k34, k35, k36, k28, k19, k29, k09,     k6b, k1a, k5c, k38, \
    k49, k40, k42, k41, k43, k45, k47, k46, k48, k4c, k44, k5a, k4b, k6a, k7a,     k76, k78, k4a, k57, \
    k3c, k59, k50, k52, k51, k53, k54, k55, k56, k58, k5b, k77, k6c, k7c,          k73, k74, k75, k0a, \
    k17, k0b, k68, k61, k60, k62, k65, k63, k64, k67, k66, k69, k2b, k7b, k25,     k70, k71, k72,  \
    k1b,                       k1c,                      k26,   k22, k24, k23,     k79, k2a,      k3a  \
) { \
    { k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, KC_NO  }, \
    { k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c  }, \
    { k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, KC_NO  }, \
    { k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, KC_NO, k3c }, \
    { k40, k41, k42, k43, k44, k45, k46, k47, k48, k49, k4a, k4b, k4c  }, \
    { k50, k51, k52, k53, k54, k55, k56, k57, k58, k59, k5a, k5b, k5c  }, \
    { k60, k61, k62, k63, k64, k65, k66, k67, k68, k69, k6a, k6b, k6c  }, \
    { k70, k71, k72, k73, k74, k75, k76, k77, k78, k79, k7a, k7b, k7c  } \
}

#define kEYMAP LAYOUT