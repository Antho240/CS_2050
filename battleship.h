#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROW_SIZE 10

// struct defintions
typedef struct
{
    char name[20];
    int length;
    int startPostion[2];
    char direction;
} battleships;

// function headers
int **createBoard(int **board, int rows, int *cols);
void placeShip(int **board, battleships *ship);
void printBoard(int **board);
void freeBoard(int **board);
void createShip(battleships *ship, int shipCount);
