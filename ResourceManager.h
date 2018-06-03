//
// Created by cub3d on 26/05/2018.
//

#ifndef LOCKSCREEN_FONTMANAGER_H
#define LOCKSCREEN_FONTMANAGER_H


#include <string>
#include <map>
#include "TTFFont.h"
#include "Image.h"

extern std::map<std::string, std::shared_ptr<TTFFont>> fontMap;
extern std::map<std::string, std::shared_ptr<Image>> imageMap;

void registerFont(const std::string& name, const std::string& path, const int size, SDL_Color colour);

void registerImage(const std::string& name, const std::string& path);

//TODO: handling for failing to get image
#define GET_FONT(name) fontMap[name]
#define GET_IMAGE(name) imageMap[name]

#endif //LOCKSCREEN_FONTMANAGER_H
