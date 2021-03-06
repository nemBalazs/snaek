#ifndef BOARDALTERATIONS
#define BOARDALTERATIONS
// empties the board
void InitBoard() {
    for(int column = 0; column < HEIGHT; column++) {
        for(int row = 0; row < WIDTH; row++) {
            if(column == 0 || column == HEIGHT-1 || row == 0 || row == WIDTH-1) {
                Board[column][row] = BORDER;
            }
            else {
            Board[column][row] = EMPTY_SPACE;
            }
        }
    }

    Board[2][2] = SNAKE;
    Board[2][3] = SNAKE_HEAD;
}

// yes cool name
void PrintBoardStatus() {
    std::cout << "Snaek";
    for(int column = 0; column < HEIGHT; column++) {
        std::cout << std::endl;
        for(int row = 0; row < WIDTH; row++) {
            std::cout << Board[column][row] << " ";
        }
    }
    std::cout << std::endl;
}

// simple treat placing algorithm
void PlaceTreat() {
    srand(time(NULL));
    bool TreatIsPlaced = false;
    int column, row;
    while(!TreatIsPlaced) {
        column = rand() % (HEIGHT);
        row = rand() % (WIDTH);

        // check for occupied place
        if(Board[column][row] == SNAKE || Board[column][row] == TREAT || Board[column][row] == BORDER
            || Board[column][row] == SNAKE_HEAD) {
            if(DEBUG_MODE) { std::cout << "Place occupied\n"; }
            
            // checking for game over
            bool BoardIsFull = true;
            for(int clm = 0; clm < HEIGHT; clm++) {
                for(int r = 0; r < WIDTH; r++) {
                    if (Board[clm][r] == EMPTY_SPACE) {
                        BoardIsFull = false;
                    }
                }
            }

            if (DEBUG_MODE) { printf("BIF Status: %d\nColumn %i : Row %i\n", BoardIsFull, column, row); }

            // if the board is full, end the current game
            if(BoardIsFull == true) {
                std::cout << "Board is full\n";
                SnakeIsDead = true;
                break;
            } else { continue; }

        } else {
            if(DEBUG_MODE) { printf("Treat been placed at %i : %i\n", column, row); }
            Board[column][row] = TREAT;
            TreatIsPlaced = true;
        }
    }
}

#endif