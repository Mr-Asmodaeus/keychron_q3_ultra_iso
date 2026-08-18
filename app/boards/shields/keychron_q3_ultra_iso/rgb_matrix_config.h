#pragma once
#include "rgb_matrix_types.h"

#define __ NO_LED
led_config_t g_led_config = {
    {// Key Matrix to LED Index
     // ISO layout: 88 LEDs
     // Row 0: ESC, F1-F12, Mute(encoder), PrtSc, ScrLk, Calc = 13 keys + gap + 3 nav = 16 LED indices
     {
         0,
         1,
         2,
         3,
         4,
         5,
         6,
         7,
         8,
         9,
         10,
         11,
         12,
         __,
         13,
         14,
         15,
     },
     // Row 1: Grave,1-0,Minus,Equal,Backspace, Ins,Home,PgUp = 14 keys + 3 nav = 17 LED indices
     {
         16,
         17,
         18,
         19,
         20,
         21,
         22,
         23,
         24,
         25,
         26,
         27,
         28,
         29,
         30,
         31,
         32,
     },
     // Row 2: Tab,Q-],Enter(ISO L-shape at col13), Del,End,PgDn = 13 keys + enter + 3 nav
     {
         33,
         34,
         35,
         36,
         37,
         38,
         39,
         40,
         41,
         42,
         43,
         44,
         45,
         46,
         47,
         48,
         49,
     },
     // Row 3: Caps,A-L,;,',NUHS = 13 keys (Enter is at row 2 col 13 in ISO)
     {
         50,
         51,
         52,
         53,
         54,
         55,
         56,
         57,
         58,
         59,
         60,
         61,
         __,
         62,
         __,
         __,
         __,
     },

     // Row 4: LShift,NUBS,Z-/,RShift, Up = 14 keys
     {
         63,
         64,
         65,
         66,
         67,
         68,
         69,
         70,
         71,
         72,
         73,
         74,
         __,
         75,
         __,
         76,
         __,
     },
     // Row 5: LCtrl,Win/Opt,Alt/Cmd,Space,RAlt/RCmd,RWin/ROpt,Fn,RCtrl, Left,Down,Right = 11 keys
     {77, 78, 79, __, __, __, 80, __, __, __, 81, 82, 83, 84, 85, 86, 87}},
    {
     // LED Index to Physical Position (scaled to 0-224 x 0-64)
     // Row 0 (y=0): ESC, F1-F12, (gap), Mute, PrtSc, ScrLk, Calc
     {0, 0},    {16, 0},   {29, 0},   {42, 0},   {54, 0},   {66, 0},   {84, 0},   {97, 0},
     {110, 0},  {126, 0},  {139, 0},  {152, 0},  {165, 0},             {198, 0},  {211, 0},  {224, 0},
     // Row 1 (y=15): Grave, 1-0, -, =, Backspace, Ins, Home, PgUp
     {0, 15},   {13, 15},  {26, 15},  {39, 15},  {52, 15},  {65, 15},  {78, 15},  {91, 15},
     {104, 15}, {117, 15}, {130, 15}, {143, 15}, {156, 15}, {176, 15}, {198, 15}, {211, 15}, {224, 15},
     // Row 2 (y=28): Tab, Q-], (ISO Enter top), Del, End, PgDn
     {3, 28},   {20, 28},  {33, 28},  {46, 28},  {59, 28},  {72, 28},  {85, 28},  {98, 28},
     {111, 28}, {124, 28}, {137, 28}, {150, 28}, {163, 28}, {178, 34}, {198, 28}, {211, 28}, {224, 28},
     // Row 3 (y=40): Caps, A-L, ;, ', NUHS
     {5, 40},   {23, 40},  {36, 40},  {49, 40},  {62, 40},  {75, 40},  {88, 40},  {101, 40},
     {114, 40}, {127, 40}, {140, 40}, {150, 40}, {166, 40},
     // Row 4 (y=52): LShift, NUBS, Z-/, RShift, Up
     {2, 52},   {16, 52},  {29, 52},  {42, 52},  {55, 52},  {68, 52},  {81, 52},  {94, 52},
     {107, 52}, {120, 52}, {133, 52}, {146, 52},            {171, 52},            {211, 52},
     // Row 5 (y=64): LCtrl, Win/Opt, Alt/Cmd, Space, RAlt/RCmd, RWin/ROpt, Fn, RCtrl, Left, Down, Right
     {2, 64},   {18, 64},  {34, 64},                          {83, 64},
                                      {131, 64}, {148, 64}, {164, 64}, {178, 64}, {198, 64}, {211, 64}, {224, 64}

    },
    {
        // RGB LED Index to Flag
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,    1, 1, 1, 1,
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 1,
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 1,
        8, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1,
        1, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    1,    1,
        1, 1, 1,          4,          1, 1, 1, 1, 1, 1, 1
    }

};
#ifdef CONFIG_KEYCHRON_RGB_ENABLE
#define DC_RED                                                                                     \
    { 0, 255, 255 }
#define DC_BLU                                                                                     \
    { 170, 255, 255 }
#define DC_YLW                                                                                     \
    { 43, 255, 255 }
#define DC_NUL                                                                                     \
    { 0, 0, 0 }

HSV default_per_key_led[RGB_MATRIX_LED_COUNT] = {
    DC_RED, DC_YLW, DC_YLW, DC_YLW, DC_YLW, DC_YLW, DC_YLW, DC_YLW, DC_YLW, DC_YLW, DC_YLW,
    DC_YLW, DC_YLW,         DC_YLW, DC_YLW, DC_YLW,
    DC_BLU, DC_BLU, DC_BLU, DC_BLU, DC_BLU, DC_BLU, DC_BLU, DC_BLU, DC_BLU, DC_BLU, DC_BLU,
    DC_BLU, DC_BLU, DC_YLW, DC_YLW, DC_YLW, DC_YLW,
    DC_YLW, DC_BLU, DC_BLU, DC_BLU, DC_BLU, DC_BLU, DC_BLU, DC_BLU, DC_BLU, DC_BLU, DC_BLU,
    DC_BLU, DC_BLU, DC_RED, DC_YLW, DC_YLW, DC_YLW,
    DC_YLW, DC_BLU, DC_BLU, DC_BLU, DC_BLU, DC_BLU, DC_BLU, DC_BLU, DC_BLU, DC_BLU, DC_BLU,
    DC_BLU, DC_BLU,
    DC_YLW, DC_YLW, DC_BLU, DC_BLU, DC_BLU, DC_BLU, DC_BLU, DC_BLU, DC_BLU, DC_BLU, DC_BLU,
    DC_BLU,         DC_YLW,         DC_YLW,
    DC_YLW, DC_YLW, DC_YLW,                         DC_BLU,                         DC_YLW,
    DC_YLW, DC_YLW, DC_YLW, DC_YLW, DC_YLW, DC_YLW,

};

// Default mixed RGB region
uint8_t default_region[RGB_MATRIX_LED_COUNT] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0,    // 16
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    // 17
    0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    // 17
    0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,                 // 13
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0,    0,        // 14
    0, 0, 0,          0,          0, 0, 0, 0, 0, 0, 0,      // 11
};
#endif
