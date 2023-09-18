#include <stdio.h>
#include "clientes.h"
#include "veiculos.h"
#include "locacoes.h"
#include <stdlib.h>
#include <string.h>

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
lista_cliente *pega_cliente(lista_cliente *lista_clientes)
{
    char nome_cliente[20];
    printf("Informe o CNH do cliente: ");
    fgets(nome_cliente, sizeof(nome_cliente), stdin);

    nome_cliente[strcspn(nome_cliente, "\n")] = '\0';
    lista_cliente *l = aloca_lista_clintes();

    for (l = lista_clientes->prox; l != NULL; l = l->prox)
    {
        if (strcmp(nome_cliente, l->dados->cnh) == 0)
        {
            return l;
        }
    }
    return NULL;
}

lista_veiculo *pega_veiculo(lista_veiculo *veiculos)
{
    char placa_veiculo[10];
    printf("Informe a placa do veículo: ");
    fgets(placa_veiculo, sizeof(placa_veiculo), stdin);

    placa_veiculo[strcspn(placa_veiculo, "\n")] = '\0';
    lista_veiculo *l = aloca_veic();
    for (l = veiculos->prox; l != NULL; l = l->prox)
    {
        if (strcmp(placa_veiculo, l->veic.placa) == 0)
        {
            return l;
        }
    }
    return NULL;
}

ListaLocacao *pega_informacao_locacao(lista_cliente *lista_clientes, lista_veiculo *lista_veic)
{
    lista_cliente *cliente = pega_cliente(lista_clientes);
    lista_veiculo *veiculo = pega_veiculo(lista_veic);

    if (cliente == NULL || veiculo == NULL || !veiculo->veic.disponivel)
    {
        printf("Cliente ou veículo não disponível.\n");
        return NULL;
    }
    else
    {
        ListaLocacao *locacao_a_realizar = aloca_lista_locacao();
        locacao_a_realizar->locacao_cliente->cl = cliente;
        locacao_a_realizar->locacao_cliente->vc = veiculo;
        return locacao_a_realizar;
    }
}

bool locacaoAtiva(Locacao *locacao, Date data_atual)
{
    if (!locacao->vc->veic.disponivel == true)
    {
        return true;
    }
    return false;
}

void locacoes_ativas(ListaLocacao *lista_locacoes, Date data_atual)
{
    printf("Locações Ativas:\n");

    for (ListaLocacao *locacao = lista_locacoes; locacao != NULL; locacao = locacao->prox)
    {
        if (locacaoAtiva(locacao->locacao_cliente, data_atual))
        {
            printf("Cliente: %s\n", locacao->locacao_cliente->cl->dados->nome);
            printf("Veículo: %s\n", locacao->locacao_cliente->vc->veic.modelo);
            printf("Data de Retirada: %d/%d/%d\n", locacao->locacao_cliente->data_retirada->day,
                   locacao->locacao_cliente->data_retirada->month, locacao->locacao_cliente->data_retirada->year);
            if (locacao->locacao_cliente->data_devolucao != NULL)
            {
                printf("Data de Devolução: %d/%d/%d\n", locacao->locacao_cliente->data_devolucao->day,
                       locacao->locacao_cliente->data_devolucao->month, locacao->locacao_cliente->data_devolucao->year);
            }
            else
            {
                printf("Ainda não devolvido\n");
            }
            printf("\n");
        }
    }
}

ListaLocacao *locar_veiculo(ListaLocacao *l, ListaLocacao *lista_locacao, Date *data_atual)
{
    if (l == NULL)
    {
        printf("Falha ao realizar a locacao!\n");
        return lista_locacao;
    }
    l->locacao_cliente->data_retirada = data_atual;
    l->locacao_cliente->data_devolucao = pega_data("de devolução");
    l->ant == NULL;
    l->prox = lista_locacao;
    lista_locacao->ant = l;

    return l;
}

