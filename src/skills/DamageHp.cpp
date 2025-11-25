#include "DamageHp.h"
#include "../character/Character.h"

DamageHp::DamageHp(std::string n, bool magic,float p, float c, TargetType tt)
    : Skill(n,magic,p,c,tt) {}

void DamageHp::useSkill(Character* source, Character* target) {
    if (!canUse(source)) return;

    float dmgStat = (isMagic) ? source->getMagic() : source->getAtk();

    if (target->getIsDefending()) { target->setHp((dmgStat*0.2)*points - target->getDef()*1.5); }

    target->setHp((dmgStat*0.2)*points - target->getDef());
}