#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int comp(int a , int b){
    return (b-a);
}
void insertion(int *arr, int n)
{
    for (int i = 1; i< n ; i++){
        for ( int j = i; j>0  && comp(arr[j],arr[j-1])>0 ; j--){
            swap(&arr[j],&arr[j-1]);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    insertion(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}