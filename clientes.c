
#include "clientes.h"
#include "veiculos.h"
#include "locacoes.h"
#include <stdlib.h>

#include <stdio.h>

lista_cliente *cria_lista_clientes()
{
    return NULL;
}

lista_cliente *aloca_lista_clientes()
{

    lista_cliente *cliente;
    cliente = (lista_cliente *)malloc(sizeof(lista_cliente));
    return cliente;
}

lista_cliente *pega_info_clientes(lista_cliente* cliente)
{
    printf("Nome: ");
    scanf(" %[^\n]s", cliente->dados.nome);
    printf("CNH: ");
    scanf(" %[^\n]s", cliente->dados.cnh);
    printf("Numero de Telefone: ");
    scanf(" %[^\n]s", cliente->dados.numero);
    return cliente;
}

lista_cliente* add_cliente(lista_cliente *list_client)
{

    printf("CRIANDO CLIENTE:\n");
    lista_cliente *novo_cliente;
    novo_cliente = aloca_lista_clientes();
    novo_cliente = pega_info_clientes(novo_cliente);
    novo_cliente->prox = list_client;
    list_client = novo_cliente;
    return list_client;
}

void imprimir_clientes(lista_cliente *lista_cli)
{
    lista_cliente *cliente;
    int i;
    for (cliente = lista_cli, i = 1; cliente != NULL; cliente = cliente->prox, i++)
    {
        printf("Cliente %d:\n", i);
        imprimir_cliente(cliente->dados);
    }
}

void imprimir_cliente(dadosClientes cliente)
{
    printf("\tNome: %s\n\tCNH: %s\n\tNumero de Telefone: %s\n", cliente.nome,
        cliente.cnh, cliente.numero);
}