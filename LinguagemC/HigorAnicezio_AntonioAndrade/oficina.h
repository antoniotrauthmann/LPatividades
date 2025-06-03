#ifndef oficina_h
#define oficina_h

#define max_veiculos 200

typedef struct 
{
    char placa[10];
    char modelo[30];
    char marca[30];
    int ano;
    int tipo;
    char proprietario[50];
}veiculo;

void carregar_veiculos(veiculo veiculos[], int *total_veiculos);
void cadastrar_veiculo(veiculo veiculos[],int *total_veiculos);
int busca_placa(veiculo veiculos[],int total_veiculos, const char *placa);

#endif