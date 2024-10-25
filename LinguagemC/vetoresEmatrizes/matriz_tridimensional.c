#include <stdio.h>
#define anos 4
#define meses 12
#define pontos_recebimento 2

int main(){
    int pacotes[anos][meses][pontos_recebimento];
    int pacotes_mensais = 0,pacotes_anuais = 0, pacotes_totais = 0;
    float media_mensal;

    for (int i = 0; i < anos; i++)
    {
        for (int o = 0; o < meses; o++)
        {
            for (int j = 0; j < pontos_recebimento; j++)
            {
                printf("digite o numero de pacotes recebidos no ponto atual/0 curitiba e 1 sao paulo %d",j);
                scanf("%d",&pacotes[i][o][j]);
            } 
        } 
    }

    printf("menu\n");
    printf("1.relatorio por mes\n");
    printf("2.relatorio por ano\n");
    printf("3.relatorio media mensal\n");
    printf("4.relatorio geral\n");

    int menu;
    scanf("%d",&menu);
    int i=0,o=0,j=0;
    switch (menu)
    {
    case 1:
        printf("digite o ano que deseja:\n");
        scanf("%d",i);
        printf("digite o mes que deseja:\n");
        scanf("%d",&o);
        printf("digite o posto /0 para curitiba e 1 para sao paulo.\n");
        scanf("%d",&j);

        printf("numero de pacotes: %d\n",pacotes[i][o][j]);
        break;
    case 2:
        i=0,o=0,j=0;
        printf("digite o ano:\n");
        scanf("%d",i);
        printf("digite o posto:\n");
        scanf("%d",&j);

        for ( o = 0; o < meses; o++)
        {
            pacotes_anuais += pacotes[i][o][j];
        }
        printf("total de pacotes recebidos neste ano no posto selecionado foi de: %d\n",pacotes_anuais);
        break;
    case 3:

        for ( i = 0; i < anos; i++)
        {
            for ( o = 0; o < meses; o++)
            {
                for ( j = 0; j < pontos_recebimento; j++)
                {
                    pacotes_totais +=  pacotes[i][o][j];
                }
                pacotes_mensais += pacotes_totais;
            }
            media_mensal = pacotes_mensais/meses;
            printf("pacotes mensais do ano%d: %d\n",i,pacotes_mensais);

            if (media_mensal > 500)
            {
                printf("media acima de 500 pacotes\n");
            }
            else if (media_mensal < 90)
            {
                printf("media abaixo de 90 pacotes\n");
            }
            else if(media_mensal< 501 && media_mensal> 90)
            {
                printf("media mensal dentro do esperado\n");
            } 
        }      
        break;
    case 4:
        
        break;
    default:
        break;
    }

}