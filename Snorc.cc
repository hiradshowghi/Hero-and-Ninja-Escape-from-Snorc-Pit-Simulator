#include "Snorc.h"

Snorc::Snorc(int row, int col, int strength, MoveBehaviour* moveBehaviour)
    : Participant('s', row, col, moveBehaviour), strength(strength) {}

void Snorc::incurDamage(int damage) {
    
}

int Snorc::causeDamage() const {
    return strength; 
}

bool Snorc::isSafe() const {
    return false; 
}
