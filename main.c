#include <stdio.h>
#include <locale.h>
#include <wchar.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void unidade_com_submenu_comprimento();
void unidade_com_submenu_massa();
void unidade_com_submenu_velocidade();
void unidade_com_submenu_temperatura();
void unidade_com_submenu_potencia();
void unidade_com_submenu_dados();
void converter_dados(double valor, char unidade);
void convert_power(float value, int from_unit, int to_unit);

int validar_inteiro(const char *entrada);
int validar_float(const char *entrada);

char option_string[2];
char value_string[17];

// Função para validar se a entrada é um número inteiro
int validar_inteiro(const char *entrada)
{
    for (int i = 0; entrada[i] != '\0'; i++)
    {
        if (!isdigit(entrada[i]))
        {
            return 0; // Retorna inválido se não for um dígito
        }
    }
    return 1; // Retorna válido
}

// Função para validar se a entrada é um número float válido
int validar_float(const char *entrada)
{
    int ponto_encontrado = 0; // Para rastrear se já encontramos um ponto decimal
    for (int i = 0; entrada[i] != '\0'; i++)
    {
        if (!isdigit(entrada[i]))
        {
            if (entrada[i] == '.' && !ponto_encontrado)
            {
                ponto_encontrado = 1; // Primeiro ponto decimal é válido
            }
            else
            {
                return 0; // Caracter inválido encontrado
            }
        }
    }
    return 1; // Entrada válida
}

int main()
{
    // Configurar as definições de localidades do programa de acordo com o ambiente em que o programa será executado
    setlocale(LC_ALL, "");

    setlocale(LC_NUMERIC, "C");

    int option = -1;

    while (option != 0)
    {
        wprintf(L"\n");
        wprintf(L"::::: UNIDADES DE MEDIDAS ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
        wprintf(L"::                                                                                          ::\n");
        wprintf(L":: 1. Comprimento (metro, centímetro, milímetro)                                            ::\n");
        wprintf(L":: 2. Massa (quilograma, grama, tonelada)                                                   ::\n");
        wprintf(L":: 4. Temperatura (Celsius, Fahrenheit, Kelvin)                                             ::\n");
        wprintf(L":: 5. Velocidade (km/h, m/s, mph)                                                           ::\n");
        wprintf(L":: 6. Potência (Watts (W), quilowatts (kW), cavalos-vapor (cv ou hp))                       ::\n");
        wprintf(L":: 9. Dados (Bits, bytes, kilobytes (KB), megabytes (MB), gigabytes (GB), terabytes (TB))   ::\n");
        wprintf(L":: 0. Sair                                                                                  ::\n");
        wprintf(L"::                                                                                          ::\n");
        wprintf(L"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");

    m: // início do salto
        wprintf(L"Digite uma opção: ");
        scanf("%s", option_string);
        while ((getchar()) != '\n')
            ;                                // limpar o buffer
        if (!validar_inteiro(option_string)) // valida a opção digitada, aceita apenas inteiros
        {
            wprintf(L"Opção inválida. Digite apenas as opções presentes no menu\n");
            goto m;
        }
        option = atoi(option_string); // converte de string para float

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
            unidade_com_submenu_velocidade();
            break;
        case 6:
            unidade_com_submenu_potencia();
            break;
        case 9:
            unidade_com_submenu_dados();
            break;
        case 0:
            wprintf(L"Encerrando...\n");
            break;
        default:
            wprintf(L"Opção inválida. Digite apenas as opções presentes no menu\n");
            goto m;
            break;
        }
    }

    return 0;
}

