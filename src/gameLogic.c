#include "gameLogic.h"
#include "dispaly.h"



void newGame(void) {
    displayInit();
    int boardSize;
    displayMoveCursor(2, 2);
    displayMessage("Developed by: Shady Mansour <shadymansour19@gmail.com>");
    displayMoveCursor(4, 14);
    displayMessage("Board Size? <%d..%d> ", MIN_BOARD_SIZE, MAX_BOARD_SIZE);
    do {
        boardSize = displayGetPressedKey() - '0';
    } while (boardSize < MIN_BOARD_SIZE || boardSize > MAX_BOARD_SIZE);

    displayBoardInit(boardSize);
    Board_t* board = newBoard(boardSize);
    printBoard(board);
    while (true) {
        int key = displayGetPressedKey();
        if (key == KEY_RESIZE) {
            displayInit(boardSize);
        }
        if (moveBoard(board, key) == false && canBoardMove(board) == false) {
            break;
        }
        printBoard(board);
    }

    int score = board->score;
    freeBoard(board);
    if (displayEndGame(score)) {
        newGame();
    }
}
