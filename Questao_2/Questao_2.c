#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "movimentacao.h"
#include "analise_pos.h"
#include "dados.h"

//assinatura das funções de outros arquivos
//funções do dados.h
int DadosIniciais();
int jogarDado();

//função do movimentacao.h
void movimentacao(int jog_da_vez, int posx_jog, int posy_jog, int dado, int* soma_dado, char matriz[11][14]);

//função do analise_pos.h
void analiseCores(int jog_da_vez, int* soma_dado, int posx_jog,int posy_jog,int* joghp, char matriz[11][14],int* jog_novamente,int* jog_semjogar);

//incializa tabuleiro vazio
void zerarTabuleiro(int linhas,int colunas, char matriz[][colunas]){
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            matriz[i][j] = ' ';
        }
    }
}

//imprime tabuleiro
void printarTabuleiro(int linhas, int colunas, char matriz[][colunas]){
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
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