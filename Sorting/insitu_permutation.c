#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void insitu_permutation(int *arr, int n)
{
    for(int i = 0 ; i< n;){
        if(arr[i]==i+1){
            i++;
        }
        else{
            swap(&arr[i],&arr[arr[i]-1]);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];// Assume an array of type 1,2,3,4,5,6.....n
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    insitu_permutation(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}