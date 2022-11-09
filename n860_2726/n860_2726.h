#include "quantum.h"

/*
#define LAYOUT( \
    k00, k01, k02, k03, k04, k05, k06, \
    k10, k11, k12, k13, k14, k15, k16, \
    k20, k21, k22, k23, k24, k25, k26, \
    k30, k31, k32, k33, k34, k35, k36, \
    k40, k41, k42, k43, k44, k45, k46, \
    k50, k51, k52, k53, k54, k55, k56, \
    k60, k61, k62, k63, k64, k65, k66, \
    k70, k71, k72, k73, k74, k75, k76, \
    k80, k81, k82, k83, k84, k85, k86, \
    k90, k91, k92, k93, k94, k95, k96, \
    ka0, ka1, ka2, ka3, ka4, ka5, ka6, \
    kb0, kb1, kb2, kb3, kb4, kb5, kb6, \
    kc0, kc1, kc2, kc3, kc4, kc5, kc6, \
    kd0, kd1, kd2, kd3, kd4, kd5, kd6, \
    ke0, ke1, ke2, ke3, ke4, ke5, ke6, \
    kf0, kf1, kf2, kf3, kf4, kf5, kf6 \
) { \
    {k00, k01, k02, k03, k04, k05, k06}, \
    {k10, k11, k12, k13, k14, k15, k16}, \
    {k20, k21, k22, k23, k24, k25, k26}, \
    {k30, k31, k32, k33, k34, k35, k36}, \
    {k40, k41, k42, k43, k44, k45, k46}, \
    {k50, k51, k52, k53, k54, k55, k56}, \
    {k60, k61, k62, k63, k64, k65, k66}, \
    {k70, k71, k72, k73, k74, k75, k76}, \
    {k80, k81, k82, k83, k84, k85, k86}, \
    {k90, k91, k92, k93, k94, k95, k96}, \
    {ka0, ka1, ka2, ka3, ka4, ka5, ka6}, \
    {kb0, kb1, kb2, kb3, kb4, kb5, kb6}, \
    {kc0, kc1, kc2, kc3, kc4, kc5, kc6}, \
    {kd0, kd1, kd2, kd3, kd4, kd5, kd6}, \
    {ke0, ke1, ke2, ke3, ke4, ke5, ke6}, \
    {kf0, kf1, kf2, kf3, kf4, kf5, kf6} \
}
*/


// wtf is this layout

//BREAK key is mapped to F0 via external to matrix direct pin
#define LAYOUT( \
    kf0,      k10, k20, k30, k40, k50, k60, k70, k80, k90, ka0, \
    k00, k01, k11, k21, k31, k41, k51, k61, k71, k81, k91, ka1, kb1, kc1, kc2,      kd1, ke1,  k84, k74, k64, k54, \
    k05, k02, k12, k22, k32, k42, k52, k62, k72, k82, k92, ka2, kb2,                kd2, ke2,  k85, k75, k65, k55, \
    kf3, k03, k13, k23, k33, k43, k53, k63, k73, k83, k93, ka3, kb3,     kc3,       kd3, ke3,  k95, ka5, kb5, kc5, \
    kf1, k06, k16, k26, k36, k46, k56, k66, k76, k86, k96, ka6,          kf6,       kd6, ke6,  k94, ka4, kb4, \
        kf2, kf5,            k45,                     kb0, kf4,                kc0, kd5, ke5,     kd4,   ke4,  kc4, \
                       ke0, kd0 \
) { \
    {k00, k01, k02, k03, KC_NO, k05, k06}, \
    {k10, k11, k12, k13, KC_NO, KC_NO, k16}, \
    {k20, k21, k22, k23, KC_NO, KC_NO, k26}, \
    {k30, k31, k32, k33, KC_NO, KC_NO, k36}, \
    {k40, k41, k42, k43, KC_NO, k45, k46}, \
    {k50, k51, k52, k53, k54, k55, k56}, \
    {k60, k61, k62, k63, k64, k65, k66}, \
    {k70, k71, k72, k73, k74, k75, k76}, \
    {k80, k81, k82, k83, k84, k85, k86}, \
    {k90, k91, k92, k93, k94, k95, k96}, \
    {ka0, ka1, ka2, ka3, ka4, ka5, ka6}, \
    {kb0, kb1, kb2, kb3, kb4, kb5, KC_NO}, \
    {kc0, kc1, kc2, kc3, kc4, kc5, KC_NO}, \
    {kd0, kd1, kd2, kd3, kd4, kd5, kd6}, \
    {ke0, ke1, ke2, ke3, ke4, ke5, ke6}, \
    {kf0, kf1, kf2, kf3, kf4, kf5, kf6} \
}
#define kEYMAP LAYOUT
