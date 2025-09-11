#ifndef  DIRECTIONS_H_
#define  DIRECTIONS_H_


#include <ncurses.h>

typedef enum {
    UP = KEY_UP, 
    DOWN = KEY_DOWN,
    LEFT = KEY_LEFT, 
    RIGHT = KEY_RIGHT, 
    NU_DIRECTIONS
} Direction_t;


#endif   // DIRECTIONS_H_