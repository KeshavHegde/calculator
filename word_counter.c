#include<stdio.h>
#include<string.h>

int is_char(char check){
    return check>=65 && check<=90 || check>=97 && check<=122;
    //return check>='A' && check<='Z' || check>='a' && check<='z';
}

int main(){
    char input[100];
    fgets(input,sizeof(input),stdin);
    int count=0;
    for(int itr=0;itr<strlen(input);itr++){
       if(input[itr]==' ' && is_char(input[itr+1]))
       count++;
    }
    count++;
    printf("%d",count);
    return 0;
}
