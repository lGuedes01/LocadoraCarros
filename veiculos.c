#include "veiculos.h"
#include <stdio.h>
#include <stdlib.h>

lista_veiculo *cria_lista_veic()
{
    return NULL;
}

lista_veiculo *aloca_veic()
{
    lista_veiculo *veic;
    veic = (lista_veiculo *)malloc(sizeof(lista_veiculo));
    return veic;
}

lista_veiculo *pega_info_veic(lista_veiculo *veiculo)
{
    veiculo->veic.marca = (char *)malloc(20 * sizeof(char));
    printf("Marca:");
    scanf(" %[^\n]s", veiculo->veic.marca);
    veiculo->veic.modelo = (char *)malloc(20 * sizeof(char));
    printf("Modelo:");
    scanf(" %[^\n]s", veiculo->veic.modelo);
    veiculo->veic.ano_de_fab = (char *)malloc(20 * sizeof(char));
    printf("Ano de fabricacao:");
    scanf(" %[^\n]s", veiculo->veic.ano_de_fab);
    veiculo->veic.placa = (char *)malloc(20 * sizeof(char));
    printf("Placa:");
    scanf(" %[^\n]s", veiculo->veic.placa);
    printf("KMs rodados:");
    scanf(" %d", &veiculo->veic.km_atual);
    printf("Preco da diaria:");
    scanf(" %f", &veiculo->veic.preco_diaria);
    veiculo->veic.disponivel = true;
    return veiculo;
}

lista_veiculo *add_veic(lista_veiculo *list_veic)
{
    lista_veiculo *novo_veic;
    novo_veic = aloca_veic();
    novo_veic = pega_info_veic(novo_veic);
    novo_veic->ant = NULL;
    novo_veic->prox = list_veic;
    if (list_veic != NULL)
        list_veic->ant = novo_veic;
    return novo_veic;
}

void imprime_veiculos(lista_veiculo *list_veic)
{
    lista_veiculo *p;
    int i;
    for (p = list_veic, i = 1; p != NULL; p = p->prox, i++)
    {
        printf("Carro %d:\n", i);
        imprime_veic(p->veic);
    }
}

void imprime_veic(dadosVeiculo veic)
{
    printf("\tMarca: %s\n\tModelo: %s\n\tAno de Fabricacao: %s\n\tPlaca: %s\n\tKm atual: %d km\n\tValor da diaria: R$%.2f\n", veic.marca,
     veic.modelo, veic.ano_de_fab, veic.placa,veic.km_atual,veic.preco_diaria);
}

void top3MaisRodados(lista_veiculo *list_veic)
{

    lista_veiculo *p;
    int vet[3] = {0, 0, 0};
    lista_veiculo *vet_veic[3];
    for (int i = 0; i < 3; i++)
        vet_veic[i] = NULL;
    for (p = list_veic; p != NULL; p = p->prox)
    {
        int km = p->veic.km_atual;
        for (int i = 0; i < 3; i++)
        {
            if (km >= vet[i])
            {
                if (i != 2)
                {
                    for (int j = 2; j > i; j--)
                    {
                        vet[j] = vet[j - 1];
                        vet_veic[j] = vet_veic[j - 1];
                    }
                } 
                    vet[i] = km;
                    vet_veic[i] = p;
                break;
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (vet_veic[i] != NULL)
            printf("top %d: Placa: %s; Km: %d\n", i + 1, vet_veic[i]->veic.placa, vet[i]);
    }
}