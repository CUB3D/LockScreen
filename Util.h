//
// Created by cub3d on 26/05/2018.
//

#ifndef LOCKSCREEN_UTIL_H
#define LOCKSCREEN_UTIL_H

#include <ios>
#include <SDL_pixels.h>
#include <sstream>

inline int parseHexString(std::stringstream& stream, std::string str) {
    stream << std::hex << str[0];
    stream << std::hex << str[1];
    int x = 0;
    stream >> x;
    stream.clear();
    return x;
}

SDL_Color getColourFromString(std::string str)
{
    std::stringstream strstream;

    // R G B A
    int colourParts[4];

    colourParts[3] = 255;

    if (str.length() >= 8) {
        colourParts[3] = parseHexString(strstream, str);
        str = str.erase(0, 2);
    }

    for(int i = 0; i < 3; i++) {
        colourParts[i] = parseHexString(strstream, str);
        str = str.erase(0, 2);
    }

    //printf("%d:%d:%d:%d\n", colourParts[1], colourParts[2], colourParts[4], colourParts[0]);

    return (SDL_Color) {colourParts[1], colourParts[2], colourParts[4], colourParts[0]};
}

#endif //LOCKSCREEN_UTIL_H
