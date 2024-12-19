#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

// Constantes de conversão para potência
#define W_TO_KW 0.001
#define W_TO_CV 0.00136
#define W_TO_HP 0.00134102
#define KW_TO_W 1000.0
#define CV_TO_W 735.499
#define HP_TO_W 745.7

// Enumeração para unidades de potência
typedef enum {
    WATTS = 1,
    KILOWATTS,
    CV,
    HP,
    VOLTAR = 0
} UnidadePotencia;

// Estrutura para armazenar os fatores de conversão
typedef struct {
    double fator;
    const char* unidade;
} FatorConversao;

// Funções do sistema de potência
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void exibirMenuPotencia() {
    printf("\n=== Conversao de Potencia ===\n");
    printf("1 - Watts (W)\n");
    printf("2 - Quilowatts (kW)\n");
    printf("3 - Cavalos-vapor (CV)\n");
    printf("4 - Horse Power (HP)\n");
    printf("0 - Voltar\n");
    printf("Escolha uma opcao: ");
}

bool entradaValidaPotencia(int opcao) {
    return (opcao >= 0 && opcao <= 4);
}

int obterOpcaoPotencia(const char* titulo) {
    int opcao;
    do {
        printf("\n=== %s ===\n", titulo);
        exibirMenuPotencia();
        if (scanf("%d", &opcao) != 1) {
            limparBuffer();
            printf("Entrada invalida! Digite um numero.\n");
            continue;
        }
        limparBuffer();
        
        if (!entradaValidaPotencia(opcao)) {
            printf("Opcao invalida! Escolha entre 0 e 4.\n");
        }
    } while (!entradaValidaPotencia(opcao));
    
    return opcao;
}

double obterValorPotencia() {
    double valor;
    bool entradaValida = false;
    
    do {
        printf("Digite o valor a ser convertido: ");
        if (scanf("%lf", &valor) != 1) {
            limparBuffer();
            printf("Entrada invalida! Digite um numero.\n");
            continue;
        }
        limparBuffer();
        
        if (valor < 0) {
            printf("Por favor, digite um valor positivo.\n");
            continue;
        }
        entradaValida = true;
    } while (!entradaValida);
    
    return valor;
}

void converterPotencia(double valor, UnidadePotencia entrada, UnidadePotencia saida) {
    if (entrada == saida) {
        printf("Resultado: %.4f (mesma unidade)\n", valor);
        return;
    }
    
    const FatorConversao paraWatts[] = {
        {1.0, "W"},           // WATTS
        {KW_TO_W, "W"},       // KILOWATTS
        {CV_TO_W, "W"},       // CV
        {HP_TO_W, "W"}        // HP
    };
    
    const FatorConversao deWatts[] = {
        {1.0, "W"},                    // WATTS
        {W_TO_KW, "kW"},              // KILOWATTS
        {W_TO_CV, "CV"},              // CV
        {W_TO_HP, "HP"}               // HP
    };
    
    double valorEmWatts = valor * paraWatts[entrada - 1].fator;
    double resultado = valorEmWatts * deWatts[saida - 1].fator;
    
    printf("\nResultado da conversao:\n");
    printf("%.4f %s = %.4f %s\n", 
           valor, deWatts[entrada - 1].unidade,
           resultado, deWatts[saida - 1].unidade);
}

void submenu_potencia() {
    bool continuar = true;
    while (continuar) {
        UnidadePotencia unidadeEntrada = obterOpcaoPotencia("Unidade de Entrada");
        if (unidadeEntrada == VOLTAR) {
            limparTela();
            return;
        }
        
        double valor = obterValorPotencia();
        
        UnidadePotencia unidadeSaida = obterOpcaoPotencia("Unidade de Saida");
        if (unidadeSaida == VOLTAR) {
            limparTela();
            return;
        }
        
        converterPotencia(valor, unidadeEntrada, unidadeSaida);
        
        char resposta;
        printf("\nDeseja fazer outra conversao de potencia? (S/N): ");
        scanf(" %c", &resposta);
        limparBuffer();
        
        if (resposta != 'S' && resposta != 's') {
            limparTela();
            continuar = false;
        } else {
            limparTela();
        }
    }
}

