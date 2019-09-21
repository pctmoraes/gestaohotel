#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma region Estrutura de Dados
static int menu;
static int i;

typedef struct 
{
    int Codigo;
    float Peso;
    char Sexo;
} Hospede;

typedef  Hospede Hotel[10];
#pragma endregion

#pragma region Menus Secundários
void PessoaMaisPesada(Hotel Pessoa, int *fim)
{
    printf("____________________________________________\n\n");
    printf("              Pessoa mais pesada\n\n");
    printf("                    - - -\n\n");
    if (*fim == -1)
        printf("\t  Nao ha pessoas cadastradas.\n\n\t Acesse a opcao 4 para cadastrar.\n\n");
    else
    {
        printf("\t   Codigo  |  Peso  |  Sexo\n\n");
        printf("\t     %d     | %.2f  |    %c\n\n", Pessoa[0].Codigo, Pessoa[0].Peso, Pessoa[0].Sexo);
    }
    system("pause");
}

void PessoaMenosPesada(Hotel Pessoa, int *fim)
{
    printf("____________________________________________\n\n");
    printf("              Pessoa menos pesada\n\n");
    printf("                    - - -\n\n");
    if (*fim == -1)
        printf("\t Nao ha pessoas cadastradas.\n\n\t Acesse a opcao 4 para cadastrar.\n\n");
    else
    {
        printf("\t   Codigo  |  Peso  |  Sexo\n\n");
        printf("\t     %d     | %.2f  |    %c\n\n", Pessoa[*fim].Codigo, Pessoa[*fim].Peso, Pessoa[*fim].Sexo);
    }
    system("pause");
}

void ConsultaPessoa(Hotel Pessoa, int *fim)
{
    int codigo;
    int index = -1;

    printf("____________________________________________\n\n");
    printf("               Consultar pessoa\n\n");
    printf("                    - - -\n\n");
    if (*fim == -1)
        printf("\t  Nao ha pessoas para consultar.\n\n\t Acesse a opcao 4 para cadastrar.\n\n");
    else
    {
        printf("\n\n\t       Digite o codigo: ");
        scanf("%i", &codigo);

        for (i = 0; i <= *fim; i++)
        {
            if (Pessoa[i].Codigo == codigo)
            {
                index = i;
                i = *fim;
            }
        }

        if (index != -1)
        {
            printf("\n\n\t    Codigo  |  Peso  |  Sexo\n\n");
            printf("\t      %d     | %.2f  |    %c\n\n", Pessoa[index].Codigo, Pessoa[index].Peso, Pessoa[index].Sexo);
        }
        else
            printf("\n\n\t         Codigo invalido!\n\n");
    }
    system("pause");
}

void InserePessoa(Hotel Pessoa, int *fim)
{
    Hospede PessoaTemporaria;

    printf("____________________________________________\n\n");
    printf("                Inserir pessoa\n\n");
    printf("                    - - -\n\n");
    if (*fim == 9)
    {
        printf("\tDesculpe,\n\tnao ha vagas disponiveis\n\tpara um novo cadastro.\n\n");
        system("pause");
        return;
    }
    else
    {
        printf("       Codigo: ");
        scanf("%i", &Pessoa[*fim+1].Codigo);
        printf("       Peso: ");
        scanf("%f", &Pessoa[*fim+1].Peso);
        printf("       Sexo: ");
        fflush(stdin);
        Pessoa[*fim+1].Sexo = getchar();
        
        (*fim)++;

        for (i = 0; i <= *fim; i++)
        {
            if (Pessoa[i].Peso < Pessoa[*fim].Peso)
            {
                PessoaTemporaria = Pessoa[*fim];
                Pessoa[*fim] = Pessoa[i];
                Pessoa[i] = PessoaTemporaria;
            }
            
        }

        printf("\n\n       Pessoa cadastrada com sucesso!\n\n");
    }
    
    system("pause");
}

void RemovePessoa(Hotel Pessoa, int *fim)
{
    int codigo;
    int index = -1;

    printf("____________________________________________\n\n");
    printf("                Remover pessoa\n\n");
    printf("                    - - -\n\n");
    if (*fim == -1)
        printf("\t  Nao ha pessoas para remover.\n\n\t Acesse a opcao 4 para cadastrar.\n\n");
    else
    {
        printf("\n\n\t       Digite o codigo: ");
        scanf("%i", &codigo);

        for (i = 0; i <= *fim; i++)
        {
            if (Pessoa[i].Codigo == codigo)
            {
                index = i;
                i = *fim;
            }
        }

        if (index != -1)
        {
            for (i = index + 1; i <= *fim; i++)
            {
                Pessoa[index].Codigo = Pessoa[index+1].Codigo;
                Pessoa[index].Peso = Pessoa[index+1].Peso;
                Pessoa[index].Sexo = Pessoa[index+1].Sexo;
            }

            (*fim)--;

            printf("\n\n\t   Pessoa removida com sucesso.\n\n");
        }
        else
            printf("\n\n\t         Codigo invalido!\n\n");
    }
    
    system("pause");
}

