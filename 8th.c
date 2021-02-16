/*
Design, Develop and Implement a menu driven Program in C for the following
operations on Doubly Linked List (DLL) of Employee Data with the fields: SSN, Name,
Dept, Designation,Sal, PhNo
a. Create a DLL of N Employees Data by using end insertion.
b. Display the status of DLL and count the number of nodes in it
c. Perform Insertion and Deletion at End of DLL
d. Perform Insertion and Deletion at Front of DLL
e. Demonstrate how this DLL can be used as Double Ended Queue
f. Exit
*/

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct EmployeeData{
    struct EmployeeData *prev;
    int SSN,  PhNo;
    char name[20], dept[20], designation[20];
    float sal;
    struct EmployeeData *next;
};

typedef struct EmployeeData employee;
employee *first = NULL, *last = NULL;
int n;


void CreateList(int n){
    employee *t;
    int i;

    first = (employee*) malloc(sizeof(employee));
    first -> prev = NULL;
    printf("\n Enter employee id: ");
    scanf("%d", &first -> SSN);
    printf("\n Enter employee name: ");
    scanf("%s", &first -> name);
    printf("\n Enter employee deptartment: ");
    scanf("%s", &first -> dept);
    printf("\n Enter employee designation: ");
    scanf("%s", &first -> designation);
    printf("\n Enter employee salary: ");
    scanf("%f", &first -> sal);
    printf("\n Enter employee phone number: ");
    scanf("%d", &first -> PhNo);

    first -> next = NULL;
    last = first;


    for(i=1; i<n; i++){
        t = (employee*) malloc(sizeof(employee));
        t -> prev = last;
        last -> next = t;
        printf("\n Enter employee id: ");
        scanf("%d", &t -> SSN);
        printf("\n Enter employee name: ");
        scanf(" %s", &t -> name);
        printf("\n Enter employee deptartment: ");
        scanf(" %s", &t -> dept);
        printf("\n Enter employee designation: ");
        scanf(" %s", &t -> designation);
        printf("\n Enter employee salary: ");
        scanf("%f", &t -> sal);
        printf("\n Enter employee phone number: ");
        scanf("%d", &t -> PhNo);
        t -> next = NULL;
        last = t;
    }
}

void display(){
    if(first == NULL){
        printf("\n NO data is entered, list is empty: \n");
    }
    else{
        employee *t;
        t = first;
        while(t != NULL){
            printf("\n Employee id: %d", t -> SSN);
            printf("\n Employee name: %s", t -> name);
            printf("\n Employee department: %s", t -> dept);
            printf("\n Employee designatio: %s", t -> designation);
            printf("\n employee salary: %f", t -> sal);
            printf("\n employee Phone NUMB.: %d", t -> PhNo);

            t = t-> next;
            printf("\n \n");
        }
    }
}

void insertEnd(){
    employee *t = (employee*)malloc(sizeof(employee));
    printf("\n Enter employee id: ");
    scanf("%d", &t -> SSN);
    printf("\n Enter employee name: ");
    scanf("%s", &t -> name);
    printf("\n Enter employee deptartment: ");
    scanf("%s", &t -> dept);
    printf("\n Enter employee designation: ");
    scanf("s", &t -> designation);
    printf("\n Enter employee salary: ");
    scanf("%f", &t -> sal);
    printf("\n Enter employee phone number: ");
    scanf("%d", &t -> PhNo);

    if(first == NULL){
        t -> prev = NULL;
        t -> next = NULL;
        first = t;
        last = first;
    }
    else{
        t -> next = NULL;
        t -> prev = last;
        last -> next = t;
        last = t;
    }
}

void insertFront(){
    employee *t = (employee*)malloc(sizeof(employee));
    printf("\n Enter employee id: ");
    scanf("%d", &t -> SSN);
    printf("\n Enter employee name: ");
    scanf("%s", &t -> name);
    printf("\n Enter employee deptartment: ");
    scanf("%s", &t -> dept);
    printf("\n Enter employee designation: ");
    scanf("%s", &t -> designation);
    printf("\n Enter employee salary: ");
    scanf("%f", &t -> sal);
    printf("\n Enter employee phone number: ");
    scanf("%d", &t -> PhNo);

    if(first == NULL){
        t -> prev = NULL;
        t -> next = NULL;
        first = t;
        last = first;
    }
    else{
        t -> next = first;
        t -> prev = NULL;
        first -> prev = t;
        first = t;
    }
}

void deleteEnd(){
    employee *t = last;
    employee *d;
    d = last;
    t = last -> prev;
    t -> next = NULL;
    last = t;
    free(d);
}

void deleteFront(){
    employee *t = first;
    employee *d;
    d = first;
    t = first -> next;
    t -> prev = NULL;
    first = t;
    free(d);
}

void main(){
    int choice, key, info;
    while(1){
        printf("\nDLIST OPERATIONS\n");
        printf("1.Create a list \n ");
        printf("2.INSERT at End of DLL \n ");
        printf("3.INSERT at Front of DLL\n ");
        printf("4.DELETE at End of DLL \n ");
        printf("5.DELETE at Front of DLL \n ");
        printf("6. DISPLAY\n ");
        printf("7.EXIT\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("\n Enter the number of elements to be included is list: ");
                    scanf("%d", &n);
                    CreateList(n);
            break;

            case 2: insertEnd();
            break;

            case 3: insertFront();
            break;

            case 4: deleteEnd();
            break;

            case 5: deleteFront();
            break;

            case 6: display();
            break;

            case 7: exit(0);

        }
    }
}