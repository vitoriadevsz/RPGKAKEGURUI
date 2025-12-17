#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ========== VARIAVEIS GLOBAIS ==========
char nomeJogador1[20];
char nomeJogador2[20];
char nomePersonagem1[30];
char nomePersonagem2[30];

char *ptrNomeJogador1 = nomeJogador1;
char *ptrNomeJogador2 = nomeJogador2;
char *ptrNomePersonagem1 = nomePersonagem1;
char *ptrNomePersonagem2 = nomePersonagem2;

// ========== ESTRUTURAS ==========
struct jogador {
    char nome[20];
    int mao[10];
    int cartasNaMao;
    int pontos;
    int dedos;
};

struct Jogador {
    char nome[20];
    int escolha;
    int vivo;
};

// ========== PROTOTIPOS DE FUNCOES ==========
void realizarCadastro();
int jogodecarta();
int PptRussa();
int verdadeD();
int somaDaMao(struct jogador j);
void limpar_tela();
void limparBuffer();

// ========== FUNCAO PRINCIPAL ==========
int main() {
    realizarCadastro();
    return 0;
}

// ========== FUNCOES AUXILIARES ==========
void limpar_tela() {
    system("cls");  // Para Windows no Dev-C++
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// ========== FUNCAO somaDaMao (JOGO 21) ==========
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

// ========== JOGO 21 ==========
int jogodecarta() {
    srand(time(NULL));
    int deck[52];
    int i, j, r;
    int quantidadeJogadores = 2;

    printf("Iniciando o jogo 21...\n");

    struct jogador jg[quantidadeJogadores];

    jg[0].pontos = 0; jg[0].cartasNaMao = 0;
    strcpy(jg[0].nome, ptrNomePersonagem1);

    jg[1].pontos = 0; jg[1].cartasNaMao = 0;
    strcpy(jg[1].nome, ptrNomePersonagem2);

    for (int rodada = 1; rodada <= 2; rodada++) {
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
                    printf("\n%s ja estourou!\n", jg[i].nome);
                    continue;
                }

                printf("\n%s, sua mao atual: ", jg[i].nome);
                for (int k = 0; k < jg[i].cartasNaMao; k++) {
                    int carta = jg[i].mao[k];
                    int rank = carta % 13;
                    int naipe = carta / 13;

                    if (rank == 0) printf("A");
                    else if (rank <= 9) printf("%d", rank + 1);
                    else if (rank == 10) printf("J");
                    else if (rank == 11) printf("Q");
                    else printf("K");

                    if      (naipe == 0) printf("C ");
                    else if (naipe == 1) printf("O ");
                    else if (naipe == 2) printf("Co ");
                    else                 printf("E ");
                }
                printf(" (Soma: %d)\n", soma);

                if (soma == 21) {
                    printf("%s fez 21!\n", jg[i].nome);
                    alguemFez21 = 1;
                    break;
                }

                if (jg[i].cartasNaMao >= 10) {
                    printf("%s atingiu o maximo de cartas.\n", jg[i].nome);
                    continue;
                }

                if (soma < 21) {
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
                        printf("Voltando para o menu principal...........");
                        realizarCadastro();
                        return 0;
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
                printf("\nTodos os jogadores estao travados. Encerrando a rodada.\n");
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
            printf("\n%s venceu a rodada com %d pontos!\n", jg[vencedor].nome, maiorSoma);
            jg[vencedor].pontos += 10;
        } else {
            printf("\nNinguem venceu a rodada.\n");
        }

        printf("\n=== Placar Atual ===\n");
        for (i = 0; i < quantidadeJogadores; i++) {
            printf("%s: %d pontos\n", jg[i].nome, jg[i].pontos);
        }
    }

    printf("\n=== Pontuacao Final ===\n");
    for (i = 0; i < quantidadeJogadores; i++)
        printf("%s: %d pontos\n", jg[i].nome, jg[i].pontos);
    
    if (jg[0].pontos > jg[1].pontos)
        printf("\n%s venceu o jogo com %d pontos!\n", jg[0].nome, jg[0].pontos);
    else if (jg[1].pontos > jg[0].pontos)
        printf("\n%s venceu o jogo com %d pontos!\n", jg[1].nome, jg[1].pontos);
    else
        printf("\nEmpate com %d pontos cada! Ambos jogaram muito bem!\n", jg[0].pontos);
        
    realizarCadastro();
    return 0;
}

