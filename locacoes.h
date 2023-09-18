#ifndef LOCACOES_H
#define LOCACOES_H

#include <stdbool.h>

#include "clientes.h"
#include "veiculos.h"

struct Date
{
    int day;
    int month;
    int year;
};
typedef struct Date Date;

struct locacao
{
    lista_cliente *cl;
    lista_veiculo *vc;
    float valor_pago;
    struct Date *data_retirada;
    struct Date *data_devolucao;
};
typedef struct locacao Locacao;

struct listaLocacao
{
    Locacao *locacao_cliente;
    struct listaLocacao *ant;
    struct listaLocacao *prox;
};
typedef struct listaLocacao ListaLocacao;

#endif