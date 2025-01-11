#include<stdio.h>
#include<string.h>

int rotation_check(char *input1,char *input2,int size1,int size2){
    int flag=0;
    for(int itr2=0;itr2<size2;itr2++){
       if(input1[0]==input2[itr2]){
        int itr=0;
        while(input1[itr]==input2[itr2]){
            itr++;
            itr2=(itr2+1)%(size2-1);
            if(itr==size1-1){
             flag=1;
             break;
            }
        }
     }  
    }
    return flag;
}

int main(){
    char input1[100],input2[100];
    fgets(input1,sizeof(input1),stdin);
    fgets(input2,sizeof(input2),stdin);
    int size1=strlen(input1);
    int size2=strlen(input2);
    if(size1 >0 && input1[size1-1]=='\n'){
      input1[size1-1]='\0';
    }
    if(size2 >0 && input2[size2-1]=='\n'){
      input2[size2-1]='\0';
    }
    int flag=rotation_check(input1,input2,size1,size2);
    if(flag==1)
      printf("TRUE"); 
    else 
      printf("FALSE");
    return 0;
}
