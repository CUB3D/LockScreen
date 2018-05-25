//
// Created by cub3d on 14/05/2018.
//

#include "Image.h"

Image::Image(SDL_Renderer* render, const std::string& path) : windowRenderer(render) {
    SDL_Surface* image = IMG_Load(path.c_str());
    if(!image) {
        printf("[IMG] Error loading image: %s\n", IMG_GetError());
    }

    this->image = SDL_CreateTextureFromSurface(this->windowRenderer, image);
    if(!this->image) {
        printf("Error: failed to create texture: %s\n", IMG_GetError());
    }

    this->size = (SDL_Rect) {0, 0, image->w, image->h};

    SDL_FreeSurface(image);
}

void Image::draw(const int x, const int y, const double angle) {
    SDL_Rect drawRect = this->size;

    drawRect.x = x;
    drawRect.y = y;

    if(!SDL_RenderCopyEx(this->windowRenderer, this->image, nullptr, &drawRect, angle, nullptr, SDL_FLIP_NONE)) {
        printf("Unable to render image: %s\n", IMG_GetError());
        SDL_ClearError();
    }

}

Image::~Image() {
    SDL_DestroyTexture(this->image);
    this->windowRenderer = nullptr;
}
