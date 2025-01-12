#include <stdio.h>
#include<string.h>
#include <stdlib.h>

int check_palin(char *input,int right,int left){
    while(left<=right){
        if(input[left]!=input[right])
          return 0;
         left++;
         right--;
    }
    return 1;
}

char* longest_palin(char* input,int size){
    char *result=NULL;
    int max_len=0;
    int dub=1;
    for(int left=0;left<size ;left++){
        for(int right=size-1;right>=left;right--){
        if(input[left]==input[right]){
            if(check_palin(input,right,left)){
                if((right-left+1)>max_len){
                    max_len=(right-left+1);
                    result=(char *)realloc(result,(max_len+1)*sizeof(char));
                    strncpy(result, input + left, max_len);  
                    result[max_len]='\0';
                }
                else if((right-left+1)==max_len){
                    dub++;
                    result=(char *)realloc(result,(max_len+2)*dub*sizeof(char));
                    strcat(result," ");
                    strncat(result, input + left, max_len);  
                }
            }
          }
        }
    }   
    return result;
}

int main() {
    char input1[100];
    printf("Enter the string: ");
    fgets(input1,sizeof(input1),stdin);
    int size1=strlen(input1);
    if(size1>0 && input1[size1-1]=='\n'){
        input1[size1-1]='\0';
        size1--;
    }
    char *result=longest_palin(input1,size1);
    printf("%s",result);
    free(result);
    return 0;
}
