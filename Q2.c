#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void zerarTabuleiro(int linhas,int colunas, char matriz[][colunas]){
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            matriz[i][j] = ' ';
        }
    }
}

void printarTabuleiro(int linhas, int colunas, char matriz[][colunas]){
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
}

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

//Para navegar entre linhas e colunas será usado a soma dos dados
//Ex1: se a soma for entre 0 e 10 ele andará para a direita (coluna + 1)
//Ex2: se a soma for entre 11 e 16 ele andará para baixo (linha + 1)
//Ex3: se a soma for entre 17 e 25 ele andará para a esquerda (coluna - 1)
//Ex4: se a soma for entre 26 e 27 ele andará para cima (linha - 1)
//Ex5: se a soma for maior ou igual a 28 o jogo é encerrado e o jogador vencedor é informado

//movimenta jogador de acordo com o somatório dos dados até o momento da jogada e posiciona na casa correspondente
void movimentacao(int jog_da_vez, int posx_jog, int posy_jog, int dado, int* soma_dado, char matriz[11][14]){
    if(jog_da_vez == 1){
        switch(*soma_dado){
            case 1:
                matriz[posx_jog][posy_jog] = ' ';
                matriz[2-1][2+1] = '1';
                break;
            case 2:
                matriz[posx_jog][posy_jog] = ' ';
                matriz[2-1][3+1] = '1';
                break;
            case 3:
                matriz[posx_jog][posy_jog] = ' ';
                matriz[2-1][4+1] = '1';
                break;
            case 4:
                matriz[posx_jog][posy_jog] = ' ';
                matriz[2-1][5+1] = '1';
                break;
            case 5:
                matriz[posx_jog][posy_jog] = ' ';
                matriz[2-1][6+1] = '1';
                break;
            case 6:
                matriz[posx_jog][posy_jog] = ' ';
                matriz[2-1][7+1] = '1';
                break;
            case 7:
                matriz[posx_jog][posy_jog] = ' ';
                matriz[2-1][8+1] = '1';
                break;
            case 8:
                matriz[posx_jog][posy_jog] = ' ';
                matriz[2-1][9+1] = '1';
                break;
            case 9:
                matriz[posx_jog][posy_jog] = ' ';
                matriz[2-1][10+1] = '1';
                break;
            case 10:
                matriz[posx_jog][posy_jog] = ' ';
                matriz[3][11+1] = '1';
                break;
            case 11:
                matriz[posx_jog][posy_jog] = ' ';
                matriz[1][2] = '1';
                *soma_dado = 0;
                break;
            case 12:
                matriz[posx_jog][posy_jog] = ' ';
                matriz[5][11+1] = '1';
                break;
            case 13:
                matriz[posx_jog][posy_jog] = ' ';
                matriz[6][11+1] = '1';
                break;
            case 14:
                matriz[posx_jog][posy_jog] = ' ';
                matriz[7][11+1] = '1';
                break;
            case 15:
                matriz[posx_jog][posy_jog] = ' ';
                matriz[8][11+1] = '1';
                break;
            case 16: 
                matriz[posx_jog][posy_jog] = ' ';
                matriz[9][11-1] = '1';
                break;
            case 17: 
                matriz[posx_jog][posy_jog] = ' ';
                matriz[9][10-1] = '1';
                break;
            case 18:
                matriz[posx_jog][posy_jog] = ' ';
                matriz[8+1][9-1] = '1';
                break;
            case 19:
                matriz[posx_jog][posy_jog] = ' ';
                matriz[8+1][8-1] = '1';
                break;
            case 20:
                matriz[posx_jog][posy_jog] = ' ';
                matriz[8+1][7-1] = '1';
                break;
            case 21:
                matriz[posx_jog][posy_jog] = ' ';
                matriz[8+1][6-1] = '1';
                break;
            case 22:
                matriz[posx_jog][posy_jog] = ' ';
                matriz[8+1][5-1] = '1';
                break;
            case 23:
                matriz[posx_jog][posy_jog] = ' ';
                matriz[8+1][4-1] = '1';
                break;
            case 24:
                matriz[posx_jog][posy_jog] = ' ';
                matriz[8+1][3-1] = '1';
                break;
            case 25:
                matriz[posx_jog][posy_jog] = ' ';
                matriz[7][2-1] = '1';
                break;
            case 26:
                matriz[posx_jog][posy_jog] = ' ';
                matriz[6][2-1] = '1';
                break;
            case 27:
                matriz[posx_jog][posy_jog] = ' ';
                matriz[5][2-1] = '1';
                break;
        }
        
        if(*soma_dado >= 28){
            printf("Jogador 1 venceu\n");
        }
    }

    if(jog_da_vez == 2){

        switch(*soma_dado){
            case 1:
                matriz[posx_jog][posy_jog] = ' ';
                matriz[2-2][2+1] = '2';
                break;
            case 2:
                matriz[posx_jog][posy_jog] = ' ';
                matriz[2-2][3+1] = '2';
                break;
            case 3:
                matriz[posx_jog][posy_jog] = ' ';
                matriz[2-2][4+1] = '2';
                break;
            case 4:
                matriz[posx_jog][posy_jog] = ' ';
                matriz[2-2][5+1] = '2';
                break;
            case 5:
                matriz[posx_jog][posy_jog] = ' ';
                matriz[2-2][6+1] = '2';
                break;
            case 6:
                matriz[posx_jog][posy_jog] = ' ';
                matriz[2-2][7+1] = '2';
                break;
            case 7:
                matriz[posx_jog][posy_jog] = ' ';
                matriz[2-2][8+1] = '2';
                break;
            case 8:
                matriz[posx_jog][posy_jog] = ' ';
                matriz[2-2][9+1] = '2';
                break;
            case 9:
                matriz[posx_jog][posy_jog] = ' ';
                matriz[2-2][10+1] = '2';
                break;
            case 10:
                matriz[posx_jog][posy_jog] = ' ';
                matriz[3][11+2] = '2';
                break;
            case 11:
                matriz[posx_jog][posy_jog] = ' ';
                matriz[0][2] = '2';
                *soma_dado = 0;
                break;
            case 12:
                matriz[posx_jog][posy_jog] = ' ';
                matriz[5][11+2] = '2';
                break;
            case 13:
                matriz[posx_jog][posy_jog] = ' ';
                matriz[6][11+2] = '2';
                break;
            case 14:
                matriz[posx_jog][posy_jog] = ' ';
                matriz[7][11+2] = '2';
                break;
            case 15:
                matriz[posx_jog][posy_jog] = ' ';
                matriz[8][11+2] = '2';
                break;
            case 16: 
                matriz[posx_jog][posy_jog] = ' ';
                matriz[9+1][11-1] = '2';
                break;
            case 17: 
                matriz[posx_jog][posy_jog] = ' ';
                matriz[9+1][10-1] = '2';
                break;
            case 18:
                matriz[posx_jog][posy_jog] = ' ';
                matriz[8+1+1][9-1] = '2';
                break;
            case 19:
                matriz[posx_jog][posy_jog] = ' ';
                matriz[8+1+1][8-1] = '2';
                break;
            case 20:
                matriz[posx_jog][posy_jog] = ' ';
                matriz[8+1+1][7-1] = '2';
                break;
            case 21:
                matriz[posx_jog][posy_jog] = ' ';
                matriz[8+1+1][6-1] = '2';
                break;
            case 22:
                matriz[posx_jog][posy_jog] = ' ';
                matriz[8+1+1][5-1] = '2';
                break;
            case 23:
                matriz[posx_jog][posy_jog] = ' ';
                matriz[8+1+1][4-1] = '2';
                break;
            case 24:
                matriz[posx_jog][posy_jog] = ' ';
                matriz[8+1+1][3-1] = '2';
                break;
            case 25:
                matriz[posx_jog][posy_jog] = ' ';
                matriz[7][2-2] = '2';
                break;
            case 26:
                matriz[posx_jog][posy_jog] = ' ';
                matriz[6][2-2] = '2';
                break;
            case 27:
                matriz[posx_jog][posy_jog] = ' ';
                matriz[5][2-2] = '2';
                break;
        }
    }
}

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

