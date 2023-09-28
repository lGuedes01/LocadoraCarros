#ifndef VEICULOS_H
#define VEICULOS_H

#include <stdbool.h>

struct dados_veic
{
    char placa[10];
    char marca[20];
    char modelo[20];
    int ano_de_fab;
    int km_atual;
    float preco_diaria;
    bool disponivel;
};
typedef struct dados_veic DadosVeic;

struct lista_veiculo
{
    struct lista_veiculo *prox;
    DadosVeic info;
};
typedef struct lista_veiculo ListaVeiculo;

ListaVeiculo *cria_lista_veic();
ListaVeiculo *aloca_veic();
ListaVeiculo *pega_info_veic(ListaVeiculo *veiculo);
ListaVeiculo *add_veic(ListaVeiculo *list_veic);
void imprime_veiculos(ListaVeiculo *list_veic);
void imprime_veic(DadosVeic veic);
void top3MaisRodados(ListaVeiculo *list_veic);

#endif