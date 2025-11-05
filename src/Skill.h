#ifndef SKILL_H
#define SKILL_H

#include "Skills.hpp"
#include "Character.h"

class Skill {
protected:
    bool isMagic;
    float points;
    float cost;
public:
    // constructor / destructor
    Skill(bool magic, float p, float c);
    virtual ~Skill();

    // getters
    bool getIsMagic() const;
    float getPoints() const;
    float getCost() const;

    bool canUse(Character& source) const;

    virtual void useSkill(Character& source, Character& target) = 0;
};

#endif