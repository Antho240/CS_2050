#include "prelab4.h"


Employee * readEmployeeArray(FILE *fp){
    const char filename[50] = "employees.txt";
    fp = fopen(filename, "r");
    if(fp == NULL){
        printf("error opening file.\n");
        fclose(fp);
        return NULL;
    }
    int numEmp = 0;
    if(fscanf(fp, "%d", &numEmp) != 1 || numEmp == 0){
        printf("***Number of employees not detected***\n");
        fclose(fp);
        return NULL;
    }
    Employee* employees = NULL;
    employees = malloc(sizeof(int) + sizeof(Employee) * numEmp);
    if(employees == NULL){
        printf("***Malloc of employee array failed***\n");
        fclose(fp);
        return NULL;
    }
    ((int*)employees)[0] = numEmp;
    employees = (Employee*)(((int*)employees)+1);

    int empID = -1;
    int jobType = -1;
    float salary = -1;
    int i = 0;
    while(fscanf(fp, "%d %d %f", &empID, &jobType, &salary) == 3 && i<numEmp){
        employees[i].empID = empID;
        employees[i].jobType = jobType;
        employees[i].salary = salary;
        i++;
    }
    fclose(fp);
    return employees;
}

Employee * getEmployeeByID(Employee * emps, int empID){
    if(emps == NULL){
        return NULL;
    }
    int size = getSize(emps);
    if(size==0){
        return NULL;
    }
    for(int i=0; i<size; i++){
        if(empID == emps[i].empID){
            return &emps[i];
        }
    }
    printf("***No employees were found with provided ID***\n");
    return NULL;
}

int setEmpSalary(Employee * emps, int empID, float salary){
    Employee* emp = getEmployeeByID(emps, empID);
    if(emp != NULL){
        emp->salary = salary;
        return 0;
    }
    return 1;
}

int getEmpSalary(Employee * emps, int empID, float *salary){
    Employee* emp = getEmployeeByID(emps, empID);
    if(emp != NULL){
        *salary = emp->salary;
        return 0;
    }
    return 1;
}

int setEmpJobType(Employee * emps, int empID, int job){
    Employee* emp = getEmployeeByID(emps, empID);
    if(emp != NULL){
        emp->jobType = job;
        return 0;
    }
    return 1;
}

int getEmpJobType(Employee * emps, int empID, int *job){
    Employee* emp = getEmployeeByID(emps, empID);
    if(emp != NULL){
        *job = emp->jobType;
        return 0;
    }
    return 1;
}

int freeArray(Employee** employees){
    if(*employees != NULL){
        int *p = ((int*)(*employees))-1;
        free(p);
        (*employees) = NULL;
        return 0;
    }
    return 1;
}

int getSize(Employee* employees){
    if(employees == NULL){
        printf("***Failed to get size***\n");
        return 0;
    }
    int size = ((int*)employees)[-1];
    return size;
}