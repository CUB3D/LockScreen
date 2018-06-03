//
// Created by cub3d on 03/06/2018.
//

#ifndef LOCKSCREEN_STATICIMAGEWIDGET_H
#define LOCKSCREEN_STATICIMAGEWIDGET_H


#include "BaseWidget.h"
#include "../Image.h"

class StaticImageWidget : public BaseWidget {
public:
    std::shared_ptr<Image> image;

    StaticImageWidget(const std::string& name);

    bool isDirty() override;
    void draw() override;
};


#endif //LOCKSCREEN_STATICIMAGEWIDGET_H
