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

int isLoop(Node *p){
    Node* q, *r;
    q = r = p;
    do{
        q=q->next;
        r= r->next;
        if(r!=NULL){
            r=r->next;
        }
        else{
            q=q;
        }
    }while(q!=NULL && r!=NULL && q!=r);

    if(q==r){
        return 1;
    }
    else{
        return 0;
    }
}
 
int main() {
 
    int A[] = {3, 5, 7, 8, 10};

    Node* head = create(A,sizeof(A)/sizeof(int));
    display(head);
    printf("\n");
    display(head);

    Node* t1, *t2;
    t1 = head->next->next;
    t2= head->next->next->next->next;
    t2->next = t1;
    printf("%d",isLoop(head));

    return 0;
}