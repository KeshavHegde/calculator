#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void check_rotate(char *input,char *input2,int size){
    strcat(input2,input2);
    if(strstr(input2,input)!=NULL)
        printf("true");
    else
        printf("false");
}

int main(){
    char input[100],input2[200];
    printf("Enter the string: ");
    scanf("%[^,],%s",input,input2);
    int size=strlen(input);
    int size2=strlen(input2);
    if(size==size2)
        check_rotate(input,input2,size);
    else
         printf("false");
    return 0;
}
