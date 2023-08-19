#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node * next;
};

struct Node* create(int A[],int n){
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = NULL;

    struct Node* temp, *cross;
    cross = head;
    int i;
    for(i=1;i<n;i++){
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data=A[i];
        temp->next = NULL;
        cross->next = temp;
        cross = temp;
    }

    return head;

}

void display(struct Node* ptr){
    while (ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }
}

struct Node* delete_at_index(struct Node* ptr, int size, int index){
    struct Node* temp, *tq;
    temp = ptr;
    tq = ptr->next;
    if(index<1 || index>size){
        printf("invalid index\n");
        return ptr;
    }
    if(index==1){    
        temp = temp->next;
        free(ptr);
        return temp;

        //ptr = ptr->next;
        //return ptr;
    }
    else if(index==size){
        while(tq->next!=NULL){
            temp=temp->next;
            tq = tq->next;
        }
        temp->next=NULL;
        free(tq);
        return ptr;
    }
    else{
        int i = 1;
        while(i!=index-1){
            temp = temp->next;
            tq=tq->next;
            i++;
        }
        temp->next = tq->next;
        free(tq);
        return ptr;
    }

}


int main(){
    int A[] = {3,8,11,5,9};
    struct Node * head = create(A,sizeof(A)/sizeof(int));
    display(head);

    head = delete_at_index(head,5,1);
    display(head);

    return 0;
}