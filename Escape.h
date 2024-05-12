#ifndef ESCAPE_H
#define ESCAPE_H

#include "List.h" // Assuming List.h is your modified template class
#include "Participant.h"
#include "Hero.h"
#include "Snorc.h"
#include "Ninja.h"
#include <vector>

class Escape {
public:
    Escape();
    ~Escape();
    void runEscape();
private:
    List<Participant*> participants;
    Hero* hero1;
    Hero* hero2;
    void spawnSnorc();
    void spawnNinja();
    bool isOver() const;
    static bool withinBounds(int row, int col);
    void moveParticipants();
    void checkForCollision();
    void printPit() const;
    void printOutcome() const;
};

#endif // ESCAPE_H
