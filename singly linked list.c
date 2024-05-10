#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
}*head;

void insertatbegin(struct node **head,int data)
{
   struct node*newnode=(struct node*)malloc(sizeof(struct node));
   newnode->data=data;
   newnode->next=head;
   *head=newnode;
}

void insertatend(struct node**head,int data)
{
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    if (*head == NULL) {
        *head = newnode;
        return;
    }
    struct node*temp=*head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
     temp->next=newnode;
}

void insertatmiddle(struct node**head,int data)
{
    int i=0,pos;
    printf("ENTER THE POSITION TO INSERT AT THE MIDDLE:");
    scanf("%d",&pos);
    struct node*temp=*head;
    while(i<pos)
    {
        temp=temp->next;
        i++;
    }
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=temp->next;
    temp->next=newnode;
}

void deletionatbegin(struct node**head,int data)
{
    struct node*temp=*head;
   if(temp==NULL)
   {
       printf("deletion can't performed");
   }
   else
    temp=temp->next;
   free(temp);
}

void deletionatend(struct node**head,int data)
{
    struct node*temp=*head,*prev;
    while(temp!=NULL)
    {
        temp=temp->next;
    }
    prev->next=NULL;
    free(temp);
}

void deletionatmiddle(struct node**head,int data)
{
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    int i=1,pos;
    printf("ENTER THE POSITION TO DELETE AT THE MIDDLE:");
    scanf("%d",&pos);
    struct node*temp=*head;
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    temp->next=newnode->next;
    free(newnode);
}

void display(struct node*head)
{
    while (head!= NULL)
    {
      printf("%d ",head->data);
      head=head->next;
    }
  printf ("\n");
}

int main()
{
    struct node*head=NULL;
    insertatbegin(&head,10);
    insertatbegin(&head,20);
    insertatbegin(&head,30);
    display(head);
    insertatend(&head,40);
    insertatend(&head,50);
    insertatend(&head,60);
    display(head);
    insertatmiddle(&head,80);
    display(head);
    deletionatbegin(&head,10);
    display(head);
    deletionatend(&head,60);
    display(head);
    deletionatmiddle(&head,50);
    display(head);
}
