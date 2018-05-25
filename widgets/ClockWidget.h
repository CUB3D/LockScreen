//
// Created by cub3d on 15/05/2018.
//

#ifndef LOCKSCREEN_CLOCKWIDGET_H
#define LOCKSCREEN_CLOCKWIDGET_H

#include "BaseWidget.h"
#include <ctime>

class ClockWidget : public BaseWidget {
public:
    struct tm* timeInstance;
    int lastSecond = 0;

    ClockWidget();

    void draw() override;
    bool isDirty() override;
};


#endif //LOCKSCREEN_CLOCKWIDGET_H
