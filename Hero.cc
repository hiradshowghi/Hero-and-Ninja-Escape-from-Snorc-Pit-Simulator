#include "Hero.h"

Hero::Hero(char avatar, int row, int col, MoveBehaviour* moveBehaviour, const std::string& name)
    : Participant(avatar, row, col, moveBehaviour), name(name) {}

void Hero::incurDamage(int damage) {
    if (damage == RESCUE) { 
        rescued = true;
        
    } else {
        health -= damage;
        if (health <= 0) {
            dead = true; 
            avatar = '+'; 
        }
    }
}

int Hero::causeDamage() const {
    return 0; 
}

bool Hero::isSafe() const {
    return row == 0; 
}

const std::string& Hero::getName() const { return name; }
int Hero::getHealth() const { return health; }
bool Hero::isRescued() const { return rescued; }
