//
// Created by cub3d on 03/06/2018.
//
#include "ResourceManager.h"
#include <string>
#include <map>
#include "TTFFont.h"
#include "Image.h"

std::map<std::string, std::shared_ptr<TTFFont>> fontMap;
std::map<std::string, std::shared_ptr<Image>> imageMap;

void registerFont(const std::string& name, const std::string& path, const int size, SDL_Color colour) {
    if(fontMap.find(name) == fontMap.end()) {
        fontMap[name] = std::make_shared<TTFFont>(path, size, colour);
    }
}

void registerImage(const std::string& name, const std::string& path) {
    if(imageMap.find(name) == imageMap.end()) {
        imageMap[name] = std::make_shared<Image>(path);
    }
}
