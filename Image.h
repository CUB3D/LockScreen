//
// Created by cub3d on 14/05/2018.
//

#ifndef LOCKSCREEN_IMAGE_H
#define LOCKSCREEN_IMAGE_H

#include <SDL.h>
#include <string>
#include <SDL_image.h>
#include <iostream>
#include "UIRenderer.h"

class Image {
public:
    SDL_Texture* image;
    SDL_Rect size;
    bool init = false;
    std::string path;

    Image(const std::string &path);

    void draw(std::shared_ptr<UIRenderer> renderer, const int x, const int y, const double angle);

    ~Image();
};


#endif //LOCKSCREEN_IMAGE_H