ListaLocacao *realizar_locacao(lista_veiculo *lista_veic, lista_cliente *lista_cli, ListaLocacao *lista_locacao, Date *data_atual)
{
    imprime_info_locacao_veic(lista_veic);

    ListaLocacao *l = pega_informacao_locacao(lista_cli, lista_veic);

    lista_locacao = locar_veiculo(l, lista_locacao, data_atual);

    return lista_locacao;
}

void listarVeicDisp(lista_veiculo *veic)
{
    lista_veiculo *p;
    int i;
    for (p = veic, i = 1; p != NULL; p = p->prox, i++)
    {
        if (p->veic.disponivel == true)
        {
            printf("modelo: %s\nplaca: %s\n", p->veic.modelo, p->veic.placa);
        }
    }
}

float calcular_valor_locacao(dadosVeiculo *veiculo, Date data_retirada, Date data_devolucao)
{

    int dias_locados = daysBetweenDates(data_retirada, data_devolucao);

    float valor_total = dias_locados * veiculo->preco_diaria;

    return valor_total;
}

void registrar_quilometragem(dadosVeiculo *veiculo, int nova_quilometragem)
{
    if (nova_quilometragem > veiculo->km_atual)
    {
        veiculo->km_atual = nova_quilometragem;
    }
    else
    {
        printf("A nova quilometragem deve ser maior do que a quilometragem atual.\n");
    }
}

void devolver_veiculo(ListaLocacao *lista_locacoes, Date data_atual)
{
    char placa_veiculo[10];
    printf("Informe a placa do veículo a ser devolvido: ");
    fgets(placa_veiculo, sizeof(placa_veiculo), stdin);
    placa_veiculo[strcspn(placa_veiculo, "\n")] = '\0';

    ListaLocacao *locacao = aloca_lista_locacao();

    for (locacao = lista_locacoes; locacao != NULL; locacao = locacao->prox)
    {
        if (strcmp(placa_veiculo, locacao->locacao_cliente->vc->veic.placa) == 0)
        {

            if (locacao->locacao_cliente->vc->veic.disponivel == true)
            {
                printf("Este veículo já foi devolvido.\n");
                return;
            }

            float valor_locacao = calcular_valor_locacao(&locacao->locacao_cliente->vc->veic,
                                                         *locacao->locacao_cliente->data_retirada, data_atual);
            printf("Valor da locação: %.2f\n", valor_locacao);

            int nova_quilometragem;
            printf("Informe a nova quilometragem do veículo: ");
            scanf("%d", &nova_quilometragem);

            registrar_quilometragem(&locacao->locacao_cliente->vc->veic, nova_quilometragem);

            locacao->locacao_cliente->data_devolucao = &data_atual;
            locacao->locacao_cliente->vc->veic.disponivel = true;

            printf("Veículo devolvido com sucesso.\n");
            return;
        }
    }
    printf("Veículo não encontrado na lista de locações.\n");
}

void listar_locacoes(ListaLocacao *lista_locacoes)
{
    printf("Locações:\n");

    for (ListaLocacao *locacao = lista_locacoes; locacao != NULL; locacao = locacao->prox)
    {
        printf("Cliente: %s\n", locacao->locacao_cliente->cl->dados->nome);
        printf("Veículo: %s\n", locacao->locacao_cliente->vc->veic.modelo);
        printf("Data de Retirada: %d/%d/%d\n", locacao->locacao_cliente->data_retirada->day,
               locacao->locacao_cliente->data_retirada->month, locacao->locacao_cliente->data_retirada->year);
        printf("Data de Devolução: %d/%d/%d\n", locacao->locacao_cliente->data_devolucao->day,
               locacao->locacao_cliente->data_devolucao->month, locacao->locacao_cliente->data_devolucao->year);
        printf("Valor pago: %f\n", locacao->locacao_cliente->valor_pago);
        printf("\n");
    }
}
