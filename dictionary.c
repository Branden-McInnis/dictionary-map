#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "dictionary.h"

Dictionary* dict_initialize(int(*compare)(void*,void*), void(*print)(void*)){

    Dictionary* dict = malloc(sizeof(*dict));

    dict->tree = bintree_initialize(sizeof(Pair), "Pair", compare, print);

    return dict;

}
 
bool dict_insert(Dictionary* dict, void* key, void* value){

    Pair* pair = malloc(sizeof(*pair));

    pair->first = key;
    pair->second = value;

    return bintree_insert_replace(dict->tree, pair);

}
 
void* dict_get(Dictionary* dict, void* key){

    if(dict == NULL || key == NULL){
        
        return NULL;

    }

    Pair* pair = malloc(sizeof(*pair));

    pair->first = key;
    pair->second = NULL;
    Pair* tempPair = pair_get(dict->tree, pair);
    
    return tempPair->second;

}

void* pair_get(BinaryTree* tree,void* pair){

    if(tree == NULL || pair == NULL){

        return NULL;

    }

    return pair_get_recursive(tree, tree->top, pair);

}

void* pair_get_recursive(BinaryTree* tree, BinaryTreeNode* node, void* pair){

    if(tree == NULL || node == NULL){

        return NULL;

    }

    if(tree->compare(pair, node->data) == 0){

        return node->data;

    }

    if(tree->compare(pair, node->data) > 0){

                return pair_get_recursive(tree,  node->left, pair);
    }

    else{
    
        return pair_get_recursive(tree,  node->right, pair);

    }


}
 
ArrayList* dict_key_list(Dictionary* dict, int size){

    ArrayList* arr = alist_initialize(10, size, "key");

     inorder(dict->tree, dict->tree->top, arr);

     return arr;
}
 
bool dict_contains(Dictionary* dict, void* key){

    Pair* pair = malloc(sizeof(*pair));
    pair->first = key;
    pair->second = NULL;
    return  bintree_search(dict->tree, pair);


}
 
void inorder(BinaryTree* tree, BinaryTreeNode* node, ArrayList* arr){

    if(tree == NULL || node == NULL){

        return;

    }

    Pair* pair = node->data;
    void* k = pair->first;

    if(node!=NULL){

        inorder(tree, node->left, arr);
        alist_add(arr, k);
        inorder(tree, node->right, arr);

    }


}
