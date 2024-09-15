/////////questão 1/////////

#include <stdio.h>
int main() {

    int i1,i2,i3,p1,p2,p3;
    float media_idade,media_peso;
    char nome [20];

    ///primeira pessoa///
    
    printf("Olá,digite seu nome: ");
        scanf("%s",nome);{
        printf("\n Sua idade: ");
        scanf("%d",&i1);
        printf("\n Seu peso: ");
        scanf("%d",&p1);
    }
    ///segunda pessoa///

    printf("Olá,digite seu nome: ");
        scanf("%s",nome);{
        printf("\n Sua idade: ");
        scanf("%d",&i2);
        printf("\n Seu peso: ");
        scanf("%d",&p2);
    }

    ///terceira pessoa///

    printf("Olá,digite seu nome: ");
        scanf("%s",nome);{
        printf("\n Sua idade: ");
        scanf("%d",&i3);
        printf("\n Seu peso: ");
        scanf("%d",&p3);
    }

    ///medias de peso e idade///

    media_idade = (float) (i1+i2+i3)/3;

    printf ("A idade media é: %f ",media_idade);

    media_peso = (float) (p1+p2+p3)/3;

    if (media_peso > 55 )
        printf("media de peso ultrapassa 55 Kg");

        else{ 
            printf("sua media de peso é: %f", media_peso);
        }     

    

}
