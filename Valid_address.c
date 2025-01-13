#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int is_num(char check){
    return check >='0' && check<='9';
}

int atoil(char *input,int left,int right){
    int result=0;
    for(int itr=left;itr<right;itr++){
       if(! is_num(input[itr])){
        return -1;
       }
       result=(result*10)+(input[itr]-'0');
    }
    return result;
}

void validity_checker(char *input,int size){
    int left=0,addres=0;
    for(int itr=0;itr<size;itr++){
        if(input[itr]=='.' && input[itr+1]=='.'){
            printf("invalid");
              return ;
        }
        if((itr==0 || input[itr]=='.') && input[itr+1]=='0'&& is_num(input[itr+2])){
            printf("invalid");
              return ;
        }  
        if(input[itr]=='.' || itr==size-1){
            int num=atoil(input,left,itr);
            if(num<0 || num>255){
              printf("invalid");
              return ;
            }
            addres++;
            left = itr + 1;
        }
    }
    if(addres==4)
         printf("valid");
    else
         printf("invalid");
}
        
int main(){
    char input[16];
    printf("Enter the string: ");
    fgets(input,sizeof(input),stdin);
    int size=strlen(input);
    if(size>0 && input[size-1]=='\n'){
        input[size-1]='\0';
        size--;
    }
    validity_checker(input,size);
    return 0;
}
