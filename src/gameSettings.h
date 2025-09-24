#ifndef  GAMESETTINGS_H_
#define  GAMESETTINGS_H_



#define  UNDO_LIMIT                         (10)                                          // defines max allowable undo operations

#define  PROBABILITY_LOW                    (0.1)                                         // Defines probability to fill new cells with the lower of available two choices
#define  LOWEST_MSB(maxMsb, boardSize)      (MAX((1), (maxMsb) - (0) - (boardSize)))      // user-defined function for lowest msb to fill new cells with as a function of current max msb & board size

#define  MIN_BOARD_SIZE                     (2)
#define  MAX_BOARD_SIZE                     (9)

#define  QUIT_KEY                           ('q')
#define  UNDO_KEY                           ('u')
#define  REDO_KEY                           ('r')
#define  HELP_KEY                           ('?')
#define  HINT_KEY                           ('h')



#endif   // GAMESETTINGS_H_