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


lista_cliente *cria_lista_clientes();
lista_cliente *aloca_lista_clientes();
lista_cliente *add_cliente(lista_cliente *client);
dadosClientes *pega_info_clientes(dadosClientes *dados);
void imprimir_clientes(lista_cliente *lista_cli);

#endif