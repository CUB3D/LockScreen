//
// Created by cub3d on 15/05/2018.
//

#ifndef LOCKSCREEN_BASEWIDGET_H
#define LOCKSCREEN_BASEWIDGET_H

#include "../TTFFont.h"
#include "../UIRenderer.h"

class BaseWidget {
public:
    int x;
    int y;
    std::shared_ptr<TTFFont> font;
    std::shared_ptr<UIRenderer> renderer;

    virtual void draw() = 0;
    virtual bool isDirty() = 0;
};


#endif //LOCKSCREEN_BASEWIDGET_H
