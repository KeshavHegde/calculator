#include<stdio.h>
#include<string.h>
#include <stdlib.h>

void dublicate_remover(char *input,int size,char *result){
     int res_size=0;
    for(int itr=0;itr<size;itr++){
        if(input[itr]==' ')
           continue;
        char temp=input[itr];
        int present=0;
        for(int itr2=0;itr2<res_size;itr2++){
            if(result[itr2]==temp)
             present=1;
        }
        if(present==0){
            result=(char *)realloc(result,(res_size+1)*sizeof(char));
            result[res_size]=temp;
            res_size++;
        }
    }
    result[res_size]='\0';
    printf("%s",result);
}

int main(){
    char input[100];
    fgets(input,sizeof(input),stdin);
    int size=strlen(input);
    if(size>0 && input[size-1]=='\n'){
    input[size-1]='\0';
    size--;
    }
    char *result=NULL;
    dublicate_remover(input,size,result);
    free(result);
    return 0;
}
