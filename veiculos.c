#include "veiculos.h"
#include <stdio.h>
#include <stdlib.h>

ListaVeiculo *cria_lista_veic()
{
    return NULL;
}

ListaVeiculo *aloca_veic()
{
    ListaVeiculo *veic;
    veic = (ListaVeiculo *)malloc(sizeof(ListaVeiculo));
    return veic;
}

ListaVeiculo *pega_info_veic(ListaVeiculo *veiculo)
{
    printf("Marca:");
    scanf(" %[^\n]s", veiculo->info.marca);
    printf("Modelo:");
    scanf(" %[^\n]s", veiculo->info.modelo);
    printf("Ano de fabricacao:");
    scanf("%d", &veiculo->info.ano_de_fab);
    printf("Placa:");
    scanf(" %[^\n]s", veiculo->info.placa);
    printf("KMs rodados:");
    scanf("%d", &veiculo->info.km_atual);
    printf("Preco da diaria:");
    scanf("%f", &veiculo->info.preco_diaria);
    veiculo->info.disponivel = true;
    return veiculo;
}

ListaVeiculo *add_veic(ListaVeiculo *list_veic)
{
    printf("-----Adicionando Veiculo-----\n");
    ListaVeiculo *novo_veic;
    novo_veic = aloca_veic();
    novo_veic = pega_info_veic(novo_veic);
    novo_veic->prox = list_veic;
    list_veic = novo_veic;
    return list_veic;
}

void imprime_veiculos(ListaVeiculo *list_veic)
{
    ListaVeiculo *p;
    if (list_veic == NULL)
    {
        printf("Nao existem veiculos cadastrados!\n");
    }
    else
    {
        printf("---------------Imprimindo Veiculos---------------\n");
        int i;
        for (p = list_veic, i = 1; p != NULL; p = p->prox, i++)
        {
            printf("Carro %d:\n", i);
            imprime_veic(p->info);
        }
        printf("------------Fim da Lista de Veiculos-------------\n");
    }
}

void imprime_veic(DadosVeic veic)
{
    printf("\tMarca: %s\n\tModelo: %s\n\tAno de Fabricacao: %d\n\tPlaca: %s\n\tKm atual: %d km\n\tValor da diaria: R$%.2f\n", veic.marca,
           veic.modelo, veic.ano_de_fab, veic.placa, veic.km_atual, veic.preco_diaria);
}

void top3MaisRodados(ListaVeiculo *list_veic)
{

    ListaVeiculo *p;
    int vet[3] = {0, 0, 0};
    ListaVeiculo *vet_veic[3];
    for (int i = 0; i < 3; i++)
        vet_veic[i] = NULL;
    for (p = list_veic; p != NULL; p = p->prox)
    {
        int km = p->info.km_atual;
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
            printf("top %d: Placa: %s; Km: %d\n", i + 1, vet_veic[i]->info.placa, vet[i]);
    }
}