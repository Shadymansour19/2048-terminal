#ifndef  GAME_H_
#define  GAME_H_


#include "gameSettings.h"
#include "board.h"


#define   STACK_CAPACITY            ((UNDO_LIMIT) + (1))


typedef struct Game_t {
    Board_t  boardsStack[STACK_CAPACITY];
    int      boardSize;
    int      boardsStackSize;
    int      currentBoardIdx;
    int      lastBoardIdx;
} Game_t;



bool initGame(int boardSize, Game_t* game);
void cloneGame(Game_t* src, Game_t* dst);
bool gameSlide(Game_t* game, Direction_t dir);
void gamePrintBoard(Game_t* game);
void gameUndo(Game_t* game);
void gameRedo(Game_t* game);
Direction_t gameHint(Game_t* game);
bool isGameOver(Game_t* game);
int  getGameScore(Game_t* game);
void freeGame(Game_t* game);



#endif   // GAME_H_