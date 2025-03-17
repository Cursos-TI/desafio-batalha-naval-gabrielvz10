#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3
#define AFETADO 5

void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

void posicionarNavios(int tabuleiro[TAMANHO][TAMANHO]) {
    int linha_h = 2, coluna_h = 1;
    for (int i = 0; i < NAVIO; i++) tabuleiro[linha_h][coluna_h + i] = 3;

    int linha_v = 5, coluna_v = 6;
    for (int i = 0; i < NAVIO; i++) tabuleiro[linha_v + i][coluna_v] = 3;

    int linha_d1 = 1, coluna_d1 = 4;
    for (int i = 0; i < NAVIO; i++) tabuleiro[linha_d1 + i][coluna_d1 + i] = 3;

    int linha_d2 = 7, coluna_d2 = 5;
    for (int i = 0; i < NAVIO; i++) tabuleiro[linha_d2 - i][coluna_d2 + i] = 3;
}

void aplicarCone(int tabuleiro[TAMANHO][TAMANHO], int x, int y) {
    for (int i = 0; i < 3; i++) {
        for (int j = -i; j <= i; j++) {
            int nx = x + i, ny = y + j;
            if (nx >= 0 && nx < TAMANHO && ny >= 0 && ny < TAMANHO && tabuleiro[nx][ny] != 3) {
                tabuleiro[nx][ny] = AFETADO;
            }
        }
    }
}

void aplicarCruz(int tabuleiro[TAMANHO][TAMANHO], int x, int y) {
    for (int i = -2; i <= 2; i++) {
        if (x + i >= 0 && x + i < TAMANHO && tabuleiro[x + i][y] != 3) {
            tabuleiro[x + i][y] = AFETADO;
        }
        if (y + i >= 0 && y + i < TAMANHO && tabuleiro[x][y + i] != 3) {
            tabuleiro[x][y + i] = AFETADO;
        }
    }
}

void aplicarOctaedro(int tabuleiro[TAMANHO][TAMANHO], int x, int y) {
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (x + i >= 0 && x + i < TAMANHO && y + j >= 0 && y + j < TAMANHO && tabuleiro[x + i][y + j] != 3) {
                tabuleiro[x + i][y + j] = AFETADO;
            }
        }
    }
}

void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("\nTabuleiro de Batalha Naval:\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    
    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);
    
    aplicarCone(tabuleiro, 3, 3);
    aplicarCruz(tabuleiro, 6, 6);
    aplicarOctaedro(tabuleiro, 8, 2);
    
    exibirTabuleiro(tabuleiro);

    return 0;
}