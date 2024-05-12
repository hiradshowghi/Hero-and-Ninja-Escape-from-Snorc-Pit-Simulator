#ifndef ESCAPEEBEHAVIOUR_H
#define ESCAPEEBEHAVIOUR_H

#include "MoveBehaviour.h"
#include <cstdlib> 

class EscapeeBehaviour : public MoveBehaviour {
public:
    void move(int &row, int &col) override;
};

#endif
