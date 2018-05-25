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

class TTFFont {
public:
    TTF_Font* font;
    SDL_Renderer* render;
    SDL_Color color = (SDL_Color) {0, 0, 0, 255};

    explicit TTFFont(const std::string& path, const int size, SDL_Renderer* render);

    void drawString(const std::string& str, const int x, const int y);

    virtual ~TTFFont();

    int stringWidth(const std::string& string);
};


#endif //LOCKSCREEN_TTFFONT_H
