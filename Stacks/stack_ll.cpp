#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
private:
    Node *top;
public:
    Stack();
    void push (int x);
    int pop();
    int peek(int index);
    void Display();
    int isEmpty();
    int numel();
};

Stack::Stack()
{
    top = NULL;
}

int Stack::numel()
{
    int els = 0;
    Node *t = top;
    while(t!=NULL){
        t=t->next;
        els++;
    }
    return els;
}

int Stack::isEmpty() {
    return numel()==0;
}
 

int Stack::peek(int index){
    
    Node *t = top;

    if(index<=0 || top==NULL){
        return -1;
    }
    int i = 1;
    while(t!=NULL){
        if(i==index){
            return t->data;
        }
        i++;
        t = t->next;
    }
    return -1;
}
void Stack::push(int x) {
    Node* t = new Node;
    if (t == NULL){
        cout << "Stack Overflow!" << endl;
    } else {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Stack::pop()
{
    int x;
    if(top==NULL)
        cout<<"Stack is empty"<<endl;
    else{
        x= top->data;
        Node *t = top;
        top = top->next;
        delete t;
    }
    return x;
}

void Stack::Display()
{
    Node *p = top;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}

int main()
{
    Stack stk;
    cout<<stk.numel();
    cout<<endl;
    cout<<stk.isEmpty();
    cout<<endl;
    stk.push(10);
    stk.push(23);
    stk.push(28);
    stk.push(48);
    stk.push(68);
    stk.Display();
    cout<<endl;
    cout<<stk.pop();
    cout<<endl;
    cout<<stk.peek(2);
    cout<<endl;
    cout<<stk.numel();
}