#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct TrieNode{
    struct TrieNode* children[26];
    int end;
};
typedef struct TrieNode* Trie;
Trie createtrienode(){
    Trie T = malloc(sizeof(struct TrieNode));
    for(int i = 0 ; i<26 ; i++){
        T->children[i]=NULL;
    }
    T->end=0;
    return T;
}
void Insert(Trie T, char* word){
    Trie temp = T;
    int size = strlen(word);
    for ( int i =0 ; i< size ; i++ ){
        char ch = word[i]-'a';
        if(temp->children[ch]==NULL){
            temp->children[ch]=createtrienode();
        }
        temp=temp->children[ch];
    }
    temp->end=1;
}
int search(Trie T, char* word ){
    Trie temp = T;
    int size = strlen(word);
    for ( int i = 0 ; i< size ; i++){
        char ch = word[i]-'a';
        if(temp->children[ch]==NULL){
            return 0;
        }
        temp=temp->children[ch];
    }
    if(temp->end == 1){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    int t;
    scanf("%d", &t);
    Trie T = createtrienode();
    for ( int i = 0 ; i < t ; i++){
        char* word;
        scanf("%s", word);
        Insert(T,word);
    }
    for ( int i = 0; i< t ; i++){
        char* word;
        scanf("%s",word);
        printf("%d",search(T,word));
    }
}