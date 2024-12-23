#include <stdio.h>
#include <locale.h>
#include <wchar.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h>
#include <ctype.h> 

void unidade_com_submenu_comprimento();
void unidade_com_submenu_massa();
void unidade_com_submenu_temperatura();
void unidade_com_submenu_potencia();
void convert_power(float value, int from_unit, int to_unit);

bool validate_option(char c[2]); 
bool validate_value(char c[17]); 

char option_string[2]; 
char value_string[17]; 

// valida os dados de entrada do menu principal e submenus
bool validate_option(char c[2])
{
    for (int i = 0; i < strlen(c); i++)
    {   
        //invalida o caractere se não for dígito
        if (!isdigit(c[i]))
        {
            return false;
        }
    }
    return true;
}

// valida os valores que serão convertidos
bool validate_value(char c[17])
{ 
    int point = 0;
    for (int i = 0; i < strlen(c); i++)
    {

        //replace o ponto para virgula
        if (ispunct(c[i]))
        {
            c[i] = ',';
            point++;
        }

        //invalida se ocorrência de ponto/virgula for maior que 1
        if (point > 1)
            return false;

        //invalida se hover alguma letra
        if (point == 0 && !isdigit(c[i]))
            return false;

        if (point == 1)
        {  
            //invalida se o ponto/vírgula for o primeiro caractere
            if (i == 0)
                return false;

            // invalida se o valor, pue possui já um ponto, é maior ou igual a 2 dígitos 
            // recebe um caractere não dígito e não ponto/vírgula
            if (i >= 2 && !ispunct(c[i]) && !isdigit(c[i])) 
                return false;
        }
    }
    return true;
}

int main()
{
    //Configurar as definições de localidades do programa de acordo com o ambiente em que o programa será executado
    setlocale(LC_ALL, "");

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
        while ((getchar()) != '\n');  // limpar o buffer
        if (!validate_option(option_string)) // valida a opção digitada, aceita apenas inteiros
        {
            wprintf(L"Opção inválida, digite apenas números\n");
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
    float value = 0.0;
    float resultado = 0.0;

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
        wprintf(L":: 0. sair                                        ::\n");
        wprintf(L"::                                                ::\n");
        wprintf(L"::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");

        wprintf(L"Digite uma opção: ");
    m1: // inicio do saldo submenu
        scanf("%s", option_string);
        while ((getchar()) != '\n'); // limpa o buffer
        if (!validate_option(option_string)) // valida a opção digitada, aceita apenas inteiros
        {
            wprintf(L"Opção inválida, digite apenas números\n");
            goto m1; // salto do submenu
        }
        option = atoi(option_string); // converte a string já validada para float


        if (option != 0)
        {
            switch (option)
            {
            case 1: // Conversão de metro para centímetro
                wprintf(L"Digite o valor em metros: ");
             m1v1:
                scanf("%s", value_string);
                while ((getchar()) != '\n'); // limpa o buffer
                if (!validate_value(value_string)) // valida o valor digitado, aceita ponto ou vígula, inteiro ou float
                {
                    wprintf(L"Valor inválido! Tente novamente.\n");
                    goto m1v1;
                }
                value = atof(value_string); // converte string validada para float

                resultado = value * 100.0; // 1 metro = 100 centímetros
                wprintf(L"%.2f metros equivalem a %.2f centímetros.\n", value, resultado);
                
                break;
            case 2: // Conversão de metro para milímetro
                wprintf(L"Digite o valor em metros: ");
                if (scanf("%f", &value) == 0)
                {
                    while (getchar() != '\n'); // Limpa o buffer
                    wprintf(L"Valor inválido! Tente novamente.\n");
                }
                else
                {
                    float resultado = value * 1000.0; // 1 metro = 1000 milímetros
                    wprintf(L"%.2f metros equivalem a %.2f milímetros.\n", value, resultado);
                }
                break;
            case 3: // Conversão de centímetro para metro
                wprintf(L"Digite o valor em centímetros: ");
                if (scanf("%f", &value) == 0)
                {
                    while (getchar() != '\n'); // Limpa o buffer
                    wprintf(L"Valor inválido! Tente novamente.\n");
                }
                else
                {
                    float resultado = value / 100.0; // 1 metro = 100 centímetros
                    wprintf(L"%.2f centímetros equivalem a %.2f metros.\n", value, resultado);
                }
                break;
            case 4: // Conversão de centímetro para milímetro
                wprintf(L"Digite o valor em centímetros: ");
                if (scanf("%f", &value) == 0)
                {
                    while (getchar() != '\n'); // Limpa o buffer
                    wprintf(L"Valor inválido! Tente novamente.\n");
                }
                else
                {
                    float resultado = value * 10.0; // 1 centímetro = 10 milímetros
                    wprintf(L"%.2f centímetros equivalem a %.2f milímetros.\n", value, resultado);
                }
                break;
            case 5: // Conversão de milímetro para centímetro
                wprintf(L"Digite o valor em milímetros: ");
                if (scanf("%f", &value) == 0)
                {
                    while (getchar() != '\n'); // Limpa o buffer
                    wprintf(L"Valor inválido! Tente novamente.\n");
                }
                else
                {
                    float resultado = value / 10.0; // 1 centímetro = 10 milímetros
                    wprintf(L"%.2f milímetros equivalem a %.2f centímetros.\n", value, resultado);
                }
                break;
            case 6: // Conversão de milímetro para metro
                wprintf(L"Digite o valor em milímetros: ");
                if (scanf("%f", &value) == 0)
                {
                    while (getchar() != '\n'); // Limpa o buffer
                    wprintf(L"Valor inválido! Tente novamente.\n");
                }
                else
                {
                    float resultado = value / 1000.0; // 1 metro = 1000 milímetros
                    wprintf(L"%.2f milímetros equivalem a %.2f metros.\n", value, resultado);
                }
                break;
            default:
                wprintf(L"Opção não encontrada!\n");
                break;
            }
        }
    }
} 

