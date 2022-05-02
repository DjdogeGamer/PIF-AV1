#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void iniciarElementos(char cenario[10][10], char elemento, int n_Elementos)
{
    for(int e = 1; e <= n_Elementos;)
    {
        int el = rand()%10;
        int ec = rand()%10;
        
        if(cenario[el][ec] == '_')
        {
            cenario[el][ec] = elemento;
            e++;
        }
    }
}

void zerarCenario(char cenario[10][10])
{
   for(int l = 0; l < 10 ; l++)
    {
        for(int c = 0; c < 10; c++)
        {
           cenario[l][c] = '_';
        }
        
    }
}

void imprimir(char cenario[10][10])
{
    for(int l = 0; l < 10 ; l++)
    {
        for(int c = 0; c < 10; c++)
        {
            printf("%c ", cenario[l][c]);
        }
        printf("\n");
    }
    
}

int guerraContraCersei(int vidaJ,int vidaC)
{
    int x = 1;
    while(x > 0)
    {   
        int taxaAtaqueJ = rand()%100;
        printf("\nJon joga o dado! dado de Jon = %i\n", taxaAtaqueJ);
        if(taxaAtaqueJ >= 50)
        {
            vidaC = vidaC - 10;
            printf("\n*****Ataque de Jon bem sucedido!*****\n Vida de Cersei = %i\n", vidaC);
            if(vidaC <= 0)
            {
                printf("\n######Cersei Morreu! Jon ganhou a Guerra!#####\n");
                return  vidaJ;
            }
        }
        else
        {
            printf("Ataque de Jon mau sucedido! vez de Cersei.");
        }
        int taxaAtaqueC = rand()%100;
        printf("\nCersei joga o dado! dado de Cersei = %i\n", taxaAtaqueC);
        if(taxaAtaqueC >= 50)
        {
            vidaJ = vidaJ - 10;
            printf("\n*****Ataque de Cersei bem sucedido!*****\n Vida de Jon = %i\n", vidaJ);
            if(vidaJ <= 0)
            {
                return vidaJ;
            }
        }
        else
        {
            printf("Ataque de Cersei mal sucedido! vez de Jon.");
        }
    }
}

int guerraContraRei(int vidaJ, int vidaReidaNoite){
    int x = 1;
    while(x > 0)
    {   
        int taxaAtaqueJ = rand()%100;
        printf("\nJon joga o dado! dado de Jon = %i\n", taxaAtaqueJ);
        if(taxaAtaqueJ >= 50)
        {
            vidaReidaNoite = vidaReidaNoite - 10;
            printf("\n*****Ataque de Jon bem sucedido!*****\n Vida do Rei da noite = %i\n", vidaReidaNoite);
            if(vidaReidaNoite <= 0)
            {
                printf("\n######Rei da noite Morreu! Jon ganhou a Guerra!#####\n");
                return 2;
            }
        }
        else
        {
            printf("Ataque mau sucedido! vez do Rei da Noite.");
        }
        int taxaAtaqueR = rand()%100;
        printf("\nRei da Noite joga o dado! dado do Rei da Noite = %i\n", taxaAtaqueR);
        if(taxaAtaqueR >= 50)
        {
            vidaJ = vidaJ - 5;
            vidaReidaNoite = vidaReidaNoite + 5;
            printf("\n*****Ataque do Rei da Noite bem sucedido!*****\n Vida de Jon = %i   Vida do Rei da noite = %i\n", vidaJ, vidaReidaNoite);
            if(vidaJ <= 0)
            {
                return 1;
            }
        }
        else
        {
            printf("Ataque do Rei da Noite mal sucedido! vez de Jon.");
        }
    }
}

