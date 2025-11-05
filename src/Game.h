#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Character.h"
#include "Warrior.h"
#include "Enemy.h"
#include "Boss.h"
#include "Combat.h"

class Game {
private:
    Warrior* player;
    vector<Character*> arena;
    int currentIndex;
public:
    Game(const string& n);
    ~Game();

    void gameLoop();
};

#endif