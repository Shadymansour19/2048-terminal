#include "colors.h"


const int BACKGROUND_COLOR[32] = {
    COLOR_BLACK,                // Background color for Empty cell
    COLOR_YELLOW,               // Background color for cell with value 2           (2^1)
    COLOR_ORANGE,               // Background color for cell with value 4           (2^2)
    COLOR_RED,                  // Background color for cell with value 8           (2^3)
    COLOR_BROWN,                // Background color for cell with value 16          (2^4)
    COLOR_GRAY,                 // Background color for cell with value 32          (2^5)
    COLOR_GREEN,                // Background color for cell with value 64          (2^6)
    COLOR_CYAN,                 // Background color for cell with value 128         (2^7)
    COLOR_BLUE,                 // Background color for cell with value 256         (2^8)
    COLOR_MAGENTA,              // Background color for cell with value 512         (2^9)
    COLOR_BLOOD,                // Background color for cell with value 1024        (2^10)
    COLOR_ROSE,                 // Background color for cell with value 2048        (2^11)
    COLOR_OLIVE,                // Background color for cell with value 4096        (2^12)
    COLOR_YELLOW,               // Background color for cell with value 8192        (2^13)
    COLOR_ORANGE,               // Background color for cell with value 16384       (2^14)
    COLOR_RED,                  // Background color for cell with value 32768       (2^15)
    COLOR_GRAY,                 // Background color for cell with value 65636       (2^16)
    COLOR_GREEN,                // Background color for cell with value 131072      (2^17)
    COLOR_BROWN,                // Background color for cell with value 262144      (2^18)
    COLOR_BLUE,                 // Background color for cell with value 524288      (2^19)
    COLOR_ROSE,                 // Background color for cell with value 1048576     (2^20)
    COLOR_MAGENTA,              // Background color for cell with value 2097152     (2^21)
    COLOR_BLOOD,                // Background color for cell with value 4194304     (2^22)
    COLOR_OLIVE,                // Background color for cell with value 8388608     (2^23)
    COLOR_CYAN,                 // Background color for cell with value 16777216    (2^24)
};


void colorsInit(void) {
    init_color(COLOR_GRAY, 400, 400, 400);
    init_color(COLOR_BROWN, 500, 300, 200);
    init_color(COLOR_ORANGE, 800, 500, 200);
    init_color(COLOR_YELLOW, 800, 700, 20);
    init_color(COLOR_MAGENTA, 600, 0, 600);
    init_color(COLOR_OLIVE, 400, 420, 150);
    init_color(COLOR_BLUE, 400, 350, 900);
    init_color(COLOR_ROSE, 800, 400, 400);
    init_color(COLOR_BLOOD, 450, 50, 50);
}