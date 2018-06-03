//
// Created by cub3d on 26/05/2018.
//

#ifndef LOCKSCREEN_CONFIG_H
#define LOCKSCREEN_CONFIG_H

#include <string>
#include <rapidjson.h>
#include <document.h>
#include <fstream>
#include <filereadstream.h>
#include <vector>
#include "ResourceManager.h"
#include "Util.h"
#include "widgets/BaseWidget.h"
#include "widgets/StaticImageWidget.h"

void loadFonts(rapidjson::Document& document) {
    rapidjson::Value& fonts = document["Fonts"];

    if(fonts.GetType() != rapidjson::Type::kObjectType) {
        printf("Font should be an object\n");
        return;
    }

    for(auto itr = fonts.MemberBegin(); itr != fonts.MemberEnd(); itr++) {
        rapidjson::Value& name = itr->name;

        rapidjson::Value& content = itr->value;

        if(content.GetType() != rapidjson::Type::kObjectType) {
            printf("Each font element should be an object\n");
            return;
        }

        rapidjson::Value& path = content.GetObject()["Path"];

        if(path.GetType() != rapidjson::Type::kStringType) {
            printf("Paths should be strings\n");
            return;
        }

        rapidjson::Value& size = content.GetObject()["Size"];

        if(size.GetType() != rapidjson::Type::kNumberType) {
            printf("Size should be a number\n");
            return;
        }

        rapidjson::Value& colour = content.GetObject()["Colour"];

        if(path.GetType() != rapidjson::Type::kStringType) {
            printf("Colour should be a hex string\n");
            return;
        }

        registerFont(name.GetString(), path.GetString(), size.GetInt(), getColourFromString(colour.GetString()));
    }
}

void loadImages(rapidjson::Document& document) {
    rapidjson::Value& images = document["Images"];

    if(images.GetType() != rapidjson::Type::kObjectType) {
        printf("Images should be an object\n");
        return;
    }

    for(auto img = images.MemberBegin(); img != images.MemberEnd(); img++) {
        rapidjson::Value& name = img->name;

        rapidjson::Value& content = img->value;

        if(content.GetType() != rapidjson::Type::kObjectType) {
            printf("Each font element should be an object\n");
            return;
        }

        rapidjson::Value& path = content.GetObject()["Path"];

        if(path.GetType() != rapidjson::Type::kStringType) {
            printf("Paths should be strings\n");
            return;
        }

        registerImage(name.GetString(), path.GetString());
    }
}

std::vector<std::unique_ptr<BaseWidget>> loadWidgets(rapidjson::Document& document) {
    std::vector<std::unique_ptr<BaseWidget>> vecWidgets;

    rapidjson::Value& widgets = document["Widgets"];

    if(widgets.GetType() != rapidjson::Type::kObjectType) {
        printf("Widgets should be an object\n");
        return vecWidgets;
    }

    for(auto img = widgets.MemberBegin(); img != widgets.MemberEnd(); img++) {
        rapidjson::Value& name = img->name;

        rapidjson::Value& content = img->value;

        if(content.GetType() != rapidjson::Type::kObjectType) {
            printf("Each widget element should be an object\n");
            return vecWidgets;
        }

        rapidjson::Value& X = content["X"];

        if(X.GetType() != rapidjson::Type::kNumberType) {
            printf("Coordinates should be numbers\n");
            return vecWidgets;
        }

        rapidjson::Value& Y = content["Y"];

        if(Y.GetType() != rapidjson::Type::kNumberType) {
            printf("Coordinates should be numbers\n");
            return vecWidgets;
        }

        std::unique_ptr<BaseWidget> widget;

        std::string nameStr = std::string(name.GetString());

        if(nameStr == "Image") {
            rapidjson::Value& imageName = content["Name"];

            if(imageName.GetType() != rapidjson::Type::kStringType) {
                printf("Image name should be a string\n");
                return vecWidgets;
            }

            widget = std::make_unique<StaticImageWidget>(imageName.GetString());
        }

        if(nameStr == "Clock") {
            widget = std::make_unique<StaticImageWidget>("Wallpaper");
        }

        vecWidgets.push_back(std::move(widget));
    }

    return vecWidgets;
}

std::vector<std::unique_ptr<BaseWidget>> loadConfig(const std::string& path) {
    FILE* file = fopen(path.c_str(), "r");

    char buffer[4096];
    rapidjson::FileReadStream stream(file, buffer, sizeof(buffer));

    rapidjson::Document document;
    document.ParseStream(stream);

    loadFonts(document);
    loadImages(document);
    auto vecWidgets = loadWidgets(document);

    fclose(file);

    return vecWidgets;
}

#endif //LOCKSCREEN_CONFIG_H
