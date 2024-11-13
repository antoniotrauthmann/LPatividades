#include <stdio.h>
#include <string.h>

#define MAX_PACOTES_ESCRITORIO 60
#define MAX_PACOTES_POR_LOTE 3
#define MAX_PACOTES_TOTAL (MAX_PACOTES_ESCRITORIO * 3) // Total para 3 escritórios

// Função para inicializar os dados
void inicializar_dados(int* total_pacotes, int* pacotes_palmas, int* pacotes_gurupi, int* pacotes_goiania, int codigos[], int pesos[], char destinos[][20], char senha_admin[]) {
    *total_pacotes = 0;
    *pacotes_palmas = 0;
    *pacotes_gurupi = 0;
    *pacotes_goiania = 0;

    // Registro da senha do administrador
    printf("Digite a senha do administrador: ");
    scanf("%s", senha_admin);

    // Registrar pacotes iniciais (opcional, dependendo do que já deve ser registrado)
    printf("Digite os pacotes iniciais (codigo, peso, destino). Digite 0 para finalizar.\n");
    while (1) {
        int codigo, peso;
        char destino[20];
        
        printf("Digite o codigo do pacote: ");
        scanf("%d", &codigo);
        if (codigo == 0) break;  // Sai quando o código 0 for inserido
        
        printf("Digite o peso do pacote (kg): ");
        while (scanf("%d", &peso) != 1 || peso <= 0) {
            while(getchar() != '\n');
            printf("Valor invalido. Digite um peso valido (positivo): ");
        }
        
        printf("Digite o escritorio de destino (Palmas, Gurupi ou Goiania): ");
        scanf("%s", destino);
        
        // Chama a função de registrar pacote
        registrar_pacote(total_pacotes, pacotes_palmas, pacotes_gurupi, pacotes_goiania, codigos, pesos, destinos, codigo, peso, destino);
    }
}

// Função para registrar um pacote
void registrar_pacote(int* total_pacotes, int* pacotes_palmas, int* pacotes_gurupi, int* pacotes_goiania, int codigos[], int pesos[], char destinos[][20], int codigo, int peso, char destino[]) {
    if (*total_pacotes >= MAX_PACOTES_TOTAL) {
        printf("Capacidade total de pacotes atingida.\n");
        return;
    }

    if (strcmp(destino, "Palmas") == 0 && *pacotes_palmas >= MAX_PACOTES_ESCRITORIO) {
        printf("Limite de pacotes para Palmas atingido.\n");
        return;
    }
    if (strcmp(destino, "Gurupi") == 0 && *pacotes_gurupi >= MAX_PACOTES_ESCRITORIO) {
        printf("Limite de pacotes para Gurupi atingido.\n");
        return;
    }
    if (strcmp(destino, "Goiania") == 0 && *pacotes_goiania >= MAX_PACOTES_ESCRITORIO) {
        printf("Limite de pacotes para Goiania atingido.\n");
        return;
    }

    codigos[*total_pacotes] = codigo;
    pesos[*total_pacotes] = peso;
    strcpy(destinos[*total_pacotes], destino);

    // Atualiza o número de pacotes por escritório
    if (strcmp(destino, "Palmas") == 0) {
        (*pacotes_palmas)++;
    } else if (strcmp(destino, "Gurupi") == 0) {
        (*pacotes_gurupi)++;
    } else if (strcmp(destino, "Goiania") == 0) {
        (*pacotes_goiania)++;
    }

    (*total_pacotes)++;
    printf("Pacote registrado com sucesso!\n");
}

