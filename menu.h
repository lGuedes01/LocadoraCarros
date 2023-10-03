#ifndef MENU_H
#define MENU_H

#include "veiculos.h"
#include "clientes.h"
#include "locacoes.h"

void imprime_menu();
int pega_opcao();
Date pega_data(char *termo);
void menu(ListaCliente *lista_clientes, ListaVeiculo *lista_veiculos, ListaLocacao *lista_locacoes);
Date pega_mes();

#endif