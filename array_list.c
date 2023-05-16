#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "array_list.h"

     ArrayList* alist_initialize(int maxSize, int itemSize, char* dataName){
    
        ArrayList* newarrayList = malloc(sizeof(ArrayList));

        newarrayList->arr = malloc(maxSize*sizeof(void*));
        newarrayList->size = 0;
        newarrayList->maxSize = maxSize;
        newarrayList->itemSize = itemSize;
        newarrayList->type = malloc(strlen(dataName) + 1);
        strcpy(newarrayList->type, dataName);

        return newarrayList;

     }

     bool alist_add(ArrayList* arrList, void* element){
     

         if(arrList == NULL){

            return false;

         }

         if(element == NULL){

            return false;

        
        }

          if(arrList->size == arrList->maxSize){

              _alist_resize(arrList);

           }



         arrList->arr[arrList->size] = malloc(arrList->itemSize);

         memcpy(arrList->arr[arrList->size], element, arrList->itemSize);

         arrList->size++;

         

         return true;
            
     }

     bool alist_add_at(ArrayList* arrList, int index, void* element){
            
        if(arrList == NULL){

            return false;

        }


        if(element == NULL){

            return false;

        }

        if (index < 0 || index > arrList->size) {

            return false;

        }

        if(arrList->size == arrList->maxSize){

              _alist_resize(arrList);

          }

        for(int i = arrList->size -1; i>=index; i--){

                arrList->arr[i + 1] = arrList->arr[i];

        }

         arrList->arr[index] = malloc(arrList->itemSize);    
            
        if(arrList->arr[index] == NULL){

            return false;

        }

             memcpy(arrList->arr[index], element,arrList-> itemSize);
                
             arrList->size++;

             return true;
            
        

     }

     void alist_clear(ArrayList* arrList){

         for(int i = 0; i < sizeof(arrList->arr); i++){
             free(arrList->arr[i]);

         }

         arrList->size = 0;

     }

     void* alist_get(ArrayList* arrList, int index){


        if(index < 0 || index > arrList->size){

            return NULL;

        }
    
         void* voidPtr = arrList->arr[index];

         return voidPtr;



     }

     int alist_index_of(ArrayList* arrList, void* element){


         if(arrList == NULL){
            
             return -1;

         }
    
         if(element == NULL){

            return -1;

         }


        for(int i = 0; i < arrList->size; i++){

            if (memcmp(arrList->arr[i] , element, arrList->itemSize) == 0){

                return i;

            }

        }

        return -1;

     }

     void* alist_remove(ArrayList* arrList, int index){
        
             if(arrList == NULL){
 
               return NULL;
 
          }

            if(index < 0 || index > arrList->size){
 
             return NULL;
 
         }


        
        void* voidPtr = arrList->arr[index];

        arrList->arr[index] = NULL;

        for(int i = index + 1; i < arrList->size; i++){
    
            arrList->arr[i-1] = arrList->arr[i];
            
        }

                 arrList->size--;


        return voidPtr;    

     }

     bool alist_destroy(ArrayList* arrList){
            
         if(arrList == NULL){
        
             return false;

         }    
    
         while(arrList->size > 0){
        
             free(arrList->arr[arrList->size - 1]);
             arrList->size--;

         }

    

       return true;
            
     }

     bool _alist_resize(ArrayList* arrList){
            
        if(arrList == NULL){

            return false;

        }   

        void* temp = realloc(arrList->arr, arrList->maxSize * 2 * sizeof(void*));

        if(temp == NULL){

            return false;
        }

        arrList->arr = temp;
        arrList->maxSize *= 2;

        return true;

    }

