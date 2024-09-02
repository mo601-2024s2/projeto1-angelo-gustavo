# Projeto 1 de MO601 - Simulador RISC-V

## Identificação do Grupo

- Ângelo Renato Pazin Malaguti - RA 165429
- Gustavo Araújo Morais - RA 170603

## Descrição geral

Este repositório contém o simulador escrito em C de RISC-V implementado como primeiro projeto da turma do segundo semestre de 2024 da disciplina MO601. Os seus arquivos estão distribuídos da seguinte maneira

```
.
├── src
│   └── include
└── test
    └── ACStone
```

A pasta src contém os arquivos de código bem como a Makefile necessária para compilar o projeto. A pasta test contém a benchmark ACStone bem como um .sh que permite que os códigos de teste em C sejam compilados em arquivos binários executáveis(elf) no simulador.

## Requisitos

Rodar este programa requer a instalação das seguintes bibliotecas

- libbsd
- gcc-riscv64-linux-gnu
- libelf
- gcc
- glibc
- make
- libc6-dev
- dpkg-dev (debian)

## Código

O código desenvolvido está dividido em uma série de módulos que se comportam da seguinte maneira.

| Nome do módulo | Função |
|-|-|
| `reader.c` | Leitura dos arquivos binários(elf) e adaptação em um formato para execução no simulador |
| `log.c` | Geração e manipulação dos logs |
| `instructions.c` | Implementação das instruções de tipo I e M do RISC-V |
| `memory.c` | Geração e manipulação da DRAM |
| `cpu.c` | Roda o programa instrução por instrução, incluindo o processo de decoficação |

Dado um arquivo binário(elf), `main.c` o interpreta por meio de `reader.c` e o roda por meio de `cpu.c`.

## Testagem

Todos os testes do ACStone, salvo aqueles de ponto flutuante, foram executados um-a-um para garantir que eles não exibiam qualquer erro.

## Considerações

Um simulador de RISC-V ilustra como código roda em máquinas reais. O seu desenvolvimento, então, construiu para nós um entendimento mais intuitivo de como os constituintes de um computador operam em conjunto para executar tarefas complexas.

Em particular, superamos desafios com a leitura de arquivos elf, e manipulação de inteiros com e sem sinal.
