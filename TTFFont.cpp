//
// Created by cub3d on 11/05/2018.
//

#include "TTFFont.h"

TTFFont::TTFFont(const std::string& path, const int size, SDL_Renderer* render) : render(render) {
    this->font = TTF_OpenFont(path.c_str(), size);
    if(!this->font) {
        printf("ERROR: loading fonts: %s\n", TTF_GetError());
    }
}

void TTFFont::drawString(const std::string& str, const int x, const int y) {
    SDL_Surface* textSurface = TTF_RenderText_Blended(this->font, str.c_str(), this->color);

    if(!textSurface) {
        printf("[FONT] Error drawing string: %s\n", TTF_GetError());
        return;
    }

    auto texture = SDL_CreateTextureFromSurface(this->render, textSurface);
    SDL_FreeSurface(textSurface);
    SDL_Rect quad = {x, y, textSurface->w, textSurface->h};
    SDL_RenderCopy( this->render, texture, nullptr, &quad);

    SDL_DestroyTexture(texture);
}

TTFFont::~TTFFont() {
    TTF_CloseFont(this->font);
    this->render = nullptr;
}

int TTFFont::stringWidth(const std::string& string) {
    int width = 0;
    TTF_SizeText(this->font, string.c_str(), &width, nullptr);
    return width;
}
