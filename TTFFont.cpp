//
// Created by cub3d on 11/05/2018.
//

#include "TTFFont.h"
#include "UIRenderer.h"

TTFFont::TTFFont(const std::string &path, const int size, SDL_Color colour) : colour(colour){
    this->font = TTF_OpenFont(path.c_str(), size);
    if(!this->font) {
        printf("ERROR: loading fonts: %s\n", TTF_GetError());
    }
}

void TTFFont::drawString(const std::string &str, const int x, const int y, std::shared_ptr<UIRenderer> render) {
    SDL_Surface* textSurface = TTF_RenderText_Blended(this->font, str.c_str(), this->colour);

    if(!textSurface) {
        printf("[FONT] Error drawing string: %s\n", TTF_GetError());
        return;
    }

    auto texture = SDL_CreateTextureFromSurface(render->windowRenderer, textSurface);
    SDL_FreeSurface(textSurface);
    SDL_Rect quad = {x, y, textSurface->w, textSurface->h};
    SDL_RenderCopy(render->windowRenderer, texture, nullptr, &quad);

    SDL_DestroyTexture(texture);
}

TTFFont::~TTFFont() {
    TTF_CloseFont(this->font);
}

int TTFFont::stringWidth(const std::string& string) {
    int width = 0;
    TTF_SizeText(this->font, string.c_str(), &width, nullptr);
    return width;
}
