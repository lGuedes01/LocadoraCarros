#ifndef RENTALCAR_H
#define RENTALCAR_H

#include <stdbool.h>

struct DadosVeiculo
{
    char* placa;    
    char* marca;
    char* modelo;   
    char* ano_de_fab;   
    int km_atual;
    float preco_diaria;
    bool disponivel;
};
typedef struct DadosVeiculo dadosVeiculo;


struct ListaVeiculo
{
    struct ListaVeiculo* ant;
    struct ListaVeiculo* prox;
    dadosVeiculo veic;    
};
typedef struct ListaVeiculo lista_veiculo;

struct DadosClientes
{
    char* nome;
    char* cnh;
    char* numero;
};
typedef struct DadosClientes dadosClientes;


struct ListaCliente 
{
    struct ListaCliente* ant;
    struct ListaCliente* prox;
    dadosClientes dados;
};
typedef struct ListaCliente lista_cliente;

struct Alocacao 
{
    lista_cliente* cl;
    lista_veiculo* vc;
};
typedef struct Alocacao alocacao;

lista_veiculo* cria_lista_veic();
lista_veiculo* aloca_veic();
lista_veiculo* pega_info_veic(lista_veiculo* veiculo);
lista_veiculo* ultimo (lista_veiculo* list_veic);
lista_veiculo* add_veic(lista_veiculo* list_veic);
void imprime_veic(lista_veiculo* list_veic);

#endif