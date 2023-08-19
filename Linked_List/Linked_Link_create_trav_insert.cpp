#include <iostream>
#include <cstdio>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

Node* create(int A[], int n){
    Node* head = new Node;
    head->data = A[0];
    head->next = NULL;

    Node * cross, *temp;
    cross = head;
    for(int i=1;i<n;i++){
        temp = new Node;
        temp->data = A[i];
        temp->next = NULL;
        cross->next = temp;
        cross = temp;
    }
    return head;
}

void display(Node* p){
    //Node* p = ptr;
    while (p!=NULL){
        printf("%d\n",p->data);
        p=p->next;
    }
}

void insert_at_index(Node * p, int val, int index){
    int i=1;
    Node * newnode = new Node;

    Node* cross;
    cross = p;
    newnode->data = val;
    while (i!=index-1){
        cross = cross->next;
        i++;
    }
    Node* temp;
    temp = cross->next;
    cross->next = newnode;
    newnode->next = temp;

}

void test(Node **p) {
    *p = (*p)->next;
}

int main(){
    int A[] = {6,9,23,56,78};
    int n = 5;
    Node* head = create(A,n);
    display(head);

    test(&head);
    //insert_at_index(head,65,2);
    display(head);

    return 0;
}
