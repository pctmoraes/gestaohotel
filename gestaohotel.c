#include <stdio.h>
#include <stdlib.h>

int main()
{
    #pragma region Métodos
    void MenuPrincipal();
    void PessoaMaisPesada();
    void PessoaMenosPesada();
    void ConsultaPessoa();
    void InserePessoa();
    void RemovePessoa();
    void ConsultaNumeroDePessoas();
    void VerificaTodosDadosDePessoas();
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
    
    #pragma region Variáveis 
    int menu;
    #pragma endregion

    MenuPrincipal();
    scanf("%d", &menu);
    
    #pragma region Switch Case 
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
    }
    #pragma endregion
}

void MenuPrincipal()
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
    printf("________________________________\n\n");
    printf("   Digite o menu desejado: ");
}

#pragma region Menus Secundários
void PessoaMaisPesada()
{
    printf("________________________________\n\n");
    printf("     Pessoa mais pesada\n\n");
}

void PessoaMenosPesada()
{
    printf("________________________________\n\n");
    printf("     Pessoa menos pesada\n\n");
}

void ConsultaPessoa()
{
    printf("________________________________\n\n");
    printf("     Consultar pessoa\n\n");
}

void InserePessoa()
{
    printf("________________________________\n\n");
    printf("     Inserir pessoa\n\n");
}

void RemovePessoa()
{
    printf("________________________________\n\n");
    printf("     Remover pessoa\n\n");
}

void ConsultaNumeroDePessoas()
{
    printf("________________________________\n\n");
    printf("  Consultar numero de pessoas\n\n");
}

void VerificaTodosDadosDePessoas()
{
    printf("________________________________\n\n");
    printf("  Verificar todos os registros\n\n");
}
#pragma endregion