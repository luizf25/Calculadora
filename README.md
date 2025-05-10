# Calculadora C++ Simples

Uma calculadora de linha de comando simples desenvolvida em C++ que realiza operações aritméticas básicas, potenciação e raiz quadrada. Lida com números inteiros e de ponto flutuante (com vírgula/ponto decimal) e inclui suporte para UTF-8 no console do Windows.

## Funcionalidades

*   **Operações Aritméticas:**
    *   Soma (`+`)
    *   Subtração (`-`)
    *   Multiplicação (`*`)
    *   Divisão (`/`)
*   **Operações Matemáticas Adicionais:**
    *   Potenciação (`^`)
    *   Raiz Quadrada (`r`)
*   **Tipos de Números:** Suporte para números inteiros e de ponto flutuante.
*   **Interface:** Menu interativo de linha de comando.
*   **Tratamento de Erros:**
    *   Entrada inválida (não numérica).
    *   Divisão por zero.
    *   Raiz quadrada de número negativo (no domínio dos números reais).
*   **Internacionalização:** Configura o console do Windows para UTF-8, permitindo a exibição correta de caracteres acentuados.
*   **Usabilidade:** Permite realizar múltiplas operações em uma única execução e possui uma opção para sair.

## Pré-requisitos

*   Um compilador C++ que suporte C++11 ou superior (ex: g++, Clang, MSVC).
    *   Para compilação no Windows, o MinGW (g++) é uma opção popular.
*   Sistema Operacional Windows (para a funcionalidade de `SetConsoleOutputCP` e `SetConsoleCP` via `Windows.h`).
