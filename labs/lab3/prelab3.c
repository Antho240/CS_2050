#include "prelab3.h"

Spaceship** load_fleet(const char* filename){
    FILE* fp = fopen(filename, "r");
    if(fp == NULL){
        printf("unable to open file");
        return NULL;
    }

    int cols[NUMBER_OF_CLASSES] = {0}; //E C M D V
    if(fscanf(fp, "%d %d %d %d %d", &cols[0], &cols[1], &cols[2], &cols[3], &cols[4]) != 5){
        fclose(fp);
        printf("invalid count of types at top of file");
        return NULL;
    }
    Spaceship** fleet = malloc(sizeof(Spaceship*) * NUMBER_OF_CLASSES);
    if(fleet == NULL){
        printf("fleet allocation failed");
        fclose(fp);
        return NULL;
    }
    for(int i=0; i<NUMBER_OF_CLASSES; i++){
        fleet[i] = malloc(sizeof(int) + sizeof(Spaceship) * cols[i]);
        ((int*)fleet[i])[0] = cols[i];
        fleet[i] = ((Spaceship*)(((int*)fleet[i])+1));
    }

    char name[50];
    char class;
    float speed;
    int count_of_class[NUMBER_OF_CLASSES] = {-1,-1,-1,-1,-1};//start at -1 so when incrementing the first time it will start at 0
    while(fscanf(fp, "%s %c %f", name, &class, &speed) == 3){
        int index_of_class;
        switch(class){
            case 'E': 
            index_of_class = 0;
            count_of_class[index_of_class]++;
            break;
            case 'C':
            index_of_class = 1;
            count_of_class[index_of_class]++; 
            break;
            case 'M':
            index_of_class = 2;
            count_of_class[index_of_class]++;
            break;
            case 'D':
            index_of_class = 3;
            count_of_class[index_of_class]++;
            break;
            case 'V':
            index_of_class = 4;
            count_of_class[index_of_class]++;
            break;
            default: continue;
        }
        fleet[index_of_class][count_of_class[index_of_class]].speed = speed;
        strncpy(fleet[index_of_class][count_of_class[index_of_class]].name, name, 50);
    }
    fclose(fp);
    return fleet;
}

char class_with_highest_average_speed(Spaceship** fleet){
    //E C M D V
    int index;
    float avg_speed[NUMBER_OF_CLASSES] = {0.0};
    for(int i=0; i<NUMBER_OF_CLASSES; i++){
        float sum= 0.0;
        float avg = 0.0;
        for(int j=0; j<(((int*)fleet[i])[-1]); j++){
            sum+=fleet[i][j].speed;
        }
        avg = sum/(((int*)fleet[i])[-1]);
        avg_speed[i] = avg;
    }
    int max = INT_MIN;
    for(int i=0; i<NUMBER_OF_CLASSES; i++){
        if(avg_speed[i] > max){
            max = avg_speed[i];
            index = i;
        }
    }
    switch (index) {
    case 0: return 'E'; break;
    case 1: return 'C'; break;
    case 2: return 'M'; break;
    case 3: return 'D'; break;
    case 4: return 'V'; break;
    default: printf("average speed not found"); exit(1); break;
    }
    return 'z';
}

void free_fleet(Spaceship** fleet){
    //int* p = ((int*)fleet)-1;
    for(int i=0; i<NUMBER_OF_CLASSES; i++){
        fleet[i] = ((Spaceship*)(((int*)fleet[i])-1));
        free(fleet[i]);
    }
    free(fleet);
}