#include "gameLogic.h"
#include "dispaly.h"



void newGame(void) {
    int boardSize;
    do {
        printf("\nBoard Size? <%d..%d> ", MIN_BOARD_SIZE, MAX_BOARD_SIZE);
        scanf("%d", &boardSize);
    } while (boardSize < MIN_BOARD_SIZE || boardSize > MAX_BOARD_SIZE);

    displayInit(boardSize);
    Board_t* board = newBoard(boardSize);
    printBoard(board);
    while (true) {
        int key = getch();
        if (key == KEY_RESIZE) {
            displayInit(boardSize);
        }
        if (moveBoard(board, key) == false && canBoardMove(board) == false) {
            break;
        }
        printBoard(board);
        refresh();
    }
    int score = board->score;
    freeBoard(board);
    if (displayEndGame(score)) {
        newGame();
    }
}
