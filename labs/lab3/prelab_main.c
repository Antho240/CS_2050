#include "prelab3.h"


int main(void){
    const char filename[] = "fleet.txt";
    Spaceship** fleet = NULL;
    fleet = load_fleet(filename);
    char fastest_class = class_with_highest_average_speed(fleet);
    printf("Class with greatest average speed is %c!\n",fastest_class);
    free_fleet(fleet);
    return 0;
}