#include <iostream>
#include "calcmodel.h"
#include "enum_math_action.h"

using namespace std;

string MathActToStr(MathAction act)
{
    string result = "";

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
}
