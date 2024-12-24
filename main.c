#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

void unidade_simples(float value);
void unidade_com_submenu();
void unidade_com_submenu_comprimento();
int validar_numero(const char *entrada);
int validar_float(const char *entrada);


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
            if (scanf("%f", &option) == 0)
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
            //unidade_com_submenu_velocidade();
            break;
        case 6:
            unidade_com_submenu_potencia();
            break;
        case 9:
            break;
        case 0:
            wprintf(L"Encerrando...\n");
            break;
        default:
            wprintf(L"Opção não encontrada!\n");
            break;
        }
    }

    return 0;
}

/*ESTE BLOCO DE CÓDIGO SERVE DE MODELO PARA TODAS AS CONVERSÕES
    void unidade_com_submenu_nomeDaSuaGrandeza()
    {
        int option = -1;
        float value = 0.0;

        while (option != 0)
        {
            wprintf(L"\n");
            wprintf(L":::: Grandeza ::::::::::::::::::::::::::::::::::::::\n");
            wprintf(L"::                                                ::\n");
            wprintf(L":: 1. Exemplo 1                                   ::\n");
            wprintf(L":: 2. Exemplo 2                                   ::\n");
            wprintf(L":: 3. Exemplo 3                                   ::\n");
            wprintf(L":: 0. sair                                        ::\n");
            wprintf(L"::                                                ::\n");
            wprintf(L"::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");

            wprintf(L"digite uma opção: ");
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
                    wprintf(L"digite um valor: ");
                    if (scanf("%f", &option) == 0)
                    {
                        float opt;
                        // remove a entrada inválida do buffer de entrada do usuário
                        while ((opt = getchar()) != '\n' && opt != EOF);
                        wprintf(L"valor inválido!\n");
                        break;
                    }
                    wprintf(L"faça a conversão\n");
                    break;
                default:
                    wprintf(L"opção não encontrada!\n");
                    break;
                }
            }
        }
    }
*/

//  -----------------------------UNIDADES DE COMPRIMENTO----------------------------------

void unidade_com_submenu_comprimento()
{
    int option = -1;
    char valor[50]; // Buffer para o valor
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
                wprintf(L"Opção não encontrada!\n");
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
    
    // Primeiro convertemos para Watts como unidade intermediária
    float watts;
    switch(from_unit) {
        case 1: // De Watts
            watts = value;
            break;
        case 2: // De Quilowatts
            watts = value * 1000.0;
            break;
        case 3: // De Cavalos-Vapor
            watts = value * 735.49875;
            break;
        default:
            wprintf(L"Unidade de origem inválida!\n");
            return;
    }
    
    // Depois convertemos de Watts para a unidade de destino
    switch(to_unit) {
        case 1: // Para Watts
            result = watts;
            break;
        case 2: // Para Quilowatts
            result = watts / 1000.0;
            break;
        case 3: // Para Cavalos-Vapor
            result = watts / 735.49875;
            break;
        default:
            wprintf(L"Unidade de destino inválida!\n");
            return;
    }
    
    wprintf(L"Resultado: %.4f %s\n", result, unit_names[to_unit - 1]);
}

// Submenu de potência
void unidade_com_submenu_potencia()
{
    int option = -1;
    float value = 0.0;
    while (option != 0)
    {
        wprintf(L"\n");
        wprintf(L":::: Potência :::::::::::::::::::::::::::::::::::::\n");
        wprintf(L"::                                                ::\n");
        wprintf(L":: 1. Watts (W) -> Quilowatts (kW)               ::\n");
        wprintf(L":: 2. Watts (W) -> Cavalos-Vapor (cv)            ::\n");
        wprintf(L":: 3. Quilowatts (kW) -> Watts (W)               ::\n");
        wprintf(L":: 4. Quilowatts (kW) -> Cavalos-Vapor (cv)      ::\n");
        wprintf(L":: 5. Cavalos-Vapor (cv) -> Watts (W)            ::\n");
        wprintf(L":: 6. Cavalos-Vapor (cv) -> Quilowatts (kW)      ::\n");
        wprintf(L":: 0. Sair                                       ::\n");
        wprintf(L"::                                               ::\n");
        wprintf(L":::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
        wprintf(L"Digite uma opção: ");
        if (scanf("%d", &option) == 0)
        {
            while (getchar() != '\n');
            option = -1;
        }
        if (option > 0 && option <= 6)
        {
            wprintf(L"Digite o valor: ");
            if (scanf("%f", &value) == 0)
            {
                while (getchar() != '\n');
                wprintf(L"Valor inválido! Tente novamente.\n");
                continue;
            }
            
            // Mapeamento correto das opções do menu para as unidades
            int from_unit, to_unit;
            switch(option) {
                case 1: // W -> kW
                    from_unit = 1; to_unit = 2;
                    break;
                case 2: // W -> cv
                    from_unit = 1; to_unit = 3;
                    break;
                case 3: // kW -> W
                    from_unit = 2; to_unit = 1;
                    break;
                case 4: // kW -> cv
                    from_unit = 2; to_unit = 3;
                    break;
                case 5: // cv -> W
                    from_unit = 3; to_unit = 1;
                    break;
                case 6: // cv -> kW
                    from_unit = 3; to_unit = 2;
                    break;
            }
            
            convert_power(value, from_unit, to_unit);
        }
    }
}

 
