#include <stdio.h>
#include <string.h>

#define MAX_TAMANHO 20

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

int main() {
    char str[MAX_TAMANHO + 1]; 
    char c;
    int mascara[MAX_TAMANHO];

    printf("Digite uma string (máximo 20 caracteres): ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    printf("Digite um caractere: ");
    scanf(" %c", &c);

    int resultado = preencheMascara(str, c, mascara);

    printf("Máscara: ");
    for (int i = 0; i < strlen(str); i++) {
        printf("%d ", mascara[i]);
    }
    printf("\n");

    if (resultado) {
        printf("O caractere '%c' foi encontrado na string.\n", c);
    } else {
        printf("O caractere '%c' não foi encontrado na string.\n", c);
    }

    return 0;
}
