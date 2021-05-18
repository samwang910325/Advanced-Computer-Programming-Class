
#include<math.h>
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<string.h> 
#include<time.h>

int cmp(const void* a , const void*b)
{
    int* c=(int*)a;
    int* d=(int*) b;

    if(*c>*d) return 1 ;
    else if(*c<*d) return -1 ; 
    return 0 ;
}
int cmpr(const void* a , const void*b)
{
    int* c=(int*)a;
    int *d=(int*) b;
    if(*c>*d) return -1 ;
    else if(*c<*d) return 1; 
    return 0 ;
}

int cmpptr(const void* a , const void*b)
{
    int** c=(int**)a;
    int**d=(int**) b;
    if(**c>**d) return 1 ;
    else if(**c<**d) return -1; 
    return 0 ;
}

void heapify (void* ptr ,size_t n , size_t size, int (*cmp) (const void*, const void*) )
{
    int height = (int) log2(n) +1 ;
    int start = pow(2,height-1)-1 ;
    char * p =(char*) ptr ;
    int maxi ;  
    char* tmp=(char*)malloc(size) ; 
    for(int i=start  ; i>0; i--)
    {
        for(int k=i ; ; )
        {
            if(k*2+1 <=n)
            {
                if(cmp(p+k*2*size,p+(k*2+1)*size)==1 ) maxi=k*2+1 ; 
                else                  maxi=k*2   ;   
            }
            else if(k*2 <=n)
            {
                maxi=k*2 ;
            }
            else
            {
                maxi=-1 ; 
            }

            if(maxi!=-1 && cmp(p+k*size,p+(maxi*size))==1) 
            {
                memcpy(tmp,p+size*k,size); 
                memcpy(p+size*k,p+maxi*size,size);
                memcpy(p+maxi*size,tmp,size);
                k=maxi ; 
            }
            else
            {
                break ; 
            }
        }
    }
}
void popheap(void* ptr ,size_t n ,void* out, size_t size, int (*cmp) (const void*, const void*) )
{
    char * p =(char*) ptr ;
    memcpy(out,p+size,size);
    memcpy(p+size,p+size*n,size);
    n-=1 ; 
    int maxi ; 
    char* tmp=(char*   )malloc(size) ; 
    for(int k=1 ; ; )
    {
        if(k*2+1 <=n)
        {
            if(cmp(p+k*2*size,p+(k*2+1)*size)==1 ) maxi=k*2+1 ; 
            else                  maxi=k*2   ;   
        }
        else if(k*2 <=n)
        {
            maxi=k*2 ;
        }
        else
        {
            maxi=-1 ; 
        }
        if(maxi!=-1 &&  cmp(p+k*size,p+(maxi*size))==1)
        {
            memcpy(tmp,p+size*k,size); 
            memcpy(p+size*k,p+size*maxi,size);
            memcpy(p+maxi*size,tmp,size);
            k=maxi ; 
        }
        else
        {
            break ; 
        }
    }
    return ; 
}
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
void insertion(void* arr,size_t n , size_t size,int (*cmp) (const void*,const void*))
{
    char *tmp = (char*) malloc(size);
    char* j ;
    char *k;
    char* i=(char*) arr;
    char *c=(char*) malloc(size*n);

    for(i ; i<(char *)arr +n*size ;i+=size)
    {
        memcpy(tmp,i,size);
        for( j=(char*)arr  ; j<i ;  j=j+size)
            if(cmp(j,i) == 1)  break;
    
        memcpy(c,j,(int)(i-j));
        memcpy(j,tmp,size);
        memcpy(j+size,c,i-j);
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
void mergesort(void* arr, size_t n, size_t size, int (*cmp) (const void*, const void*))
{
    if (n < 6 )
    {
        selectionsort(arr, n, size, cmp); 
        return ; 
    }
    void* t =(void*) malloc(size*n) ;
    int nl,nr;
    nl = n / 2;
    nr = n / 2;
    if(n%2!=0 )
    {
        nr++;
    }
    mergesort(arr, nl, size, cmp);
    mergesort((char*)arr+size*nl, nr , size, cmp);
    int i=0 ;
    int j=0 ; 
    int total=0; 
    while(true)
    {
        if(total==n) break;
        else if(i<nl && j<nr && cmp((char*)arr+i*size,(char*)arr+size*nl+j*size)==-1 ) 
        {
            memcpy((char*) t+total*size,(char*)arr+i*size,size);
            total++ ; 
            i++ ;
        }
        else if (i<nl && j<nr && cmp((char*)arr+i*size,(char*)arr+size*nl+j*size)==0 )
        {
            memcpy((char*) t+total*size,(char*)arr+size*nl+j*size,size);
            total++ ; 
            j++ ;
        }
        else if(i<nl&& j>=nr)
        {
            memcpy((char*) t+total*size,(char*)arr+i*size,size);
            total++ ; 
            i++ ;
        }
        else if(j<nr && i>=nl)
        {
            memcpy((char*) t+total*size,(char*)arr+size*nl+j*size,size);
            total++ ; 
            j++ ;
        }
        else if( i<nl && j<nr && cmp((char*)arr+i*size,(char*)arr+size*nl+j*size)== 1  )
        {
            memcpy((char*) t+total*size,(char*)arr+size*nl+j*size,size);
            total++ ; 
            j++ ;
        }
    }
    memcpy(arr,t,size*n);
    free(t);
    return ;
}
void heapsort(void* arr , size_t n , size_t size, int (*cmp) (const void*, const void*))
{

    void* array= malloc(size*(n+1)); 
    memcpy((char*)array+size,arr,size*n); 
    void *tmp=malloc(size); 
    heapify(array,n,size,cmp);
    memcpy(arr,(char*) array +size   ,size*n);
    
    for(int c=0 ; c<n ; c++)
    {
        popheap(array,-c+n,tmp,size,cmp);
        memcpy((char*)arr+size*c,tmp,size);
    }
}
