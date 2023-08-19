#include <iostream>
#include <cstdio>
using namespace std;

// class are private by default, hence public
class Node{
public:
    int data;
    Node* next;
};

Node* create(int A[], int n){

    Node* head = new Node;
    head->data = A[0];
    head->next = NULL;
    
    int i;   
    Node* t, *last;
    last = head;

    for(i=1;i<n;i++){
        t = new Node;
        t->data=A[i];
        t->next=NULL;
        last->next = t;
        last = t;
    }
    return head;
}

void display(Node* p){
    while (p!=NULL){
        printf("%d\n",p->data);
        p=p->next;
    }
}

Node *concat(Node* ptr,Node*ptr2){
    Node *p=ptr;
    Node *q = ptr;
    while(p->next!=NULL){
        p = p->next;
    }
    p->next = ptr2;
    return q;
}

Node * mergeascend(struct Node *p,struct Node *q)
{
    
    Node *last;
    Node* third=NULL;
    if(p->data < q->data)
    {
        last=p;
        p=p->next;
    }
    else
    {
        last=q;
        q=q->next;
    }
    third = last;

    while(p!=NULL && q!=NULL)
    {
        if(p->data < q->data)
        {
            last->next=p;
            last=p;
            p=p->next;
        }
        else
        {
            last->next=q;
            last=q;
            q=q->next;
        }
        last->next=NULL;
    }
    if(p==NULL){last->next=q;}
    if(q==NULL)last->next=p;
    return third;
}

 
int main() {
 
    int A[] = {3, 5, 7, 8, 10};
    int B[] = {2,6,10,11,14,22};

    Node* head = create(A,sizeof(A)/sizeof(int));
    //display(head);
    //printf("\n");
    Node* head2 = create(B,sizeof(B)/sizeof(int));
    //display(head2);
    //printf("\n");

    //Node* newhead = concat(head,head2);
    //display(head);
    //printf("\n");


    Node* mergedhead = mergeascend(head,head2);
    display(mergedhead);

    printf("\n");
    display(head);

 
    return 0;
}