//
// Created by cub3d on 19/05/2018.
//

#ifndef LOCKSCREEN_BATTERYWIDGET_H
#define LOCKSCREEN_BATTERYWIDGET_H


#include "BaseWidget.h"
#include "../Image.h"

class BatteryWidget : public BaseWidget {
public:
    std::unique_ptr<Image> background;

    BatteryWidget(std::shared_ptr<UIRenderer> ui);

    void draw() override;
};


#endif //LOCKSCREEN_BATTERYWIDGET_H
