#ifndef CALCCONTROLLER_H
#define CALCCONTROLLER_H

#include <string>
#include "enum_display_mode.h"
#include "enum_number_system.h"

class CalcController
{
private:
    NumberSystem numberSystem;
    DisplayMode displayMode;
public:
    CalcController();
    void SetNumberSystem(NumberSystem numberSystem);
    NumberSystem GetNumberSestem();
    void SetDisplayMode(DisplayMode displayMode);
    DisplayMode GetDisplayMode();

};

#endif // CALCCONTROLLER_H
