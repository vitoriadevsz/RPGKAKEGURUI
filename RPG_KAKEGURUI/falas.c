#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> // Necessário para strcmp
#include "vmenu.h"

// ----------------- FALAS YUMEKO -----------------
void FalasYumekoinicio() {
    char falainicio[5][200] = {
        "Oh? Você realmente acha que consegue me impressionar com tão pouco? Que adorável…",
        "Hehehe… já estou sentindo o arrepio da sua insegurança. Continue assim.",
        "Uau… essa sua confiança barata quase me fez rir alto. Quase.",
        "Você parece tão certo de si… é fofo. E extremamente patético.",
        "Então é com isso que você vem? Hmmm… decepcionante, mas divertido."
    };
    srand(time(NULL));
    int r = rand() % 5;
    printf("%s\n", falainicio[r]);
}

void FalasYumekomelho() {
    char falameio[5][200] = {
        "Ahhh, eu estou adorando ver você tremer. Mostre mais desse desespero!",
        "Você realmente acredita que tem alguma chance? Isso é tão… delicioso.",
        "Seu esforço é tão frágil que eu mal consigo levar a sério. Mas me divirta, vai.",
        "Está suando? Que lindo. Nada como alguém afundando diante de mim.",
        "Hahaha… quanto mais luta, mais evidente fica o quanto você é previsível."
    };
    srand(time(NULL));
    int r = rand() % 5;
    printf("%s\n", falameio[r]);
}

void Falasyumekoitoria() {
    char falavitoria[5][200] = {
        "Vencemos! Hehehe… claro que foi graças a mim. Mas seu pequeno empurrãozinho até ajudou.",
        "Hahaha! Eles não tiveram chance! Eu fiz tudo, mas você até que não atrapalhou dessa vez.",
        "A vitória é minha, obviamente. Mas olha só… você conseguiu ser útil por alguns segundos.",
        "Fantástico! Senti o medo deles o tempo inteiro… e você ajudou um pouquinho. Um pouquinho.",
        "Essa vitória tem meu nome em letras enormes… o seu pode ficar pequeno no canto, só para não reclamar."
    };
    srand(time(NULL));
    int r = rand() % 5;
    printf("%s\n", falavitoria[r]);
}

void FalasYumekoderrota() {
    char faladerrota[5][200] = {
        "Perdemos? Hahaha… sério mesmo? Eu só caí por causa de VOCÊ. Se eu estivesse sozinha, teria vencido facilmente.",
        "Que vergonha… tudo por culpa sua. Eu me diverti, claro, mas você estragou o final. Patético.",
        "Eu quase virei tudo, mas aí você fez aquela besteira. Não espere que eu te console.",
        "Eu não perdi… VOCÊ me arrastou pra baixo. Tente ao menos não atrapalhar da próxima vez.",
        "Derrota? Não pra mim. Pra mim é só prova de que com você do lado, nem eu faço milagres."
    };
    srand(time(NULL));
    int r = rand() % 5;
    printf("%s\n", faladerrota[r]);
}

// ----------------- FALAS RYOTA -----------------
void FalasRyotainicio() {
    char falainicio[5][200] = {
        "Ah, então é isso que você chama de estratégia? Interessante…",
        "Hmm, pensei que viria com algo mais digno… mas tudo bem.",
        "Heh, você chega com tudo e ainda acha que pode me surpreender? Fofo.",
        "Então é assim que joga? Eu estava esperando algo realmente desafiador.",
        "Sério mesmo? Isso é o seu melhor? Estou quase com pena."
    };
    srand(time(NULL));
    int r = rand() % 5;
    printf("%s\n", falainicio[r]);
}

void FalasRyotamelho() {
    char falameio[5][200] = {
        "Hahaha, sério que você tentou isso? Muito engraçado!",
        "Cada movimento seu só me faz rir mais… continue assim.",
        "Nossa, quase consegui me concentrar… mas aí você fez isso.",
        "Ah, você acha que isso me derruba? Que adorável ilusão.",
        "Patético, mas devo admitir, você me diverte."
    };
    srand(time(NULL));
    int r = rand() % 5;
    printf("%s\n", falameio[r]);
}

void FalasRyotaderrota() {
    char faladerrota[5][200] = {
        "Perdemos… você viu isso, não é? Preciso rever meus cálculos.",
        "Hmm… parece que subestimei você. É hora de ajustar minha estratégia.",
        "Não subestime os detalhes… e você acabou de provar isso.",
        "Certo… analisando seus movimentos, vejo onde falhei.",
        "A derrota é apenas mais uma lição… e você acabou de me ensinar uma."
    };
    srand(time(NULL));
    int r = rand() % 5;
    printf("%s\n", faladerrota[r]);
}

void FalasRyotavitoria() {
    char falavitoria[5][200] = {
        "Hahaha, fácil demais! Você viu o que acabou de acontecer, não é mesmo?",
        "Vitória garantida… e você ainda tentou me acompanhar!",
        "Ah, que divertido! Aposto que não esperava que eu fosse tão rápido.",
        "Uau, que batalha! Pena que você ficou um passo atrás o tempo todo.",
        "Haha, vitória minha… e você só está assistindo, né? Admito que foi divertido."
    };
    srand(time(NULL));
    int r = rand() % 5;
    printf("%s\n", falavitoria[r]);
}

// ----------------- FUNÇÃO MOSTRAR FALA -----------------
void mostrarFala(char *personagem, int tipo) {
    if (strcmp(personagem, "Yumeko Jabami") == 0) {
        if (tipo == 0) FalasYumekoinicio();
        else if (tipo == 1) FalasYumekomelho();
        else if (tipo == 2) Falasyumekoitoria();
        else if (tipo == 3) FalasYumekoderrota();
    }
    else if (strcmp(personagem, "Ryota Suzui") == 0) {
        if (tipo == 0) FalasRyotainicio();
        else if (tipo == 1) FalasRyotamelho();
        else if (tipo == 2) FalasRyotavitoria();
        else if (tipo == 3) FalasRyotaderrota();
    }
    else if (strcmp(personagem, "Mary Saotome") == 0) { /* ... */ }
    else if (strcmp(personagem, "Itsuki Sumeragi") == 0) { /* ... */ }
    else if (strcmp(personagem, "Kirari Momobami") == 0) { /* ... */ }
}
