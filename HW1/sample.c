#include<stdio.h>
#include"mysort.h"
#include<stdlib.h>
int main (void)
{
    int arr[10]={3,5,7,2,3,1,4,5,2,1};
    printf("The unsorted array is: \n");
    print(arr,10);
    printf("The array sorted using bubble sort is: \n");
    bubble(arr,10);
    print(arr,10);
    printf("The array sorted using selection sort  is: \n");
    selection(arr,10);
    print(arr,10);
    printf("The array sorted using inserction sort is: \n");
    inserction(arr,10);
    print(arr,10);
    system("pause");
    return 0 ; 
}