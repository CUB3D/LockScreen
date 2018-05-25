//
// Created by cub3d on 13/05/2018.
//

#ifndef LOCKSCREEN_XCBINSTANCE_H
#define LOCKSCREEN_XCBINSTANCE_H


#include <xcb/xcb.h>

class XCBInstance {
public:
    struct ev_io* xcb_watcher;
    struct ev_check* xcb_check;
    struct ev_prepare* xcb_prepare;
    xcb_connection_t* connection;
    struct xkb_state *xkb_state;
    struct xkb_compose_table *xkb_compose_table;
    struct xkb_compose_state *xkb_compose_state;
    struct xkb_context *xkb_context;
    struct xkb_keymap *xkb_keymap;

    XCBInstance();

    bool setup_xkb();
    void setupMouseAndKeyboardGrabbing();

    bool loadComposeTable(const char *locale);
    bool loadKeymap();
    bool genNewState();

    ~XCBInstance();
};


#endif //LOCKSCREEN_XCBINSTANCE_H
