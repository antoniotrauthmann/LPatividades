#include <stdio.h>
int main(){
    int idade, contador=0;
    char op;

    do
    {
        printf("\n digite sua idade: ");
        scanf("%d",&idade);

        if(idade >=18 ){
            printf("\n maior de idade!");
        }
        else{
            printf ("\n menor de idade");
        }
        contador = contador + 1;
        
        printf ("\n deseja continuar? (s) ou (n)");
        scanf(" %c",&op);
    
    } while (op == 's');

    printf("\n numero de entradas: %d ", contador);
    
}