#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int num=0; 

void SolveQueen(int* c , int n )
{
    if(n==8)
    {
        num++ ; 
        printf("Case:   %d",num); 
        for(int i=0 ; i<64 ;i++)
        {
            if(i%8==0)
                printf("\n"); 
            if(c[i] <2) printf("  "); 
            if(c[i]==2) printf("%d ",  1); 
    
        }
        printf("\n\n");
        free(c); 
        return ; 
    }

    for(int i=n*8; i<8*n+8  ; i++)
    {
        if(c[i]!=0 ) continue ; 
        int* tmp=(int*) malloc(64*sizeof(int)); 
        memcpy((void*)   tmp,(const void*) c,sizeof(int)*64 ); 
        tmp[i]=2; 
        int aaa=i ; 
        int leftnum= i%8 ; 
        int rightnum = 7-i%8;
        int right_tmp=1 , left_tmp=1 ; 
        aaa+=8; 
        while(aaa<64  )
        {
            tmp[aaa]=1 ; 
            if(right_tmp <= rightnum)
            {
                tmp[aaa+right_tmp]=1; 
                right_tmp++ ; 
            } 
            if(left_tmp <= leftnum)
            {
                tmp[aaa-left_tmp]=1;
                ++left_tmp;
            }
            aaa+=8 ;
        }
        SolveQueen(tmp,n+1);
    }
}

int main(void)
{
    int matrix[64]={0};
    SolveQueen(matrix,0);
    printf("\n%d\n",num);
    return 0 ;
}
