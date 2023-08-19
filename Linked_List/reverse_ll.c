#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node *create(int A[], int n)
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = NULL;

    struct Node *temp, *cross;
    cross = head;
    int i;
    for (i = 1; i < n; i++)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = NULL;
        cross->next = temp;
        cross = temp;
    }

    return head;
}

void display(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

void reverse(struct Node **ptr)
{
    struct Node *q=NULL, *r = NULL, *p =*ptr;

    while(p!=NULL){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    *ptr = q;
}

struct Node *reverse2(struct Node* ptr){
    struct Node *q=NULL, *r = NULL, *p =ptr;
    while(p!=NULL){
        r=q;
        q=p;
        p = p->next;
        q->next=r;
    }
    return q;
}



int main()
{
    int A[] = {3, 8, 11, 5, 9};
    struct Node *head = create(A, sizeof(A) / sizeof(int));
    display(head);

    //reverse(&head);
    struct Node *head2 = reverse2(head);
    display(head2);
    display(head);

    return 0;
}