void unidade_com_submenu_velocidade()
{
    int option = -1;
    double valor = 0.0;

    while (option != 0)
    {
        wprintf(L"\n:::: Conversor de Velocidade :::::::::::::::::::::::::\n");
        wprintf(L"::                                                ::\n");
        wprintf(L":: 1. km/h -> m/s                                 ::\n");
        wprintf(L":: 2. km/h -> mph                                 ::\n");
        wprintf(L":: 3. mph -> km/h                                 ::\n");
        wprintf(L":: 4. mph -> m/s                                  ::\n");
        wprintf(L":: 5. m/s -> km/h                                 ::\n");
        wprintf(L":: 6. m/s -> mph                                  ::\n");
        wprintf(L":: 0. Sair                                        ::\n");
        wprintf(L"::                                                ::\n");
        wprintf(L"::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");

    m1: // inicio do submenu
        wprintf(L"Digite uma opção: ");
        scanf("%s", option_string);
        while ((getchar()) != '\n')
            ; // limpa o buffer
        if (!validar_inteiro(option_string))
        { // valida a opção digitada, aceita apenas inteiros
            wprintf(L"Opção inválida, digite apenas números\n");
            goto m1; // salto do submenu
        }
        option = atoi(option_string); // converte a string validada para inteiro

        if (option != 0)
        {
            switch (option)
            {
            case 1: // Conversão de km/h para m/s
                wprintf(L"Digite o valor em km/h: ");
            m1v1: // inicio da validação do valor
                scanf("%s", value_string);
                while ((getchar()) != '\n')
                    ; // limpa o buffer
                if (!validar_float(value_string))
                { // valida o valor digitado
                    wprintf(L"Valor inválido! Tente novamente.\n");
                    goto m1v1;
                }
                valor = atof(value_string); // converte a string validada para double

                wprintf(L"%.2f km/h equivalem a %.2f m/s.\n", valor, valor / 3.6);
                break;
            case 2: // Conversão de km/h para mph
                wprintf(L"Digite o valor em km/h: ");
                scanf("%s", value_string);
                while ((getchar()) != '\n')
                    ; // limpa o buffer
                if (!validar_float(value_string))
                { // valida o valor digitado
                    wprintf(L"Valor inválido! Tente novamente.\n");
                    goto m1v1;
                }
                valor = atof(value_string); // converte a string validada para double

                wprintf(L"%.2f km/h equivalem a %.2f mph.\n", valor, valor * 0.621371);
                break;
            case 3: // Conversão de mph para km/h
                wprintf(L"Digite o valor em mph: ");
                scanf("%s", value_string);
                while ((getchar()) != '\n')
                    ; // limpa o buffer
                if (!validar_float(value_string))
                { // valida o valor digitado
                    wprintf(L"Valor inválido! Tente novamente.\n");
                    goto m1v1;
                }
                valor = atof(value_string); // converte a string validada para double

                wprintf(L"%.2f mph equivalem a %.2f km/h.\n", valor, valor / 0.621371);
                break;
            case 4: // Conversão de mph para m/s
                wprintf(L"Digite o valor em mph: ");
                scanf("%s", value_string);
                while ((getchar()) != '\n')
                    ; // limpa o buffer
                if (!validar_float(value_string))
                { // valida o valor digitado
                    wprintf(L"Valor inválido! Tente novamente.\n");
                    goto m1v1;
                }
                valor = atof(value_string); // converte a string validada para double

                wprintf(L"%.2f mph equivalem a %.2f m/s.\n", valor, valor / 2.23694);
                break;
            case 5: // Conversão de m/s para km/h
                wprintf(L"Digite o valor em m/s: ");
                scanf("%s", value_string);
                while ((getchar()) != '\n')
                    ; // limpa o buffer
                if (!validar_float(value_string))
                { // valida o valor digitado
                    wprintf(L"Valor inválido! Tente novamente.\n");
                    goto m1v1;
                }
                valor = atof(value_string); // converte a string validada para double

                wprintf(L"%.2f m/s equivalem a %.2f km/h.\n", valor, valor * 3.6);
                break;
            case 6: // Conversão de m/s para mph
                wprintf(L"Digite o valor em m/s: ");
                scanf("%s", value_string);
                while ((getchar()) != '\n')
                    ; // limpa o buffer
                if (!validar_float(value_string))
                { // valida o valor digitado
                    wprintf(L"Valor inválido! Tente novamente.\n");
                    goto m1v1;
                }
                valor = atof(value_string); // converte a string validada para double

                wprintf(L"%.2f m/s equivalem a %.2f mph.\n", valor, valor * 2.23694);
                break;
            default:
                wprintf(L"Opção não encontrada! Tente novamente.\n");
                break;
            }
        }
    }
}
//  -----------------------------UNIDADES DE COMPRIMENTO----------------------------------

