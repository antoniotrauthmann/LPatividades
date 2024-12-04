#include <stdio.h>
#include <stdlib.h>

#define MIN_ENTREVISTAS 20
#define MAX_ENTREVISTAS 30
#define MAX_MESES 3
#define FILENAME "entrevistas.bin"

typedef struct {
    int candidato_presidencia;
    int candidato_governo;
    int idade;
    int faixa_salarial;
} Entrevista;

// Função para ler os dados do arquivo binário
void ler_dados(Entrevista entrevistas[MAX_MESES][MAX_ENTREVISTAS]) {
    FILE *arquivo = fopen(FILENAME, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }
    fread(entrevistas, sizeof(Entrevista), MAX_MESES * MAX_ENTREVISTAS, arquivo);
    fclose(arquivo);
    printf("Dados lidos do arquivo com sucesso.\n");
}

// Função para exibir as porcentagens de votos para Presidência
void exibir_porcentagem_presidencia(Entrevista entrevistas[MAX_MESES][MAX_ENTREVISTAS]) {
    int votos_17 = 0, votos_26 = 0, votos_branco = 0, votos_indeciso = 0;
    for (int mes = 0; mes < MAX_MESES; mes++) {
        for (int i = 0; i < MAX_ENTREVISTAS; i++) {
            switch (entrevistas[mes][i].candidato_presidencia) {
                case 17: votos_17++; break;
                case 26: votos_26++; break;
                case 0: votos_branco++; break;
                default: votos_indeciso++; break;
            }
        }
    }
    int total_votos = votos_17 + votos_26 + votos_branco + votos_indeciso;
    printf("\nPorcentagem de votos para Presidência:\n");
    printf("Candidato 17: %.2f%%\n", (float)votos_17 / total_votos * 100);
    printf("Candidato 26: %.2f%%\n", (float)votos_26 / total_votos * 100);
    printf("Brancos: %.2f%%\n", (float)votos_branco / total_votos * 100);
    printf("Indecisos: %.2f%%\n", (float)votos_indeciso / total_votos * 100);
}

// Função para exibir as porcentagens de votos para Governo
void exibir_porcentagem_governo(Entrevista entrevistas[MAX_MESES][MAX_ENTREVISTAS]) {
    int votos_17 = 0, votos_26 = 0, votos_31 = 0, votos_branco = 0, votos_indeciso = 0;
    for (int mes = 0; mes < MAX_MESES; mes++) {
        for (int i = 0; i < MAX_ENTREVISTAS; i++) {
            switch (entrevistas[mes][i].candidato_governo) {
                case 17: votos_17++; break;
                case 26: votos_26++; break;
                case 31: votos_31++; break;
                case 0: votos_branco++; break;
                default: votos_indeciso++; break;
            }
        }
    }
    int total_votos = votos_17 + votos_26 + votos_31 + votos_branco + votos_indeciso;
    printf("\nPorcentagem de votos para Governo:\n");
    printf("Candidato 17: %.2f%%\n", (float)votos_17 / total_votos * 100);
    printf("Candidato 26: %.2f%%\n", (float)votos_26 / total_votos * 100);
    printf("Candidato 31: %.2f%%\n", (float)votos_31 / total_votos * 100);
    printf("Brancos: %.2f%%\n", (float)votos_branco / total_votos * 100);
    printf("Indecisos: %.2f%%\n", (float)votos_indeciso / total_votos * 100);
}

// Função para exibir os votos dos mais jovens (abaixo de 30 anos) no último mês
void exibir_intencao_presidencia_jovens(Entrevista entrevistas[MAX_MESES][MAX_ENTREVISTAS]) {
    int votos_17 = 0, votos_26 = 0, votos_indeciso = 0, votos_branco = 0;
    for (int i = 0; i < MAX_ENTREVISTAS; i++) {
        if (entrevistas[2][i].idade < 30) { // Último mês, ou seja, mês 2
            switch (entrevistas[2][i].candidato_presidencia) {
                case 17: votos_17++; break;
                case 26: votos_26++; break;
                case 0: votos_branco++; break;
                default: votos_indeciso++; break;
            }
        }
    }
    printf("\nIntenção de votos para Presidência entre os mais jovens (abaixo de 30 anos) no último mês:\n");
    printf("Candidato 17: %d votos\n", votos_17);
    printf("Candidato 26: %d votos\n", votos_26);
    printf("Brancos: %d votos\n", votos_branco);
    printf("Indecisos: %d votos\n", votos_indeciso);
}

// Função para exibir os votos por faixa salarial
void exibir_intencao_presidencia_por_faixa(Entrevista entrevistas[MAX_MESES][MAX_ENTREVISTAS]) {
    int votos_17_faixa1 = 0, votos_26_faixa1 = 0, votos_17_faixa2 = 0, votos_26_faixa2 = 0;
    int votos_17_faixa3 = 0, votos_26_faixa3 = 0;

    for (int mes = 0; mes < MAX_MESES; mes++) {
        for (int i = 0; i < MAX_ENTREVISTAS; i++) {
            if (entrevistas[mes][i].faixa_salarial == 1) {
                if (entrevistas[mes][i].candidato_presidencia == 17) votos_17_faixa1++;
                if (entrevistas[mes][i].candidato_presidencia == 26) votos_26_faixa1++;
            } else if (entrevistas[mes][i].faixa_salarial == 2) {
                if (entrevistas[mes][i].candidato_presidencia == 17) votos_17_faixa2++;
                if (entrevistas[mes][i].candidato_presidencia == 26) votos_26_faixa2++;
            } else if (entrevistas[mes][i].faixa_salarial == 3) {
                if (entrevistas[mes][i].candidato_presidencia == 17) votos_17_faixa3++;
                if (entrevistas[mes][i].candidato_presidencia == 26) votos_26_faixa3++;
            }
        }
    }
    printf("\nIntenção de votos para Presidência por faixa salarial:\n");
    printf("Faixa 1 (menos de 3 salários): Candidato 17: %d votos, Candidato 26: %d votos\n", votos_17_faixa1, votos_26_faixa1);
    printf("Faixa 2 (de 3 a 5 salários): Candidato 17: %d votos, Candidato 26: %d votos\n", votos_17_faixa2, votos_26_faixa2);
    printf("Faixa 3 (mais de 5 salários): Candidato 17: %d votos, Candidato 26: %d votos\n", votos_17_faixa3, votos_26_faixa3);
}

// Função principal que exibe o menu
int main() {
    Entrevista entrevistas[MAX_MESES][MAX_ENTREVISTAS];
    int opcao;
    
    // Lê os dados do arquivo
    ler_dados(entrevistas);

    do {
        printf("\nMENU DE CONSULTAS:\n");
        printf("[1] Intencao de votos para Presidencia\n");
        printf("[2] Intencao de votos para Governo\n");
        printf("[3] Intencao de votos para Presidencia entre os mais jovens\n");
        printf("[4] Intencao de votos para Presidencia por faixa salarial\n");
        printf("[0] Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                exibir_porcentagem_presidencia(entrevistas);
                break;
            case 2:
                exibir_porcentagem_governo(entrevistas);
                break;
            case 3:
                exibir_intencao_presidencia_jovens(entrevistas);
                break;
            case 4:
                exibir_intencao_presidencia_por_faixa(entrevistas);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}
