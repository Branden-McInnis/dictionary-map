#ifndef _DICT_HEADER
#define _DICT_HEADER

#include <stdbool.h>
#include "array_list.h"
#include "bintree.h"

typedef struct _Pair{

    void* first;
    void* second;

}Pair;

typedef struct _Dictionary{

    BinaryTree* tree;

}Dictionary;

Dictionary* dict_initialize(int(*)(void*,void*), void(*)(void*));

bool dict_insert(Dictionary*, void*, void*);

void* dict_get(Dictionary*, void*);

ArrayList* dict_key_list(Dictionary*, int);

bool dict_contains(Dictionary*, void*);

void* pair_get(BinaryTree*, void*);

void* pair_get_recursive(BinaryTree*, BinaryTreeNode*, void*);

void inorder(BinaryTree*, BinaryTreeNode*, ArrayList*);

#endif
