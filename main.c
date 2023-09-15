#include <stdio.h>
#include <stdlib.h>
#include "rentalCars.h"


int main()
{
    lista_veiculo* veiculos;
    veiculos = cria_lista_veic();
    veiculos = add_veic(veiculos);
    imprime_veic(veiculos);
    system("pause");
    return 0;
}
