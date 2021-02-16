/*
__EXPEREMENT 01__

Design, Develop and Implement a menu driven program in C for the following Array operations
a. Creating Array of N Integer elements.
b. Display of Array elements with suitable headings.
c. Inserting an element (ELEM) at a given valid position (POS).
d. Deleting an element at a given valid position (POS).
e. Exit.


ALGORITHM:

Step 1: Start.
Step 2: read N value.
Step 3: read array of N integer elements.
Step 4: print array of N integer elements.
Step 5: insert an element at given position in an array.
step 6: delete an element at given position from an array.
Step 7: stop. 

*/

#include<stdio.h>
#include<stdlib.h>

int a[10], n, elem, i, pos;

void create(){
    printf("\n enter the size of array:");
    scanf("%d", &n);
    printf("enter array elements: \n");
    for(i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
}

void display(){
    printf("Array elements are:\n");
    for(i=0; i<n; i++){
        printf("%d \t", a[i]);
    }
}

void insert(){
    printf("\n enter the position of new element:");
    scanf("%d", &pos);
    printf("\n enter the element to be inserted:");
    scanf("%d", &elem);
    for(i=n-1; i>= pos; i--){
        a[i+1] = a[i];
    }
    a[pos] = elem; 
    printf("\n array elements updated.");
    n = n+1; 
}

void delete(){
    printf("\n enter the position of element to be deleted: ");
    scanf("%d",&pos);
    elem = a[pos];
    for(i=pos; i<n-1; i++){
        a[i] = a[i+1];
    }
    n = n-1;
    printf("\n element %d is deleted", elem);
}

void main(){
    int ch; 
    do{
        printf("\n\n --------MENU--------\n");
        printf("1.Create\n 2.Display\n 3.Insert\n 4.Delete\n 5.Exit\n");
        printf("------------------------");
        printf("\n Enter your choice:");
        scanf("%d", &ch);
        switch(ch){
            case 1: create();
                    break;

            case 2: display();
                    break;

            case 3: insert();
                    break;

            case 4: delete();
                    break;

            case 5: exit(0);
                    break;

            default: printf("\n invalied choice \n");
                    break;
        }
    }while(ch!=5);
}