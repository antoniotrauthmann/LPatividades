#include <stdio.h>
#include <string.h>

#include "servico.h"
#include "oficina.h"

void registro_servico(servico servicos[],int *total_servicos,veiculo veiculos[],int total_veiculos){
    
    if (*total_servicos >= max_servicos)
    {
        printf("limite de servicos atingido.\n");
    }

        servico s;
        printf("------Ordem de Servico------\n");

        printf("Placa do veiculo:\n");
        scanf(" %9s",s.placa);

        if (busca_placa(veiculos, total_veiculos, s.placa) == -1)
        {
            printf("Veiculo nao registrado.\n");
        }

        printf("Digite a data: dia/mes/ano,\n");
        scanf(" %[^\n]",s.data);
        printf("Digite a hora: horas:minutos.\n");
        scanf(" %[^\n]", s.hora);
        printf("Tipo de servico:\n");
        scanf(" %[^\n]",s.tipo_servico);
        printf("Digite o nome do mecanico responsavel:\n");
        scanf(" %[^\n]",s.mecanico);
        printf("Digite o nome do proprietario:\n");
        scanf(" %[^\n]",s.proprietario); 

        servicos [*total_servicos] = s;
        (*total_servicos)++;

        FILE *f = fopen("servicos.txt", "a");
        if (f == NULL) {
            printf("Erro ao abrir o arquivo.\n");
            return;
        }

        fprintf(f, "%s %s %s %s %s\n",s.data, s.hora, s.tipo_servico, s.mecanico, s.placa);

        fclose(f);
        printf("Servico Registrado.\n");

}

void alterar_servico(servico servicos[],int *total_servicos){
    
    servico s;
    if (*total_servicos == 0)
    {
        printf("Nenhum servico registrado.\n");
    }

    char placa[10];

    printf("Digite a placa do veiculo cadastrado para alterar o servico.\n");
    scanf("%s",placa);

    int encontrado = 0;
    for (int i = 0; i < total_servicos; i++)
    {
        if (strcmp(servicos[i].placa, placa) == 0) {
            printf("--- Servico Encontrado ---\n");
            printf("Data: %s | Hora: %s | Mecanico: %s | Servico: %s\n",servicos[i].data, servicos[i].hora,servicos[i].mecanico, servicos[i].tipo_servico);

            printf("--- Novos Dados---\n");
            printf("Digite a data: dia/mes/ano,\n");
            scanf(" %[^\n]", s.data);   
            printf("Digite a hora: horas:minutos.\n");
            scanf(" %[^\n]", s.hora);
            printf("Tipo de servico:\n");
            scanf(" %[^\n]",s.tipo_servico);
            printf("Digite o nome do mecanico responsavel:\n");
            scanf(" %[^\n]",s.mecanico);
            printf("Digite o nome do proprietario:\n");
            scanf(" %[^\n]",s.proprietario);

            printf("Servico alterado.\n");
            encontrado = 1;

            int opc;
            printf("Deseja salvar a alteracao? [0]sim|[1]nao.\n");
            scanf("%d",&opc);

            if (opc == 0)
            {
                FILE *f = fopen("servicos.txt", "w");
                for (int i = 0; i < total_servicos; i++) {
                    fprintf(f, "%s;%s;%s;%s;%s\n",servicos[i].data, servicos[i].hora,servicos[i].tipo_servico, servicos[i].mecanico,servicos[i].placa);
                }
                fclose(f);
            }
            break;
        }
    }

    if (!encontrado)
    {
        printf("Nenhum servico encontrado pela placa %s.\n",placa);
    }
    
}

void listagem_servico(servico servicos[],int total_servicos){

    printf("---- Listagem da Ordem de Servico----\n");
    for (int i = 0; i < total_servicos; i++)
    {
        printf("Ordem %d:\n",i+1);
        printf("Veiculo: %s.\n", servicos[i].placa);
        printf("Data: %s |Horario: %s.\n", servicos[i].data, servicos[i].hora);
        printf("Proprietario: %s.\n",servicos[i].proprietario);
        printf("---------------------------\n");
        printf("Mecanico Responsavel: %s.\n", servicos[i].mecanico);
        printf("Tipo de Servico: %s.\n",servicos[i].tipo_servico);
    } 
}