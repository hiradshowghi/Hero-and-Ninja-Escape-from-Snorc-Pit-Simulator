#ifndef NINJA_H
#define NINJA_H

#include "Participant.h"
#include "MoveBehaviour.h" 

class Ninja : public Participant {
public:
    Ninja(int row, int col, MoveBehaviour* moveBehaviour);

    void incurDamage(int damage) override;
    int causeDamage() const override;
    bool isSafe() const override;

    bool isPoisoned() const;

private:
    bool poisoned = false;
    int strength = 0;
};

#endif 
