#include <stdio.h>
#include<stdlib.h>

struct Stack
{
    int size;
    int top;
    int *S;
};

void Create (struct Stack *st){
    printf("Enter size of stack:");
    scanf("%d",&st->size);
    st->top=-1;
    st->S = (int *)malloc(st->size*sizeof(int));
}

void Display(struct Stack st)
{
    int i;
    for(i=st.top;i>=0;i--)
    {
        printf("%d ",st.S[i]);
    }
    printf("\n");
}

void Push(struct Stack *st, int val)
{
    if(st->top==st->size-1)
    {
        printf("Stack Overflow");
    }
    else{
        st->top++;
        st->S[st->top]=val;
    }
}

void Pop(struct Stack *st)
{
    if (st->top == -1)
    {
        printf("Stack Underflow");
    }
    else{
        st->top--;
    }
}

int Peek(struct Stack st, int index)
{
    if (st.top < index){
        printf("Invalid index");
    }
    else{
        return st.S[index];
    }
}

int isEmpty(struct Stack st)
{
    if (st.top==-1){
        return 1;
    }
    return 0;
}

int isFull(struct Stack st)
{
    return st.top==st.size-1;
}

int stackTop(struct Stack st)
{
    if(!isEmpty(st))
        return st.S[st.top];
    return -1;
}

int main()
{
    struct Stack st;
    Create(&st);

    Push(&st,10);
    Push(&st,20);
    Push(&st,30);
    Push(&st,40);
    Pop(&st);

    printf("%d \n",Peek(st,2));


    Display(st);

    return 0;
}


