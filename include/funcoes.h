#ifndef FUNCOES_H
#define FUNCOES_H

#include "módulo.h"

void cadastrarAtivo(Ativo carteira[], int *quantidade);

void listarAtivos(Ativo carteira[], int quantidade);

float calcularValorTotal(Ativo carteira[], int quantidade);

float calcularRentabilidadeGeral(Ativo carteira[], int quantidade);

void ordenarPorRentabilidade(Ativo carteira[], int quantidade);

void simuladorEducativo(Ativo carteira[], int quantidade);

void relatorioFinal(Ativo carteira[], int quantidade);

#endif
