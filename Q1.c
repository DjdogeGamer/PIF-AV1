#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void zerarTabuleiro(int tam, int matriz[tam][tam]){
    //zerar matriz
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            matriz[i][j] = 0;
        }
    }
}

void printarTabuleiro(int tam, int matriz[tam][tam]){
    //exibe tabuleiro
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            printf("%i ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main(){

    srand(time(NULL));

    int matriz[8][8];
    int opcao;
    char peca_1,peca_2;

    printf("JOGADOR 1 digite o tipo da peca: ");
    scanf("%c", &peca_1);
    getchar();
    printf("\n");

    printf("JOGADOR 2 digite o tipo da peca: ");
    scanf("%c", &peca_2);
    getchar();
    printf("\n");

    //laço que dará a opção de ser repetido até que uma das duas peças seja derrubada, assim que um jogador vencer o jogo o programa encerra
    do{
        printf("Peca do jogador 1 = 1 /Peca do jogador 2 = 2");
        printf("\n");

        //zerar matriz
        zerarTabuleiro(8, matriz);
        //printarTabuleiro(8, matriz);
        printf("\n");

        //inicializa peca 2
        int linha_peca2 = rand()%8;
        int coluna_peca2 = rand()%8;
        matriz[linha_peca2][coluna_peca2] = 2;
        
        //inicializa peca 1
        int linha_peca1 = rand()%8; 
        int coluna_peca1 = rand()%8;

        //confere se a pedra pode ser inserida na posição
        if(matriz[linha_peca1][coluna_peca1] == 0){
            matriz[linha_peca1][coluna_peca1] = 1;
        }
        else{
            int linha_peca1 = rand()%8; 
            int coluna_peca1 = rand()%8;

            matriz[linha_peca1][coluna_peca1] = 1;
        }

        
        printarTabuleiro(8, matriz);
        printf("\n");

        //confere se umaa peça derruba a outra por meio de uma variavel validadora
        int validador = 0;

        //confere se as peças declaradas são iguais, caso sejam, ambas podem se derrubar (com excessão do peão)
        if (peca_1 == peca_2)
        {
            if(peca_1 == 'T'){ // TORRE

                for(int i = 0; i < 8; i++){
                    if(matriz[i][coluna_peca1] == 2){
                        validador = 3;
                    }
                }

                for(int i = 0; i < 8; i++){
                    if(matriz[linha_peca1][i] == 2){
                        validador = 3;
                    }
                }
            }

            if(peca_1 == 'P'){ // PEÃO

                if(matriz[linha_peca2-1][coluna_peca2-1] == 1 || matriz[linha_peca2-1][coluna_peca2+1] == 1) {
                    validador = 1;
                }

                if(matriz[linha_peca1-1][coluna_peca1-1] == 2 || matriz[linha_peca1-1][coluna_peca2+1] == 2) {
                    validador = 2;
                }
            }

            if(peca_1 == 'C'){ // CAVALO

                if(matriz[linha_peca1-2][coluna_peca1-1] == 2 || matriz[linha_peca1-1][coluna_peca1-2] == 2 || matriz[linha_peca1-2][coluna_peca1+1] == 2 || matriz[linha_peca1+1][coluna_peca1+2] == 2) {
                    validador = 3;
                }else if (matriz[linha_peca1-1][coluna_peca1+2] == 2 || matriz[linha_peca1-2][coluna_peca1+1] == 2 || matriz[linha_peca1+1][coluna_peca1-2] == 2 || matriz[linha_peca1+2][coluna_peca1-1] == 2) {
                    validador = 3;
                }
            }

            int m, o;

            if(peca_1 == 'Q'){ // RAINHA

                for(int i = 0; i < 8; i++){ // coluna 
                    if(matriz[i][coluna_peca1] == 2){
                        validador = 3;
                    }
                }

                for(int i = 0; i < 8; i++){ // linha
                    if(matriz[linha_peca1][i] == 2) {
                        validador = 3;
                    }
                }

                for (m = linha_peca1 + 1, o = coluna_peca1 + 1; m < 8 && o < 8; m++, o++) {
                    if(matriz[m][o] == 2) {
                        validador = 3;
                    }
                }
                for (m = linha_peca1 - 1, o = coluna_peca1 - 1; m >= 0 && o >= 0; m--, o--) {
                    if(matriz[m][o] == 2) {
                        validador = 3;
                    }
                }
                for (m = linha_peca1 - 1, o = coluna_peca1 + 1; m >= 0 && o < 8; m--, o++) {
                    if(matriz[m][o] == 2) {
                        validador = 3;
                    }
                }
                for (m = linha_peca1 + 1, o = coluna_peca1 - 1; m < 8 && o >= 0; m++, o--) {
                    if(matriz[m][o] == 2) {
                        validador = 3;
                    }
                }
            }

            int k, l;

            if(peca_1 == 'B'){ // BISPO

                for (k = linha_peca1 + 1, l = coluna_peca1 + 1; k < 8 && l < 8; k++, l++) {
                    if(matriz[k][l] == 2) {
                        validador = 3;
                    }
                }
                for (k = linha_peca1 - 1, l = coluna_peca1 - 1; k >= 0 && l >= 0; k--, l--) {
                    if(matriz[k][l] == 2) {
                        validador = 3;
                    }
                }
                for (k = linha_peca1 - 1, l = coluna_peca1 + 1; k >= 0 && l < 8; k--, l++) {
                    if(matriz[k][l] == 2) {
                        validador = 3;
                    }
                }
                for (k = linha_peca1 + 1, l = coluna_peca1 - 1; k < 8 && l >= 0; k++, l--) {
                    if(matriz[k][l] == 2) {
                        validador = 3;
                    }
                }
            }

            if(peca_1 == 'K'){ // REI 

                if(matriz[linha_peca1+1][coluna_peca1] == 2 || matriz[linha_peca1-1][coluna_peca1] == 2) {
                    validador = 2;
                } else if (matriz[linha_peca1][coluna_peca1+1] == 2 || matriz[linha_peca1][coluna_peca1-1] == 2) {
                    validador = 2;
                } else if(matriz[linha_peca1-1][coluna_peca1+1] == 2 || matriz[linha_peca1+1][coluna_peca1-1] == 2) {
                    validador = 2;
                } else if (matriz[linha_peca1+1][coluna_peca1-1] == 2 || matriz[linha_peca1-1][coluna_peca1+1] == 2) {
                    validador = 2;
                }
            }

        }
        //caso as peças sejam diferentes, analisa qual pode ser derrubada
        else{

            //confere se a peça 2 derruba uma pedra
            switch (peca_2)
            {
                case 'T': // TORRE

                    for(int i = 0; i < 8; i++){
                        if(matriz[i][coluna_peca2] == 1){
                            validador = 1;
                        }
                    }

                    for(int i = 0; i < 8; i++){
                        if(matriz[linha_peca2][i] == 1){
                            validador = 1;
                        }
                    }

                break;

                case 'P': // PEÃO

                    if(matriz[linha_peca2-1][coluna_peca2-1] == 1 || matriz[linha_peca2-1][coluna_peca2+1] == 1) {
                        validador = 1;
                    }

                break;

                case 'C': // CAVALO

                    if(matriz[linha_peca2-2][coluna_peca2-1] == 1 || matriz[linha_peca2-1][coluna_peca2-2] == 1 || matriz[linha_peca2-2][coluna_peca2+1] == 1 || matriz[linha_peca2+1][coluna_peca2+2] == 1) {
                        validador = 1;
                    }else if (matriz[linha_peca2-1][coluna_peca2+2] == 1 || matriz[linha_peca2-2][coluna_peca2+1] == 1 || matriz[linha_peca2+1][coluna_peca2-2] == 1 || matriz[linha_peca2+2][coluna_peca2-1] == 1) {
                        validador = 1;
                    }

                break;

                int m, o;

                case 'Q': // RAINHA

                    for(int i = 0; i < 8; i++){ // coluna 
                        if(matriz[i][coluna_peca2] == 1){
                            validador = 1;
                        }
                    }

                    for(int i = 0; i < 8; i++){ // linha
                        if(matriz[linha_peca2][i] == 1) {
                            validador = 1;
                        }
                    }

                    for (m = linha_peca2 + 1, o = coluna_peca2 + 1; m < 8 && o < 8; m++, o++) {
                        if(matriz[m][o] == 1) {
                            validador = 1;
                        }
                    }
                    for (m = linha_peca2 - 1, o = coluna_peca2 - 1; m >= 0 && o >= 0; m--, o--) {
                        if(matriz[m][o] == 1) {
                            validador = 1;
                        }
                    }
                    for (m = linha_peca2 - 1, o = coluna_peca2 + 1; m >= 0 && o < 8; m--, o++) {
                        if(matriz[m][o] == 1) {
                            validador = 1;
                        }
                    }
                    for (m = linha_peca2 + 1, o = coluna_peca2 - 1; m < 8 && o >= 0; m++, o--) {
                        if(matriz[m][o] == 1) {
                            validador = 1;
                        }
                    }
                
                break;

                int k, l;

                case 'B': // BISPO

                    for (k = linha_peca2 + 1, l = coluna_peca2 + 1; k < 8 && l < 8; k++, l++) {
                        if(matriz[k][l] == 1) {
                            validador = 1;
                        }
                    }
                    for (k = linha_peca2 - 1, l = coluna_peca2 - 1; k >= 0 && l >= 0; k--, l--) {
                        if(matriz[k][l] == 1) {
                            validador = 1;
                        }
                    }
                    for (k = linha_peca2 - 1, l = coluna_peca2 + 1; k >= 0 && l < 8; k--, l++) {
                        if(matriz[k][l] == 1) {
                            validador = 1;
                        }
                    }
                    for (k = linha_peca2 + 1, l = coluna_peca2 - 1; k < 8 && l >= 0; k++, l--) {
                        if(matriz[k][l] == 1) {
                            validador = 1;
                        }
                    }

                break;

                case 'K': // REI 

                    if(matriz[linha_peca2+1][coluna_peca2] == 1 || matriz[linha_peca2-1][coluna_peca2] == 1) {
                        validador = 1;
                    } else if (matriz[linha_peca2][coluna_peca2+1] == 1 || matriz[linha_peca2][coluna_peca2-1] == 1) {
                        validador = 1;
                    } else if(matriz[linha_peca2-1][coluna_peca2+1] == 1 || matriz[linha_peca2+1][coluna_peca2-1] == 1) {
                        validador = 1;
                    } else if (matriz[linha_peca2+1][coluna_peca2-1] == 1 || matriz[linha_peca2-1][coluna_peca2+1] == 1) {
                        validador = 1;
                    }

                break;

            default:
                printf("Opcao invalida\n");
                break;
            }

            //confere se a peça 1 derruba uma pedra
            switch (peca_1)
            {
                case 'T': // TORRE

                    for(int i = 0; i < 8; i++){
                        if(matriz[i][coluna_peca1] == 2){
                            validador = 2;
                        }
                    }

                    for(int i = 0; i < 8; i++){
                        if(matriz[linha_peca1][i] == 2){
                            validador = 2;
                        }
                    }

                break;

                case 'P': // PEÃO

                    if(matriz[linha_peca1-1][coluna_peca1-1] == 2 || matriz[linha_peca1-1][coluna_peca2+1] == 2) {
                        validador = 2;
                    }

                break;

                case 'C': // CAVALO

                    if(matriz[linha_peca1-2][coluna_peca1-1] == 2 || matriz[linha_peca1-1][coluna_peca1-2] == 2 || matriz[linha_peca1-2][coluna_peca1+1] == 2 || matriz[linha_peca1+1][coluna_peca1+2] == 2) {
                        validador = 2;
                    }else if (matriz[linha_peca1-1][coluna_peca1+2] == 2 || matriz[linha_peca1-2][coluna_peca1+1] == 2 || matriz[linha_peca1+1][coluna_peca1-2] == 2 || matriz[linha_peca1+2][coluna_peca1-1] == 2) {
                        validador = 2;
                    }

                break;

                int m, o;

                case 'Q': // RAINHA

                    for(int i = 0; i < 8; i++){ // coluna 
                        if(matriz[i][coluna_peca1] == 2){
                            validador = 2;
                        }
                    }

                    for(int i = 0; i < 8; i++){ // linha
                        if(matriz[linha_peca1][i] == 2) {
                            validador = 2;
                        }
                    }

                    for (m = linha_peca1 + 1, o = coluna_peca1 + 1; m < 8 && o < 8; m++, o++) {
                        if(matriz[m][o] == 2) {
                            validador = 2;
                        }
                    }
                    for (m = linha_peca1 - 1, o = coluna_peca1 - 1; m >= 0 && o >= 0; m--, o--) {
                        if(matriz[m][o] == 2) {
                            validador = 2;
                        }
                    }
                    for (m = linha_peca1 - 1, o = coluna_peca1 + 1; m >= 0 && o < 8; m--, o++) {
                        if(matriz[m][o] == 2) {
                            validador = 2;
                        }
                    }
                    for (m = linha_peca1 + 1, o = coluna_peca1 - 1; m < 8 && o >= 0; m++, o--) {
                        if(matriz[m][o] == 2) {
                            validador = 2;
                        }
                    }
                
                break;

                int k, l;

                case 'B': // BISPO

                    for (k = linha_peca1 + 1, l = coluna_peca1 + 1; k < 8 && l < 8; k++, l++) {
                        if(matriz[k][l] == 2) {
                            validador = 2;
                        }
                    }
                    for (k = linha_peca1 - 1, l = coluna_peca1 - 1; k >= 0 && l >= 0; k--, l--) {
                        if(matriz[k][l] == 2) {
                            validador = 2;
                        }
                    }
                    for (k = linha_peca1 - 1, l = coluna_peca1 + 1; k >= 0 && l < 8; k--, l++) {
                        if(matriz[k][l] == 2) {
                            validador = 2;
                        }
                    }
                    for (k = linha_peca1 + 1, l = coluna_peca1 - 1; k < 8 && l >= 0; k++, l--) {
                        if(matriz[k][l] == 2) {
                            validador = 2;
                        }
                    }

                break;

                case 'K': // REI 

                    if(matriz[linha_peca1+1][coluna_peca1] == 2 || matriz[linha_peca1-1][coluna_peca1] == 2) {
                        validador = 2;
                    } else if (matriz[linha_peca1][coluna_peca1+1] == 2 || matriz[linha_peca1][coluna_peca1-1] == 2) {
                        validador = 2;
                    } else if(matriz[linha_peca1-1][coluna_peca1+1] == 2 || matriz[linha_peca1+1][coluna_peca1-1] == 2) {
                        validador = 2;
                    } else if (matriz[linha_peca1+1][coluna_peca1-1] == 2 || matriz[linha_peca1-1][coluna_peca1+1] == 2) {
                        validador = 2;
                    }

                break;

                default:
                    printf("Opcao invalida\n");
                break;
            }
        }

        if(validador == 0){
            printf("Nenhuma pedra eh derrubada.\n");
        }
        else if(validador == 1){
            printf("Pedra 2 derruba uma pedra.\n");
            printf("JOGADOR 2 venceu !!!");
            break;
        }
        else if(validador == 2){
            printf("Pedra 1 derruba uma pedra\n");
            printf("JOGADOR 1 venceu !!!");
            break;
        }
        else if(validador == 3){
            printf("Ambas as pedras podem ser derrubadas\n");
            break;
        }

        //Repetidor do while
        printf("Tentar novamente ?\n");
        printf("1 = SIM \n2 = NAO\n");
        printf("Opcao: ");
        scanf("%i",&opcao);
        getchar();

    }while(opcao == 1);

    return 0;
}
