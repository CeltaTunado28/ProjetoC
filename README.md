# Carteira de Investimentos em C

## Sobre o projeto

Este projeto é um sistema de carteira de investimentos desenvolvido em linguagem C. Seu objetivo é permitir o cadastro e o gerenciamento de ativos, além de calcular o valor total da carteira e sua rentabilidade geral.

O projeto utiliza estruturas (`struct`), vetores, funções e arquivos para armazenar os dados dos ativos.

## Funcionalidades

- Cadastrar ativos com nome, categoria, quantidade, preço de compra e preço atual.
- Listar todos os ativos cadastrados.
- Calcular o valor total atual da carteira.
- Calcular a rentabilidade geral da carteira em porcentagem.
- Salvar os dados dos ativos em um arquivo de texto.
- Carregar os dados salvos ao iniciar o programa.

## Tecnologias utilizadas

- Linguagem C
- Biblioteca padrão de entrada e saída (`stdio.h`)
- Manipulação de arquivos com `fopen`, `fprintf`, `fscanf` e `fclose`

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

## Como executar

É necessário ter um compilador C instalado, como o GCC.

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

Os dados da carteira são armazenados no arquivo `data/carteira.txt`. Ao iniciar o programa, os ativos salvos são carregados para a memória. Após cadastrar um novo ativo ou encerrar o programa, os dados são salvos novamente no arquivo.

## Objetivo acadêmico

O projeto tem como objetivo praticar conceitos fundamentais da linguagem C, incluindo estruturas de dados, funções, vetores, passagem de parâmetros e manipulação de arquivos.
