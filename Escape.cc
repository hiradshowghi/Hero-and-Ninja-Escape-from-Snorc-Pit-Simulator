#include "Escape.h"
#include <iostream>
#include <cstdlib> 
#include <ctime>   
#include "defs.h"
Escape::Escape() {
    
    srand(static_cast<unsigned>(time(nullptr)));

    
    hero1 = new Hero('H', MAX_ROW - 1, rand() % (MAX_COL - 10) + 7, new EscapeeBehaviour(), "Timmy");
    hero2 = new Hero('H', MAX_ROW - 1, rand() % (MAX_COL - 10) + 7, new EscapeeBehaviour(), "Harold");
    
    while (hero1->getCol() == hero2->getCol()) {
        hero2->setCol(rand() % (MAX_COL - 10) + 7);
    }

    
    participants += hero1;
    participants += hero2;
}

Escape::~Escape() {
    
    Participant* participant;
    while (participants.getSize() > 0) {
        participant = participants[0]; 
        participants -= participant;   
        delete participant;            
    }
}


void Escape::runEscape() {
    while (!isOver()) {
        moveParticipants();
        spawnSnorc();
        spawnNinja();
        checkForCollision();
        printPit();
    }
    printOutcome();
}

void Escape::spawnSnorc() {
    static int snorcCount = 0; 
    if (snorcCount < MAX_SNORCS) { 
        int startRow = rand() % (MAX_ROW - 7) + 7; 
        int startCol = rand() % MAX_COL; 

        Snorc* snorc = new Snorc(startRow, startCol, rand() % 3 + 2, new VillainBehaviour()); 
        participants += snorc; 
        snorcCount++; 
    }
}

void Escape::spawnNinja() { 
    int startRow = 0;
    int startCol = rand() % MAX_COL; 
    Ninja* ninja = new Ninja(startRow, startCol, new RescuerBehaviour());
    participants += ninja;
}


bool Escape::isOver() const {
    
    for (auto participant : participants) {
        Hero* hero = dynamic_cast<Hero*>(participant);
        if (hero) {
            if (hero->getRow() == 0 || hero->isDead()) { 
                return true;
            }
        }
    }
    return false;
}

bool Escape::withinBounds(int row, int col) {
    return row >= 0 && row < MAX_ROW && col >= 0 && col < MAX_COL;
}

void moveParticipants() {
        
        std::vector<Participant*> participantsArray(participants.begin(), participants.end());

        
        for (Participant* participant : participantsArray) {
            
            participant->move();

            
            for (Participant* otherParticipant : participantsArray) {
                if (participant != otherParticipant && participant->hasCollided(*otherParticipant)) {
                    
                    participant->collide(*otherParticipant);
                }
            }
        }
    }

Participant* Escape::checkForCollision(Participant* participant) {
    
    std::vector<Participant*> participantArray = participants.toArray();
    for (Participant* other : participantArray) {
        if (other != participant && other->getRow() == participant->getRow() && other->getCol() == participant->getCol()) {
            return other; 
        }
    }
    return nullptr; 
}

void printPit() {
        const int rows = pit.getNumRows();
        const int cols = pit.getNumColumns();       
        std::vector<std::vector<char>> grid(rows, std::vector<char>(cols, ' '));     
        std::vector<Participant*> participantsArray(participants.begin(), participants.end());      
        for (Participant* participant : participantsArray) {
            int row = participant->getRow();
            int col = participant->getColumn();
            grid[row][col] = participant->getAvatar();
        }

        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << grid[i][j] << ' ';
            }
            std::cout << '\n';
        }

        
        for (Participant* participant : participantsArray) {
            std::cout << participant->getName() << ": ";
            if (participant->isAlive() && pit.isInside(*participant)) {
                
                std::cout << "Health: " << participant->getHealth();
            } else {
                
                std::cout << "Status: ";
                if (participant->isEscaped()) {
                    std::cout << "Escaped";
                } else if (participant->isRescued()) {
                    std::cout << "Rescued";
                } else {
                    std::cout << "Deceased";
                }
            }
            std::cout << std::endl;
        }
    }

void printOutcome(Participant* hero) {  
        std::cout << hero->getName() << ": ";
        if (hero->isEscaped()) {
            std::cout << "Escaped";
        } else if (hero->isRescued()) {
            std::cout << "Rescued";
        } else {
            std::cout << "Deceased";
        }
        std::cout << std::endl;
    }

