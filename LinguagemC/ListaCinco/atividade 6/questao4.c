//////soma indeterminada de numeros inteiros/////
#include<stdio.h>
int main(){
    int soma=0,numero1,numero2;
    char op;

    do
    {
        printf("digite o primeiro numero inteiro da sua soma:\n");
        scanf("%d",&numero1);
        printf("digite o segundo numero inteiro:\n");
        scanf("%d",&numero2);

        soma = numero1 + numero2;

        printf("o resultado e: %d\n",soma);
        printf("deseja continuar? digite s ou n\n");
        scanf(" %c",&op);
    } 
    while (op == 's');
    
}