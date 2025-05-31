#include <stdio.h>
#include <string.h>
#include "oficina.h"
#include "servico.h"

void busca_proprietario(servico servicos[],int total_servicos, const char *nome){
    printf("-----Servicos por Proprietario-----\n");
    for (int i = 0; i < total_servicos; i++)
    {
        if (strcmp(servicos[i].proprietario, nome) == 0 )
        {
            printf("Data: %s |Mecanico: %s| Servico: %s\n");
        }
        else
        printf("Propietario nao encontrado.");
        
        
    }
    
}

void busca_mecanico(servico servicos[],int total_servicos, const char nome){
    printf("-----Servicos por Mecanico-----\n");
    for (int i = 0; i < total_servicos; i++)
    {
        if (strcmp(servicos[i].mecanico, nome) == 0)
        {
            printf("Data: %s |Mecanico: %s| Servico: %s\n");
        }
        else
        printf("Servico ou mecanico nao encontrado.\n");
        
    }
    

}