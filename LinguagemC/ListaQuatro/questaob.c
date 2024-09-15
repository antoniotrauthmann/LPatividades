#include <stdio.h>
int main(){
    float tinta1,tinta2,areaquadr;
    int entrada;

    printf("\n qual tinta usar? 1 para tinta acrilica e 2 para tinta lavavel");
    scanf("%d",&entrada);

    if (entrada == 1)
    {
        printf("\n tinta acrilica!\ndigite a area do retangulo:");
        scanf("%f",&areaquadr);

        tinta1 = (10*areaquadr);
        printf("\no custo sera de: %f",tinta1);
    }
    else{
        printf("\n tinta lavavel!\ndigite a area do retangulo:");
        scanf("%f",&areaquadr);

        tinta2 = (15*areaquadr);
         printf("\no custo sera de: %f",tinta2);
    }
    

}