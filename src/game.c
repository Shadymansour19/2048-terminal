#include "game.h"


// static void displayHelp(Game_t* game);              // display help in blocking-mode until pressing esc

static void dbg(Game_t* game) {
    FILE* lg = fopen("log.txt", "a+");
    for (int i = 0; i < STACK_CAPACITY; i++) {
        fprintf(lg, "board num %d:\n", i);
        for (int r = 0; r < game->boardSize; r++) {
            for (int c = 0; c < game->boardSize; c++) {
                fprintf(lg, "%d ", game->boardsStack[i].cells[r][c]);
            }
            fprintf(lg, "\n");
        }
        fprintf(lg, "\n");
    }
    fclose(lg);
}


static int maxScore(Game_t* game, Direction_t dir, int depth) {
    if (depth == 0) {
        return getGameScore(game);
    }

    if (gameSlide(game, dir) == false) {
        return getGameScore(game);
    }
    
    int score = MAX(
        MAX(
            maxScore(game, UP, depth - 1), 
            maxScore(game, DOWN, depth - 1)
        ),
        MAX(
            maxScore(game, LEFT, depth - 1), 
            maxScore(game, RIGHT, depth - 1)
        )
    );
    gameUndo(game);
    return score;
}



bool initGame(int boardSize, Game_t* game) {
    if (game == NULL) {
        return false;
    }

    for (int i = 0; i < STACK_CAPACITY; i++) {
        if (initBoard(boardSize, &game->boardsStack[i]) == false) {
            return false;
        }
    }
    
    game->boardSize = boardSize;
    game->boardsStackSize = 1;
    game->currentBoardIdx = 0;
    game->lastBoardIdx = 0;
    printBoard(&game->boardsStack[game->currentBoardIdx]);
    return true;
}


void cloneGame(Game_t* src, Game_t* dst) {
    dst->boardSize = src->boardSize;
    dst->boardsStackSize = src->boardsStackSize;
    dst->currentBoardIdx = src->currentBoardIdx;
    dst->lastBoardIdx = src->lastBoardIdx;

    for (int i = 0; i < STACK_CAPACITY; i++) {
        initBoard(dst->boardSize, &dst->boardsStack[i]);
        copyBoard(&src->boardsStack[i], &dst->boardsStack[i]);
    }
}


void gameUndo(Game_t* game) {
    int prevIdx = (game->currentBoardIdx + game->boardsStackSize - 1) % game->boardsStackSize;
    if (prevIdx == game->lastBoardIdx) {
        printf("\a");       // Produces a beep sound
        fflush(stdout);     // Ensure the sound is played immediately
    } else {
        game->currentBoardIdx = prevIdx;
    }
}



void gameRedo(Game_t* game) {
    if (game->currentBoardIdx == game->lastBoardIdx) {
        printf("\a");       // Produces a beep sound
        fflush(stdout);     // Ensure the sound is played immediately
    } else {
        game->currentBoardIdx = (game->currentBoardIdx + 1) % game->boardsStackSize;
        printBoard(&game->boardsStack[game->currentBoardIdx]);
    }
}


Direction_t gameHint(Game_t* game) {
    Game_t gameClone;
    cloneGame(game, &gameClone);

    int upScore = maxScore(&gameClone, UP, MAX_HINT_DEPTH);
    int downScore = maxScore(&gameClone, DOWN, MAX_HINT_DEPTH);
    int leftScore = maxScore(&gameClone, LEFT, MAX_HINT_DEPTH);
    int rightScore = maxScore(&gameClone, RIGHT, MAX_HINT_DEPTH);

    freeGame(&gameClone);

    int maxScore = MAX(
        MAX(upScore, downScore),
        MAX(leftScore, rightScore)
    );

    if (maxScore == upScore) {
        return UP;
    } else if (maxScore == downScore) {
        return DOWN;
    } else if (maxScore == leftScore) {
        return LEFT;
    } else {
        return RIGHT;
    }
}


bool gameSlide(Game_t* game, Direction_t dir) {
    int  nextIdx = (game->currentBoardIdx + 1) % STACK_CAPACITY;
    bool ret = slideBoard(&game->boardsStack[game->currentBoardIdx], &game->boardsStack[nextIdx], dir);
    if (ret) {
        game->currentBoardIdx = nextIdx;
        game->lastBoardIdx = game->currentBoardIdx;
        game->boardsStackSize = MIN(game->boardsStackSize + 1, STACK_CAPACITY);
    }
    return ret;
}



void gamePrintBoard(Game_t* game) {
    printBoard(&game->boardsStack[game->currentBoardIdx]);
}



bool isGameOver(Game_t* game) {
    return (canBoardMove(&game->boardsStack[game->currentBoardIdx]) == false);
}


int  getGameScore(Game_t* game) {
    return game->boardsStack[game->currentBoardIdx].score;
}



void freeGame(Game_t* game) {
    if (game == NULL) {
        return;
    }

    for (int i = 0; i < STACK_CAPACITY; i++) {
        freeBoard(&game->boardsStack[i]);
    }
}
