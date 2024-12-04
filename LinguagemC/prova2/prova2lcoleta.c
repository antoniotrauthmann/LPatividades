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

// Função para coletar os dados das entrevistas
void coletar_dados(Entrevista entrevistas[MAX_MESES][MAX_ENTREVISTAS], int mes) {
    int num_entrevistas = 0;

    // Garante que o número de entrevistas esteja entre 20 e 30
    while (num_entrevistas < MAX_ENTREVISTAS) {
        printf("Digite os dados da entrevista %d para o mes %d:\n", num_entrevistas + 1, mes + 1);

        // Coletar dados da entrevista
        printf("Candidato à Presidência (17, 26, branco, indeciso): ");
        scanf("%d", &entrevistas[mes][num_entrevistas].candidato_presidencia);

        printf("Candidato ao Governo (17, 26, 31, branco, indeciso): ");
        scanf("%d", &entrevistas[mes][num_entrevistas].candidato_governo);

        printf("Idade: ");
        scanf("%d", &entrevistas[mes][num_entrevistas].idade);

        printf("Faixa salarial (1: < 3 SM, 2: 3 a 5 SM, 3: > 5 SM): ");
        scanf("%d", &entrevistas[mes][num_entrevistas].faixa_salarial);

        num_entrevistas++;  // Incrementa o contador de entrevistas

        // Verifica se o número de entrevistas atendeu o mínimo ou excedeu o máximo
        if (num_entrevistas < MIN_ENTREVISTAS) {
            printf("Você ainda precisa inserir mais entrevistas para o mes %d.\n", mes + 1);
        }

        // Verifica se ultrapassou o limite máximo
        if (num_entrevistas >= MAX_ENTREVISTAS) {
            printf("Limite de entrevistas atingido para o mes %d.\n", mes + 1);
            break;  // Sai do laço quando atinge o limite máximo de entrevistas
        }
    }

    printf("Número de entrevistas finalizadas para o mes %d.\n", mes + 1);
}

// Função para gravar os dados no arquivo binário
void gravar_dados(Entrevista entrevistas[MAX_MESES][MAX_ENTREVISTAS]) {
    FILE *arquivo = fopen(FILENAME, "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para gravação.\n");
        return;
    }
    fwrite(entrevistas, sizeof(Entrevista), MAX_MESES * MAX_ENTREVISTAS, arquivo);
    fclose(arquivo);
    printf("Dados gravados no arquivo com sucesso.\n");
}

int main() {
    Entrevista entrevistas[MAX_MESES][MAX_ENTREVISTAS];
    int mes;

    // Coleta de dados para 3 meses
    for (mes = 0; mes < MAX_MESES; mes++) {
        printf("---- Coletando dados para o mes %d ----\n", mes + 1);
        coletar_dados(entrevistas, mes);  // Chama a função de coleta para cada mês
    }

    // Grava os dados coletados no arquivo
    gravar_dados(entrevistas);
    return 0;
}
