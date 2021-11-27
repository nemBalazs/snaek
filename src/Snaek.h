#ifndef SNAEKMOV
#define SNAEKMOV
// 1: UP
// 2: LEFT
// 3: DOWN
// 4: RIGHT
void SnakeMove(int SnakeX, int SnakeY, int direction) {
    int NewSnakeX, NewSnakeY;
        if(direction == 1) {
            NewSnakeX = (SnakeX - 1);
            NewSnakeY = SnakeY;
        }
        else if(direction == 2) {
            NewSnakeX = SnakeX;
            NewSnakeY = (SnakeY - 1);
        }
        else if(direction == 3) {
            NewSnakeX = (SnakeX + 1);
            NewSnakeY = SnakeY;
        }
        else if(direction == 4) {
            NewSnakeX = SnakeX;
            NewSnakeY = (SnakeY + 1);
    }

    // the actual relocation

    if(Board[NewSnakeX][NewSnakeY] == BORDER || Board[NewSnakeX][NewSnakeY] == SNAKE) {
        Board[NewSnakeX][NewSnakeY] = "X";
        SnakeIsDead = true;
    }

    else if(Board[NewSnakeX][NewSnakeY] == TREAT) {
        // SnakeLength++;
        Points++;
    }
    if(!SnakeIsDead) {
        PlacedSnakeNum = 0;
        Board[NewSnakeX][NewSnakeY] = SNAKE_HEAD;
        Board[SnakeX][SnakeY] = SNAKE;

        for(int column = 0; column < HEIGHT; column++) {
            for(int row = 0; row < WIDTH; row++) {
                if(Board[column][row] == SNAKE_HEAD || Board[column][row] == SNAKE) {
                    if(DEBUG_MODE) { std::cout << "Snake at: " << column << ":" << row << " = " << Board[column][row]
                    << std::endl; }
                    PlacedSnakeNum++;
                }
            }
        }
        
        if(PlacedSnakeNum > SnakeLength) {
            Board[SnakeX][SnakeY] = EMPTY_SPACE;
        }

    if(DEBUG_MODE) { printf("PlacedSnakeNum: %i, SnakeLength: %i\n", PlacedSnakeNum, SnakeLength); }
    
    }
}
// this just locates the snake's pos, and then passes the info to SnakeMove()
void InitMove(int direction) {
    
    for(int column = 0; column < HEIGHT; column++) {
        for(int row = 0; row < WIDTH; row++) {
            if(Board[column][row] == SNAKE_HEAD) {
                SnakeLocationX = column;
                SnakeLocationY = row;
                break;
            }
        }
    }
    SnakeMove(SnakeLocationX, SnakeLocationY, direction);
}

#endif