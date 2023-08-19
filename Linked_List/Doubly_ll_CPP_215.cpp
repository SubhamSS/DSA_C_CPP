#include<iostream>
#include<cstdio>

using namespace std;

class Node{
public:
    Node* prev;
    int data;
    Node* next;
};

class DoublyLinkedList{
private:
    Node* head;
public:
    DoublyLinkedList(){
      head = NULL;  
    };
    DoublyLinkedList(int A[], int n);
    //~DoublyLinkedList();
    void Display();
    int Length();
    void Insert(int index, int x);
    void Delete(int index);
    void Reverse();
};

DoublyLinkedList::DoublyLinkedList(int *A, int n){
    head = new Node;
    head->data = A[0];
    head->next = NULL;
    head->prev = NULL;

    Node* temp;
    Node* back = head;
    for(int i =1; i<n;i++){
        temp = new Node;
        temp->data = A[i];
        temp->prev = back;
        temp->next = NULL;
        back->next = temp;
        back = temp;
    }
}

void DoublyLinkedList::Display(){
    Node* p = head;
    while(p!=NULL){
        printf("%d<->",p->data);
        p = p->next;
    }
    printf("\n");
}

int DoublyLinkedList::Length(){
    Node* p = head;
    int n=0;
    while(p!=NULL){
        n++;
        p = p->next;
    }
    return n;
}

void DoublyLinkedList::Insert(int index, int x){
    Node* p = head;
    Node* temp;
    temp = new Node;
    if(index<0 || index>Length()){
        return;
    }
    if(index==0){
        temp->data = x;
        temp->next = p;
        temp->prev = NULL;
        p->prev = temp;
        head = temp;
    }
    else{
        for(int i=0;i<index-1;i++){
            p=p->next;
        }
        temp->data = x;
        temp->prev = p;
        temp->next =p->next;
        if(index!=Length()){
            p->next->prev=temp;
        }
        p->next = temp;
    }
}

void DoublyLinkedList::Delete(int index){
    Node * p = head;
    if(index < 0 || index >= Length())
        return;
    if(index==0){
        p=p->next;
        p->prev = NULL;
        free(head);
        head = p;
    }
    else{
        Node * q = p->next;
        for(int i = 0;i<index-1;i++){
            p=p->next;
            q= q->next;
        }
        p->next = q->next;
        if(index!=Length()){
            q->next->prev = p;
        }
        q->next = NULL;
        q->prev = NULL;
        free(q);
    }

}

void DoublyLinkedList::Reverse(){
    Node* p = head;
    Node *q=NULL, *r=NULL;
    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
        q->next = r;
        q->prev=p;
    }
    head=q;
}



int main() {
 
    int A[] {1, 3, 5, 7, 9};
 
    DoublyLinkedList dll(A, sizeof(A)/sizeof(A[0]));
    dll.Display();
    cout << "Length: " << dll.Length() << endl;
 
    dll.Insert(0, 11);
    dll.Insert(2,23);
    dll.Insert(7, 13);
    dll.Display();
 
    dll.Delete(0);
    dll.Display();
    dll.Delete(3);
    dll.Display();
    dll.Delete(5);
    dll.Display();
 
    dll.Reverse();
    dll.Display();
 
    return 0;
}