#include<stdio.h>
#include<stdlib.h>

//node to store data and pointer
struct Node{
    int data;
    struct Node * next;
};

//function to traverse
void ll_traverse(struct Node* ptr){
    while(ptr!=NULL)
    {
        printf("Element %d\n",ptr->data);
        ptr = ptr->next;
    }
}

int main() {

    struct Node *head;
    struct Node *second;
    struct Node *third;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 7;
    head->next = second;

    // link second and third nodes
    second->data = 8;
    second->next = third;

    // last node points to null
    third->data = 41;
    third->next = NULL;

    ll_traverse(head);

    return 0;
}
