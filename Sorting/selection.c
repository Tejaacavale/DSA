#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selection(int *arr, int n)
{
    for(int i = 0 ; i< n ; i++){
        int min = i;
        for ( int j = i ; j <n ; j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        swap(&arr[i],&arr[min]);
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
    selection(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}