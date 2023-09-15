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
typedef struct date Date

struct locacao
{
    lista_cliente *cl;
    lista_veiculo *vc;
    float valor_pago;
    struct Date *data_retirada;
    struct Date *data_devolucao;
}


struct listaLocacao
{
    struct ListaLocacao *ant;
    struct ListaLocacao *prox;
    
};
typedef struct listaLocacao ListaLocacao;



#endif