//  -----------------------------CONVERSÃO DE TEMPERATURA----------------------------------

//Este bloco realiza a conversão de temperatura para Celsius, Fahrenheit, Kelvin ou outras escalas desejadas a partir da entrada de um valor pelo usuário

//Declaração das funções do tipo float que contém o cálculo da conversão entre as unidades de temperatura Celsius, Fahrenheit e Kelvin
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
    //Declarando variáveis
    int option = -1;
    float temperatura, resultado;

    //Esse laço tem a funcionalidade de abrir um menu com as opções de entrada
    while (option != 0) {
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
    //A função a seguir exibe a entrada de dados
    m2:
        wprintf(L"Digite uma opção: ");
        scanf("%s", option_string);
        while ((getchar()) != '\n');
        
        //Caso a entrada seja composta por caracteres especiais ou letras, ela volta para a função m2
        if (!validate_option(option_string)){
            wprintf(L"Opção inválida, digite apenas números\n");
            goto m2;
        }

        option = atoi(option_string);
        
        //Aqui compara a entrada para que a mesma seja de 0 a 6 apenas, caso não seja volta para a função m2
        if (option < 0 || option > 6){
            wprintf(L"Opção inválida. Digite números de 0 a 6. \n");
            goto m2;
        }

        //A entrada do valor de temperatura é realizada dentro desse laço, onde também possui ooutro laço while que remove entrada inválida do buffer de entrada
        if (option != 0) {
            wprintf(L"\nDigite a temperatura a ser convertida: ");
            if (scanf("%f", &temperatura) != 1) {
                int opt;
                while ((opt = getchar()) != '\n' && opt != EOF);
                continue;
            }
            
            //Esse switch-case envia para o caso escolhido de 1 a 6 para converter a temperatura e mostrar o resultado ao usuário
            switch (option) {
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
                default:
                    wprintf(L"Opção não encontrada!\n");
                    break;
            }
        }
        //Caso a entrada seja 0, imprime uma mensagem de que o sistema está encerrando
        else{
            wprintf(L"Encerrando...\n");
        }
        
    }
}

//  -----------------------------CONVERSOR DE MASSA----------------------------------
void unidade_com_submenu_massa(){
    int option = -1;
    float value = 0.0;
    
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
            case 1: // Conversão de tonelada para quilograma
                wprintf(L"Digite o valor em tonelada: ");
                // Se o scanf falhar ao interpretar a entrada como um número, ele retorna 0
                if (scanf("%f", &value) == 0)
                {
                    // Remove entrada inválida do buffer
                    while (getchar() != '\n');
                    wprintf(L"Valor inválido! Tente novamente.\n");
                }
                else
                {
                    float resultado = value * 1000.0; // 1 t = 1000 kg
                    wprintf(L"%.2f toneladas equivalem a %.2f quilogramas.\n", value, resultado);
                }
                break;
            case 2: // Conversão de tonelada para grama
                wprintf(L"Digite o valor em toneladas: ");
                if (scanf("%f", &value) == 0)
                {
                    while (getchar() != '\n'); // Limpa o buffer
                    wprintf(L"Valor inválido! Tente novamente.\n");
                }
                else
                {
                    float resultado = value * 1000000.0; // 1 t = 1kk g
                    wprintf(L"%.2f toneladas equivalem a %.2f gramas.\n", value, resultado);
                }
                break;
            case 3: // Conversão de quilograma para tonelada
                wprintf(L"Digite o valor em quilogramas: ");
                if (scanf("%f", &value) == 0)
                {
                    while (getchar() != '\n'); // Limpa o buffer
                    wprintf(L"Valor inválido! Tente novamente.\n");
                }
                else
                {
                    float resultado = value / 1000.0; // 1 t = 1000 kg
                    wprintf(L"%.2f quilogramas equivalem a %.3f toneladas.\n", value, resultado);
                }
                break;
            case 4: // Conversão de quilograma para grama
                wprintf(L"Digite o valor em quilogramas: ");
                if (scanf("%f", &value) == 0)
                {
                    while (getchar() != '\n'); // Limpa o buffer
                    wprintf(L"Valor inválido! Tente novamente.\n");
                }
                else
                {
                    float resultado = value * 1000.0; // 1 kg = 1000 g
                    wprintf(L"%.2f quilogramas equivalem a %.2f gramas.\n", value, resultado);
                }
                break;
            case 5: // Conversão de gramas para quilogramas
                wprintf(L"Digite o valor em gramas: ");
                if (scanf("%f", &value) == 0)
                {
                    while (getchar() != '\n'); // Limpa o buffer
                    wprintf(L"Valor inválido! Tente novamente.\n");
                }
                else
                {
                    float resultado = value / 1000.0; // 1 kg = 1000 g
                    wprintf(L"%.2f gramas equivalem a %.3f quilogramas.\n", value, resultado);
                }
                break;
            case 6: // Conversão de gramas para toneladas
                wprintf(L"Digite o valor em gramas: ");
                if (scanf("%f", &value) == 0)
                {
                    while (getchar() != '\n'); // Limpa o buffer
                    wprintf(L"Valor inválido! Tente novamente.\n");
                }
                else
                {
                    float resultado = value / 1000000.0; // 1 t = 1kk g
                    wprintf(L"%.2f gramas equivalem a %.6f toneladas.\n", value, resultado);
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

 
