////////questao3////////

#include <stdio.h>
int main() {
    int l1,l2,l3;

    printf ("digite os lados do triangulo: ");

    scanf("%d,%d,%d",&l1,&l2,&l3);

    if (l1 == l2 && l2 == l3)
        printf ("triangulo equilatero!");

        else if (l1 == l2 || l1 == l3 && l2 != l1)
            printf( "triangulo isosceles");

            else{
                printf ("triangulo escaleno");
            }
        
}