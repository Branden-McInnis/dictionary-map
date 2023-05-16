#include "queue.h"
#include <stdlib.h>
#include <string.h>


Queue* queue_initialize(int dataSize, char* dataName){

    Queue* queuePtr = malloc(sizeof(*queuePtr));

    if(queuePtr == NULL){
        
        return NULL;

    }

    queuePtr->first = NULL;
    queuePtr->last = NULL;
    queuePtr->size = 0;
    queuePtr->itemSize = dataSize;
    queuePtr->type = malloc(strlen(dataName) + 1);
    
    if(queuePtr->type == NULL){
    
        return NULL;

    }

    strcpy(queuePtr->type, dataName);

    return queuePtr;


}

bool queue_enqueue(Queue* queuePtr, void* element){

    if(queuePtr == NULL || element == NULL){

        return false;

    }

    Node* newNode = malloc(sizeof(*newNode));

    if(newNode == NULL){

        return false;

    }

    newNode->data = malloc(queuePtr->itemSize);

    if(newNode->data == NULL){

        free(newNode);
        return false;

    }

    memcpy(newNode->data,element,queuePtr->itemSize);


    newNode->next = NULL;

    if(queuePtr->last == NULL){

        queuePtr->first = newNode;

    }

    else{

        queuePtr->last->next = newNode;

    }

    queuePtr->last = newNode;

    queuePtr->size++;

    return true;
    
}

void* queue_dequeue(Queue* queuePtr){

    if(queuePtr == NULL){
        
        return false;

    }


    Node* nodePtr = queuePtr->first;
    void* element = nodePtr->data;
    queuePtr->first = nodePtr->next;
    
    if(queuePtr->first == NULL){

        queuePtr->last = NULL;

    }

    if(nodePtr->data == NULL){

        return NULL;

    }

    free(nodePtr);
    nodePtr = NULL;

    queuePtr->size--;
    return element;

}

void* queue_peek(Queue* queuePtr){
    
    if(queuePtr->first == NULL){
        
        return NULL;

    }

    return queuePtr->first->data;

}

int queue_size(Queue* queuePtr){

    return queuePtr->size;
    
}

bool queue_contains(Queue* queuePtr, void* element){

    if(queuePtr == NULL || element == NULL){
    
        return false;

    }

    Node* nodePtr = queuePtr->first;

    while(nodePtr != NULL){

        if(memcmp(nodePtr->data,element,queuePtr->itemSize) == 0){

            return true;

        }
        
        nodePtr = nodePtr->next;

    }
    
    return false;

}

bool queue_destroy(Queue* queuePtr){
    
    if(queuePtr == NULL){

        return false;

    }

    Node* nodePtr = queuePtr->first;

    while(nodePtr != NULL){

        Node* tempNode = nodePtr->next;

        free(nodePtr->data);

        nodePtr = tempNode;


    }

    free(queuePtr);

    return true;

}



