#include "board.h"
#include <math.h>


static void fillOneCell(Board_t* board);


static void fillOneCell(Board_t* board) {
    int r, c;
    do {
        r = rand() % board->size;
        c = rand() % board->size;
    } while (board->cellsMsb[r][c]);
    
    board->cellsMsb[r][c] = LOWEST_MSB(board->maxMsb, board->size);
    board->cellsMsb[r][c] += ((rand() / (double) RAND_MAX) > PROBABILITY_LOW);
    board->maxMsb = MAX(board->maxMsb, board->cellsMsb[r][c]);
}


Board_t* newBoard(int size) {
    srand(time(NULL));
    Board_t* board = malloc(sizeof(Board_t));
    if (board == NULL) {
        return NULL;
    }

    board->size = size;
    board->score = 0;
    board->maxMsb = 0;
    board->cellsMsb = calloc(sizeof(int*), size);
    if (board->cellsMsb == NULL) {
        return NULL;
    }

    for (int i = 0; i < size; i++) {
        board->cellsMsb[i] = calloc(sizeof(int), size);
        if (board->cellsMsb[i] == NULL) {
            return NULL;
        }
    }

    fillOneCell(board);
    fillOneCell(board);
    
    return board;
}


void printBoard(Board_t* board) {
    displayScore(board->score);
    for (int i = 0; i < board->size; i++) {
        for (int j = 0; j < board->size; j++) {
            if (board->cellsMsb[i][j]) {
                displayCell(i, j, board->cellsMsb[i][j]);
            } else {
                clearCell(i, j);
            }
        }
    }
}


bool canBoardMove(Board_t* board) {
    for (int i = 0; i < board->size; i++) {
        for (int j = 0; j < board->size; j++) {
            if (board->cellsMsb[i][j] == 0 || (i > 0 && board->cellsMsb[i][j] == board->cellsMsb[i-1][j]) || (j > 0 && board->cellsMsb[i][j] == board->cellsMsb[i][j-1])) {
                return true;
            } 
        }
    }
    return false;
}


bool moveBoard(Board_t* board, Direction_t dir) {
    bool ret = false;
    if (dir == UP) {
        ret = moveBoardUp(board);
    } else if (dir == DOWN) {
        ret = moveBoardDown(board);
    } else if (dir == LEFT) {
        ret = moveBoardLeft(board);
    } else if (dir == RIGHT) {
        ret = moveBoardRight(board);
    } 

    if (ret) {
        fillOneCell(board);
    }
    return ret;
}



bool moveBoardUp(Board_t* board) {
    bool isAnyMoved = false;
    for (int i = 1; i < board->size; i++) {
        for (int j = 0; j < board->size; j++) {
            if (board->cellsMsb[i][j] == 0) {
                continue;
            } 
            
            int r = i;
            if (board->cellsMsb[i-1][j] == 0) {
                r = i-1;
                while (r > 0 && board->cellsMsb[r-1][j] == 0) {
                    r--;
                }
                board->cellsMsb[r][j] = board->cellsMsb[i][j];
                board->cellsMsb[i][j] = 0;
                isAnyMoved = true;
            }
            
            if (r > 0 && board->cellsMsb[r-1][j] == board->cellsMsb[r][j]) {
                board->cellsMsb[r-1][j]++;
                board->cellsMsb[r][j] = 0;
                board->score += 1 << board->cellsMsb[r-1][j];
                board->maxMsb = MAX(board->maxMsb, board->cellsMsb[r-1][j]);
                isAnyMoved = true;
            }
        }
    }
    return isAnyMoved;
}


bool moveBoardDown(Board_t* board) {
    bool isAnyMoved = false;
    for (int i = board->size - 2; i >= 0; i--) {
        for (int j = 0; j < board->size; j++) {
            if (board->cellsMsb[i][j] == 0) {
                continue;
            } 
            
            int r = i;
            if (board->cellsMsb[i+1][j] == 0) {
                r = i+1;
                while (r+1 < board->size && board->cellsMsb[r+1][j] == 0) {
                    r++;
                }
                board->cellsMsb[r][j] = board->cellsMsb[i][j];
                board->cellsMsb[i][j] = 0;
                isAnyMoved = true;
            }
            
            if (r+1 < board->size && board->cellsMsb[r+1][j] == board->cellsMsb[r][j]) {
                board->cellsMsb[r+1][j]++;
                board->cellsMsb[r][j] = 0;
                board->score += 1 << board->cellsMsb[r+1][j];
                board->maxMsb = MAX(board->maxMsb, board->cellsMsb[r+1][j]);
                isAnyMoved = true;
            }
        }
    }
    return isAnyMoved;
}


bool moveBoardLeft(Board_t* board) {
    bool isAnyMoved = false;
    for (int i = 0; i < board->size; i++) {
        for (int j = 1; j < board->size; j++) {
            if (board->cellsMsb[i][j] == 0) {
                continue;
            } 
            
            int c = j;
            if (board->cellsMsb[i][j-1] == 0) {
                c = j-1;
                while (c > 0 && board->cellsMsb[i][c-1] == 0) {
                    c--;
                }
                board->cellsMsb[i][c] = board->cellsMsb[i][j];
                board->cellsMsb[i][j] = 0;
                isAnyMoved = true;
            }
            
            
            if (c > 0 && board->cellsMsb[i][c-1] == board->cellsMsb[i][c]) {
                board->cellsMsb[i][c-1]++;
                board->cellsMsb[i][c] = 0;
                board->score += 1 << board->cellsMsb[i][c-1];
                board->maxMsb = MAX(board->maxMsb, board->cellsMsb[i][c-1]);
                isAnyMoved = true;
            }
        }
    }
    return isAnyMoved;
}


bool moveBoardRight(Board_t* board) {
    bool isAnyMoved = false;
    for (int i = 0; i < board->size; i++) {
        for (int j = board->size - 2; j >= 0; j--) {
            if (board->cellsMsb[i][j] == 0) {
                continue;
            } 
            
            int c = j;
            if (board->cellsMsb[i][j+1] == 0) {
                c = j+1;
                while (c+1 < board->size && board->cellsMsb[i][c+1] == 0) {
                    c++;
                }
                board->cellsMsb[i][c] = board->cellsMsb[i][j];
                board->cellsMsb[i][j] = 0;
                isAnyMoved = true;
            }
            
            
            if (board->cellsMsb[i][c+1] == board->cellsMsb[i][c]) {
                board->cellsMsb[i][c+1]++;
                board->cellsMsb[i][c] = 0;
                board->score += 1 << board->cellsMsb[i][c+1];
                board->maxMsb = MAX(board->maxMsb, board->cellsMsb[i][c+1]);
                isAnyMoved = true;
            }
        }
    }
    return isAnyMoved;
}



void freeBoard(Board_t* board) {
    if (board == NULL) {
        return;
    }

    if (board->cellsMsb == NULL) {
        free(board);
        return;
    }

    for (int i = 0; i < board->size; i++) {
        free(board->cellsMsb[i]);
    }
    free(board->cellsMsb);
    free(board);
}
