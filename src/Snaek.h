#ifndef SNAEKMOV
#define SNAEKMOV

int points;

// 1: UP
// 2: LEFT
// 3: DOWN
// 4: RIGHT
void MoveSnake(int direction) {
    int SnaekLocationX, SnaekLocationY;
    bool GameEnd = false;
    for(int column = 0; column < HEIGHT; column++) {
        for(int row = 0; row < WIDTH; row++) {
            if(Board[column][row] == SNAKE) {
                SnaekLocationX = column;
                SnaekLocationY = row;
                break;
            }
        }
    }

    // up
    if(direction == 1) {
        if (Board[SnaekLocationX - 1][SnaekLocationY] == BORDER) {
            SnakeIsDead = true;
        }
        else if (Board[SnaekLocationX - 1][SnaekLocationY] == TREAT) {
            points++;
        }
        if (!GameEnd) {
        Board[SnaekLocationX][SnaekLocationY] = EMPTY_SPACE;
        Board[SnaekLocationX - 1][SnaekLocationY] = SNAKE;
        }
    }

    // left
    if(direction == 2) {
        if (Board[SnaekLocationX][SnaekLocationY - 1] == BORDER) {
            SnakeIsDead = true;
        }
        else if (Board[SnaekLocationX][SnaekLocationY - 1] == TREAT) {
            points++;
        }
        if (!GameEnd) {
        Board[SnaekLocationX][SnaekLocationY] = EMPTY_SPACE;
        Board[SnaekLocationX][SnaekLocationY - 1] = SNAKE;
        }
    }

    // down
    if(direction == 3) {
        if (Board[SnaekLocationX + 1][SnaekLocationY] == BORDER) {
            SnakeIsDead = true;
        }
        else if (Board[SnaekLocationX + 1][SnaekLocationY] == TREAT) {
            points++;
        }
        if (!GameEnd) {
        Board[SnaekLocationX][SnaekLocationY] = EMPTY_SPACE;
        Board[SnaekLocationX + 1][SnaekLocationY] = SNAKE;
        }
    }

    // right
    if(direction == 4) {
        if (Board[SnaekLocationX][SnaekLocationY + 1] == BORDER) {
            SnakeIsDead = true;
        }
        else if (Board[SnaekLocationX][SnaekLocationY + 1] == TREAT) {
            points++;
        }
        if (!GameEnd) {
        Board[SnaekLocationX][SnaekLocationY] = EMPTY_SPACE;
        Board[SnaekLocationX][SnaekLocationY + 1] = SNAKE;
        }
    }



}
#endif