void unidade_com_submenu_comprimento()
{

    setlocale(LC_NUMERIC, "C");

    char entrada[50]; // Buffer para a entrada
    int option = -1;
    char valor[50]; // Buffer para o valor
    float value = 0.0;

    while (option != 0)
    {
        wprintf(L"\n");
        wprintf(L":::: Comprimento :::::::::::::::::::::::::::::::::::\n");
        wprintf(L"::                                                ::\n");
        wprintf(L":: 1. metro -> centímetro                         ::\n");
        wprintf(L":: 2. metro -> milímetro                          ::\n");
        wprintf(L":: 3. centímetro -> metro                         ::\n");
        wprintf(L":: 4. centímetro -> milímetro                     ::\n");
        wprintf(L":: 5. milímetro -> centímetro                     ::\n");
        wprintf(L":: 6. milímetro -> metro                          ::\n");
        wprintf(L":: 0. voltar                                      ::\n");
        wprintf(L"::                                                ::\n");
        wprintf(L"::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");

    m1:
        wprintf(L"digite uma opção: ");
        scanf("%s", entrada);

        if (!validar_inteiro(entrada))
        {
            wprintf(L"Opção inválida! Tente novamente.\n");
            goto m1; // Volta ao início do loop
        }

        option = atoi(entrada); // Converte a entrada para inteiro

        if (option != 0)
        {
            switch (option)
            {
            case 1: // Conversão de metro para centímetro
            m1v1:
                wprintf(L"Digite o valor em metros: ");
                scanf("%s", valor);
                if (!validar_float(valor))
                {
                    wprintf(L"Valor inválido! Tente novamente.\n");
                    goto m1v1;
                }
                value = atof(valor); // Converte string para float
                wprintf(L"%.2f metros equivalem a %.2f centímetros.\n", value, value * 100.0);
                break;
            case 2: // Conversão de metro para milímetro
            m1v2:
                wprintf(L"Digite o valor em metros: ");
                scanf("%s", valor);
                if (!validar_float(valor))
                {
                    wprintf(L"Valor inválido! Tente novamente.\n");
                    goto m1v2;
                }
                value = atof(valor);
                wprintf(L"%.2f metros equivalem a %.2f milímetros.\n", value, value * 1000.0);
                break;
            case 3: // Conversão de centímetro para metro
            m1v3:
                wprintf(L"Digite o valor em centímetros: ");
                scanf("%s", valor);
                if (!validar_float(valor))
                {
                    wprintf(L"Valor inválido! Tente novamente.\n");
                    goto m1v3;
                }
                value = atof(valor);
                wprintf(L"%.2f centímetros equivalem a %.2f metros.\n", value, value / 100.0);
                break;
            case 4: // Conversão de centímetro para milímetro
            m1v4:
                wprintf(L"Digite o valor em centímetros: ");
                scanf("%s", valor);
                if (!validar_float(valor))
                {
                    wprintf(L"Valor inválido! Tente novamente.\n");
                    goto m1v4;
                }
                value = atof(valor);
                wprintf(L"%.2f centímetros equivalem a %.2f milímetros.\n", value, value * 10.0);
                break;
            case 5: // Conversão de milímetro para centímetro
            m1v5:
                wprintf(L"Digite o valor em milímetros: ");
                scanf("%s", valor);
                if (!validar_float(valor))
                {
                    wprintf(L"Valor inválido! Tente novamente.\n");
                    goto m1v5;
                }
                value = atof(valor);
                wprintf(L"%.2f milímetros equivalem a %.2f centímetros.\n", value, value / 10.0);
                break;
            case 6: // Conversão de milímetro para metro
            m1v6:
                wprintf(L"Digite o valor em milímetros: ");
                scanf("%s", valor);
                if (!validar_float(valor))
                {
                    wprintf(L"Valor inválido! Tente novamente.\n");
                    goto m1v6;
                }
                value = atof(valor);
                wprintf(L"%.2f milímetros equivalem a %.2f metros.\n", value, value / 1000.0);
                break;
            default:
                wprintf(L"Opção não encontrada! Tente novamente.\n");
                goto m1;
                break;
            }
        }
    }
}

//  -----------------------------CONVERSÃO DE TEMPERATURA----------------------------------

// Este bloco realiza a conversão de temperatura para Celsius, Fahrenheit, Kelvin ou outras escalas desejadas a partir da entrada de um valor pelo usuário

