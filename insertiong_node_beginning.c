#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

int main(){
    struct node *head;
    head=(struct node *)malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;
    struct node *ptr=malloc(sizeof(struct node));
    ptr->data=90;
    ptr->link=NULL;
    head->link=ptr;

    int data=5;

    struct node *insert_beg(struct node *head,int data);
    insert_beg(head,data);
    ptr=head;
    while(ptr!=NULL){
        printf("%d \n",ptr->data);
        ptr=ptr->link;
    }
    return 0;
}

struct node *insert_beg(struct node *head,int data){
    struct node *ptr =malloc(sizeof(struct node));
    ptr->data=data;
    ptr->link=NULL;
    ptr->link=head;
    head=ptr;
    return head;
}