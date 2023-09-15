void imprime_menu()
{
    printf("1 - Incluir Veículos \n
            2 - Listar Veículos \n
            3 - Incluir CLientes \n
            4 - Listar Clientes \n
            5 - Realizar Locação \n
            6 - Devolver Veículo \n
            7 - Listar Locações \n
            8 - Locações Ativas \n
            9 - Locações Realizadas Por Um Cliente \n
            10 - Faturamento Mensal da Locadora \n
            11 - Os Três Veículos Mais Rodados \n
            12 - Placa e Modelo dos Veículos não Locados \n");
}

int pega_opcao(int opcao)
{
    printf("Digite a opção que deseja acessar!");
    do
    {
    scanf("%d", &opcao);
    if(opcao < -1 && opcao > 12)
    {
         printf("Digite uma opção válida!");
    }
    } while (opcao < -1 && opcao > 12);
    return opcao;
}

void menu()
{
    int opcao = 0;
    do
    {
       
        
        imprime_menu();
        int opcao = pega_opcao();
        switch (opcao)
        {
        case 1:
            incluir_veiculo();
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        case 7:

            break;
        case 8:

            break;
        case 9:

            break;
        case 10:

            break;
        case 11:

            break;
        case 12:

            break;
        default:
            break;
        }
    } while (opcao != -1);
}