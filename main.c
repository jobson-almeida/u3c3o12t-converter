#include <stdio.h>
#include <locale.h>

void unidade_simples(float value);
void unidade_com_submenu_comprimento();
void unidade_com_submenu_massa();
void unidade_com_submenu_temperatura();
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
            unidade_com_submenu_massa();
            break;
        case 4:
            unidade_com_submenu_temperatura();
            break;
        case 5:
            break;
        case 6:
            unidade_com_submenu_potencia();
            break;
        case 9:
            break;
        default:
            // ESTE BLOCO DE CÓDIGO SERVE DE MODELO
            // printf("digite um valor: ");
            // if (scanf("%f", &option) == 0)
            // {
            //     float opt;
            //     // remove a entrada inválida do buffer de entrada
            //     while ((opt = getchar()) != '\n' && opt != EOF);
            //     printf("valor inválido!\n");
            //     break;
            // }
            // printf("faça a conversão\n");
            printf("opção não encontrada!\n");
            break;
        }
    }

    return 0;
}

/*ESTE BLOCO DE CÓDIGO SERVE DE MODELO PARA TODAS AS CONVERSÕES

void unidade_nomeDaSuaGrandeza(float value)
{
    printf("faça a conversão função\n");
}

    void unidade_com_submenu_nomeDaSuaGrandeza()
    {
        int option = -1;
        float value = 0.0;

        while (option != 0)
        {
            printf("\n");
            printf(":::: Grandeza ::::::::::::::::::::::::::::::::::::::\n");
            printf("::                                                ::\n");
            printf(":: 1. Exemplo 1                                   ::\n");
            printf(":: 2. Exemplo 2                                   ::\n");
            printf(":: 3. Exemplo 3                                   ::\n");
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
*/

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

//  -----------------------------CONVERSÃO DE TEMPERATURA----------------------------------

//Este bloco realiza a conversão de temperatura para Celsius, Fahrenheit, Kelvin ou outras escalas desejadas

//Declaração das funções que fazem a conversão entre as unidades de temperatura Celsius, Fahrenheit e Kelvin
float celsius_para_fahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

float celsius_para_kelvin(float celsius) {
    return (celsius + 273.15);
}

float fahrenheit_para_kelvin(float fahrenheit) {
    return ((fahrenheit - 32) * 5/9 + 273.15);
}

float fahrenheit_para_celsius(float fahrenheit) {
    return ((fahrenheit - 32) * 5/9);
}

float kelvin_para_celsius(float kelvin) {
    return (kelvin - 273.15);
}

float kelvin_para_fahrenheit(float kelvin) {
    return ((kelvin - 273.15) * 9/5 + 32);
}

//Inicialização da função que mostrará o menu e os resultados somente da unidade de temperatura
void unidade_com_submenu_temperatura() {
    
    int option = -1;
    float temperatura, resultado;

    //Esse laço tem a funcionalidade de abrir um menu com as opções de entrada
    while (option != 0) {
        printf("\n::::::: Temperatura ::::::::::::::::::::::::::::::::\n"
               "::                                                ::\n"
               ":: 1. Celsius -> Fahrenheit                       ::\n"
               ":: 2. Celsius -> Kelvin                           ::\n"
               ":: 3. Fahrenheit -> Kelvin                        ::\n"
               ":: 4. Fahrenheit -> Celsius                       ::\n"
               ":: 5. Kelvin -> Celsius                           ::\n"
               ":: 6. Kelvin -> Fahrenheit                        ::\n"
               ":: 0. Sair                                        ::\n"
               "::                                                ::\n"
               ":::::::::::::::::::::::::::::::::::::::::::::::::::: \n\n");

        printf("Digite uma opção: ");

        if (scanf("%d", &option) == 0) {
            int opt;
            // Remover a entrada inválida do buffer de entrada
            while ((opt = getchar()) != '\n' && opt != EOF);
            option = -1;
        } 
        else {
            if (option != 0) {
                printf("\nDigite a temperatura a ser convertida: ");
                if (scanf("%f", &temperatura) == 0) {
                    int opt;
                    while ((opt = getchar()) != '\n' && opt != EOF);
                    continue;
                }

                switch (option) {
                    case 1:
                        resultado = celsius_para_fahrenheit(temperatura);
                        printf("Resultado: %.2f °F\n", resultado);
                        break;
                    case 2:
                        resultado = celsius_para_kelvin(temperatura);
                        printf("Resultado: %.2f K\n", resultado);
                        break;
                    case 3:
                        resultado = fahrenheit_para_kelvin(temperatura);
                        printf("Resultado: %.2f K\n", resultado);
                        break;
                    case 4:
                        resultado = fahrenheit_para_celsius(temperatura);
                        printf("Resultado: %.2f °C\n", resultado);
                        break;
                    case 5:
                        resultado = kelvin_para_celsius(temperatura);
                        printf("Resultado: %.2f °C\n", resultado);
                        break;
                    case 6:
                        resultado = kelvin_para_fahrenheit(temperatura);
                        printf("Resultado: %.2f °F\n", resultado);
                        break;
                    default:
                        printf("Opção não encontrada!\n");
                        break;
                }
            }
        }
    }
}
 
