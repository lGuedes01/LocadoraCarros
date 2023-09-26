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
    char *nome_cliente;
    nome_cliente = (char*)malloc(20*sizeof(char));
    printf("Informe o CNH do cliente: ");
    scanf(" %[^\n]s, ",nome_cliente);
    for (lista_cliente *l = lista_clientes; l != NULL; l = l->prox)
    {
        if (strcmp(nome_cliente, l->dados.cnh) == 0)
        {
            return l;
        }
    }
    return NULL;
}

lista_veiculo *pega_veiculo(lista_veiculo *veiculos, lista_veiculo* veiculo_para_alocar)
{
    char* placa_veiculo;
    placa_veiculo = (char*)malloc(20*sizeof(char));
    printf("Informe a placa do veiculo: ");
    scanf(" %[^\n]s, ", placa_veiculo);
    for (veiculo_para_alocar = veiculos; veiculo_para_alocar != NULL; veiculo_para_alocar = veiculo_para_alocar->prox)
    {
        if (strcmp(placa_veiculo, veiculo_para_alocar->veic.placa) == 0)
        {
            return veiculo_para_alocar;
        }
    }
    return NULL;
}

ListaLocacao *pega_informacao_locacao(ListaLocacao *locacao_a_realizar,lista_cliente *lista_clientes, lista_veiculo *lista_veic)
{
    lista_cliente *cliente = pega_cliente(lista_clientes);
    if(cliente == NULL)
    {
        lista_clientes = add_cliente(lista_clientes);
        cliente = lista_clientes;
    }
    lista_veiculo *veiculo = NULL;
    veiculo = pega_veiculo(lista_veic, veiculo);

    if (veiculo == NULL)
    {
        printf("Veiculo nao encontrado\n");
        return NULL;
    }
    else if(!veiculo->veic.disponivel)
    {
        printf("Veiculo nao disponivel\n");
        return NULL;
    }
    else
    {
        locacao_a_realizar->locacao_cliente->cl = cliente;
        locacao_a_realizar->locacao_cliente->vc = veiculo;
        return locacao_a_realizar;
    }
}

bool locacaoAtiva(Locacao *locacao, Date data_atual)
{
    return !locacao->vc->veic.disponivel;
}

void locacoes_ativas(ListaLocacao *lista_locacoes, Date data_atual)
{
    printf("Locacoes Ativas:\n");

    for (ListaLocacao *locacao = lista_locacoes; locacao != NULL; locacao = locacao->prox)
    {
        if (locacaoAtiva(locacao->locacao_cliente, data_atual))
        {
            printf("Cliente: %s\n", locacao->locacao_cliente->cl->dados.nome);
            printf("Modelo do veiculo: %s\n", locacao->locacao_cliente->vc->veic.modelo);
            printf("Placa do veiculo: %s\n", locacao->locacao_cliente->vc->veic.placa);
            printf("Data de Retirada: %d/%d/%d\n", locacao->locacao_cliente->data_retirada.day,
                   locacao->locacao_cliente->data_retirada.month, locacao->locacao_cliente->data_retirada.year);
            printf("Data de Devolucao: %d/%d/%d\n", locacao->locacao_cliente->data_devolucao.day,
                    locacao->locacao_cliente->data_devolucao.month, locacao->locacao_cliente->data_devolucao.year);
        }
    }
}

ListaLocacao *locar_veiculo(ListaLocacao *l, ListaLocacao *lista_locacao, Date data_atual)
{
    if (l == NULL)
    {
        printf("Falha ao realizar a locacao!\n");
        return lista_locacao;
    }
    l->locacao_cliente->vc->veic.disponivel = false;
    l->locacao_cliente->data_retirada = data_atual;
    l->locacao_cliente->data_devolucao = pega_data("de devolucao"); // 
    l->prox = lista_locacao;
    lista_locacao = l;
    return lista_locacao;
}


ListaLocacao *realizar_locacao(lista_veiculo *lista_veic, lista_cliente *lista_cli, ListaLocacao *lista_locacao, Date data_atual)
{
    imprime_info_locacao_veic(lista_veic);

    ListaLocacao *l;
    l = pega_informacao_locacao(l,lista_cli, lista_veic);

    lista_locacao = locar_veiculo(l, lista_locacao, data_atual);

    return lista_locacao;
}

void listarVeicDisp(lista_veiculo *veic)
{
    lista_veiculo *p;
    for (p = veic; p != NULL; p = p->prox)
    {
        if (p->veic.disponivel == true)
        {
            printf("Modelo: %s\nPlaca: %s\n", p->veic.modelo, p->veic.placa);
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
    printf("Informe a placa do veiculo a ser devolvido: ");
    scanf(" %[^\n]s, ",placa_veiculo);

    

    for (ListaLocacao* locacao = lista_locacoes; locacao != NULL; locacao = locacao->prox)
    {
        if (strcmp(placa_veiculo, locacao->locacao_cliente->vc->veic.placa) == 0)
        {

            if (locacao->locacao_cliente->vc->veic.disponivel == true)
            {
                printf("Este veiculo ja esta disponivel.\n");
                
            }
            else
            {
                float valor_locacao = calcular_valor_locacao(&locacao->locacao_cliente->vc->veic,
                                                            locacao->locacao_cliente->data_retirada, data_atual);
                printf("Valor da locacao: %.2f\n", valor_locacao);

                int nova_quilometragem;
                printf("Informe a nova quilometragem do veiculo: ");
                scanf("%d", &nova_quilometragem);

                registrar_quilometragem(&locacao->locacao_cliente->vc->veic, nova_quilometragem);

                locacao->locacao_cliente->data_devolucao = data_atual;
                locacao->locacao_cliente->vc->veic.disponivel = true;

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
        printf("Cliente: %s\n", locacao->locacao_cliente->cl->dados.nome);
        printf("Modelo do veiculo: %s\n", locacao->locacao_cliente->vc->veic.modelo);
        printf("Placa do veiculo: %s\n", locacao->locacao_cliente->vc->veic.placa);
        printf("Data de Retirada: %d/%d/%d\n", locacao->locacao_cliente->data_retirada.day,
               locacao->locacao_cliente->data_retirada.month, locacao->locacao_cliente->data_retirada.year);
        printf("Data de Devolucao: %d/%d/%d\n", locacao->locacao_cliente->data_devolucao.day,
               locacao->locacao_cliente->data_devolucao.month, locacao->locacao_cliente->data_devolucao.year);
        printf("Valor pago: %.2f\n", locacao->locacao_cliente->valor_pago);
        printf("\n");
    }
}

void locacoes_realizadas_por_um_cliente(ListaLocacao *lista_locacoes)
{
    lista_cliente* cliente;
    cliente = pega_cliente(cliente);

    for (ListaLocacao* l = lista_locacoes ; l!=NULL ; l = l->prox )
    {
        if (l->locacao_cliente->cl = cliente)
        {
            imprimir_cliente(l->locacao_cliente->cl->dados);
            imprime_veic(l->locacao_cliente->vc->veic);
            printf("Data de Retirada: %d/%d/%d\n", l->locacao_cliente->data_retirada.day,
               l->locacao_cliente->data_retirada.month, l->locacao_cliente->data_retirada.year);
            printf("Data de Devolucao: %d/%d/%d\n", l->locacao_cliente->data_devolucao.day,
               l->locacao_cliente->data_devolucao.month, l->locacao_cliente->data_devolucao.year);
            printf("Valor pago: %.2f\n", l->locacao_cliente->valor_pago);
        }
        
    }
    
}


float faturamento_mensal(ListaLocacao *lista_locacoes)
{
    
}