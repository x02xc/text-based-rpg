#include "Game.h"

Game::Game(const string& n) 
    : player(new Warrior(n,4)), currentIndex(0) {
    
    arena.push_back(new Enemy("Rat",1));
    arena.push_back(new Enemy("Goblin",2));
    arena.push_back(new Enemy("Skeleton",3));
    arena.push_back(new Boss("Boss Man",4));
}

Game::~Game() {
    for (int i = 0; i < arena.size(); i++) { delete arena[i]; }
}

void Game::gameLoop() {
    while (true) {
        int choice;

        cout << "Choose an option: \n";
        cout << "1. Fight\n";
        cout << "2. Print Player Stats\n";
        cout << "3. Quit\n";

        cin >> choice;

        if (choice == 1) {
            cout << "Entering battle " << currentIndex + 1 << " of " << (int)arena.size() << endl;

            Combat battle(player, arena[currentIndex]);
            bool result = battle.combatLoop();

            if(!result) { cout << "===== GAME OVER =====\n"; return; }

            player->fullHeal();

            currentIndex++;

            if (currentIndex >= (int)arena.size()) { 
                cout << "====================================================" << endl;
                cout << "===== CONGRATULATIONS - YOU DEFEATED THE ARENA =====" << endl; 
                cout << "====================================================" << endl;
                return; 
            }
        } else if (choice == 2) {
            player->printInfo();
        } else if (choice == 3) {
            cout << "===== GAME OVER =====\n"; 
            return;
        } else {
            cout << "Invalid Option.\n";
        }
    }
}