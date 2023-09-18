#include <stdio.h>

#include "clientes.h"
#include "veiculos.h"
#include "locacoes.h"

int main()
{
    lista_cliente *lista_cl = cria_lista_clientes();
    lista_veiculo *lista_veic = cria_lista_veic();
    ListaLocacao *lista_loc = cria_lista_locacao();
    Date data_atual = pega_data("atual");
    menu(lista_cl, lista_veic, lista_loc, data_atual);
    finaliza_programa();

    return 0;
}