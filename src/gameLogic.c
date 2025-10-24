#include "gameLogic.h"


void newGame(void) {
    int pressedKey;

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
        pressedKey = displayGetPressedKey();
        clearTrailer();
        if (pressedKey == QUIT_KEY) {
            break;
        } else if (pressedKey == KEY_RESIZE) {
            ensureBoardFit(boardSize);
        } else if (pressedKey == HELP_KEY) {
            displayHelpScreen();
        } else if (pressedKey == UNDO_KEY) {
            gameUndo(&game);
        } else if (pressedKey == REDO_KEY) {
            gameRedo(&game);
        } else if (pressedKey == HINT_KEY) {
            Direction_t hintDir = gameHint(&game);
            switch (hintDir) {
                case UP:
                    displayTrailer("Hint: move UP");
                    break;
                case DOWN:
                    displayTrailer("Hint: move DOWN");
                    break;
                case LEFT:
                    displayTrailer("Hint: move LEFT");
                    break;
                case RIGHT:
                    displayTrailer("Hint: move RIGHT");
                    break;
                default:
                    break;
            }
        } else {
            gameSlide(&game, pressedKey);
            if (isGameOver(&game)) {
                displayTrailer("Game Over! Undo? <y/n>");
                gamePrintBoard(&game);
                do {
                    pressedKey = displayGetPressedKey();
                } while (pressedKey != 'y' && pressedKey != 'n');

                if (pressedKey == 'y') {
                    gameUndo(&game);
                    clearTrailer();
                } else {
                    break;
                }
            }
        }
        gamePrintBoard(&game);
    }

    int finalScore = getGameScore(&game);
    freeGame(&game);
    displayEndGame(finalScore);
}
