#include <stdlib.h>
#include <stdio.h>
#include "lista.h"
#include <Windows.h>


Lista* lista_cria()
{
    return NULL;
}

Lista* ultimo (Lista* l)
{
    Lista* p;
    for (p = l; p->prox != NULL; p = p->prox)
    {}
    return p;
}

Lista* lista_insere(Lista* l, int n, int lin, int col)
{
    Lista* novo;
    novo = (Lista*) malloc(sizeof(Lista));
    novo->ant = NULL;
    novo->prox = NULL;
    novo->info = n;
    novo->linha = lin;
    novo->coluna = col;
    if (l != NULL)
    {
        Lista* p = ultimo(l);
        p->prox = novo;
        novo->ant = p;
        return l;
    }
    else
        return novo;
    
}

Lista* lista_insere_nao_nulo(Lista* l, int** mat, int lin, int col)
{
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (mat[i][j] != 0)
            {
                l = lista_insere(l,mat[i][j],i,j);
            }
            
        }
    }
    return l;
}

void imprimeLista(Lista* l)
{
    for (Lista* p = l;p != NULL ;p = p->prox)
    {
        printf("numero:%d;linha%d;coluna:%d ",p->info, p->linha+1,p->coluna+1);
        printf("\n"); 
    }
}

Lista* busca_elemento_lista(Lista* l, int n)
{
    Lista* p;
    for (p = l; p != NULL; p = p->prox)
    {
        if (p->info == n)
            break;  
    }
    return p;
}

int busca_coordenada_lista(Lista* l, int lin, int col)
{
    Lista* p;
    for (p = l; p != NULL; p = p->prox)
    {
        if (p->linha == lin && p->coluna == col)
            return p->info;  
    }
    return 0;
}

int comprimento (Lista* l)
{
    int comp = 0;
    for (Lista* p = l; p  != NULL; p = p->prox)
    {
        comp++;
    }
    return comp;
}

Lista* lista_retira(Lista* l, int n)
{
    Lista* p = busca_elemento_lista(l,n);
    if (p == NULL)
        return l;
    Lista* ant = p->ant;
    if (ant == NULL)
        l = l->prox;
    else
    {
        Lista* prox = p->prox;
        ant->prox = prox;
        prox->ant = ant;
    }
    
    free(p);
    return l;
}

Lista* lista_retira_ant(Lista* l, int n)
{
    Lista* p = busca_elemento_lista(l,n);
    if (p == NULL || p->ant == NULL)
        return l;
    p = p->ant;
    Lista* ant = p->ant;
    if (ant == NULL)
    {
        l = l->prox;
        l->ant = NULL;
    }
    else
    {
        Lista* prox = p->prox;
        ant->prox = prox;
        prox->ant = ant;
    }
    
    free(p);
    return l;
}

float porcentagem(Lista* l, int tamMat)
{
    int comp = comprimento(l);
    float porcent = ((float)comp/tamMat)*100;
    return porcent;
}

Lista* procuraElementoForaDaDiagonal(int lin, int col, int** mat)
{
    Lista* l;
    l = lista_cria();
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if(i!=j && mat[i][j] != 0)
            {
                l = lista_insere(l,mat[i][j],i,j);
            }
        }
    }
    return l;
    
}

