#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* arr, int l ,int r) {
    int i = l+1;
    int j =r;
    while(1){
        while (arr[j]>=arr[l] && i<=j){
            j--;
        }
        while (arr[i]<arr[l] && i<=j){
            i++;
        }
        if(i>j){
            break;
        }
        else{
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[l],&arr[j]);
    return j;
}
void quickSort(int* arr, int l , int r){
    if((r-l)<1){
        return;
    }
    int j = partition(arr,l,r);
    quickSort(arr,l,j-1);
    quickSort(arr,j+1,r);
}

void quick(int* arr, int n){
    quickSort(arr, 0, n - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    quick(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
