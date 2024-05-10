#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insertatmiddle(struct node**head,int pos,int data)
{
    int i=1;
    struct node*temp=*head;
    while (i<pos-1&&temp!=NULL)
    {
        temp=temp->next;
        i++;
    }
    if (temp == NULL)
    {
        return;
    }
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = temp->next;
    temp->next = newnode;
}

void print(struct node**head)
{
   struct node*prev=NULL;
   struct node*temp=*head;
   struct node*next=NULL;
   while(temp!=NULL)
   {
       next=temp->next;
       temp->next=prev;
       prev=temp;
       temp=next;
   }
   *head=prev;
   printf("\n");
}

void display(struct node*head)
{
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}

void count(struct node*head)
{
    int count =0;
    while(head!=0)
    {
        head=head->next;
        count++;
    }
    printf("\n");
    printf("NUMBER OF NODE PRESENT IN LIST = %d\n",count);
}

int main() {
    struct node*head = NULL;
    struct node*newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=50;
    newnode->next=head;
    head = newnode;
    struct node*newnode1=(struct node *)malloc(sizeof(struct node));
    newnode1->data=20;
    newnode1->next=NULL;
    newnode->next=newnode1;
    struct node*newnode2=(struct node *)malloc(sizeof(struct node));
    newnode2->data=10;
    newnode2->next=NULL;
    newnode1->next=newnode2;
    insertatmiddle(&head,2,40);
    insertatmiddle(&head,3,30);
    printf("ORIGINAL LIST:\n");
    display(head);

    print(&head);
    printf("REVERSED LIST:\n");
    display(head);

    count(head);
    return 0;
}