// Função para consultar um pacote pelo código
void consultar_pacote(int total_pacotes, int codigos[], int pesos[], char destinos[][20], int codigo) {
    int encontrado = 0;
    for (int i = 0; i < total_pacotes; i++) {
        if (codigos[i] == codigo) {
            printf("Codigo: %d\n", codigos[i]);
            printf("Peso: %d kg\n", pesos[i]);
            printf("Destino: %s\n", destinos[i]);  // A exibição do destino está aqui
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Pacote nao encontrado.\n");
    }
}

// Função para mostrar a quantidade de pacotes geral
void mostrar_quantidade_pacotes(int total_pacotes, int pacotes_palmas, int pacotes_gurupi, int pacotes_goiania) {
    printf("Total de pacotes: %d\n", total_pacotes);
    printf("Porcentagem de pacotes por escritorio:\n");
    printf("Palmas: %.2f%%\n", (float)pacotes_palmas / total_pacotes * 100);
    printf("Gurupi: %.2f%%\n", (float)pacotes_gurupi / total_pacotes * 100);
    printf("Goiania: %.2f%%\n", (float)pacotes_goiania / total_pacotes * 100);
}

// Função para verificar a entrega por escritório
void verificar_entrega_por_escritorio(int total_pacotes, int pacotes_palmas, int pacotes_gurupi, int pacotes_goiania, int pesos[], char destinos[][20], char escritorio[]) {
    int quantidade = 0;
    int peso_total = 0;
    int lotes = 0;
    int reforco = 0;

    for (int i = 0; i < total_pacotes; i++) {
        if (strcmp(destinos[i], escritorio) == 0) {
            quantidade++;
            peso_total += pesos[i];
            if (pesos[i] > 50) {
                reforco = 1;
            }
        }
    }

    if (quantidade > 0) {
        printf("Pacotes para %s:\n", escritorio);
        printf("Quantidade de pacotes: %d\n", quantidade);
        printf("Peso total: %d kg\n", peso_total);
        lotes = (quantidade + MAX_PACOTES_POR_LOTE - 1) / MAX_PACOTES_POR_LOTE;
        printf("Lotes necessarios: %d\n", lotes);
        if (reforco) {
            printf("Necessidade de reforco\n");
        }
    } else {
        printf("Nenhum pacote encontrado para o escritorio %s.\n", escritorio);
    }
}

// Função para autorizar a entrega
void autorizar_entrega(char senha[], char senha_admin[], int total_pacotes, int pacotes_palmas, int pacotes_gurupi, int pacotes_goiania,int pesos[], char destinos[][20], char escritorio[]) {
    if (strcmp(senha, senha_admin) != 0) {
        printf("Senha incorreta.\n");
        return;
    }
    verificar_entrega_por_escritorio(total_pacotes, pacotes_palmas, pacotes_gurupi, pacotes_goiania, pesos, destinos, escritorio);
    printf("Entrega autorizada!\n");
}

int main() {
    int total_pacotes = 0, pacotes_palmas = 0, pacotes_gurupi = 0, pacotes_goiania = 0;
    int codigos[MAX_PACOTES_TOTAL], pesos[MAX_PACOTES_TOTAL]; // Capacidade para 3 escritórios
    char destinos[MAX_PACOTES_TOTAL][20];
    char senha_admin[20];

    // Solicitar e registrar dados iniciais
    inicializar_dados(&total_pacotes, &pacotes_palmas, &pacotes_gurupi, &pacotes_goiania, codigos, pesos, destinos, senha_admin);

    int opcao;
    do {
        // Exibir o menu para o administrador
        printf("\nMenu de opcoes:\n");
        printf("[1] Registre 1 pacote\n");
        printf("[2] Consulta pacote por codigo\n");
        printf("[3] Quantidade de pacotes geral\n");
        printf("[4] Verificar entrega por escritorio\n");
        printf("[5] Autorizar entrega\n");
        printf("[0] Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: {
                int codigo, peso;
                char destino[20];
                printf("Digite o codigo do pacote: ");
                scanf("%d", &codigo);
                printf("Digite o peso do pacote (kg): ");
                scanf("%d", &peso);
                printf("Digite o destino do pacote (Palmas, Gurupi ou Goiania): ");
                scanf("%s", destino);
                registrar_pacote(&total_pacotes, &pacotes_palmas, &pacotes_gurupi, &pacotes_goiania, codigos, pesos, destinos, codigo, peso, destino);
                break;
            }
            case 2: {
                int codigo;
                printf("Digite o codigo do pacote para consulta: ");
                scanf("%d", &codigo);
                consultar_pacote(total_pacotes, codigos, pesos, destinos, codigo);
                break;
            }
            case 3:
                mostrar_quantidade_pacotes(total_pacotes, pacotes_palmas, pacotes_gurupi, pacotes_goiania);
                break;
            case 4: {
                char escritorio[20];
                printf("Digite o nome do escritorio (Palmas, Gurupi ou Goiania): ");
                scanf("%s", escritorio);
                verificar_entrega_por_escritorio(total_pacotes, pacotes_palmas, pacotes_gurupi, pacotes_goiania, pesos, destinos, escritorio);
                break;
            }
            case 5: {
                char senha[20];
                printf("Digite a senha do administrador: ");
                scanf("%s", senha);
                printf("Digite o nome do escritorio (Palmas, Gurupi ou Goiania): ");
                char escritorio[20];
                scanf("%s", escritorio);
                autorizar_entrega(senha, senha_admin, total_pacotes, pacotes_palmas, pacotes_gurupi, pacotes_goiania, pesos, destinos, escritorio);
                break;
            }
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while(opcao != 0);

    return 0;
}