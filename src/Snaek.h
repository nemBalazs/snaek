#ifndef SNAEKMOV
#define SNAEKMOV
int Points, SnakeLocationX, SnakeLocationY, SnakeLength;

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
    if(Board[NewSnakeX][NewSnakeY] == BORDER) {
        Board[NewSnakeX][NewSnakeY] = "X";
        SnakeIsDead = true;
        goto skip;
    }
    else if(Board[NewSnakeX][NewSnakeY] == TREAT) {
        Points++;
    }
    if(!SnakeIsDead) {
        Board[NewSnakeX][NewSnakeY] = SNAKE;
        Board[SnakeX][SnakeY] = EMPTY_SPACE;
    }
skip:
    if(DEBUG_MODE) {
        printf("Direction: %i, SnakeX %i, SnakeY %i, NewSnakeX %i, NewSnakeY %i\n", direction, SnakeX, SnakeY, NewSnakeX, NewSnakeY);
    }
}

// this just locates the snake's pos, and then passes the info to SnakeMove()
void InitMove(int direction) {
    for(int column = 0; column < HEIGHT; column++) {
        for(int row = 0; row < WIDTH; row++) {
            if(Board[column][row] == SNAKE) {
                SnakeLocationX = column;
                SnakeLocationY = row;
                break;
            }
        }
    }
    SnakeMove(SnakeLocationX, SnakeLocationY, direction);
}

#endif