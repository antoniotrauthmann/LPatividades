////Estrutura de Repetição////
#include <stdio.h>
int main (){
    int i,j;

    for (int i = 1; i < 3; i++)
    {
        for (int j = 1; j <=3 ; j++)
        {
            printf ("\n  teste");
        }
        printf("%d",j);
        
    }
    printf("%d,%d",i,j);
    
}