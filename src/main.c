
#include <stdio.h>
#include "funcoes.h"
#include "modulo.h"

#define CAPACIDADE_CARTEIRA 100

int main(void) {
    Ativo carteira[CAPACIDADE_CARTEIRA];
    int quantidadeAtivos = 0;
    int opcao = 0;

    carregarCarteira(
        carteira,
        &quantidadeAtivos,
        CAPACIDADE_CARTEIRA
    );

    printf("Ativos carregados: %d\n", quantidadeAtivos);

    while (opcao != 5) {
        printf("\n=== Carteira de Investimentos ===\n");
        printf("1. Cadastrar ativo\n");
        printf("2. Listar ativos\n");
        printf("3. Ver valor total da carteira\n");
        printf("4. Ver rentabilidade geral\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida.\n");
            salvarCarteira(carteira, quantidadeAtivos);
            return 1;
        }

        switch (opcao) {
            case 1:
                cadastrarAtivo(
                    carteira,
                    &quantidadeAtivos,
                    CAPACIDADE_CARTEIRA
                );

                salvarCarteira(carteira, quantidadeAtivos);
                break;

            case 2:
                listarAtivos(carteira, quantidadeAtivos);
                break;

            case 3:
                printf(
                    "Valor total da carteira: R$ %.2f\n",
                    calcularValorTotal(carteira, quantidadeAtivos)
                );
                break;

            case 4:
                printf(
                    "Rentabilidade geral: %.2f%%\n",
                    calcularRentabilidadeGeral(
                        carteira,
                        quantidadeAtivos
                    )
                );
                break;

            case 5:
                salvarCarteira(carteira, quantidadeAtivos);
                exibirDespedida();
                break;

            default:
                printf("Opcao invalida. Escolha de 1 a 5.\n");
                break;
        }
    }

    return 0;
}
