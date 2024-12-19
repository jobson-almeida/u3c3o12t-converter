#include <stdio.h>

void unidade_simples(float value);

int main()
{

    int option = -1;
    float value = 0;

    while (option != 0)
    {
        printf("\n");
        printf("MENU PRINCIPAL\n");
        printf("1. Comprimento (metro, centímetro, milímetro) \n");
        printf("2. Massa (quilograma, grama, tonelada)\n");
        printf("4. Temperatura (Celsius, Fahrenheit, Kelvin)\n");
        printf("5. Velocidade (km/h, m/s, mph)\n");
        printf("6. Potência (Watts (W), quilowatts (kW), cavalos-vapor (cv ou hp))\n");
        printf("9. Dados (Bits, bytes, kilobytes (KB), megabytes (MB), gigabytes (GB), terabytes (TB))\n");
        printf("0. Sair\n");

        printf("digite uma opção: ");
        scanf("%d", &option); 

        switch (option)
        {
        case 1: 
        case 2:
            printf("digite um valor: ");
            scanf(" %f", &value);
            unidade_simples(value);
            break;
        case 4:
        case 5:
        case 6:
        case 9:
            printf("digite um valor: ");
            scanf(" %f", &value);
            printf("faça a conversão\n");
            break;
        default: 
            break;
        }
    }

    return 0;
}


void unidade_simples(float value)
{
    printf("faça a conversão pela função\n");
}