// Essa função serve para validar a entrada de dados em temperatura para que sejam apenas float
float validate_temperatura(const char *temp_string)
{
    int decimal_count = 0; // Contador de vírgulas

    for (size_t i = 0; i < strlen(temp_string); i++)
    {
        if (!isdigit(temp_string[i]))
        {
            if (temp_string[i] == ',' && decimal_count == 0)
            {
                decimal_count++; // Conta uma vírgula válida
            }
            else
            {
                return 0; // Retorna 0 se algum caractere não for dígito ou vírgula
            }
        }
    }
    return 1; // Retorna 1 se todos os caracteres forem válidos
}

// Declaração das funções do tipo float que contém o cálculo da conversão entre as unidades de temperatura Celsius, Fahrenheit e Kelvin
float celsius_para_fahrenheit(float celsius)
{
    return (celsius * 9 / 5) + 32;
}

float celsius_para_kelvin(float celsius)
{
    return (celsius + 273.15);
}

float fahrenheit_para_kelvin(float fahrenheit)
{
    return ((fahrenheit - 32) * 5 / 9 + 273.15);
}

float fahrenheit_para_celsius(float fahrenheit)
{
    return ((fahrenheit - 32) * 5 / 9);
}

float kelvin_para_celsius(float kelvin)
{
    return (kelvin - 273.15);
}

float kelvin_para_fahrenheit(float kelvin)
{
    return ((kelvin - 273.15) * 9 / 5 + 32);
}

