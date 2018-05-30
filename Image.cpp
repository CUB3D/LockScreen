//
// Created by cub3d on 14/05/2018.
//

#include <memory>
#include "Image.h"
#include "UIRenderer.h"

Image::Image(const std::string &path) : path(path){
}

void Image::draw(std::shared_ptr<UIRenderer> renderer, const int x, const int y, const double angle) {
    if(!init) {
        SDL_Surface* image = IMG_Load(path.c_str());
        if(!image) {
            printf("[IMG] Error loading image: %s\n", IMG_GetError());
        }

        this->image = SDL_CreateTextureFromSurface(renderer->windowRenderer, image);
        if(!this->image) {
            printf("Error: failed to create texture: %s\n", IMG_GetError());
        }

        this->size = (SDL_Rect) {0, 0, image->w, image->h};

        SDL_FreeSurface(image);
        init = true;
    }


    SDL_Rect drawRect = this->size;

    drawRect.x = x;
    drawRect.y = y;

    if(!SDL_RenderCopyEx(renderer->windowRenderer, this->image, nullptr, &drawRect, angle, nullptr, SDL_FLIP_NONE)) {
        printf("Unable to render image: %s\n", IMG_GetError());
        SDL_ClearError();
    }

}

Image::~Image() {
    SDL_DestroyTexture(this->image);
}
