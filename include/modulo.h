#ifndef MODULO_H
#define MODULO_H

#define MAX_ATIVOS 100

typedef struct {
    char nome[100];
    char categoria[50];
    int quantidade;
    float precoCompra;
    float precoAtual;
} Ativo;

void carregarAtivos(Ativo carteira[], int *quantidade);

void salvarAtivos(Ativo carteira[], int quantidade);

#endif
