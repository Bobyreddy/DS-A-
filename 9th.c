/*
Design, Develop and Implement a Program in C for the following operations on
Singly Circular Linked List (SCLL) with header nodes
a. Represent and Evaluate a Polynomial P(x,y,z) = 6x2y2z-4yz5+3x3yz+2xy5z-2xyz3
b. Find the sum of two polynomials POLY1(x,y,z) and POLY2(x,y,z) and store the
result in POLYSUM(x,y,z)
Support the program with appropriate functions for each of the above operations
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX 100

// void attach(float, int, int, int);
// int compare(int, int);
// int getmaxexp(int);
// void addpolynomial(int, int, int, int, int, int);
// void printpolynomial(polynomial , int, int);
// void readpolynomial(polynomial , int, int);
// void calculatepolynomial();
// void evaluatepolynomial();

typedef struct{
    float coef;
    int x_exp;
    int y_exp;
    int z_exp;
}polynomial;

polynomial terms[MAX];

int totalterms = 0;
int getmaxexp(int t);

void attach(float coeff, int expx, int expy, int expz){
    if(totalterms >= MAX){
        printf("\ntoo many terms: ..\n");
        exit(-1);
    }
    terms[totalterms].coef = coeff;
    terms[totalterms].x_exp = expx;
    terms[totalterms].y_exp = expy;
    terms[totalterms].z_exp = expz;
    totalterms++;
}

int compare(int startA, int startB){
    if((terms[startA].x_exp == terms[startB].x_exp) && (terms[startA].y_exp == terms[startB].y_exp) && (terms[startA].z_exp == terms[startB].z_exp)){
        return 0;
    }
    int MaxexpA = getmaxexp(startA);
    int MaxexpB = getmaxexp(startB);
    if(MaxexpA > MaxexpB){
        return 1;
    }
    else{
        return -1;
    }
}

int getmaxexp(int t){
    int max = 0;
    if(max < terms[t].x_exp){
        max = terms[t].x_exp;
    }
    if(max < terms[t].y_exp){
        max = terms[t].y_exp;
    }
    if(max < terms[t].z_exp){
        max = terms[t].z_exp;
    }
    return max;
}

void addpolynomial(int startA, int finishA, int startB, int finishB, int *startD, int *finishD){
    float coeffecient;
    *startD = totalterms;
    while(startA <= finishA && startB <= finishB){
        switch(compare(startA, startB)){
            case -1: attach(terms[startB].coef, terms[startB].x_exp, terms[startB].y_exp, terms[startB].z_exp);
                     startB++;
            break;

            case 0: coeffecient = terms[startA].coef + terms[startB].coef;
                    if(coeffecient){
                        attach(coeffecient, terms[startA].x_exp, terms[startA].y_exp, terms[startA].z_exp);
                    }
                    startA++;
                    startB++;
                    break;

            case 1: attach(terms[startA].coef, terms[startA].x_exp, terms[startA].y_exp, terms[startA].z_exp);
                    startA++;
        }
    }
    for(; startA <= finishA; startA++){
        attach(terms[startA].coef, terms[startA].x_exp, terms[startA].y_exp, terms[startA].z_exp);
    }
    for(; startB <= finishB; startB++){
        attach(terms[startB].coef, terms[startB].x_exp, terms[startB].y_exp, terms[startB].z_exp);
    }
    *finishD = totalterms - 1;
} 


void printpolynomial(polynomial terms[], int start, int finish){
    int i, temp = start;
    printf("\n");
    for(i=start; i<=finish; i++){
        printf("%.2f x^%d y^%d z^%d", terms[i].coef, terms[i].x_exp, terms[i].y_exp, terms[i].z_exp);
        if(temp++ < finish){
            printf("+");
        }
    }
}


void readpolynomial(polynomial terms[], int start, int finish){
    int i, Xexpon, Yexpon, zexpon;
    float coef;
    while(finish >= MAX){
        printf("\ntoo many terms...");
        printf("\n Number of terms: %d", finish);
    }
    for(i = start; i <= finish; i++){
        printf("\n Coefficient: ");
        scanf(" %f", &coef);
        printf("\n X Exponent: ");
        scanf(" %d", &Xexpon);
        printf("\n Y Exponent: ");
        scanf(" %d", &Yexpon);
        printf("\n Z Exponent: ");
        scanf(" %d", &zexpon);
        terms[i].coef = coef;
        terms[i].x_exp = Xexpon;
        terms[i].y_exp = Yexpon;
        terms[i].z_exp = zexpon;
    }
}

void calculatepolynomial(){
    int tPA = 0, tPB = 0;
    int startD, finishD;

    printf("\n Enter the number of terms in first polynomial: ");
    scanf(" %d", &tPA);
    readpolynomial(terms, 0, tPA-1);
    printf("\n polynomial A with %d terms is: \n", tPA);
    printpolynomial(terms, 0, tPA-1);

    printf("\n Enter the number of terms in second polynomial: ");
    scanf(" %d", &tPB);
    readpolynomial(terms, tPA, tPA+tPB-1);
    printf("\n polynomial B with %d terms is: \n", tPB);
    printpolynomial(terms, tPA, tPA+tPB-1);

    totalterms = tPA + tPB;
    addpolynomial(0, tPA - 1, tPA, tPA + tPB -1 , &startD, &finishD);
    printf("\n output polynomial after addition is: \n");
    printpolynomial(terms, startD, finishD);
    printf("\n");
}


void evaluatepolynomial(){
    int i, x, y, z;
    
    terms[1].coef = 6;
    terms[1].x_exp = 2;
    terms[1].y_exp = 2;
    terms[1].z_exp = 1;

    terms[2].coef = -4;
    terms[2].x_exp = 0;
    terms[2].y_exp = 1;
    terms[2].z_exp = 5;

    terms[3].coef = 3;
    terms[3].x_exp = 3;
    terms[3].y_exp = 1;
    terms[3].z_exp = 1;

    terms[4].coef = 2;
    terms[4].x_exp = 1;
    terms[4].y_exp = 5;
    terms[4].z_exp = 1;

    terms[5].coef = -2;
    terms[5].x_exp = 1;
    terms[5].y_exp = 1;
    terms[5].z_exp = 3;

    printf("enter the value of x \n");
    scanf("%d",&x);
    printf("enter the value of y \n");
    scanf("%d",&y);
    printf("enter the value of z \n");
    scanf("%d",&z);

    float answer = 0.0, temp;
    for(i=1; i<6; i++){
        temp = terms[i].coef * pow(x, terms[i].x_exp) * pow(y, terms[i].y_exp) * pow(z, terms[i].z_exp);
        answer = answer + temp;
    }
    printf("polynomial Evaluated to %f \n", answer);
}

void main(){
    int choice;
    while(1){
        printf("\n Dlist OPERATIONS\n");
        printf("\n 1. evaluate 6 x^2 y^2 z-4 y z^5 + 3 x^3 y z + 2 X y^5 z - 2 x y z^3");
        printf("\n 2. calculate sum of two polynomials ");
        printf("\n 3. exit\n");
        printf("Enter choice: \n");
        scanf(" %d", &choice);
        switch(choice){
            case 1: evaluatepolynomial();
            break;

            case 2: calculatepolynomial();
            break;

            case 3: exit(0);
        }
    }
}

