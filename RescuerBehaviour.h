#ifndef RESCUERBEHAVIOUR_H
#define RESCUERBEHAVIOUR_H

#include "MoveBehaviour.h"

class RescuerBehaviour : public MoveBehaviour {
public:
    void move(int &row, int &col) override;
};

#endif
