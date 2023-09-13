#ifndef RENTALCAR_H
#define RENTALCAR_H

#include <stdbool.h>

typedef struct
{
    veiculo* ant;
    veiculo* prox;
    char* placa;    
    char* marca;
    char* modelo;   
    char* ano_de_fab;   
    int km_atual;
    float preco_diaria;
    bool disponivel;    
}veiculo;


typedef struct 
{
    cliente* ant;
    cliente* prox;
    char* nome;
    char* cnh;
    char* numero;
}cliente;

typedef struct 
{
    cliente* cl;
    veiculo* vc;
}alocacoes;






#endif