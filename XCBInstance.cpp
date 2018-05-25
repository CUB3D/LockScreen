//
// Created by cub3d on 13/05/2018.
//

#include "XCBInstance.h"

#define explicit explicit_type
#include <xcb/xcb.h>
#include <xcb/xkb.h>
#include <xkbcommon/xkbcommon.h>
#include <xkbcommon/xkbcommon-compose.h>
#include <xkbcommon/xkbcommon-x11.h>
#include <ev.h>
#undef explicit

#include <cstdlib>

XCBInstance::XCBInstance() {
    this->connection = xcb_connect(nullptr, nullptr);
    this->xcb_watcher = (struct ev_io*)calloc(sizeof(struct ev_io), 1);
    this->xcb_check = (struct ev_check*)calloc(sizeof(struct ev_check), 1);
    this->xcb_prepare = (struct ev_prepare*) calloc(sizeof(struct ev_prepare), 1);
}

bool XCBInstance::setup_xkb() {
    static uint8_t xkb_base_event;
    static uint8_t xkb_base_error;

    return xkb_x11_setup_xkb_extension(this->connection,
                                       XKB_X11_MIN_MAJOR_XKB_VERSION,
                                       XKB_X11_MIN_MINOR_XKB_VERSION,
                                       XKB_X11_SETUP_XKB_EXTENSION_NO_FLAGS,
                                       NULL,
                                       NULL,
                                       &xkb_base_event,
                                       &xkb_base_error) != 1;
}

bool XCBInstance::loadComposeTable(const char *locale) {
    xkb_compose_table_unref(xkb_compose_table);

    if ((xkb_compose_table = xkb_compose_table_new_from_locale(xkb_context, locale,
                                                               static_cast<xkb_compose_compile_flags>(0))) == NULL) {
        fprintf(stderr, "[i3lock] xkb_compose_table_new_from_locale failed\n");
        return false;
    }

    struct xkb_compose_state *new_compose_state = xkb_compose_state_new(xkb_compose_table,
                                                                        static_cast<xkb_compose_state_flags>(0));
    if (new_compose_state == NULL) {
        fprintf(stderr, "[i3lock] xkb_compose_state_new failed\n");
        return false;
    }

    xkb_compose_state_unref(xkb_compose_state);
    xkb_compose_state = new_compose_state;

    return true;
}

bool XCBInstance::loadKeymap() {
    if (xkb_context == NULL) {
        if ((xkb_context = xkb_context_new(static_cast<xkb_context_flags>(0))) == NULL) {
            fprintf(stderr, "[i3lock] could not create xkbcommon context\n");
            return false;
        }
    }

    xkb_keymap_unref(xkb_keymap);

    int32_t device_id = xkb_x11_get_core_keyboard_device_id(this->connection);
    if ((xkb_keymap = xkb_x11_keymap_new_from_device(xkb_context, this->connection, device_id, XKB_KEYMAP_COMPILE_NO_FLAGS)) == NULL) {
        fprintf(stderr, "[i3lock] xkb_x11_keymap_new_from_device failed\n");
        return false;
    }

    struct xkb_state *new_state =
            xkb_x11_state_new_from_device(xkb_keymap, this->connection, device_id);
    if (new_state == NULL) {
        fprintf(stderr, "[i3lock] xkb_x11_state_new_from_device failed\n");
        return false;
    }

    xkb_state_unref(xkb_state);
    xkb_state = new_state;

    return true;
}

void XCBInstance::setupMouseAndKeyboardGrabbing() {
    auto screen = xcb_setup_roots_iterator(xcb_get_setup(this->connection)).data;
    auto pcookie = xcb_grab_pointer(
            this->connection,
            false,               /* get all pointer events specified by the following mask */
            screen->root,        /* grab the root window */
            XCB_NONE,            /* which events to let through */
            XCB_GRAB_MODE_ASYNC, /* pointer events should continue as normal */
            XCB_GRAB_MODE_ASYNC, /* keyboard mode */
            XCB_NONE,            /* confine_to = in which window should the cursor stay */
            XCB_NONE,              /* we change the cursor to whatever the user wanted */
            XCB_CURRENT_TIME);

    xcb_grab_pointer_reply_t* preply;
    if ((preply = xcb_grab_pointer_reply(this->connection, pcookie, NULL)) && preply->status == XCB_GRAB_STATUS_SUCCESS) {
        free(preply);
        printf("Success in grabbing mouse\n");
    }

    auto kcookie = xcb_grab_keyboard(
            this->connection,
            0,         /* report events */
            screen->root, /* grab the root window */
            XCB_CURRENT_TIME,
            XCB_GRAB_MODE_ASYNC, /* process events as normal, do not require sync */
            XCB_GRAB_MODE_ASYNC);

    xcb_grab_keyboard_reply_t* kreply;
    if ((kreply = xcb_grab_keyboard_reply(this->connection, kcookie, NULL)) &&
        kreply->status == XCB_GRAB_STATUS_SUCCESS) {
        free(kreply);
        printf("Success in grabbing keyboard\n");
    }
}

bool XCBInstance::genNewState() {
    int32_t device_id = xkb_x11_get_core_keyboard_device_id(this->connection);
    struct xkb_state *new_state = xkb_x11_state_new_from_device(xkb_keymap, this->connection, device_id);
    if (!new_state) {
        fprintf(stderr, "[i3lock] xkb_x11_state_new_from_device failed\n");
        return false;
    }

    xkb_state_unref(xkb_state);
    xkb_state = new_state;

    return true;
}

XCBInstance::~XCBInstance() {
    free(this->xcb_check);
    free(this->xcb_prepare);
    free(this->xcb_watcher);
}
