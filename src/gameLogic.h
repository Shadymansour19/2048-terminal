#ifndef  GAMELOGIC_H_
#define  GAMELOGIC_H_


#include "board.h"
#include "miniMax.h"


#define  PROBABILITY_LOW                    (0.7)                                         // Defines probability to fill new cells with the lower of available two choices
#define  LOWEST_MSB(maxMsb, boardSize)      (MAX(1, (maxMsb) - 4 - (boardSize)))          // user-defined function for lowest msb to fill new cells with as a function of current max msb & board size

#define  MIN_BOARD_SIZE                     (3)
#define  MAX_BOARD_SIZE                     (6)



void newGame(void);


#endif   // GAMELOGIC_H_