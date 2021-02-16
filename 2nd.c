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
int i, j, c, m, k, flag = 0; 

void stringmatch(){
    i = j = c = m = 0;  
    while(str[c] != '\0'){
        if(str[m] == pat[i]){
            i++;
            m++;
            if(pat[i]=='\0'){
                flag = 1; 
                for(k = 0; rep[k] != '\0'; k++, j++){
                    ans[j] = rep[k];
                }
                i = 0; 
                c = m;
            }
        }
        else{
            ans[j] = str[c];
            j++;
            c++;
            m = c;
            i = 0;
        }
    }
    ans[j] = '\0';
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