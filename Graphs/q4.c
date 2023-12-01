#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
struct pair
{
    int x;
    int y;
};

typedef struct pair *Pair;
struct node
{
    Pair P;
    long long dist;
};
typedef struct node *node;
node createnode(Pair P, int dist)
{
    node N = malloc(sizeof(struct node));
    N->P = P;
    N->dist = dist;
    return N;
}
typedef struct node *node;
Pair createPair(int x, int y)
{
    struct pair *p = (struct pair *)malloc(sizeof(struct pair));
    assert(p != NULL);
    p->x = x;
    p->y = y;
    return p;
}
void swap(node *arr, int i, int j)
{
    node temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void heapifymin(node *arr, int i)
{
    int k = i;
    while (k > 0 && arr[k]->dist < arr[(k - 1) / 2]->dist)
    {
        swap(arr, k, (k - 1) / 2);
        k = (k - 1) / 2;
    }
}

void heapifyminremove(node *arr, int i, int size)
{
    int k = i;
    while (1)
    {
        int t = k;
        int l = 2 * k + 1;
        int r = 2 * k + 2;
        if (l < size && arr[l]->dist < arr[t]->dist)
        {
            t = l;
        }
        if (r < size && arr[r]->dist < arr[t]->dist)
        {
            t = r;
        }
        if (t != k)
        {
            swap(arr, k, t);
            k = t;
        }
        else
        {
            break;
        }
    }
}

int insert(node *arr, int size, node el)
{
    arr[size] = el;
    heapifymin(arr, size);
    return size + 1;
}

int delete(node *arr, int size)
{
    if (size == 0)
    {
        return 0;
    }
    swap(arr, 0, size - 1);
    heapifyminremove(arr, 0, size - 1);
    return size - 1;
}
void Dijkstra(int **A, long long **dist, int n, int m)
{
    node arr[n * m * 2 + 3];
    int j = 0;
    for (int i = 0; i < m; i++)
    {
        Pair P = createPair(0, i);
        dist[0][i]=A[0][i];
        node N = createnode(P, dist[0][i]);
        j = insert(arr, j, N);
    }
    for (int i = 0; i < n-1; i++)
    {
        Pair P = createPair(i, m - 1);
        dist[i][m-1]=A[i][m-1];
        node N = createnode(P, dist[i][m-1]);
        j = insert(arr, j, N);
    }
    while (j != 0)
    {
        node N = arr[0];
        j = delete (arr, j);
        int x = N->P->x;
        int y = N->P->y;
        int dx[] = {-1, 1, 0, 0, 1, 1, -1, -1};
        int dy[] = {0, 0, -1, 1, 1, -1, 1, -1};
        for (int l = 0; l < 8; l++)
        {
            int xn = x + dx[l];
            int yn = y + dy[l];

            if (xn >= 0 && yn >= 0 && xn <= n - 1 && yn <= m - 1){
                if(dist[xn][yn]>dist[x][y]+A[xn][yn]){
                    // printf("%d %d\n", x ,y);
                    dist[xn][yn]=dist[x][y]+A[xn][yn];
                    Pair P = createPair(xn,yn);
                    node N = createnode(P,dist[xn][yn]);
                    j = insert(arr,j,N);
                }
            }
        }
    }
}
    int main()
    {
        int t;
        scanf("%d", &t);
        for (int z = 0; z < t; z++)
        {
            int n, m;
            scanf("%d %d", &n, &m);
            int **A = malloc(sizeof(int *) * n);
            for (int i = 0; i < n; i++)
            {
                A[i] = malloc(sizeof(int) * m);
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    scanf("%d", &A[i][j]);
                }
            }
            long long **dist = malloc(sizeof(long long *) * n);
            for (int i = 0; i < n; i++)
            {
                dist[i] = malloc(m * sizeof(long long));
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    dist[i][j] = LLONG_MAX;
                }
            }
            Dijkstra(A,dist,n,m);
            // for ( int i = 0; i< n ; i++){
            //     for (int j = 0 ; j< m ; j++){
            //         printf("%d ",dist[i][j]);
            //     }
            //     printf("\n");
            // }
            long long min = LLONG_MAX;
            if(A[0][0]<min){
                min=A[0][0];
            }
            if(A[n-1][m-1]<min){
                min = A[n-1][m-1];
            }
            for (int i = 0 ; i< m-1; i++ ){
                if(dist[n-1][i]<min){
                    min = dist[n-1][i];
                }
            }
            for(int j = 1 ; j<n;j++){
                if(dist[j][0]<min){
                    min = dist[j][0];
                }
            }
            printf("%lld\n", min);
        }
        return 0;
    }