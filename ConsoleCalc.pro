TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    calcmodel.cpp \
    calccontroller.cpp

HEADERS += \
    calcmodel.h \
    calccontroller.h \
    enum_math_action.h \
    enum_number_system.h \
    enum_display_mode.h \
    calc_err_const.h
