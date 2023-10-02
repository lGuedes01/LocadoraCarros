#include <stdio.h>
#include "clientes.h"
#include "veiculos.h"
#include "locacoes.h"
#include "menu.h"
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

void imprime_info_locacao_veic(ListaVeiculo *list_veic)
{
    int i = 0;
    ListaVeiculo *p = list_veic;
    while (p != NULL)
    {
        if (p->info.disponivel)
        {
            printf("Carro %d:\n", i + 1);
            printf("\tModelo: %s\n", p->info.modelo);
            printf("\tPlaca: %s\n", p->info.placa);
            i++;
        }
        p = p->prox;
    }
}

bool locacaoAtiva(Locacao locacao)
{
    return !locacao.vc->info.disponivel;
}

void locacoes_ativas(ListaLocacao *lista_locacoes)
{
    printf("Locacoes Ativas:\n");
    for (ListaLocacao *locacao = lista_locacoes; locacao != NULL; locacao = locacao->prox)
    {
        if (locacao->locacao_cliente.locacao_ativa)
        {
            printf("Cliente: %s\n", locacao->locacao_cliente.cl->info.nome);
            printf("Modelo do veiculo: %s\n", locacao->locacao_cliente.vc->info.modelo);
            printf("Placa do veiculo: %s\n", locacao->locacao_cliente.vc->info.placa);
            printf("Data de Retirada: %d/%d/%d\n\n", locacao->locacao_cliente.data_retirada.day,
                   locacao->locacao_cliente.data_retirada.month, locacao->locacao_cliente.data_retirada.year);
        }
    }
}

ListaVeiculo *veiculo_desejado(ListaVeiculo *l)
{
    char placa[20];
    printf("Digite a placa do veiculo que deseja locar: ");
    scanf(" %[^\n]s", placa);
    ListaVeiculo *p;
    for (p = l; p != NULL; p = p->prox)
    {
        if (strcmp(placa, p->info.placa) == 0)
        {
            return p;
        }
    }
    return p;
}

ListaCliente *cliente_desejado(ListaCliente *l)
{
    char cnh[20];
    printf("Digite o CNH do cliente: ");
    scanf(" %[^\n]s", cnh);
    ListaCliente *p;
    for (p = l; p != NULL; p = p->prox)
    {
        if (strcmp(cnh, p->info.cnh) == 0)
        {
            return p;
        }
    }
    return p;
}

ListaLocacao *pega_informacao_locacao(ListaLocacao *nova_locacao, ListaVeiculo *vl, ListaCliente *cl)
{
    nova_locacao->locacao_cliente.vc = veiculo_desejado(vl);
    nova_locacao->locacao_cliente.cl = cliente_desejado(cl);
    if (nova_locacao->locacao_cliente.vc == NULL)
    {
        printf("Veiculo nao encontrado\n");
        return NULL;
    }
    else if (!nova_locacao->locacao_cliente.vc->info.disponivel)
    {
        printf("Veiculo nao disponivel\n");
        return NULL;
    }
    else if (nova_locacao->locacao_cliente.cl == NULL)
    {
        printf("O cliente procurado nao esta na lista. Adicione-o depois tente novamente\n");
        return NULL;
    }
    nova_locacao->locacao_cliente.data_retirada = pega_data("retirada");
    nova_locacao->locacao_cliente.locacao_ativa = true;
    nova_locacao->locacao_cliente.valor_pago = 0;
    nova_locacao->locacao_cliente.vc->info.disponivel = false;
    return nova_locacao;
}

ListaLocacao *realizar_locacao(ListaVeiculo *lista_veic, ListaCliente *lista_cli, ListaLocacao *lista_locacao)
{
    imprime_info_locacao_veic(lista_veic);
    ListaLocacao *nova_locacao;
    nova_locacao = aloca_lista_locacao();
    nova_locacao = pega_informacao_locacao(nova_locacao, lista_veic, lista_cli);
    if (nova_locacao != NULL)
    {
        nova_locacao->prox = lista_locacao;
        lista_locacao = nova_locacao;
    }
    return lista_locacao;
}

void listarVeicDisp(ListaVeiculo *veic)
{
    ListaVeiculo *p;
    for (p = veic; p != NULL; p = p->prox)
    {
        if (p->info.disponivel == true)
        {
            printf("Modelo: %s\nPlaca: %s\n", p->info.modelo, p->info.placa);
        }
    }
}

float calcular_valor_locacao(ListaLocacao *locacao)
{

    int dias_locados = daysBetweenDates(locacao->locacao_cliente.data_retirada, locacao->locacao_cliente.data_devolucao);

    if (dias_locados == 0)
    {
        dias_locados = 1;
    }

    float valor_total = dias_locados * locacao->locacao_cliente.vc->info.preco_diaria;

    return valor_total;
}

