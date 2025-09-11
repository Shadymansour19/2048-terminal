#ifndef  BOARD_H_
#define  BOARD_H_


#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "directions.h"
#include <stdbool.h>
#include "dispaly.h"
#include "gameLogic.h"
#include "miniMax.h"


typedef struct Board_t {
    int    size;
    int    score;
    char** cellsMsb;
    char   maxMsb;
} Board_t;


Board_t* newBoard(int size);
void printBoard(Board_t* board);
bool canBoardMove(Board_t* board);
bool moveBoard(Board_t* board, Direction_t dir);
bool moveBoardUp(Board_t* board);
bool moveBoardDown(Board_t* board);
bool moveBoardLeft(Board_t* board);
bool moveBoardRight(Board_t* board);
void freeBoard(Board_t* board);


#endif   // BOARD_H_