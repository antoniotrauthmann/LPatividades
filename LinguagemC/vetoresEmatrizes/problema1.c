#include <stdio.h>
#define dias 5
#define horas 24
#define phalerta 8
int main(){
    int numero_dias=0,sinal_alertaph=0,sinal_alerta_temperatura=0,dias_acima_temperatura=0;
    int t=0;
    float ph_diario[dias];
    float temperatura[horas],temperatura_media,soma_temperaturas;
    char op;
   
    do
    {
        printf("digite o PH do dia\n");
        scanf("%f",&ph_diario[t]);
        t++;
        
        if (ph_diario[t]>phalerta)
        {
            printf("ph acima do permitido\nemitindo sinal de alerta...\n");
            sinal_alertaph++;
        }
        
        for (int i = 0; i < horas; i++)
        {
            printf("digite a temperatura\n");
            scanf("%f",&temperatura[i]);
            i++;
            if (temperatura[i] >90 && temperatura[i] < 110)
            {
                printf("temperatura acima do normal\n iniciar resfriamento...\n");
            }
            else if (temperatura[i] > 110)
            {
                printf("temperatura acima do permitido\nemitindo sinal de alerta...\n");
                sinal_alerta_temperatura++;
            }

            soma_temperaturas += temperatura[i]; 
            temperatura_media = soma_temperaturas/horas;

            if (temperatura_media > 95)
            {
                dias_acima_temperatura++;
            }
            
        } 
        
        numero_dias++;
        printf("a temperatura media foi de: %.2f\n",temperatura_media);
        printf("deseja continuar? digite s ou n\n");
        scanf(" %c",&op);

    } while (op == 's' && numero_dias <5 );

    printf("numero de dias de auditoria:%d\n",numero_dias);
    printf("numero de sinais de alerta por temperatura acima de 110 graus:%d\n",sinal_alerta_temperatura);
    printf("numero de sinais de alerta por ph acima de 8:%d\n",sinal_alertaph);
    printf("numero de dias com temperatura media acima de 95 graus:%d\n",dias_acima_temperatura);

for (int i = 0; i < dias; i++)
{
    printf("ph de cada dia em ordem cronologica:%f",ph_diario[i]);
    i++;
}




    
       
       
        
        
    
    



}