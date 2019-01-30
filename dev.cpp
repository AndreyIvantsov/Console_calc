#include <iostream>
#include "err_const.h"


double division(double a, double b)
{
    double *ptrResult = nullptr;

    try
    {
        if (b == 0.0)
            throw std::runtime_error(ERR_DIVADED_BY_ZERRO);
        *ptrResult = a / b;
    }
    catch (const std::exception &e)
    {
        // cerr - стандартный поток вывода
        // сообщений об ошибках
        std::cerr << e.what() << '\n';
    }

    return *ptrResult;
}
