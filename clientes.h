#ifndef CLIENTES_H
#define CLIENTES_H

#include <stdbool.h>

struct DadosClientes
{
    char *nome;
    char *cnh;
    char *numero;
};
typedef struct DadosClientes dadosClientes;

struct ListaCliente
{
    struct ListaCliente *ant;
    struct ListaCliente *prox;
    dadosClientes *dados;
};
typedef struct ListaCliente lista_cliente;

#endif