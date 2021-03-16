#include <stdio.h>
#include "mysort.h"

void selection(int *nums , int arrSize)
{
    int tmp;
    for(int i=0 ; i<arrSize ; ++i)
    {
        for(int j=i+1 ; j<arrSize ; ++j)
        {
            if(nums[i]>nums[j])
            {
                tmp=nums[i];
                nums[i]=nums[j];
                nums[j]=tmp;
            }
        }
    }
}


void inserction(int *nums,int arrSize)
{
    for(int i=0 ; i<arrSize ; i++)
    {
        int j,q=nums[i];
        for( j=0 ; j<i ; ++j)
            if(nums[i] < nums[j]) break;
        for(int k = i ; k>j ; --k)
            nums[ k ] = nums[k-1];
        nums[j]=q;
    }
}


void print(int *arr,int arrSize)
{
    for(int z=0 ; z<arrSize ; z++) printf("%d ",arr[z]);
    printf("\n");
}

void bubble(int* arr,int arrSize)
{
    for(int i=0 ; i<arrSize ; i++)
    {
        for(int j=arrSize-1 ; j>i;--j)
        {
            if(arr[j] <  arr[j-1])
            {
                int tmp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=tmp;
            }
        }
    }
}
