#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct{
    int empID;
    int jobType;
    float salary;
} Employee;

Employee * readEmployeeArray(FILE *fp);
Employee * getEmployeeByID(Employee * emp, int empID);
int setEmpSalary(Employee * emps, int empID, float salary);
int getEmpSalary(Employee * emps, int empID, float *salary);
int setEmpJobType(Employee * emps, int empID, int job);
int getEmpJobType(Employee * emps, int empID, int *job);
int freeArray(Employee** employees);
int getSize(Employee* employees);