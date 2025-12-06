#ifndef PPT_H
#define PPT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "menu.h"
#include "vmenu.h"

struct Jogador {
    char nome[20];
    int escolha;
    int vivo; 
};

int PptRussa() {
    srand(time(NULL));

    struct Jogador j1, j2;
    int balas = 1;
    int max_balas = 5;
    int rodada = 1;

    /*printf("Digite o nome do Jogador 1: ");
    scanf("%s", j1.nome);*/
     strcpy(j1.nome, ptrNomePersonagem1);
    j1.vivo = 1;
    
    

    /*printf("Digite o nome do Jogador 2: ");
    scanf("%s", j2.nome);*/
     strcpy(j2.nome, ptrNomePersonagem2);
    j2.vivo = 1;

    while(rodada <= 5) {
        printf("\n=== Rodada %d ===\n", rodada);
        printf("1=Pedra 2=Papel 3=Tesoura\n");

        printf("%s, escolha (1-3): ", j1.nome);
        scanf("%d", &j1.escolha);

        printf("%s, escolha (1-3): ", j2.nome);
        scanf("%d", &j2.escolha);

        
        if(j1.escolha < 1 || j1.escolha > 3) {
            printf("%s não jogou corretamente e perdeu a vez!\n", j1.nome);
            int disparo = rand() % max_balas;
            if(disparo < balas) {
                printf("%s atirou e acertou %s! %s morreu.\n", j2.nome, j1.nome, j1.nome);
                j1.vivo = 0;
                break;
            } else {
                printf("%s atirou, mas não tinha bala!\n", j2.nome);
                int opc;
                printf("%s, deseja aumentar a dificuldade? (0=não, 1=sim): ", j2.nome);
                scanf("%d", &opc);
                if(opc == 1 && balas < max_balas) {
                    balas++;
                    printf("Dificuldade aumentada! Agora o revólver tem %d balas.\n", balas);
                } else if(opc == 1 && balas >= max_balas) {
                    printf("O revólver já está no máximo de balas (%d)!\n", max_balas);
                }
            }
            rodada++;
            continue;
        }

        
        if(j2.escolha < 1 || j2.escolha > 3) {
            printf("%s não jogou corretamente e perdeu a vez!\n", j2.nome);
            int disparo = rand() % max_balas;
            if(disparo < balas) {
                printf("%s atirou e acertou %s! %s morreu.\n", j1.nome, j2.nome, j2.nome);
                j2.vivo = 0;
                break;
            } else {
                printf("%s atirou, mas não tinha bala!\n", j1.nome);
                int opc;
                printf("%s, deseja aumentar a dificuldade? (0=não, 1=sim): ", j1.nome);
                scanf("%d", &opc);
                if(opc == 1 && balas < max_balas) {
                    balas++;
                    printf("Dificuldade aumentada! Agora o revólver tem %d balas.\n", balas);
                } else if(opc == 1 && balas >= max_balas) {
                    printf("O revólver já está no máximo de balas (%d)!\n", max_balas);
                }
            }
            rodada++;
            continue;
        }

        
        int vencedor = 0; 
        if(j1.escolha != j2.escolha) {
            if((j1.escolha==1 && j2.escolha==3) ||
               (j1.escolha==2 && j2.escolha==1) ||
               (j1.escolha==3 && j2.escolha==2))
                vencedor = 1;
            else
                vencedor = 2;
        }

    
        if(vencedor == 0) {
            printf("Empate! Ninguém dispara.\n");
        } else if(vencedor == 1) {
            printf("%s venceu a rodada e pode disparar!\n", j1.nome);
            int disparo = rand() % max_balas;
            if(disparo < balas) {
                printf("%s atirou e acertou %s! %s morreu.\n", j1.nome, j2.nome, j2.nome);
                j2.vivo = 0;
                break;
            } else {
                printf("%s atirou, mas não tinha bala!\n", j1.nome);
                int opc;
                printf("%s, deseja aumentar a dificuldade? (0=não, 1=sim): ", j1.nome);
                scanf("%d", &opc);
                if(opc == 1 && balas < max_balas) {
                    balas++;
                    printf("Dificuldade aumentada! Agora o revólver tem %d balas.\n", balas);
                } else if(opc == 1 && balas >= max_balas) {
                    printf("O revólver já está no máximo de balas (%d)!\n", max_balas);
                }
            }
        } else {
            printf("%s venceu a rodada e pode disparar!\n", j2.nome);
            int disparo = rand() % max_balas;
            if(disparo < balas) {
                printf("%s atirou e acertou %s! %s morreu.\n", j2.nome, j1.nome, j1.nome);
                j1.vivo = 0;
                break;
            } else {
                printf("%s atirou, mas não tinha bala!\n", j2.nome);
                int opc;
                printf("%s, deseja aumentar a dificuldade? (0=não, 1=sim): ", j2.nome);
                scanf("%d", &opc);
                if(opc == 1 && balas < max_balas) {
                    balas++;
                    printf("Dificuldade aumentada! Agora o revólver tem %d balas.\n", balas);
                } else if(opc == 1 && balas >= max_balas) {
                    printf("O revólver já está no máximo de balas (%d)!\n", max_balas);
                }
            }
        }

        rodada++;
    }

    printf("\n=== Fim do Jogo ===\n");
    if(j1.vivo && j2.vivo) printf("Fim das 5 rodadas! Ninguém foi eliminado.\n");
    else if(j1.vivo) printf("%s venceu o jogo!\n", j1.nome);
    else if(j2.vivo) printf("%s venceu o jogo!\n", j2.nome);
    else printf("Ambos foram eliminados!\n");

    return 0;
}


#endif