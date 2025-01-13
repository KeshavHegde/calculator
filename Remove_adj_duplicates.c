#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void rem_dub(char *input,int size){
    int rot=1;
    while(rot){
        rot=0;
        for(int itr=0;itr<size;itr++){  
            if(input[itr]==input[itr+1]){
                for(int move=itr;move<size;move++)
                    input[move]=input[move+2];
                size-=2;
            }
            for(int itr2=0;itr2<size;itr2++)
                if(input[itr2]==input[itr2+1])
                    rot=1;
        }
    }
    printf("\"%s\"\n",input);
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
    rem_dub(input,size);
    return 0;
}
