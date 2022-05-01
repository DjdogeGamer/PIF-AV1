// caixa de supermercado
#include<stdio.h>

void printarSala(int tam, int matriz[tam][tam])
{
    //exibe tabuleiro
    for(int i = 0; i < tam; i++)
    {
        for(int j = 0; j < tam; j++)
        {
            printf("%i ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("--- TELA --- SAIDA\n");
}

int verificaSala(int tam, int matriz[tam][tam])
{
    int sala_cheia = 0;
    int vazio_count = 0;
    //exibe tabuleiro
    for(int i = 0; i < tam; i++)
    {
        for(int j = 0; j < tam; j++) 
        {
            if(matriz[i][j] == 0) {
              vazio_count+=1;
            }
        }
    }
      
    if(vazio_count >= 49) 
    {
        printf("\nHa assentos ainda disponiveis nessa sala!\n");
    } else if (vazio_count == 0) 
    {
        printf("\nA sala esta cheia!\n");
        return sala_cheia = 1;
    }
}

int main(void) {
    FILE* file;
    file = fopen("compras_sala_prime.txt","a");

    float preco = 0.0;
    char nomeFilme[30], categoriaFilme[20];
    int codigos[20];
    int l, c, fim, opc, entrada, assento;
    float total_cliente = 0.0;
    float total_dia = 0.0;
    int tipo_ingresso = 0;
    int sala[8][8];
    int qtd_meia = 0, qtd_inteira = 0;

    // Zerar Matriz
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            sala[i][j] = 0;
        }
    }

    // pos l
    for(int i = 0; i < 8; i++)
    {
      sala[i][0] = i;
    }

    // pos c
    for(int j = 0; j < 8; j++)
    {
      sala[0][j] = j;
    }

    sala[0][0] = 1;

    printf("\n\t --- Bem vindo! ---");
    printf("\n--- Sistema de Administracao Sala Prime V1.0 ---\n");
    
    int i = 0;
    do {
        int qtd_cadastros = 0;
        do 
        {
            printf("Digite o nome do filme: ");
            fgets(nomeFilme, sizeof(nomeFilme), stdin);

            printf("\nDigite a categoria do filme: ");
            fgets(categoriaFilme, sizeof(categoriaFilme), stdin);

            printf("\nDigite o codigo do ingresso: ");
            scanf("%i", &codigos[i]);
   
            printf("\nDigite o preco do ingresso: ");
            scanf("%f", &preco);

            printf("\nDigite o tipo do ingresso (0 - INTEIRA | 1 - MEIA): ");
            scanf("%i", &tipo_ingresso);

            printf("\nDigite a entrada: ");
            scanf("%i", &entrada);

            if(tipo_ingresso == 1) { preco/=2.0; qtd_meia++; }
            else { qtd_inteira++; }

            registrar_assento:
            printarSala(8, sala);

            if(verificaSala(8, sala) == 1) 
            {
              goto salaCheia;
            } else 

            assento = i+1;

            printf("\nEscolha o assento dispovivel (Linha, espaco, Coluna):\n");
            scanf("%i %i", &l, &c);

            if(sala[l][c] != 0)
            {
              printf("\nLugares ja ocupados! escolha outra cadeira...\n");
              goto registrar_assento;
            } else 
            {
              sala[l][c] = i+1;
            }
            printarSala(8, sala);

            total_cliente+=preco;

            printf("\nDeseja registrar mais ingressos? (0 - S / 1 - N):");
            scanf("%i", &opc);
            getchar();

            qtd_cadastros +=1;
            i++;
        } while(opc != 1);

        total_dia+=total_cliente;
        printf("\t --- Ingressos Cadastrados ---\n");

        for (int j = 0; j < qtd_cadastros; j++)
        {
          printf("FILME:%s CATEGORIA:%s ENTRADA:%i ASSENTO:%i QTD:%i COD:%i QTD MEIAS:%i QTD INTEIRAS:%i\n", nomeFilme, categoriaFilme, entrada, assento,j+1, codigos[j], qtd_meia, qtd_inteira);

          fprintf(file,"FILME:%s CATEGORIA:%s ENTRADA:%i ASSENTO:%i QTD:%i COD:%i QTD MEIAS:%i QTD INTEIRAS:%i", nomeFilme, categoriaFilme, entrada, assento,j+1, codigos[j], qtd_meia, qtd_inteira);
        }
        printf("TOTAL DA OPERACAO: R$ %.2f\n", total_cliente);
        total_cliente = 0;
        printf("Proximo...\n");

        printf("Deseja fechar o sistema? (0 - S / 1 - N):\n");
        scanf("%i", &fim);
      
    } while(fim != 0);
    printf("\t --- FIM DO EXPEDIENTE 23:00 PM ---\n");
    printf("\t      Total do dia R$ %.2f\n", total_dia);
    fclose(file);
    salaCheia:
    return 0;
}