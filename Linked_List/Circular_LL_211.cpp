#include <iostream>
#include <cstdio>
using namespace std;
 
class Node{
public:
    int data;
    Node* next;
};
 
class CircularLinkedList{
private:
    Node* head;
public:
    CircularLinkedList(int A[], int n);
    void Display();
    void recursiveDisplay(Node* p);
    Node* getHead(){ return head; }
    ~CircularLinkedList();
    void Insert(int index, int x);
    int Length();
    void Delete(int index);
    
};
 
CircularLinkedList::CircularLinkedList(int *A, int n) {
 
    head = new Node;
    head->data = A[0];
    head->next = head;

    Node* p ,*temp;
    p = head;
    
    int i;
    for(int i=1;i<n;i++)
    {
        temp = new Node;
        temp->data = A[i];
        temp->next = head;
        //temp->next = p->next;
        p->next = temp;
        p = temp;
    }

}
 
void CircularLinkedList::Display() {
    Node* p = head;
    do {
        cout << p->data << " -> " << flush;
        p = p->next;
    } while (p != head);
    cout << endl;
}

int CircularLinkedList::Length() {
    Node* p = head;
    int i =0;
    do {
        i++;
        p = p->next;
    } while (p != head);
    return i;
}
 
void CircularLinkedList::recursiveDisplay(Node *p) {
    static int flag = 0;
    if (p != head || flag == 0){
        flag = 1;
        cout << p->data << " -> " << flush;
        recursiveDisplay(p->next);
    }
    flag = 0;
}
 
CircularLinkedList::~CircularLinkedList() {
    Node* p = head;
    while (p->next != head){
        p = p->next;
    }
 
    while (p != head){
        p->next = head->next;
        delete head;
        head = p->next;
    }
 
    if (p == head){
        delete head;
        head = nullptr;
    }
 
}

void CircularLinkedList::Insert(int index, int x)
{
    Node *t;
    Node *trav;
    int i;
    if(index < 0 || index > Length())
    return;

    if(index==0)
    {
        t = new Node;
        t->data=x;
        if(head==NULL)
        {
            head=t;
            head->next=head;
        }
        else
        {
            trav = head;
            while(trav->next!=head){
                trav = trav->next;
            }
            trav->next = t;
            t->next = head;
            head = t;
        }
    }
    else
    {
        trav = head;
        t = new Node;
        t->data = x;
        for(i=0;i<index-1;i++){
            trav=trav->next;
        }
        t->next=trav->next;
        trav->next=t;
    }
}

void CircularLinkedList::Delete(int index)
{
    Node *t;
    Node *trav;
    int i;
    if(index < 0 || index >= Length())
    return;

    if(index==0)
    {
        trav = head;
        while(trav->next!=head){
            trav = trav->next;
        }
        trav->next = head->next;
        t = head->next;
        free(head);
        head = t;
    }
    else
    {
        trav = head;
        
        for(i=0;i<index-1;i++){
            trav=trav->next;
        }
        t = trav->next;
        trav->next=t->next;
        free(t);
    }
}

 
int main() {
 
    int A[] = {1, 3, 5, 7, 9};
 
    CircularLinkedList cl(A, sizeof(A)/sizeof(A[0]));
 
    cl.Display();

    printf("%d\n", cl.Length());

    cl.Insert(1, 56);
    
    cl.Display();
    printf("%d\n", cl.Length());

    cl.Delete(2);
    cl.Display();


    Node* h = cl.getHead();
    cl.recursiveDisplay(h);
 
    return 0;
}