void ConsultaNumeroDePessoas(int *fim)
{
    printf("____________________________________________\n\n");
    printf("\t  Consultar numero de pessoas\n\n");
    printf("\t\t    - - -\n\n");
    if (*fim == -1)
        printf("\tPessoas cadastradas = 0\n\n\tAcesse a opcao 4 para cadastrar.\n\n");
    else
        printf("\t  Pessoas cadastradas = %d\n\n", (*fim)+1);
    system("pause");
}

void ConsultaTodasAsPessoas(Hotel Pessoa, int *fim)
{
    printf("____________________________________________\n\n");
    printf("\t  Consultar todas as Pessoas\n\n");
    printf("\t\t     - - -\n\n");
    if (*fim == -1)
        printf("\tNao ha pessoas cadastradas.\n\n\tAcesse a opcao 4 para cadastrar.\n\n");
    else
    {
        printf("\t   Codigo  |  Peso  |  Sexo\n\n");
        for (i = 0; i <= *fim; i++)
            printf("\t     %d     | %.2f  |    %c\n\n", Pessoa[i].Codigo, Pessoa[i].Peso, Pessoa[i].Sexo);
    }
    system("pause");
}

void EncerraOsistema()
{
    printf("____________________________________________\n\n");
    printf("           Encerrando o sistema..\n\n");
    printf("           Encerrando o sistema...\n\n");
    printf("           Sistema encerrado.\n\n");
}
#pragma endregion

int MenuPrincipal()
{
    printf("____________________________________________\n\n");
    printf("               Menu  Principal\n\n");
    printf("      1 - Mais Pesado\n");
    printf("      2 - Menos Pesado\n");
    printf("      3 - Consultar Pessoa\n");
    printf("      4 - Inserir Pessoa\n");
    printf("      5 - Remover Pessoa\n");
    printf("      6 - Consultar numero de Pessoas\n");
    printf("      7 - Consultar todas as Pessoas\n");
    printf("      8 - Encerrar\n");
    printf("____________________________________________\n\n");
    printf("          Digite o menu desejado: ");

	scanf("%i", &menu);
    if (menu != 8)
    {
        while (menu < 1 || menu > 8)
	    {
            printf("____________________________________________\n\n");
            printf("          Menu invalido!\n");
            printf("____________________________________________\n\n");
            printf("          Digite o menu desejado: ");
            scanf("%i", &menu);
	    }
    }

    return menu;
}

int main()
{
    #pragma region Variáveis auxiliares
    Hotel Pessoa;
    int fim = -1;
    #pragma endregion

    #pragma region Métodos
    /*int MenuPrincipal();
    void PessoaMaisPesada(Hotel Pessoa, int *fim);
    void PessoaMenosPesada(Hotel Pessoa, int *fim);
    void ConsultaPessoa(Hotel Pessoa, int *fim);
    void InserePessoa(Hotel Pessoa, int *fim);
    void RemovePessoa(Hotel Pessoa, int *fim);
    void ConsultaNumeroDePessoas(int *fim);
    void ConsultaTodasAsPessoas(Hotel Pessoa, int *fim);
    void EncerraOsistema();*/
    #pragma endregion
    
    menu = MenuPrincipal();
    
    #pragma region Switch Case 
    while (menu < 8)
    {
        switch (menu)
        {
        case 1:
            PessoaMaisPesada(Pessoa, &fim);
            break;
        case 2:
            PessoaMenosPesada(Pessoa, &fim);
            break;
        case 3:
            ConsultaPessoa(Pessoa, &fim);
            break;
        case 4:
            InserePessoa(Pessoa, &fim);
            break;
        case 5:
            RemovePessoa(Pessoa, &fim);
            break;
        case 6:
            ConsultaNumeroDePessoas(&fim);
            break;
        case 7:
            ConsultaTodasAsPessoas(Pessoa, &fim);
            break;
        case 8:
            EncerraOsistema();
            break;
        }

        menu = MenuPrincipal();
    }
    #pragma endregion
    
    EncerraOsistema();
}

