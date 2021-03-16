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
int main(void)
{
    srand(time(NULL));
    struct personal std[500];
    FILE *namelist = fopen("name.txt","rb" );
    FILE *gendata= fopen("gen.bin","wb" );
    char namepool[500][20];
    for(int i=0 ;  i<500 ; i++)
    {
        fgets(namepool[i],20,namelist);
    }
    for(int i=0 ;  i<500 ; i++)
    {
         int  a=rand() % 500  ;
         strcpy(std[i].name,namepool[a]);
         std[i].weight=30+rand()%80 ;
         std[i].office=rand()%100;
    } 
    fwrite(std, sizeof(struct personal),500,gendata);
    fclose(namelist);
    fclose(gendata);
    return (0); 
}
