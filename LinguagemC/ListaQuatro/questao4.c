////questão 4////
#include <stdio.h>
int main(){
    float numero1,numero2,numeromaior,numeromenor;
    float soma,divisao,subtracao;
    char alternativas;

    printf("digite o primeiro numero da operacao que deseja realizar:\n");
    scanf("%f",&numero1);

    printf("digite o segundo numero:\n");
    scanf("%f",&numero2);

    if (numero1 > numero2)
    {
       numeromaior = numero1;
       numeromenor = numero2;
    }
    else{
        numeromaior = numero2;
        numeromenor = numero1;
    }
    
    printf("qual das operacoes deseja realizar? somar = o,subtrair = s ou dividir = d.");
    scanf(" %c",&alternativas);

    switch (alternativas)
    {
    case 'o':
        
        soma = numeromaior + numeromenor;
        printf("o resultado da operacao e: %f",soma);
        break;
    
    

    case 's':
        
        subtracao = numeromaior - numeromenor;
        printf("o resultado da operacao e: %f",subtracao);
        break;

    case 'd':
        
        divisao = numero1 / numero2;
        printf("o resultado da operacao e: %f",divisao);
        break;
    }
}