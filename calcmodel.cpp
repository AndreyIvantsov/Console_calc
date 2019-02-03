#include "calcmodel.h"
#include <iostream>
#include <cmath>
#include "calc_err_const.h"


CalcModel::CalcModel()
{

}

double* CalcModel::GetItemFromEndOfStsck(unsigned long indexFromEnd)
{
    unsigned long indexFronStart = stack.size() - indexFromEnd - 1;

    if (indexFronStart < 0.0)
        throw std::runtime_error(CALC_ERR_STACK_OUT_OFF_RANGE);
    else
        return &stack[indexFronStart];;
}

double* CalcModel::GetLastInStack()
{
    return  GetItemFromEndOfStsck(0);
}

double* CalcModel::GetPreLastInStack()
{
    return  GetItemFromEndOfStsck(1);
}

void CalcModel::Clear()
{
    stack.clear();
}

void CalcModel::PushOperand(double operand)
{
    stack.push_back(operand);
}

void CalcModel::PushMathAct(MathAction mathAction)
{
    double *ptrA;
    double *ptrB;
    double r;

    switch (mathAction) {

        case MathAction::PLUS:
            ptrA = GetPreLastInStack();
            ptrB = GetLastInStack();
            r = *ptrA + *ptrB;
            *ptrA = r;
            stack.pop_back();
        break;

        case MathAction::MINUS:
            ptrA = GetPreLastInStack();
            ptrB = GetLastInStack();
            r = *ptrA - *ptrB;
            *ptrA = r;
            stack.pop_back();
        break;

        case MathAction::UNAR_MINUS:
            ptrA = GetLastInStack();
            r = -*ptrA;
            *ptrA = r;
        break;

        case MathAction::MULTIPLICATION:
        ptrA = GetPreLastInStack();
        ptrB = GetLastInStack();
            r = *ptrA * *ptrB;
            *ptrA = r;
            stack.pop_back();
        break;

        case MathAction::DIVISION:
        ptrA = GetPreLastInStack();
        ptrB = GetLastInStack();
        if (*ptrB == 0.0)
            throw std::runtime_error(CALC_ERR_DIVISIOM_BY_ZERRO);
        else
        {
            r = *ptrA / *ptrB;
            *ptrA = r;
            stack.pop_back();
        }

        break;

        case MathAction::SQRT:
            ptrA = GetLastInStack();
            r = std::sqrt(*ptrA);
            *ptrA = r;
        break;

        case MathAction::COS:
            ptrA = GetLastInStack();
            r = std::cos(*ptrA);
            *ptrA = r;
        break;

        case MathAction::SIN:
            ptrA = GetLastInStack();
            r = std::sin(*ptrA);
            *ptrA = r;
        break;
    }
}

double CalcModel::PullResult()
{
    return stack[0];
}
