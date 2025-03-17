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

    // Coordenadas iniciais dos navios
    int linha_horizontal = 2, coluna_horizontal = 3; // Posição do navio horizontal
    int linha_vertical = 5, coluna_vertical = 7;     // Posição do navio vertical

    // Posiciona o navio horizontalmente (tamanho 3)
    for (int i = 0; i < navio; i++) {
        tabuleiro[linha_horizontal][coluna_horizontal + i] = 3;
    }

    // Posiciona o navio verticalmente (tamanho 3)
    for (int i = 0; i < navio; i++) {
        tabuleiro[linha_vertical + i][coluna_vertical] = 3;
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