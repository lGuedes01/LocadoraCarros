#ifndef LOCACOES_H
#define LOCACOES_H

#include <stdbool.h>

#include "clientes.h"
#include "veiculos.h"

struct date
{
    int day;
    int month;
    int year;
};
typedef struct date Date;

struct locacao
{
    lista_cliente *cl;
    lista_veiculo *vc;
    float valor_pago;
    Date data_retirada;
    Date data_devolucao;
};
typedef struct locacao Locacao;

struct listaLocacao
{
    Locacao *locacao_cliente;
    struct listaLocacao *ant;
    struct listaLocacao *prox;
};
typedef struct listaLocacao ListaLocacao;

ListaLocacao *cria_lista_locacao();
ListaLocacao *aloca_lista_locacao();
int daysBetweenDates(Date date1, Date date2);
void imprime_info_locacao_veic(lista_veiculo *list_veic);
lista_cliente *pega_cliente(lista_cliente *lista_clientes);
lista_veiculo *pega_veiculo(lista_veiculo *veiculos);
ListaLocacao *pega_informacao_locacao(lista_cliente *lista_clientes, lista_veiculo *lista_veic);
bool locacaoAtiva(Locacao *locacao, Date data_atual);
void locacoes_ativas(ListaLocacao *lista_locacoes, Date data_atual);
ListaLocacao *locar_veiculo(ListaLocacao *l, ListaLocacao *lista_locacao, Date data_atual);
ListaLocacao *realizar_locacao(lista_veiculo *lista_veic, lista_cliente *lista_cli, ListaLocacao *lista_locacao, Date data_atual);
void listarVeicDisp(lista_veiculo *veic);
float calcular_valor_locacao(dadosVeiculo *veiculo, Date data_retirada, Date data_devolucao);
void registrar_quilometragem(dadosVeiculo *veiculo, int nova_quilometragem);
void devolver_veiculo(ListaLocacao *lista_locacoes, Date data_atual);
void listar_locacoes(ListaLocacao *lista_locacoes);
void locacoes_realizadas_por_um_cliente(ListaLocacao *lista_locacoes);

#endif