// ========== PEDRA PAPEL TESOURA COM ROLETA RUSSA ==========
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
    
    printf(" === Jogo Pedra-Papel-Tesoura da Sorte === 🎮\n");
    printf(" Teste sua sorte e suas escolhas! \n\n");

    while (rodada <= 3) {
        printf("\n === Rodada %d === \n", rodada);
        printf("1=Pedra  2=Papel  3=Tesoura\n");
        printf(" 0=Voltar ao menu principal\n\n");
        
        printf(" %s, escolha (1-3): ", j1.nome);
        scanf("%d", &j1.escolha);
        
        printf(" %s, escolha (1-3): ", j2.nome);
        scanf("%d", &j2.escolha);
        
        if (j1.escolha < 1 || j1.escolha > 3) {
            printf(" s jogou incorretamente e perdeu a vez!\n", j1.nome);
            printf(" %s gira a roda da sorte...\n", j2.nome);
            int disparo = rand() % max_balas;
            if (disparo < balas) {
                printf(" Que azar! %s deu muito azar e esta fora do jogo.\n", j1.nome);
                j1.vivo = 0;
                break;
            } else {
                printf(" Ufa! A sorte sorriu para %s!\n", j1.nome);
            }
            rodada++;
            continue;
        }
        
        if (j2.escolha < 1 || j2.escolha > 3) {
            printf(" %s jogou incorretamente e perdeu a vez!\n", j2.nome);
            printf(" %s gira a roda da sorte...\n", j1.nome);
            int disparo = rand() % max_balas;
            if (disparo < balas) {
                printf(" Que azar! %s deu muito azar e esta fora do jogo.\n", j2.nome);
                j2.vivo = 0;
                break;
            } else {
                printf(" Ufa! A sorte sorriu para %s!\n", j2.nome);
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
            printf(" Empate! Ninguem gira a roda dessa vez.\n");
        } else if (vencedor == 1) {
            printf(" %s venceu a rodada!\n", j1.nome);
            printf(" %s gira a roda da sorte...\n", j1.nome);
            int disparo = rand() % max_balas;
            if (disparo < balas) {
                printf(" Que azar! %s deu muito azar e esta fora do jogo.\n", j2.nome);
                j2.vivo = 0;
                break;
            } else {
                printf(" Ufa! A sorte sorriu para %s!\n", j2.nome);
            }
        } else {
            printf(" %s venceu a rodada!\n", j2.nome);
            printf(" %s gira a roda da sorte...\n", j2.nome);
            int disparo = rand() % max_balas;
            if (disparo < balas) {
                printf(" Que azar! %s deu muito azar e esta fora do jogo.\n", j1.nome);
                j1.vivo = 0;
                break;
            } else {
                printf(" Ufa! A sorte sorriu para %s!\n", j1.nome);
            }
        }
        
        rodada++;
    }
    
    printf("\n === Fim do Jogo === \n");
    if (j1.vivo && j2.vivo)
        printf("Fim das rodadas! Ambos continuam no jogo! \n");
    else if (j1.vivo)
        printf(" %s venceu o jogo! Parabens! \n", j1.nome);
    else if (j2.vivo)
        printf(" %s venceu o jogo! Parabens! \n", j2.nome);
    else
        printf(" Ambos saíram do jogo! Foi emocionante!\n");
    
    realizarCadastro();
    return 0;
}

