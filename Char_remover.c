#include <stdio.h>
#include<string.h>
#include <stdlib.h>

int remove_char(char* input,int size,char chr){
    int itr2=0;
    for(int itr=0;itr<size;itr++){
        if(input[itr]!=chr){
            input[itr2++]=input[itr];
        }
    }
    input[itr2]='\0';
    printf("%s",input);
    return 0;
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
    char chr;
    printf("Enter char: ");
    scanf("%c",&chr);
    remove_char(input1,size1,chr);
    return 0;
}
