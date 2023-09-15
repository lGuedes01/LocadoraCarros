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


dadosVeiculo* pega_info_veic(dadosVeiculo* veiculo)
{
    veiculo->placa = (char*)malloc(20*sizeof(char));
    printf("placa:");
    scanf(" %[^\n]s", veiculo->placa);
    veiculo->marca = (char*)malloc(20*sizeof(char));
    printf("marca:");
    scanf(" %[^\n]s", veiculo->marca);
    veiculo->modelo = (char*)malloc(20*sizeof(char));
    printf("modelo:");
    scanf(" %[^\n]s", veiculo->modelo);
    veiculo->ano_de_fab = (char*)malloc(20*sizeof(char));
    printf("ano de fabricacao:");
    scanf(" %[^\n]s", veiculo->ano_de_fab);
    printf("km rodado:");
    scanf("%d", &veiculo->km_atual);
    veiculo->disponivel = true;
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
    dadosVeiculo* dados= (dadosVeiculo*)malloc(sizeof(dadosVeiculo));
    novo_veic = aloca_veic();
    dados = pega_info_veic(dados);
    novo_veic->veic = dados;
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
        printf("\tmarca: %s\n\tmodelo: %s\n\tplaca: %s\n\tano de fabricacao: %s\n", p->veic->marca,p->veic->modelo,p->veic->placa,p->veic->ano_de_fab);
    }
}

void top3MaisRodados(lista_veiculo* list_veic)
{
    
    lista_veiculo* p;
    int i;
    int vet[3] = {0,0,0};
    lista_veiculo* vet_veic[3];
    for (i=1,p = list_veic; p != NULL; p = p->prox,i++)
    {
        int km = p->veic->km_atual;
        for (int j = 0; j < 3; j++)
        {
            if (km > vet[j])
            {
                printf("%d %d %d\n",km, vet[j],j);
                if (j == 2)
                {
                    vet[j] = km;
                    vet_veic[j] = p;
                }
                else
                {
                    for (int k = 2; k > j; k--)
                    {
                        vet[k] = vet[k-1];
                    }
                    vet[j] = km;
                    vet_veic[j] = p;
                }
                break;
            }
            
        }
        
    }
    for (int j = 0; j < 3; j++)
    {
        printf("top %d: placa: %s; km: %d\n",j+1, vet_veic[j]->veic->placa, vet[j]);
    }
    
}

void listarVeicDisp(lista_veiculo* veic)
{
    lista_veiculo* p;
    int i;
    for (p = veic, i=1; p != NULL; p = p->prox, i++)
    {
        if (p->veic->disponivel == true)
        {
            printf("modelo: %s\nplaca: %s\n",p->veic->modelo,p->veic->placa);    
        }
        
        
    }
    
}