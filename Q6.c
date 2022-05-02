#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

typedef struct {
    char nome[30], codigo_produto[10];
    int quantidade_disponivel, n_vendas, n_compras, status;
    float preco;
}Produto;

void zerar(int tamanho, Produto produtos[tamanho]){
    
    for(int i=0; i<tamanho; i++) {
        strcpy(produtos[i].nome, "NULL");
        strcpy(produtos[i].codigo_produto, "NULL");
        produtos[i].quantidade_disponivel = 0;
        produtos[i].n_vendas = 0;
        produtos[i].n_compras = 0;
        produtos[i].preco = 0.0;
        produtos[i].status = 0;
    }        
}

void relatoriocompras(int tamanho, Produto produtos[tamanho]){
    
    int aux;
    char auxstr[30];
    for (int i = 1; i < tamanho; i++) {
        int j = i;
        while ((produtos[j].n_compras > produtos[j-1].n_compras) && j > 0){
            aux = produtos[j-1].n_vendas;
            produtos[j-1].n_vendas = produtos[j].n_vendas;
            produtos[j].n_vendas = aux;

            aux = produtos[j-1].n_compras;
            produtos[j-1].n_compras = produtos[j].n_compras;
            produtos[j].n_compras = aux;

            strcpy(auxstr, produtos[j-1].nome);
            strcpy(produtos[j-1].nome, produtos[j].nome);
            strcpy(produtos[j].nome, auxstr);

            strcpy(auxstr, produtos[j-1].codigo_produto);
            strcpy(produtos[j-1].codigo_produto, produtos[j].codigo_produto);
            strcpy(produtos[j].codigo_produto, auxstr);

            aux = produtos[j-1].quantidade_disponivel;
            produtos[j-1].quantidade_disponivel = produtos[j].quantidade_disponivel;
            produtos[j].quantidade_disponivel = aux;

            aux = produtos[j-1].preco;
            produtos[j-1].preco = produtos[j].preco;
            produtos[j].preco = aux;

            aux = produtos[j-1].status;
            produtos[j-1].status = produtos[j].status;
            produtos[j].status = aux;
            j--;
        }
    }
    printf("======   Lista ordenada dos produtos mais comprados:   ======\n\n");
    for (int i = 0; i < tamanho; i++ ) {
        if (strcmp("NULL", produtos[i].codigo_produto) == 1){
            printf("Nome: %s\n", produtos[i].nome);
            printf("Codigo: %s\n", produtos[i].codigo_produto);
            printf("Quantidade disponivel: %i\n", produtos[i].quantidade_disponivel);
            printf("Numero de compras: %i\n", produtos[i].n_compras);
            printf("Numero de vendas: %i\n", produtos[i].n_vendas);
            printf("Status: %i\n", produtos[i].status);
            printf("Preco unitario: %.2f\n\n", produtos[i].preco);
        }
	}
}

void relatoriovendas(int tamanho, Produto produtos[tamanho]){
    
    int aux;
    char auxstr[30];
    for (int i = 1; i < tamanho; i++) {
        int j = i;
        while ((produtos[j].n_vendas > produtos[j-1].n_vendas) && j > 0){
            aux = produtos[j-1].n_vendas;
            produtos[j-1].n_vendas = produtos[j].n_vendas;
            produtos[j].n_vendas = aux;

            aux = produtos[j-1].n_compras;
            produtos[j-1].n_compras = produtos[j].n_compras;
            produtos[j].n_compras = aux;

            strcpy(auxstr, produtos[j-1].nome);
            strcpy(produtos[j-1].nome, produtos[j].nome);
            strcpy(produtos[j].nome, auxstr);

            strcpy(auxstr, produtos[j-1].codigo_produto);
            strcpy(produtos[j-1].codigo_produto, produtos[j].codigo_produto);
            strcpy(produtos[j].codigo_produto, auxstr);

            aux = produtos[j-1].quantidade_disponivel;
            produtos[j-1].quantidade_disponivel = produtos[j].quantidade_disponivel;
            produtos[j].quantidade_disponivel = aux;

            aux = produtos[j-1].preco;
            produtos[j-1].preco = produtos[j].preco;
            produtos[j].preco = aux;

            aux = produtos[j-1].status;
            produtos[j-1].status = produtos[j].status;
            produtos[j].status = aux;
            j--;
        }
    }
    printf("======   Lista ordenada dos produtos mais vendidos:   ======\n\n");
    for (int i = 0; i < tamanho; i++ ) {
        if (strcmp("NULL", produtos[i].codigo_produto) == 1){
            printf("Nome: %s\n", produtos[i].nome);
            printf("Codigo: %s\n", produtos[i].codigo_produto);
            printf("Quantidade disponivel: %i\n", produtos[i].quantidade_disponivel);
            printf("Numero de compras: %i\n", produtos[i].n_compras);
            printf("Numero de vendas: %i\n", produtos[i].n_vendas);
            printf("Status: %i\n", produtos[i].status);
            printf("Preco unitario: %.2f\n\n", produtos[i].preco);
        }
	}
}