int q4(void) {
    int poderNegociacao = 0;
    int tentativasJon = 0;
    int status = 0;
    int vidaJ = 100, vidaC = 100, vidaReidaNoite = 200;
    srand(time(NULL));
    char cenario[10][10];
    zerarCenario(cenario);
    cenario[0][0] = 'W';//Inicialiazando Winterfell
    cenario[4][4] = 'C';//Inicialiazando Cersei
    cenario[9][9] = 'N';//Inicialiazando Rei da noite
    cenario[0][1] = 'J';//Inicialiazando Jon Snow
    int jl = 0, jc = 1;
    iniciarElementos(cenario, 'I', 20);//inicalizando Ininimigos
    iniciarElementos(cenario, 'O', 10);//inicalizando Obstaculos    
    iniciarElementos(cenario, 'V', 10);//inicalizando Vidas
    do
    {
        
        imprimir(cenario);
        
        char mov;
        printf(">");
        scanf("%c", &mov);
        getchar();
        
        switch(mov)
        {
    
            case 'w':
                if(jl - 1 >= 0 && cenario[jl-1][jc] != 'O' && cenario[jl-1][jc] != 'W')//Se atender as condições ele se move
                {
                   if(cenario[jl-1][jc] == 'C')
                   {
                       while(tentativasJon < 5){//convercer Cersei
                           tentativasJon++;
                           int auxRandPoderNegociacao = rand()%100;
                           printf("\nDado de negociação Jogado! \n dado = %i", auxRandPoderNegociacao);
                           if(auxRandPoderNegociacao > 60){
                               poderNegociacao = poderNegociacao + 1;
                               printf("\nPoder de Negociacao aumentado para: %i", poderNegociacao);
                           }
                       }
                       if(poderNegociacao >= 3){
                           printf("\nJon ganhou a negociação! ");
                           vidaJ += 100; 
                           printf("Jon agora tem %i de vida\n", vidaJ);
                       }
                       else{
                           printf("\n@@@@@@@@@@@@@@ Jon perdeu a negociação, guerra iniciada! @@@@@@@@@@@@@@\n");
                           status, vidaJ = guerraContraCersei(vidaJ, vidaC);
                       }
                   }
                   
                   else if(cenario[jl-1][jc] == 'N')
                   {
                       if(cenario[4][4] == 'C')
                       {
                           printf("Não pode infrentar o rei da noite. Fim de Jogo");
                           status = 1;
                       }
                       else
                       {
                           status = guerraContraRei(vidaJ, vidaReidaNoite);
                       }
                       
                   }
                   else if(cenario[jl-1][jc] == 'I')
                   {
                       vidaJ--;
                       if(vidaJ <= 0){
                           status = 1;
                       }
                       printf("\nJon Derrotou um inimigo! Vida de Jon = %i\n", vidaJ);
                   }
                   else if(cenario[jl-1][jc] == 'V')
                   {
                       vidaJ = vidaJ + 5;
                       printf("\nJon Pegou uma poção! Vida de Jon = %i\n", vidaJ);
                   }
                       
                    cenario[jl][jc] = '_';
                    cenario[--jl][jc] = 'J';
                }
                break;
                
            case 'a':
                if(jc - 1 >= 0 && cenario[jl][jc-1] != 'O' && cenario[jl][jc-1] != 'W')//Se atender as condições ele se move
                {
                   if(cenario[jl][jc-1] == 'C')
                   {
                       while(tentativasJon < 5){//convercer Cersei
                           tentativasJon++;
                           int auxRandPoderNegociacao = rand()%100;
                           printf("\nDado de negociação Jogado! \n dado = %i", auxRandPoderNegociacao);
                           if(auxRandPoderNegociacao > 60){
                               poderNegociacao = poderNegociacao + 1;
                               printf("\nPoder de Negociacao aumentado para: %i", poderNegociacao);
                           }
                       }
                       if(poderNegociacao >= 3){
                           printf("\nJon ganhou a negociação! ");
                           vidaJ += 100; 
                           printf("Jon agora tem %i de vida\n", vidaJ);
                       }
                       else{
                           printf("\n@@@@@@@@@@@@@@ Jon perdeu a negociação, guerra iniciada! @@@@@@@@@@@@@@\n");
                           status = guerraContraCersei(vidaJ, vidaC);
                       }
                   }
                   
                   else if(cenario[jl][jc-1] == 'N')
                   {
                       if(cenario[4][4] == 'C')
                       {
                           printf("Não pode infrentar o rei da noite. Fim de Jogo");
                           status = 1;
                       }
                       else
                       {
                           status = guerraContraRei(vidaJ, vidaReidaNoite);
                       }
                   }
                   else if(cenario[jl][jc-1] == 'I')
                   {
                       vidaJ--;
                       if(vidaJ <= 0){
                           status = 1;
                       }
                       printf("\nJon Derrotou um inimigo! Vida de Jon = %i\n", vidaJ);
                   }
                   else if(cenario[jl][jc-1] == 'V')
                   {
                       vidaJ = vidaJ + 5;
                       printf("\nJon Pegou uma poção! Vida de Jon = %i\n", vidaJ);
                   }
                       
                    cenario[jl][jc] = '_';
                    cenario[jl][--jc] = 'J';
                }
                break;
                
            case 's':
                if(jl+1 <= 9 && cenario[jl+1][jc] != 'O' && cenario[jl+1][jc] != 'W')//checando se bate na parade e obstaculo
                {
                   if(cenario[jl+1][jc] == 'C')
                   {
                       while(tentativasJon < 5){//convercer Cersei
                           tentativasJon++;
                           int auxRandPoderNegociacao = rand()%100;
                           printf("\nDado de negociação Jogado! \n dado = %i", auxRandPoderNegociacao);
                           if(auxRandPoderNegociacao > 60){
                               poderNegociacao = poderNegociacao + 1;
                               printf("\nPoder de Negociacao aumentado para: %i", poderNegociacao);
                           }
                       }
                       if(poderNegociacao >= 3){
                           printf("\nJon ganhou a negociação! ");
                           vidaJ += 100; 
                           printf("Jon agora tem %i de vida\n", vidaJ);
                       }
                       else{
                           printf("\n@@@@@@@@@@@@@@ Jon perdeu a negociação, guerra iniciada! @@@@@@@@@@@@@@\n");
                           status = guerraContraCersei(vidaJ, vidaC);
                       }
                   }
                   
                   else if(cenario[jl+1][jc] == 'N')
                   {
                       if(cenario[4][4] == 'C')
                       {
                           printf("Não pode infrentar o rei da noite. Fim de Jogo");
                           status = 1;
                       }
                       else
                       {
                           status = guerraContraRei(vidaJ, vidaReidaNoite);
                       }
                   }
                   else if(cenario[jl+1][jc] == 'I')
                   {
                       vidaJ--;
                       printf("\nJon Derrotou um inimigo! Vida de Jon = %i\n", vidaJ);
                   }
                   else if(cenario[jl+1][jc] == 'V')
                   {
                       vidaJ = vidaJ + 5;
                       printf("\nJon Pegou uma poção! Vida de Jon = %i\n", vidaJ);
                   }
                       
                    cenario[jl][jc] = '_';
                    cenario[++jl][jc] = 'J';
                }
                
                break;
                
            case 'd':
                if(jc+1 <= 9 && cenario[jl][jc+1] != 'O' && cenario[jl][jc+1] != 'W')//checando se bate na parade e obstaculo
                {
                   if(cenario[jl][jc+1] == 'C')
                   {
                       while(tentativasJon < 5){//convercer Cersei
                           tentativasJon++;
                           int auxRandPoderNegociacao = rand()%100;
                           printf("\nDado de negociação Jogado! \n dado = %i", auxRandPoderNegociacao);
                           if(auxRandPoderNegociacao > 60){
                               poderNegociacao = poderNegociacao + 1;
                               printf("\nPoder de Negociacao aumentado para: %i", poderNegociacao);
                           }
                       }
                       if(poderNegociacao >= 3){
                           printf("\nJon ganhou a negociação! ");
                           vidaJ += 100; 
                           printf("Jon agora tem %i de vida\n", vidaJ);
                       }
                       else{
                           printf("\n@@@@@@@@@@@@@@ Jon perdeu a negociação, guerra iniciada! @@@@@@@@@@@@@@\n");
                           status, vidaJ = guerraContraCersei(vidaJ, vidaC);
                       }
                   }
                   
                   else if(cenario[jl][jc+1] == 'N')
                   {
                       if(cenario[4][4] == 'C')
                       {
                           printf("Não pode infrentar o rei da noite. Fim de Jogo");
                           status = 1;
                       }
                       else
                       {
                           status = guerraContraRei(vidaJ, vidaReidaNoite);
                       }
                   }
                   else if(cenario[jl][jc+1] == 'I')
                   {
                       vidaJ--;
                       printf("\nJon Derrotou um inimigo! Vida de Jon = %i\n", vidaJ);
                   }
                   else if(cenario[jl][jc+1] == 'V')
                   {
                       vidaJ = vidaJ + 5;
                       printf("\nJon Pegou uma poção! Vida de Jon = %i\n", vidaJ);
                   }
                       
                    cenario[jl][jc] = '_';
                    cenario[jl][++jc] = 'J';
                }
                
                break;    
        }
        if(vidaJ <= 0){
            status = 1;
        }
        
        
    }
    
    while (status == 0);
    
    
    
    if(status == 1)
    {
        printf("\nMorreu! Fim de Jogo");
    }
    else if(status == 2)
    {
        printf("\n@@@@@@@@@@@@@@@@ Jon Derrotou o Rei da Noite Parabens @@@@@@@@@@@@@@@@\n Fim de Jogo.");
    }
    
    return 0;
}