// ========== VERDADE OU DESAFIO ==========
int verdadeD() {
    srand(time(NULL));

    struct JogadorVD {
        char nome[50];
        int vidas_perdidos;
    };

    struct JogadorVD jogadores[2];
    char pergunta[200], resposta_certa[200], resposta_jogador[200], desafio[200];
        
        char membros[5][20] = {
        "perdeu pontos",
        "perdeu pontos",
        "perdeu pontos",
        "perdeu pontos",
        "perdeu pontos"
    };
    

    char desafios_aleatorios[18][200] = {
        "Fique de pe em uma perna por 10 segundos",
        "Cante uma musica inventada",
        "Diga o alfabeto ao contrario",
        "Imite um animal por 5 segundos",
        "Fale uma palavra sem usar vogais",
        "Conte uma mentira engracada",
        "Faca 5 polichinelos",
        "Fale um trava-lingua rapido",
        "Finja que esta nadando em um lago imaginario",
        "Dance uma coreografia maluca",
        "Imite um fantasma por 10 segundos",
        "Fale o nome de 5 frutas rapido",
        "Finja que esta escalando uma montanha",
        "Desenhe algo imaginario no ar",
        "Diga um segredo inventado",
        "Finja que esta preso em um labirinto",
        "Imite o som de um carro",
        "Fale uma palavra inventada e explique o significado"
    };

    printf("- Perguntas ou Desafios Ficticios\n\n");
    strcpy(jogadores[0].nome, ptrNomePersonagem1);
    strcpy(jogadores[1].nome, ptrNomePersonagem2);
    jogadores[0].vidas_perdidos = 0;
    jogadores[1].vidas_perdidos = 0;

    for (int rodada = 1; rodada <= 10; rodada++) {
        int perguntador = (rodada % 2 == 1) ? 0 : 1;
        int respondedor = 1 - perguntador;

        printf("%s, digite a pergunta: ", jogadores[perguntador].nome);
        fgets(pergunta, sizeof(pergunta), stdin);
        pergunta[strcspn(pergunta, "\n")] = 0;

        printf("\n%s, digite a resposta correta: ", jogadores[perguntador].nome);
        fgets(resposta_certa, sizeof(resposta_certa), stdin);
        resposta_certa[strcspn(resposta_certa, "\n")] = 0;

        limpar_tela();

        int escolha_respondedor;
        printf("%s, escolha sua opcao:\n", jogadores[respondedor].nome);
        printf("1 - Responder a pergunta\n");
        printf("2 - Cumprir desafio\n");
        printf("3 - Voltar ao menu principal\n");
        printf("Opcao: ");
        scanf("%d", &escolha_respondedor);
        limparBuffer();

        limpar_tela();

        if (escolha_respondedor == 3) {
            realizarCadastro();
            return 0;
        }

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
                int m = jogadores[respondedor].vidas_perdidos;
                printf("%s...%s.\n", jogadores[respondedor].nome, membros[m]);
                jogadores[respondedor].vidas_perdidos++;

                if (jogadores[respondedor].vidas_perdidos == 5) {
                    printf("\nPerdeu. %s venceu!\n", jogadores[perguntador].nome);
                    realizarCadastro();
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
                printf("\nVenceu!\n");
            } else {
                printf("\nFalhou!\n");
                int m = jogadores[respondedor].vidas_perdidos;
                printf("%s Falhou!  %s.\n", jogadores[respondedor].nome, membros[m]);
                jogadores[respondedor].vidas_perdidos++;

                if (jogadores[respondedor].vidas_perdidos == 5) {
                    printf("\nPerdeu. %s venceu!\n", jogadores[perguntador].nome);
                    realizarCadastro();
                    return 0;
                }
            }
        }

        printf("\nStatus atual:\n");
        printf("%s perdeu %d pontos.\n", jogadores[0].nome, jogadores[0].vidas_perdidos);
        printf("%s perdeu %d pontos.\n", jogadores[1].nome, jogadores[1].vidas_perdidos);

        printf("\nPressione Enter para a proxima rodada...");
        getchar();
        limpar_tela();
    }

    printf("\nFim do jogo!\n");
    if (jogadores[0].vidas_perdidos < jogadores[1].vidas_perdidos)
        printf("%s venceu!\n", jogadores[0].nome);
    else if (jogadores[1].vidas_perdidos < jogadores[0].vidas_perdidos)
        printf("%s venceu!\n", jogadores[1].nome);
    else
        printf("Empate!\n");

    realizarCadastro();
    return 0;
}

