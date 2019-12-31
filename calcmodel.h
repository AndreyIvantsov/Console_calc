#ifndef CALCMODEL_H
#define CALCMODEL_H

#include <vector>
#include <string>
#include "enum_math_action.h"

using namespace std;

class CalcModel
{
private:
    vector<double> stack;
    double regA;
    double regB;
    double regC;
    double regD;
    double regE;
    double* GetLastInStack();
    double* GetPreLastInStack();
    double* GetItemFromEndOfStsck(unsigned long indexFromEnd);
public:
    CalcModel();
    void Clear();
    void PushOperand(double operand);
    void PushMathAct(MathAction mathAction);
    double PullResult();
};

#endif // CALCMODEL_H
