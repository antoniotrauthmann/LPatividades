#include <stdio.h>
#include <string.h>
#include "oficina.h"

void cadastrar_veiculo(veiculo veiculos[],int *total_veiculos){
    
    if (*total_veiculos >= max_veiculos)
    {
        printf("limite de veiculos atingido.\n");
        return;
    }
    
    veiculo v;

    printf("---------Cadastro de Veiculo-----------\n");
    printf("Tipo de veiculo: \n|1-Carro|2-Moto|3Caminhao.\n");
    scanf("%d",&v.tipo);
    printf("Placa: \n");
    scanf("%9s",v.placa);
    printf("Ano:\n");
    scanf("%d",&v.ano);
    printf("Digite o modelo do veiculo: \n");
    scanf(" %[^\n]",v.modelo);
    printf("Digite o nome da marca: \n");
    scanf(" %[^\n]",v.marca);
    printf("Digite o nome do proprietario: \n");
    scanf(" %[^\n]",v.proprietario);

    veiculos[*total_veiculos] = v;
    (*total_veiculos)++;

    FILE *f = fopen("veiculos.txt", "a");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(f, "%d %s %d %s %s %s\n",v.tipo, v.placa, v.ano, v.modelo, v.marca, v.proprietario);

    fclose(f);

    printf("Veiculo cadastrado.\n");
}

int busca_placa(veiculo veiculos[],int total_veiculos,const char *placa){
    for (int i = 0; i < total_veiculos; i++)
    {
        if (strcmp(veiculos[i].placa, placa) == 0)
        {
            return i;
        }
        
    }
    return -1;
    
}