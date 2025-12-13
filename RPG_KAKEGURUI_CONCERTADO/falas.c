#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "vmenu.h"
#include "falas.h"

void FalasYumekoinicio() {
    char falainicio[5][200] = {
        "Oh? Você realmente acha que consegue me impressionar com tão pouco? Que adorável…",
        "Hehehe… já estou sentindo o arrepio da sua insegurança. Continue assim.",
        "Uau… essa sua confiança barata quase me fez rir alto. Quase.",
        "Você parece tão certo de si… é fofo. E extremamente patético.",
        "Então é com isso que você vem? Hmmm… decepcionante, mas divertido."
    };
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
    int r = rand() % 5;
    printf("%s\n", faladerrota[r]);
}

void FalasRyotainicio() {
    char falainicio[5][200] = {
        "Ah, então é isso que você chama de estratégia? Interessante…",
        "Hmm, pensei que viria com algo mais digno… mas tudo bem.",
        "Heh, você chega com tudo e ainda acha que pode me surpreender? Fofo.",
        "Então é assim que joga? Eu estava esperando algo realmente desafiador.",
        "Sério mesmo? Isso é o seu melhor? Estou quase com pena."
    };
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
    int r = rand() % 5;
    printf("%s\n", falameio[r]);
}

void FalasRyotavitoria() {
    char falavitoria[5][200] = {
        "Hahaha, fácil demais! Você viu o que acabou de acontecer, não é mesmo?",
        "Vitória garantida… e você ainda tentou me acompanhar!",
        "Ah, que divertido! Aposto que não esperava que eu fosse tão rápido.",
        "Uau, que batalha! Pena que você ficou um passo atrás o tempo todo.",
        "Haha, vitória minha… e você só está assistindo, né? Admito que foi divertido."
    };
    int r = rand() % 5;
    printf("%s\n", falavitoria[r]);
}

void FalasRyotaderrota() {
    char faladerrota[5][200] = {
        "Perdemos… você viu isso, não é? Preciso rever meus cálculos.",
        "Hmm… parece que subestimei você. É hora de ajustar minha estratégia.",
        "Não subestime os detalhes… e você acabou de provar isso.",
        "Certo… analisando seus movimentos, vejo onde falhei.",
        "A derrota é apenas mais uma lição… e você acabou de me ensinar uma."
    };
    int r = rand() % 5;
    printf("%s\n", faladerrota[r]);
}

void FalasMaryinicio() {
    char falainicio[5][201] = {
        "Vamos lá, jogador. Não me faça bocejar logo no começo, ou vou achar que você é só enfeite igual tapete de entrada.",
        "Preparado? Espero que sim. Não quero ter que te carregar igual mala pesada em viagem barata.",
        "Heh… jogador, se perder o ritmo agora, prometo que faço parecer que foi sua culpa desde o início.",
        "O jogo começou! Tenta não tropeçar, ok? Eu não trouxe rodinhas pra te empurrar.",
        "Beleza, jogador. Se ficar lento demais, eu finjo que nem te conheço. Mais elegante assim."
    };
    int r = rand() % 5;
    printf("%s\n", falainicio[r]);
}

void FalasMarymelho() {
    char falamelho[5][201] = {
        "Agora sim, jogador! Você finalmente acertou uma. Quase achei que ia precisar te explicar com desenhos.",
        "Hehehe… tá pegando fogo! Continue assim ou vou achar que foi pura sorte de principiante.",
        "Olha só, jogador… você surpreendeu. Achei que ia ser só decoração, tipo planta de escritório.",
        "Estamos no auge! Se escorregar agora, eu juro que vou rir. Mas só um pouco… ou muito.",
        "Boa! Continue assim e talvez, só talvez, eu pare de te subestimar por cinco segundos."
    };
    int r = rand() % 5;
    printf("%s\n", falamelho[r]);
}

void FalasMaryvitoria() {
    char falavitoria[5][201] = {
        "Ha! Vencemos, jogador! Mas vamos combinar: eu fiz o trabalho e você fez… presença. Considero isso caridade.",
        "Vitória! E olha só, você conseguiu não estragar tudo. Milagre? Talvez. Talento meu? Com certeza.",
        "Ganhamos! Ou melhor… eu ganhei e deixei você ficar junto pra foto. Não precisa agradecer.",
        "Vitória na mão! Jogador, você viu? Até quando você só observa, eu faço o show acontecer.",
        "Conseguimos! E digo isso com carinho: você ajudou tanto quanto um mascote. Mas foi fofo."
    };
    int r = rand() % 5;
    printf("%s\n", falavitoria[r]);
}

