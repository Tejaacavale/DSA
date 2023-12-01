#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

struct pair
{
    int x;
    int y;
};
struct ret{
    int L;
    int** visited;
};
typedef struct ret* ret;
typedef struct pair *Pair;
Pair createPair(int x, int y)
{
    struct pair *p = (struct pair *)malloc(sizeof(struct pair));
    assert(p != NULL);
    p->x = x;
    p->y = y;
    return p;
}
ret Createret(int x , int** visited){
    ret R = malloc(sizeof(struct ret));
    R->L=x;
    R->visited = visited;
    return R;
}
Pair DFSpatch(int **A, int **visited, int n, int m, int r, Pair src, int peri, int area)
{
    int x = src->x;
    int y = src->y;
    visited[x][y] = 1;
    area++;
    // peri = peri + 4;
    int dx[] = {-1, 1, 0, 0,1,1,-1,-1};
    int dy[] = {0, 0, -1, 1,1,-1,1,-1};
    for (int j = 0; j < 4; j++)
    {
        int xn = x + dx[j];
        int yn = y + dy[j];

        if (xn >= 0 && yn >= 0 && xn <= n - 1 && yn <= m - 1)
        {
            // if (visited[xn][yn] == 1 && A[xn][yn] == 1)
            if(A[xn][yn]==0)
            {
                peri++;
                // printf("Ok");
            }
        }
        if(xn<0 || yn <0 || xn > n-1 || yn > m-1){
            peri++;
        }
    }
    
    for (int i = 0; i < 4; i++)
    {
        int xnew = x + dx[i];
        int ynew = y + dy[i];
        if (xnew >= 0 && ynew >= 0 && xnew <= n - 1 && ynew <= m - 1 && visited[xnew][ynew] == 0)
        {
            if (A[xnew][ynew] == 1)
            {
                Pair p = createPair(xnew, ynew);
                Pair P = DFSpatch(A, visited, n, m, r, p, peri, area);
                area = P->x;
                peri = P->y;
            }
        }
    }
    Pair Adash = createPair(area, peri);
    return Adash;
}
ret DFSpatchcall(int **A, int **visited, int n, int m, int r, Pair src)
{
    // in pair let x be area and y be perimeter.
    Pair ans = DFSpatch(A, visited, n, m, r, src, 0, 0);
    // printf("%d %d\n", ans->x, ans->y);
    int L = ans->x * 4 - ans->y;
    ret R = Createret(L,visited);
    return R;
}
// int DFSwhole(int** A,int** dist,int n , int m , int r,Pair src, int max){
//     int x = src->x;
//     int y = src->y;
//     visited[x][y]=1;
//     int dx[] = {-1, 1, 0, 0};
//     int dy[] = {0, 0, -1, 1};
//     for ( int i = 0 ; i< 4 ; i++){
//         int xnew = x+dx[i];
//         int ynew = y +dy[i];
//         if(xnew>=0 && ynew>=0 && xnew<=n-1 && ynew<= n-1 && visited[ynew][xnew]==0){
//             if(A[ynew][xnew]==1){
//                 Pair p = createPair(xnew,ynew);
//                 int ans = DFSpatchcall(A,dist,n,m,r,p);
//                 if(ans>max){
//                     max = ans;
//                 }
//             }
//         }
//     }
//     return max;
// }
// int solve(int** A,int** dist,int n , int m , int r){
//     printf("op");

//     printf("pp");

//     Pair p = createPair(0,0);
//     int mdash = INT_MIN;
//     int max = DFSwhole(A,dist,n,m,r,p,mdash);
//     return max;
// }
int main()
{
    int n, m, r;
    scanf("%d %d %d", &n, &m, &r);

    int **A = (int **)malloc(sizeof(int *) * n);

    for (int i = 0; i < n; i++)
    {
        A[i] = (int *)malloc(m * sizeof(int));

        for (int j = 0; j < m; j++)
        {
            A[i][j] = 0;
        }
    }

    // A[4][3]=1;
    for (int j = 0; j < r; j++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        A[a - 1][b - 1] = 1;
    }
    int **visited = malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
    {
        visited[i] = calloc(m, sizeof(int));
    }
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((visited[i][j] == 0) && (A[i][j] == 1))
            {
                Pair src = createPair(i, j);
                ret R = DFSpatchcall(A, visited, n, m, r, src);
                int ans = R->L;
                visited = R->visited;
                // for( int i = 0 ; i< n ; i++){
                //     for ( int j = 0 ; j< m ; j++){
                //         printf("%d ", visited[i][j]);
                //     }
                //     printf("\n");
                // }
                if (ans > max)
                {
                    max = ans;
                }
            }
        }
    }
    printf("%d", max);

    //    int final = solve(A,dist,n,m,r);
    //    printf("%d", final);
    return 0;
}