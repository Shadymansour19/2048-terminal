#include "gameLogic.h"


void newGame(void) {
    int pressedKey;
    static const char* (gameOverTrailer[]) = {
        "Game Over! Undo? <y,n>", 
        NULL
    };

    displayInit();
    displaySplashScreen();
    int boardSize;
    do {
        pressedKey = displayGetPressedKey();
        if (pressedKey == QUIT_KEY) {
            displayQuit();
            return;
        }
        boardSize = pressedKey - '0';
    } while (boardSize < MIN_BOARD_SIZE || boardSize > MAX_BOARD_SIZE);

    ensureBoardFit(boardSize);

    Game_t game;
    if (initGame(boardSize, &game) == false) {
        freeGame(&game);
        return;
    }

    while (true) {
        clearTrailer();
        pressedKey = displayGetPressedKey();
        if (pressedKey == QUIT_KEY) {
            break;
        } else if (pressedKey == KEY_RESIZE) {
            ensureBoardFit(boardSize);
            gamePrintBoard(&game);
        } else if (pressedKey == HELP_KEY) {
            displayHelpScreen();
            gamePrintBoard(&game);
        } else if (pressedKey == UNDO_KEY) {
            gameUndo(&game);
        } else if (pressedKey == REDO_KEY) {
            gameRedo(&game);
        } else if (gameSlide(&game, pressedKey) == false && isGameOver(&game)) {
            displayTrailer(gameOverTrailer);
            do {
                pressedKey = displayGetPressedKey();
            } while (pressedKey != 'y' && pressedKey != 'n');

            if (pressedKey == 'y') {
                gameUndo(&game);
            } else {
                break;
            }
        }
    }

    int finalScore = getGameScore(&game);
    freeGame(&game);
    if (displayEndGame(finalScore)) {
        newGame();
    }
}
