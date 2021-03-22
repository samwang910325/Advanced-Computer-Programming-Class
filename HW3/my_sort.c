#include"my_sort.h"
#include <stdio.h>
#include <stdlib.h>
#include<string.h> 

void selectionsort(void* arr,size_t n , size_t size,int (*cmp) (const void*,const void*))
{
    char* tmp=(char*) malloc(size);
    char* i=(char*) arr;
    char* j;

    for( i  ;  i <(char*)arr+n*size  ;  i+=size)
    {
        for( j=i ; j<(char*)arr+n*size  ; j+=size)
        {
            if((*cmp)(i,j)==1)
            {
                memcpy(tmp,j,size);
                memcpy(j,i,size);
                memcpy(i,tmp,size);
            }
        }
    }
    free(tmp);
    return ;
}

void inserction(void* arr,size_t n , size_t size,int (*cmp) (const void*,const void*))
{
    char *tmp = (char*) malloc(size);
    char* j ;
    char *k;
    char* i=(char*) arr;

    for(i ; i<(char *)arr +n*size ; i+=size)
    {
        memcpy(tmp,i,size);
        for( j=0 ; j<i ; j=j+size)
            if(cmp(j,i) == 1)  break;
        for( k = i ; k>j ; k=k-size);
            memcpy(k,k-1,size);
        memcpy(j,tmp,size);
    }
    return ;
}


void bubble(void* arr, size_t n, size_t size, int (*cmp) (const void*, const void*))
{

    char* i = (char*)arr,*j;
    char *tmp=malloc(size);
    int v=size;
    for( i ; i<n*size+ (char*)   arr ; i+=size)
    {
        for(j=-v+ n *size + (char*)  arr; j>i; j-=size)
        {
            if(cmp(j -v, j)>0)
            {
                memcpy(tmp , j,size);
                memcpy(j,j-v,size);
                memcpy(j-v , tmp,size);
            }
        }
    }
    return;
}