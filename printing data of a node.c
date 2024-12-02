#include<sdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
}

int main(){
    struct node *head=NULL;
    head=(struct node *)malloc(sizeof(struct node));
    print_data(head);
}

void count_nodes(struct node *head){
    int count=0;
    if(head==NULL){
        printf("linkedlist is empty");
    }
    struct node *ptr=NULL;
    ptr=head;
    while(ptr!=NULL){
        print("%d",ptr->data);
        ptr=ptr->link;
    }