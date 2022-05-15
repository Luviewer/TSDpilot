#include "complex.hpp"
#include <stdio.h>

int test_cpp(void)
{
    complex s1(1, 2);
    complex s2(3, 5);

    complex* ptr = new complex;

    *ptr = s1 + s2;

    printf("(1,2)+(3,5)=(%f,%f)\r\n", ptr->real(), ptr->imag());

    delete ptr;

    return 0;
}

MSH_CMD_EXPORT(test_cpp, test cpp);