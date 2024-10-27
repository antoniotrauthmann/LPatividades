#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX_TAMANHO 18
#define MAX_TENTATIVAS 6

int preencheMascara(const char *str, char c, int *mascara) {
    int encontrado = 0;
    int tamanho = strlen(str);
    
    for (int i = 0; i < MAX_TAMANHO; i++) {
        mascara[i] = 0;
    }
    
    for (int i = 0; i < tamanho; i++) {
        if (str[i] == c) {
            mascara[i] = 1;
            encontrado = 1;
        }
    }
    
    return encontrado;
}

void imprimePalavra(const char *str, const int *mascara) {
    for (int i = 0; i < strlen(str); i++) {
        if (mascara[i]) {
            printf("%c ", str[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    char palavraSecreta[MAX_TAMANHO + 1] = "programação";
    char letra;
    int mascara[MAX_TAMANHO];
    int tentativas = 0;
    int acertos = 0;

    memset(mascara, 0, sizeof(mascara));
    
    printf("Jogo da Forca!\n");

    while (tentativas < MAX_TENTATIVAS && acertos < strlen(palavraSecreta)) {
        imprimePalavra(palavraSecreta, mascara);
        printf("Digite uma letra: ");
        scanf(" %c", &letra);

        if (preencheMascara(palavraSecreta, letra, mascara)) {
            acertos += 1;
            printf("Você acertou a letra '%c'!\n", letra);
        } else {
            tentativas += 1;
            printf("Letra '%c' não encontrada. Tentativas restantes: %d\n", letra, MAX_TENTATIVAS - tentativas);
        }
    }

    if (acertos == strlen(palavraSecreta)) {
        printf("Parabéns! Você adivinhou a palavra: %s\n", palavraSecreta);
    } else {
        printf("Você perdeu! A palavra era: %s\n", palavraSecreta);
    }

    return 0;
}
