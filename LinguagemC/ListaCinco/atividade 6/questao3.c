#include <stdio.h>
int main(){
    int idade,conj_idade=0, contador=0;
    float media;
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
    
    conj_idade+= idade;
    media = conj_idade/contador;
    printf("\n numero de entradas: %d ", contador);
    printf ("\n media das idades: %f",media);

    
}