#ifndef VEICULOS_H
#define VEICULOS_H

#include <stdbool.h>

struct DadosVeiculo
{
    char *placa;
    char *marca;
    char *modelo;
    char *ano_de_fab;
    int km_atual;
    float preco_diaria;
    bool disponivel;
};
typedef struct DadosVeiculo dadosVeiculo;

struct ListaVeiculo
{
    struct ListaVeiculo *ant;
    struct ListaVeiculo *prox;
    dadosVeiculo veic;
};
typedef struct ListaVeiculo lista_veiculo;

lista_veiculo *cria_lista_veic();
lista_veiculo *aloca_veic();
lista_veiculo *pega_info_veic(lista_veiculo *veiculo);
lista_veiculo *add_veic(lista_veiculo *list_veic);
void imprime_veiculos(lista_veiculo *list_veic);
void imprime_veic(dadosVeiculo veic);
void top3MaisRodados(lista_veiculo *list_veic);

#endif