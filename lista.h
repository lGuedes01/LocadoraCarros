#ifndef LISTA_H
#define LISTA_H

struct lista
{
    int linha;
    int coluna;
    int info;
    struct lista* ant;
    struct lista* prox;
};
typedef struct lista Lista;

struct identidade
{
    int lin;
    int col;
    int** mat;
    Lista* prim;
};
typedef struct identidade Identidade;

Lista* lista_cria();
Lista* lista_insere(Lista* l, int n, int lin, int col);
Lista* lista_insere_nao_nulo(Lista* l, int** mat, int lin, int col);
Lista* ultimo (Lista* l);
void imprimeLista(Lista* l);
Lista* remove_lista(Lista* l, int n);
Lista* busca_elemento_lista(Lista* l, int n);
int busca_coordenada_lista(Lista* l, int lin, int col);
int comprimento (Lista* l);
Lista* lista_retira(Lista* l, int n);
Lista* lista_retira_ant(Lista* l, int n);
float porcentagem(Lista* l, int tamMat);
Lista* procuraElementoForaDaDiagonal(int lin, int col, int** mat);
#endif