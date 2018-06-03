//
// Created by cub3d on 03/06/2018.
//

#include "StaticImageWidget.h"
#include "../ResourceManager.h"

bool StaticImageWidget::isDirty() {
    return false;
}

void StaticImageWidget::draw() {
    this->image->draw(this->renderer, this->x, this->y, 0);
}

StaticImageWidget::StaticImageWidget(const std::string& name) {
    this->image = GET_IMAGE(name);
}
