#include "utilities.h"
#include <stdio.h>
#include <stdlib.h>


void BFS(Node** adjList, int n, int source, enum color* color, int* parent, int* distance){
    Node* queue = (Node*)malloc(sizeof(Node));
    for (size_t i = 1; i <= n; i++)
    {
        color[i] = white;
        parent[i] = 0;
        distance[i] = __INT_MAX__;
    }
    distance[source] = 0;
    color[source] = gray;
    enQueue(source, &queue);
    while (queue!=NULL)
    {
        int u = deQueue(&queue);
        Node* curr = adjList[u];
        for (int v = curr->i; curr!=NULL; curr = curr->next)
        {
            v = curr->i;
            if(color[v] == white){
                color[v] = gray;
                parent[v] = u;
                enQueue(v, &queue);
                distance[v] = distance[u]+1;
            }
        }
        
    }
    
}

int main(){
    enum color c[5];
    int parent[5];
    int distance[5];
    
    Node** list = malloc(sizeof(Node) * 4);
    addToList(&list[1], 2);
    addToList(&list[1], 3);
    addToList(&list[2], 1);
    addToList(&list[2], 4);
    addToList(&list[2], 5);
    addToList(&list[3], 1);
    addToList(&list[3], 4);
    addToList(&list[3], 5);
    addToList(&list[4], 2);
    addToList(&list[4], 3);
    addToList(&list[4], 5);
    addToList(&list[5], 4);
    addToList(&list[5], 3);
    addToList(&list[5], 2);
    BFS(list, 4, 1, c, parent, distance);
    for (int i = 1; i <= 4; i++)
    {
        printf("Genitore di %d: %d", i, parent[i]);
    }
    







    
}