void unidade_com_submenu_massa(){
    int option = -1;
    float value = 0.0;
    
    while (option != 0)
    {
        printf("\n");
        printf(":::: Comprimento :::::::::::::::::::::::::::::::::::\n");
        printf("::                                                ::\n");
        printf(":: 1. tonelada -> quilograma                      ::\n");
        printf(":: 2. tonelada -> grama                           ::\n");
        printf(":: 3. quilograma -> tonelada                      ::\n");
        printf(":: 4. quilograma -> grama                         ::\n");
        printf(":: 5. grama -> quilograma                         ::\n");
        printf(":: 6. grama -> tonelada                           ::\n");
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
            case 1: // Conversão de tonelada para quilograma
                printf("Digite o valor em tonelada: ");
                // Se o scanf falhar ao interpretar a entrada como um número, ele retorna 0
                if (scanf("%f", &value) == 0)
                {
                    // Remove entrada inválida do buffer
                    while (getchar() != '\n');
                    printf("Valor inválido! Tente novamente.\n");
                }
                else
                {
                    float resultado = value * 1000.0; // 1 t = 1000 kg
                    printf("%.2f toneladas equivalem a %.2f quilogramas.\n", value, resultado);
                }
                break;
            case 2: // Conversão de tonelada para grama
                printf("Digite o valor em toneladas: ");
                if (scanf("%f", &value) == 0)
                {
                    while (getchar() != '\n'); // Limpa o buffer
                    printf("Valor inválido! Tente novamente.\n");
                }
                else
                {
                    float resultado = value * 1000000.0; // 1 t = 1kk g
                    printf("%.2f toneladas equivalem a %.2f gramas.\n", value, resultado);
                }
                break;
            case 3: // Conversão de quilograma para tonelada
                printf("Digite o valor em quilogramas: ");
                if (scanf("%f", &value) == 0)
                {
                    while (getchar() != '\n'); // Limpa o buffer
                    printf("Valor inválido! Tente novamente.\n");
                }
                else
                {
                    float resultado = value / 1000.0; // 1 t = 1000 kg
                    printf("%.2f quilogramas equivalem a %.3f toneladas.\n", value, resultado);
                }
                break;
            case 4: // Conversão de quilograma para grama
                printf("Digite o valor em quilogramas: ");
                if (scanf("%f", &value) == 0)
                {
                    while (getchar() != '\n'); // Limpa o buffer
                    printf("Valor inválido! Tente novamente.\n");
                }
                else
                {
                    float resultado = value * 1000.0; // 1 kg = 1000 g
                    printf("%.2f quilogramas equivalem a %.2f gramas.\n", value, resultado);
                }
                break;
            case 5: // Conversão de gramas para quilogramas
                printf("Digite o valor em gramas: ");
                if (scanf("%f", &value) == 0)
                {
                    while (getchar() != '\n'); // Limpa o buffer
                    printf("Valor inválido! Tente novamente.\n");
                }
                else
                {
                    float resultado = value / 1000.0; // 1 kg = 1000 g
                    printf("%.2f gramas equivalem a %.3f quilogramas.\n", value, resultado);
                }
                break;
            case 6: // Conversão de gramas para toneladas
                printf("Digite o valor em gramas: ");
                if (scanf("%f", &value) == 0)
                {
                    while (getchar() != '\n'); // Limpa o buffer
                    printf("Valor inválido! Tente novamente.\n");
                }
                else
                {
                    float resultado = value / 1000000.0; // 1 t = 1kk g
                    printf("%.2f gramas equivalem a %.6f toneladas.\n", value, resultado);
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

 