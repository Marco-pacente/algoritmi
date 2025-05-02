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


void printList(Node* head);