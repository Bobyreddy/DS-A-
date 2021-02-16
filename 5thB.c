/*
Design, Develop and Implement a Program in C for the following Stack Applications
a. Evaluation of Suffix expression with single digit operands and operators: +, -, *, /, %, ^
b. Solving Tower of Hanoi problem with n disks.
*/
/*
ALGORITHM: (tower of hanio)
Step 1: Start.
Step 2: Read N number of discs.
Step 3: Move all the discs from source to destinatio by using temp rod.
Step 4: Stop.
*/

#include<stdio.h>

void towers(int, char, char, char);

void main(){
    int n;
    printf("\n Enter the number of discs: ");
    scanf("%d", &n);
    printf("\n The sequence invloved are: \n");
    towers(n, 'A', 'C', 'B');
}

void towers(int n, char from, char to, char aux){
    if(n == 1){
        printf("\n Move disk 1 from %c to %c \n", from, to);
        return;
    }
    towers(n-1, from, aux, to);
    printf("\n Move disk %d From %c to %c \n", n, from, to);
    towers(n-1, aux, to, from);
}