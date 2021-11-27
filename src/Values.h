// values i may or may not change often
const bool DEBUG_MODE = 0;
const std::string EMPTY_SPACE = " ";
const std::string SNAKE = "\033[1;31mo\033[0m";
const std::string SNAKE_HEAD = "\033[1;31m@\033[0m";
const std::string TREAT = "\033[1;36m$\033[0m";
const std::string BORDER = ".";

// height and width of the board
#define HEIGHT 15
#define WIDTH 20

std::string Board[HEIGHT][WIDTH];
bool SnakeIsDead;

int Points, SnakeLocationX, SnakeLocationY, PlacedSnakeNum;
int SnakeLength = 0;
