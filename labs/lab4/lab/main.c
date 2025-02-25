#include "lab4.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    int cols[5] = {1,2,3,4,5};
    void** courseArray = NULL;
    courseArray = allocateJagged2DArray(sizeof(Course), 5, cols);
    int rows = getRowCount(courseArray);
    int col = getColCount(courseArray, 2);
    printf("Rows: %d\nCol size of row 2: %d\n",rows, col);
    Course * course1 = NULL;
    course1 = createCourse(1050, "CompSci", "Algo&Design1");
    char info[100];
    
    if(getCourseInfo(course1, info) == 1){
        printf("Course 1 info: %s\n", info);
    }
    Course * course2 = NULL;
    course2 = createCourse(1050, "CompSci", "Algo & Design1");
    if(setCourseNumber(course2, 2050) == 0){
        printf("***Failed to set course number***\n");
    }
    if(setCourseName(course2, "DataStruct&Algoritms") == 0){
        printf("***Failed to set course number***\n");
    }
    if(setCourseDepartment(course2, "CompSci") == 0){
        printf("***Failed to set course number***\n");
    }
    char info2[100];
    if(getCourseInfo(course2, info2) == 1){
        printf("Course 2 info: %s\n", info2);
    }

    freeCourse(course1);
    freeCourse(course2);
    freeJagged2DArray(courseArray);
    return 0;
}
