#include "EscapeeBehaviour.h"

void EscapeeBehaviour::move(int &row, int &col) {
    row += rand() % 5 - 2; // -1, 0, 1, 2
    col += rand() % 3 - 1; // -1, 0, 1
}
