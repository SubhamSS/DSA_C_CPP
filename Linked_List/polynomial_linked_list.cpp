#include<iostream>
#include<cstdio>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int coeff;
    int pow;
    Node* next;
};

class poly_ll
{
private:
    Node* first;
public:
    poly_ll(int len);
    void display();
    int evaluate(int x);
    void reduce();
    void add(poly_ll adder);
};

poly_ll::poly_ll(int len){
    int coeff, pow;
    
    printf("Enter 1st coeff and power: ");
    scanf("%d%d",&coeff,&pow);

    first = new Node;
    first->coeff = coeff;
    first->pow = pow;
    first->next = NULL;

    Node *t,*last;
    last = first;

    for(int i =1;i<len;i++){
        printf("Enter %dth coeff and power: ",i+1);
        scanf("%d%d",&coeff,&pow);
        t = new Node;
        t->coeff = coeff;
        t->pow = pow;
        t->next = NULL;
        last->next = t;
        last = t;
    }

}

void poly_ll::display(){
    Node * t = first;
    while(t->next!=NULL){
        printf("%dx%d+",t->coeff,t->pow);
        t=t->next;
    }
    printf("%dx%d\n",t->coeff,t->pow);
}

void poly_ll::reduce(){
    Node *copy = first;
    Node *copy2 = copy;
    Node *ahead = copy2->next;
    while(copy!=NULL){
        while(ahead!=NULL){
            if(ahead->pow==copy->pow){
                Node* freer = ahead;
                copy->coeff +=ahead->coeff;
                copy2->next = ahead->next;
                ahead = ahead->next;
                freer->next = NULL;
                free(freer);
            }
            else{
                ahead = ahead->next;
                copy2 = copy2->next;

            }
        }
        copy = copy->next;
        if(copy==NULL){break;}
        copy2 = copy;
        ahead = copy2->next;
        if (ahead == NULL){break;}
    }
}

int poly_ll::evaluate(int x){
    Node* t = first;
    int eval = 0;
    while(t!=NULL){
        eval = eval + t->coeff*pow(x,t->pow);
        t= t->next;
    }
    return eval;
}

void poly_ll::add(poly_ll adder){
    Node * temp = first;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = adder.first;
}



int main(){
    int len, len2;
    printf("Enter length of polynomial: ");
    scanf("%d",&len);
    poly_ll poly1(len);
    poly1.display();
    poly1.reduce();

    poly1.display();
    int ev1 = poly1.evaluate(6);
    printf("\n%d",ev1);

    printf("Enter length of polynomial 2: ");
    scanf("%d",&len2);
    poly_ll poly2(len2);
    poly2.display();

    poly1.add(poly2);

    poly1.display();
    poly1.reduce();
    poly1.display();

    return 0;
}



