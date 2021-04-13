/*
Design, Develop and Implement a Program in C for the following Stack Applications
a. Evaluation of Suffix expression with single digit operands and operators: +, -, *, /, %, ^
b. Solving Tower of Hanoi problem with n disks.
*/
/*
ALGORITHM: (suffix expression)
Step 1: Start.
Step 2: Read the postfix/suffix expression.
Step 3: Evaluate the postfix expression based on the precedence of the operator.
step 4: Stop.
*/

#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>

float stack[25];
int top = -1;

float evaluate(char [], float []);
void push(float);
float pop();


void main(){
    char suffix[50];
    float data[15], result;
    int i=0;
    printf("\n Enter suffix expression: ");
    scanf("%s", suffix);
    while(suffix[i] != '\0'){
        if(isalpha(suffix[i])){
            printf("\n Enter the value of %c: ", suffix[i]);
            scanf("%f", &data[i]);
        }
        i++;
    }
    result = evaluate(suffix, data);
    printf("\n The result of %s = %.2f", suffix, result);
}

float evaluate(char s[], float d[]){
    int i = 0;
    float op1, op2;
    char c;
    while(s[i] != '\0'){
        c = s[i];
        if(isalpha(s[i])){
            push(d[i]);
        }
        else{
            op2 = pop();
            op1 = pop();
            switch(c){
                case '+': push(op1 + op2);
                break;
                case '-': push(op1 - op2);
                break;
                case '*': push(op1 * op2);
                break;
                case '/': push(op1 / op2);
                break;
                case '^': push(pow(op1, op2));
                break;
            }
        }
        i++;
    }
    return(pop());
}

void push(float d){
    stack[++top] = d;
}

float pop(){
    return stack[top--];
}
