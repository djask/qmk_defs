#include "quantum.h"

// LSHIFT = RSHIFT
// ENTER = PAD ENTER
#define LAYOUT( \
        k12, k13,  k40, k41, k50, k51, k60, k61, k70, k71, k80, k81,   k92,k93, \
        k14, k15,k32,k33,k42,k43,k52,k53,k62,k63,k72,k73,k82,k83,k85,  k91,k95,  ka2,ka3,kb2,kb3, \
        k16, k17,k34,k35,k44,k45,k54,k55,k64,k65,k74,k75,k84,  k87,              ka4,ka5,kb4,kb5, \
        k10,k11,k27,k36,k37,k46,k47,k56,k57,k66,k67,k76,k77,k86,         k96,    ka6,ka7,kb6,kb7, \
        k01,  k29,k38,k39,k48,k49,k58,k59,k68,k69,k78,k79,             k98,k99,  ka8,ka9,kb8,kb9, \
            k20,k21, k3a,            k5a,            k7a,                k8a,    k9a,kaa,kba     \
) { \
  {KC_NO, k01, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO}, \
  {k10, k11, k12, k13, k14, k15, k16, k17, KC_NO, KC_NO, KC_NO}, \
  {k20, k21, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, k27, KC_NO, k29, KC_NO}, \
  {KC_NO, KC_NO, k32, k33, k34, k35, k36, k37, k38, k39, k3a}, \
  {k40, k41, k42, k43, k44, k45, k46, k47, k48, k49, KC_NO}, \
  {k50, k51, k52, k53, k54, k55, k56, k57, k58, k59, k5a}, \
  {k60, k61, k62, k63, k64, k65, k66, k67, k68, k69, KC_NO}, \
  {k70, k71, k72, k73, k74, k75, k76, k77, k78, k79, k7a}, \
  {k80, k81, k82, k83, k84, k85, k86, k87, KC_NO, KC_NO, k8a}, \
  {KC_NO, k91, k92, k93, KC_NO, k95, k96, KC_NO, k98, k99, k9a}, \
  {KC_NO, KC_NO, ka2, ka3, ka4, ka5, ka6, ka7, ka8, ka9, kaa}, \
  {KC_NO, KC_NO, kb2, kb3, kb4, kb5, kb6, kb7, kb8, kb9, kba} \
}
#define kEYMAP LAYOUT

/*
#define LAYOUT( \
  k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, \
  k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, \
  k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, \
  k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, \
  k40, k41, k42, k43, k44, k45, k46, k47, k48, k49, k4a, \
  k50, k51, k52, k53, k54, k55, k56, k57, k58, k59, k5a, \
  k60, k61, k62, k63, k64, k65, k66, k67, k68, k69, k6a, \
  k70, k71, k72, k73, k74, k75, k76, k77, k78, k79, k7a, \
  k80, k81, k82, k83, k84, k85, k86, k87, k88, k89, k8a, \
  k90, k91, k92, k93, k94, k95, k96, k97, k98, k99, k9a, \
  ka0, ka1, ka2, ka3, ka4, ka5, ka6, ka7, ka8, ka9, kaa, \
  kb0, kb1, kb2, kb3, kb4, kb5, kb6, kb7, kb8, kb9, kba \
) { \
  {k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a}, \
  {k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a}, \
  {k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a}, \
  {k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a}, \
  {k40, k41, k42, k43, k44, k45, k46, k47, k48, k49, k4a}, \
  {k50, k51, k52, k53, k54, k55, k56, k57, k58, k59, k5a}, \
  {k60, k61, k62, k63, k64, k65, k66, k67, k68, k69, k6a}, \
  {k70, k71, k72, k73, k74, k75, k76, k77, k78, k79, k7a}, \
  {k80, k81, k82, k83, k84, k85, k86, k87, k88, k89, k8a}, \
  {k90, k91, k92, k93, k94, k95, k96, k97, k98, k99, k9a}, \
  {ka0, ka1, ka2, ka3, ka4, ka5, ka6, ka7, ka8, ka9, kaa}, \
  {kb0, kb1, kb2, kb3, kb4, kb5, kb6, kb7, kb8, kb9, kba} \
}
#define kEYMAP LAYOUT
*/
