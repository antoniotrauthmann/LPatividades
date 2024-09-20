#include <stdio.h>

#define NUM_ATLETAS 10
#define MEDICOES 8

int main() {
    int frequenciasCardiacas[NUM_ATLETAS][MEDICOES];
    float niveisOxigenio[NUM_ATLETAS][MEDICOES];

    for (int i = 0; i < NUM_ATLETAS; i++) {
        for (int j = 0; j < MEDICOES; j++) {
            frequenciasCardiacas[i][j] = 60 + (i + j); 
            niveisOxigenio[i][j] = 95.0 + (i * 0.5); 
        }
    }

    char resposta;
    do {
        int atletaNumero;
        printf("Informe o número do atleta (0 a %d): ", NUM_ATLETAS - 1);
        scanf("%d", &atletaNumero);

        if (atletaNumero < 0 || atletaNumero >= NUM_ATLETAS) {
            printf("Número de atleta inválido. Tente novamente.\n");
            continue;
        }

        float somaOxigenio = 0;
        int maiorFrequencia = frequenciasCardiacas[atletaNumero][0];

        for (int i = 0; i < MEDICOES; i++) {
            somaOxigenio += niveisOxigenio[atletaNumero][i];
            if (frequenciasCardiacas[atletaNumero][i] > maiorFrequencia) {
                maiorFrequencia = frequenciasCardiacas[atletaNumero][i];
            }
        }
        float mediaOxigenio = somaOxigenio / MEDICOES;

        printf("Relatório do Atleta %d:\n", atletaNumero);
        printf("Média de Oxigênio no Sangue: %.2f\n", mediaOxigenio);
        printf("Maior Frequência Cardíaca: %d\n", maiorFrequencia);

        printf("Deseja ver o relatório de outro atleta? (s/n): ");
        scanf(" %c", &resposta); 
        
    } while (resposta == 's' || resposta == 'S');

}