//funçaõ para jogar dado
int jogarDado() {
    int dado;
    return dado = 1 + rand() % 6;
}


int main(){

    srand(time(NULL));

    //inicialização da matriz
    int linhas = 11;
    int colunas = 14; 
    char matriz[linhas][colunas];

    //variáveis auxiliares
    int jog_da_vez = 0; //alterna entre os jogadores
    int jog_novamente = 0; //utilizada para caso um jogador jogue mais de uma vez seguida
    int jog_semjogar = 0; //variavel para limitar os movimentos caso caia numa casa amarela
    int dado_jog1, dado_jog2; //separação de um dado para cada jogador para facilitar no somatório de cada jogador
    int soma_dado1 = 0, soma_dado2 = 0; //somatório de cada jogador
    int j1hp = 10, j2hp = 10; //vida dos jogadores

    char opc; //interações com o dado

    zerarTabuleiro(linhas,colunas,matriz);

    //montar tabuleiro
    matriz[2][2] = 'P'; //00 POSIÇÃO INICIAL
    matriz[2][3] = 'W'; //01 
    matriz[2][4] = 'R'; //02
    matriz[2][5] = 'G'; //03
    matriz[2][6] = 'W'; //04
    matriz[2][7] = 'B'; //05
    matriz[2][8] = 'W'; //06
    matriz[2][9] = 'Y'; //07
    matriz[2][10] = 'W'; //08
    matriz[2][11] = 'R'; //09 FIM DIREITA
    matriz[3][11] = 'G'; //10 DESCE COLUNA
    matriz[4][11] = 'P'; //11 
    matriz[5][11] = 'B'; //12
    matriz[6][11] = 'W'; //13
    matriz[7][11] = 'W'; //14
    matriz[8][11] = 'R'; //15 FIM COLUNA
    matriz[8][10] = 'G'; //16 INICIO ESQUERDA
    matriz[8][9] = 'W'; //17
    matriz[8][8] = 'Y'; //18
    matriz[8][7] = 'W'; //19
    matriz[8][6] = 'R'; //20
    matriz[8][5] = 'G'; //21
    matriz[8][4] = 'W'; //22
    matriz[8][3] = 'B'; //23
    matriz[8][2] = 'R'; //24 FIM ESQUERDA
    matriz[7][2] = 'Y'; //25 SOBE COLUNA
    matriz[6][2] = 'G'; //26
    matriz[5][2] = 'P'; //27 POSIÇÃO FINAL

    //inicializa as coordenadas dos jogadores em variaveis pra facilitar manipulação das posições
    int posx_jog1 = 1;
    int posy_jog1 = 2;
    int posx_jog2 = 0;
    int posy_jog2 = 2;

    matriz[posx_jog1][posy_jog1] = '1';
    matriz[posx_jog2][posy_jog2] = '2';

    printarTabuleiro(linhas,colunas,matriz);
    printf("\n");

    printf("INICIO DO JOGO !!!\n");

    //indica qual jogador vai começar
    int primeiro = DadosIniciais();
    printf("\nJogador %i comeca!\n\n", primeiro);

    //jogador 1 inicia
    if(primeiro == 1) {
        jog_da_vez = 1;

    }

    //jogador 2 inicia
    if(primeiro == 2) {
        jog_da_vez = 2;

    }

    do{
        //valida vida do jogador 2 ao fim de cada laço
        if(j2hp <= 0){
            printf("Voce morreu :(\n");
            printf("Jogador %i venceu !!!!\n",jog_da_vez);
            break;
        }

        //valida fim de jogo
        if(soma_dado2 >= 27){
            printf("Jogador 2 venceu !!!!!!");
            break;
        }

        //casa amarela, jogador 2 sem jogar
        if(jog_semjogar == -2){
            jog_semjogar = 0;
            jog_novamente = -1;
        }
        
        //JOGADAS JOGADOR 1
        if (jog_da_vez == 1 && jog_semjogar != -1 && jog_semjogar != -2){
            printf("\nJogador 1 HP:%i\n",j1hp);
            printf("Digite X para jogar dado: ");
            scanf("%c", &opc);
            getchar();
            dado_jog1 = jogarDado();
            printf("Dado: %i\n\n", dado_jog1);

            soma_dado1 = soma_dado1 + dado_jog1;
            printf("Soma dado 1: %i\n", soma_dado1);

            movimentacao(jog_da_vez, posx_jog1, posy_jog1, dado_jog1, &soma_dado1, matriz);
            printarTabuleiro(linhas,colunas,matriz);
            printf("\n");

            //atualiza posição do jogador após a movimentação
            for(int i = 0; i < 11; i++){
                for(int j = 0; j < 14; j++){
                    if(matriz[i][j] == '1'){
                        posx_jog1 = i;
                        posy_jog1 = j;
                    }
                }
            }

            //analisa a casa do jogador
            analiseCores(jog_da_vez, &soma_dado1,posx_jog1,posy_jog1,&j1hp,matriz,&jog_novamente,&jog_semjogar);
            printf("\nJogador 1 HP:%i\n",j1hp);

            //casa azul, repete o processo do jogador da vez
            if (jog_novamente == -1){
                printf("Jogador 1, jogue novamente\n");
                printf("\nJogador 1 HP:%i\n",j1hp);
                printf("Digite X para jogar dado: ");
                scanf("%c", &opc);
                getchar();
                dado_jog1 = jogarDado();
                printf("Dado: %i\n\n", dado_jog1);

                soma_dado1 = soma_dado1 + dado_jog1;
                printf("Soma dado 1: %i\n", soma_dado1);

                if(soma_dado1 >= 27){
                    printf("Jogador 1 venceu !!!!!!");
                    break;
                }
                else{
                    movimentacao(jog_da_vez, posx_jog1, posy_jog1, dado_jog1, &soma_dado1, matriz);
                    printarTabuleiro(linhas,colunas,matriz);
                    printf("\n");

                    for(int i = 0; i < 11; i++){
                        for(int j = 0; j < 14; j++){
                            if(matriz[i][j] == '1'){
                                posx_jog1 = i;
                                posy_jog1 = j;
                            }
                        }
                    }
                    printf("\nJogador 1 HP:%i\n",j1hp);

                    //encerra repetição
                    jog_novamente = 0;
                }
            }
            
            //atualiza jogador
            jog_da_vez = 2;
        }

        //casa amarela, jogador 1 sem jogar
        if(jog_semjogar == -1){
            jog_novamente = -1;
            jog_semjogar = 0;
        }

        //valida se o jogador 1 está vivo
        if (j1hp <= 0){
            printf("Voce morreu :(\n");
            printf("Jogador %i venceu !!!!\n",jog_da_vez);
            break;
        }

        //valida fim de jogo para jogador 1
        if(soma_dado1 >= 27){
            printf("Jogador 1 venceu !!!!!!");
            break;
        }

        //JOGADAS JOGADOR 2
        if (jog_da_vez == 2 && jog_semjogar != -2 && jog_semjogar != -1){
            printf("\nJogador 2 HP:%i\n",j2hp);
            printf("Digite X para jogar dado: ");
            scanf("%c", &opc);
            getchar();
            dado_jog2 = jogarDado();
            printf("Dado: %i\n\n", dado_jog2);

            soma_dado2 = soma_dado2 + dado_jog2;
            printf("Soma dado 2: %i\n", soma_dado2);


            movimentacao(jog_da_vez, posx_jog2, posy_jog2, dado_jog2, &soma_dado2, matriz);
            printarTabuleiro(linhas,colunas,matriz);
            printf("\n");

            //atualiza posição do jogador após a movimentação
            for(int i = 0; i < 11; i++){
                for(int j = 0; j < 14; j++){
                    if(matriz[i][j] == '2'){
                        posx_jog2 = i;
                        posy_jog2 = j;
                    }
                }
            }

            //analisa posição do jogador e aplica regras
            analiseCores(jog_da_vez, &soma_dado2,posx_jog2,posy_jog2,&j2hp,matriz,&jog_novamente,&jog_semjogar);
            printf("\nJogador 2 HP:%i\n",j2hp);

            //casa azul, repete o processo do jogador da vez
            if (jog_novamente == -1){
                printf("Jogador 2, jogue novamente\n");
                printf("\nJogador 2 HP:%i\n",j2hp);
                printf("Digite X para jogar dado: ");
                scanf("%c", &opc);
                getchar();
                dado_jog2 = jogarDado();
                printf("Dado: %i\n\n", dado_jog2);

                soma_dado2 = soma_dado2 + dado_jog2;
                printf("Soma dado 2: %i\n", soma_dado2);

                if(soma_dado2 >= 27){
                    printf("Jogador 2 venceu !!!!!!");
                    break;
                }
                else{
                    movimentacao(jog_da_vez, posx_jog2, posy_jog2, dado_jog2, &soma_dado2, matriz);
                    printarTabuleiro(linhas,colunas,matriz);
                    printf("\n");

                    for(int i = 0; i < 11; i++){
                        for(int j = 0; j < 14; j++){
                            if(matriz[i][j] == '2'){
                                posx_jog2 = i;
                                posy_jog2 = j;
                            }
                        }
                    }
                    printf("\nJogador 2 HP:%i\n",j2hp);

                    //encerra repetição
                    jog_novamente = 0;
                }
            }

            //atualiza jogador
            jog_da_vez = 1;
        }

    }while(1);

    printf("FIM DE JOGO");

    return 0;
}

//OBS1: mostrar backups
//OBS2: explicar motivos de usar cada processo