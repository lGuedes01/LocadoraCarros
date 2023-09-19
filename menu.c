#include <stdio.h>
#include "clientes.h"
#include "veiculos.h"
#include "locacoes.h"

void imprime_menu()
{
    printf("1 - Incluir Veículos\n"
           "2 - Listar Veículos\n"
           "3 - Incluir Clientes\n"
           "4 - Listar Clientes\n"
           "5 - Realizar Locação\n"
           "6 - Devolver Veículo\n"
           "7 - Listar Locações\n"
           "8 - Locações Ativas\n"
           "9 - Locações Realizadas Por Um Cliente\n"
           "10 - Faturamento Mensal da Locadora\n"
           "11 - Os Três Veículos Mais Rodados\n"
           "12 - Placa e Modelo dos Veículos não Locados\n");
}

int pega_opcao()
{
    int opcao;
    printf("Digite a opção que deseja acessar!");
    do
    {
        scanf("%d", &opcao);
        if (opcao < -1 && opcao > 12)
        {
            printf("Digite uma opção válida!");
        }
    } while (opcao < -1 && opcao > 12);
    return opcao;
}

Date pega_data(char termo)
{
    Date data;

    printf("Informe a data %s (dd/mm/aaaa): ", termo);
    scanf("%d/%d/%d", &data.day, &data.month, &data.year);

    return data;
}

void menu(lista_cliente *lista_clientes, lista_veiculo *lista_veiculos, ListaLocacao *lista_locacoes, Date data_atual)
{
    int opcao = 0;
    do
    {
        imprime_menu();
        int opcao = pega_opcao();
        switch (opcao)
        {
        case 1:
            lista_veiculos = add_veic(lista_veiculos);
            break;
        case 2:
            imprime_veic(lista_veiculos);
            break;
        case 3:
            lista_clientes = add_cliente(lista_clientes);
            break;
        case 4:
            imprimir_clientes(lista_clientes);
            break;
        case 5:
            lista_locacoes = realizar_locacao(lista_veiculos, lista_clientes, lista_locacoes, data_atual);
            break;
        case 6:
            devolver_veiculo(lista_locacoes, data_atual);
            break;
        case 7:
            listar_locacoes(lista_locacoes);
            break;
        case 8:
            locacoes_ativas(lista_locacoes, data_atual);
            break;
        case 9:
            locacoes_realizadas_por_um_cliente(lista_locacoes);
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
        default:
            break;
        }
    } while (opcao != -1);
}

