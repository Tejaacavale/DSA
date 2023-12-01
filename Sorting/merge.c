#include <stdio.h>
#include <stdlib.h>
typedef char *ElemType;
void swap(ElemType *a, ElemType *b)
{
    ElemType temp = *a;
    *a = *b;
    *b = temp;
}
int comparator(ElemType a, ElemType b)
{
    int la = 0;
    int lb = 0;
    int check = 0;
    while (a[la] != '\0')
    {
        la++;
    }
    while (b[lb] != '\0')
    {
        lb++;
    }
    return la - lb;
}
void merge(ElemType *arr, int l, int mid, int r)
{
    int lenl = mid - l+1;
    int lenr = r - mid ;
    ElemType *larr = malloc(sizeof(ElemType) * lenl);
    ElemType *rarr = malloc(sizeof(ElemType) * lenr);
    for (int i = 0; i < lenl; i++)
    {
        larr[i] = arr[i + l];
    }
    for (int i = 0; i < lenr; i++)
    {
        rarr[i] = arr[i + mid + 1];
    }
    int i = 0;
    int j = 0;
    int k = l;
    while (i < lenl && j < lenr)
    {
        if (comparator(larr[i], rarr[j]) > 0)
        {
            arr[k] = larr[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = rarr[j];
            k++;
            j++;
        }
    }
    while (j < lenr)
    {
        arr[k] = rarr[j];
        j++;
        k++;
    }
    while (i < lenl)
    {
        arr[k] = larr[i];
        i++;
        k++;
    }
    free(larr);
    free(rarr);
}
void mergeS(ElemType *arr, int l, int r)
{
    if (l - r == 0)
    {
        return;
    }
    int mid = (l + r)/2;
    mergeS(arr, l, mid);
    mergeS(arr, mid + 1, r);
    merge(arr, l, mid, r);
}
void mergeSort(ElemType *arr, int n)
{
    mergeS(arr, 0, n - 1);
}

int main()
{
    int n;
    scanf("%d\n", &n);
    char **names = malloc(sizeof(char *) * n);
    for (int j = 0; j < n; j++)
    {
        int m;
        scanf("%d\n", &m);
        names[j] = malloc(sizeof(char) * (m + 1));
        scanf("%s", names[j]);
    }
    mergeSort(names, n);
    for (int o = 0; o < n; o++)
    {
        printf("%s\n", names[o]);
    }
}