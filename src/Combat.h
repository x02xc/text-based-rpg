#ifndef COMBAT_H
#define COMBAT_H

#include "Character.h"
#include <iostream>

class Combat {
private:
    Character* player;
    Character* enemy;
    int turnCount;
public:
    Combat(Character* p, Character* e);
    
    void printInfo() const;
    void endInfo(Character* w,Character* l) const;

    int playerTurn();
    int enemyTurn();
    
    bool combatLoop();
};

#endif