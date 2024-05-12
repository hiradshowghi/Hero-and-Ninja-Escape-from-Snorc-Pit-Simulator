#ifndef SNORC_H
#define SNORC_H

#include "Participant.h"
#include "MoveBehaviour.h"

class Snorc : public Participant {
public:
    Snorc(int row, int col, int strength, MoveBehaviour* moveBehaviour);

    void incurDamage(int damage) override;
    int causeDamage() const override;
    bool isSafe() const override;

private:
    int strength;
};

#endif 
