#include <stdio.h>
#include <string.h>

#include "servico.h"
#include "oficina.h"

void carregar_servicos(servico servicos[],int *total_servicos){
    FILE *f = fopen("servicos.txt","r");

    if (f == NULL)
    {
        *total_servicos = 0;
        return;
    }

    *total_servicos = 0;
    char linha[200];

    while (fgets(linha,sizeof(linha),f)!= NULL && *total_servicos < max_servicos)
    {
        sscanf(linha,"%10[^;];%5[^;];%29[^;];%49[^;];%49[^;];%9s", servicos[*total_servicos].data, servicos[*total_servicos].hora, servicos[*total_servicos].tipo_servico, servicos[*total_servicos].mecanico,servicos[*total_servicos].proprietario, servicos[*total_servicos].placa);

        (*total_servicos)++;
    }
    fclose(f);      
}

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
            return;
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

        fprintf(f, "%s;%s;%s;%s;%s;%s\n",s.data, s.hora, s.tipo_servico, s.mecanico, s.proprietario,s.placa);

        fclose(f);
        printf("Servico Registrado.\n");

}

void alterar_servico(servico servicos_array[], int *total_servicos_ptr) {
    if (*total_servicos_ptr == 0) {
        printf("Nenhum servico registrado.\n");
        return;
    }

    char placa_busca[10];
    printf("Digite a placa do veiculo para alterar o servico: ");
    scanf("%9s", placa_busca); 

    FILE *file_servico = fopen("servicos.txt", "r");
    FILE *file_temp = fopen("temp.txt", "w");

    if (file_servico == NULL || file_temp == NULL) {
        printf("Erro ao tentar abrir arquivos.\n");
        if (file_servico) fclose(file_servico);
        if (file_temp) fclose(file_temp);
        return;
    }

    int encontrado = 0;
    int alterado_e_salvo = 0;
    char linha[200];
    servico s_temp;

    while (fgets(linha, sizeof(linha), file_servico) != NULL) {
         sscanf(linha, "%10[^;];%5[^;];%29[^;];%49[^;];%49[^;];%9[^;\n]",s_temp.data, s_temp.hora, s_temp.tipo_servico,s_temp.mecanico, s_temp.proprietario, s_temp.placa);

        if (strcmp(s_temp.placa, placa_busca) == 0 && !alterado_e_salvo) {
            encontrado = 1;
            printf("--- Servico Encontrado ---\n");
            printf("Data: %s | Hora: %s | Mecanico: %s | Servico: %s | Proprietario: %s | Placa: %s\n",
                   s_temp.data, s_temp.hora, s_temp.mecanico, s_temp.tipo_servico, s_temp.proprietario, s_temp.placa);  

            printf("--- Novos Dados---\n");
            printf("Digite a data (dd/mm/aaaa): ");
            scanf(" %10[^\n]", s_temp.data);
            printf("Digite a hora (hh:mm): ");
            scanf(" %5[^\n]", s_temp.hora);
            printf("Tipo de servico: ");
            scanf(" %29[^\n]", s_temp.tipo_servico);
            printf("Nome do mecanico responsavel: ");
            scanf(" %49[^\n]", s_temp.mecanico);
            printf("Nome do proprietario: ");
            scanf(" %49[^\n]", s_temp.proprietario);

            int opc_salvar;
            printf("Deseja salvar a alteracao? [0]sim | [1]nao.\n");
            scanf("%d", &opc_salvar);

            if (opc_salvar == 0) {
                fprintf(file_temp, "%s;%s;%s;%s;%s;%s\n",s_temp.data, s_temp.hora, s_temp.tipo_servico,s_temp.mecanico, s_temp.proprietario, s_temp.placa);
                printf("Servico alterado e marcado para salvar.\n");
                alterado_e_salvo = 1;
            } else {
                fputs(linha, file_temp);
                printf("Alteracao descartada.\n");
            }
        } else {
            fputs(linha, file_temp);
        }
    }

    fclose(file_servico);
    fclose(file_temp);

    if (encontrado && alterado_e_salvo) {
        remove("servicos.txt");
        rename("temp.txt", "servicos.txt");
        printf("Arquivo de servicos atualizado.\n");
        carregar_servicos(servicos_array, total_servicos_ptr);
    } else if (encontrado && !alterado_e_salvo) {
        printf("Nenhuma alteracao foi salva.\n");
        remove("temp.txt");
    }
    else {
        printf("Nenhum servico encontrado para a placa: %s\n", placa_busca);
        remove("temp.txt");
    }
}

void listagem_servicos(servico servicos[],int total_servicos){

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