#include <stdio.h>
#include <locale.h>

void unidade_simples(float value);
void unidade_com_submenu();
void unidade_com_submenu_comprimento();
void unidade_com_submenu_potencia();
void convert_power(float value, int from_unit, int to_unit);

int main()
{
    // definir o UTF
    setlocale(LC_ALL, "pt_BR.UTF-8");

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
            // remove a entrada inválida do buffer de entrada
            while ((opt = getchar()) != '\n' && opt != EOF);
            option = -1;
        }

        switch (option)
        {
        case 1:
            unidade_com_submenu_comprimento();
            break;
        case 2:
            printf("digite um valor: ");
            if (scanf("%f", &value) == 0)
            {
                float opt;
                // remove a entrada inválida do buffer de entrada
                while ((opt = getchar()) != '\n' && opt != EOF);
                printf("valor inválido!\n");
                break;
            }
            unidade_simples(value);
            break;
        case 4:
            unidade_com_submenu();
            break;
        case 5:
            break;
        case 6:
            unidade_com_submenu_potencia();
            break;
        case 9:
    printf("digite um valor: ");
    float option;  // Declare option como float
    if (scanf("%f", &option) == 0)
    {
        int opt;  // Esta variável pode continuar como int pois é só para limpar o buffer
        // remove a entrada inválida do buffer de entrada
        while ((opt = getchar()) != '\n' && opt != EOF);
        printf("valor inválido!\n");
        break;
    }
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
        if (scanf("%d", &option) == 0)
        {
            int opt;
            // remove a entrada inválida do buffer de entrada
            while ((opt = getchar()) != '\n' && opt != EOF);
            option = -1;
        }

        if (option != 0)
        {
            switch (option)
            {
            case 1:
            case 2:
            case 3:
                printf("digite um valor: ");
                if (scanf("%f", &option) == 0)
                {
                    float opt;
                    // remove a entrada inválida do buffer de entrada do usuário
                    while ((opt = getchar()) != '\n' && opt != EOF);
                    printf("valor inválido!\n");
                    break;
                }
                printf("faça a conversão\n");
                break;
            default:
                printf("opção não encontrada!\n");
                break;
            }
        }
    }
}

//  -----------------------------UNIDADES DE COMPRIMENTO----------------------------------

