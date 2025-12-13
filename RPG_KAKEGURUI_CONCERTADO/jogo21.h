#ifndef JOGO21_H
#define JOGO21_H

struct jogador {
    char nome[20];
    int mao[10];
    int cartasNaMao;
    int pontos;
    int dedos;
};

int somaDaMao(struct jogador j);
int jogodecarta();

#endif
