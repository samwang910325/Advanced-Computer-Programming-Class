#include<stdio.h>
#include <stdlib.h>
#include<string.h>

int global_index ;

int cmp(const void* n1 , const void* n2)
{
    int *a1=(int*) n1;
    int *a2=(int*) n2; 
    if(*a1<*a2) return -1;
    else if(*a1==* a2) return 0; 
    else  return  1; 
}
void print(int osize,int n ,int** out)
{
    for(int j=0 ; j<osize ; ++j)
    {
        for(int k=0; k<n ; k++ )
        {
            printf("%d ",out[j][k]);
        }
        printf("\n");
    }
    return ;
}
void  printar(int n ,int* arr)
{
    for(int i=0 ; i<n ; i++)
        printf("%d ",arr[i]); 
    printf("\n");
    return ; 
}
void combination (int n , int k , int* array,int* current,int index, int size , int** out )
{
    if(size==k)
    {
        out[global_index++]=current;
        return ;
    }
    for(int i=index ; i<=n-(k-size) ; i++)
    {
        int* arr=(int*) malloc(sizeof(int)*k);
        memcpy(arr,current,k*sizeof(int));
        arr[size]=array[i]; 
        combination(n,k,array,arr,i+1,size+1,out);
    }
    free(current);
    return ;
}

int combinationn(int k,int n)
{
    int out=1 ; 
    for(int a=n ; a> (n-k);a--)
    {
        out*=a;
    }
    for(int i=1; i<=k ; i++)
    {   
        out/=i ; 
    }
    return out ; 
}
void permute(int n,int k,int *arr , int**out)
{
    if(n==1)
    {
        printar(k,arr);
    }
    else
    {
        int tm=0;
        for(int j= 0 ; j<n ; j++)
        {
            permute( n-1,k,arr,out);
            if(n%2==1)
            {
                tm =arr[0] ;
                arr[0]=arr[n-1];
                arr[n-1]=tm;
            }
            else if(n%2==0)
            {
                tm =arr[ j] ;
                arr[j]=arr[n-1];
                arr[n-1]=tm;
            }
        }
    }
    
    return ; 
}
int main(void)
{
    printf("Please input the size of your arr\n");
    int  k ,n; 
    scanf("%d",&n);
    printf("\nInput your arr of size  %d  \n",n);
    int *arr=(int*) malloc(sizeof(int)*n );
    for(int z=0 ; z<n ; ++z   )
    {
        scanf("%d",&arr[z]);
    }
    printf("\nInput the k\n");
    scanf("%d",&k);
    char  ch ;
    printf("\nWhat action  are you goint to do,combination or permutation?\n");
    printf("Enter p  if you want the permutation of the array \n");
    printf("Enter c,if you  want the combination of the array\n");
    scanf("  %c",&ch);

    int *current=(int*) malloc(sizeof(int));
    int outsize=combinationn(k,n);
    int** out=(int**) malloc(sizeof(int*)*outsize);
    global_index=0;
    combination(n,k,arr,current,0,0,out);
    if(ch=='p')
    {
       for(int i=0 ; i <outsize ; i++)
       {
           permute( k,k, out[i],out);
       }
    }
    else if(ch =='c')
    {
        print(outsize,k,out );
    }
    free(arr) ; 
    return 0 ; 
}

