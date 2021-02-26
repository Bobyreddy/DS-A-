/*
Design, Develop and Implement a menu driven Program in C for the following
operations on Singly Linked List (SLL) of Student Data with the fields: USN, Name,
Branch, Sem, PhNo
a. Create a SLL of N Students Data by using front insertion.
b. Display the status of SLL and count the number of nodes in it
c. Perform Insertion and Deletion at End of SLL
d. Perform Insertion and Deletion at Front of SLL
e. Demonstrate how this SLL can be used as STACK and QUEUE
f. Exit
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct nodes{
    int usn, sem, phno;
    char name[20], branch[20];
    struct nodes *link; 
}node;

node *start = NULL;

int usn, sem, phno;
char name[20], branch[20];

void create();
void display();
void insertfront();
void insertend();
void deletefront();
void deleteend();
void printfun();

void main(){
    int ch;
    do{
        printf("\n MENU \n\n 1. create\n 2. display\n 3. insert front\n 4. delete front\n 5. insert end\n 6. delete end\n 7. Exit..\n \n enter your choice...: ");
        scanf("%d", &ch);
        switch(ch){
            case 1: create(); 
            break;

            case 2: display();
            break;

            case 3: insertfront();
            break;

            case 4: deletefront();
            break;

            case 5: insertend();
            break;

            case 6: deleteend();
            break;

            case 7: exit(0);
        }
    }while(ch != 7);
}

void create(){
    node *tmp;
    int n, i;
    printf("\n \n how many nodes u want to create \n ");
    scanf("%d", &n);
    for(i=0; i<n; i++){
        printfun();
        tmp = (node*)malloc(sizeof(node));
        tmp -> usn = usn;
        tmp -> sem = sem;
        tmp -> phno = phno;
        strcpy(tmp -> name, name);
        strcpy(tmp -> branch, branch);
        tmp -> link = NULL;
        if(start == NULL){
            start = tmp;
        }
        else{
            tmp -> link = start;
            start = tmp;
    }
    }
}

void display(){
    node *q;
    int count = 0;
    if(start == NULL){
        printf("\n list is empty \n");
    }
    else{
        q = start;
        while(q != NULL){
            count++;
            printf("\n USN : %d", q -> usn);
            printf("\n SEM : %d", q -> sem);
            printf("\n PHNO : %d", q -> phno);
            printf("\n NAME : %s", q -> name);
            printf("\n BRANCH : %s\n", q -> branch);
            q = q -> link;
        }
        printf("\nTotal number of students = %d", count);
    }
}

void insertfront(){
    node *temp;
    temp = (node*)malloc(sizeof(node));
    printfun();
    temp -> usn = usn;
    temp -> sem = sem;
    temp -> phno = phno;
    strcpy(temp -> name, name);
    strcpy(temp -> branch, branch);
    temp -> link = NULL;
    if(start == NULL){
        start = temp;
    }
    else{
        temp -> link = start;
        start = temp;
    }
}

void insertend(){
    node *q, *temp;
    temp = (node*)malloc(sizeof(node));
    printfun();
    temp -> usn = usn;
    temp -> sem = sem;
    temp -> phno = phno;
    strcpy(temp -> name , name);
    strcpy(temp -> branch, branch);
    temp -> link = NULL;

    if(start == NULL){
        start = temp;
    }
    else{
        q = start;
        while(q -> link != NULL){
            q = q-> link;
        }
        q -> link = temp;
    }
}

void deletefront(){
    node *temp = start;
    if(start -> link == NULL){
        free(start); 
        start = NULL;
    }
    else{
        start = start -> link;
        free(temp);
    }
    printf("\n the element deleted successfully");
}

void deleteend(){
    node *temp = start;
    node *t;
    if(start -> link == NULL){
        free(start);
        start = NULL;
    }
    else{
        while(temp -> link != NULL){
            t = temp;
            temp = temp -> link;
        }
        free(t -> link);
        t -> link = NULL;
    }
    printf("\n the element deleted successfully");
}

void printfun(){
  printf("\n enter USN: ");
  scanf("%d", &usn);
  printf("\n enter name: ");
  scanf(" %s", &name);
  printf("\n enter branch: ");
  scanf(" %s", &branch);
  printf("\n enter SEM: ");
  scanf("%d", &sem);
  printf("\n enter phone no: ");
  scanf("%d", &phno);
  printf("\n");
}

