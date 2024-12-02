#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

int main(){
    struct node *head=NULL;
    head=(struct node *)malloc(sizeof(struct node));
    head->data=69;
    head->link=NULL;
    struct node *current=NULL;
    current=(struct node *)malloc(sizeof(struct node));
    current->data=45;
    current->link=NULL;
    head->link=current;

    current=(struct node *)malloc(sizeof(struct node));
    current->data=7;
    current->link=NULL;
    head->link->link=current;
    
    printf("%d %d %d %d",head->data,head->link,current->data,current->link);
    return 0;
}