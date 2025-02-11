#include "battleship.h"

int **createBoard(int **board, int rows, int *cols){
    // allocate board
    board = malloc(sizeof(int) + sizeof(char *) * rows);
    // printf("before shift: %p", board);
    ((int *)board)[0] = rows;
    board = ((int **)(((int *)board) + 1));
    // printf("after shift: %p", board);
    for (int i = 0; i < rows; i++){
        board[i] = malloc(sizeof(int) + sizeof(int) * cols[i]);
        if (board[i] == NULL)
        {
            printf("Memory allocation failed");
            exit(1);
        }
        board[i][0] = cols[i];
        board[i]++;
    }
    // intialize board
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols[i]; j++){
            board[i][j] = 0;
        }
    }
    return board;
}

void createShip(battleships *ship, int shipCount){
    char name[20];
    int length = 0;
    int startPostion[2] = {0, 0};
    char direction;
    printf("Enter name of ship %d: ", shipCount);
    scanf("%s",name);
    printf("Enter length of ship %d: ", shipCount);
    scanf("%d", &length);
    printf("Enter the starting row and column (0-9): ");
    scanf("%d, %d", &startPostion[0], &startPostion[1]);
    printf("Enter direction of ship (H/V): ");
    getchar();
    direction = getchar();
    printf("\n");
    strncpy(ship->name, name, length);
    ship->length = length;
    ship->startPostion[0] = startPostion[0];
    ship->startPostion[1] = startPostion[1];
    ship->direction = direction;
}

void placeShip(int **board, battleships *ship){
    int startPostion[2] = {ship->startPostion[0], ship->startPostion[1]};
    char direction = ship->direction;
    int length = ship->length;
    if (direction == 'V'){
        if(startPostion[0] + length > 9 && startPostion[0] - length < 0){
            printf("error out of bounds");
            exit(1);
        }
        if(startPostion[0] - length < 0) {
            for (int i = 0; i < length; i++){
            board[startPostion[0] + i][startPostion[1]] = 1;
            }
        }
        else{
            for (int i = 0; i < length; i++){
            board[startPostion[0] - i][startPostion[1]] = 1;
            }
        }
    }
    else if (direction == 'H'){
        if(startPostion[1] + length > 9 && startPostion[1] - length < 0){
            printf("error out of bounds");
            exit(1);
        }
        if(startPostion[1] - length < 0) {
            for (int i = 0; i < length; i++){
            board[startPostion[0]][startPostion[1] + i] = 1;
            }
        }
        else{
            for (int i = 0; i < length; i++){
            board[startPostion[0]][startPostion[1] - i] = 1;
            }
        }
    }
}

void printBoard(int **board){
    printf("Board:\n");
    int *p = ((int *)board) - 1;
    for (int i = 0; i < *p; i++){
        for (int j = 0; j < board[i][-1]; j++){
            if(board[i][j] == 0){
                printf("~ ");
            }
            else{
                printf("S ");
            }
            //printf("%d", board[i][j]);
        }
        printf("\n");
    }
}

void freeBoard(int **board){
    int *p = ((int *)board) - 1;
    for (int i = 0; i < *p; i++){
        board[i] = board[i] - 1;
        free(board[i]);
    }
    free(p);
}
