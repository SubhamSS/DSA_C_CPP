
#include <iostream>
#include<cstring>
using namespace std;
#include "stack_head.cpp"

int isBalanced(char* exp){
    Stack stk;
 
    for (int i=0; i<strlen(exp); i++){
        if (exp[i] == '('){
            stk.push(exp[i]);

        } else if (exp[i] == ')'){
            if (stk.isEmpty()){
                return false;
            } else {
                stk.pop();
            }
        }
    }
    return stk.isEmpty() ? true : false;
}

int main() {
 
    char E[] = "((a+b)*(c-d))";
    cout << isBalanced(E) << endl;
 
    char F[] = "((a+b)*(c-d)))";
    cout << isBalanced(F) << endl;
 
    char G[] = "(((a+b)*(c-d))";
    cout << isBalanced(G) << endl;
 
    return 0;
 
}