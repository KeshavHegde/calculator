#include<stdio.h>
#include<stdlib.h>
#include <string.h>

void generate_permutation(char *input, int left, int right, char ***result, int *count) {
    if (left==right) {
        (*count)++;
        *result=(char **)realloc(*result,(*count)*sizeof(char *));
        (*result)[(*count) - 1] = (char *)malloc((strlen(input) + 1)*sizeof(char));
        strcpy((*result)[(*count)-1],input);
    } else {
        for (int itr=left;itr<=right;itr++) {
            char temp=input[left];
            input[left]=input[itr];
            input[itr]=temp;
            generate_permutations(input,left+1,right,result,count);
            temp=input[left];
            input[left]=input[itr];
            input[itr]=temp;
        }
    }
}

void str_permutation(char *input,int size){
    char **result=NULL;
    int count=0;
    generate_permutation(input,0,size-1,&result,&count);
    printf("[");
    for(int i=0;i<count;i++){
        printf("\"%s\"",result[i]);
        if(i<count-1)
          printf(",");
    }
    printf("]");
    free(result);
    result=NULL;
}

int main(){
    char input[100];
    printf("Enter the string: ");
    fgets(input,sizeof(input),stdin);
    int size=strlen(input);
    if(size>0 && input[size-1]=='\n'){
        input[size-1]='\0';
        size--;
    }
    str_permutation(input,size);
    return 0;
}
