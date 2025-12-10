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
    std::vector<Command> skillMenuOptions;

    for(int i = 0; i < gameData->playerParty[gameData->partyIndex]->getSkillListSize(); i++) {
        std::string commandName = gameData->playerParty[gameData->partyIndex]->getSkills()[i]->getName();

        skillMenuOptions.emplace_back(Command{
            commandName,
            [this,i]() { 
                auto pickedSkill = gameData->playerParty[gameData->partyIndex]->getSkills()[i];
                if(pickedSkill != nullptr) { gameData->currentBattle.actionQueue.emplace(pickedSkill); }
             }
        });

        if(gameData->partyIndex != 0) {
            skillMenuOptions.emplace_back(Command{
                "[BACK]",
                [this]() { 
                    gameData->partyIndex--;
                    createSelectSkillMenu();
                }
            });
        }
        
    }
    menuStack.emplace("Choose a Move: ",skillMenuOptions);

    createSelectTargetMenu();
}