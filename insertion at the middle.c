#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
}*head,*body,*tail;
int main()
{
    head=(struct node*)malloc(sizeof(struct node));
   body=(struct node*)malloc(sizeof(struct node));
   tail=(struct node*)malloc(sizeof(struct node));
   head->data=10;
   tail->data=30;
   body->data=40;
   head->next=tail;
   tail->next=body;
   body->next=NULL;
   int i=1,pos;
    printf("Enter the position");
    scanf("%d",&pos);
    struct node *temp=head;
    while(i<pos)
    {
        temp->next=NULL;
        i++;
    }
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=20;
    newnode->next=temp->next;
    temp->next=newnode;
    while(i>pos)
      {
          while(temp->next!=NULL){
        temp=temp->next;
        printf("%d ",temp->data);
        i++;
      }
}
}

