#include "rentalCars.h"
#include <stdio.h>
#include <stdlib.h>

lista_veiculo* cria_lista_veic()
{
    return NULL;
}


lista_veiculo* aloca_veic()
{
    lista_veiculo* veic;
    veic = (lista_veiculo*)malloc(sizeof(lista_veiculo));
    return veic;
}


lista_veiculo* pega_info_veic(lista_veiculo* veiculo)
{
    veiculo->veic.placa = (char*)malloc(20*sizeof(char));
    printf("placa:");
    scanf(" %[^\n]s", veiculo->veic.placa);
    veiculo->veic.marca = (char*)malloc(20*sizeof(char));
    printf("marca:");
    scanf(" %[^\n]s", veiculo->veic.marca);
    veiculo->veic.modelo = (char*)malloc(20*sizeof(char));
    printf("modelo:");
    scanf(" %[^\n]s", veiculo->veic.modelo);
    veiculo->veic.ano_de_fab = (char*)malloc(20*sizeof(char));
    printf("ano de fabricacao:");
    scanf(" %[^\n]s", veiculo->veic.ano_de_fab);
    return veiculo;
}


lista_veiculo* ultimo (lista_veiculo* list_veic)
{
    lista_veiculo* p;
    for (p = list_veic; p->prox != NULL; p = p->prox)
    {}
    return p;
}

lista_veiculo* add_veic(lista_veiculo* list_veic)
{
    lista_veiculo* novo_veic;
    novo_veic = aloca_veic();
    novo_veic = pega_info_veic(novo_veic);
    novo_veic->ant = NULL;
    novo_veic->prox = list_veic; 
    if (list_veic != NULL)
        list_veic->ant = novo_veic;
    return novo_veic;
    
}

void imprime_veic(lista_veiculo* list_veic)
{
    lista_veiculo* p;
    int i;
    for (p = list_veic, i=1; p != NULL; p = p->prox, i++)
    {
        printf("Carro %d:\n", i);
        printf("\tmarca: %s\n\tmodelo: %s\n\tplaca: %s\n\tano de fabricacao: %s\n", p->veic.marca,p->veic.modelo,p->veic.placa,p->veic.ano_de_fab);
    }
}