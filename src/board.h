#ifndef  BOARD_H_
#define  BOARD_H_


#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "directions.h"
#include <stdbool.h>
#include "display.h"
#include "cell.h"
#include "gameSettings.h"
#include "miniMax.h"


typedef struct Board_t {
    int      size;
    int      score;
    Cell_t** cells;
    Cell_t   maxCell;
} Board_t;


bool initBoard(int size, Board_t* board);
void printBoard(Board_t* board);
bool canBoardMove(Board_t* board);
void copyBoard(Board_t* src, Board_t* dst);
bool slideBoard(Board_t* oldBoard, Board_t* newBoard, Direction_t dir);
void freeBoard(Board_t* board);


#endif   // BOARD_H_