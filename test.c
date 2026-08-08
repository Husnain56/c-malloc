#include<stdio.h>


int main(){


    int a = 10;

    int* ptr = &a;

    int** ptr2 = &ptr;

    printf("Contents: %p",ptr2);

    int b = 20;

    ptr = &b;
 
    printf("Content 1: %p",ptr);
    printf("Content 2: %p",ptr2);

}
