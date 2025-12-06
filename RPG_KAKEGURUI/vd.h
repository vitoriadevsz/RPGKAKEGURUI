#ifndef VD_H
#define VD_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "menu.h"
#include "vmenu.h"

void limpar_tela() {
    for (int i = 0; i < 50; i++) printf("\n");
}

// Função para limpar o buffer do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int verdadeD() {
    srand(time(NULL));

    struct Jogador {
        char nome[50];
        int membros_perdidos;
    };

    struct Jogador jogadores[2];
    char pergunta[200], resposta_certa[200], resposta_jogador[200], desafio[200];

    char membros[5][20] = {
        "braco direito",
        "braco esquerdo",
        "perna direita",
        "perna esquerda",
        "cabeca"
    };

    // Lista de 18 desafios aleatórios
    char desafios_aleatorios[18][200] = {
        "Fique de pé em uma perna por 10 segundos",
        "Cante uma música inventada",
        "Diga o alfabeto ao contrário",
        "Imite um animal por 5 segundos",
        "Fale uma palavra sem usar vogais",
        "Conte uma mentira engraçada",
        "Faça 5 polichinelos",
        "Fale um trava-língua rápido",
        "Finja que está nadando em um lago imaginário",
        "Dance uma coreografia maluca",
        "Imite um fantasma por 10 segundos",
        "Fale o nome de 5 frutas rápido",
        "Finja que está escalando uma montanha",
        "Desenhe algo imaginário no ar",
        "Diga um segredo inventado",
        "Finja que está preso em um labirinto",
        "Imite o som de um carro",
        "Fale uma palavra inventada e explique o significado"
    };

    // Entrada de nomes usando variáveis globais
    printf("Jogo de Terror Extremo - Perguntas ou Desafios Ficticios\n\n");
    strcpy(jogadores[0].nome, ptrNomePersonagem1);
    strcpy(jogadores[1].nome, ptrNomePersonagem2);
    jogadores[0].membros_perdidos = 0;
    jogadores[1].membros_perdidos = 0;

    for (int rodada = 1; rodada <= 10; rodada++) {
        int perguntador = (rodada % 2 == 1) ? 0 : 1;
        int respondedor = 1 - perguntador;

        // --- Perguntador prepara pergunta e resposta ---
        printf("%s, digite a pergunta: ", jogadores[perguntador].nome);
        fgets(pergunta, sizeof(pergunta), stdin);
        pergunta[strcspn(pergunta, "\n")] = 0;

        printf("\n%s, digite a resposta correta: ", jogadores[perguntador].nome);
        fgets(resposta_certa, sizeof(resposta_certa), stdin);
        resposta_certa[strcspn(resposta_certa, "\n")] = 0;

        limpar_tela();

        // --- Respondedor escolhe: pergunta ou desafio ---
        int escolha_respondedor;
        printf("%s, escolha sua opcao:\n", jogadores[respondedor].nome);
        printf("1 - Responder a pergunta\n");
        printf("2 - Cumprir desafio\n");
        printf("Opcao: ");
        scanf("%d", &escolha_respondedor);
        limparBuffer(); // limpa buffer do teclado

        limpar_tela();

        if (escolha_respondedor == 1) {
            printf("%s, responda a pergunta:\n%s\n", jogadores[respondedor].nome, pergunta);
            fgets(resposta_jogador, sizeof(resposta_jogador), stdin);
            resposta_jogador[strcspn(resposta_jogador, "\n")] = 0;

            char primeira_certa[50], primeira_resp[50];
            sscanf(resposta_certa, "%s", primeira_certa);
            sscanf(resposta_jogador, "%s", primeira_resp);

            if (strcmp(primeira_certa, primeira_resp) == 0) {
                printf("\nAcertou!\n");
            } else {
                printf("\nErrou!\n");
                int m = jogadores[respondedor].membros_perdidos;
                printf("%s perdeu o %s.\n", jogadores[respondedor].nome, membros[m]);
                jogadores[respondedor].membros_perdidos++;

                if (jogadores[respondedor].membros_perdidos == 5) {
                    printf("\nA cabeca caiu. %s venceu!\n", jogadores[perguntador].nome);
                    return 0;
                }
            }

        } else if (escolha_respondedor == 2) {
            int escolha_desafio;
            printf("%s, digite 1 para escrever o desafio ou 2 para deixar o sistema escolher: ", jogadores[perguntador].nome);
            scanf("%d", &escolha_desafio);
            limparBuffer();

            if (escolha_desafio == 1) {
                printf("Digite seu desafio: ");
                fgets(desafio, sizeof(desafio), stdin);
                desafio[strcspn(desafio, "\n")] = 0;
            } else {
                int indice = rand() % 18;
                strcpy(desafio, desafios_aleatorios[indice]);
            }

            limpar_tela();

            printf("%s, voce cumpriu o desafio ficticio? (sim/nao)\nDesafio: %s\n", jogadores[respondedor].nome, desafio);
            char resposta[10];
            fgets(resposta, sizeof(resposta), stdin);
            resposta[strcspn(resposta, "\n")] = 0;

            if (strcmp(resposta, "sim") == 0) {
                printf("\nSobreviveu ao terror imaginario!\n");
            } else {
                printf("\nFalhou!\n");
                int m = jogadores[respondedor].membros_perdidos;
                printf("%s perdeu o %s.\n", jogadores[respondedor].nome, membros[m]);
                jogadores[respondedor].membros_perdidos++;

                if (jogadores[respondedor].membros_perdidos == 5) {
                    printf("\nA cabeca caiu. %s venceu!\n", jogadores[perguntador].nome);
                    return 0;
                }
            }
        }

        // Status após a rodada
        printf("\nStatus atual:\n");
        printf("%s perdeu %d membros.\n", jogadores[0].nome, jogadores[0].membros_perdidos);
        printf("%s perdeu %d membros.\n", jogadores[1].nome, jogadores[1].membros_perdidos);

        printf("\nPressione Enter para a próxima rodada...");
        getchar(); // espera Enter
        limpar_tela();
    }

    // Fim do jogo
    printf("\nFim do jogo!\n");
    if (jogadores[0].membros_perdidos < jogadores[1].membros_perdidos)
        printf("%s venceu!\n", jogadores[0].nome);
    else if (jogadores[1].membros_perdidos < jogadores[0].membros_perdidos)
        printf("%s venceu!\n", jogadores[1].nome);
    else
        printf("Empate!\n");

    return 0;
}

#endif
