#include <iostream>
#include <string>
#include <stdlib.h>
#include "BoardAlterations.h"
#include "Snaek.h"

int main() {
    if(HEIGHT < 5 || WIDTH < 5) {
        printf("Invalid arguments for 'HEIGHT' (%i) or 'WIDTH' (%i) \n", HEIGHT, WIDTH);
    }
    std::cout << "Snaek by nemBalazs66" << std::endl;

game_init:
    InitBoard();
    points = 0;
    SnakeIsDead = false;
// game init end

    while(!SnakeIsDead) {
        PlaceTreat();
        PrintBoardStatus();

get_input:
        printf("\nEnter a direction\nMovement:\n W\nASD\n");
        std::string Input = "";
        std::cin >> Input;
        if(Input == "W" || Input == "w") { MoveSnake(1); }
        else if(Input == "A" || Input == "a") { MoveSnake(2); }
        else if(Input == "S" || Input == "s") { MoveSnake(3); }
        else if(Input == "D" || Input == "d") { MoveSnake(4); }
        else {
            printf("%s isn't a movement\n", Input);
            goto get_input;
        }
    }

    printf("You died. Points: %i\n", points);
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