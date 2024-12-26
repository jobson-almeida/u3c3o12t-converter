#ifndef CONVERTER_H
#define CONVERTER_H

// TEMPERATURA ////////////////////////////////////////////
/// @brief Função que converte de celsius para fahrenheit
/// @param celsius Valor da temperatura em celsius
/// @return Valor em fahrenheit
float celsius_para_fahrenheit(float celsius); 

/// @brief Função que converte de celsius para kelvin
/// @param celsius Valor da temperatura em celsius
/// @return Valor em kelvin  
float celsius_para_kelvin(float celsius);
 
/// @brief Função que converte de fahrenheit para kelvin
/// @param fahrenheit Valor da temperatura em fahrenheit
/// @return Valor em kelvin
float fahrenheit_para_kelvin(float fahrenheit);

/// @brief Função que converte de fahrenheit para celsius
/// @param fahrenheit Valor da temperatura em fahrenheit
/// @return Valor em celsius 
float fahrenheit_para_celsius(float fahrenheit);

/// @brief Função que converte de kelvin para celsius
/// @param kelvin Valor da temperatura em kelvin
/// @return Valor em celsius 
float kelvin_para_celsius(float kelvin);
 
/// @brief Função que converte de kelvin para fahrenheit
/// @param kelvin Valor da temperatura em kelvin
/// @return Valor em fahrenheit
float kelvin_para_fahrenheit(float kelvin);

#endif