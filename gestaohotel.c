#include <stdio.h>
#include <stdlib.h>

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
    printf("________________________________\n\n");
    printf("     Pessoa mais pesada\n\n");
    printf("           - - -\n\n");
    if (*fim == -1)
        printf("  Nao ha pessoas cadastradas.\n\n  Acesse a opcao 4 para cadastrar.\n\n");
    else
    {
        printf("  Codigo  |  Peso  |  Sexo\n\n");
        printf("    %d     | %.2f  |    %c\n\n", Pessoa[0].Codigo, Pessoa[0].Peso, Pessoa[0].Sexo);
    }
    system("pause");
}

void PessoaMenosPesada(Hotel Pessoa, int *fim)
{
    printf("________________________________\n\n");
    printf("     Pessoa menos pesada\n\n");
    printf("           - - -\n\n");
    if (*fim == -1)
        printf("  Nao ha pessoas cadastradas.\n\n  Acesse a opcao 4 para cadastrar.\n\n");
    else
    {
        printf("  Codigo  |  Peso  |  Sexo\n\n");
        printf("    %d     | %.2f  |    %c\n\n", Pessoa[*fim].Codigo, Pessoa[*fim].Peso, Pessoa[*fim].Sexo);
    }
    system("pause");
}

void ConsultaPessoa()
{
    printf("________________________________\n\n");
    printf("     Consultar pessoa\n\n");
    system("pause");
}

void InserePessoa()
{
    printf("________________________________\n\n");
    printf("     Inserir pessoa\n\n");
    system("pause");
}

void RemovePessoa()
{
    printf("________________________________\n\n");
    printf("     Remover pessoa\n\n");
    system("pause");
}

void ConsultaNumeroDePessoas(int *fim)
{
    printf("________________________________\n\n");
    printf("  Consultar numero de pessoas\n\n");
    printf("            - - -\n\n");
    if (*fim == -1)
        printf("  Pessoas cadastradas = 0\n\n  Acesse a opcao 4 para cadastrar.\n\n");
    else
        printf("  Pessoas cadastradas = %d\n\n", (*fim)+1);
    system("pause");
}

void ConsultaTodasAsPessoas(Hotel Pessoa, int *fim)
{
    printf("________________________________\n\n");
    printf("  Consultar todas as Pessoas\n\n");
    printf("            - - -\n\n");
    if (*fim == -1)
        printf("  Nao ha pessoas cadastradas.\n\n  Acesse a opcao 4 para cadastrar.\n\n");
    else
    {
        printf("  Codigo  |  Peso  |  Sexo\n\n");
        for (i = 0; i <= *fim; i++)
            printf("    %d     | %.2f  |    %c\n\n", Pessoa[i].Codigo, Pessoa[i].Peso, Pessoa[i].Sexo);
    }
    system("pause");
}

void EncerraOsistema()
{
    printf("________________________________\n\n");
    printf("  Encerrando o sistema..\n\n");
    printf("  Encerrando o sistema...\n\n");
    printf("  Sistema encerrado.\n\n");
}
#pragma endregion

int MenuPrincipal()
{
    printf("________________________________\n\n");
    printf("        Menu  Principal\n\n");
    printf(" 1 - Mais Pesado\n");
    printf(" 2 - Menos Pesado\n");
    printf(" 3 - Consultar Pessoa\n");
    printf(" 4 - Inserir Pessoa\n");
    printf(" 5 - Remover Pessoa\n");
    printf(" 6 - Consultar numero de Pessoas\n");
    printf(" 7 - Consultar todas as Pessoas\n");
    printf(" 8 - Encerrar\n");
    printf("________________________________\n\n");
    printf("   Digite o menu desejado: ");

	scanf("%i", &menu);
    if (menu != 8)
    {
        while (menu < 1 || menu > 8)
	    {
            printf("________________________________\n\n");
            printf("   Menu invalido!\n");
            printf("________________________________\n\n");
            printf("   Digite o menu desejado: ");
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
    int MenuPrincipal();
    void PessoaMaisPesada(Hotel Pessoa, int *fim);
    void PessoaMenosPesada(Hotel Pessoa, int *fim);
    void ConsultaPessoa();
    void InserePessoa();
    void RemovePessoa();
    void ConsultaNumeroDePessoas(int *fim);
    void ConsultaTodasAsPessoas(Hotel Pessoa, int *fim);
    void EncerraOsistema();
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
            ConsultaPessoa();
            break;
        case 4:
            InserePessoa();
            break;
        case 5:
            RemovePessoa();
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

