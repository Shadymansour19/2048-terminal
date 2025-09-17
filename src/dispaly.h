#ifndef  DISPALY_H_
#define  DISPALY_H_


#include <ncurses.h>
#include "colors.h"
#include <string.h>


#define     displayMessage                printw
#define     displayGetPressedKey          getch
#define     displayMoveCursor             move

void displayInit();
void displayBoardInit(int boardSize);
void displayScore(int score);
void displayCell(int row, int col, int cellVal);
void clearCell(int row, int col);
bool displayEndGame(int finalScore);


#endif   // DISPALY_H_