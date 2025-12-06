#pragma once

#include "command.h"
#include <string>
#include <vector>

class Menu {
private:
    std::vector<Command*> menuItems;
    std::string message;
public:
    Menu(std::string msg);

    void getMenuMessage() const;
};

class MainMenu : public Menu {
public:
    MainMenu(std::string msg);
};

class SkillMenu : public Menu {
public:
    SkillMenu(std::string msg);
};