// Inicialização da função que mostrará o menu e os resultados somente da unidade de temperatura
void unidade_com_submenu_temperatura()
{
    // Declarando variáveis
    int option = -1;
    float temperatura, resultado;
    char temp_string[10];

    // Esse laço tem a funcionalidade de abrir um menu com as opções de entrada
    while (option != 0)
    {
        wprintf(L"\n::::::: Temperatura ::::::::::::::::::::::::::::::::\n"
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

    // A função a seguir exibe a entrada de dados
    m4:
        wprintf(L"Digite uma opção: ");
        scanf("%s", option_string);
        while ((getchar()) != '\n')
            ;

        // O laço a seguir serve para impedir a inserção de letras, caracteres especiais ou números maiores que 6, caso ocorra a entrada destes, o laço envia para a função m4
        if (!validar_inteiro(option_string) || atoi(option_string) > 6)
        {
            wprintf(L"Opção inválida. Digite números de 0 a 6. \n");
            goto m4;
        }

        option = atoi(option_string);

        // A entrada do valor de temperatura é realizada dentro desse laço, onde também faz a modificação de identificar apenas a vírgula como separador
        if (option != 0)
        {
            wprintf(L"\nDigite a temperatura a ser convertida (utilize vírgula): ");
            scanf("%s", temp_string);

            if (!validate_temperatura(temp_string))
            {
                wprintf(L"Entrada inválida. Digite apenas números (utilizando vírgula). \n");
                while ((getchar()) != '\n')
                    ;
                continue;
            }

            for (int i = 0; temp_string[i] != '\0'; i++)
            {
                if (temp_string[i] == ',')
                {
                    temp_string[i] = '.';
                }
            }

            temperatura = strtof(temp_string, NULL);

            // Esse switch-case envia para o caso escolhido de 1 a 6 para converter a temperatura e mostrar o resultado ao usuário
            switch (option)
            {
            case 1:
                resultado = celsius_para_fahrenheit(temperatura);
                wprintf(L"Resultado: %.2f °F\n", resultado);
                break;
            case 2:
                resultado = celsius_para_kelvin(temperatura);
                wprintf(L"Resultado: %.2f K\n", resultado);
                break;
            case 3:
                resultado = fahrenheit_para_kelvin(temperatura);
                wprintf(L"Resultado: %.2f K\n", resultado);
                break;
            case 4:
                resultado = fahrenheit_para_celsius(temperatura);
                wprintf(L"Resultado: %.2f °C\n", resultado);
                break;
            case 5:
                resultado = kelvin_para_celsius(temperatura);
                wprintf(L"Resultado: %.2f °C\n", resultado);
                break;
            case 6:
                resultado = kelvin_para_fahrenheit(temperatura);
                wprintf(L"Resultado: %.2f °F\n", resultado);
                break;
            }
        }
        // Caso a entrada seja 0, imprime uma mensagem de que o sistema está encerrando
        else
        {
            wprintf(L"Encerrando...\n");
        }
    }
}

//  -----------------------------CONVERSOR DE MASSA----------------------------------
void unidade_com_submenu_massa()
{
    int option = -1;
    float value = 0.0;
    float resultado = 0.0;

    while (option != 0)
    {
        wprintf(L"\n");
        wprintf(L":::: Massa :::::::::::::::::::::::::::::::::::::::::\n");
        wprintf(L"::                                                ::\n");
        wprintf(L":: 1. tonelada -> quilograma                      ::\n");
        wprintf(L":: 2. tonelada -> grama                           ::\n");
        wprintf(L":: 3. quilograma -> tonelada                      ::\n");
        wprintf(L":: 4. quilograma -> grama                         ::\n");
        wprintf(L":: 5. grama -> quilograma                         ::\n");
        wprintf(L":: 6. grama -> tonelada                           ::\n");
        wprintf(L":: 0. sair                                        ::\n");
        wprintf(L"::                                                ::\n");
        wprintf(L"::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");

    m2:
        wprintf(L"Digite uma opção: ");
        scanf("%s", option_string);
        while ((getchar()) != '\n')
            ;                                                           // limpa o buffer
        if (!validar_inteiro(option_string) || atoi(option_string) > 6) // valida a opção digitada, aceita apenas inteiros presente
        {
            wprintf(L"Opção inválida. Digite números de 0 a 6. \n");
            goto m2;
        }
        option = atoi(option_string); // converte de string para float

        if (option != 0)
        {
            switch (option)
            {
            case 1: // Conversão de tonelada para quilograma
            m2v1:
                wprintf(L"Digite o valor em tonelada: ");
                scanf("%s", value_string);
                while ((getchar()) != '\n')
                    ;                             // limpa o buffer
                if (!validar_float(value_string)) // valida o valor digitado, aceita ponto ou vígula, inteiro ou float
                {
                    wprintf(L"Valor inválido! Tente novamente.\n");
                    goto m2v1;
                }
                value = atof(value_string); // converte de string para float

                resultado = value * 1000.0; // 1 t = 1000 kg
                wprintf(L"%.2f toneladas equivalem a %.2f quilogramas.\n", value, resultado);
                break;
            case 2: // Conversão de tonelada para grama
                wprintf(L"Digite o valor em toneladas: ");
                if (scanf("%f", &value) == 0)
                {
                    while (getchar() != '\n')
                        ; // Limpa o buffer
                    wprintf(L"Valor inválido! Tente novamente.\n");
                }
                else
                {
                    resultado = value * 1000000.0; // 1 t = 1kk g
                    wprintf(L"%.2f toneladas equivalem a %.2f gramas.\n", value, resultado);
                }
                break;
            case 3: // Conversão de quilograma para tonelada
                wprintf(L"Digite o valor em quilogramas: ");
                if (scanf("%f", &value) == 0)
                {
                    while (getchar() != '\n')
                        ; // Limpa o buffer
                    wprintf(L"Valor inválido! Tente novamente.\n");
                }
                else
                {
                    resultado = value / 1000.0; // 1 t = 1000 kg
                    wprintf(L"%.2f quilogramas equivalem a %.3f toneladas.\n", value, resultado);
                }
                break;
            case 4: // Conversão de quilograma para grama
                wprintf(L"Digite o valor em quilogramas: ");
                if (scanf("%f", &value) == 0)
                {
                    while (getchar() != '\n')
                        ; // Limpa o buffer
                    wprintf(L"Valor inválido! Tente novamente.\n");
                }
                else
                {
                    resultado = value * 1000.0; // 1 kg = 1000 g
                    wprintf(L"%.2f quilogramas equivalem a %.2f gramas.\n", value, resultado);
                }
                break;
            case 5: // Conversão de gramas para quilogramas
                wprintf(L"Digite o valor em gramas: ");
                if (scanf("%f", &value) == 0)
                {
                    while (getchar() != '\n')
                        ; // Limpa o buffer
                    wprintf(L"Valor inválido! Tente novamente.\n");
                }
                else
                {
                    resultado = value / 1000.0; // 1 kg = 1000 g
                    wprintf(L"%.2f gramas equivalem a %.3f quilogramas.\n", value, resultado);
                }
                break;
            case 6: // Conversão de gramas para toneladas
                wprintf(L"Digite o valor em gramas: ");
                if (scanf("%f", &value) == 0)
                {
                    while (getchar() != '\n')
                        ; // Limpa o buffer
                    wprintf(L"Valor inválido! Tente novamente.\n");
                }
                else
                {
                    resultado = value / 1000000.0; // 1 t = 1kk g
                    wprintf(L"%.2f gramas equivalem a %.6f toneladas.\n", value, resultado);
                }
                break;
            }
            resultado = 0.0;
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
    switch (from_unit)
    {
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
    switch (to_unit)
    {
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

    m6:
        wprintf(L"Digite uma opção: ");
        scanf("%s", option_string);
        while ((getchar()) != '\n')
            ;

        // As unicas opções aceitas são os números representados no menu, caso contrário volta ao rótulo m4
        if (!validar_inteiro(option_string) || atoi(option_string) > 6)
        {
            wprintf(L"Opção inválida. Digite números de 0 a 6. \n");
            goto m6;
        }

        option = atoi(option_string);

        if (option > 0)
        {

        v6:
            wprintf(L"Digite o valor: ");
            scanf("%s", value_string);
            while ((getchar()) != '\n')
                ;                             // limpa o buffer
            if (!validar_float(value_string)) // valida o valor digitado, aceita ponto ou vígula, inteiro ou float
            {
                wprintf(L"Valor inválido! Tente novamente.\n");
                goto v6;
            }
            value = atof(value_string); // converte de string para float

            // Mapeamento correto das opções do menu para as unidades
            int from_unit, to_unit;
            switch (option)
            {
            case 1: // W -> kW
                from_unit = 1;
                to_unit = 2;
                break;
            case 2: // W -> cv
                from_unit = 1;
                to_unit = 3;
                break;
            case 3: // kW -> W
                from_unit = 2;
                to_unit = 1;
                break;
            case 4: // kW -> cv
                from_unit = 2;
                to_unit = 3;
                break;
            case 5: // cv -> W
                from_unit = 3;
                to_unit = 1;
                break;
            case 6: // cv -> kW
                from_unit = 3;
                to_unit = 2;
                break;
            }

            convert_power(value, from_unit, to_unit);
        }
    }
}

void unidade_com_submenu_dados()
{

    double valor;
    int opcao = -1;

    while (opcao != 0)
    {
        wprintf(L"\n");
        wprintf(L":::: Dados (tabela de Bytes) ::::::::\n");
        wprintf(L"::                                 ::\n");
        wprintf(L":: 1 - Bits                        ::\n");
        wprintf(L":: 2 - Bytes                       ::\n");
        wprintf(L":: 3 - Kilobytes (KB)              ::\n");
        wprintf(L":: 4 - Megabytes (MB)              ::\n");
        wprintf(L":: 5 - Gigabytes (GB)              ::\n");
        wprintf(L":: 6 - Terabytes (TB)              ::\n");
        wprintf(L":: 0 - Voltar                      ::\n");
        wprintf(L"::                                 ::\n");
        wprintf(L":::::::::::::::::::::::::::::::::::::\n");
        wprintf(L"\n");

    m9:
        wprintf(L"Escolha a unidade: ");
        scanf("%s", option_string);
        while ((getchar()) != '\n');

        // valida a opção digita como um inteiro de 0 a 6
        if (!validar_inteiro(option_string) || atoi(option_string) > 6)
        {
            wprintf(L"Opção inválida. Digite números de 0 a 6. \n");
            goto m9;
        }

        opcao = atoi(option_string);

        if (opcao != 0)
        {
        v9:
            wprintf(L"Digite um valor em byte: ");
            scanf("%s", value_string);
            while ((getchar()) != '\n') ;   // limpa o buffer
            if (!validar_float(value_string)) // valida o valor digitado, aceita ponto ou vígula, inteiro ou float
            {
                wprintf(L"Valor inválido! Tente novamente.\n");
                goto v9;
            }
            valor = strtod(value_string, NULL); // converte de string para float
            wprintf(L"%lf", valor);

            switch (opcao)
            { 
            case 1:
                wprintf(L"%.2lf bits\n", valor * 8);
                break;                
            case 2:
                wprintf(L"%.2lf bytes\n", valor);
                break;
            case 3:
                wprintf(L"%.2lf Kb\n", valor * 0.001);
                break;
            case 4:
                wprintf(L"%.2lf MB\n", valor * 0.000001);
                break;
            case 5:
                wprintf(L"%.2lf bytes\n", valor * 1e-9);
                break;
            case 6:
                wprintf(L"%.2lf TB\n", valor * 1e-12);
                break;
            }
        }
    }
