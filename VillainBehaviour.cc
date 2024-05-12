#include "VillainBehaviour.h"

void VillainBehaviour::move(int &row, int &col) {
    row += rand() % 3 - 1; // -1, 0, 1, ensures not moving beyond limits
    col += rand() % 3 - 1;
}
