
/// @brief Função que converte de celsius para fahrenheit
/// @param celsius Valor da temperatura em celsius
/// @return Valor em fahrenheit 
float celsius_para_fahrenheit(float celsius)
{
    return (celsius * 9 / 5) + 32;
}

/// @brief Função que converte de celsius para kelvin
/// @param celsius Valor da temperatura em celsius
/// @return Valor em kelvin
float celsius_para_kelvin(float celsius)
{
    return (celsius + 273.15);
}

/// @brief Função que converte de fahrenheit para kelvin
/// @param fahrenheit Valor da temperatura em fahrenheit
/// @return Valor em kelvin
float fahrenheit_para_kelvin(float fahrenheit)
{
    return ((fahrenheit - 32) * 5 / 9 + 273.15);
}

/// @brief Função que converte de fahrenheit para celsius
/// @param fahrenheit Valor da temperatura em fahrenheit
/// @return Valor em celsius 
float fahrenheit_para_celsius(float fahrenheit)
{
    return ((fahrenheit - 32) * 5 / 9);
}
 
/// @brief Função que converte de kelvin para celsius
/// @param kelvin Valor da temperatura em kelvin
/// @return Valor em celsius
float kelvin_para_celsius(float kelvin)
{
    return (kelvin - 273.15);
}

/// @brief Função que converte de kelvin para fahrenheit
/// @param kelvin Valor da temperatura em kelvin
/// @return Valor em fahrenheit 
float kelvin_para_fahrenheit(float kelvin)
{
    return ((kelvin - 273.15) * 9 / 5 + 32);
}