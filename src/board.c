#include "board.h"
#include <math.h>


static void fillOneCell(Board_t* board);
static bool slideBoardUp(Board_t* board);
static bool slideBoardDown(Board_t* board);
static bool slideBoardLeft(Board_t* board);
static bool slideBoardRight(Board_t* board);



bool initBoard(int size, Board_t* board) {
    srand(time(NULL));
    if (board == NULL) {
        return false;
    }

    board->size = size;
    board->score = 0;
    board->maxCell = EMPTY_CELL;
    board->cells = calloc(sizeof(char*), size);
    if (board->cells == NULL) {
        return false;
    }

    for (int i = 0; i < size; i++) {
        board->cells[i] = calloc(sizeof(char), size);
        if (board->cells[i] == NULL) {
            return false;
        }
        for (int j = 0; j < size; j++) {
            board->cells[i][j] = EMPTY_CELL;
        }
    }

    fillOneCell(board);
    fillOneCell(board);
    
    return true;
}



static void fillOneCell(Board_t* board) {
    int r, c;
    do {
        r = rand() % board->size;
        c = rand() % board->size;
    } while (board->cells[r][c]);
    
    board->cells[r][c] = newCell(board->size, board->maxCell);
    board->maxCell = MAX(board->maxCell, board->cells[r][c]);
}




void printBoard(Board_t* board) {
    displayScore(board->score);
    for (int i = 0; i < board->size; i++) {
        for (int j = 0; j < board->size; j++) {
            if (board->cells[i][j] == EMPTY_CELL) {
                clearCell(i, j);
            } else {
                displayCell(i, j, board->cells[i][j]);
            }
        }
    }
}


bool canBoardMove(Board_t* board) {
    for (int i = 0; i < board->size; i++) {
        for (int j = 0; j < board->size; j++) {
            if (board->cells[i][j] == EMPTY_CELL || (i > 0 && board->cells[i][j] == board->cells[i-1][j]) || (j > 0 && board->cells[i][j] == board->cells[i][j-1])) {
                return true;
            } 
        }
    }
    return false;
}


void copyBoard(Board_t* src, Board_t* dst) {
    for (int i = 0; i < src->size; i++) {
        for (int j = 0; j < src->size; j++) {
            dst->cells[i][j] = src->cells[i][j];
        }
    }
    dst->maxCell = src->maxCell;
    dst->score = src->score;
}


bool slideBoard(Board_t* oldBoard, Board_t* newBoard, Direction_t dir) {
    bool ret = false;
    copyBoard(oldBoard, newBoard);
    if (dir == UP) {
        ret = slideBoardUp(newBoard);
    } else if (dir == DOWN) {
        ret = slideBoardDown(newBoard);
    } else if (dir == LEFT) {
        ret = slideBoardLeft(newBoard);
    } else if (dir == RIGHT) {
        ret = slideBoardRight(newBoard);
    } 
    
    if (ret) {
        fillOneCell(newBoard);
    }
    return ret;
}



static bool slideBoardUp(Board_t* board) {
    bool isAnyMoved = false;
    for (int i = 1; i < board->size; i++) {
        for (int j = 0; j < board->size; j++) {
            if (board->cells[i][j] == EMPTY_CELL) {
                continue;
            } 
            
            int r = i;
            if (board->cells[i-1][j] == EMPTY_CELL) {
                r = i-1;
                while (r > 0 && board->cells[r-1][j] == EMPTY_CELL) {
                    r--;
                }
                board->cells[r][j] = board->cells[i][j];
                board->cells[i][j] = EMPTY_CELL;
                isAnyMoved = true;
            }
            
            if (r > 0 && board->cells[r-1][j] == board->cells[r][j]) {
                board->cells[r-1][j]++;
                board->cells[r][j] = EMPTY_CELL;
                board->score += 1 << board->cells[r-1][j];
                board->maxCell = MAX(board->maxCell, board->cells[r-1][j]);
                isAnyMoved = true;
            }
        }
    }
    return isAnyMoved;
}


static bool slideBoardDown(Board_t* board) {
    bool isAnyMoved = false;
    for (int i = board->size - 2; i >= 0; i--) {
        for (int j = 0; j < board->size; j++) {
            if (board->cells[i][j] == EMPTY_CELL) {
                continue;
            } 
            
            int r = i;
            if (board->cells[i+1][j] == EMPTY_CELL) {
                r = i+1;
                while (r+1 < board->size && board->cells[r+1][j] == EMPTY_CELL) {
                    r++;
                }
                board->cells[r][j] = board->cells[i][j];
                board->cells[i][j] = EMPTY_CELL;
                isAnyMoved = true;
            }
            
            if (r+1 < board->size && board->cells[r+1][j] == board->cells[r][j]) {
                board->cells[r+1][j]++;
                board->cells[r][j] = EMPTY_CELL;
                board->score += 1 << board->cells[r+1][j];
                board->maxCell = MAX(board->maxCell, board->cells[r+1][j]);
                isAnyMoved = true;
            }
        }
    }
    return isAnyMoved;
}


static bool slideBoardLeft(Board_t* board) {
    bool isAnyMoved = false;
    for (int i = 0; i < board->size; i++) {
        for (int j = 1; j < board->size; j++) {
            if (board->cells[i][j] == EMPTY_CELL) {
                continue;
            } 
            
            int c = j;
            if (board->cells[i][j-1] == EMPTY_CELL) {
                c = j-1;
                while (c > 0 && board->cells[i][c-1] == EMPTY_CELL) {
                    c--;
                }
                board->cells[i][c] = board->cells[i][j];
                board->cells[i][j] = EMPTY_CELL;
                isAnyMoved = true;
            }
            
            
            if (c > 0 && board->cells[i][c-1] == board->cells[i][c]) {
                board->cells[i][c-1]++;
                board->cells[i][c] = EMPTY_CELL;
                board->score += 1 << board->cells[i][c-1];
                board->maxCell = MAX(board->maxCell, board->cells[i][c-1]);
                isAnyMoved = true;
            }
        }
    }
    return isAnyMoved;
}


static bool slideBoardRight(Board_t* board) {
    bool isAnyMoved = false;
    for (int i = 0; i < board->size; i++) {
        for (int j = board->size - 2; j >= 0; j--) {
            if (board->cells[i][j] == EMPTY_CELL) {
                continue;
            } 
            
            int c = j;
            if (board->cells[i][j+1] == EMPTY_CELL) {
                c = j+1;
                while (c+1 < board->size && board->cells[i][c+1] == EMPTY_CELL) {
                    c++;
                }
                board->cells[i][c] = board->cells[i][j];
                board->cells[i][j] = EMPTY_CELL;
                isAnyMoved = true;
            }
            
            
            if (board->cells[i][c+1] == board->cells[i][c]) {
                board->cells[i][c+1]++;
                board->cells[i][c] = EMPTY_CELL;
                board->score += 1 << board->cells[i][c+1];
                board->maxCell = MAX(board->maxCell, board->cells[i][c+1]);
                isAnyMoved = true;
            }
        }
    }
    return isAnyMoved;
}



void freeBoard(Board_t* board) {
    if (board == NULL || board->cells == NULL) {
        return;
    }

    for (int i = 0; i < board->size; i++) {
        free(board->cells[i]);
    }
    free(board->cells);
    board->cells = NULL;
}
