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

void reverse(Node** p){
    Node* q = NULL, *r= NULL;
    while(*p!=NULL){
        r=q;
        q=*p;
        *p = (*p)->next;
        q->next = r;
    }
    *p=q;

}
 
int main() {
 
    int A[] = {3, 5, 7, 10, 15};

    Node* head = create(A,sizeof(A)/sizeof(int));
    display(head);
    reverse(&head);
    display(head);
 
    return 0;
}