#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
struct personal
{
    char name[20];
    int  weight;
    int  office ;
};

//Compare office number
int cmpoff(const void* a , const void* b)
{
    struct personal* data0=(struct personal*)  a;
    struct personal* data1=(struct personal*)  b; 
    if(data0->office <data1->office) return -1 ;
    if(data0->office > data1->office) return 1;
    if(data0->office == data1->office) return 0 ;
}
//Printing the structure personal
int printing(void* p)
{
    struct personal* d =(struct personal *) p;
    for(int i=0 ; i<500; i++)
    {
        printf("{\n Name:%s Weights:%d \n Office:%d \n}\n",d[i].name,d[i].weight,d[i].office);
    }
}
//Compare name via dictionary order
int cmpname(const void* a , const void* b)
{
   return strcmp((char*)a,(char*)b);
}
// Compare the weight 
int cmpweight(const void* a , const void* b)
{
    struct personal* data0=(struct personal*)  a;
    struct personal* data1=(struct personal*)  b; 
    if(data0->weight <data1->weight ) return -1 ;
    if(data0->weight > data1->weight) return 1;
    if(data0->weight == data1->weight) return 0 ;
}
int main(void)
{
    FILE* data=fopen("gen.bin","rb" );
    struct personal d[500];
    fread(d,sizeof(struct personal) ,500,data  );
    qsort(d,500,sizeof(struct personal),cmpoff);
    printing(d);
    qsort(d,500,sizeof(struct personal),cmpweight);
    printing(d);
    qsort(d,500,sizeof(struct personal),cmpname);
    printing(d);
}

