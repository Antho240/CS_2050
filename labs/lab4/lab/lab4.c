//  Anthony Stuart      02/21/2025      ansmvf

#include "lab4.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void ** allocateJagged2DArray(int elementSize, int rows, int lengths[]){
    if(rows == 0){ //error checking to prevent seg fault
        return NULL;
    }
    void** array = malloc(sizeof(int) + sizeof(void*) * rows);
    if(array == NULL){
        return NULL;
    }
    ((int*)array)[0] = rows;
    array = (void**)(((int*)array)+1);
    for(int i=0; i<rows; i++){
        array[i] = malloc(sizeof(int) + elementSize * lengths[i]);
        ((int*)array[i])[0] = lengths[i];
        array[i] = (void*)(((int*)array[i])+1);
    }
    return array;
}

void freeJagged2DArray(void ** arrayJagged){
    if(arrayJagged != NULL){ // error check to prevent seg fault
        int* p = (((int*)arrayJagged)-1);
        for(int i=0; i<*p; i++){
            arrayJagged[i] = (void*)(((int*)arrayJagged[i])-1);
            free(arrayJagged[i]);
        }
        free(p);
    }
}

int getRowCount(void ** arrayJagged){
    int count = ((int*)arrayJagged)[-1];
    return count;
}

int getColCount(void ** arrayJagged, int row){
    int count = ((int*)arrayJagged[row])[-1];
    return count;
}

Course * createCourse(int number, char * department, char * name){
    if(department== NULL || name == NULL){ //error checking to prevent seg fault
        return NULL;
    }
    Course* course = malloc(sizeof(Course));
    course->number = number;
    strncpy(course->department, department, 64);
    strncpy(course->name, name, 64);
    return course;
}

void freeCourse(Course * pCourse){
    free(pCourse);
}

int getCourseInfo(Course * pCourse, char * outputString){
    if(pCourse == NULL){ //error checking to prevent seg fault
        return 0;
    }
    int number = pCourse->number;
    // sprintf used to paste the data from the struct into the output string
    sprintf(outputString, "%d %s %s", number, pCourse->department, pCourse->name);
    return 1;
}

int setCourseNumber(Course * pCourse, int number){
    if(pCourse == NULL){ //error checking to prevent seg fault
        return 0;
    }
    pCourse->number = number;
    return 1;
}

int setCourseDepartment(Course * pCourse, char * department){
    if(pCourse == NULL || department==NULL){ //error checking to prevent seg fault
        return 0;
    }
    strncpy(pCourse->department, department, 64);
    return 1;
}

int setCourseName(Course * pCourse, char * name){
    if(pCourse == NULL || name==NULL){ //error checking to prevent seg fault
        return 0;
    }
    strncpy(pCourse->name, name, 64);
    return 1;
}