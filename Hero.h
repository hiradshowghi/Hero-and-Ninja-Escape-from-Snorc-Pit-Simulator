#ifndef HERO_H
#define HERO_H

#include "Participant.h"
#include "defs.h"
#include "MoveBehaviour.h" 

class Hero : public Participant {
public:
    Hero(char avatar, int row, int col, MoveBehaviour* moveBehaviour, const std::string& name);

    void incurDamage(int damage) override;
    int causeDamage() const override;
    bool isSafe() const override;

    
    const std::string& getName() const;
    int getHealth() const;
    bool isRescued() const;

private:
    std::string name;
    int health = MAX_HEALTH; 
    bool rescued = false;
};

#endif 
