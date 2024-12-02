#include<sdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
}

int main(){
    count_nodes();
}

void count_nodes(struct node *head){
    int count=0;
    if(head==NULL){
        printf("linkedlist is empty");
    }
    struct node *ptr=NULL;
    ptr=head;
    while(ptr!=NULL){
        count++;
        ptr=ptr->link;
    }
    printf("%d",count);
}