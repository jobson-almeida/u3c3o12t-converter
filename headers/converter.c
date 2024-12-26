
 
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