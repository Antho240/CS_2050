#include "prelab4.h"

int main(void){
    FILE* fp = NULL;
    Employee* employees = NULL;
    employees = readEmployeeArray(fp);
    
    if(setEmpSalary(employees, 14000, 154000.00)){
        printf("***Set Employee salary failed***\n");
    }
    float salary;
    if(getEmpSalary(employees, 14000, &salary)){
        printf("***Get Employee salary failed***\n");
    }
    else{
        printf("Salary of employee from lookup: %.2f\n", salary);
    }

    if(setEmpJobType(employees, 14000, 5)){
        printf("***Set job type failed***\n");
    }
    int job;
    if(getEmpJobType(employees, 14000, &job)){
        printf("***Get job type failed***\n");
    }
    else{
        printf("Job type of employee from lookup: %d\n", job);
    }
   


    if(!freeArray(&employees)){
        printf("memory succesfully freed\n");
    }
    //printf("address after free: %p\n", employees);
    return 0;
}