/*
Design, Develop and Implement a menu driven program in C for the following operations on
STACK of integers (Array implementation of stack with maximum size MAX)
a. Push an element on to stack
b. Pop an element from stack.
c. Demonstrate how stack can be used to check palindrome.
d. Demonstrate Overflow and Underflow situations on stack.
e. Display the status of stack.
f. Exit.
*/

/*
ALGORITHM:
Step 1: Start.
Step 2: initialize stack size MAX and top of the stack -1.
Step 3: Push integer element on to stack and display the contents of the stack.
        if stack is full give a message as 'stack is overflow'.
Step 4: Pop element form stack along with display the stack contents.
        if stack id empty give a message as 'stack us underflow'.
step 5: check wheather the stack contents are palindrome or not.
step 6: Stop.
*/      

#include<stdio.h>
#include<stdlib.h>

#define MAX 20

int stack[MAX], item;
int ch, top = -1, count = 0, status = 0;

void push(){
    printf("\n enter a element to be pushed: ");
    scanf("%d", &item);
    if(top == (MAX - 1)){
        printf("\n overflow...");
    }
    else{
        stack[++top] = item;
        status++;
    }
}   

int pop(){
    int ret;
    if(top == -1){
        printf("\n underflow...");
    }
    else{
        ret = stack[top--];
        status--;       
        printf("\n %d is popped ", ret);
    }
    return ret;
}

void palindrome(){
    int i, temp;
    temp = status;
    for(i = 0; i<temp; i++){
        if(stack[i] == pop(stack))
        count++;
    }
    if(temp == count){
        printf("\n stack contents are palindrome");
    }
    else{
        printf("\n stack contents are not palindrome");
    }
}

void display(){
    int i; 
    printf("\n the stack contents are: ");
    if(top == -1){
        printf("stack is empty: ");
    }
    else{
        for(i = top; i>= 0; i--){
            printf("\n------\n| %d |", stack[i]);
        }
        printf("\n");
    }
}

void main(){
    do{
        printf("\n ---- MAIN MENU ---- \n");
        printf("\n 1. PUSH \n 2. POP \n 3. PALINDROME CHECKER \n 4. exit ");
        printf("\n enter your choice: ");
        scanf("%d", &ch);

        switch(ch){
            case 1:
                    push();
                    display();
                    break;
            
            case 2: item = pop();
                    display();
                    break;

            case 3: palindrome();
                    break;

            case 4: exit(0);
                    break;
            
            default: printf("\n end of execution: ");
        }
    }while(ch != 4);
}