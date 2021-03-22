#include <stdio.h>
#include <stdlib.h>

#include<string.h> 

void selectionsort(void* arr,size_t n , size_t size,int (*cmp) (const void*,const void*));
void inserction(void* arr,size_t n , size_t size,int (*cmp) (const void*,const void*));
void bubble(void* arr, size_t n, size_t size, int (*cmp) (const void*, const void*)) ;