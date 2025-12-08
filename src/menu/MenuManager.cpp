#include "MenuManager.h"
#include <cstdlib>

MenuManager::MenuManager(GameData *gm)
:   gameData(gm) {}

void MenuManager::createMainMenu() {
    menuStack.emplace("Choose an Option:\n",std::vector<Command>{
        {"Fight",[this]() { createFightMenu(); }}, // TODO - fix
        {"Print Party Stats",[this]() { gameData->playerParty.printPartyInfo(); }},
        {"Quit",[this]() { exit(0); }}
    });
}

void MenuManager::createFightMenu() {
    menuStack.emplace("Choose an Option:\n",std::vector<Command>{
        {"Fight",[this]() { createSelectSkillMenu(); }},
        {"Print Battle Info",[this]() { 
            cout << "==== Player Party =====\n";
            gameData->playerParty.printPartyInfo();
            cout << endl << "==== Enemy Party =====\n";
            gameData->arena[gameData->currentIndex].printPartyInfo();
        }}
    });
}

void MenuManager::createSelectSkillMenu() {
    menuStack.emplace("Choose a Skill:\n",std::vector<Command>{});

    gameData->currentBattle.actionQueue.emplace();
}