//
// Created by cub3d on 14/05/2018.
//

#ifndef LOCKSCREEN_IMAGE_H
#define LOCKSCREEN_IMAGE_H

#include <SDL.h>
#include <string>
#include <SDL_image.h>
#include <iostream>

class Image {
public:
    SDL_Texture* image;
    SDL_Renderer* windowRenderer;
    SDL_Rect size;

    Image(SDL_Renderer* render, const std::string& path);

    void draw(const int x, const int y, const double angle);

    ~Image();
};


#endif //LOCKSCREEN_IMAGE_H
