#ifndef BUFFDEF_H
#define BUFFDEF_H

#include "Skill.h"

class BuffDef : public Skill {
public:
    BuffDef(bool magic, float p, float c);

    void useSkill(Character& source, Character& taget) override;
};

#endif