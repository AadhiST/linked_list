#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) { exit(1); }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) { return newNode; }
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) { return newNode; }
    struct Node* current = head;
    while (current->next != NULL) { current = current->next; }
    current->next = newNode;
    newNode->prev = current;
    return head;
}

struct Node* insertAtPosition(struct Node* head, int value, int position) {
    struct Node* newNode = createNode(value);
    if (head == NULL || position <= 0) { return head; }
    if (position == 1) {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }
    struct Node* current = head;
    for (int i = 1; i < position - 1 && current != NULL; i++) { current = current->next; }
    if (current == NULL) { return head; }
    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != NULL) { current->next->prev = newNode; }
    current->next = newNode;
    return head;
}

struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) { return head; }
    struct Node* temp = head;
    head = head->next;
    if (head != NULL) { head->prev = NULL; }
    free(temp);
    return head;
}

struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) { return head; }
    if (head->next == NULL) { free(head); return NULL; }
    struct Node* current = head;
    while (current->next->next != NULL) { current = current->next; }
    free(current->next);
    current->next = NULL;
    return head;
}

struct Node* deleteFromPosition(struct Node* head, int position) {
    if (head == NULL || position <= 0) { return head; }
    if (position == 1) {
        struct Node* temp = head;
        head = head->next;
        if (head != NULL) { head->prev = NULL; }
        free(temp);
        return head;
    }
    struct Node* current = head;
    for (int i = 1; i < position && current != NULL; i++) { current = current->next; }
    if (current == NULL) { return head; }
    current->prev->next = current->next;
    if (current->next != NULL) { current->next->prev = current->prev; }
    free(current);
    return head;
}

void display(struct Node* head) {
    printf("Doubly Linked List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void freeList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    int choice, value, position;
    do {
        printf("\n1. Insert at the beginning\n2. Insert at the end\n3. Insert at a specific position\n");
        printf("4. Delete from the beginning\n5. Delete from the end\n6. Delete from a specific position\n");
        printf("7. Display\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            head = insertAtBeginning(head, value);
            break;
            case 2:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                head = insertAtEnd(head, value);
                break;
            case 3:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the position: ");
                scanf("%d", &position);
                head = insertAtPosition(head, value, position);
                break;
            case 4:
                head = deleteFromBeginning(head);
                break;
            case 5:
                head = deleteFromEnd(head);
                break;
            case 6:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                head = deleteFromPosition(head, position);
                break;
            case 7:
                display(head);
                break;
            case 8:
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 8);
    freeList(head);
    return 0;
}
