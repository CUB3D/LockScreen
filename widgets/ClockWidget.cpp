//
// Created by cub3d on 15/05/2018.
//

#include "ClockWidget.h"
#include <sstream>
#include <chrono>

#define CLOCK_WIDGET_BUFFER_SIZE 64

ClockWidget::ClockWidget() {
}

void ClockWidget::draw() {
    char buffer[CLOCK_WIDGET_BUFFER_SIZE];
    snprintf(buffer, CLOCK_WIDGET_BUFFER_SIZE, "%02d:%02d:%02d\0",
             this->timeInstance->tm_hour,
             this->timeInstance->tm_min,
             this->timeInstance->tm_sec);

    font->drawString(buffer, this->x, this->y);
}

bool ClockWidget::isDirty() {
    std::time_t t = std::time(0);   // get time now
    this->timeInstance = std::localtime(&t);

    if(this->timeInstance->tm_sec != this->lastSecond) {
        this->lastSecond = this->timeInstance->tm_sec;
        return true;
    }

    return false;
}
