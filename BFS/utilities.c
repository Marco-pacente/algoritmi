#include <stdio.h>
#include <stdlib.h>

enum color {
    white,
    gray,
    black
};


typedef struct node{
    int i;
    struct node* next;
} Node;


void addToList(Node** head, int i);


void enQueue(int i, Node** head);

int deQueue(Node** head);


void enQueue(int n, Node** head){
    Node* new = malloc(sizeof(Node));
    new->i = n;
    new->next = NULL;
    if (*head == NULL)
    {
        *head = new;
        return;
    }

    Node* curr = *head;

    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = new;    
}

int deQueue(Node** head){
    if (*head == NULL)
    {
        return -1;
    }
    
    Node* newHead = *head;
    
    newHead = newHead->next;
    free(*head);
    *head = newHead;
    return newHead->i;
}

void addToList(Node** head, int n){
    Node* new = malloc(sizeof(Node));
    new->i = n;
    new->next = NULL;
    if (*head == NULL)
    {
        *head = new;
        return;
    }
    Node* curr = *head; 
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr -> next = new;    
}

void printList(Node* head){
    while(head != NULL){
        printf("Elemento: %d\n", head->i);
        head = head->next;
    }
    
}