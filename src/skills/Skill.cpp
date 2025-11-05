#include "skills/Skill.h"
#include "Formulas.hpp"
#include "Character/Character.h"
#include <iostream>

Skill::Skill(bool magic, float p, float c)
    : isMagic(magic), points(p), cost(c) {}

Skill::~Skill() {}

bool Skill::canUse(Character& source) const {
    if (source.getResource() < cost) { 
        cout << (source.getIsMagic()) ? "Not Enough Mana!\n" : "Not Enough Stamina!\n"; 
        return false;
    }
    return true;
}

bool Skill::getIsMagic() const { return isMagic; }
float Skill::getPoints() const { return points; }
float Skill::getCost() const { return cost; }