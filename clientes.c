
#include "clientes.h"
#include "veiculos.h"
#include "locacoes.h"
#include <stdlib.h>

#include <stdio.h>

ListaCliente *cria_lista_clientes()
{
    return NULL;
}

ListaCliente *aloca_lista_clientes()
{

    ListaCliente *cliente;
    cliente = (ListaCliente *)malloc(sizeof(ListaCliente));
    return cliente;
}

ListaCliente *pega_info_clientes(ListaCliente* cliente)
{
    printf("Nome: ");
    scanf(" %[^\n]s", cliente->info.nome);
    printf("CNH: ");
    scanf(" %[^\n]s", cliente->info.cnh);
    printf("Numero de Telefone: ");
    scanf(" %[^\n]s", cliente->info.numero);
    return cliente;
}

ListaCliente* add_cliente(ListaCliente *list_client)
{

    printf("CRIANDO CLIENTE:\n");
    ListaCliente *novo_cliente;
    novo_cliente = aloca_lista_clientes();
    novo_cliente = pega_info_clientes(novo_cliente);
    novo_cliente->prox = list_client;
    list_client = novo_cliente;
    return list_client;
}

void imprimir_clientes(ListaCliente *lista_cli)
{
    ListaCliente *cliente;
    int i;
    for (cliente = lista_cli, i = 1; cliente != NULL; cliente = cliente->prox, i++)
    {
        printf("Cliente %d:\n", i);
        imprimir_cliente(cliente->info);
    }
}

void imprimir_cliente(DadosClientes cliente)
{
    printf("\tNome: %s\n\tCNH: %s\n\tNumero de Telefone: %s\n", cliente.nome,
        cliente.cnh, cliente.numero);
}