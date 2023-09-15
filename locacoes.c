#include <stdio.h>
#include "clientes.h"
#include "veiculos.h"
#include "locacoes.h"

ListaLocacao *cria_lista_locacao()
{
    return NULL;
}

ListaLocacao *aloca_lista_locacao()
{
    ListaLocacao *locacao;
    locacao = (ListaLocacao *)malloc(sizeof(ListaLocacao));

    return locacao;
}

// Função para calcular a diferença em dias entre duas datas
int daysBetweenDates(Date date1, Date date2)
{
    int days1 = date1.year * 365 + date1.day;
    int days2 = date2.year * 365 + date2.day;

    // Adicionar dias extras para os anos bissextos
    days1 += date1.year / 4 - date1.year / 100 + date1.year / 400;
    days2 += date2.year / 4 - date2.year / 100 + date2.year / 400;

    // Adicionar dias para os meses
    int monthDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 1; i < date1.month; i++)
    {
        days1 += monthDays[i];
    }
    for (int i = 1; i < date2.month; i++)
    {
        days2 += monthDays[i];
    }

    // Considerar anos bissextos
    if (date1.month <= 2 && (date1.year % 4 == 0 && (date1.year % 100 != 0 || date1.year % 400 == 0)))
    {
        days1--;
    }
    if (date2.month <= 2 && (date2.year % 4 == 0 && (date2.year % 100 != 0 || date2.year % 400 == 0)))
    {
        days2--;
    }

    // Calcular a diferença em dias
    int difference = days2 - days1;
    return difference;
}

void imprime_info_locacao_veic(lista_veiculo *list_veic)
{
    lista_veiculo *p;
    int i;
    for (p = list_veic, i = 1; p != NULL; p = p->prox, i++)
    {
        printf("Carro %d:\n", i);
        printf("\tmodelo: %s\n\tplaca: %s\n", p->veic.modelo, p->veic.placa);
    }
}

ListaLocacao *pega_informacao_locacao()
{
    pega_cliente();
    pega_veiculo();
    verifica_disponibilidade_veic();
}

void realizar_locacao(lista_veiculo *lista_veic, lista_cliente *lista_cli, ListaLocacao *lista_locacao)
{
    imprime_info_locacao_veic(lista_veic);

    lista_locacao = pega_informacao_locacao();

    locar_veiculo();
}
