#include<stdio.h>

#define CAPACITY 640000

char HEAP[CAPACITY];

size_t current_size = 0;

void* heap_alloc(size_t size){
       
    if(current_size + size > CAPACITY){
        return NULL;    
    }  

    char* ptr = &HEAP[current_size];
    current_size += size;
    return ptr;
}

int main(){

    

    char * pointer = heap_alloc(2);
    char * ptr = heap_alloc(1);

    printf("Memory address of first pointer: %p\n", (void*)pointer);
    printf("Memory address of second pointer: %p", (void*)ptr);

    pointer = NULL;
    ptr = NULL;
        
    return 0;
}
