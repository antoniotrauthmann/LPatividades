#include "relatorio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef strcasestr
char* strcasestr(const char *haystack, const char *needle) {
    while (*haystack) {
        const char *h = haystack;
        const char *n = needle;
        
        while (tolower(*h) == tolower(*n) && *n) {
            h++;
            n++;
        }
        
        if (*n == '\0') return (char *)haystack;
        haystack++;
    }
    return NULL;
}
#endif


int comparar_servicos(const void *a, const void *b) {
    const servico *s1 = (const servico *)a;
    const servico *s2 = (const servico *)b;
    
    int cmp_data = strcmp(s1->data, s2->data);
    if (cmp_data != 0) return cmp_data;
    
    return strcmp(s1->hora, s2->hora);
}

void relatorio_servico(servico servicos[], int total_servicos, const char *tipo_servico) {
    servico *filtrados = malloc(total_servicos * sizeof(servico));
    int count = 0;
    
    for (int i = 0; i < total_servicos; i++) {
        if (strcasestr(servicos[i].tipo_servico, tipo_servico)) {
            filtrados[count++] = servicos[i];
        }
    }
    
    qsort(filtrados, count, sizeof(servico), comparar_servicos);
    
    FILE *f = fopen("relatorio.txt", "w");
    if (!f) {
        printf("Erro ao criar relatorio!\n");
        free(filtrados);
        return;
    }
    
    fprintf(f, "RELATORIO: Servicos '%s'\n", tipo_servico);
    fprintf(f, "================================================\n");
    
    for (int i = 0; i < count; i++) {
        fprintf(f, "Data: %s %s\n", filtrados[i].data, filtrados[i].hora);
        fprintf(f, "Veiculo: %s | Proprietario: %s\n", 
                filtrados[i].placa, filtrados[i].proprietario);
        fprintf(f, "Mecanico: %s\n", filtrados[i].mecanico);
        fprintf(f, "------------------------------------------------\n");
    }
    
    fprintf(f, "TOTAL: %d servicos\n", count);
    fprintf(f, "================================================\n");
    
    fclose(f);
    free(filtrados);
    
    printf("Relatorio gerado em 'relatorio.txt'\n");
}

void relatorio_mecanico(servico servicos[], int total_servicos, const char *mecanico) {
    servico *filtrados = malloc(total_servicos * sizeof(servico));
    int count = 0;
    
    for (int i = 0; i < total_servicos; i++) {
        if (strcasestr(servicos[i].mecanico, mecanico)) {
            filtrados[count++] = servicos[i];
        }
    }
    
    qsort(filtrados, count, sizeof(servico), comparar_servicos);
    
    FILE *f = fopen("relatorio.txt", "w");
    if (!f) {
        printf("Erro ao criar relatorio!\n");
        free(filtrados);
        return;
    }
    
    fprintf(f, "RELATORIO: Mecanico '%s'\n", mecanico);
    fprintf(f, "================================================\n");
    
    for (int i = 0; i < count; i++) {
        fprintf(f, "Data: %s %s\n", filtrados[i].data, filtrados[i].hora);
        fprintf(f, "Veiculo: %s | Servico: %s\n", 
                filtrados[i].placa, filtrados[i].tipo_servico);
        fprintf(f, "Proprietario: %s\n", filtrados[i].proprietario);
        fprintf(f, "------------------------------------------------\n");
    }
    
    fprintf(f, "TOTAL: %d servicos\n", count);
    fprintf(f, "================================================\n");
    
    fclose(f);
    free(filtrados);
    
    printf("Relatorio gerado em 'relatorio.txt'\n");
}

