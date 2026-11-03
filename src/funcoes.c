#include <stdio.h>
#include "funcoes.h"

#define TAXA_POUPANCA 0.005f
#define TAXA_TESOURO 0.008f
#define TAXA_CDB 0.009f
#define MESES 12

void cadastrarAtivo(Ativo carteira[], int *quantidade) {
    int resultado;
    Ativo novoAtivo;

    if (*quantidade >= MAX_ATIVOS) {
        printf("\nLimite de ativos atingido!\n");
        return;
    }

    printf("\n=== CADASTRAR ATIVO ===\n");

    printf("Nome do ativo: ");

    if (scanf(" %99[^\n]", novoAtivo.nome) != 1) {
        printf("\nErro na leitura do nome.\n");
        return;
    }

    printf("Categoria: ");

    if (scanf(" %49[^\n]", novoAtivo.categoria) != 1) {
        printf("\nErro na leitura da categoria.\n");
        return;
    }

    printf("Quantidade: ");
    resultado = scanf("%d", &novoAtivo.quantidade);

    if (resultado != 1) {
        printf("\nQuantidade invalida!\n");

        while (getchar() != '\n');

        return;
    }

    printf("Preco de compra: R$ ");
    resultado = scanf("%f", &novoAtivo.precoCompra);

    if (resultado != 1) {
        printf("\nPreco de compra invalido!\n");

        while (getchar() != '\n');

        return;
    }

    printf("Preco atual: R$ ");
    resultado = scanf("%f", &novoAtivo.precoAtual);

    if (resultado != 1) {
        printf("\nPreco atual invalido!\n");

        while (getchar() != '\n');

        return;
    }

    if (novoAtivo.quantidade <= 0 ||
        novoAtivo.precoCompra <= 0 ||
        novoAtivo.precoAtual < 0) {

        printf("\nValores invalidos! Cadastro cancelado.\n");
        return;
    }

    carteira[*quantidade] = novoAtivo;

    (*quantidade)++;

    printf("\nAtivo cadastrado com sucesso!\n");
}

void listarAtivos(Ativo carteira[], int quantidade) {
    int i;
    float valorAtual;
    float rentabilidade;

    printf("\n=== ATIVOS CADASTRADOS ===\n");

    if (quantidade == 0) {
        printf("Nenhum ativo cadastrado.\n");
        return;
    }

    for (i = 0; i < quantidade; i++) {

        valorAtual = carteira[i].quantidade *
                     carteira[i].precoAtual;

        rentabilidade =
            ((carteira[i].precoAtual -
              carteira[i].precoCompra) /
              carteira[i].precoCompra) * 100;

        printf("\nAtivo: %s\n", carteira[i].nome);

        printf("Categoria: %s\n", carteira[i].categoria);

        printf("Quantidade: %d\n", carteira[i].quantidade);

        printf("Valor atual: R$ %.2f\n", valorAtual);

        printf("Rentabilidade: %.2f%%\n", rentabilidade);
    }
}

float calcularValorTotal(Ativo carteira[], int quantidade) {
    int i;
    float total = 0;

    for (i = 0; i < quantidade; i++) {

        total += carteira[i].quantidade *
                 carteira[i].precoAtual;
    }

    return total;
}

float calcularRentabilidadeGeral(Ativo carteira[], int quantidade) {
    int i;
    float valorInvestido = 0;
    float valorAtual = 0;

    for (i = 0; i < quantidade; i++) {

        valorInvestido += carteira[i].quantidade *
                          carteira[i].precoCompra;

        valorAtual += carteira[i].quantidade *
                      carteira[i].precoAtual;
    }

    if (valorInvestido <= 0) {
        return 0;
    }

    return ((valorAtual - valorInvestido) /
            valorInvestido) * 100;
}

void ordenarPorRentabilidade(Ativo carteira[], int quantidade) {
    int i, j;
    Ativo temporario;

    float rentabilidade1;
    float rentabilidade2;

    /* Ordenacao Bubble Sort: maior para menor */

    for (i = 0; i < quantidade - 1; i++) {

        for (j = 0; j < quantidade - 1 - i; j++) {

            rentabilidade1 =
                ((carteira[j].precoAtual -
                  carteira[j].precoCompra) /
                  carteira[j].precoCompra) * 100;

            rentabilidade2 =
                ((carteira[j + 1].precoAtual -
                  carteira[j + 1].precoCompra) /
                  carteira[j + 1].precoCompra) * 100;

            if (rentabilidade1 < rentabilidade2) {

                temporario = carteira[j];

                carteira[j] = carteira[j + 1];

                carteira[j + 1] = temporario;
            }
        }
    }
}

