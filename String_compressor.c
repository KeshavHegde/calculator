#include <stdio.h>
#include<string.h>
#include <stdlib.h>

void string_compresser(char* input,int size){
    int count=0,index=0;
    char *result=NULL;
    for(int itr=0;itr<size;itr++){
        if(input[itr]==input[itr+1]){
            count++;
        }else{
            count++;
            result=(char*)realloc(result,(index+2)*sizeof(char));
            result[index]=input[itr];
            index++;
            result[index]=count+'0';
            count=0;
            index++;
        }
    }result[index]='\0';
    if(size >= index)
        input=result;
    printf("%s",input);
    free(result);
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
    string_compresser(input1,size1);
    return 0;
}
