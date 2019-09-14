#include <stdio.h>
#include <stdlib.h>

static int menu;

int main()
{
    #pragma region Métodos
    int MenuPrincipal();
    void PessoaMaisPesada();
    void PessoaMenosPesada();
    void ConsultaPessoa();
    void InserePessoa();
    void RemovePessoa();
    void ConsultaNumeroDePessoas();
    void VerificaTodosDadosDePessoas();
    void EncerraOsistema();
    #pragma endregion

    #pragma region Estruturas de Dados
    typedef struct
    {
        int codigo;
        float peso;
        char sexo;
    } Hospede;

    typedef  Hospede Hotel[10];
    Hotel Pessoa;
    #pragma endregion
    
    menu = MenuPrincipal();
    
    #pragma region Switch Case 
    while (menu < 8)
    {
        switch (menu)
        {
        case 1:
            PessoaMaisPesada();
            break;
        case 2:
            PessoaMenosPesada();
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
            ConsultaNumeroDePessoas();
            break;
        case 7:
            VerificaTodosDadosDePessoas();
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
    printf(" 7 - Verificar todos os dados\n");
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

#pragma region Menus Secundários
void PessoaMaisPesada()
{
    printf("________________________________\n\n");
    printf("     Pessoa mais pesada\n\n");
    system("pause");
}

void PessoaMenosPesada()
{
    printf("________________________________\n\n");
    printf("     Pessoa menos pesada\n\n");
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

void ConsultaNumeroDePessoas()
{
    printf("________________________________\n\n");
    printf("  Consultar numero de pessoas\n\n");
    system("pause");
}

void VerificaTodosDadosDePessoas()
{
    printf("________________________________\n\n");
    printf("  Verificar todos os registros\n\n");
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