#include <stdio.h>
#include <stdlib.h>
#include <string.h>    // Para strcpy
#include <time.h>
#include "vmenu.h"     // para ptrNomePersonagem1/2
#include "jogo21.h"
#include  "falas.h"
#include "menu.h"// struct jogador e protótipos
    // seu arquivo de falas, se tiver
    
    
/*      
mostrarFala(ptrNomePersonagem1, 0);
mostrarFala(ptrNomePersonagem2, 0);

mostrarFala(ptrNomePersonagem1, 1);
mostrarFala(ptrNomePersonagem2, 1);

mostrarFala(ptrNomePersonagem1, 2);
mostrarFala(ptrNomePersonagem2, 3);*/



// Função para somar as cartas na mão
int somaDaMao(struct jogador j) {
    int soma = 0, cont = 0;

    for (int k = 0; k < j.cartasNaMao; k++) {
        int rank = j.mao[k] % 13;
        int valor = (rank == 0) ? 11 : (rank <= 9 ? rank + 1 : 10);
        soma += valor;
        if (valor == 11) cont++;
    }

    while (soma > 21 && cont--) soma -= 10;

    return soma;
}

// Função principal do jogo 21
int jogodecarta() {
    srand(time(NULL));

    int deck[52];
    int i, j, r;
    int quantidadeJogadores = 2;

    printf("Iniciando o jogo 21...\n");

    struct jogador jg[quantidadeJogadores];

    jg[0].pontos = 0; jg[0].dedos = 5; jg[0].cartasNaMao = 0;
    strcpy(jg[0].nome, ptrNomePersonagem1);

    jg[1].pontos = 0; jg[1].dedos = 5; jg[1].cartasNaMao = 0;
    strcpy(jg[1].nome, ptrNomePersonagem2);

    for (int rodada = 1; rodada <= 5; rodada++) {
        printf("\n=== Rodada %d ===\n", rodada);

        for (i = 0; i < quantidadeJogadores; i++)
            jg[i].cartasNaMao = 0;

        int indiceDoDeck = 0;

        for (i = 0; i < 52; i++) deck[i] = i;

        for (i = 0; i < 52; i++) {
            j = rand() % 52;
            r = deck[i]; deck[i] = deck[j]; deck[j] = r;
        }

        for (i = 0; i < 2; i++)
            for (j = 0; j < quantidadeJogadores; j++)
                jg[j].mao[jg[j].cartasNaMao++] = deck[indiceDoDeck++];

        int alguemFez21 = 0;

        while (indiceDoDeck < 52 && !alguemFez21) {
            for (i = 0; i < quantidadeJogadores; i++) {
                int soma = somaDaMao(jg[i]);

                if (soma > 21) {
                    printf("\n%s já estourou!\n", jg[i].nome);
                    continue;
                }

                printf("\n%s, sua mão atual: ", jg[i].nome);
                for (int k = 0; k < jg[i].cartasNaMao; k++) {
                    int carta = jg[i].mao[k];
                    int rank = carta % 13;
                    int naipe = carta / 13;

                    if (rank == 0) printf("A");
                    else if (rank <= 9) printf("%d", rank + 1);
                    else if (rank == 10) printf("J");
                    else if (rank == 11) printf("Q");
                    else printf("K");

                    if      (naipe == 0) printf("♣ ");
                    else if (naipe == 1) printf("♦ ");
                    else if (naipe == 2) printf("♥ ");
                    else                 printf("♠ ");
                }
                printf(" (Soma: %d)\n", soma);

                if (soma == 21) {
                    printf("%s fez 21!\n", jg[i].nome);
                    alguemFez21 = 1;
                    break;
                }

                if (jg[i].cartasNaMao >= 10) {
                    printf("%s atingiu o máximo de cartas.\n", jg[i].nome);
                    continue;
                }

                if (soma < 21 && jg[i].dedos > 0) {
                    char escolha;
                    printf("Deseja cavar uma carta? (s/n/c): ");
                    scanf(" %c", &escolha);

                    if (escolha == 'n' || escolha == 'N') {
                        printf("%s decidiu parar.\n", jg[i].nome);
                        continue;
                    }

                    if (escolha == 's' || escolha == 'S') {
                        if (indiceDoDeck < 52)
                            jg[i].mao[jg[i].cartasNaMao++] = deck[indiceDoDeck++];
                        else
                            printf("O deck acabou!\n");
                    }
                    
                     if (escolha == 'c' || escolha == 'C') {
                    
                    printf("voutando para o menu princimal...........");
                     realizarCadastro();
                }
                }
               
                
            }

            int todosTravados = 1;
            for (int x = 0; x < quantidadeJogadores; x++) {
                int somaX = somaDaMao(jg[x]);
                if (somaX <= 21 && jg[x].cartasNaMao < 10) {
                    todosTravados = 0;
                    break;
                }
            }

            if (todosTravados) {
                printf("\nTodos os jogadores estão travados. Encerrando a rodada.\n");
                break;
            }
        }

        int vencedor = -1, maiorSoma = 0;
        for (i = 0; i < quantidadeJogadores; i++) {
            int soma = somaDaMao(jg[i]);
            if (soma <= 21 && soma > maiorSoma) {
                maiorSoma = soma;
                vencedor = i;
            }
        }

        if (vencedor != -1) {
            printf("\n%s venceu a rodada com %d!\n", jg[vencedor].nome, maiorSoma);
            jg[vencedor].pontos += 10;
        } else {
            printf("\nNinguém venceu a rodada.\n");
        }

        for (i = 0; i < quantidadeJogadores; i++) {
            if (i != vencedor) jg[i].dedos--;
            printf("%s: %d pontos, %d dedos\n", jg[i].nome, jg[i].pontos, jg[i].dedos);
        }
    }

    printf("\n=== Pontuação Final ===\n");
    for (i = 0; i < quantidadeJogadores; i++)
        printf("%s: %d pontos, %d dedos\n", jg[i].nome, jg[i].pontos, jg[i].dedos);

    return 0;
}
