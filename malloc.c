#include<stdio.h>

#define CAPACITY 640000

char HEAP[CAPACITY] = {0};

typedef struct{

    heap_chunk* next;
    char** head;
    bool isFree;

} heap_chunk;

heap_chunk CHUNK_TABLE[CAPACITY];

size_t current_size = 0;

   
void* heap_alloc(size_t size){
       
    if(current_size + size > CAPACITY){
        return NULL;    
    }  
    

    char* ptr = &HEAP[current_size];
    
    heap_chunk prev;
    prev.head = &ptr;
    prev.isFree = false;
    prev.next = NULL;
    CHUNK_TABLE[current_size] = prev;

    for(int i = current_size; i < current_size + size; i++){

        heap_chunk chunk;
        
        prev.next = chunk; 

        chunk.isFree = false;
        chunk.next = NULL;

        CHUNK_TABLE[i] = chunk;
        prev = chunk;
    }
    
    current_size += size;
    return ptr;
}

void heap_free(void* ptr){
    
    if(ptr==NULL){
        return;
    }
    
    
    
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
