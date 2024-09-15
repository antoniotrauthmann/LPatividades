////////////questao2////////////

#include <stdio.h>
int main() {
    int idade;

    printf ("Digite sua idade: ");
    scanf("%d",&idade);

        if (idade >= 18)
        printf ("eleitor obrigatorio");
        
         else if (idade>16 && idade<18)
         printf ("eleitor opcional");
        
         else
         printf("nao eleitor");
        

    

    return 0;
}