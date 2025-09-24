#include "display.h"


#define   SCORE_ROW         (1)
#define   TRAILER_MARGIN    (2) 
#define   CELL_NUM_ROWS     ((4)  - ((2) * ((boardSize) >= (6))))
#define   CELL_NUM_COLS     ((10) - ((4) * ((boardSize) >= (6))))
#define   ROWS_OFFSET       (3) 
#define   COLS_OFFSET       (((COLS) - ((CELL_NUM_COLS) * (boardSize))) / (2)) 



static int boardSize;
static void displayBoarders(void);


void displayInit(void) {
    initscr();
    clear();
    keypad(stdscr, TRUE);
    noecho();
    attron(A_BOLD);                     // bold font
    curs_set(0);                        // hide cursor
    
    start_color();
    colorsInit();

    // Define color used for each cell. Refer to colors.c for colors definition
    for (Cell_t cell = CELL_MIN; cell < CELL_MAX; cell++) {
        init_pair(cell, COLOR_WHITE, BACKGROUND_COLOR[cell]);
    }
}


void displaySplashScreen(void) {
    mvprintw(2 , 2, "Developed by: Shady Mansour <shadymansour19@gmail.com>");
    mvprintw(3 , 2, "Source code: https://github.com/shadymansour19/2048-terminal");
    mvprintw(5 , 2, "Usage: ");
    mvprintw(6 , 4, "- Arrow keys to slide the tiles");
    mvprintw(7 , 4, "- %c to quit the game", QUIT_KEY);
    mvprintw(8 , 4, "- %c to undo last move", UNDO_KEY);
    mvprintw(9 , 4, "- %c to redo last move", REDO_KEY);
    mvprintw(10, 4, "- %c to git a hint", HINT_KEY);
    mvprintw(11, 4, "- %c to display this help message", HELP_KEY);
    mvprintw(13, 14, "Board Size? <%d..%d> ", MIN_BOARD_SIZE, MAX_BOARD_SIZE);
}


void ensureBoardFit(const int bs) {
    boardSize = bs;
    int minLines = ROWS_OFFSET + boardSize * CELL_NUM_ROWS + TRAILER_MARGIN + 1;
    int minCols  = MAX(50, boardSize * CELL_NUM_COLS) + 1;
    char msg[80];
    sprintf(msg, "Please resize window to be at least %d x %d", minCols, minLines);

    while (LINES < minLines || COLS < minCols) {
        displayClearAll();
        int row = LINES / 2;
        int col = (COLS - strlen(msg)) / 2;
        move(row, col);
        printw("%s", msg);
        displayGetPressedKey();
    }
    displayClearAll();
    displayReinit();
}



void displayBoarders() {
    // Draw vertical borders
    for (int col = 0; col <= boardSize; col++) {
        mvvline(ROWS_OFFSET, COLS_OFFSET + col * CELL_NUM_COLS, ACS_VLINE, CELL_NUM_ROWS * boardSize);
    }
    
    // Draw horizontal borders
    for (int row = 0; row <= boardSize; row++) {
        mvhline(row * CELL_NUM_ROWS + ROWS_OFFSET, COLS_OFFSET, ACS_HLINE, CELL_NUM_COLS * boardSize + 1);
    }
}


void displayReinit(void) {
    displayClearAll();
    displayBoarders();
}



void displayScore(const int score) {
    move(SCORE_ROW, 0);
    clrtoeol();
    move(SCORE_ROW, COLS / 2 - 5);
    printw("score: %d", score);
}


void displayCell(const int row, const int col, const Cell_t cell) {
    int cellStRow = ROWS_OFFSET + row * CELL_NUM_ROWS + 1;
    int cellEdRow = ROWS_OFFSET + (row + 1) * CELL_NUM_ROWS - 1;
    int cellStCol = COLS_OFFSET + col * CELL_NUM_COLS + 1;
    int cellEdCol = COLS_OFFSET + (col + 1) * CELL_NUM_COLS - 1;
    
    attron(COLOR_PAIR(cell));
    
    // paint cell background color 
    for (int i = cellStRow; i <= cellEdRow; i++) {
        for (int j = cellStCol; j <= cellEdCol; j++) {
            mvprintw(i, j, " ");
        }
    }
    
    // display cell value
    char valToDisplay[6] = {};
    getCellDisplayStr(cell, valToDisplay);
    int stRow = (cellStRow + cellEdRow) / 2;
    int stCol = (cellStCol + cellEdCol - strlen(valToDisplay) + 1) / 2;
    mvprintw(stRow, stCol, "%s", valToDisplay);
    
    attroff(COLOR_PAIR(cell));
    refresh();
}


void clearCell(const int row, const int col) {
    int cellStRow = ROWS_OFFSET + row * CELL_NUM_ROWS + 1;
    int cellEdRow = ROWS_OFFSET + (row + 1) * CELL_NUM_ROWS - 1;
    int cellStCol = COLS_OFFSET + col * CELL_NUM_COLS + 1;
    int cellEdCol = COLS_OFFSET + (col + 1) * CELL_NUM_COLS - 1;
    
    // clear cell content 
    for (int i = cellStRow; i <= cellEdRow; i++) {
        for (int j = cellStCol; j <= cellEdCol; j++) {
            mvprintw(i, j, " ");
        }
    }
}



void displayTrailer(const char** msgs) {
    int cellStRow = ROWS_OFFSET + boardSize * CELL_NUM_ROWS + TRAILER_MARGIN;
    for (int i = 0; msgs[i]; i++) {
        mvprintw(cellStRow + i, TRAILER_MARGIN, "%s", msgs[i]);
    }
}



void clearTrailer(void) {
    int cellStRow = ROWS_OFFSET + boardSize * CELL_NUM_ROWS + TRAILER_MARGIN;
    for (int r = cellStRow; r < LINES; r++) {
        move(r, 0);
        clrtoeol();
    }
}




bool displayEndGame(const int finalScore) {
    clear();
    move(5, 0);
    printw("                  Game Over!                   \n\r");
    printw("              Final Score: %d!                 \n\r", finalScore);
    printw("                New Game? <y/n>                \n\r");
    refresh();
    
    int choice;
    do {
        choice = displayGetPressedKey();
    } while (choice != 'y' && choice != 'n');

    if (choice == 'y') {
        return true;
    }
    
    displayQuit();
    return false;
}
