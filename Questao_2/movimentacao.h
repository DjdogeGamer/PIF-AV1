#include <stdio.h>

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