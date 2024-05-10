#include<stdio.h>
#include<stdlib.h>
struct node
{
    char data;
    struct node*next;
    struct node*prev;
};

void insertatbegin(struct node**head,char data)
{
   struct node*newnode=(struct node*)malloc(sizeof(struct node));
   newnode->data=data;
   newnode->next=*head;
   newnode->prev=NULL;
   if (*head != NULL)
    {
        (*head)->prev = newnode;
    }

    *head = newnode;
}

void insertatend(struct node**head,char data)
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
    newnode->prev=temp;
}

void insertatmiddle(struct node**head,int pos,char data)
{
    int i=1;
   struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
    struct node*temp=*head;
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    newnode->next=temp->next;
    (temp->next)->prev=newnode;
    temp->next=newnode;
    newnode->prev=temp;
}

void deleteatbegin(struct node**head)
{
    if(*head==NULL)
    {
        return;
    }
    struct node*temp=*head;
    *head=(*head)->next;
    (*head)->prev=NULL;
    free(temp);
}
void deleteatend(struct node**head)
{
    if (*head == NULL)
    {
        return;
    }

    struct node *temp = *head;
    while (temp->next != NULL)
        {
            temp = temp->next;
        }
    struct node*del=temp->prev;
    del->next=NULL;
    free(temp);
}

void deleteatmiddle(struct node**head,int pos)
{
  int i=0;
  struct node* temp = *head;
  if(*head == NULL)
  {
    printf("List is empty\n");
  }
  else
  {
    while(i<pos-1)
      {
        temp=temp->next;
        i++;
      }
    (temp->prev)->next=temp->next;
    (temp->next)->prev=temp->prev;
    free(temp);

  }

}

void display(struct node*head)
{
    printf("FORWARD DIRECTION\n");
    while(head!=NULL)
    {
        printf("%c ",head->data);
        head=head->next;
    }
    printf("\n");
}

void print(struct node*head)
{
    struct node*end=head;
    while (end->next != NULL)
    {
        end = end->next;
    }
    printf("REVERSE DIRECTION\n");
    while(end!=NULL)
    {
        printf("%c ",end->data);
        end=end->prev;
    }
    printf("\n");
}

int main()
{
  struct node*head=NULL;
  int pos;
  insertatbegin(&head,'b');
  insertatbegin(&head,'a');
  printf("\t\tinsertatbegin:\n");
  display(head);
  print(head);

  insertatend(&head,'d');
  insertatend(&head,'e');
  printf("\t\n\tinsertatend:\n");
  display(head);
  print(head);

  insertatmiddle(&head,3,'c');
  printf("\t\n\tinsertatmiddle:\n");
  display(head);
  print(head);

  deleteatbegin(&head);
  printf("\t\n\tdeleteatbegin:\n");
  display(head);
  print(head);

  deleteatend(&head);
  printf("\t\n\tdeleteatend:\n");
  display(head);
  print(head);

  deleteatmiddle(&head,2);
  printf("\t\n\tdeleteatmiddle:\n");
  display(head);
  print(head);
  return 0;
}
