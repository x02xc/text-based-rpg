#pragma once

struct Stats {
    int level;

    float hp; float maxHp;
    float resource; float maxResource;

    float attack; float defense;
    float magic; float resistance;
};

enum class ClassType { Warrior, Mage, Archer, Healer};
enum class ResourceType { Mana, Stamina};