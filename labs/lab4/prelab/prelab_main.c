#include "prelab4.h"

int main(void){
    FILE* fp = NULL;
    Employee* emps = NULL;
    emps = readEmployeeArray(fp);
    Employee* emp1 = NULL;
    int id = 11000;
    emp1 = getEmployeeByID(emps, id);
    if(emp1 != NULL){
        printf("Employee with ID #%d info: %d, %d, %.2f\n", id, emp1->empID, emp1->jobType, emp1->salary);
    }
    
    float salary=0;
    if(getEmpSalary(emps, id, &salary)){
        printf("***Failed to get salary***\n");
    }
    else{
        printf("Employee with ID #%d salary: %.2f\n", id, salary);
    }

    int jobtype;
    if(getEmpJobType(emps, id, &jobtype)){
        printf("***Failed to get jobtype***\n");
    }
    else{
        printf("Employee with ID #%d jobtype: %d\n", id, jobtype);
    }

    int set_salary = 70000;
    if(setEmpSalary(emps, id, set_salary)){
        printf("***Failed to set salary***\n");
    }
    else{
        getEmpSalary(emps, id, &salary);
        printf("Employee with ID #%d salary updated to: %.2f\n", id, salary);
    }

    int set_jobtype = 2;
    if(setEmpJobType(emps, id, set_jobtype)){
        printf("***Failed to set jobtype***\n");
    }
    else{
        getEmpJobType(emps, id, &jobtype);
        printf("Employee with ID #%d jobtype updated to: %d\n", id, jobtype);
    }


    
    freeArray(&emps);
    if(emps==NULL){
        printf("***memory freed succesfully***\n");
    }
    return 0;
}