#ifndef VILLAINBEHAVIOUR_H
#define VILLAINBEHAVIOUR_H

#include "MoveBehaviour.h"

class VillainBehaviour : public MoveBehaviour {
public:
    void move(int &row, int &col) override;
};

#endif
