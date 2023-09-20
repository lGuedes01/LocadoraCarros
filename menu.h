#ifndef MENU_H
#define MENU_H

void imprime_menu();
int pega_opcao();
Date pega_data(char* termo);
void menu(lista_cliente *lista_clientes, lista_veiculo *lista_veiculos, ListaLocacao *lista_locacoes, Date data_atual);


#endif