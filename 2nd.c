/* 
__EXPERIMENT - 02__

Design, Develop and Implement a program in C for the following operations on Strings

a. Read a Main String (STR), a Pattern String (PAT) and a Replace String (REP).
b. Perform Pattern Matching Operation: Find and Replace all occurrences of PAT in STR with
REP if PAT exists in STR. Repost suitable messages in case PAT does not exist in STR


ALGORITHM:
Step 1: start
Step 2: read main string STR, patter string PAT and replace string REP.
Step 3: Search / find the pattern string PAT in the main string
Step 4: if PAT is found then replace all occurrences of PAT in main string STR with REP string
Step 5: if PAT is not found give a suitable error message.
Step 6: Stop
*/

#include<stdio.h>

char str[100], pat[50], rep[50], ans[100];
int i, j, k, l, m, flag = 0; 

void stringmatch(){
    i = j = k = l = m = 0;  
    while(str[i] != '\0'){
        if(str[j] == pat[k]){
            j++;
            k++;
            if(pat[k]=='\0'){
                flag = 1; 
                for(l = 0; rep[l] != '\0'; l++, m++){
                    ans[m] = rep[l];
                }
                k = 0; 
                i = j;
            }
        }
        else{
            ans[m] = str[i];
            m++;
            i++;
            j = i;
            k = 0;
        }
    }
    ans[m] = '\0';
}

void main(){
    printf("\n enter the string: ");
    gets(str);
    printf("\n enter pattren string: ");
    gets(pat);
    printf("\n enter a replace sting: ");
    gets(rep);
    stringmatch();
    if(flag == 1){
        printf("\n the resultant string is \n %s", ans);
    }
    else{
        printf("\n pattren string not found\n");
    }
}       
