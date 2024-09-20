#include <stdio.h>
#define QuantidadePessoas 13
#define QuantidadeGrupos 5

int main() {
    int idade[QuantidadeGrupos][QuantidadePessoas];
    int contIdade, acima_media, abaixo_media;
    float media_idade;

    for (int i = 0; i < QuantidadeGrupos; i++) {
        contIdade = 0;
        acima_media = 0;
        abaixo_media = 0;

        for (int j = 0; j < QuantidadePessoas; j++) {
            printf("Grupo %d, digite a sua idade: ", i + 1);
            scanf("%d", &idade[i][j]);
            contIdade += idade[i][j];
        }

        media_idade = contIdade / (float)QuantidadePessoas;

        for (int j = 0; j < QuantidadePessoas; j++) {
            if (idade[i][j] > media_idade) {
                acima_media++;
            } else {
                abaixo_media++;
            }
        }

        printf("================================================\n");
        printf("Media de idade do grupo %d: %.2f\n", i + 1, media_idade);
        printf("Pessoas abaixo da media de idade: %d\n", abaixo_media);
        printf("Pessoas acima da media: %d\n", acima_media);
    }
}