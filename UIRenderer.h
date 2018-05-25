//
// Created by cub3d on 15/05/2018.
//

#ifndef LOCKSCREEN_UIRENDERER_H
#define LOCKSCREEN_UIRENDERER_H


#include <SDL.h>

class UIRenderer {
public:
    SDL_Renderer* windowRenderer;
    SDL_Rect screenSize;

    void drawRoundedRect(int x, int y, int width, int height, int radius, SDL_Color color);
};


#endif //LOCKSCREEN_UIRENDERER_H
