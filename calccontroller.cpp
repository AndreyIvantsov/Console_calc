#include "calccontroller.h"
#include "enum_display_mode.h"

CalcController::CalcController()
{
    SetDisplayMode(DisplayMode::ROWS);
    SetNumberSystem(NumberSystem::DEC);
}

void CalcController::SetNumberSystem(NumberSystem numberSystem)
{
    this->numberSystem = numberSystem;
}

NumberSystem CalcController::GetNumberSestem()
{
    return this->numberSystem;
}

void CalcController::SetDisplayMode(DisplayMode displayMode)
{
    this->displayMode = displayMode;
}

DisplayMode CalcController::GetDisplayMode()
{
    return this->displayMode;
}
