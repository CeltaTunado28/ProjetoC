# Carteira de Investimentos em C

## Sobre o projeto

Este projeto consiste em um sistema de carteira de investimentos desenvolvido em linguagem C. Seu objetivo é permitir o cadastro e o gerenciamento de ativos financeiros, além de acompanhar o desempenho dos investimentos e apresentar informações sobre a rentabilidade da carteira.

O sistema também possui um simulador educativo que compara diferentes modalidades de investimento, auxiliando na compreensão de conceitos financeiros e contribuindo para a inclusão financeira.

O projeto utiliza estruturas (`struct`), vetores, funções, ponteiros, algoritmos de ordenação e manipulação de arquivos.

## Funcionalidades

- Cadastrar ativos com nome, categoria, quantidade, preço de compra e preço atual.
- Listar todos os ativos cadastrados.
- Calcular o valor total atual da carteira.
- Calcular a rentabilidade geral da carteira em porcentagem.
- Ordenar os ativos de acordo com sua rentabilidade, utilizando o algoritmo Bubble Sort.
- Gerar um relatório final contendo os ativos ordenados, valor investido, valor atual, lucro ou prejuízo e rentabilidade geral.
- Simular o rendimento de diferentes modalidades de investimento durante 12 meses.
- Comparar os resultados de Poupança, Tesouro Selic e CDB.
- Apresentar explicações educativas sobre rentabilidade, risco e liquidez.
- Salvar os dados dos ativos em um arquivo de texto.
- Carregar os dados salvos ao iniciar o programa.

## Tecnologias e conceitos utilizados

- Linguagem C.
- Biblioteca padrão de entrada e saída (`stdio.h`).
- Estruturas de dados (`struct`).
- Vetores e passagem de parâmetros.
- Ponteiros.
- Funções e modularização do código.
- Algoritmo de ordenação Bubble Sort.
- Manipulação de arquivos com `fopen`, `fprintf`, `fscanf` e `fclose`.

## Estrutura do projeto

```text
meu-projeto-c/
├── src/
│   ├── main.c
│   ├── funcoes.c
│   └── modulo.c
├── include/
│   ├── funcoes.h
│   └── modulo.h
├── data/
│   └── carteira.txt
└── README.md
```

## Simulador educativo

O sistema conta com um simulador que utiliza o valor total atual da carteira como referência para comparar três modalidades de investimento:

- **Poupança:** taxa ilustrativa de 0,50% ao mês.
- **Tesouro Selic:** taxa ilustrativa de 0,80% ao mês.
- **CDB:** taxa ilustrativa de 0,90% ao mês.

A simulação considera um período de 12 meses e apresenta o valor final estimado de cada modalidade, além dos ganhos obtidos no período.

**Importante:** as taxas utilizadas são exclusivamente ilustrativas e não representam taxas reais de mercado ou garantias de rendimento.

## Relatório final

O relatório final apresenta os ativos cadastrados organizados em ordem decrescente de rentabilidade.

Além disso, exibe:

- Valor investido.
- Valor atual de cada ativo.
- Rentabilidade individual.
- Valor total da carteira.
- Rentabilidade geral.
- Lucro ou prejuízo total.

O relatório também apresenta informações sobre o impacto social do projeto e sua relação com a inclusão financeira.

## Como executar

É necessário possuir um compilador C instalado, como o GCC.

Na pasta raiz do projeto, execute o comando:

```bash
gcc -Iinclude src/main.c src/funcoes.c src/modulo.c -o carteira
```

Depois, execute o programa:

**Windows:**

```bash
carteira.exe
```

**Linux:**

```bash
./carteira
```

A pasta `data` deve existir para que o programa consiga salvar os dados no arquivo `carteira.txt`.

## Armazenamento dos dados

Os dados da carteira são armazenados no arquivo `data/carteira.txt`.

O sistema utiliza arquivos de texto para manter os dados dos ativos salvos, permitindo que as informações sejam recuperadas ao iniciar o programa novamente.

## Objetivo acadêmico

O projeto tem como objetivo praticar conceitos fundamentais da linguagem C, incluindo estruturas de dados, funções, vetores, ponteiros, passagem de parâmetros, modularização, algoritmos de ordenação e manipulação de arquivos.

Além do aprendizado técnico, o projeto busca contribuir com o **ODS 8.10 da ONU**, relacionado à ampliação do acesso aos serviços financeiros, promovendo a educação financeira e apresentando diferentes possibilidades de investimento de maneira simples e acessível.
