#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct TrieNode
{
    struct TrieNode *children[26];
    int end;
    int count;
    int *arr;
};
typedef struct TrieNode *Trie;
Trie createtrienode()
{
    Trie T = malloc(sizeof(struct TrieNode));
    for (int i = 0; i < 26; i++)
    {
        T->children[i] = NULL;
    }
    T->end = 0;
    T->arr = malloc(sizeof(int) * 10001);
    T->count = -1;
    return T;
}
void Insert(Trie T, char *word, int targ)
{
    Trie temp = T;
    int size = strlen(word);
    for (int i = 0; i < size; i++)
    {
        char ch = word[i] - 'a';
        temp->count++;
        temp->arr[temp->count] = targ;
        temp->arr = realloc(temp->arr,sizeof(int*)*(temp->count+1));
        if (temp->children[ch] == NULL)
        {
            temp->children[ch] = createtrienode();
        }
        temp = temp->children[ch];
    }
    temp->count++;
    temp->arr[temp->count] = targ;
    temp->arr = realloc(temp->arr,sizeof(int*)*(temp->count+1));
    temp->end = 1;
}
int *search(Trie T, char *word)
{
    Trie temp = T;
    int size = strlen(word);
    for (int i = 0; i < size; i++)
    {
        char ch = word[i] - 'a';
        if (temp->children[ch] == NULL)
        {
            int* arr = malloc(sizeof(int));
            arr[0] = -1;
            return arr;
        }
        temp = temp->children[ch];
    }
    
    int* arr = temp->arr;
    arr[temp->count+1]=-1;
    return arr;
}
int comparator(const void* p, const void* q) {
    char* pw = *(char**)p;
    char* qw = *(char**)q;
    int k = strcmp(pw,qw);
    if(k > 0 ){
        return 1;
    }
    else {
        return -1;
    }
}

int main()
{
    int S;
    scanf("%d", &S);
    char *targets[1000];
    Trie T = createtrienode();
    for (int i = 0; i < S; i++)
    {
        int t;
        scanf("%d", &t);
        char *arr = malloc(sizeof(char) * 2 * 1000000);
        scanf("%s", arr);
        arr = realloc(arr, sizeof(char) * (strlen(arr) + 1));
        targets[i] = arr;
        for (int j = 0; j < t; j++)
        {
            char *geuss = malloc(sizeof(char) * 2 * 1000000);
            scanf("%s", geuss);
            geuss = realloc(geuss, sizeof(char) * (strlen(geuss) + 1));
            Insert(T, geuss, i);
        }
    }
    int q;
    scanf("%d", &q);
    for (int j = 0; j < q; j++)
    {
        char *querie = malloc(sizeof(char) * 2 * 1000000);
        scanf("%s", querie);
        querie = realloc(querie, sizeof(char) * (strlen(querie) + 1));
        int *arr = search(T, querie);
        int i = 0 ;
        int sizearr =0 ;
        while( arr[sizearr]!=-1){
            sizearr++;
        }
        char** answers = malloc(sizeof(char*)*(sizearr+1));

        if(arr[0]==-1){
            printf("0\n");
            continue;
        }
        while(arr[i]!=-1){
            answers[i]=targets[arr[i]];
            i++;
        }
        qsort(answers,i,sizeof(char*),comparator);
        char** answers2=malloc(sizeof(char*)*(sizearr+1));
        int size = i;
        int count = 1;
        answers2[0]=answers[0];
        for ( int i = 1 ; i< size ;i++){
            if(strcmp(answers[i],answers[i-1])!=0){
                answers2[count]=answers[i];
                count++;
            }
        }
        printf("%d ",count);
        for ( int k = 0 ; k< count ; k++){
            printf("%s ", answers2[k]);
        }
        printf("\n");
       
        
    }
    
}
