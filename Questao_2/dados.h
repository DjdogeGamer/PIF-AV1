#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//decisão de quem começa o jogo
int DadosIniciais() {
    int j;
    int dado1, dado2;
    int resultado1, resultado2;

    //dados jogador 2
    printf("Jogador 1: \n");

    printf("Dado 1...\n");
    dado1 = (1 + rand() % 6);
    printf("%i\n", dado1);

    printf("Dado 2...\n");
    dado2 = (1 + rand() % 6);
    printf("%i\n", dado2);

    resultado1 = dado1 + dado2;
    printf("Soma dos dados = %i\n", resultado1);

    //dados jogador 2
    printf("Jogador 2: \n");

    printf("Dado 1...\n");
    dado1 = (1 + rand() % 6);
    printf("%i\n", dado1);

    printf("Dado 2...\n");
    dado2 = (1 + rand() % 6);
    printf("%i\n", dado2);

    resultado2 = dado1 + dado2;
    printf("Soma dos dados = %i\n", resultado2);

    if(resultado1 > resultado2) {
        return j = 1;
    } else {
        return j = 2;
    }
}

//funçaõ para jogar dado
int jogarDado() {
    int dado;
    return dado = 1 + rand() % 6;
}