#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

void insertatbegin(struct node** head, int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = *head;
    *head = newnode;
}

void insertatend(struct node** head, int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    if (*head == NULL) {
        *head = newnode;
        return;
    }
    struct node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}

void insertatmiddle(struct node** head, int data) {
    int i = 1, pos;
    printf("ENTER THE POSITION TO INSERT AT THE MIDDLE:");
    scanf("%d", &pos);
    struct node* temp = *head;
    while (i < pos - 1) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = temp->next;
    temp->next = newnode;
}

void deleteatbegin(struct node** head) {
    if (*head == NULL) {
        printf("List is empty. Deletion can't be performed\n");
        return;
    }
    struct node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deletionatend(struct node** head) {
    if (*head == NULL) {
        printf("List is empty. Deletion can't be performed\n");
        return;
    }
    struct node* temp = *head;
    struct node* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    if (prev != NULL) {
        prev->next = NULL;
    } else {
        *head = NULL;
    }
    free(temp);
}

void deletionatmiddle(struct node** head) {
    int i = 1, pos;
    printf("ENTER THE POSITION TO DELETE AT THE MIDDLE:");
    scanf("%d", &pos);
    struct node* temp = *head;
    struct node* prev = NULL;
    while (i < pos && temp != NULL) {
        prev = temp;
        temp = temp->next;
        i++;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }
    if (prev != NULL) {
        prev->next = temp->next;
    } else {
        *head = temp->next;
    }
    free(temp);
}

void modify(struct node**head,int olddata,int newdata)
{
    int pos=0;
    struct node*temp=*head;
    while(temp!=NULL)
    {
        if(temp->data==olddata)
        {
            temp->data=newdata;
            printf("\n%d found at position %d,replaced with %d\n",olddata,pos,newdata);
        }
        temp=temp->next;
    }
    free(temp);
}

void display(struct node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
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
    printf("NUMBER OF NODE PRESENT IN LIST %d",count);
}

int main() {
    struct node* head = NULL;
    insertatbegin(&head, 10);
    insertatbegin(&head, 20);
    insertatbegin(&head, 30);
    display(head);

    insertatend(&head, 40);
    insertatend(&head, 50);
    insertatend(&head, 60);
    display(head);
    insertatmiddle(&head, 80);
    display(head);
    deleteatbegin(&head);
    display(head);
    deletionatend(&head);
    display(head);
    deletionatmiddle(&head);
    display(head);
    modify(&head,80,35);
    display(head);
    count(head);
    // Freeing memory
    struct node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }



    return 0;
}
