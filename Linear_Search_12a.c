#include<stdio.h>
 
 
void display(int *arr, int n){
    // Code for Traversal
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");   
}
 
int lin_search(int arr[], int size, int val){
    // code for lin search
    
    for (int i = 0; i <size; i++)
    {
        if (arr[i] == val){
            return i; 
        }
        
    }  
        return -1;
}
 
int main(){
    int arr[100] = {7, 8, 12, 27, 88};
    int size = 5;
    display(arr, size); 

    int search_val = 67;
    lin_search(arr, size, search_val);

    if (lin_search(arr, size, search_val)>=0){
        printf("Element found at position %d", lin_search(arr, size, search_val));
    }
    else{
        printf("Element not found");
    }
    return 0;
}