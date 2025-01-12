#include <stdio.h>
#include<string.h>
#include <stdlib.h>

int check_anag(char* input1,char* input2,int size1,int size2){
    if(size1!=size2)
      return 0;
    int *temp=(int *)calloc(size1,sizeof(int));
    for(int itr=0;itr<size1;itr++){
        int temp_flag=0;
        for(int itr2=0;itr2<size1;itr2++){
            if(input1[itr]==input2[itr2] && temp[itr2]==0){
                temp_flag=1;
                temp[itr2]=1;
                break;
            }
        }
       if (temp_flag==0){
            free(temp);
            return 0;
        }
    }
    free(temp);
    return 1;
}

int main() {
    char input1[100],input2[100];
    printf("Enter first string: ");
    fgets(input1,sizeof(input1),stdin);
    int size1=strlen(input1);
    if(size1>0 && input1[size1-1]=='\n'){
        input1[size1-1]='\0';
        size1--;
    }
    printf("Enter second string: ");
    fgets(input2,sizeof(input2),stdin);
    int size2=strlen(input2);
    if(size2>0 && input2[size2-1]=='\n'){
        input2[size2-1]='\0';
        size2--;
    }
    int flag=check_anag(input1,input2,size1,size2);
    if(flag)
       printf("TRUE");
    else
       printf("FALSE");
    return 0;
}
