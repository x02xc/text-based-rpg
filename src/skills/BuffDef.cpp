#include "BuffDef.h"
#include "../character/Character.h"

BuffDef::BuffDef(std::string n, bool magic, float p, float c, TargetType tt)
    : Skill(n,magic,p,c,tt) {}

void BuffDef::useSkill(Character* source, Character* target) {
    if (!canUse(source)) return;

    target->setDefense(target->getDef() + points * (source->getLevel() * 0.5));
}