#include "Character.h"
#include <iostream>

// constructor
Character::Character(string n, int l) : name(n) { 
    stats.level = l; 
    skills.emplace_back(basicAttack);
    skills.emplace_back(basicDefend);
}

// destructor
Character::~Character() {};

// getters
const string& Character::getName() const { return name; }
int Character::getLevel() const { return stats.level; }
float Character::getExp() const { return exp; }
float Character::getNextLevel() const { return nextLevel; }
float Character::getExpDrop() const { return expDrop; }
float Character::getMaxHp() const { return stats.maxHp; }
float Character::getHp() const { return stats.hp; }
float Character::getMaxResource() const { return stats.maxResource; }
float Character::getResource() const { return resource; }
float Character::getAtk() const { return stats.attack; }
float Character::getDef() const { return stats.defense; }
float Character::getMagic() const { return stats.magic; }
float Character::getResistance() const { return stats.resistance; }
bool Character::getIsMagic() const { return isMagic; }
bool Character::getIsAlive() const { return isAlive; }
bool Character::getIsDefending() const { return isDefending; }

// setters
void Character::setHp(float h) { stats.hp = h; }
void Character::setResource(float r) { resource = r; }
void Character::setAttack(float atk) { stats.attack = atk; }
void Character::setDefense(float def) { stats.defense = def; }
void Character::setIsAlive(bool b) { isAlive = b; }
void Character::setIsDefending(bool b) { isDefending = b; }

void Character::performAction(Character& target, Skill& skill) {
    // check if character can use skill
    skill.canUse(*this);

    // decrease resource
    setResource(stats.resource - skill.getCost());

    
}

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
void Character::reset() {
    if (isDefending) { isDefending = false; }
}

void Character::levelUp() {
    stats.level = stats.level + 1;
    this->setHpStat();
    this->setAtkStat();
    this->setDefStat();
}

void Character::canLevel(Character& target) {
    exp += target.getExpDrop();

    if (exp >= nextLevel) {
        float difference = exp - nextLevel;
        levelUp();
        exp = difference;
        nextLevel = nextLevelFormula(stats.level);
    }
}

// print info
void Character::printInfo() const {
    cout << "===== " << name << " =====\n";
    cout << "LEVEL: " << stats.level << " (" << exp << "exp / " << nextLevel << "exp)" << endl;
    cout << "HP: " << stats.hp << " / " << stats.maxHp << endl;
    cout << "ATK: " << stats.attack << endl;
    cout << "DEF: " << stats.defense << endl;
    cout << "STATUS: " << (isAlive ? "Alive" : "Dead") << endl;
}