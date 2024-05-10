#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

void insertStart (struct Node **head, int data)
{
  struct Node *newNode = (struct Node *) malloc (sizeof (struct Node));
  newNode->data = data;
  newNode->next = *head;
  *head = newNode;
}

void insertLast (struct Node **head, int data)
{
  struct Node *newNode = (struct Node *) malloc (sizeof (struct Node));
  newNode->data = data;
  newNode->next = NULL;
  if (*head == NULL)
    {
      *head = newNode;
      return;
    }

  struct Node *temp = *head;

  while (temp->next != NULL)
    temp = temp->next;

  temp->next = newNode;
}
void insertmiddle(struct Node **head,int data)
{
	int i=1,pos;
	printf("Enter the position");
	scanf("%d",&pos);
	struct Node *temp=*head;
	while(i<pos)
	{
		temp=temp->next;
		i++;
	}
	struct Node *newnode=(struct Node*)malloc(sizeof (struct Node)) ;
	newnode->data=data;
	newnode->next=temp->next;
	temp->next=newnode;
}
void deleteNode(struct Node** head_ref, int key) {
  struct Node *temp = *head_ref, *prev;

  if (temp != NULL && temp->data == key) {
  *head_ref = temp->next;
  free(temp);
  return;
  }

}
void display (struct Node *node)
{
  while (node != NULL)
    {
      printf ("%d ", node->data);
      node = node->next;
    }
  printf ("\n");
}
int main ()
{
  struct Node *head = NULL;
  insertStart (&head, 12);
  insertStart (&head, 16);
  insertStart (&head, 20);

  insertLast (&head, 10);
  insertLast (&head, 14);
  insertLast (&head, 18);
  insertLast (&head, 11);

  insertmiddle(&head,100);
  insertmiddle(&head,200);

	deleteNode(&head,20);
	deleteNode(&head,100);
  display (head);
  return 0;
}
