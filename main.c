#include "battleship.h"
#define ROW_SIZE 10

int main(void){
    int **board = NULL;
    int cols[ROW_SIZE] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    int shipCount = 0;
    printf("Enter the number of ships: ");
    scanf("%d", &shipCount);
    int shipNumber = 0;
    board = createBoard(board, ROW_SIZE, cols);
    if (board == NULL){
        printf("memeory allocation failed");
    }
    battleships *fleet = malloc(sizeof(battleships) * shipCount);
    
    while (shipNumber < shipCount){
        createShip(&fleet[shipNumber], shipNumber);
        placeShip(board, &fleet[shipNumber]);
        shipNumber++;
    }

    printBoard(board);
    freeBoard(board);
}