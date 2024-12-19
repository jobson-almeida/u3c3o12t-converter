#include <stdio.h>

void unidade_simples(float value);
void unidade_com_submenu();

int main()
{

    int option = -1;
    float value = 0;

    while (option != 0)
    {
        printf("\n");
        printf("::::: UNIDADES DE MEDIDAS ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
        printf("::                                                                                          ::\n");
        printf(":: 1. Comprimento (metro, centímetro, milímetro)                                            ::\n");
        printf(":: 2. Massa (quilograma, grama, tonelada)                                                   ::\n");
        printf(":: 4. Temperatura (Celsius, Fahrenheit, Kelvin)                                             ::\n");
        printf(":: 5. Velocidade (km/h, m/s, mph)                                                           ::\n");
        printf(":: 6. Potência (Watts (W), quilowatts (kW), cavalos-vapor (cv ou hp))                       ::\n");
        printf(":: 9. Dados (Bits, bytes, kilobytes (KB), megabytes (MB), gigabytes (GB), terabytes (TB))   ::\n");
        printf(":: 0. Sair                                                                                  ::\n");
        printf("::                                                                                          ::\n");
        printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");

        printf("digite uma opção: "); 
        if (scanf("%d", &option) == 0)
        {
            int opt;
             //remove a entrada inválida do buffer de entrada  
            while ((opt = getchar()) != '\n' && opt != EOF); 
            option = -1;
        }

        switch (option)
        {
        case 1:
        case 2:
            printf("digite um valor: ");
            scanf(" %f", &value);
            unidade_simples(value);
            break;
        case 4:
            unidade_com_submenu();
            break;
        case 5:
        case 6:
        case 9:
            printf("digite um valor: ");
            scanf(" %f", &value);
            printf("faça a conversão\n");
            break;
        default:
            printf("opção não encontrada!\n");
            break;
        }
    }

    return 0;
}

void unidade_simples(float value)
{
    printf("faça a conversão pela função\n");
}

void unidade_com_submenu()
{
    int option = -1;
    float value = 0.0;

    while (option != 0)
    {
        printf("\n");
        printf(":::: Comprimento :::::::::::::::::::::::::::::::::::\n");
        printf("::                                                ::\n");
        printf(":: 1. metro -> centímetro                         ::\n");
        printf(":: 2. centímetro -> metro                         ::\n");
        printf(":: 3. opção 3                                     ::\n");
        printf(":: 0. sair                                        ::\n");
        printf("::                                                ::\n");
        printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");

        printf("digite uma opção: ");
        scanf(" %d", &option);

        if (option != 0)
        {
            switch (option)
            {
            case 1:
            case 2:
            case 3:
                printf("digite um valor: ");
                scanf("%f", &value);
                printf("faça a conversão\n");
                break;
            default:
                printf("opção não encontrada!\n");
                break;
            }
        }
    }
}