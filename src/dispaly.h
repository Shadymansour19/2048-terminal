#ifndef  DISPALY_H_
#define  DISPALY_H_


#include <ncurses.h>
#include "colors.h"
#include <string.h>

void displayInit(int boardSize);
void displayScore(int score);
void displayCell(int row, int col, int cellVal);
void clearCell(int row, int col);
bool displayEndGame(int finalScore);


#endif   // DISPALY_H_