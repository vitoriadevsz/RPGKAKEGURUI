
 


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vmenu.h"
#include "jogo21.h"
#include "ppt.h"
#include "vd.h"



void realizarCadastro() {
    int personagem1, personagem2;

    printf("Bem vindo(a) à Academia Hyakkaou... Onde perder não é uma opção!");
    printf("\n__");

    // --- JOGADOR 1 ---
    printf("\n\nInforme o nome do Jogador 1: ");
    scanf("%19s", ptrNomeJogador1);  // usando ponteiro
    
    printf("\n ESCOLHA UM PERSONAGEM (%s) \n", ptrNomeJogador1);
    printf("1 - Yumeko Jabami\n2 - Ryota Suzui\n3 - Mary Saotome\n4 - Itsuki Sumeragi\n5 - Kirari Momobami\n");
    printf("Digite um número: ");
    scanf("%d", &personagem1);

    switch (personagem1){
        case 1: printf(" >> Yumeko: Vamos apostar até o último suspiro!\n"); strcpy(ptrNomePersonagem1, "Yumeko Jabami"); break;
        case 2: printf(" >> Ryota: Espero que você não seja um peso.\n"); strcpy(ptrNomePersonagem1, "Ryota Suzui"); break;
        case 3: printf(" >> Mary: Não espere piedade. Eu vou vencer.\n"); strcpy(ptrNomePersonagem1, "Mary Saotome"); break;
        case 4: printf(" >> Itsuki: Mostre seu valor. Eu gosto de apostas altas.\n"); strcpy(ptrNomePersonagem1, "Itsuki Sumeragi"); break;
        case 5: printf(" >> Kirari: Surpreenda-me... se puder.\n"); strcpy(ptrNomePersonagem1, "Kirari Momobami"); break;
        default: printf(" OPÇÃO INVÁLIDA! (Seguindo como desconhecido)\n"); strcpy(ptrNomePersonagem1, "Desconhecido"); break;
    }

    // --- JOGADOR 2 ---
    printf("\n\nInforme o nome do Jogador 2: ");
    scanf("%19s", ptrNomeJogador2);  // usando ponteiro

    do {
        printf("\n ESCOLHA UM PERSONAGEM (%s) \n", ptrNomeJogador2);
        printf("1 - Yumeko Jabami\n2 - Ryota Suzui\n3 - Mary Saotome\n4 - Itsuki Sumeragi\n5 - Kirari Momobami\n");
        printf("Digite um número: ");
        scanf("%d", &personagem2);

        if (personagem2 == personagem1){
            printf("\nOpção inválida! O Jogador 1 já escolheu este personagem. Escolha outro.\n");
        }
    } while (personagem2 == personagem1);

    switch (personagem2){
        case 1: printf(" >> Yumeko: Tente não desmoronar... isso me entediaria.\n"); strcpy(ptrNomePersonagem2, "Yumeko Jabami"); break;
        case 2: printf(" >> Ryota: Espero que consiga acompanhar.\n"); strcpy(ptrNomePersonagem2, "Ryota Suzui"); break;
        case 3: printf(" >> Mary: Eu vou te esmagar antes que perceba.\n"); strcpy(ptrNomePersonagem2, "Mary Saotome"); break;
        case 4: printf(" >> Itsuki: Perder agora seria humilhante.\n"); strcpy(ptrNomePersonagem2, "Itsuki Sumeragi"); break;
        case 5: printf(" >> Kirari: Mostre algo digno... ou suma.\n"); strcpy(ptrNomePersonagem2, "Kirari Momobami"); break;
        default: printf(" OPÇÃO INVÁLIDA! (Seguindo como desconhecido)\n"); strcpy(ptrNomePersonagem2, "Desconhecido"); break;
    }
    int op;
    printf("1 para jogo 21 2 pedra papel tesoura com roleta russa 3 verdade ou desafio ");
    scanf("%d",&op);
    getchar();
    
    switch(op){
        case 1:
           jogodecarta(); 
         break;
         
        case 2:
         PptRussa();
         break;
         
        case 3:
         verdadeD();
         break;
    }

    printf("\n\nPERSONAGENS DEFINIDOS! PREPAREM-SE PARA A APOSTA DE VIDA OU MORTE...");
    printf("\nPressione ENTER para continuar.");
    getchar(); getchar(); // Pausa para leitura
}


