/*********** Declaration*******
I hereby certify that no part of this assignment has been copied from any other student’s work or from any other source. No part of the code has been written/produced for me by another person or copied from any other source.
I hold a copy of this assignment that I can produce if the original is lost or damaged.
**************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define PASSER 1
#define EATER -1
#define UNOCCUPIED 0

#define MIN_BOARD_SIZE 3

// Board structure to store the game board and its size
typedef struct
{
    int size;
    int **board;
} Board;

struct Move
{
    int x, y;
};

// Function prototypes
void initBoard(Board *b);
void printBoard(Board *b);
bool addMove(Board *b, int x, int y, int player);
bool checkWin(Board *b, int player);
bool checkFull(Board *b);
void randomMove(Board *b, int player);
void straightLineMove(Board *b, int player);
void makeMove(Board *b, struct Move move, int player);
void undoMove(Board *b, struct Move move);
void smartMove(Board *b, int player);
bool checkWinForPasser(Board *b, int player, int x, int y);
bool checkWinForEater(Board *b, int player, int x, int y);

int main(void)
{
    int choice;
    printf("Enter 1 to play as human vs human\n");
    printf("Enter 2 to play as the Passer against a random player\n");
    printf("Enter 3 to play as the Eater against a random player\n");
    printf("Enter 4 to play as the Passer against the straight line player\n");
    printf("Enter 5 to play as the Eater against the straight line player\n");

    printf("\nEnter 1, 2, 3, 4 or 5:");
    scanf("%d", &choice);

    if (choice == 1)
    {
        Board b;
        printf("Enter the size of the board (minimum size is %d): ", MIN_BOARD_SIZE);
        scanf("%d", &b.size);
        while (b.size < MIN_BOARD_SIZE)
        {
            printf("The size of the board must be at least %d. Please enter a valid size: ", MIN_BOARD_SIZE);
            scanf("%d", &b.size);
        }
        initBoard(&b);
        printBoard(&b);
        srand(time(NULL));
        int player = PASSER;
        while (true)
        {
            if (player == PASSER)
            {
                int x, y;
                printf("Passer's turn to move \n");
                printf("Enter Row: ");
                scanf("%d", &x);
                printf("Enter Column: ");
                scanf("%d", &y);
                x--;
                y--;
                if (!addMove(&b, x, y, player))
                {
                    printf("Invalid move. Try again. \n");
                    continue;
                }

                if (checkWin(&b, player))
                {
                    printf("Passer wins! \n");
                    break;
                }
                if (checkFull(&b))
                {
                    printf("Draw! \n");
                    break;
                }
                player = EATER;
            }
            else if (player == EATER)
            {
                int x, y;
                printf("Eater's turn to move \n");
                printf("Enter Row: ");
                scanf("%d", &x);
                printf("Enter Column: ");
                scanf("%d", &y);
                x--;
                y--;
                if (!addMove(&b, x, y, player))
                {
                    printf("Invalid move. Try again. \n");
                    continue;
                }
                printBoard(&b);
                if (checkWin(&b, player))
                {
                    printf("Eater wins! \n");
                    break;
                }
                if (checkFull(&b))
                {
                    printf("Draw! \n");
                    break;
                }
                player = PASSER;
            }
        }
            printBoard(&b);
    }

    if (choice == 2)
    {
        Board b;
        printf("Enter the size of the board (minimum size is %d): ", MIN_BOARD_SIZE);
        scanf("%d", &b.size);
        while (b.size < MIN_BOARD_SIZE)
        {
            printf("The size of the board must be at least %d. Please enter a valid size: ", MIN_BOARD_SIZE);
            scanf("%d", &b.size);
        }
        initBoard(&b);
        printBoard(&b);
        srand(time(NULL));
        int player = PASSER;
        while (true)
        {
            if (player == PASSER)
            {
                int x, y;
                printf("Passer's turn to move\n");
                printf("Enter Row: ");
                scanf("%d", &x);
                printf("Enter Column: ");
                scanf("%d", &y);
                x--;
                y--;
                if (!addMove(&b, x, y, player))
                {
                    printf("Invalid move. Try again. \n");
                    continue;
                }
                if (checkWin(&b, player))
                {
                    printf("Passer wins! \n");
                    break;
                }
                if (checkFull(&b))
                {
                    printf("Draw! \n");
                    break;
                }
                player = EATER;
            }
            else if (player == EATER)
            {
                printf("Eater's turn to move \n");
                smartMove(&b, player);
                printBoard(&b);
                if (checkWin(&b, player))
                {
                    printf("Eater wins! \n");
                    break;
                }
                if (checkFull(&b))
                {
                    printf("Draw! \n");
                    break;
                }
                player = PASSER;
            }
        }
            printBoard(&b);
    }

    else if (choice == 3)
    {
        Board b;
        printf("Enter the size of the board (minimum size is %d): ", MIN_BOARD_SIZE);
        scanf("%d", &b.size);
        while (b.size < MIN_BOARD_SIZE)
        {
            printf("The size of the board must be at least %d. Please enter a valid size: ", MIN_BOARD_SIZE);
            scanf("%d", &b.size);
        }
        initBoard(&b);
        printBoard(&b);
        srand(time(NULL));
        int player = EATER;
        while (true)
        {
            if (player == EATER)
            {
                int x, y;
                printf("Eater's turn to move\n");
                printf("Enter Row: ");
                scanf("%d", &x);
                printf("Enter Column: ");
                scanf("%d", &y);
                x--;
                y--;
                if (!addMove(&b, x, y, player))
                {
                    printf("Invalid move. Try again. \n");
                    continue;
                }

                if (checkWin(&b, player))
                {
                    printf("Eater wins! \n");
                    break;
                }
                if (checkFull(&b))
                {
                    printf("Draw! \n");
                    break;
                }
                player = PASSER;
            }

            else if (player == PASSER)
            {
                printf("Passer's turn to move \n");
                smartMove(&b, player);
                printBoard(&b);
                if (checkWin(&b, player))
                {
                    printf("Passer wins! \n");
                    break;
                }
                if (checkFull(&b))
                {
                    printf("Draw! \n");
                    break;
                }
                player = EATER;
            }
        }
            printBoard(&b);
    }

    else if (choice == 4)
    {
        Board b;
        printf("Enter the size of the board (minimum size is %d): ", MIN_BOARD_SIZE);
        scanf("%d", &b.size);
        while (b.size < MIN_BOARD_SIZE)
        {
            printf("The size of the board must be at least %d. Please enter a valid size: ", MIN_BOARD_SIZE);
            scanf("%d", &b.size);
        }
        initBoard(&b);
        printBoard(&b);
        srand(time(NULL));
        int player = PASSER;
        while (true)
        {
            if (player == PASSER)
            {
                int x, y;
                printf("Passer's turn to move\n");
                printf("Enter Row: ");
                scanf("%d", &x);
                printf("Enter Column: ");
                scanf("%d", &y);
                x--;
                y--;
                if (!addMove(&b, x, y, player))
                {
                    printf("Invalid move. Try again. \n");
                    continue;
                }
                if (checkWin(&b, player))
                {
                    printf("Passer wins! \n");
                    break;
                }
                if (checkFull(&b))
                {
                    printf("Draw! \n");
                    break;
                }
                player = EATER;
            }
            else if (player == EATER)
            {
                printf("Eater's turn to move \n");
                straightLineMove(&b, player);
                printBoard(&b);
                if (checkWin(&b, player))
                {
                    printf("Eater wins! \n");
                    break;
                }
                if (checkFull(&b))
                {
                    printf("Draw! \n");
                    break;
                }
                player = PASSER;
            }
        }
            printBoard(&b);
    }

    else if (choice == 5)
    {
        Board b;
        printf("Enter the size of the board (minimum size is %d): ", MIN_BOARD_SIZE);
        scanf("%d", &b.size);
        while (b.size < MIN_BOARD_SIZE)
        {
            printf("The size of the board must be at least %d. Please enter a valid size: ", MIN_BOARD_SIZE);
            scanf("%d", &b.size);
        }
        initBoard(&b);
        printBoard(&b);
        srand(time(NULL));
        int player = EATER;
        while (true)
        {
            if (player == PASSER)
            {
                printf("Passer's turn to move \n");
                straightLineMove(&b, player);
                printBoard(&b);
                if (checkWin(&b, player))
                {
                    printf("Passer wins! \n");
                    break;
                }
                if (checkFull(&b))
                {
                    printf("Draw! \n");
                    break;
                }
                player = EATER;
            }
            else if (player == EATER)
            {
                int x, y;
                printf("Eater's turn to move \n");
                printf("Enter Row: ");
                scanf("%d", &x);
                printf("Enter Column: ");
                scanf("%d", &y);
                x--;
                y--;
                if (!addMove(&b, x, y, player))
                {
                    printf("Invalid move. Try again. \n");
                    continue;
                }

                if (checkWin(&b, player))
                {
                    printf("Eater wins! \n");
                    break;
                }
                if (checkFull(&b))
                {
                    printf("Draw! \n");
                    break;
                }
                player = PASSER;
            }
        }
            printBoard(&b);
    }
}

// Initializes the board with the given size and sets all cells to unoccupied
void initBoard(Board *b)
{
    b->board = (int **)malloc(b->size * sizeof(int *));
    for (int i = 0; i < b->size; i++)
    {
        b->board[i] = (int *)malloc(b->size * sizeof(int));
    }

    for (int i = 0; i < b->size; i++)
    {
        for (int j = 0; j < b->size; j++)
        {
            b->board[i][j] = UNOCCUPIED;
        }
    }
}

// Prints the game board
void printBoard(Board *b)
{
    // Calculate the number of spaces to print before the board
    int numSpaces = (b->size * 5 - 1) / 2;

    printf("\n\n");
    // Print spaces
    for (int i = 0; i < numSpaces; i++)
    {
        printf("   ");
    }

    // Print column numbers
    printf("        ");
    for (int j = 0; j < b->size; j++)
    {
        printf("%d       ", j + 1);
    }
    printf("\n");
    // print straight line above the board to make it look better
    for (int i = 0; i < numSpaces; i++)
    {
        printf("   ");
    }
    for (int i = 0; i < b->size; i++)
    {
        printf("_________");
    }
    printf("\n\n");
    for (int i = 0; i < b->size; i++)
    {
        // Print spaces
        for (int j = 0; j < numSpaces; j++)
        {
            printf("   ");
        }

        // Print row number
        printf("%d       ", i + 1);

        // Print row of board
        for (int j = 0; j < b->size; j++)
        {
            if (b->board[i][j] == UNOCCUPIED)
            {
                printf("_       ");
            }
            else if (b->board[i][j] == PASSER)
            {
                printf("P       ");
            }
            else
            {
                printf("E       ");
            }
        }
        printf("\n\n");
    }
    // print straight line under the board to make it look better
    for (int i = 0; i < numSpaces; i++)
    {
        printf("   ");
    }
    for (int i = 0; i < b->size; i++)
    {
        printf("_________");
    }
    printf("\n\n");
}

// Adds a move to the board at the specified position for the specifi3 2ed player
bool addMove(Board *b, int x, int y, int player)
{
    // Check if the position is out of bounds
    if (x < 0 || x >= b->size || y < 0 || y >= b->size)
    {
        return false;
    }

    // Check if the position is already occupied
    if (b->board[x][y] != UNOCCUPIED)
    {
        return false;
    }

    b->board[x][y] = player;
    return true;
}

// Returns true if the board is full, false otherwise
bool checkFull(Board *b)
{
    for (int i = 0; i < b->size; i++)
    {
        for (int j = 0; j < b->size; j++)
        {
            if (b->board[i][j] == UNOCCUPIED)
            {
                return false;
            }
        }
    }
    return true;
}

// Makes a random move for the specified player
void randomMove(Board *b, int player)
{
    while (true)
    {
        int x = rand() % b->size;
        int y = rand() % b->size;
        if (addMove(b, x, y, player))
        {
            break;
        }
    }
}
void straightLineMove(Board *b, int player)
{
    for (int i = 0; i < b->size; i++)
    {
        for (int j = 0; j < b->size; j++)
        {
            if (b->board[i][j] == UNOCCUPIED)
            {
                makeMove(b, (struct Move){i, j}, player);
                return;
            }
        }
    }
}

void makeMove(Board *b, struct Move move, int player)
{
    addMove(b, move.x, move.y, player);
}

void undoMove(Board *b, struct Move move)
{
    b->board[move.x][move.y] = UNOCCUPIED;
}

void smartMove(Board *b, int player)
{
    // Implement the smart move for the eater here

    // First, try to find a winning move
    for (int i = 0; i < b->size; i++)
    {
        for (int j = 0; j < b->size; j++)
        {
            if (addMove(b, i, j, player))
            {
                if (checkWin(b, player))
                {
                    // Make the winning move and return
                    printf("Eater is making a winning move at (%d, %d)\n", i, j);
                    return;
                }
                else
                {
                    // Undo the move
                    undoMove(b, (struct Move){i, j});
                }
            }
        }
    }

    // If there is no winning move, try to block the passer from winning
    for (int i = 0; i < b->size; i++)
    {
        for (int j = 0; j < b->size; j++)
        {
            if (addMove(b, i, j, PASSER))
            {
                if (checkWin(b, PASSER))
                {
                    // Make the blocking move and return
                    printf("Eater is making a blocking move at (%d, %d)\n", i, j);
                    makeMove(b, (struct Move){i, j}, player);
                    return;
                }
                else
                {
                    // Undo the move
                    undoMove(b, (struct Move){i, j});
                }
            }
        }
    }

    // If there is no winning or blocking move, make a random move
    randomMove(b, player);
}

// Returns true if the game is won, false otherwise
bool checkWin(Board *b, int player)
{
    // Check if the game is won by going down
    for (int i = 0; i < b->size; i++)
    {
        if (checkWinForPasser(b, player, 0, i))
        {
            return true;
        }
    }

    // Check if the game is won by going up
    for (int i = 0; i < b->size; i++)
    {
        if (checkWinForEater(b, player, b->size - 1, i))
        {
            return true;
        }
    }

    return false;
}

// Returns true if the game is won by going down, false otherwise
bool checkWinForPasser(Board *b, int player, int x, int y)
{
    // Check if the position is out of bounds
    if (x < 0 || x >= b->size || y < 0 || y >= b->size)
    {
        return false;
    }

    // Check if the position is occupied by the player
    if (b->board[x][y] != player)
    {
        return false;
    }

    // Check if the player has reached the bottom of the board
    if (x == b->size - 1)
    {
        return true;
    }

    // Check if the player has won by going down
    if (checkWinForPasser(b, player, x + 1, y))
    {
        return true;
    }

    // Check if the player has won by going down-left
    if (checkWinForPasser(b, player, x + 1, y - 1))
    {
        return true;
    }

    // Check if the player has won by going down-right
    if (checkWinForPasser(b, player, x + 1, y + 1))
    {
        return true;
    }

    return false;
}

// Returns true if the game is won by going up, false otherwise
bool checkWinForEater(Board *b, int player, int x, int y)
{
    // Check if the position is out of bounds
    if (x < 0 || x >= b->size || y < 0 || y >= b->size)
    {
        return false;
    }

    // Check if the position is occupied by the player
    if (b->board[x][y] != player)
    {
        return false;
    }

    // Check if the player has reached the top of the board
    if (x == 0)
    {
        return true;
    }

    // Check if the player has won by going up
    if (checkWinForEater(b, player, x - 1, y))
    {
        return true;
    }

    // Check if the player has won by going up-left
    if (checkWinForEater(b, player, x - 1, y - 1))
    {
        return true;
    }

    // Check if the player has won by going up-right
    if (checkWinForEater(b, player, x - 1, y + 1))
    {
        return true;
    }

    return false;
}
