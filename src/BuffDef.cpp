#include "BuffDef.h"

BuffDef::BuffDef(bool magic, float p, float c)
    : Skill(magic,p,c) {}

void BuffDef::useSkill(Character& source, Character& target) {
    target.setDefense(points * (source.getLevel() * 0.5));
}