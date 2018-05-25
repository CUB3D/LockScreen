//
// Created by cub3d on 15/05/2018.
//

#include "PasswordEntryWidget.h"
#include "../Image.h"

void PasswordEntryWidget::draw() {
    this->background->draw(this->x - this->background->size.w / 2, this->y + this->background->size.h / 2, 0);
}

bool PasswordEntryWidget::isDirty() {
    return true;
}

PasswordEntryWidget::PasswordEntryWidget(std::shared_ptr<UIRenderer> pRenderer) {
    this->renderer = pRenderer;

    this->background = std::make_unique<Image>(pRenderer->windowRenderer,
                                               "/home/cub3d/Development/LockScreen/res/img/background.png");
}
