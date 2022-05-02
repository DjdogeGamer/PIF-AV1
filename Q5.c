#include <stdio.h>

typedef struct{

    char nome[30];
    char cpf[11];
    int salario;

}Funcionario;

void cadastrarFuncionarios(Funcionario funcionarios[], int n_de_funcionarios){

    for(int i = 0; i < n_de_funcionarios;i++){
        printf("Informe o nome do funcionario: ");
        scanf(" %s", funcionarios[i].nome);
        getchar();

        printf("Informe o cpf do funcionario: ");
        scanf(" %s", &funcionarios[i].cpf);
        getchar();

        printf("Informe o salario desse funcionario: R$");
        scanf("%i", &funcionarios[i].salario);
        getchar();

        printf("\n");

    }
}

int somaSalarios(Funcionario funcionarios[], int n_de_funcionarios){
    if(n_de_funcionarios == 0){
        return 0;
    }
    else{
        return funcionarios[n_de_funcionarios-1].salario + somaSalarios(funcionarios,n_de_funcionarios-1);
    }
}

int main(){

    int n_de_funcionarios = 0;
    Funcionario funcionarios[n_de_funcionarios];

    printf("Informe a quantidade de funcionarios a serem cadastrados: ");
    scanf("%i",&n_de_funcionarios);
    getchar();
    printf("\n");

    cadastrarFuncionarios(funcionarios,n_de_funcionarios);

    printf("Soma: %i\n",somaSalarios(funcionarios,n_de_funcionarios));

    return 0;
}
