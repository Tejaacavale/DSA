#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void shell(int *arr, int n)
{
    for (int increment = n / 2; increment > 0; increment /= 2)
    {
        for (int i = increment; i < n; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= increment && arr[j - increment] > temp; j -= increment)
            {
                arr[j] = arr[j - increment];
                for ( int k = 0 ; k< n ; k++){
                printf( "%d ", arr[k]);
            }
                printf("\n");
            }
            
            arr[j] = temp;
            for ( int k = 0 ; k< n ; k++){
                printf( "%d ", arr[k]);
            }
            printf("\n");

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
    shell(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}