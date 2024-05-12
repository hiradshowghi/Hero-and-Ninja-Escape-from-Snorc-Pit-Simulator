#include "Ninja.h"

Ninja::Ninja(int row, int col, MoveBehaviour* moveBehaviour)
    : Participant('N', row, col, moveBehaviour) {}

void Ninja::incurDamage(int damage) {
    if (poisoned) {
        return;
    }
    if (damage == RESCUE) {
        
        return;
    } else if (damage > 0) {
        poisoned = true;
        strength = random(6, 9); 
        avatar = 'S'; 
        
    }
    
}

int Ninja::causeDamage() const {
    if (poisoned) {
        return strength;
    }
    return RESCUE; 
}

bool Ninja::isSafe() const {   
    return false; 
}

bool Ninja::isPoisoned() const {
    return poisoned;
}
