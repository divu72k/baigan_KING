#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
}

int main(){
    struct node *head=NULL;
    head=(struct node *)malloc(sizeof(struct node));
    insert_end(head,87);
}

void insert_end(struct node *head, data){
    struct node *ptr=NULL;
    ptr=head;
    struct node *temp;
    temp->data=data;
    temp->link=NULL;
    while(ptr->link!=NULL){
        ptr=ptr->link;
    }
    ptr->link=temp;
}