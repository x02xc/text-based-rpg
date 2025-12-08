#pragma once

#include "../party/Party.h"
#include "../combat/Action.h"
#include "../combat/Combat.h"
#include <queue>

struct GameData {
    Party playerParty;
    Party bossParty;
    vector<Party> arena;
    int currentIndex;
    int partyIndex;
    Character* source;
    Character* target;
    queue<Action> actionQueue;
    Combat currentBattle;
};