void unidade_com_submenu_comprimento()
{
    int option = -1;
    float value = 0.0;

    while (option != 0)
    {
        printf("\n");
        printf(":::: Comprimento :::::::::::::::::::::::::::::::::::\n");
        printf("::                                                ::\n");
        printf(":: 1. metro -> centímetro                         ::\n");
        printf(":: 2. metro -> milímetro                          ::\n");
        printf(":: 3. centímetro -> metro                         ::\n");
        printf(":: 4. centímetro -> milímetro                     ::\n");
        printf(":: 5. milímetro -> centímetro                     ::\n");
        printf(":: 6. milímetro -> metro                          ::\n");
        printf(":: 0. sair                                        ::\n");
        printf("::                                                ::\n");
        printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");

        printf("digite uma opção: ");
        if (scanf("%d", &option) == 0)
        {
            int opt;
            // remove a entrada inválida do buffer de entrada
            while ((opt = getchar()) != '\n' && opt != EOF);
            option = -1;
        }

        if (option != 0)
        {
            switch (option)
            {
            case 1: // Conversão de metro para centímetro
                printf("Digite o valor em metros: ");
                // Se o scanf falhar ao interpretar a entrada como um número, ele retorna 0
                if (scanf("%f", &value) == 0)
                {
                    // Remove entrada inválida do buffer
                    while (getchar() != '\n');
                    printf("Valor inválido! Tente novamente.\n");
                }
                else
                {
                    float resultado = value * 100.0; // 1 metro = 100 centímetros
                    printf("%.2f metros equivalem a %.2f centímetros.\n", value, resultado);
                }
                break;
            case 2: // Conversão de metro para milímetro
                printf("Digite o valor em metros: ");
                if (scanf("%f", &value) == 0)
                {
                    while (getchar() != '\n'); // Limpa o buffer
                    printf("Valor inválido! Tente novamente.\n");
                }
                else
                {
                    float resultado = value * 1000.0; // 1 metro = 1000 milímetros
                    printf("%.2f metros equivalem a %.2f milímetros.\n", value, resultado);
                }
                break;
            case 3: // Conversão de centímetro para metro
                printf("Digite o valor em centímetros: ");
                if (scanf("%f", &value) == 0)
                {
                    while (getchar() != '\n'); // Limpa o buffer
                    printf("Valor inválido! Tente novamente.\n");
                }
                else
                {
                    float resultado = value / 100.0; // 1 metro = 100 centímetros
                    printf("%.2f centímetros equivalem a %.2f metros.\n", value, resultado);
                }
                break;
            case 4: // Conversão de centímetro para milímetro
                printf("Digite o valor em centímetros: ");
                if (scanf("%f", &value) == 0)
                {
                    while (getchar() != '\n'); // Limpa o buffer
                    printf("Valor inválido! Tente novamente.\n");
                }
                else
                {
                    float resultado = value * 10.0; // 1 centímetro = 10 milímetros
                    printf("%.2f centímetros equivalem a %.2f milímetros.\n", value, resultado);
                }
                break;
            case 5: // Conversão de milímetro para centímetro
                printf("Digite o valor em milímetros: ");
                if (scanf("%f", &value) == 0)
                {
                    while (getchar() != '\n'); // Limpa o buffer
                    printf("Valor inválido! Tente novamente.\n");
                }
                else
                {
                    float resultado = value / 10.0; // 1 centímetro = 10 milímetros
                    printf("%.2f milímetros equivalem a %.2f centímetros.\n", value, resultado);
                }
                break;
            case 6: // Conversão de milímetro para metro
                printf("Digite o valor em milímetros: ");
                if (scanf("%f", &value) == 0)
                {
                    while (getchar() != '\n'); // Limpa o buffer
                    printf("Valor inválido! Tente novamente.\n");
                }
                else
                {
                    float resultado = value / 1000.0; // 1 metro = 1000 milímetros
                    printf("%.2f milímetros equivalem a %.2f metros.\n", value, resultado);
                }
                break;
            default:
                printf("Opção não encontrada!\n");
                break;
            }
        }
    }
}

//  -----------------------------UNIDADES DE POTENCIA----------------------------------

// Conversão de potência
void convert_power(float value, int from_unit, int to_unit)
{
    float result;
    const char *unit_names[] = {"Watts (W)", "Quilowatts (kW)", "Cavalos-Vapor (cv)"};

    if (from_unit == 1) // Watts (W)
        result = (to_unit == 2) ? value / 1000.0 : value / 735.49875;
    else if (from_unit == 2) // Quilowatts (kW)
        result = (to_unit == 1) ? value * 1000.0 : value * 1000.0 / 735.49875;
    else // Cavalos-Vapor (cv)
        result = (to_unit == 1) ? value * 735.49875 : value * 735.49875 / 1000.0;

    printf("Resultado: %.4f %s\n", result, unit_names[to_unit - 1]);
}

// Submenu de potência
void unidade_com_submenu_potencia()
{
    int option = -1;
    float value = 0.0;

    while (option != 0)
    {
        printf("\n");
        printf(":::: Potência :::::::::::::::::::::::::::::::::::::\n");
        printf("::                                                ::\n");
        printf(":: 1. Watts (W) -> Quilowatts (kW)                ::\n");
        printf(":: 2. Watts (W) -> Cavalos-Vapor (cv)             ::\n");
        printf(":: 3. Quilowatts (kW) -> Watts (W)                ::\n");
        printf(":: 4. Quilowatts (kW) -> Cavalos-Vapor (cv)       ::\n");
        printf(":: 5. Cavalos-Vapor (cv) -> Watts (W)             ::\n");
        printf(":: 6. Cavalos-Vapor (cv) -> Quilowatts (kW)       ::\n");
        printf(":: 0. Sair                                        ::\n");
        printf("::                                                ::\n");
        printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");

        printf("Digite uma opção: ");
        if (scanf("%d", &option) == 0)
        {
            while (getchar() != '\n');
            option = -1;
        }

        if (option != 0)
        {
            printf("Digite o valor: ");
            if (scanf("%f", &value) == 0)
            {
                while (getchar() != '\n');
                printf("Valor inválido! Tente novamente.\n");
                continue;
            }

            convert_power(value, option / 2 + 1, option % 2 + 1);
        }
    }
}