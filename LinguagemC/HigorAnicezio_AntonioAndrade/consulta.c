#include <stdio.h>
#include <string.h>
#include "oficina.h"
#include "servico.h"

void busca_proprietario(servico servicos[],int total_servicos, const char *nome){
    printf("-----Servicos por Proprietario-----\n");
    int encontrado = 0;

    for (int i = 0; i < total_servicos; i++)
    {
        if (strcmp(servicos[i].proprietario, nome) == 0 )
        {
            printf("Data: %s |Mecanico: %s| Servico: %s\n",servicos[i].data, servicos[i].mecanico, servicos[i].tipo_servico);
            encontrado = 1;
        }       
    }
    if (!encontrado)
    {
        printf("Servico nao encontrado.\n");
    }
}

void busca_mecanico(servico servicos[],int total_servicos, const char *nome){
    printf("-----Servicos por Mecanico-----\n");
    int encontrado = 0;

    for (int i = 0; i < total_servicos; i++)
    {
        if (strcmp(servicos[i].mecanico, nome) == 0)
        {
            printf("Data: %s |Mecanico: %s| Servico: %s\n", servicos[i].data, servicos[i].mecanico, servicos[i].tipo_servico);
            encontrado = 1;
        }
    }
    if (!encontrado)
    {
        printf("Servico ou Mecanico nao encontrado.\n");
    }
    

}