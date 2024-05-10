#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node*link;
}*newnode,*head,*temp,*tail;
//insertion at the beginning
int main()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=5;
    newnode->link=head;
    head=newnode;
    printf("%d",newnode->data);
    return 0;
    }

//insertion at the end
/*void display(struct node *nodes){
    temp=(struct node*)malloc(sizeof(struct node));
    temp->link=head;
    while(temp->link!=NULL){
        temp=temp->link;
        printf("%d ",temp->data);
    }
}
int main()
{
    head=(struct node*)malloc(sizeof(struct node));
    newnode=(struct node*)malloc(sizeof(struct node));
    tail=(struct node*)malloc(sizeof(struct node));
    temp=(struct node*)malloc(sizeof(struct node));
    head->data=10;
    tail->data=20;
    newnode->data=30;
    head->link=tail;
    tail->link=NULL;
    newnode->link=NULL;
    temp=head;
    while(temp->link!=NULL){
        temp=temp->link;
    }
    temp->link=newnode;
    tail=newnode;
    display(head);
    return 0;
}*/
