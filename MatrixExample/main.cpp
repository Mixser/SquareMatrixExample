#include <iostream>

#include "Matrix.h"


void work()
{
    SquareMatrix a;
    std::cin >> a;
    std::cout << a;

    SquareMatrix d;
    std::cin >> d;

    SquareMatrix f = a + d;

    SquareMatrix c = 2 * a;
    SquareMatrix b = a * 2;

    std::cout << c << std::endl << b << std::endl << f;
}

int main(int argc, char ** argv)
{
    work();
    return 0;
}