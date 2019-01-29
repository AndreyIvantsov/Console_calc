#include <iostream>

double division(int a, int b)
{
    //double *ptrResult = nullptr;
    double *ptrResult = nullptr;

    try
    {
        if (b == 0)
            throw std::runtime_error("Divaded by zerro!");
        double result = double(a) / double(b);
        //int result = a / b;
        ptrResult = &result;
    }
    catch (const std::exception &e)
    {
        // cerr - стандартный поток вывода
        // сообщений об ошибках
        std::cerr << e.what() << '\n';
    }

    return *ptrResult;
}