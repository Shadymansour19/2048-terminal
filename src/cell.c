#include "cell.h"


Cell_t newCell(int boardSize, Cell_t maxCell) {
    return LOWEST_MSB(maxCell, boardSize) + ((rand() / (double) RAND_MAX) > PROBABILITY_LOW);
}




void getCellDisplayStr(Cell_t msb, char* str) {
    static char units[] = {
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
    sprintf(str, "%d", val);
    if (cat > 0 && strlen(str)%2 == 1) {
        sprintf(str, "%d %c", val, units[cat]);
    } else {
        sprintf(str, "%d%c", val, units[cat]);
    }
}
