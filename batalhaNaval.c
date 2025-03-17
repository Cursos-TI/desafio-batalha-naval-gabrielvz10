#include <stdio.h>

int main() {
    int tamanho = 10;  // Tamanho do tabuleiro
    int navio = 3;     // Tamanho do navio
    int tabuleiro[10][10]; // Matriz do tabuleiro

    // Inicializa o tabuleiro preenchendo com 0 (água)
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Posicionando 4 navios:
    // 1. Navio horizontal (linha 2, começando na coluna 1)
    int linha_horizontal = 2, coluna_horizontal = 1;
    for (int i = 0; i < navio; i++) {
        tabuleiro[linha_horizontal][coluna_horizontal + i] = 3;
    }

    // 2. Navio vertical (coluna 6, começando na linha 5)
    int linha_vertical = 5, coluna_vertical = 6;
    for (int i = 0; i < navio; i++) {
        tabuleiro[linha_vertical + i][coluna_vertical] = 3;
    }

    // 3. Navio diagonal ↘ (diagonal crescente, começando em 1,4)
    int linha_diag1 = 1, coluna_diag1 = 4;
    for (int i = 0; i < navio; i++) {
        tabuleiro[linha_diag1 + i][coluna_diag1 + i] = 3;
    }

    // 4. Navio diagonal ↙ (diagonal decrescente, começando em 7,5)
    int linha_diag2 = 7, coluna_diag2 = 5;
    for (int i = 0; i < navio; i++) {
        tabuleiro[linha_diag2 - i][coluna_diag2 + i] = 3;
    }

    // Exibe o tabuleiro no console
    printf("Tabuleiro de Batalha Naval:\n");
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}