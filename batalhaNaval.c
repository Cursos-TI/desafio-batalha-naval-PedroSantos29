#include <stdio.h>

int main(){
    int tamanho = 10;
    int navio = 3;
    char tabuleiro[10][10];
    char letras[10] = {'J', 'I', 'H', 'G', 'F', 'E', 'D', 'C', 'B', 'A'};
    
    // Inicializa o tabuleiro com '0' (água)
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            tabuleiro[i][j] = '0';
        }
    }

    // Definição das coordenadas iniciais dos navios
    int linha1 = 2, coluna1 = 3, direcao1 = 0; // Horizontal
    int linha2 = 5, coluna2 = 6, direcao2 = 1; // Vertical

    printf("=== Tabuleiro de Batalha Naval ===\n\n");
    printf("Coordenadas dos navios:\n");
    
    // Posicionamento do primeiro navio (horizontal)
    if (coluna1 + navio <= tamanho) {
        int sobreposicao = 0;
        for (int i = 0; i < navio; i++) {
            if (tabuleiro[linha1][coluna1 + i] != '0') {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            printf("Navio 1 (horizontal): ");
            for (int i = 0; i < navio; i++) {
                tabuleiro[linha1][coluna1 + i] = '3';
                printf("(%c, %d) ", letras[linha1], coluna1 + i);
            }
            printf("\n");
        } else {
            printf("Erro ao posicionar o primeiro navio!\n");
        }
    } else {
        printf("Erro: primeiro navio ultrapassa os limites do tabuleiro!\n");
    }

    // Posicionamento do segundo navio (vertical)
    if (linha2 + navio <= tamanho) {
        int sobreposicao = 0;
        for (int i = 0; i < navio; i++) {
            if (tabuleiro[linha2 + i][coluna2] != '0') {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            printf("Navio 2 (vertical): ");
            for (int i = 0; i < navio; i++) {
                tabuleiro[linha2 + i][coluna2] = '3';
                printf("(%c, %d) ", letras[linha2 + i], coluna2);
            }
            printf("\n");
        } else {
            printf("Erro ao posicionar o segundo navio!\n");
        }
    } else {
        printf("Erro: segundo navio ultrapassa os limites do tabuleiro!\n");
    }

    // Exibição do tabuleiro no console
    printf("\n  ");
    for (int j = 0; j < tamanho; j++) {
        printf("%d ", j);
    }
    printf("\n");
    
    for (int i = 0; i < tamanho; i++) {
        printf("%c ", letras[i]);
        for (int j = 0; j < tamanho; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
        
    return 0;
}
