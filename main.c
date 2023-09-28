#include <stdio.h>
#include <stdlib.h>

#include "clientes.h"
#include "veiculos.h"
#include "locacoes.h"
#include "menu.h"

int main()
{
    ListaCliente *lista_cl = cria_lista_clientes();
    ListaVeiculo *lista_veic = cria_lista_veic();
    ListaLocacao *lista_loc = cria_lista_locacao();
    menu(lista_cl, lista_veic, lista_loc);
    //finaliza_programa();

    return 0;
}