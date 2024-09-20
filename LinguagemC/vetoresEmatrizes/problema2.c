#include <stdio.h>
#include <string.h>

#define SETORES_UNIDADE1 2
#define SETORES_UNIDADE2 5

typedef struct {
    int funcionarios;
    char cor_camisa[10];
    char tecido_calca[10];
} setor;

typedef struct {
    setor setores[SETORES_UNIDADE2];
} unidade;

unidade unidades[2];

void coletar_dados() {
    for (int unidade = 0; unidade < 2; unidade++) {
        int max_setores = (unidade == 0) ? SETORES_UNIDADE1 : SETORES_UNIDADE2;
        for (int setor = 0; setor < max_setores; setor++) {
            printf("Digite o numero de funcionarios do setor %d da unidade %d: ", setor + 1, unidade + 1);
            scanf("%d", &unidades[unidade].setores[setor].funcionarios);
            printf("Digite a cor da camiseta (branca, preta ou azul) do setor %d: ", setor + 1);
            scanf(" %s", unidades[unidade].setores[setor].cor_camisa);
            printf("Digite o tecido da calca (tactel ou moletom) do setor %d: ", setor + 1);
            scanf(" %s", unidades[unidade].setores[setor].tecido_calca);
        }
    }
}

void emicao_relatorio() {
    char continuar[4];
    do {
        printf("Escolha o relatorio desejado:\n");
        printf("======================================\n");
        printf("1. Total de funcionários da unidade\n");
        printf("2. Total de funcionários do setor\n");
        printf("3. Uniforme do setor\n");
        printf("4. Maior unidade\n");
        printf("5. Total de encomendas\n");
        int alternativa;
        scanf("%d", &alternativa);

        switch (alternativa) {
        case 1: {
            printf("Digite o numero da unidade: \n");
            int unidade;
            scanf("%d", &unidade);
            int total_funcionario = 0;
            int max_setores = (unidade == 1) ? SETORES_UNIDADE1 : SETORES_UNIDADE2;

            for (int setor = 0; setor < max_setores; setor++) {
                total_funcionario += unidades[unidade - 1].setores[setor].funcionarios;
            }

            printf("Total de funcionarios da unidade %d: %d\n", unidade, total_funcionario);
            break;
        }
        case 2: {
            printf("Digite o numero da unidade: \n");
            int unidade;
            scanf("%d", &unidade);
            printf("Digite o numero do setor: \n");
            int setor;
            scanf("%d", &setor);
            printf("Total de funcionarios do setor %d da unidade %d: %d\n", setor, unidade, unidades[unidade - 1].setores[setor - 1].funcionarios);
            break;
        }
        case 3: {
            printf("Digite o numero da unidade: \n");
            int unidade;
            scanf("%d", &unidade);
            printf("Digite o numero do setor: \n");
            int setor;
            scanf("%d", &setor);
            printf("Uniforme do setor %d da unidade %d:\n=================\n Camiseta %s, Calça %s\n", setor, unidade, unidades[unidade - 1].setores[setor - 1].cor_camisa, unidades[unidade - 1].setores[setor - 1].tecido_calca);
            break;
        }
        case 4: {
            int total_unidade1 = 0;
            int total_unidade2 = 0;

            for (int setor = 0; setor < SETORES_UNIDADE1; setor++) {
                total_unidade1 += unidades[0].setores[setor].funcionarios;
            }
            for (int setor = 0; setor < SETORES_UNIDADE2; setor++) {
                total_unidade2 += unidades[1].setores[setor].funcionarios;
            }

            if (total_unidade1 > total_unidade2) {
                printf("A unidade 1 tem mais funcionarios. \n");
            } else if (total_unidade2 > total_unidade1) {
                printf("A unidade 2 tem mais funcionarios. \n");
            } else {
                printf("As unidades têm o mesmo número de funcionarios. \n");
            }
            break;
        }
        case 5: {
            int total_brancas = 0, total_pretas = 0, total_azuis = 0;
            int total_tactel = 0, total_moletom = 0;

            for (int unidade = 0; unidade < 2; unidade++) {
                int max_setores = (unidade == 0) ? SETORES_UNIDADE1 : SETORES_UNIDADE2;

                for (int setor = 0; setor < max_setores; setor++) {
                    int funcionarios = unidades[unidade].setores[setor].funcionarios;

                    if (strcmp(unidades[unidade].setores[setor].cor_camisa, "branca") == 0) {
                        total_brancas += funcionarios * 2;
                    } else if (strcmp(unidades[unidade].setores[setor].cor_camisa, "preta") == 0) {
                        total_pretas += funcionarios * 2;
                    } else if (strcmp(unidades[unidade].setores[setor].cor_camisa, "azul") == 0) {
                        total_azuis += funcionarios * 2;
                    }

                    if (strcmp(unidades[unidade].setores[setor].tecido_calca, "tactel") == 0) {
                        total_tactel += funcionarios * 2;
                    } else if (strcmp(unidades[unidade].setores[setor].tecido_calca, "moletom") == 0) {
                        total_moletom += funcionarios * 2;
                    }
                }                   
            }
            printf("Total de encomendas:\n====================\n");
            printf("Camisetas brancas: %d\n", total_brancas);
            printf("Camisetas pretas: %d\n", total_pretas);
            printf("Camisetas azuis: %d\n", total_azuis);
            printf("Calças tactel: %d\n", total_tactel);
            printf("Calças moletom: %d\n", total_moletom);
            break;
        }
        default:
            printf("Opção inválida...\ntente novamente.\n");
            break;        
        }
        printf("Deseja realizar outro relatório? sim/não: \n");
        scanf(" %s", continuar);
    } while (strcmp(continuar, "sim") == 0);
}

int main() {
    coletar_dados();
    emicao_relatorio();
}