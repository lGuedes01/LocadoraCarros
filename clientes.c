
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

    lista_cliente *cliente = (lista_cliente *)malloc(sizeof(lista_cliente));

    return cliente;
}

lista_cliente* add_cliente(lista_cliente *client)
{

    printf("CRIANDO CLIENTE:\n");
    dadosClientes *dados = (dadosClientes *)malloc(sizeof(dadosClientes));
    lista_cliente *novo_cliente = aloca_lista_clientes();

    dados = pega_info_clientes(dados);

    novo_cliente->dados = dados;
    novo_cliente->ant = NULL;
    novo_cliente->prox = client;

    if (client != NULL)
    {
        client->ant = novo_cliente;
    }

    return novo_cliente;
}

dadosClientes *pega_info_clientes(dadosClientes *dados)
{
    dados->nome = (char *)malloc(20 * sizeof(char));
    printf("Nome: ");
    scanf(" %[^\n]s", &dados->nome);
    dados->nome = (char *)malloc(20 * sizeof(char));
    printf("CNH: ");
    scanf(" %[^\n]s", &dados->cnh);
    dados->nome = (char *)malloc(20 * sizeof(char));
    printf("Número de Telefone: ");
    scanf(" %[^\n]s", &dados->numero);
}

void imprimir_clientes(lista_cliente *lista_cli)
{
    lista_cliente *cliente;
    int i;
    for (cliente = lista_cli, i = 1; cliente != NULL; cliente = cliente->prox, i++)
    {
        printf("Cliente %d:\n", i);
        printf("\tNome: %s\n\tCNH: %s\n\tNúmero de Telefone: %s\n\tano de fabricacao: %s\n", cliente->dados->nome, cliente->dados->cnh, cliente->dados->numero);
    }
}
