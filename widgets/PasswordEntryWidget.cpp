//
// Created by cub3d on 15/05/2018.
//

#include "PasswordEntryWidget.h"
#include "../Image.h"
#include "../main.h"

void PasswordEntryWidget::draw() {
    this->background->draw(this->renderer, this->x - this->background->size.w / 2, this->y + this->background->size.h / 2, 0);
}

bool PasswordEntryWidget::isDirty() {
    if(ss.length() != lastPasswordLength) {
        this->lastPasswordLength = ss.length();
        return true;
    }
    return false;
}

PasswordEntryWidget::PasswordEntryWidget(std::shared_ptr<UIRenderer> pRenderer) {
    this->renderer = pRenderer;

    this->background = std::make_unique<Image>("/home/cub3d/Development/git/LockScreen/res/img/background.png");
}
