#include<stdio.h>
#include<string.h>

int is_num(char check){
    return check >='0' && check<='9';
}

int atoi(char *input,int size){
    int is_neg=0;
    int result=0;
    for(int itr=0;itr<size;itr++){
        if(input[itr]=='-' && itr==0){
          is_neg=1;
          itr++;
        }
        if(! is_num(input[itr])){
          result=0;
         break;
        }
        result=(result*10)+(input[itr]-'0');
    } 
    if(is_neg==1)
     return result*(-1);
    return result;
}

int main(){
    char input1[100];
    printf("enter the input: ");
    fgets(input1,sizeof(input1),stdin);
    int size1=strlen(input1);
    if (size1>0 && input1[size1-1]=='\n') {
        input1[size1-1]='\0'; 
        size1--;
    }
    int result=atoi(input1,size1);
    printf("%d",result);
    return 0;
}
