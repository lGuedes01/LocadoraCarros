#include <stdio.h>
#include "clientes.h"
#include "veiculos.h"
#include "locacoes.h"
#include "menu.h"

void imprime_menu()
{
    printf("\n"
           "-----------------------------------------------\n"
           "1 - Incluir Veiculos\n"
           "2 - Listar Veiculos\n"
           "3 - Incluir Clientes\n"
           "4 - Listar Clientes\n"
           "5 - Realizar Locacao\n"
           "6 - Devolver Veiculo\n"
           "7 - Listar Locacoes\n"
           "8 - Locacoes Ativas\n"
           "9 - Locacoes Realizadas Por Um Cliente\n"
           "10 - Faturamento Mensal da Locadora\n"
           "11 - Os Tres Veiculos Mais Rodados\n"
           "12 - Placa e Modelo dos Veiculos nao Locados\n"
           "-1 - Sair\n"
           "-----------------------------------------------\n");
}

int pega_opcao()
{
    int opcao;
    printf("Digite a opcao que deseja acessar: ");
    do
    {
        scanf("%d", &opcao);
        if (opcao < -1 && opcao > 12)
        {
            printf("Digite uma opcao valida!");
        }
    } while (opcao < -1 && opcao > 12);
    return opcao;
}

Date pega_data(char *termo)
{
    Date data;

    printf("Informe a data %s (dd/mm/aaaa): ", termo);
    scanf("%d/%d/%d", &data.day, &data.month, &data.year);

    return data;
}

Date pega_mes()
{
    Date data;
    printf("Digite o mes que deseja verificar o faturamento(mm/aaaa): ");
    scanf("%d/%d", &data.month, &data.year);

    return data;
}

void menu(ListaCliente *lista_clientes, ListaVeiculo *lista_veiculos, ListaLocacao *lista_locacoes)
{
    int opcao = 0;
    do
    {
        imprime_menu();
        opcao = pega_opcao();
        switch (opcao)
        {
        case 1:
            lista_veiculos = add_veic(lista_veiculos);
            break;
        case 2:
            imprime_veiculos(lista_veiculos);
            break;
        case 3:
            lista_clientes = add_cliente(lista_clientes);
            break;
        case 4:
            imprimir_clientes(lista_clientes);
            break;
        case 5:
            lista_locacoes = realizar_locacao(lista_veiculos, lista_clientes, lista_locacoes);
            break;
        case 6:
            devolver_veiculo(lista_locacoes);
            break;
        case 7:
            listar_locacoes(lista_locacoes);
            break;
        case 8:
            locacoes_ativas(lista_locacoes);
            break;
        case 9:
            locacoes_realizadas_por_um_cliente(lista_locacoes, lista_clientes);
            break;
        case 10:
            faturamento_mensal(lista_locacoes);
            break;
        case 11:
            top3MaisRodados(lista_veiculos);
            break;
        case 12:
            listarVeicDisp(lista_veiculos);
            break;
        case -1:
            printf("Obrigado por usar o sistema!\n");
            break;
        default:
            break;
        }
    } while (opcao != -1);
}
