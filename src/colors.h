#ifndef  COLORS_H_
#define  COLORS_H_

#include <ncurses.h>


extern const int BACKGROUND_COLOR[32];

#define COLOR_GRAY      (8)
#define COLOR_BROWN     (9)
#define COLOR_ORANGE    (10)
#define COLOR_OLIVE     (11)
#define COLOR_ROSE     (12)
#define COLOR_BLOOD     (13)


void colorsInit(void);

#endif   // COLORS_H_