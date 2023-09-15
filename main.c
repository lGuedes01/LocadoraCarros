#include <stdio.h>
#include <stdlib.h>
#include "rentalCars.h"


int main()
{
    lista_veiculo* veiculos;
    veiculos = cria_lista_veic();
    for (int i = 0; i < 3; i++)
    {
        veiculos = add_veic(veiculos);
    }
    top3MaisRodados(veiculos);
    // imprime_veic(veiculos);
    system("pause");
    return 0;
}
