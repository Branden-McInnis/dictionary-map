#ifndef __STACK_HEADER
#define __STACK_HEADER
#include <stdbool.h>

 typedef struct _Nodes{
 
     void* data;
 
     struct _Nodes* next;
 
     struct _Nodes* prev;
 
 } Nodes;

typedef struct _Stack{
    
	Nodes* first;
	
	int size;
	
	int itemSize;
	
	char* type;	
	
}Stack;


Stack* stack_initialize(int, char*);

bool stack_push(Stack*, void*);

void* stack_pop(Stack*);

void* stack_peek(Stack*);

int stack_size( Stack*);

bool stack_contains( Stack*, void*);

bool stack_destroy( Stack*);


#endif



