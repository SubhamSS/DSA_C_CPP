#include<iostream>
#include<cstdio>
#include <bits/stdc++.h>

using namespace std;

class Stack
{
private:
    int size;
    int top;
    int *S;
public:
    Stack(int size);
    ~Stack();
    void Display();
    void Push(int val);
    void Pop();
    int Peek(int index);
    int isEmpty();
    int isFull();
    int StackTop();
};

Stack::Stack(int size)
{
    this->size = size;
    this->top=-1;
    this->S = new int[size];
}

Stack::~Stack()
{
    delete[] S;
}

void Stack::Display()
{
    int i;
    for(i=top;i>=0;i--)
    {
        printf("%d ",S[i]);
    }
    printf("\n");
}

void Stack::Push(int val)
{
    if(top==size-1)
    {
        printf("Stack Overflow");
    }
    else{
        top++;
        S[top]=val;
    }
}

void Stack::Pop()
{
    if (top == -1)
    {
        printf("Stack Underflow");
    }
    else{
        top--;
    }
}

int Stack::Peek(int index)
{
    if (top < index){
        printf("Invalid index");
    }
    else{
        return S[index];
    }
}

int Stack::isEmpty()
{
    return top == -1;
}

int Stack::isFull()
{
    return top==size-1;
}

int Stack::StackTop()
{
    if(!isEmpty())
        return S[top];
    return -1;
}

int main() {
 
    int A[] = {1, 3, 5, 7, 9};
 
    Stack stk(sizeof(A)/sizeof(A[0]));
 
    // Populate stack with array elements
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        stk.Push(A[i]);
        stk.Display();
    }
    stk.Pop();
    printf("%d\n",stk.StackTop());
    stk.Push(11);
    stk.Display();
}