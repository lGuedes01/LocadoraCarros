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
    ListaCliente *cl;
    ListaVeiculo *vc;
    float valor_pago;
    Date data_retirada;
    Date data_devolucao;
    bool locacao_ativa;
};
typedef struct locacao Locacao;

struct listaLocacao
{
    Locacao locacao_cliente;
    struct listaLocacao *prox;
};
typedef struct listaLocacao ListaLocacao;

ListaLocacao *cria_lista_locacao();
ListaLocacao *aloca_lista_locacao();
int daysBetweenDates(Date date1, Date date2);
void imprime_info_locacao_veic(ListaVeiculo *list_veic);
ListaCliente *cliente_desejado(ListaCliente *lista_clientes);
ListaVeiculo *veiculo_desejado(ListaVeiculo *veiculos);
ListaLocacao *pega_informacao_locacao(ListaLocacao *locacao_a_realizar, ListaVeiculo *lista_veic, ListaCliente *lista_clientes);
bool locacaoAtiva(Locacao locacao);
void locacoes_ativas(ListaLocacao *lista_locacoes);
ListaLocacao *realizar_locacao(ListaVeiculo *lista_veic, ListaCliente *lista_cli, ListaLocacao *lista_locacao);
void listarVeicDisp(ListaVeiculo *veic);
float calcular_valor_locacao(ListaLocacao* locacao);
int registrar_quilometragem(int km_atual, int kms_rodados);
void devolver_veiculo(ListaLocacao *lista_locacoes);
void listar_locacoes(ListaLocacao *lista_locacoes);
void locacoes_realizadas_por_um_cliente(ListaLocacao *lista_locacoes, ListaCliente* cl);
void faturamento_mensal(ListaLocacao *lista_locacoes);
bool verifica_data(Date data, ListaLocacao *l, char *placa);

#endif