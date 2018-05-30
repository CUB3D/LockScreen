//
// Created by cub3d on 15/05/2018.
//

#ifndef LOCKSCREEN_UIRENDERER_H
#define LOCKSCREEN_UIRENDERER_H


#include <SDL.h>
//TBH this should be a struct
class UIRenderer {
public:
    SDL_Renderer* windowRenderer;
    SDL_Rect screenSize;

    UIRenderer(SDL_Renderer* renderer, SDL_Rect screenSize);
};


#endif //LOCKSCREEN_UIRENDERER_H
