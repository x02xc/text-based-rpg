#ifndef ACTION_H
#define ACTION_H

#include "Character.h"
#include "Skill.h"

class Action {
private:
    float basePoints;
    float critChance;
    Character* source;
    Character* target;
    Skill* skill;
public:
    Action(Character* s,Character* t,Skill* sk);
    virtual ~Action();

    void action();
};

#endif