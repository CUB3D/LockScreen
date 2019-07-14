//
// Created by cub3d on 15/05/2018.
//

#include "PasswordEntryWidget.h"
#include "../Image.h"
#include "../main.h"
#include "../ResourceManager.h"

void PasswordEntryWidget::draw() {
    this->background->draw(this->renderer, this->x - this->background->size.w / 2, this->y + this->background->size.h / 2, 0);

    std::shared_ptr<Image> dot = GET_IMAGE("Dot");

    for(int x = 0; x < ss.length(); x++) {
        dot->draw(renderer, this->x - this->background->size.w / 2 + dot->size.w * x + 2,
                  this->y + this->background->size.h / 2 + dot->size.h / 2, 0);
    }
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

    //TODO: use resource manager
    this->background = std::make_unique<Image>("res/img/background.png");
}
