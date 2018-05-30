//
// Created by cub3d on 11/05/2018.
//

#ifndef LOCKSCREEN_TTFFONT_H
#define LOCKSCREEN_TTFFONT_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <memory>
#include "UIRenderer.h"

class TTFFont {
public:
    TTF_Font* font;
    SDL_Color colour = (SDL_Color) {0, 0, 0, 255};

    explicit TTFFont(const std::string &path, const int size, SDL_Color colour);

    void drawString(const std::string &str, const int x, const int y, std::shared_ptr<UIRenderer> render);

    virtual ~TTFFont();

    int stringWidth(const std::string& string);
};


#endif //LOCKSCREEN_TTFFONT_H
