#include <stdio.h>

// Análise das posições:
// Linha de cima (início): comparará as condições de letras com a as letras abaixo (linha + 1 ou + 2)
// Coluna da direita (segunda seção): comparará as condições de letras com as letras a esquerda (coluna - 1 ou - 2)
// Linha de baixo (terceira seção): comparará as condições de letras com as letras acima (linha -1 ou -2)
// Coluna da esquerda (final): comparará as condições de letras com as letras a direita (coluna + 1 ou + 2)

/* Aplicação das regras das cores:
A célula branca representa um espaço neutro onde não há ação sobre o jogador = W / 02, 05, 07, 09, 14, 15, 18, 20, 23
A célula vermelha penaliza o jogador em 3 pontos de vida = R / 03, 10, 16, 21, 25
A célula verde recupera 1 ponto de vida do jogador = G / 04, 11, 17, 22, 27 
A célula amarela aprisiona o jogador por um turno sem jogar = Y / 08, 19, 26
A célula azul permite que o jogador jogue novamente = B / 06, 13, 24
A célula preta faz o jogador voltar para o início (desconsidere as células de início e fim) = P / 01, 12, 28
*/

//Ja que a preta so ocorre uma vez, nós preferimos colocar na casa especifica do case (case 11: matriz[4][11])
void analiseCores(int jog_da_vez, int* soma_dado, int posx_jog,int posy_jog,int* joghp, char matriz[11][14],int* jog_novamente,int* jog_semjogar){

    //jogador analisado
    if(jog_da_vez == 1){

        //linha inicial
        if (*soma_dado >= 1 && *soma_dado < 10){
            if(matriz[posx_jog][posy_jog + 1] == 'P'){
                printf("Casa preta, retorne ao inicio.");
            }
            if(matriz[posx_jog + 1][posy_jog] == 'W'){
                printf("Casa branca, escapou dessa vez.");
            }
            if(matriz[posx_jog + 1][posy_jog] == 'R'){
                printf("Casa vermelha, -3 de vida.");
                *joghp = *joghp - 3;
            }
            if(matriz[posx_jog + 1][posy_jog] == 'G'){
                if(*joghp < 10){
                    printf("Casa verde, +1 de vida.");
                    *joghp = *joghp + 1;
                }
                if(*joghp == 10){
                    printf("Vida cheia");
                }
            }
            if(matriz[posx_jog + 1][posy_jog] == 'Y'){ 
                printf("Casa amarela, um turno sem jogar.");
                *jog_semjogar = -1;
            }
            if(matriz[posx_jog + 1][posy_jog] == 'B'){ 
                printf("Casa azul, jogue novamente.");
                *jog_novamente = -1;
            }
        }

        //coluna da direita
        if (*soma_dado >= 10 && *soma_dado < 16){
            if(matriz[posx_jog][posy_jog + 1] == 'P'){
                printf("Casa preta, retorne ao inicio.");
            }
            if(matriz[posx_jog][posy_jog - 1] == 'W'){
                printf("Casa branca, escapou dessa vez.");
            }
            if(matriz[posx_jog][posy_jog - 1] == 'R'){
                printf("Casa vermelha, -3 de vida.");
                *joghp = *joghp - 3;
            }
            if(matriz[posx_jog][posy_jog - 1] == 'G'){
                if(*joghp < 10){
                    printf("Casa verde, +1 de vida.");
                    *joghp = *joghp + 1;
                }
                if(*joghp == 10){
                    printf("Vida cheia");
                }
            }
            if(matriz[posx_jog][posy_jog - 1] == 'Y'){ 
                printf("Casa amarela, um turno sem jogar.");
                *jog_semjogar = -1;
            }
            if(matriz[posx_jog][posy_jog - 1] == 'B'){ 
                printf("Casa azul, jogue novamente.");
                *jog_novamente = -1;
            }
        }

        //linha de baixo
        if (*soma_dado >= 16 && *soma_dado < 24){
            if(matriz[posx_jog][posy_jog + 1] == 'P'){
                printf("Casa preta, retorne ao inicio.");
            }
            if(matriz[posx_jog - 1][posy_jog] == 'W'){
                printf("Casa branca, escapou dessa vez.");
            }
            if(matriz[posx_jog - 1][posy_jog] == 'R'){
                printf("Casa vermelha, -3 de vida.");
                *joghp = *joghp - 3;
            }
            if(matriz[posx_jog - 1][posy_jog] == 'G'){
                if(*joghp < 10){
                    printf("Casa verde, +1 de vida.");
                    *joghp = *joghp + 1;
                }
                if(*joghp == 10){
                    printf("Vida cheia");
                }
            }
            if(matriz[posx_jog - 1][posy_jog] == 'Y'){ 
                printf("Casa amarela, um turno sem jogar.");
                *jog_semjogar = -1;
            }
            if(matriz[posx_jog - 1][posy_jog] == 'B'){ 
                printf("Casa azul, jogue novamente.");
                *jog_novamente = -1;
            }
        }

        //coluna final
        if(*soma_dado >= 25 && *soma_dado <= 27){
            if(matriz[posx_jog][posy_jog + 1] == 'P'){
                printf("Casa preta, retorne ao inicio.");
            }
            if(matriz[posx_jog][posy_jog + 1] == 'W'){
                printf("Casa branca, escapou dessa vez.");
            }
            if(matriz[posx_jog][posy_jog + 1] == 'R'){
                printf("Casa vermelha, -3 de vida.");
                *joghp = *joghp - 3;
            }
            if(matriz[posx_jog][posy_jog + 1] == 'G'){
                if(*joghp < 10){
                    printf("Casa verde, +1 de vida.");
                    *joghp = *joghp + 1;
                }
                if(*joghp == 10){
                    printf("Vida cheia");
                }
            }
            if(matriz[posx_jog][posy_jog + 1] == 'Y'){
                printf("Casa amarela, um turno sem jogar.");
                *jog_semjogar = -1;
            }
            if(matriz[posx_jog][posy_jog + 1] == 'B'){ 
                printf("Casa azul, jogue novamente.");
                *jog_novamente = -1;
            }
        }

    }

    //jogador analisado
    if(jog_da_vez == 2){

        //linha inicial
        if (*soma_dado >= 1 && *soma_dado < 10){
            if(matriz[posx_jog][posy_jog + 2] == 'P'){
                printf("Casa preta, retorne ao inicio.");
            }
            if(matriz[posx_jog + 2][posy_jog] == 'W'){
                printf("Casa branca, escapou dessa vez.");
            }
            if(matriz[posx_jog + 2][posy_jog] == 'R'){
                printf("Casa vermelha, -3 de vida.");
                *joghp = *joghp - 3;
            }
            if(matriz[posx_jog + 2][posy_jog] == 'G'){
                if(*joghp < 10){
                    printf("Casa verde, +1 de vida.");
                    *joghp = *joghp + 1;
                }
                if(*joghp == 10){
                    printf("Vida cheia");
                }
            }
            if(matriz[posx_jog + 2][posy_jog] == 'Y'){ 
                printf("Casa amarela, um turno sem jogar.");
                *jog_semjogar = -2;
            }
            if(matriz[posx_jog + 2][posy_jog] == 'B'){ 
                printf("Casa azul, jogue novamente.");
                *jog_novamente = -1;
            }
        }

        //coluna da direita
        if (*soma_dado >= 10 && *soma_dado < 16){
            if(matriz[posx_jog][posy_jog + 2] == 'P'){
                printf("Casa preta, retorne ao inicio.");
            }
            if(matriz[posx_jog][posy_jog - 2] == 'W'){
                printf("Casa branca, escapou dessa vez.");
            }
            if(matriz[posx_jog][posy_jog - 2] == 'R'){
                printf("Casa vermelha, -3 de vida.");
                *joghp = *joghp - 3;
            }
            if(matriz[posx_jog][posy_jog - 2] == 'G'){
                if(*joghp < 10){
                    printf("Casa verde, +1 de vida.");
                    *joghp = *joghp + 1;
                }
                if(*joghp == 10){
                    printf("Vida cheia");
                }
            }
            if(matriz[posx_jog][posy_jog - 2] == 'Y'){ 
                printf("Casa amarela, um turno sem jogar.");
                *jog_semjogar = -2;
            }
            if(matriz[posx_jog][posy_jog - 2] == 'B'){ 
                printf("Casa azul, jogue novamente.");
                *jog_novamente = -1;
            }
        }

        //linha de baixo
        if (*soma_dado >= 16 && *soma_dado < 24){
            if(matriz[posx_jog][posy_jog + 2] == 'P'){
                printf("Casa preta, retorne ao inicio.");
            }
            if(matriz[posx_jog - 2][posy_jog] == 'W'){
                printf("Casa branca, escapou dessa vez.");
            }
            if(matriz[posx_jog - 2][posy_jog] == 'R'){
                printf("Casa vermelha, -3 de vida.");
                *joghp = *joghp - 3;
            }
            if(matriz[posx_jog - 2][posy_jog] == 'G'){
                if(*joghp < 10){
                    printf("Casa verde, +1 de vida.");
                    *joghp = *joghp + 1;
                }
                if(*joghp == 10){
                    printf("Vida cheia");
                }
            }
            if(matriz[posx_jog - 2][posy_jog] == 'Y'){ 
                printf("Casa amarela, um turno sem jogar.");
                *jog_semjogar = -2;
            }
            if(matriz[posx_jog - 2][posy_jog] == 'B'){ 
                printf("Casa azul, jogue novamente.");
                *jog_novamente = -1;
            }
        }

        //coluna final
        if(*soma_dado >= 24 && *soma_dado <= 27){
            if(matriz[posx_jog][posy_jog + 2] == 'P'){
                printf("Casa preta, retorne ao inicio.");
            }
            if(matriz[posx_jog][posy_jog + 2] == 'W'){
                printf("Casa branca, escapou dessa vez.");
            }
            if(matriz[posx_jog][posy_jog + 2] == 'R'){
                printf("Casa vermelha, -3 de vida.");
                *joghp = *joghp - 3;
            }
            if(matriz[posx_jog][posy_jog + 2] == 'G'){
                if(*joghp < 10){
                    printf("Casa verde, +1 de vida.");
                    *joghp = *joghp + 1;
                }
                if(*joghp == 10){
                    printf("Vida cheia");
                }
            }
            if(matriz[posx_jog][posy_jog + 2] == 'Y'){ 
                printf("Casa amarela, um turno sem jogar.");
                *jog_semjogar = -2;
            }
            if(matriz[posx_jog][posy_jog + 2] == 'B'){
                printf("Casa azul, jogue novamente.");
                *jog_novamente = -1;
            }
        }
    }

}