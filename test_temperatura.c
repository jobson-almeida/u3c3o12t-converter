#include "headers/minunit.h"
#include "headers/converter.h"

#define NUM_FAILED_TESTS 4
#define NUM_TESTS 8

float celsius_para_fahrenheit(float celsius);

void test_setup(void)
{
}

void test_teardown(void)
{
}

// teste positivo para converter a temperatura de celsius para fahrenheit
MU_TEST(test_celsius_para_fahrenheit_pass)
{
    mu_assert_float_eq(212.000000, celsius_para_fahrenheit(100));
}

// teste negativo para converter a temperatura de celsius para fahrenheit
MU_TEST(test_celsius_para_fahrenheit_fail)
{
    mu_assert_float_eq(212.000010, celsius_para_fahrenheit(100));
}

// teste positivo para converter a temperatura de celsius para kelvin
MU_TEST(test_celsius_para_kelvin_pass)
{
    mu_assert_float_eq(373.149994, celsius_para_kelvin(100));
}

// teste negativo para converter a temperatura de celsius para kelvin
MU_TEST(test_celsius_para_kelvin_fail)
{
    mu_assert_float_eq(373.189994, celsius_para_kelvin(100));
}

// teste positivo para converter a temperatura de fahrenheit para kelvin
MU_TEST(test_fahrenheit_para_kelvin_pass)
{
    mu_assert_float_eq(310.927765, fahrenheit_para_kelvin(100));
}

// teste negativo para converter a temperatura de fahrenheit para kelvin
MU_TEST(test_fahrenheit_para_kelvin_fail)
{
    mu_assert_float_eq(310.926765, fahrenheit_para_kelvin(100));
}

// teste positivo para converter a temperatura de fahrenheit para celsius
MU_TEST(test_fahrenheit_para_celsius_pass)
{
    mu_assert_float_eq(37.777779, fahrenheit_para_celsius(100));
}

// teste negativo para converter a temperatura de fahrenheit para celsius
MU_TEST(test_fahrenheit_para_celsius_fail)
{
    mu_assert_float_eq(37.777479, fahrenheit_para_celsius(100));
}

MU_TEST_SUITE(test_suite)
{
    MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

    MU_RUN_TEST(test_celsius_para_fahrenheit_pass);
    MU_RUN_TEST(test_celsius_para_fahrenheit_fail);

    MU_RUN_TEST(test_celsius_para_kelvin_pass);
    MU_RUN_TEST(test_celsius_para_kelvin_fail);

    MU_RUN_TEST(test_fahrenheit_para_kelvin_pass);
    MU_RUN_TEST(test_fahrenheit_para_kelvin_fail);

    MU_RUN_TEST(test_fahrenheit_para_celsius_pass);
    MU_RUN_TEST(test_fahrenheit_para_celsius_fail);
}

int main(int argc, char *argv[])
{
    MU_RUN_SUITE(test_suite);
    printf("\n\n");

    double minunit_end_real_timer = mu_timer_real();
    double minunit_end_proc_timer = mu_timer_cpu();

    printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("Number asserts: %d\n", minunit_assert);
    printf("Number failed tests: %d\n", minunit_fail);
    printf("Number successful tests: %d\n\n", minunit_assert - minunit_fail);
    printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");

    printf("\nFinished in %.8f seconds (real) %.8f seconds (proc)\n\n", minunit_end_real_timer - minunit_real_timer, minunit_end_proc_timer - minunit_proc_timer);
    printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n\n");

    if (minunit_assert != NUM_TESTS)
        return 1;
    else if (minunit_fail != NUM_FAILED_TESTS)
        return -1;
    return 0;
}
