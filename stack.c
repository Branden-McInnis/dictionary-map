#include "stack.h"
#include <stdlib.h>
#include <string.h>


Stack* stack_initialize(int dataSize, char* dataName){

    Stack* stackPtr = malloc(sizeof(*stackPtr));

    if(stackPtr == NULL){
        
        return NULL;

    }

    stackPtr->first = NULL;
    stackPtr->size = 0;
    stackPtr->itemSize = dataSize;
    stackPtr->type = malloc(strlen(dataName) + 1);
    
    if(stackPtr->type == NULL){
    
        return NULL;

    }

    strcpy(stackPtr->type, dataName);

    return stackPtr;


}

bool stack_push(Stack* stackPtr, void* element){

    if(stackPtr == NULL || element == NULL){

        return false;

    }

    Nodes* newNode = malloc(sizeof(*newNode));

    if(newNode == NULL){

        return false;

    }

    newNode->data = malloc(stackPtr->itemSize);

    if(newNode->data == NULL){

        free(newNode);
        return false;

    }

    memcpy(newNode->data,element,stackPtr->itemSize);

    newNode->next = stackPtr->first;

    stackPtr->first = newNode;

    stackPtr->size++;

    return true;
    
}

void* stack_pop(Stack* stackPtr){

    if(stackPtr == NULL || stackPtr->first == NULL){
        
        return false;

    }


    Nodes* nodePtr = stackPtr->first;
    void* element = nodePtr->data;
    stackPtr->first = nodePtr->next;
    
    if(stackPtr->first == NULL){

        stackPtr->first = NULL;

    }

    if(nodePtr->data == NULL){

        return NULL;

    }

    free(nodePtr);

    stackPtr->size--;
    return element;

}

void* stack_peek(Stack* stackPtr){
    
    if(stackPtr->first == NULL){
        
        return NULL;

    }

    return stackPtr->first->data;

}

int stack_size(Stack* stackPtr){

    return stackPtr->size;
    
}

bool stack_contains(Stack* stackPtr, void* element){

    if(stackPtr == NULL || element == NULL){
    
        return false;

    }

    Nodes* nodePtr = stackPtr->first;

    while(nodePtr != NULL){

        if(memcmp(nodePtr->data,element,stackPtr->itemSize) == 0){

            return true;

        }
        
        nodePtr = nodePtr->next;

    }
    
    return false;

}

bool stack_destroy(Stack* stackPtr){
    
    if(stackPtr == NULL){

        return false;

    }

    Nodes* nodePtr = stackPtr->first;

    while(nodePtr != NULL){

        Nodes* tempNode = nodePtr->next;

        free(nodePtr->data);

        nodePtr = tempNode;


    }

    free(stackPtr);

    return true;

}





