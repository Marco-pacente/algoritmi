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

void* initList();

void addToList(Node** head, int i);


void enQueue(int i, Node* head);

int deQueue(Node* head);


void enQueue(int i, Node* head){
    while (head != NULL)
    {
        head = head->next;
    }
    head->i = i;   
}

int deQueue(Node* head){
    Node* p;
    int i;
    i = head->i;
    p = head;
    head = head->next;
    free(p);
    p = NULL;
    return i;
}

void addToList(Node** head, int n){
    Node* new = malloc(sizeof(Node));
    new->i = n;
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

int main(){
    Node** adjList = malloc(sizeof(Node)*4);
    addToList(&adjList[1], 2);
    addToList(&adjList[2], 1);
    addToList(&adjList[2], 3);
    addToList(&adjList[3], 2);
    addToList(&adjList[3], 4);
    addToList(&adjList[4], 3);


    printf("Adiacenti a 1: \n");
    printList(adjList[1]);
    printf("Adiacenti a 2: \n");
    printList(adjList[2]);
    printf("Adiacenti a 3: \n");
    printList(adjList[3]);
    printf("Adiacenti a 4: \n");
    printList(adjList[4]);
    
}