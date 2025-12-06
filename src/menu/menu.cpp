#include "menu.h"

Menu::Menu(std::string msg)
    : message(msg) {}

MainMenu::MainMenu(std::string msg) : Menu(msg) {
     
}

SkillMenu::SkillMenu(std::string msg) : Menu(msg) {

}