#include <stdio.h>
#include<string.h>
#include <stdlib.h>

int longest_word(char* input,int size){
    char *result=NULL;
    int itr=0,itr2=0;
    int max_len=0;
    int word_counter=0,f_len=0;
    while(itr2<=size){
        if(input[itr2]==' ' || input[itr2]=='\0'){
            word_counter++;
            int len =itr2-itr;
            if(word_counter==1){
                f_len=len;
                max_len=len;
                result=(char *)realloc(result,(f_len+1)*sizeof(char));
                int i=0;
                while(i<max_len){
                    result[i]=input[itr+i];
                    i++;
                }result[max_len]='\0';
            }
            else if(len>=max_len && f_len<len){
                max_len=len;
                result=(char *)realloc(result,(max_len+1)*sizeof(char));
                int i=0;
                while(i<max_len){
                    result[i]=input[itr+i];
                    i++;
                }result[max_len]='\0';
            }
            itr2++;
            itr=itr2;
        }
        else{
          itr2++;
        }
    }
    printf("%s",result);
    free(result);
    return 0;
}

int main() {
    char input1[100];
    printf("enter the sentence: ");
    fgets(input1,sizeof(input1),stdin);
    int size1=strlen(input1);
    if(size1>0 && input1[size1-1]=='\n'){
        input1[size1-1]='\0';
        size1--;
    }
    longest_word(input1,size1);
    return 0;
}
