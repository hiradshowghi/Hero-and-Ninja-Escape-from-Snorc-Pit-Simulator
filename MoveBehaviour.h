#ifndef MOVEBEHAVIOUR_H
#define MOVEBEHAVIOUR_H

class MoveBehaviour {
public:
    virtual ~MoveBehaviour() {}
    virtual void move(int &row, int &col) = 0;
};

#endif
