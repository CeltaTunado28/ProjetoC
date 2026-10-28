
#include <stdio.h>
#include "funcoes.h"

void cadastrarAtivo(Ativo carteira[], int *quantidadeAtivos, int capacidade) {
    if (*quantidadeAtivos >= capacidade) {
        printf("A carteira esta cheia!\n");
        return;
    }

    int indice = *quantidadeAtivos;

    printf("Nome do ativo: ");
    if (scanf(" %49[^\n]", carteira[indice].nome) != 1) {
        printf("Erro ao ler o nome.\n");
        return;
    }

    printf("Categoria: ");
    if (scanf(" %49[^\n]", carteira[indice].categoria) != 1) {
        printf("Erro ao ler a categoria.\n");
        return;
    }

    printf("Quantidade: ");
    if (scanf("%d", &carteira[indice].quantidade) != 1 ||
        carteira[indice].quantidade <= 0) {
        printf("Quantidade invalida.\n");
        return;
    }

    printf("Preco de compra: ");
    if (scanf("%f", &carteira[indice].preco_compra) != 1 ||
        carteira[indice].preco_compra < 0) {
        printf("Preco de compra invalido.\n");
        return;
    }

    printf("Preco atual: ");
    if (scanf("%f", &carteira[indice].preco_atual) != 1 ||
        carteira[indice].preco_atual < 0) {
        printf("Preco atual invalido.\n");
        return;
    }

    (*quantidadeAtivos)++;

    printf("Ativo cadastrado com sucesso!\n");
}

void listarAtivos(Ativo carteira[], int quantidadeAtivos) {
    if (quantidadeAtivos == 0) {
        printf("Nenhum ativo cadastrado.\n");
        return;
    }

    for (int i = 0; i < quantidadeAtivos; i++) {
        printf("\n--- Ativo %d ---\n", i + 1);
        printf("Nome: %s\n", carteira[i].nome);
        printf("Categoria: %s\n", carteira[i].categoria);
        printf("Quantidade: %d\n", carteira[i].quantidade);
        printf("Preco de compra: R$ %.2f\n",
               carteira[i].preco_compra);
        printf("Preco atual: R$ %.2f\n",
               carteira[i].preco_atual);
    }
}

float calcularRentabilidade(float precoCompra, float precoAtual) {
    if (precoCompra == 0) {
        return 0;
    }

    return (precoAtual - precoCompra) / precoCompra * 100;
}

float calcularLucro(float precoCompra, float precoAtual, int quantidade) {
    return (precoAtual - precoCompra) * quantidade;
}

void exibirRentabilidadeELucro(Ativo ativo) {
    printf("Ativo: %s (%s)\n", ativo.nome, ativo.categoria);

    printf("Rentabilidade: %.2f%%\n",
           calcularRentabilidade(ativo.preco_compra,
                                 ativo.preco_atual));

    printf("Lucro/prejuizo: R$ %.2f\n",
           calcularLucro(ativo.preco_compra,
                         ativo.preco_atual,
                         ativo.quantidade));
}

float calcularValorTotal(Ativo carteira[], int quantidadeAtivos) {
    float total = 0;

    for (int i = 0; i < quantidadeAtivos; i++) {
        total += carteira[i].preco_atual * carteira[i].quantidade;
    }

    return total;
}

float calcularRentabilidadeGeral(Ativo carteira[], int quantidadeAtivos) {
    float totalInvestido = 0;
    float valorAtual = 0;

    for (int i = 0; i < quantidadeAtivos; i++) {
        totalInvestido += carteira[i].preco_compra *
                          carteira[i].quantidade;

        valorAtual += carteira[i].preco_atual *
                      carteira[i].quantidade;
    }

    if (totalInvestido == 0) {
        return 0;
    }

    return (valorAtual - totalInvestido) / totalInvestido * 100;
}

void classificarRisco(float rentabilidade) {
    if (rentabilidade < -10) {
        printf("Risco elevado: rentabilidade abaixo de -10%%.\n");
    } else if (rentabilidade < 0) {
        printf("Rentabilidade negativa.\n");
    } else if (rentabilidade > 0) {
        printf("Rentabilidade positiva.\n");
    } else {
        printf("Rentabilidade neutra.\n");
    }
}

void exibirClassificacaoRisco(Ativo ativo) {
    float rentabilidade = calcularRentabilidade(
        ativo.preco_compra,
        ativo.preco_atual
    );

    classificarRisco(rentabilidade);
}

void exibirDespedida(void) {
    printf("Encerrando o programa.\n");
}
