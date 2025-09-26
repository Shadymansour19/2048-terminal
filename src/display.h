#ifndef  DISPLAY_H_
#define  DISPLAY_H_


#include <ncurses.h>
#include "colors.h"
#include "gameSettings.h"
#include <string.h>
#include "cell.h"


#define     displayMessage                printw
#define     displayGetPressedKey          getch
#define     displayMoveCursor             move
#define     displayClearAll               clear
#define     displayQuit                   endwin


void displayInit(void);
void displayHelpScreen(void);
void displaySplashScreen(void);
void ensureBoardFit(const int bs);                  // bs = board size
void displayReinit(void);
void displayScore(const int score);
void displayCell(const int row, const int col, const Cell_t cellVal);
void clearCell(const int row, const int col);
void displayTrailer(const char** msgs);
void clearTrailer(void);
bool displayEndGame(const int finalScore);


#endif   // DISPLAY_H_