#ifndef servico_h
#define servico_h

#include "oficina.h"

#define max_servicos 200

typedef struct
{
    char data[11];
    char hora[6];
    char tipo_servico[30];
    char mecanico[50];
    char proprietario[50];
    char placa[10];
}servico;

void carregar_servicos(servico servicos[], int *total_servicos);
void registro_servico(servico servicos[],int *total_servicos,veiculo veiculos[],int total_veiculos);
void busca_proprietario(servico servicos[],int total, const char *nome);
void busca_mecanico(servico servicos[],int total, const char *nome);
void listagem_servicos(servico servicos[],int total_servicos);
void alterar_servico(servico servicos[], int *total_servicos);

#endif