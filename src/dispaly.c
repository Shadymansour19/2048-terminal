#include "dispaly.h"


#define   ROWS_OFFSET       (3) 
#define   CELL_NUM_ROWS     (4)
#define   CELL_NUM_COLS     (15)


static void msbToStr(char msb, char* str);


static void msbToStr(char msb, char* str) {
    char units[] = {
        '\0', 
        'K',        // Kilo
        'M',        // Mega
        'G',        // Giga
        'T',        // Tera
        'P',        // Pate
        'E',        // Exa
        'Z',        // Zeta
        'Y',        // Yotta
    };

    int cat = msb / 10;
    int val = 1 << (msb % 10);
    sprintf(str, "%d%c", val, units[cat]);
}


void displayInit(int boardSize) {
    initscr();
    clear();
    keypad(stdscr, TRUE);
    noecho();
    attron(A_BOLD);                     // bold font
    curs_set(0);                        // hide cursor
    
    start_color();
    colorsInit();

    // Define color used for each cell. Refer to colors.c for colors definition
    for (int msb = 1; msb < 32; msb++) {
        init_pair(msb, COLOR_WHITE, BACKGROUND_COLOR[msb]);
    }

    // Draw vertical borders
    for (int col = 0; col <= boardSize; col++) {
        mvvline(ROWS_OFFSET, col * CELL_NUM_COLS, ACS_VLINE, CELL_NUM_ROWS * boardSize);
    }
    
    // Draw horizontal borders
    for (int row = 0; row <= boardSize; row++) {
        mvhline(row * CELL_NUM_ROWS + ROWS_OFFSET, 0, ACS_HLINE, CELL_NUM_COLS * boardSize + 1);
    }
}


void displayScore(int score) {
    mvprintw(1, COLS / 2 - 5, "score: %d", score);
}


void displayCell(int row, int col, int cellValMsb) {
    int stRow = ROWS_OFFSET + row * CELL_NUM_ROWS + 1;
    int edRow = ROWS_OFFSET + (row + 1) * CELL_NUM_ROWS - 1;
    int stCol = col * CELL_NUM_COLS + 1;
    int edCol = (col + 1) * CELL_NUM_COLS - 1;
    
    attron(COLOR_PAIR(cellValMsb));
    
    // paint cell background color 
    for (int i = stRow; i <= edRow; i++) {
        for (int j = stCol; j <= edCol; j++) {
            mvprintw(i, j, " ");
        }
    }
    
    // display cell value
    char valToDisplay[10] = {};
    msbToStr(cellValMsb, valToDisplay);
    row = (stRow + edRow) / 2;
    col = (stCol + edCol - strlen(valToDisplay)) / 2;
    mvprintw(row, col, "%s", valToDisplay);
    
    attroff(COLOR_PAIR(cellValMsb));
    refresh();
}


void clearCell(int row, int col) {
    int stRow = ROWS_OFFSET + row * CELL_NUM_ROWS + 1;
    int edRow = ROWS_OFFSET + (row + 1) * CELL_NUM_ROWS - 1;
    int stCol = col * CELL_NUM_COLS + 1;
    int edCol = (col + 1) * CELL_NUM_COLS - 1;
    
    // clear cell content 
    for (int i = stRow; i <= edRow; i++) {
        for (int j = stCol; j <= edCol; j++) {
            mvprintw(i, j, " ");
        }
    }
}



bool displayEndGame(int finalScore) {
    clear();
    move(5, 0);
    printw("                 Game Over!                   \n\r");
    printw("              Final Score: %d!                \n\r", finalScore);
    printw("               New Game? <y/n>                \n\r");
    refresh();
    
    int choice;
    do {
        choice = getch();
    } while (choice != 'y' && choice != 'n');

    if (choice == 'y') {
        return true;
    }
    
    endwin();
    return false;
}