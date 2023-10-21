#include<stdio.h>
 
 
void display(int *arr, int n){
    // Code for Traversal
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");   
}
 
int bin_search(int arr[], int size, int val){
    // code for lin search
    
    int low = 0, high = size-1, mid = (low+high)/2;

    while (low<=high){
    if (arr[mid] == val){
        return mid;
    }
    else if (val > arr[mid]){
        low = mid+1;
        mid = (low+high)/2;
    }
    else{
        high = mid-1;
        mid = (low+high)/2;
    }
    }
    return -1;
}
 
int main(){
    int arr[] = {7, 8, 12, 27, 88, 265, 678, 1111, 2222};
    int size = sizeof(arr)/sizeof(int);
    display(arr, size); 

    int search_val = 27;
    bin_search(arr, size, search_val);

    if (bin_search(arr, size, search_val)>=0){
        printf("Element found at position %d", bin_search(arr, size, search_val));
    }
    else{
        printf("Element not found");
    }
    return 0;
}