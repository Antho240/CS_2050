#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define NUMBER_OF_CLASSES 5

typedef struct {
    char name[50];
    float speed; //spee in light-years per hour
} Spaceship;

Spaceship** load_fleet(const char* filename);
char class_with_highest_average_speed(Spaceship** fleet);
void free_fleet(Spaceship** fleet);
void printShip(Spaceship ship);
void printFleet(Spaceship** fleet);