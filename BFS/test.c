#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int i;
    struct node* next;
} Node;

void printList(Node* head){
    while(head != NULL){
        printf("Elemento: %d\n", head->i);
        head = head->next;
    }
}
void addToList(Node* head, int n){
    while (head->next != NULL)
    {
        head = head->next;
        printf("%p\n", head);
    }
    head->next = malloc(sizeof(Node));
    head->next->i = n;
}

int main(){
    Node* node = malloc(sizeof(Node));
    node->i = 3;
    addToList(node, 6);
    printList(node);
}