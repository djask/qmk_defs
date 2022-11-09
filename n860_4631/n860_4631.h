#include "quantum.h"
/*
#define LAYOUT( \
    k00, k01, k02, k03, k04, k05, k06, k07, \
    k10, k11, k12, k13, k14, k15, k16, k17, \
    k20, k21, k22, k23, k24, k25, k26, k27, \
    k30, k31, k32, k33, k34, k35, k36, k37, \
    k40, k41, k42, k43, k44, k45, k46, k47, \
    k50, k51, k52, k53, k54, k55, k56, k57, \
    k60, k61, k62, k63, k64, k65, k66, k67, \
    k70, k71, k72, k73, k74, k75, k76, k77, \
    k80, k81, k82, k83, k84, k85, k86, k87, \
    k90, k91, k92, k93, k94, k95, k96, k97, \
    ka0, ka1, ka2, ka3, ka4, ka5, ka6, ka7, \
    kb0, kb1, kb2, kb3, kb4, kb5, kb6, kb7, \
    kc0, kc1, kc2, kc3, kc4, kc5, kc6, kc7, \
    kd0, kd1, kd2, kd3, kd4, kd5, kd6, kd7, \
    ke0, ke1, ke2, ke3, ke4, ke5, ke6, ke7, \
    kf0, kf1, kf2, kf3, kf4, kf5, kf6, kf7 \
) { \
    {k00, k01, k02, k03, k04, k05, k06, k07}, \
    {k10, k11, k12, k13, k14, k15, k16, k17}, \
    {k20, k21, k22, k23, k24, k25, k26, k27}, \
    {k30, k31, k32, k33, k34, k35, k36, k37}, \
    {k40, k41, k42, k43, k44, k45, k46, k47}, \
    {k50, k51, k52, k53, k54, k55, k56, k57}, \
    {k60, k61, k62, k63, k64, k65, k66, k67}, \
    {k70, k71, k72, k73, k74, k75, k76, k77}, \
    {k80, k81, k82, k83, k84, k85, k86, k87}, \
    {k90, k91, k92, k93, k94, k95, k96, k97}, \
    {ka0, ka1, ka2, ka3, ka4, ka5, ka6, ka7}, \
    {kb0, kb1, kb2, kb3, kb4, kb5, kb6, kb7}, \
    {kc0, kc1, kc2, kc3, kc4, kc5, kc6, kc7}, \
    {kd0, kd1, kd2, kd3, kd4, kd5, kd6, kd7}, \
    {ke0, ke1, ke2, ke3, ke4, ke5, ke6, ke7}, \
    {kf0, kf1, kf2, kf3, kf4, kf5, kf6, kf7} \
}
#define kEYMAP LAYOUT

*/

// note left and right shift are hardwired to same matrix location
// also note the numpad cluster does not exist and can be connected in side port
// this accessory is so rare though, that I can't test it and don't think anyone else will be able to either

#define LAYOUT( \
k06, k16,  k26, k36, k46, k56, k66,  k86, k96, ka6,   kc6, kd6,       k07, k17, k27,  ke3, ke4, ke6, ke7, \
                                                                      k37, k47, k57,  kf3, kf4, kf6, kf7, \
  k15, k25, k35, k45, k55, k65, k75, k85, k95, ka5, kb5, kc5, ke5,    k67, k77, k87,  \
k04, k14, k24, k34, k44, k54, k64, k74, k84, k94, ka4, kb4,   kd4,                    k60, k70, ka0, kc0, \
k03,  k13, k23, k33, k43, k53, k63, k73, k83, k93, ka3, kb3,  kc3,         k97,       kd1, kc2, kd2, ke2, \
k80,    k12, k22, k32, k42, k52, k62, k72, k82, k92, ka2,             ka7, kc7, kb7,  k91, ka1, kc1, kf2, \
k90,      k11,        k10,         k20,          kb1,                                 k61, k71, k81, kf5, \
                            ke1,  kf1,                                     kd7,         kd3,    kd0 \
) { \
    {KC_NO, KC_NO, KC_NO, k03, k04, KC_NO, k06, k07}, \
    {k10, k11, k12, k13, k14, k15, k16, k17}, \
    {k20, KC_NO, k22, k23, k24, k25, k26, k27}, \
    {KC_NO, KC_NO, k32, k33, k34, k35, k36, k37}, \
    {KC_NO, KC_NO,  k42, k43, k44, k45, k46, k47}, \
    {KC_NO, KC_NO, k52, k53, k54, k55, k56, k57}, \
    {k60, k61, k62, k63, k64, k65, k66, k67}, \
    {k70, k71, k72, k73, k74, k75, KC_NO, k77}, \
    {k80, k81, k82, k83, k84, k85, k86, k87}, \
    {k90, k91, k92, k93, k94, k95, k96, k97}, \
    {ka0, ka1, ka2, ka3, ka4, ka5, ka6, ka7}, \
    {KC_NO, kb1, KC_NO, kb3, kb4, kb5, KC_NO, kb7}, \
    {kc0, kc1, kc2, kc3, KC_NO, kc5, kc6, kc7}, \
    {kd0, kd1, kd2, kd3, kd4, KC_NO, kd6, kd7}, \
    {KC_NO, ke1, ke2, ke3, ke4, ke5, ke6, ke7}, \
    {KC_NO, kf1, kf2, kf3, kf4, kf5, kf6, kf7} \
}
#define kEYMAP LAYOUT
