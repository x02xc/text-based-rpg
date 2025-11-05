#include "Warrior.h"

Warrior::Warrior(const string& n,int level)
    : Character(n, level) {
        stats.hp = warriorHp(level);
        stats.maxHp = warriorHp(level);
        stats.resource = warriorResource(level);
        stats.maxResource = warriorResource(level);
        stats.attack = warriorAtk(level);
        stats.defense = warriorDef(level);
        stats.magic = warriorMagic(level);
        stats.resistance = warriorResistance(level);
    };

void Warrior::setHpStat() { stats.maxHp = warriorHp(stats.level); stats.maxHp = warriorHp(stats.level); }

void Warrior::setResourceStat() { stats.maxResource = warriorResource(stats.level); stats.resource = warriorResource(stats.level); }

void Warrior::setAtkStat() {stats.attack = warriorAtk(stats.level); }

void Warrior::setDefStat() {stats.defense = warriorDef(stats.level); }

void Warrior::setMagicStat() { stats.magic = warriorMagic(stats.level); }

void Warrior::setResistanceStat() { stats.resistance = warriorResistance(stats.level); }