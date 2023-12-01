#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifymin(int *arr, int i)
{
    int k = i;
    while (k > 0 && arr[k] < arr[(k - 1) / 2])
    {
        swap(&arr[k], &arr[(k - 1) / 2]);
        k = (k - 1) / 2;
    }
}

void heapifyminremove(int *arr, int i, int size)
{
    int k = i;
    while (1)
    {
        int t = k;
        int l = 2 * k + 1;
        int r = 2 * k + 2;
        if (l < size && arr[l] < arr[t])
        {
            t = l;
        }
        if (r < size && arr[r] < arr[t])
        {
            t = r;
        }
        if (t != k)
        {
            swap(&arr[k], &arr[t]);
            k = t;
        }
        else
        {
            break;
        }
    }
}

int insert(int *arr, int size, int el)
{
    arr[size] = el;
    heapifymin(arr, size);
    return size + 1;
}

int delete(int *arr, int size)
{
    if (size == 0)
    {
        return 0;
    }
    swap(&arr[0], &arr[size - 1]);
    heapifyminremove(arr, 0, size - 1);
    return size - 1;
}
typedef int VID; // Vertex ID
struct stnode
{
    VID ID;
    struct stnode *next;
};
typedef struct stnode *node;
typedef struct stnode *LinkedList;
struct stgraph
{
    int iN; // Size of array / adjacency list
    node *adj;
};
typedef struct stgraph *Graph;
node createnode(VID v)
{
    node N = malloc(sizeof(struct stnode));
    N->ID = v;
    N->next = NULL;
    return N;
}
Graph creategraph(int N)
{
    Graph G = malloc(sizeof(struct stgraph));
    G->iN = N;
    G->adj = malloc(sizeof(node) * N);

    for (int i = 0; i < N; i++)
    {
        G->adj[i] = malloc(sizeof(struct stnode)); // Allocate memory for each node
        G->adj[i]->ID = i;                         // Set the ID of the node
        G->adj[i]->next = NULL;                    // Initialize next pointer
    }

    return G;
}
// void AddEdge(Graph G, VID u, VID v)
// {
//     node temp = G->adj[u];
//     if (temp->next == NULL)
//     {
//         temp->next = createnode(v);
//         return;
//     }
//     else
//     {
//         while(temp->next!=NULL&& v>=temp->next->ID ){
//             temp=temp->next;
//         }
//         node n = createnode(v);
//         node k =temp->next;
//         temp->next=n;
//         temp->next->next=k;
//         // if(v>=temp->next->ID){
//         // while (temp->next != NULL)
//         // {
//         //     temp = temp->next;
//         // }
//         // temp->next = createnode(v);
//         // return;
//         // }
//         // else{
//         //     node n = temp->next;
//         //     G->adj[u]->next=createnode(v);
//         //     G->adj[u]->next->next=n;
//         // }
//     }
// }
void AddEdge(Graph G, VID u , VID v){
    node temp = G->adj[u];
    if(temp->next==NULL){
        temp->next=createnode(v);
    }
    else{
        node n = temp->next;
        G->adj[u]->next=createnode(v);
        G->adj[u]->next->next=n;
    }
}
// void AddEdge(Graph G, VID u , VID v){
//     node temp = G->adj[u];
//     if(temp->next==NULL){
//         printf("ok");
//         temp->next =createnode(v);
//     }
//     else{
//         if(v>=temp->next->ID){
//             printf("lol");
//             while(temp->next!=NULL){
//                 temp=temp->next;
//             }
//             temp->next=createnode(v);
//         }
//         else{
//             printf("lolol");
//             node n = createnode(v);
//             G->adj[u]->next=n;
//             G->adj[u]->next->next=temp;
//         }
//     }
//     return;
// }

void BFS(Graph G, VID u)
{
    int *visited = calloc(sizeof(int), G->iN); // 0 indicates visited
    int j = 0;
    int arr[2*G->iN];

    // Queue Q = createque();
    // Push(Q, u);
    j = insert(arr,j,u);
    visited[u] = 1;
    while(j>0)
    {
        int v = arr[0];
        j = delete(arr,j);
        // printf("%d\n",v+1);
        // for(int i = 0 ; i< G->iN; i++){
        //     printf("%d ", visited[i]);
        // }
        // printf("\n")
            printf("%d ", v+1);
        node temp = G->adj[v];
        while (temp->next != NULL)
        {
            if (visited[temp->next->ID] == 0)
            {
                // Push(Q, temp->next->ID);
                visited[temp->next->ID] = 1;
                j = insert(arr,j,temp->next->ID);
            }
            temp = temp->next;
        }
    }
    return;
}

int main()
{
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    Graph G = creategraph(n);
    // assert(n<100000);
    for (int i = 0; i < m; i++)
    {
        VID u, v;
        scanf("%d %d", &u, &v);
        AddEdge(G, u - 1, v - 1);
        AddEdge(G, v - 1, u - 1);
    }
    // // sortlist(G);
    // printf("\n");
    // for(int i = 0; i< n ; i++){
    //     node temp=G->adj[i];
    //     printf("%d->",i+1);
    //     while(temp->next!=NULL){
    //         printf("%d ", temp->next->ID+1);
    //         temp=temp->next;
    //     }
    //     printf("\n");
    // }
    // printf("\n");
    // traversal(G);
    BFS(G, 0);
    // printf("\n");
    // DFS(G,0);
}