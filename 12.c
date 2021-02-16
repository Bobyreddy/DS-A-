/*
Given a File of N employee records with a set K of Keys(4-digit) which uniquely
determine the records in file F. Assume that file F is maintained in memory by a Hash
Table(HT) of m memory locations with L as the set of memory addresses (2-digit) of
locations in HT. Let the keys in K and addresses in L are Integers. Design and develop
a Program in C that uses Hash function H: K →L as H(K)=K mod m (remainder
method), and implement hashing technique to map a given key K to the address space
L. Resolve the collision (if any) using linear probing
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int tablesize = 0, toEle = 0;

typedef struct{
    int salary, key;
    char name[100];
    int marker;
}node;

node *hashTable = NULL;

void insertINHash(int, char * , int );
void deleteFromHash(int );
void searchElement(int);
void display();
int checkduplicate(int );

void main(){
    int key, salary, ch;
    char name[100];
    printf("\n enter the no of elements: ");
    scanf(" %d", &tablesize);
    hashTable = (node*)calloc(tablesize, sizeof(node));
    while(1){
        printf("\n 1. Insertion \t 2. Deletion \n 3. Searching \t 4. Display \n 5. Exit \t \n Enter Your choice: ");
        scanf(" %d", &ch);
        switch(ch){
            case 1: if(tablesize == toEle){
                        printf("\n Hash table full !!");
                        break;
                    }
                    printf("\n Enter the key values between 0 & 9999: ");
                    scanf(" %d", &key);
                    if(key > 9999){
                        printf(" Key Value Should Be < 10000 \n ");
                        break;
                    }
                    if(checkduplicate(key)){ printf("\n Key already exists "); break;}
                    else{
                        getchar();
                        printf("\n Name: ");
                        fgets(name, 100, stdin);
                        name[strlen(name)-1] = '\0';
                        printf("\n Salary ");
                        scanf(" %d", &salary);
                        insertINHash(key, name, salary);
                        break;
                    }
            
            case 2: printf("\n Enter the key value: ");
                    scanf(" %d", &key);
                    deleteFromHash(key);
            break;

            case 3: printf("\n Enter the key value: ");
                    scanf(" %d", &key);
                    searchElement(key);
            break;

            case 4: display();
            break;

            case 5: exit(0);

            default: printf("\n invalid choice !!!");
            break;
        }
    }
}

void insertINHash(int key, char *name, int age){
    int hashIndex = key % tablesize;
    // if(tablesize == toEle){
    //     printf("\n Hash table full !!");
    //     return;
    // }
    while(hashTable[hashIndex].marker == 1){ hashIndex = (hashIndex + 1) % tablesize; }
    hashTable[hashIndex].key = key;
    hashTable[hashIndex].salary = age;
    strcpy(hashTable[hashIndex].name, name);
    hashTable[hashIndex].marker = 1;
    toEle++;
    return;
}

void deleteFromHash(int key){
    int hashIndex = key %tablesize, count = 0, flag = 0;
    if(toEle == 0){
        printf("\n hash table is empty !!");
        return;
    }
    while(hashTable[hashIndex].marker != 0 && count <= tablesize){
        if(hashTable[hashIndex].key == key){
            hashTable[hashIndex].marker = -1;
            hashTable[hashIndex].salary = 0;
            strcpy(hashTable[hashIndex].name, "\0");
            toEle--;
            flag = 1;
            break;
        }
        hashIndex = (hashIndex + 1) % tablesize;
        count++;
    }
    if(flag) printf("\n Given Data Deleted From Hash Table");
    else printf("\n Given data is not available in hash table ");
        return;
}

void searchElement(int key){
    int hashIndex = key % tablesize, flag = 0, count = 0;
    if(toEle == 0){
        printf("\n Hash table is Empty!!");
        return;
    }
    while(hashTable[hashIndex].marker != 0 && count <= tablesize){
        if(hashTable[hashIndex].key == key){
            printf("\n Employee ID: %d ", hashTable[hashIndex].key);
            printf("\n Name: %s ", hashTable[hashIndex].salary );
            flag = 1;
            break;
        }
        count++;
        hashIndex = (hashIndex + 1) %tablesize;
    }
    if( !flag ){
        printf("\n Given Data is not present in hash table ");
        return;
    }
}


void display(){
    int i;
    if(toEle == 0){
        printf("\n Hash Table is empty!! ");
        return;
    }
    printf("\n EmployeeID \t Name \t Salary \t index \n ");
    printf(" -----------------------------------------\n");
    for(i = 0; i<tablesize; i++){
        if(hashTable[i].marker == 1){
            printf(" %d \t %-15s \t %-2d \t %-2d \n", hashTable[i].key, hashTable[i].name, hashTable[i].salary, i);
            // printf("%-15s");
            // printf(" %-2d \t");
            // printf("%d\n", i);
        }
    }
    printf("\n");
    return;
}

int checkduplicate(int key){
    int hashIndex = key % tablesize, flag = 0, count;
    while(hashTable[hashIndex].marker != 0 && count <= tablesize){
        if(hashTable[hashIndex].key == key){
            flag = 1;
            return 1;
        }
        count++;
        hashIndex = (hashIndex + 1) % tablesize;
    }
    if(!flag) return 0;
}