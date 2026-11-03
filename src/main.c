#include <stdio.h>
#include "funcoes.h"

int main() {
    Ativo carteira[MAX_ATIVOS];
    int quantidade = 0;
    int opcao;
    int resultado;

    carregarAtivos(carteira, &quantidade);

    do {
        printf("\n=== CARTEIRA DE INVESTIMENTOS ===\n");
        printf("1. Cadastrar ativo\n");
        printf("2. Listar ativos\n");
        printf("3. Valor total da carteira\n");
        printf("4. Rentabilidade geral\n");
        printf("5. Ordenar por rentabilidade\n");
        printf("6. Simulador educativo\n");
        printf("7. Relatorio final\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");

        resultado = scanf("%d", &opcao);

        if (resultado != 1) {
            printf("\nDigite uma opcao valida!\n");

            while (getchar() != '\n');

            continue;
        }

        switch (opcao) {

            case 1:
                cadastrarAtivo(carteira, &quantidade);
                salvarAtivos(carteira, quantidade);
                break;

            case 2:
                listarAtivos(carteira, quantidade);
                break;

            case 3:
                printf("\n=== VALOR TOTAL ===\n");
                printf("Valor da carteira: R$ %.2f\n",
                       calcularValorTotal(carteira, quantidade));
                break;

            case 4:
                printf("\n=== RENTABILIDADE GERAL ===\n");
                printf("Rentabilidade: %.2f%%\n",
                       calcularRentabilidadeGeral(carteira, quantidade));
                break;

            case 5:
                ordenarPorRentabilidade(carteira, quantidade);

                printf("\nCarteira ordenada com sucesso!\n");

                listarAtivos(carteira, quantidade);

                salvarAtivos(carteira, quantidade);
                break;

            case 6:
                simuladorEducativo(carteira, quantidade);
                break;

            case 7:
                relatorioFinal(carteira, quantidade);
                break;

            case 0:
                salvarAtivos(carteira, quantidade);
                printf("\nSistema encerrado.\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}
