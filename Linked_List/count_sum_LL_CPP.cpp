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
    while (p!=NULL){
        printf("%d\n",p->data);
        p=p->next;
    }
}

void count_sum(Node* p, int* count, int * sum){
    *count = 0;
    *sum = 0;
    while (p!=NULL){
        *count +=1;
        *sum += p->data;
        p=p->next;
    }
}

int main(){
    int A[] = {6,9,23,56,78};
    int n = 5;
    Node* head = create(A,n);
    display(head);

    int count, sum;
    count_sum(head, &count, &sum);
    printf("Count = %d, sum = %d",count, sum);
    return 0;
}