void FalasMaryderrota() {
    char faladerrota[5][201] = {
        "Perdemos… Jogador, você caiu tão rápido que nem deu tempo de fingir que foi culpa minha.",
        "Derrota. E olha… eu até tentei salvar, mas você mergulhou de cabeça no erro. Belo estilo, pelo menos.",
        "Não deu. Se você tivesse um pouco mais de ritmo, eu prometo que não estaria rindo por dentro agora.",
        "Perdemos, jogador. Mas relaxa… acontece. Só não faça virar hábito, tá?",
        "Derrota amarga. E sinceramente? Você caiu tão bonito que quase pareceu planejado."
    };
    int r = rand() % 5;
    printf("%s\n", faladerrota[r]);
}

void FalasItsukiinicio() {
    char falainicio[5][200] = {
        "Itsuki: Ahh… você chegou. Que fofo. Vou destruir você com tanta elegância que vai até agradecer.",
        "Itsuki: Entre e sorria. Quero assistir o exato momento em que sua confiança desmorona.",
        "Itsuki: Novatos são meus favoritos… eles quebram tão rápido que mal dá tempo de aquecer.",
        "Itsuki: Vamos jogar? Meu coração vibra só de imaginar seu desespero crescendo.",
        "Itsuki: Cuidado. Eu coleciono derrotas de adversárias como troféus… e você vai virar mais um."
    };
    int r = rand() % 5;
    printf("%s\n", falainicio[r]);
}

void FalasItsukimelho() {
    char falamelho[5][200] = {
        "Itsuki: Ótimo! Continue! Nada me excita mais que alguém tentando superar o inevitável.",
        "Itsuki: Hahaha… ousado. Tenho quase vontade de te aplaudir. Quase.",
        "Itsuki: Interessante… você realmente tentou. Adoro ilusões assim.",
        "Itsuki: Isso! Reaja mais! Cada tentativa sua alimenta minha alegria cruel.",
        "Itsuki: Surpreendente. Você fez algo certo. Não se acostume, é raro."
    };
    int r = rand() % 5;
    printf("%s\n", falamelho[r]);
}

void FalasItsukivitoria() {
    char falavitoria[5][200] = {
        "Itsuki: Vitória perfeita. E só porque VOCÊ, jogador, não atrapalhou. Milagre raro.",
        "Itsuki: Ganhei! E você jogou bem… inacreditável. O mundo realmente está acabando.",
        "Itsuki: Venci. Claro. Mas parabéns por não ser inútil dessa vez, jogador.",
        "Itsuki: Maravilhoso! Jogador, você brilhou tanto que quase achei que tinha cérebro.",
        "Itsuki: Ahhh vitória doce… jogador, devo admitir: você foi útil. Não se acostume."
    };
    int r = rand() % 5;
    printf("%s\n", falavitoria[r]);
}

void FalasItsukiderrota() {
    char faladerrota[5][200] = {
        "Itsuki: Derrota? Ah, que vergonha… Jogador! Você respirou errado e estragou tudo!",
        "Itsuki: Perder assim? Jogador, seu desastre é contagioso! Quase vomitei.",
        "Itsuki: Culpa sua, jogador! Você fede a azar! Até minhas cartas sentiram nojo.",
        "Itsuki: Ei, jogador! Quem te ensinou a jogar, um pombo? Sou obrigada a perder contigo por perto.",
        "Itsuki: Hahaha— olha isso! Jogador, sua burrice é tão grande que virou arma contra mim!"
    };
    int r = rand() % 5;
    printf("%s\n", faladerrota[r]);
}

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
    else if (strcmp(personagem, "Mary Saotome") == 0) {
        if (tipo == 0) FalasMaryinicio();
        else if (tipo == 1) FalasMarymelho();
        else if (tipo == 2) FalasMaryvitoria();
        else if (tipo == 3) FalasMaryderrota();
    }
    else if (strcmp(personagem, "Itsuki Sumeragi") == 0) {
        if (tipo == 0) FalasItsukiinicio();
        else if (tipo == 1) FalasItsukimelho();
        else if (tipo == 2) FalasItsukivitoria();
        else if (tipo == 3) FalasItsukiderrota();
    }
}