int registrar_quilometragem(int km_atual, int kms_rodados)
{
    return km_atual + kms_rodados;
}

void devolver_veiculo(ListaLocacao *lista_locacoes)
{
    char placa_veiculo[10];
    printf("Informe a placa do veiculo a ser devolvido: ");
    scanf(" %[^\n]s, ", placa_veiculo);

    for (ListaLocacao *locacao = lista_locacoes; locacao != NULL; locacao = locacao->prox)
    {
        if (strcmp(placa_veiculo, locacao->locacao_cliente.vc->info.placa) == 0)
        {

            if (locacao->locacao_cliente.vc->info.disponivel == true)
            {
                printf("Este veiculo ja esta disponivel.\n");
            }
            else
            {
                locacao->locacao_cliente.data_devolucao = pega_data("de devolucao");
                float valor_locacao = calcular_valor_locacao(locacao);
                printf("Valor da locacao: %.2f\n", valor_locacao);
                locacao->locacao_cliente.valor_pago = valor_locacao;
                int kms_rodados;
                printf("Informe quantos quilometros foram rodados: ");
                scanf("%d", &kms_rodados);
                int km_atual = locacao->locacao_cliente.vc->info.km_atual;
                locacao->locacao_cliente.vc->info.km_atual = registrar_quilometragem(km_atual, kms_rodados);
                locacao->locacao_cliente.locacao_ativa = false;
                locacao->locacao_cliente.vc->info.disponivel = true;

                printf("Veiculo devolvido com sucesso.\n");
            }
            break;
        }
    }
    printf("Veiculo nao encontrado na lista de locacoes.\n");
}

void listar_locacoes(ListaLocacao *lista_locacoes)
{
    printf("Locacoes:\n");

    for (ListaLocacao *locacao = lista_locacoes; locacao != NULL; locacao = locacao->prox)
    {
        printf("Cliente: %s\n", locacao->locacao_cliente.cl->info.nome);
        printf("Modelo do veiculo: %s\n", locacao->locacao_cliente.vc->info.modelo);
        printf("Placa do veiculo: %s\n", locacao->locacao_cliente.vc->info.placa);
        printf("Data de Retirada: %d/%d/%d\n", locacao->locacao_cliente.data_retirada.day,
               locacao->locacao_cliente.data_retirada.month, locacao->locacao_cliente.data_retirada.year);
        if (!locacao->locacao_cliente.locacao_ativa)
            printf("Data de Devolucao: %d/%d/%d\n", locacao->locacao_cliente.data_devolucao.day,
                   locacao->locacao_cliente.data_devolucao.month, locacao->locacao_cliente.data_devolucao.year);
        printf("Valor pago: %.2f\n", locacao->locacao_cliente.valor_pago);
        printf("\n");
    }
}

void locacoes_realizadas_por_um_cliente(ListaLocacao *lista_locacoes, ListaCliente *cl)
{
    ListaCliente *cliente;
    cliente = cliente_desejado(cl);

    for (ListaLocacao *l = lista_locacoes; l != NULL; l = l->prox)
    {
        if (l->locacao_cliente.cl == cliente)
        {
            imprimir_cliente(l->locacao_cliente.cl->info);
            imprime_veic(l->locacao_cliente.vc->info);
            printf("Data de Retirada: %d/%d/%d\n", l->locacao_cliente.data_retirada.day,
                   l->locacao_cliente.data_retirada.month, l->locacao_cliente.data_retirada.year);
            if (!l->locacao_cliente.locacao_ativa)
                printf("Data de Devolucao: %d/%d/%d\n", l->locacao_cliente.data_devolucao.day,
                       l->locacao_cliente.data_devolucao.month, l->locacao_cliente.data_devolucao.year);
            printf("Valor pago: %.2f\n", l->locacao_cliente.valor_pago);
        }
    }
}

void faturamento_mensal(ListaLocacao *lista_locacoes)
{
    float faturamento = 0;
    Date mes_faturamento = pega_mes();

    for (ListaLocacao *locacao = lista_locacoes; locacao != NULL; locacao = locacao->prox)
    {
        if (mes_faturamento.month == locacao->locacao_cliente.data_devolucao.month &&
            mes_faturamento.year == locacao->locacao_cliente.data_devolucao.year)
        {
            faturamento = faturamento + locacao->locacao_cliente.valor_pago;
        }
    }

    printf("Faturamento mensal: R$%.2f\n", faturamento);
}