#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct LinkedList {
    struct Node* head;
};

struct LinkedList* createLinkedList() {
    struct LinkedList* list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    list->head = NULL;
    return list;
}

int isEmpty(struct LinkedList* list) {
    return list->head == NULL;
}

void insertAtHead(struct LinkedList* list, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = list->head;
    list->head = newNode;
}

int deleteAtHead(struct LinkedList* list) {
    if (isEmpty(list)) {
        printf("List is empty\n");
        return -1; // Assuming -1 represents an error or invalid value
    }
    int data = list->head->data;
    struct Node* temp = list->head;
    list->head = list->head->next;
    free(temp);
    return data;
}

void display(struct LinkedList* list) {
    struct Node* current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("None\n");
}

int main() {
    struct LinkedList* list = createLinkedList();

    insertAtHead(list, 1);
    insertAtHead(list, 2);
    insertAtHead(list, 3);

    display(list);

    printf("Deleted item from head: %d\n", deleteAtHead(list));

    display(list);

    free(list); // Free allocated memory

    return 0;
}