void unidade_simples(float value) {
    printf("Faca a conversao pela funcao\n");
    printf("\nPressione Enter para continuar...");
    getchar();
    limparTela();
}

void exibirMenuPrincipal() {
    printf("\n");
    printf("::::: UNIDADES DE MEDIDAS :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("::                                                                                        ::\n");
    printf(":: 1. Comprimento (metro, centimetro, milimetro)                                         ::\n");
    printf(":: 2. Massa (quilograma, grama, tonelada)                                                ::\n");
    printf(":: 4. Temperatura (Celsius, Fahrenheit, Kelvin)                                          ::\n");
    printf(":: 5. Velocidade (km/h, m/s, mph)                                                        ::\n");
    printf(":: 6. Potencia (Watts (W), quilowatts (kW), cavalos-vapor (cv ou hp))                   ::\n");
    printf(":: 9. Dados (Bits, bytes, kilobytes (KB), megabytes (MB), gigabytes (GB), terabytes (TB))::\n");
    printf(":: 0. Sair                                                                               ::\n");
    printf("::                                                                                       ::\n");
    printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
}

void unidade_com_submenu() {
    int option = -1;
    float value = 0.0;
    
    while (option != 0) {
        printf("\n");
        printf(":::: Comprimento :::::::::::::::::::::::::::::::::::\n");
        printf("::                                                ::\n");
        printf(":: 1. metro -> centimetro                        ::\n");
        printf(":: 2. centimetro -> metro                        ::\n");
        printf(":: 3. opcao 3                                    ::\n");
        printf(":: 0. sair                                       ::\n");
        printf("::                                               ::\n");
        printf(":::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
        
        printf("Digite uma opcao: ");
        if (scanf("%d", &option) != 1) {
            int opt;
            while ((opt = getchar()) != '\n' && opt != EOF);
            option = -1;
            printf("Opcao invalida!\n");
            continue;
        }
        
        if (option != 0) {
            switch (option) {
                case 1:
                case 2:
                case 3:
                    printf("Digite um valor: ");
                    if (scanf("%f", &value) != 1) {
                        float opt;
                        while ((opt = getchar()) != '\n' && opt != EOF);
                        printf("Valor invalido!\n");
                        break;
                    }
                    printf("Faca a conversao\n");
                    printf("\nPressione Enter para continuar...");
                    limparBuffer();
                    getchar();
                    limparTela();
                    break;
                default:
                    printf("Opcao nao encontrada!\n");
                    printf("\nPressione Enter para continuar...");
                    limparBuffer();
                    getchar();
                    limparTela();
                    break;
            }
        } else {
            limparTela();
        }
    }
}

int main() {
    #ifdef _WIN32
        system("chcp 65001");
    #endif
    
    setlocale(LC_ALL, "pt_BR.UTF-8");
    int option = -1;
    float value = 0;
    
    while (option != 0) {
        exibirMenuPrincipal();
        
        printf("Digite uma opcao: ");
        if (scanf("%d", &option) != 1) {
            limparBuffer();
            printf("Opcao invalida!\n");
            continue;
        }
        limparBuffer();
        
        switch (option) {
            case 1:
            case 2:
                printf("Digite um valor: ");
                if (scanf("%f", &value) != 1) {
                    printf("Valor invalido!\n");
                    limparBuffer();
                    break;
                }
                unidade_simples(value);
                break;
            case 4:
                unidade_com_submenu();
                break;
            case 5:
            case 6:
                limparTela();
                submenu_potencia();
                break;
            case 9:
                printf("Digite um valor: ");
                if (scanf("%f", &value) != 1) {
                    printf("Valor invalido!\n");
                    limparBuffer();
                    break;
                }
                printf("Faca a conversao\n");
                printf("\nPressione Enter para continuar...");
                getchar();
                limparTela();
                break;
            case 0:
                limparTela();
                printf("\nPrograma encerrado. Obrigado!\n");
                break;
            default:
                printf("Opcao nao encontrada!\n");
                printf("\nPressione Enter para continuar...");
                getchar();
                limparTela();
                break;
        }
    }
    
    return 0;
}