// ========== MENU PRINCIPAL ==========
void realizarCadastro() {
    int personagem1, personagem2;

    printf("Bem vindo(a) a Academia Hyakkaou... Onde perder nao e uma opcao!");
    printf("\n_______________________________________________________________");

    printf("\n\nInforme o nome do Jogador 1: ");
    scanf("%19s", ptrNomeJogador1);
    
    printf("\n ESCOLHA UM PERSONAGEM (%s) \n", ptrNomeJogador1);
    printf("1 - Yumeko Jabami\n2 - Ryota Suzui\n3 - Mary Saotome\n4 - Itsuki Sumeragi\n5 - Kirari Momobami\n");
    printf("Digite um numero: ");
    scanf("%d", &personagem1);

    switch (personagem1){
        case 1: printf(" >> Yumeko: Vamos apostar ate o ultimo suspiro!\n"); strcpy(ptrNomePersonagem1, "Yumeko Jabami"); break;
        case 2: printf(" >> Ryota: Espero que voce nao seja fraco.\n"); strcpy(ptrNomePersonagem1, "Ryota Suzui"); break;
        case 3: printf(" >> Mary: Nao espere piedade. Eu vou vencer.\n"); strcpy(ptrNomePersonagem1, "Mary Saotome"); break;
        case 4: printf(" >> Itsuki: Mostre seu valor. Eu gosto de apostas altas.\n"); strcpy(ptrNomePersonagem1, "Itsuki Sumeragi"); break;
        case 5: printf(" >> Kirari: Surpreenda-me... se puder.\n"); strcpy(ptrNomePersonagem1, "Kirari Momobami"); break;
        default: printf(" OPCAO INVALIDA! (Seguindo como desconhecido)\n"); strcpy(ptrNomePersonagem1, "Desconhecido"); break;
    }
    printf("______________________________________________________________________");
    printf("\n\nInforme o nome do Jogador 2: ");
    scanf("%19s", ptrNomeJogador2);

    do {
        printf("\n ESCOLHA UM PERSONAGEM (%s) \n", ptrNomeJogador2);
        printf("1 - Yumeko Jabami\n2 - Ryota Suzui\n3 - Mary Saotome\n4 - Itsuki Sumeragi\n5 - Kirari Momobami\n");
        printf("Digite um numero: ");
        scanf("%d", &personagem2);

        if (personagem2 == personagem1){
            printf("\nOpcao invalida! O Jogador 1 ja escolheu este personagem. Escolha outro.\n");
        }
    } while (personagem2 == personagem1);

    switch (personagem2){
        case 1: printf(" >> Yumeko: Tente nao desmoronar... isso me entediaria.\n"); strcpy(ptrNomePersonagem2, "Yumeko Jabami"); break;
        case 2: printf(" >> Ryota: Espero que consiga acompanhar.\n"); strcpy(ptrNomePersonagem2, "Ryota Suzui"); break;
        case 3: printf(" >> Mary: Eu vou te esmagar antes que perceba.\n"); strcpy(ptrNomePersonagem2, "Mary Saotome"); break;
        case 4: printf(" >> Itsuki: Perder agora seria humilhante.\n"); strcpy(ptrNomePersonagem2, "Itsuki Sumeragi"); break;
        case 5: printf(" >> Kirari: Mostre algo digno... ou suma.\n"); strcpy(ptrNomePersonagem2, "Kirari Momobami"); break;
        default: printf(" OPCAO INVALIDA! (Seguindo como desconhecido)\n"); strcpy(ptrNomePersonagem2, "Desconhecido"); break;
    }
    
    int op;
    printf("__________________________________________________________________");
    printf("\n\n=== ESCOLHA O JOGO ===\n");
    printf("1 - Jogo 21\n");
    printf("2 - Pedra Papel Tesoura\n");
    printf("3 - Verdade ou Desafio\n");
    printf("Digite o numero do jogo: ");
    scanf("%d", &op);
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
           
        default:
           printf("Opcao invalida!\n");
           realizarCadastro();
           break;
    }

    printf("\n\nPERSONAGENS DEFINIDOS! PREPAREM-SE PARA A APOSTA...");
    printf("\nPressione ENTER para continuar.");
    getchar(); 
    getchar();
}