void simuladorEducativo(Ativo carteira[], int quantidade) {
    float valorInicial;
    float poupanca;
    float tesouro;
    float cdb;

    int i;

    valorInicial = calcularValorTotal(carteira, quantidade);

    if (valorInicial <= 0) {
        printf("\nCadastre ativos antes de utilizar o simulador.\n");
        return;
    }

    poupanca = valorInicial;
    tesouro = valorInicial;
    cdb = valorInicial;

    /* Simulacao de 12 meses */

    for (i = 0; i < MESES; i++) {

        poupanca *= (1 + TAXA_POUPANCA);

        tesouro *= (1 + TAXA_TESOURO);

        cdb *= (1 + TAXA_CDB);
    }

    printf("\n=== SIMULADOR EDUCATIVO ===\n");

    printf("Valor inicial: R$ %.2f\n", valorInicial);

    printf("Periodo: 12 meses\n\n");

    printf("POUPANCA (0.50%%/mes): R$ %.2f (+R$ %.2f)\n",
           poupanca, poupanca - valorInicial);

    printf("TESOURO SELIC (0.80%%/mes): R$ %.2f (+R$ %.2f)\n",
           tesouro, tesouro - valorInicial);

    printf("CDB 110%% CDI (0.90%%/mes): R$ %.2f (+R$ %.2f)\n",
           cdb, cdb - valorInicial);

    printf("\n=== O QUE ISSO SIGNIFICA? ===\n");

    printf("\nPoupanca:\n");
    printf("Investimento conhecido, com baixo risco e rendimento menor.\n");

    printf("\nTesouro Selic:\n");
    printf("Titulo publico federal, considerado de baixo risco.\n");

    printf("\nCDB:\n");
    printf("Investimento oferecido por bancos, que pode contar com "
           "protecao do FGC, conforme as regras e limites de cobertura.\n");

    printf("\nRentabilidade: representa o ganho ou a perda de um investimento.\n");

    printf("Risco: representa a possibilidade de perder dinheiro ou "
           "nao obter o rendimento esperado.\n");

    printf("Liquidez: indica a facilidade de resgatar o dinheiro investido.\n");

    printf("\nATENCAO: as taxas utilizadas sao ilustrativas.\n");

    printf("Os resultados nao representam garantia de rendimento.\n");
}

void relatorioFinal(Ativo carteira[], int quantidade) {
    int i;

    float valorInvestido = 0;
    float valorAtual = 0;

    float lucroPrejuizo;
    float rentabilidade;

    printf("\n=== RELATORIO FINAL ===\n");

    if (quantidade == 0) {
        printf("Nenhum ativo cadastrado.\n");
        return;
    }

    ordenarPorRentabilidade(carteira, quantidade);

    printf("\n=== ATIVOS ORDENADOS POR RENTABILIDADE ===\n");

    for (i = 0; i < quantidade; i++) {

        float valorAtivo;
        float rentabilidadeAtivo;

        valorAtivo = carteira[i].quantidade *
                     carteira[i].precoAtual;

        rentabilidadeAtivo =
            ((carteira[i].precoAtual -
              carteira[i].precoCompra) /
              carteira[i].precoCompra) * 100;

        printf("\n%d. %s\n", i + 1, carteira[i].nome);

        printf("Rentabilidade: %.2f%%\n", rentabilidadeAtivo);

        printf("Valor atual: R$ %.2f\n", valorAtivo);

        valorInvestido += carteira[i].quantidade *
                          carteira[i].precoCompra;

        valorAtual += valorAtivo;
    }

    lucroPrejuizo = valorAtual - valorInvestido;

    if (valorInvestido > 0) {

        rentabilidade =
            (lucroPrejuizo / valorInvestido) * 100;

    } else {

        rentabilidade = 0;
    }

    printf("\n=== RESULTADO GERAL ===\n");

    printf("Valor investido: R$ %.2f\n", valorInvestido);

    printf("Valor total da carteira: R$ %.2f\n", valorAtual);

    printf("Rentabilidade geral: %.2f%%\n", rentabilidade);

    if (lucroPrejuizo > 0) {

        printf("Lucro total: R$ %.2f\n", lucroPrejuizo);

    } else if (lucroPrejuizo < 0) {

        printf("Prejuizo total: R$ %.2f\n", -lucroPrejuizo);

    } else {

        printf("Resultado total: R$ 0.00 (sem lucro ou prejuizo)\n");
    }

    printf("\n=== IMPACTO SOCIAL ===\n");

    printf("O simulador educativo contribui para a inclusao "
           "financeira ao apresentar investimentos acessiveis "
           "e comparar seus rendimentos de forma simples. "
           "A ferramenta ajuda os usuarios a compreender "
           "conceitos financeiros, conhecer diferentes "
           "possibilidades de investimento e tomar decisoes "
           "mais conscientes. Dessa forma, contribui com o "
           "ODS 8.10 da ONU, que busca ampliar o acesso a "
           "servicos financeiros.\n");
}
