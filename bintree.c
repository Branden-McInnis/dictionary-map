//adapted from binary tree assignemnt I had done in 2110

#include "bintree.h"
#include "stack.h"
#include "queue.h"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

 BinaryTree* bintree_initialize(int itemSize, char* type, int (*compare)(void*, void*), void (*print)(void*)){

    BinaryTree* tree = malloc(sizeof(BinaryTree));

    tree->top = NULL;
    tree->itemSize = itemSize;
    tree->type = type;
    tree->compare = compare;
    tree->print = print;

    return tree;


 }

 BinaryTreeNode* bintree_create_node(int itemSize, void* element){

     BinaryTreeNode* node = malloc(sizeof(BinaryTreeNode));

     node->data = malloc(itemSize);
     node->left = NULL;
     node->right = NULL;
     
     memcpy(node->data, element, itemSize);

     return node;


 }

 bool bintree_insert(BinaryTree* tree, void* element){

    if(tree->top == NULL){

        BinaryTreeNode* node = bintree_create_node(tree->itemSize, element);
        tree->top = node;
        return true;

    }

    else{

        return _bintree_insert_recursive(tree, tree->top, element);

    }

 }

 bool bintree_search(BinaryTree* tree, void* element){
    
    if(tree == NULL || tree->top == NULL){
        
        return false;

    }

    return _bintree_search_recursive(tree, tree->top, element);

 }

 void bintree_print_in_order(BinaryTree* tree){
    
        if(tree == NULL){
            return;
        }

        _bintree_in_order_recursive(tree, tree->top);

 }

 void bintree_print_pre_order(BinaryTree* tree){

        if(tree == NULL){
             return;
         }

        _bintree_pre_order_recursive(tree, tree->top);

 }

 void bintree_print_post_order(BinaryTree* tree){

    if(tree == NULL){
             return;
         }

    _bintree_post_order_recursive(tree, tree->top);

 }

 void bintree_print_reverse_order(BinaryTree* tree){

    if(tree == NULL){
             return;
         }

    _bintree_reverse_order_recursive(tree, tree->top);           

 }

 bool _bintree_insert_recursive(BinaryTree* tree, BinaryTreeNode* node, void* element){
        

    if(tree->compare(node->data, element) < 0 && node->left == NULL){

         BinaryTreeNode* newNode = bintree_create_node(tree->itemSize, element);
         node->left = newNode;
         return true;
    }

    if(tree->compare(node->data, element) > 0 && node->right == NULL){

         BinaryTreeNode* newNode = bintree_create_node(tree->itemSize, element);
         node->right = newNode;
         return true;

    }

    if(tree->compare(node->data, element) < 0){

       return _bintree_insert_recursive(tree, node->left, element);

    }

    if(tree->compare(node->data, element) > 0){
    
       return _bintree_insert_recursive(tree, node->right, element);

    }

    if(tree->compare(node->data, element) == 0 && node->right == NULL){

        BinaryTreeNode* newNode = bintree_create_node(tree->itemSize, element);
        node->right = newNode;
        return true;
    

    }

    if(tree->compare(node->data, element) == 0){

        return _bintree_insert_recursive(tree, node->right, element);

    }

    else{

        return NULL;

    }



 }

 bool _bintree_search_recursive(BinaryTree* tree, BinaryTreeNode* node, void* element){


     if(tree == NULL || node == NULL){

         return false;

     }

     if(tree->compare(node->data, element) == 0){
    
         return true;


     }

     else if (tree->compare(node->data, element) < 0){
        
        return _bintree_search_recursive(tree, node->left, element);

     }

     else{

         return _bintree_search_recursive(tree, node->right, element);

        }

 }

 void _bintree_in_order_recursive(BinaryTree* tree, BinaryTreeNode* node){
    

    if(node == NULL){
        return;
    }    
        _bintree_in_order_recursive(tree, node->left);
        tree->print(node->data);
        _bintree_in_order_recursive(tree, node->right);

    

 }

 void _bintree_pre_order_recursive(BinaryTree* tree, BinaryTreeNode* node){
    
      if(node == NULL){ 
        return;
      }
          tree->print(node->data);
         _bintree_pre_order_recursive(tree, node->left);
         _bintree_pre_order_recursive(tree, node->right);

     

 }

 void _bintree_post_order_recursive(BinaryTree* tree, BinaryTreeNode* node){

     if(node == NULL){
        return;
     }

         _bintree_post_order_recursive(tree, node->left);
         _bintree_post_order_recursive(tree, node->right);
         tree->print(node->data);
     

 } 

void _bintree_reverse_order_recursive(BinaryTree* tree, BinaryTreeNode* node){

         if(node == NULL){
            return;
         }
 
         _bintree_reverse_order_recursive(tree, node->right);
         tree->print(node->data);
         _bintree_reverse_order_recursive(tree, node->left);
 
     

 }

void bintree_print_breadth_first(BinaryTree* tree){
 
     if(tree->top->data == NULL){
 
         return;
 
     }

    Queue* queue = queue_initialize(sizeof(BinaryTreeNode), "BinaryTreeNode");
    BinaryTreeNode* node;

    if(queue_enqueue(queue, tree->top) == true){
      
        while(queue->size != 0){

            node =  queue_dequeue(queue);
          
            tree->print(node->data);

            if(node->left != NULL){
            
                queue_enqueue(queue, node->left);

            }
            
            if(node->right != NULL){
            
                queue_enqueue(queue, node->right);

            }


        }
    

    }

}

void bintree_print_depth_first(BinaryTree* tree){


     if(tree->top->data == NULL){
 
          return;
 
      }
 
     Stack* stack = stack_initialize(sizeof(BinaryTreeNode), "BinaryTreeNode");
     BinaryTreeNode* node;
     if(stack_push(stack, tree->top) == true){
    
 
         while(stack_size(stack) !=  0){
             node = stack_pop(stack);
             tree->print(node->data);
 
             if(node->left != NULL){
 
                 stack_push(stack, node->left);
 
             }
 
             if(node->right != NULL){
 
                 stack_push(stack, node->right);
 
             }
 
 
         }
 
 
     }

}

bool bintree_insert_replace(BinaryTree* tree, void* element){

    if(tree->top == NULL){

         BinaryTreeNode* node = bintree_create_node(tree->itemSize, element);
         tree->top = node;
         return true;

     }

     else{

         return _bintree_insert_replace_recursive(tree, tree->top, element);

     }

}

bool _bintree_insert_replace_recursive(BinaryTree* tree, BinaryTreeNode* node, void* element){

    
     if(tree->compare(node->data, element) < 0 && node->left == NULL){
 
          BinaryTreeNode* newNode = bintree_create_node(tree->itemSize, element);
          node->left = newNode;
          return true;
     }
 
     if(tree->compare(node->data, element) > 0 && node->right == NULL){
 
          BinaryTreeNode* newNode = bintree_create_node(tree->itemSize, element);
          node->right = newNode;
          return true;
 
     }
 
     if(tree->compare(node->data, element) < 0){
 
        return _bintree_insert_replace_recursive(tree, node->left, element);
 
     }
 
     if(tree->compare(node->data, element) > 0){
 
        return _bintree_insert_replace_recursive(tree, node->right, element);
 
     }
 
     if(tree->compare(node->data, element) == 0){
 
         memcpy(node->data,element,tree->itemSize);
        return true;

     }
 
     else{
 
         return NULL;
 
     }

}


 






