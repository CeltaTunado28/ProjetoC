
#include <stdio.h>
#include "modulo.h"

void salvarCarteira(Ativo carteira[], int quantidadeAtivos) {
    FILE *arquivo = fopen("data/carteira.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar.\n");
        return;
    }

    for (int i = 0; i < quantidadeAtivos; i++) {
        fprintf(arquivo, "%s\n", carteira[i].nome);
        fprintf(arquivo, "%s\n", carteira[i].categoria);
        fprintf(arquivo, "%d\n", carteira[i].quantidade);
        fprintf(arquivo, "%.2f\n", carteira[i].preco_compra);
        fprintf(arquivo, "%.2f\n", carteira[i].preco_atual);
    }

    fclose(arquivo);
    printf("Carteira salva com sucesso!\n");
}

void carregarCarteira(Ativo carteira[], int *quantidadeAtivos, int capacidade) {
    FILE *arquivo = fopen("data/carteira.txt", "r");

    *quantidadeAtivos = 0;

    if (arquivo == NULL) {
        return;
    }

    while (*quantidadeAtivos < capacidade) {
        int indice = *quantidadeAtivos;

        if (fscanf(arquivo, " %49[^\n]", carteira[indice].nome) != 1) {
            break;
        }

        if (fscanf(arquivo, " %49[^\n]", carteira[indice].categoria) != 1 ||
            fscanf(arquivo, "%d", &carteira[indice].quantidade) != 1 ||
            fscanf(arquivo, "%f", &carteira[indice].preco_compra) != 1 ||
            fscanf(arquivo, "%f", &carteira[indice].preco_atual) != 1) {
            printf("Aviso: dados incompletos no arquivo da carteira.\n");
            break;
        }

        (*quantidadeAtivos)++;
    }

    fclose(arquivo);
}
