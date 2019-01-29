#include <iostream>
#include <string>
#include <cstdlib>
#include "math_func.h"

void ShowMenu();
int GetNomberOfAction();
int GetMemberOfOperation(std::string membresName);

int main(int argc, char const *argv[])
{
    int action = 0;
    std::string actionSign = "";
    std::string result = "";

    ShowMenu();
    action = GetNomberOfAction();
    int a = GetMemberOfOperation("A");
    int b = GetMemberOfOperation("B");
    std::string strA = std::to_string(a);
    std::string strB = std::to_string(b);

    switch (action)
    {
        case 1:
            actionSign = " + ";
            result = std::to_string(add(a, b));
            break;

        case 2:
            actionSign = " - ";
            result = std::to_string(sub(a, b));
            break;

        case 3:
            actionSign = " * ";
            result = std::to_string(mult(a, b));
            break;
        
        case 4:
            actionSign = " / ";
            result = std::to_string(division(a, b));
            break;

        default:
            std::cout << "Ошибка: Недопустимый номер операции!" << std::endl;
            break;
    }

    std::cout << "------------------------" << std::endl;
    std::cout << strA + actionSign + strB + " = " + result << std::endl;

    return 0;
}

void ShowMenu()
{
    system("clear");
    std::cout << "Математические операции:" << std::endl;
    std::cout << "1. Сложение" << std::endl;
    std::cout << "2. Вычитание" << std::endl;
    std::cout << "3. Умножение" << std::endl;
    std::cout << "4. Деление" << std::endl;
    std::cout << "------------------------" << std::endl;
}

int GetNomberOfAction()
{
    int nomber = 0;
    std::cout << ">  Введите номер операции [1-4]: ";
    std::cin >> nomber;
    return nomber;
}

int GetMemberOfOperation(std::string membresName)
{
    int nomber = 0;
    std::cout << ">  Введите " + membresName  + " = ";
    std::cin >> nomber;
    return nomber;
}