#ifndef RESCUEDBEHAVIOUR_H
#define RESCUEDBEHAVIOUR_H

#include "MoveBehaviour.h"

class RescuedBehaviour : public MoveBehaviour {
public:
    void move(int &row, int &col) override;
};

#endif
