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
        printf("%d/n",ptr->data);
        ptr = ptr->next;
    }
}

void count_sum(struct Node *ptr, int *count, int *sum){
    *count = 0;
    *sum =0;

    while(ptr!=NULL){
        *count = *count +1;
        *sum = *sum + ptr->data;
        ptr=ptr->next;
    }
}

int main(){
    int A[] = {3,8,11,5,9};
    struct Node * head = create(A,sizeof(A)/sizeof(int));
    int count, sum;
    count_sum(head, &count, &sum);
    printf("No of elements = %d, with sum = %d",count, sum);

    return 0;
}