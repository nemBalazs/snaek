#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "Values.h"
#include "BoardAlterations.h"
#include "Snaek.h"

int main() {
    if(HEIGHT < 5 || WIDTH < 5) {
        printf(">> WARNING: Height or Width is lower than the minimum\n", HEIGHT, WIDTH);
    }
    std::cout << "Snaek by nemBalazs66" << std::endl;

game_init:
    InitBoard();
    Points = 0;
    SnakeIsDead = false;
// game init end

    while(!SnakeIsDead) {
        PlaceTreat();
        PrintBoardStatus();

get_input:
        printf("\nEnter a direction\nMovement:\n W\nASD\n");
        std::string Input = "";
        std::cin >> Input;
        if(Input == "W" || Input == "w") { InitMove(1); }
        else if(Input == "A" || Input == "a") { InitMove(2); }
        else if(Input == "S" || Input == "s") { InitMove(3); }
        else if(Input == "D" || Input == "d") { InitMove(4); }
        else {
            std::cout << Input << " isn't a valid movement" << std::endl;
            goto get_input;
        }
    }

    printf("You died. Points: %i\n", Points);
    PrintBoardStatus();
    goto retry;
retry:
        std::cout << "Retry? (y/n)\n";
        std::string RetryInput;
        std::cin >> RetryInput;
        if(RetryInput == "y" || RetryInput == "Y") { goto game_init; }
        else if (RetryInput == "n" || RetryInput == "N") { return 0; }
        else {
            std::cout << "Invalid choice, ";
            goto retry;
        }
}