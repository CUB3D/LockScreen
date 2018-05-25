//
// Created by cub3d on 19/05/2018.
//

#include "BatteryWidget.h"

void BatteryWidget::draw() {

}

BatteryWidget::BatteryWidget(std::shared_ptr<UIRenderer> render) {
    this->renderer = render;

    this->background = std::make_unique<Image>(this->renderer->windowRenderer, "/home/cub3d/Development/LockScreen/res/img/empty-battery.png");
}
