#include <iostream>
#include <stdlib.h>
#include "BoardAlterations.h"
int wins, defeats = 0;

int main() {
    
    std::cout << "Snaek" << std::endl;

game_init:
    InitBoard();
    SnaekIsDead = false;
// game init end

    while(!SnaekIsDead) {
        PlaceTreat();
        PrintBoardStatus();
        if(DEBUG_MODE) { system("read"); }
    }

    return 0;
}