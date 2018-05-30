//
// Created by cub3d on 15/05/2018.
//

#ifndef LOCKSCREEN_PASSWORDENTRYWIDGET_H
#define LOCKSCREEN_PASSWORDENTRYWIDGET_H


#include "BaseWidget.h"
#include "../Image.h"

class PasswordEntryWidget : public BaseWidget {
public:
    std::unique_ptr<Image> background;
    int lastPasswordLength;

    explicit PasswordEntryWidget(std::shared_ptr<UIRenderer> pRenderer);

    void draw();
    bool isDirty();
};


#endif //LOCKSCREEN_PASSWORDENTRYWIDGET_H
