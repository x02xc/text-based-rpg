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

// TODO - Add Battle Menu Derived Class