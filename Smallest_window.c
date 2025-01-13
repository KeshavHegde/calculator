#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void window_finder(char *input,int size,char *pattern,int sizep){
    char *res=NULL;
    int min_len=size+1;
    for(int itr=0;itr<size;itr++){
        int *track=(int *)calloc(sizep,sizeof(int));
        int check=0;
        for(int itr2=0;itr2<sizep;itr2++){
            if(input[itr]==pattern[itr2] ){
                track[itr2]=1;
                check++;
                for(int itr3=itr+1;itr3<size;itr3++){
                    for(int itr4=0;itr4<sizep;itr4++){
                        if(input[itr3]==pattern[itr4] &&  track[itr4]==0){
                            track[itr4]=1;
                            check++;
                        }
                        if(check==sizep && (itr3-itr+1)<min_len){
                            min_len=(itr3-itr+1);
                            res=(char *)realloc(res,(min_len+1)*sizeof(char));
                            strncpy(res,input+itr,min_len);
                            res[min_len]='\0';
                        }
                      
                    }
                }
            }
        }
    }
    printf("%s",res);
    free(res);
}
        
int main(){
    char input[100],pattern[100];
    printf("Enter the string: ");
    fgets(input,sizeof(input),stdin);
    int size=strlen(input);
    if(size>0 && input[size-1]=='\n'){
        input[size-1]='\0';
        size--;
    }
     printf("Enter the pattern: ");
    fgets(pattern,sizeof(pattern),stdin);
    int sizep=strlen(pattern);
    if(sizep>0 && pattern[sizep-1]=='\n'){
        pattern[sizep-1]='\0';
        sizep--;
    }
    window_finder(input,size,pattern,sizep);
    return 0;
}
/*
Problem Statement: 
Find the smallest substring in a given string that contains all the characters of another string. 
Sample Input and Output: 
1. Input: 
str = "ADOBECODEBANC", pat = "ABC" 
Output: "BANC" 
Explanation: "BANC" is the smallest substring in "ADOBECODEBANC" that contains all 
the characters of "ABC". */
