// ppt.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "vmenu.h"   // para acessar ptrNomePersonagem1 e ptrNomePersonagem2

// Definição da struct Jogador (local ao jogo PPT)
struct Jogador {
    char nome[20];
    int escolha;  // 1=Pedra, 2=Papel, 3=Tesoura
    int vivo;     // 1=alive, 0=dead
};

int PptRussa() {
    srand(time(NULL));

    struct Jogador j1, j2;
    int balas = 1;
    int max_balas = 5;
    int rodada = 1;

    strcpy(j1.nome, ptrNomePersonagem1);
    j1.vivo = 1;

    strcpy(j2.nome, ptrNomePersonagem2);
    j2.vivo = 1;

    printf("=== Jogo Pedra-Papel-Tesoura com Roleta Russa ===\n");

    while (rodada <= 5) {
        printf("\n=== Rodada %d ===\n", rodada);
        printf("1=Pedra 2=Papel 3=Tesoura\n");
        printf("0=Voltar ao menu principal\n");

        printf("%s, escolha (1-3): ", j1.nome);
        scanf("%d", &j1.escolha);

        if (j1.escolha == 0) {
             realizarCadastro();
        }

        printf("%s, escolha (1-3): ", j2.nome);
        scanf("%d", &j2.escolha);

        if (j2.escolha == 0) {
            return 0; // VOLTA PARA O MENU
        }

        if (j1.escolha < 1 || j1.escolha > 3) {
            printf("%s jogou incorretamente e perdeu a vez!\n", j1.nome);
            int disparo = rand() % max_balas;
            if (disparo < balas) {
                printf("%s atirou e acertou %s! %s morreu.\n", j2.nome, j1.nome, j1.nome);
                j1.vivo = 0;
                break;
            } else {
                printf("%s atirou, mas não tinha bala!\n", j2.nome);
            }
            rodada++;
            continue;
        }

        if (j2.escolha < 1 || j2.escolha > 3) {
            printf("%s jogou incorretamente e perdeu a vez!\n", j2.nome);
            int disparo = rand() % max_balas;
            if (disparo < balas) {
                printf("%s atirou e acertou %s! %s morreu.\n", j1.nome, j2.nome, j2.nome);
                j2.vivo = 0;
                break;
            } else {
                printf("%s atirou, mas não tinha bala!\n", j1.nome);
            }
            rodada++;
            continue;
        }

        int vencedor = 0;
        if (j1.escolha != j2.escolha) {
            if ((j1.escolha == 1 && j2.escolha == 3) ||
                (j1.escolha == 2 && j2.escolha == 1) ||
                (j1.escolha == 3 && j2.escolha == 2)) {
                vencedor = 1;
            } else {
                vencedor = 2;
            }
        }

        if (vencedor == 0) {
            printf("Empate! Ninguém dispara.\n");
        } else if (vencedor == 1) {
            printf("%s venceu a rodada e pode disparar!\n", j1.nome);
            int disparo = rand() % max_balas;
            if (disparo < balas) {
                printf("%s atirou e acertou %s! %s morreu.\n", j1.nome, j2.nome, j2.nome);
                j2.vivo = 0;
                break;
            } else {
                printf("%s atirou, mas não tinha bala!\n", j1.nome);
            }
        } else {
            printf("%s venceu a rodada e pode disparar!\n", j2.nome);
            int disparo = rand() % max_balas;
            if (disparo < balas) {
                printf("%s atirou e acertou %s! %s morreu.\n", j2.nome, j1.nome, j1.nome);
                j1.vivo = 0;
                break;
            } else {
                printf("%s atirou, mas não tinha bala!\n", j2.nome);
            }
        }

        rodada++;
    }

    printf("\n=== Fim do Jogo ===\n");
    if (j1.vivo && j2.vivo)
        printf("Fim das 5 rodadas! Ninguém foi eliminado.\n");
    else if (j1.vivo)
        printf("%s venceu o jogo!\n", j1.nome);
    else if (j2.vivo)
        printf("%s venceu o jogo!\n", j2.nome);
    else
        printf("Ambos foram eliminados!\n");

    return 0;
}
