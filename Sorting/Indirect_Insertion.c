#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertion(int *arr,int* indices, int n)
{
   for ( int i = 0 ; i< n ; i++){
        for(int j = i ; j> 0 && arr[indices[j]]>arr[indices[j-1]]; j--){
            swap(&arr[indices[j]],&arr[indices[j-1]]);
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
    int indices[n];
    for ( int i = 0 ; i< n ; i++){
        indices[i]=i;
    }
    insertion(arr,indices,n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[indices[i]]);
    }
    printf("\n");
}