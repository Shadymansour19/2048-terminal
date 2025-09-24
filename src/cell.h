#ifndef  CELL_H_
#define  CELL_H_



#include "gameSettings.h"
#include "miniMax.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



#define     EMPTY_CELL      (0) 
#define     CELL_MIN        (1) 
#define     CELL_MAX        (32) 



typedef unsigned char Cell_t;        // define cell value using its msb as cell value is always a power of 2


Cell_t newCell(int boardSize, Cell_t maxCell);
void getCellDisplayStr(Cell_t cell, char* str);




#endif   // CELL_H_