int inserir(int tamanho, Produto produtos[tamanho], int posicao, Produto novo){
        
    int status = 1;
    char nulo[5] = "NULL";
        
        for (int i=0; i<tamanho; i++){
            if (strcmp(produtos[i].codigo_produto, novo.codigo_produto) == 0){
                status = 0;
            }
        }

        if (status == 1){
            for (int i=0; i<tamanho; i++){
                if (strcmp(nulo, produtos[i].codigo_produto) == 0){
                    posicao = i;
                    break;
                } 
            }
            novo.status = 1;
            novo.quantidade_disponivel = 0;
            novo.n_vendas = 0;
            novo.n_compras = 0;
            produtos[posicao] = novo;
        }
    

    return status;
}

int remover(int tamanho, Produto produtos[tamanho],  char codigo[]){
    int status = 0, posicao;
   
    for (int i=0; i<tamanho; i++){
        if (strcmp(produtos[i].codigo_produto, codigo) == 0){
            posicao = i;
            status = 1;
        } 
    }
    if (status == 1){
        strcpy(produtos[posicao].nome, "NULL");
        strcpy(produtos[posicao].codigo_produto, "NULL");
        produtos[posicao].quantidade_disponivel = 0;
        produtos[posicao].n_vendas = 0;
        produtos[posicao].n_compras = 0;
        produtos[posicao].preco = 0.0;
        produtos[posicao].status = 0;  
    }
    
    
    return status;
}

int buscar(int tamanho, Produto produtos[tamanho], char codigo[]){
    int posicao = -1;
    for (int i=0; i<tamanho; i++){
        if (strcmp(produtos[i].codigo_produto, codigo) == 0){
            posicao = i;
        } 
    }
    return posicao;
}

int comprar(int tamanho, Produto produtos[tamanho], char codigo[], int qtd){
    int status, posicao;
    posicao = buscar(tamanho, produtos, codigo);
    if (posicao>=0 && posicao<=tamanho){
        produtos[posicao].quantidade_disponivel += qtd;
        produtos[posicao].n_compras += qtd;
        status = 1;
    }
    else{
        status = 0;
    }
    return status;
}

int vender(int tamanho, Produto produtos[tamanho], char codigo[], int qtd){
    int status, posicao;
    posicao = buscar(tamanho, produtos, codigo);
     if (posicao>=0 && posicao<=tamanho){
        if (produtos[posicao].quantidade_disponivel > 0){
            produtos[posicao].quantidade_disponivel -= qtd;
            produtos[posicao].n_vendas += qtd;
            status = 1;
        }
    }
    else{
        status = 0;
    }
    return status;
}

