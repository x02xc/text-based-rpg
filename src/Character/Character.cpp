#include "Character.h"
#include "../skills/SkillList.h"
#include "../skills/BuffDef.h"
#include "../skills/DamageHp.h"

// constructor
Character::Character(string n, int l) 
    : name(n), exp(0), nextLevel(nextLevelFormula(l)), expDrop(expDropFormula(l)), isAlive(true), isDefending(false) { 
    stats.level = l;
    skills.emplace_back(&BasicAttack);
    skills.emplace_back(&BasicDefend);
}

// getters
const string& Character::getName() const { return name; }
int Character::getLevel() const { return stats.level; }
float Character::getExp() const { return exp; }
float Character::getNextLevel() const { return nextLevel; }
float Character::getExpDrop() const { return expDrop; }
float Character::getMaxHp() const { return stats.maxHp; }
float Character::getHp() const { return stats.hp; }
float Character::getResource() const { return stats.resource; }
float Character::getMaxResource() const { return stats.maxResource; }
float Character::getAtk() const { return stats.attack; }
float Character::getDef() const { return stats.defense; }
float Character::getMagic() const { return stats.magic; }
float Character::getResistance() const { return stats.resistance; }
bool Character::getIsAlive() const { return isAlive; }
bool Character::getIsDefending() const { return isDefending; }
bool Character::getIsMagic() const { return isMagic; }
const vector<Skill*>& Character::getSkills() { return skills; }

// setters
void Character::setHp(float h) { stats.hp = h; }
void Character::setResource(float r) { stats.resource = r; }
void Character::setAttack(float atk) { stats.attack = atk; }
void Character::setDefense(float def) { stats.defense = def; }
void Character::setIsAlive(bool b) { isAlive = b; }
void Character::setIsDefending(bool b) { isDefending = b; }
void Character::setIsMagic(bool b) { isMagic = b; }

void Character::fullHeal() {
    if (!isAlive) return;

    stats.hp = stats.maxHp;
}

// defend (just switches isDefending bool for combat system)
void Character::defend() {
    isDefending = true;

    cout << name << " is now defending!\n";
}

// reset
void Character::resetIsDefending() {
    if (isDefending) { isDefending = false; }
}

void Character::levelUp() {
    stats.level = stats.level + 1;
    this->setHpStat();
    this->setAtkStat();
    this->setDefStat();
}

void Character::canLevel(float xp) {
    exp += xp;

    if (exp >= nextLevel) {
        float difference = exp - nextLevel;
        levelUp();
        exp = difference;
        nextLevel = nextLevelFormula(stats.level);
    }
}

// print info
void Character::printInfo() const {
    cout << "===== " << name << " ( ";
    printClass();
    cout << " ) =====\n";
    cout << "LEVEL: " << stats.level << " (" << exp << "exp / " << nextLevel << "exp)" << " | ";
    cout << "HP: " << stats.hp << " / " << stats.maxHp << " | ";
    cout << "ATK: " << stats.attack << " | ";
    cout << "DEF: " << stats.defense << " | ";
    cout << "MAG: " << stats.magic << " | ";
    cout << "RES: " << stats.resistance << " | ";
    cout << "STATUS: " << (isAlive ? "Alive" : "Dead");
    cout << endl;
}

void Character::printSkills() const {
    for (size_t i = 0; i < skills.size(); i++) {
        cout << i + 1 << ") " << skills[i]->getName() << endl;
    }
}