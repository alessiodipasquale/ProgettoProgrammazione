#include "./Game/GameManager.hpp"

int main() {
    srand(time(NULL));   
    GameManager game;
    game.mainMenu();
    return 0;
}
