
#ifndef FUNCOES_H
#define FUNCOES_H

typedef struct {
    char nome[50];
    char categoria[50];
    int quantidade;
    float preco_compra;
    float preco_atual;
} Ativo;

void cadastrarAtivo(Ativo carteira[], int *quantidadeAtivos, int capacidade);

void listarAtivos(Ativo carteira[], int quantidadeAtivos);

float calcularRentabilidade(float precoCompra, float precoAtual);

float calcularLucro(float precoCompra, float precoAtual, int quantidade);

void exibirRentabilidadeELucro(Ativo ativo);

float calcularValorTotal(Ativo carteira[], int quantidadeAtivos);

float calcularRentabilidadeGeral(Ativo carteira[], int quantidadeAtivos);

void classificarRisco(float rentabilidade);

void exibirClassificacaoRisco(Ativo ativo);

void exibirDespedida(void);

#endif
