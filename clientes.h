#ifndef CLIENTES_H
#define CLIENTES_H

#include <stdbool.h>

struct dados_clientes
{
    char nome[50];
    char cnh[20];
    char numero[20];
};
typedef struct dados_clientes DadosClientes;

struct lista_cliente
{
    struct lista_cliente *prox;
    DadosClientes info;
};
typedef struct lista_cliente ListaCliente;

ListaCliente *cria_lista_clientes();
ListaCliente *aloca_lista_clientes();
ListaCliente *add_cliente(ListaCliente *client);
ListaCliente *pega_info_clientes(ListaCliente *cliente);
void imprimir_clientes(ListaCliente *lista_cli);
void imprimir_cliente(DadosClientes cliente);

#endif