#ifndef __BINTREE_HEADER
#define __BINTREE_HEADER
#include <stdbool.h>
#include "queue.h"
#include "stack.h"

typedef struct _BinTreeNode{

    void* data;
    struct _BinTreeNode* left;
    struct _BinTreeNode* right;


}BinaryTreeNode;

typedef struct _BinaryTree{

    BinaryTreeNode* top;
    int itemSize;
    char* type;
    int (*compare)(void*,void*);
    void (*print)(void*);

}BinaryTree;

BinaryTree* bintree_initialize(int, char*, int (*)(void*, void*), void (*)(void*));

BinaryTreeNode* bintree_create_node(int, void*);

bool bintree_insert(BinaryTree*, void*);

bool bintree_search(BinaryTree*, void*);

void bintree_print_in_order(BinaryTree*);

void bintree_print_pre_order(BinaryTree*);

void bintree_print_post_order(BinaryTree*);

void bintree_print_reverse_order(BinaryTree*);

bool _bintree_insert_recursive(BinaryTree*, BinaryTreeNode*, void*);

bool _bintree_search_recursive(BinaryTree*, BinaryTreeNode*, void*);

void _bintree_in_order_recursive(BinaryTree*, BinaryTreeNode*);

void _bintree_pre_order_recursive(BinaryTree*, BinaryTreeNode*);

void _bintree_post_order_recursive(BinaryTree*, BinaryTreeNode*);

void _bintree_reverse_order_recursive(BinaryTree*, BinaryTreeNode*);

void bintree_print_breadth_first(BinaryTree*);

void bintree_print_depth_first(BinaryTree*);

bool bintree_insert_replace(BinaryTree*, void*);

bool _bintree_insert_replace_recursive(BinaryTree*, BinaryTreeNode*, void*);

void bintree_print_breadth_first(BinaryTree*);

void bintree_print_depth_first(BinaryTree*);

bool bintree_insert_replace(BinaryTree*, void*);

bool _bintree_insert_replace_recursive(BinaryTree*, BinaryTreeNode*, void*);

#endif