int main(){
    
    time_t start_t, end_t; 
    double diff_t;
    float saldototal;
    int tamanho = 10, opcao, posicao, status, qtd;
    char codigo[10];
    Produto produtos[tamanho], novo;
    zerar(tamanho, produtos);

    do {
        system("cls");
        printf("Digite o numero da opcao que deseja realizar: \n");
        printf("1 - Inserir.\t\t\t2 - Remover.\n3 - Buscar.\t\t\t4 - Comprar.\n5 - Vender.\t\t\t6 - Relatorio de vendas.\n7 - Relatorio de compras.\t8 - Extrado da conta.\n9 - Produtos em estoque.\t10 - Sair.\n\n> ");
        scanf("%i", &opcao);

        switch (opcao){
            // Inserir produto
            case 1:{
                
                printf("Digite o nome que deseja inserir: ");
                scanf("%s", novo.nome);
                printf("Digite o codigo do produto que deseja inserir: ");
                scanf("%s", novo.codigo_produto);
                printf("Digite o preco que deseja inserir: ");
                scanf("%f", &novo.preco);
                
                status = inserir(tamanho, produtos, posicao, novo);

                if (status == 1){
                    printf("Produto inserido com sucesso!\n\n");
                    
                }
                else if (status == 0){
                    printf("\nEste codigo de produto ja existe!\n");
                    printf("Se deseja cadastrar um novo produto! Tente outro codigo!\n");
                }
                diff_t = 0;
                time(&start_t);
                while(diff_t<=1.000000){
                    time(&end_t);
                    diff_t = difftime(end_t, start_t);
                }
                break;
            }
            // Remover produto
            case 2:{
                printf("Digite o codigo do produto que deseja remover: ");
                scanf("%s", codigo);
                
                status = remover(tamanho, produtos, codigo);

                if (status == 1){
                    printf("Produto removido com sucesso!\n");
                    
                }
                else if (status == 0){
                    printf("Este produto nao existe!\n");
                }
                diff_t = 0;
                time(&start_t);
                while(diff_t<=1.000000){
                    time(&end_t);
                    diff_t = difftime(end_t, start_t);
                }
                break;
            }
            // Buscar produto
            case 3:{
                printf("Digite o codigo do produto que deseja buscar: ");
                scanf("%s", codigo);
                posicao = buscar(tamanho, produtos, codigo);
                if (posicao>=0 && posicao<=tamanho){
                    printf("\nProduto encontrado!\n\n");
                    printf("Nome: %s\n", produtos[posicao].nome);
                    printf("Codigo: %s\n", produtos[posicao].codigo_produto);
                    printf("Quantidade disponivel: %i\n", produtos[posicao].quantidade_disponivel);
                    printf("Numero de compras: %i\n", produtos[posicao].n_compras);
                    printf("Numero de vendas: %i\n", produtos[posicao].n_vendas);
                    printf("Status: %i\n", produtos[posicao].status);
                    printf("Preco unitario: %.2f\n\n", produtos[posicao].preco);
                }
                else{
                    printf("\nProduto nao encontrado!\n\n");
                }
                system("pause");
                break;
            }
            // Compra de produtos
            case 4:{
                printf("Digite o codigo do produto que deseja comprar: ");
                scanf("%s", codigo);
                printf("Digite a quantos produtos deseja comprar: ");
                scanf("%i", &qtd);
                status = comprar(tamanho, produtos, codigo, qtd);
                if (status == 1){
                    printf("Produto comprado com sucesso!\n\n");
                }
                else if (status == 0){
                    printf("Houve uma falha na compra do produto! Verifique se o mesmo existe!\n\n");
                }
                diff_t = 0;
                time(&start_t);
                while(diff_t<=1.000000){
                    time(&end_t);
                    diff_t = difftime(end_t, start_t);
                }
                break;
            }
            // Venda de produtos
            case 5:{
                printf("Digite o codigo do produto que deseja vender: ");
                scanf("%s", codigo);
                printf("Digite a quantos produtos deseja vender: ");
                scanf("%i", &qtd);
                status = vender(tamanho, produtos, codigo, qtd);
                if (status == 1){
                    printf("Produto vendido com sucesso!\n\n");
                }
                else if (status == 0){
                    printf("Houve uma falha na venda do produto! Verifique se há algum disponivel ou se o produto existe!\n\n");
                }
                diff_t = 0;
                time(&start_t);
                while(diff_t<=1.000000){
                    time(&end_t);
                    diff_t = difftime(end_t, start_t);
                }
                break;
            }
            //1. Lista ordenada dos produtos mais vendidos
            case 6:{
                relatoriovendas(tamanho, produtos);
                system("pause");
                break;
            }
            //2. Lista ordenada dos produtos mais comprados
            case 7:{
                relatoriocompras(tamanho, produtos);
                system("pause");
                break;
            }
            //3. Extrato da conta da padaria
            case 8:{
                float somavendas = 0, somaestoque = 0;
                for (int i=0; i<tamanho; i++){
                    if (strcmp("NULL", produtos[i].codigo_produto) == 1){
                        somavendas += produtos[i].n_vendas * produtos[i].preco;
                        somaestoque += produtos[i].quantidade_disponivel * produtos[i].preco;
                    }
                }
                saldototal = somavendas + somaestoque;
                printf("\nO extrato de vendas eh de R$%.2f\n", somavendas);
                printf("\nO extrato de produtos em estoque eh de R$%.2f\n", somaestoque);
                printf("\nO extrato total da padaria eh de R$%.2f\n\n", saldototal);
                system("pause");
                break;
            }
            //4. Produtos em estoque
            case 9:{
                printf("\n============Produto============Quantidade em estoque============\n\n");
                for (int i=0; i<tamanho; i++){
                    if (strcmp("NULL", produtos[i].codigo_produto) == 1){
                        printf("            %s                              %i\n", produtos[i].nome, produtos[i].quantidade_disponivel);
                    }
                }
                printf("\n");
                system("pause");
                break;
            }
            case 10:{
                printf("\nVoce optou por sair! Volte sempre!\n");
                diff_t = 0;
                time(&start_t);
                while(diff_t<=1.000000){
                    time(&end_t);
                    diff_t = difftime(end_t, start_t);
                }
                break;
            }
            default:{
                printf("Esta opcao nao eh valida!");
                system("pause");
                break;
            }
        }
    }while(opcao != 10);

    return 0;
}