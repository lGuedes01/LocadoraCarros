#ifndef CLIENTES_H
#define CLIENTES_H

#include <stdbool.h>

struct DadosClientes
{
    char nome[20];
    char cnh[20];
    char numero[20];
};
typedef struct DadosClientes dadosClientes;

struct ListaCliente
{
    struct ListaCliente *prox;
    dadosClientes dados;
};
typedef struct ListaCliente lista_cliente;


lista_cliente *cria_lista_clientes();
lista_cliente *aloca_lista_clientes();
lista_cliente *add_cliente(lista_cliente *client);
lista_cliente *pega_info_clientes(lista_cliente *cliente);
void imprimir_clientes(lista_cliente *lista_cli);
void imprimir_cliente(dadosClientes cliente);

#endif