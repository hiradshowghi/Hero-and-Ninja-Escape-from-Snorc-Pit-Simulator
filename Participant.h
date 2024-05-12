#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include <string>
#include "MoveBehaviour.h" 

class Participant {
public:
    Participant(char avatar, int row, int col, MoveBehaviour* moveBehaviour)
    : avatar(avatar), row(row), col(col), moveBehaviour(moveBehaviour) {}

    virtual ~Participant() {
        delete moveBehaviour; 
    }

    
    virtual void incurDamage(int damage) = 0;
    virtual int causeDamage() const = 0;
    virtual bool isSafe() const = 0;
    virtual void move() {
        if (moveBehaviour && !isDead()) { 
            moveBehaviour->move(row, col); 
        }
    }

    
    char getAvatar() const { return avatar; }
    int getRow() const { return row; }
    int getCol() const { return col; }
    void setMoveBehaviour(MoveBehaviour* mb) { moveBehaviour = mb; }
    bool isDead() const { return dead; }

protected:
    char avatar;
    int row, col;
    bool dead = false;
    MoveBehaviour* moveBehaviour; 
};

#endif 
