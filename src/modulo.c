#include <errno.h>
#include <stdio.h>

#if defined(_WIN32)
#include <direct.h>
#define MKDIR(path) _mkdir(path)
#else
#include <sys/stat.h>
#include <sys/types.h>
#define MKDIR(path) mkdir(path, 0777)
#endif

#include "módulo.h"

#define CAMINHO_CARTEIRA "data/carteira.txt"

static void garantirDiretorioDados(void) {
    if (MKDIR("data") != 0 && errno != EEXIST) {
        printf("\nErro ao criar a pasta data/ para armazenamento dos dados.\n");
    }
}

void carregarAtivos(Ativo carteira[], int *quantidade) {
    FILE *arquivo;
    char linha[300];

    *quantidade = 0;
    garantirDiretorioDados();

    arquivo = fopen(CAMINHO_CARTEIRA, "r");

    if (arquivo == NULL) {
        return;
    }

    while (fgets(linha, sizeof(linha), arquivo) != NULL &&
           *quantidade < MAX_ATIVOS) {

        Ativo novoAtivo;

        if (sscanf(linha, "%99[^|]|%49[^|]|%d|%f|%f",
                   novoAtivo.nome,
                   novoAtivo.categoria,
                   &novoAtivo.quantidade,
                   &novoAtivo.precoCompra,
                   &novoAtivo.precoAtual) == 5) {

            if (novoAtivo.quantidade > 0 &&
                novoAtivo.precoCompra > 0 &&
                novoAtivo.precoAtual >= 0) {

                carteira[*quantidade] = novoAtivo;

                (*quantidade)++;
            }
        }
    }

    fclose(arquivo);
}

void salvarAtivos(Ativo carteira[], int quantidade) {
    FILE *arquivo;
    int i;

    garantirDiretorioDados();
    arquivo = fopen(CAMINHO_CARTEIRA, "w");

    if (arquivo == NULL) {
        printf("\nErro ao abrir o arquivo para salvar os dados!\n");
        return;
    }

    for (i = 0; i < quantidade; i++) {

        fprintf(arquivo, "%s|%s|%d|%.2f|%.2f\n",
                carteira[i].nome,
                carteira[i].categoria,
                carteira[i].quantidade,
                carteira[i].precoCompra,
                carteira[i].precoAtual);
    }

    fclose(arquivo);
}
