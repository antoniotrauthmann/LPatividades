#include <stdio.h>
#include "oficina.h"
#include "servico.h"
#include "relatorio.h"

veiculo veiculos[max_veiculos];
int total_veiculos = 0;

servico servicos[max_servicos];
int total_servicos = 0;

int main(){

    carregar_veiculos(veiculos, &total_veiculos);
    carregar_servicos(servicos, &total_servicos);

    int opc;

    do
    {
        printf("-----MENU-----\n");
        printf("[1]Cadastrar Veiculo.\n");
        printf("[2]Registrar Ordem de Servico.\n");
        printf("[3]Consulta por Proprietario.\n");
        printf("[4]Consulta por Mecanico Responsavel.\n");
        printf("[5]Alterar Ordens de Servico.\n");
        printf("[6]Listagem de Ordem de Servico.\n");
        printf("[7]Gerar Relatorio.\n");
        printf("[0]Sair do Menu.\n");
        scanf("%d",&opc);

        switch (opc)
        {

        char nome[50];
        
        case 1:
            cadastrar_veiculo(veiculos,&total_veiculos);
            break;
        
        case 2:
            registro_servico(servicos,&total_servicos,veiculos,total_veiculos);
            break;
        
        case 3:
            
            printf("Digite o nome do proprietario: ");
            scanf(" %49[^\n]", nome);
            busca_proprietario(servicos, total_servicos, nome);
            break;
        
        case 4:
            
            printf("Digite o nome do mecanico: ");
            scanf(" %49[^\n]", nome);
            busca_mecanico(servicos, total_servicos, nome);
            break;
        
        case 5:
            alterar_servico(servicos,&total_servicos);
            break;
        
        case 6:
            listagem_servicos(servicos,total_servicos);
            break;
        
        case 7:
            int opc2;
            
            printf("---- Tipo de Relatorio ----\n");
            printf("[1]Tipo de Servico.\n");
            printf("[2]Por Mecanico Responsavel.\n");
            printf("[3]Sair.\n");
            scanf("%d", &opc2);

            char str_temp[50];

            switch (opc2)

            
            {
            case 1:
                printf("Tipo de Servico:\n");
                scanf(" %49[^\n]",str_temp);
                relatorio_servico( servicos, total_servicos, str_temp);
                break;
            case 2:
                printf("Nome do Mecanico Responsavel:\n");
                scanf(" %49[^\n]",str_temp);
                relatorio_mecanico(servicos, total_servicos, str_temp);

                break;
            case 3:
                printf("Saindo do Menu de Relatorio...\n");
                break;
            
            default:
                printf("Opcao Invalida.\n");
                break;
            }

        break;

        default:
            printf("Opcao invalida.\n");
        break;

        }

    } while (opc !=0 );
    
}