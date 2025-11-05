#include "Game.h"
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0));

    cout << "===== WELCOME =====" << endl;

    // TODO - Prompt for Class

    string playerName;
    cout << "Player Name: ";
    cin >> playerName;

    Game game(playerName);
    game.gameLoop();
    return 0;
}