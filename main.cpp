#include <iostream>
#include "calcmodel.h"
#include "enum_math_action.h"

using namespace std;

<<<<<<< HEAD
int main() // int argc, char const *argv[]
{
    int action = 0;
    std::string actionSign = "";
    std::string result = "";

    ShowMenu();
    action = GetNomberOfAction();
    double a = GetMemberOfOperation("A");
    double b = GetMemberOfOperation("B");
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
=======
string MathActToStr(MathAction act)
{
    string result = "";
>>>>>>> 559c6e7062d1b3f09d8f0267acf8fedcacbe82de

    switch (act) {
    case MathAction::PLUS:
        result = " + ";
        break;
    case MathAction::MINUS:
        result = " - ";
        break;
    case MathAction::MULTIPLICATION:
        result = " * ";
        break;
    case MathAction::DIVISION:
        result = " / ";
        break;
    case MathAction::UNAR_MINUS:
        result = "-(";
        break;
    case MathAction::SQRT:
        result = "sqrt(";
        break;
    case MathAction::SIN:
        result = "sin(";
        break;
    case MathAction::COS:
        result = "cos(";
        break;
//    default:
//        result = "err";
//        break;
    }
    return result;
}

void TestCalc(CalcModel &calc, double a, double b, MathAction act)
{
    calc.PushOperand(a);
    calc.PushOperand(b);

    try
    {
        calc.PushMathAct(act);
        double result = calc.PullResult();
        cout << to_string(a) + MathActToStr(act) + to_string(b) + " = " + to_string(result) + '\n';
    }
    catch (std::runtime_error& e)
    {
        cerr << e.what() << endl;
    }
}

void TestCalc(CalcModel &calc, double a, MathAction act)
{
    calc.PushOperand(a);
    calc.PushMathAct(act);
    double result = calc.PullResult();
    cout << MathActToStr(act) + to_string(a) + ") = " + to_string(result) + '\n';
}

int main()
{
<<<<<<< HEAD
    int nomber = 0;
    std::cout << ">  Введите " + membresName  + " = ";
    std::cin >> nomber;
    return nomber;
=======
    cout << "Calc:" << endl;
    CalcModel calc;

    calc.Clear();
    TestCalc(calc, 123.45, 76.55, MathAction::PLUS);

    calc.Clear();
    TestCalc(calc, 623.45, 23.45, MathAction::MINUS);

    calc.Clear();
    TestCalc(calc, 60.05, MathAction::UNAR_MINUS);

    calc.Clear();
    TestCalc(calc, 623.45, 23.45, MathAction::MULTIPLICATION);

    calc.Clear();
    TestCalc(calc, 30.49, 298.45, MathAction::DIVISION);

    calc.Clear();
    TestCalc(calc, 30.49, 0.0, MathAction::DIVISION);

    calc.Clear();
    TestCalc(calc, 64.00, MathAction::SQRT);

    calc.Clear();
    TestCalc(calc, 3.14 * 60 / 180, MathAction::COS);

    calc.Clear();
    TestCalc(calc, 3.14 * 30 / 180, MathAction::SIN);


    return 0;
>>>>>>> 559c6e7062d1b3f09d8f0267acf8fedcacbe82de
}
