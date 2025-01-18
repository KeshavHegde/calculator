#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *head=NULL;

node* create_node(int input){
    node *temp=(node*)malloc(sizeof(node));
    temp->next=NULL;
    temp->data=input;
    return temp;
}

void insertAtBeginning(int value){
    node* temp=create_node(value);
    temp->next=head;
    head = temp;
}

void insertAtEnd(int value){
    node* temp=create_node(value);
    if(head==NULL){
        head=temp;
        return ;
    }
    node* cur=head;
    while(cur->next!=NULL){
        cur=cur->next;
    }
    cur->next=temp;
}

void insertAtPosition(int position, int value){
    node* temp=create_node(value);
    if (position == 1) {
        temp->next = head;
        head = temp;
        return ;
    }
    node* cur=head;
    int cur_pos=1;
    while(cur!=NULL && cur_pos < position - 1){
        cur=cur->next;
        cur_pos++; 
    }
    if(cur==NULL){
        printf("position out of range\n ");
        free(temp);
    }
    else{
        temp->next = cur->next;
        cur->next = temp;
    }
}

void display(){
    if(head==NULL)
       return ;
    node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void updateAtBeginning(){
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }int element;
    printf("New element: ");
    scanf("%d",&element);
    head->data=element;
}

void updateAtEnd(){
    int element;
    printf("New element: ");
    scanf("%d",&element);
    node* cur=head;
    while(cur->next!=NULL){
        cur=cur->next;
    }
    cur->data=element;
}

void  updateAtPosition(int position, int newValue){
    node* cur=head;
    int cur_pos=1;
    while(cur->next!=NULL && cur_pos!=position){
        cur=cur->next;
        cur_pos++;
    }
    if(cur==NULL){
        printf("position out of range\n");
        return;
    }
    else {
       cur->data=newValue;
    }
}

void deleteAtBeginning(){
    if(head==NULL){
        return;
    }
    node* temp=head;
    head=head->next;
    free(temp);
}

void deleteAtEnd(){
    if(head==NULL){
        printf("List is empty\n");
        return ;
    }
    if (head->next == NULL) {
        free(head);
        return ;
    }
    node* cur=head;
    while(cur->next->next!=NULL){
        cur=cur->next;
    }
    free(cur->next);
    cur->next=NULL;
}

void deleteAtPosition(int position){
    if(head==NULL){
        printf("List is empty\n");
        return ;
    }
     if (position==1) {
        node* temp=head;
        head=head->next; 
        free(temp);        
        return;       
    }
    node* cur=head;
    int cur_pos=1;
    node* temp=NULL;
    while(cur->next!=NULL && cur_pos<position-1){
        cur_pos++;
        cur=cur->next;
    }
    if(cur->next==NULL ){
        printf("position out of range node\n");
        return;
    }
    else{
        node* temp=cur->next;
        cur->next=temp->next;
        free(temp);
    }
}

int main(){
    int input;
    int op=1;
    int total_input;
    scanf("%d",&total_input);
    for(int itr=0;itr<total_input;itr++){
    while(op){
        scanf("%d",&op);
        int value,position;
        switch(op){
            case 2: scanf("%d",&value);
                    insertAtBeginning(value);
                    break;
            case 1: scanf("%d",&value);
                    insertAtEnd(value);
                    break;
            case 3: scanf("%d %d",&position,&value);
                    insertAtPosition(position, value);
                    break;
            case 4: display();
                    break;
            case 9: updateAtBeginning();
                    break;
            case 10: updateAtEnd();
                    break;
            case 5: scanf("%d %d",&position,&value);
                    updateAtPosition(position,value);
                    break;
            case 6: deleteAtBeginning();
                    break;
            case 7: deleteAtEnd();
                    break;
            case 8: scanf("%d",&position);
                    deleteAtPosition(position);
                    break;
            default: printf("Invalid operation\n");
                    break;
        }
    }
    }
    return 0;
}
