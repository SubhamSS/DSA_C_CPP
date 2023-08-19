#include<stdio.h>
#include<stdlib.h>


struct Node {
    int data;
    struct Node * next;
};

void traverse(struct Node* ptr){
    while (ptr->next != NULL){
        printf("Element: %d \n",ptr->data);
        ptr = ptr->next;
    }
    printf("Element: %d \n",ptr->data);

}

struct Node * insert_begin(struct Node* ptr, int data){
    struct Node * begin;
    begin = (struct Node *)malloc(sizeof(struct Node));
    begin->data = data;
    begin->next = ptr;

    return begin;
}

struct Node * insertAtend(struct Node* ptr,int data){
    struct Node * p;
    p = (struct Node *)malloc(sizeof(struct Node));

    struct Node * q = ptr;
    while(q->next != NULL){
        q = q->next;
    }
    q->next = p;
    p->next = NULL;
    p->data= data;

    return ptr;
}

struct Node * InsertAtIndex(struct Node * ptr, int data, int index){
    struct Node * p = (struct Node *)malloc(sizeof(struct Node));
    struct Node * q = ptr;

    int i = 0;
    
    while(i!=index-1){
        q = q->next;
        i++;
    }
    p->data = data;
    p->next = q->next;
    q->next = p;

    return ptr;
}

struct Node * InsertAfter(struct Node * ptr, struct Node * nodeafter, int data){
    struct Node * p;
    p = (struct Node *)malloc(sizeof(struct Node));
    p->next = nodeafter->next;
    p->data = data;
    nodeafter->next = p;

    return ptr;
}

int main() {

    struct Node * head;
    struct Node * second;
    struct Node * third;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 9;
    head->next = second;
    
    second->data = 23;
    second->next = third;

    third->data = 34;
    third->next = NULL;

    traverse(head);

    head = insert_begin(head,55);
    traverse(head);

    head = insertAtend(head, 200);
    traverse(head);

    head = InsertAtIndex(head, 67,3);
    traverse(head);

    head = InsertAfter(head, second, 99);
    traverse(head);

    return 0;

}