#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <X11/X.h>

// The c library uses explicit as a param name at xkb.h:2005, replace because explicit is reserved in c++
#define explicit explicit_type
    #include <xcb/xcb.h>
    #include <xcb/xkb.h>
    #include <xkbcommon/xkbcommon.h>
    #include <xkbcommon/xkbcommon-compose.h>
    #include <xkbcommon/xkbcommon-x11.h>
    #include <ev.h>
#undef explicit

#include "TTFFont.h"
#include "XCBInstance.h"
#include "Image.h"

#include "widgets/ClockWidget.h"
#include "widgets/PasswordEntryWidget.h"

bool running = true;
std::string ss;
std::unique_ptr<XCBInstance> xcb;
bool screenDirty;

void quit(int exitcode) {
    SDL_Quit();
    exit(exitcode);
}

SDL_Renderer* createWindow()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Error: SDL failed to initialise, %s\n", SDL_GetError());
       // quit(ErrorCodes::SDL_INITIALIZATION_FAIL);
    }

    auto window = SDL_CreateWindow("", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1366, 768, SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN);

    if (!window)
    {
        printf("Error: SDL failed to create a window, %s\n", SDL_GetError());
        //quit(ErrorCodes::SDL_WINDOW_CREATION_FAIL);
    }

    SDL_Renderer* windowRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!windowRenderer)
    {
        printf("Error: SDL failed to create renderer, %s\n", SDL_GetError());
       // quit(ErrorCodes::SDL_WINDOW_RENDERER_CREATION_FAIL);
    }

    SDL_SetRenderDrawColor(windowRenderer, 0, 0, 0, 0); // Black

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
    {
        printf("Error: SDL failed to initialise PNG loading, %s\n", IMG_GetError());
       // quit(ErrorCodes::SDL_WINDOW_PNG_INIT_FAIL);
    }

    if(TTF_Init() == -1)
    {
        printf("Error: SDL failed to initialise TTF handling, %s\n", TTF_GetError());
        //quit(ErrorCodes::SDL_WINDOW_TTF_INIT_FAIL);
    }

    return windowRenderer;
}

void attempLogin() {
    if(ss == "password") {
        quit(0);
    }
}

extern "C" {
static void handle_key_press(xcb_key_press_event_t *event) {
    xkb_keysym_t ksym;
    char buffer[128];
    int n;
    bool ctrl;
    bool composed = false;

    ksym = xkb_state_key_get_one_sym(xcb->xkb_state, event->detail);
    ctrl = xkb_state_mod_name_is_active(xcb->xkb_state, XKB_MOD_NAME_CTRL, XKB_STATE_MODS_DEPRESSED);

    /* The buffer will be null-terminated, so n >= 2 for 1 actual character. */
    memset(buffer, '\0', sizeof(buffer));

    if (xcb->xkb_compose_state && xkb_compose_state_feed(xcb->xkb_compose_state, ksym) == XKB_COMPOSE_FEED_ACCEPTED) {
        switch (xkb_compose_state_get_status(xcb->xkb_compose_state)) {
            case XKB_COMPOSE_NOTHING:
                break;
            case XKB_COMPOSE_COMPOSING:
                return;
            case XKB_COMPOSE_COMPOSED:
                /* xkb_compose_state_get_utf8 doesn't include the terminating byte in the return value
             * as xkb_keysym_to_utf8 does. Adding one makes the variable n consistent. */
                n = xkb_compose_state_get_utf8(xcb->xkb_compose_state, buffer, sizeof(buffer)) + 1;
                ksym = xkb_compose_state_get_one_sym(xcb->xkb_compose_state);
                composed = true;
                break;
            case XKB_COMPOSE_CANCELLED:
                xkb_compose_state_reset(xcb->xkb_compose_state);
                return;
        }
    }

    if (!composed) {
        n = xkb_keysym_to_utf8(ksym, buffer, sizeof(buffer));
    }

    switch (ksym) {
        case XKB_KEY_j:
        case XKB_KEY_m:
        case XKB_KEY_Return:
        case XKB_KEY_KP_Enter:
        case XKB_KEY_XF86ScreenSaver:
            if ((ksym == XKB_KEY_j || ksym == XKB_KEY_m) && !ctrl)
                break;

            //TODO: PAM
            attempLogin();
            return;
        case XKB_KEY_u:
        case XKB_KEY_Escape:
            if ((ksym == XKB_KEY_u && ctrl) ||
                ksym == XKB_KEY_Escape) {
                ss = "";
                return;
            }
            break;
        case XKB_KEY_Delete:
        case XKB_KEY_KP_Delete:
            /* Deleting forward doesn’t make sense, as i3lock doesn’t allow you
             * to move the cursor when entering a password. We need to eat this
             * key press so that it won’t be treated as part of the password,
             * see issue #50. */
            return;
        case XKB_KEY_h:
        case XKB_KEY_BackSpace:
            if (ksym == XKB_KEY_h && !ctrl) {
                break;
            }

            if (ss.length() > 0) {
                ss = ss.substr(0, ss.length() - 1);
            }
            return;
    }

    ss += std::string(buffer);

    screenDirty = true;

    //TODO
    if(ss.length() == 8) {
        attempLogin();
    }

#if 0
    /* FIXME: handle all of these? */
    printf("is_keypad_key = %d\n", xcb_is_keypad_key(sym));
    printf("is_private_keypad_key = %d\n", xcb_is_private_keypad_key(sym));
    printf("xcb_is_cursor_key = %d\n", xcb_is_cursor_key(sym));
    printf("xcb_is_pf_key = %d\n", xcb_is_pf_key(sym));
    printf("xcb_is_function_key = %d\n", xcb_is_function_key(sym));
    printf("xcb_is_misc_function_key = %d\n", xcb_is_misc_function_key(sym));
    printf("xcb_is_modifier_key = %d\n", xcb_is_modifier_key(sym));
#endif
}
}

static void xcb_check_cb(EV_P_ ev_check *w, int revents) {
    xcb_generic_event_t *event;

    //if (xcb_connection_has_error(conn))
        //errx(EXIT_FAILURE, "X11 connection broke, did your server terminate?\n");

    while ((event = xcb_poll_for_event(xcb->connection)) != NULL) {
        if (event->response_type == 0) {
            xcb_generic_error_t *error = (xcb_generic_error_t *)event;
            fprintf(stderr, "X11 Error received! sequence 0x%x, error_code = %d\n", error->sequence, error->error_code);
            free(event);
            continue;
        }

        /* Strip off the highest bit (set if the event is generated) */
        int type = (event->response_type & 0x7F);

        switch (type) {
            case XCB_KEY_PRESS:
                handle_key_press((xcb_key_press_event_t *)event);
                break;
        }

        free(event);
    }
}

static void xcb_prepare_cb(EV_P_ ev_prepare *w, int revents) {
    xcb_flush(xcb->connection);
}

static void xcb_got_event(EV_P_ struct ev_io *w, int revents) {
    /* empty, because xcb_prepare_cb and xcb_check_cb are used */
}

int main() {
    //system("scrot /tmp/desktop.png");
    system("convert -resize 20% -filter Gaussian -define 'filter:sigma=1.5' -resize 500.5% /home/cub3d/Pictures/Wallpaper.png /tmp/desktop.png");

    xcb = std::make_unique<XCBInstance>();
    xcb->setup_xkb();
    xcb->loadKeymap();
    xcb->loadComposeTable("en_GB.utf8");
    xcb->genNewState();
    xcb->setupMouseAndKeyboardGrabbing();

    auto render = createWindow();

    SDL_Rect screenSize = {0, 0, 1366, 768};

    ev_io_init(xcb->xcb_watcher, xcb_got_event, xcb_get_file_descriptor(xcb->connection), EV_READ);
    ev_io_start(EV_DEFAULT, xcb->xcb_watcher);

    ev_check_init(xcb->xcb_check, xcb_check_cb);
    ev_check_start(EV_DEFAULT, xcb->xcb_check);

    ev_prepare_init(xcb->xcb_prepare, xcb_prepare_cb);
    ev_prepare_start(EV_DEFAULT, xcb->xcb_prepare);

    TTFFont mainFont("/home/cub3d/Development/LockScreen/res/fonts/IBMPlexSans-Regular.ttf", 14, render);
    mainFont.color = (SDL_Color) {255, 255, 255, 255};

    TTFFont detailFont("/home/cub3d/Development/LockScreen/res/fonts/IBMPlexSans-Bold.ttf", 14, render);
    detailFont.color = (SDL_Color) {255, 255, 255, 255};

    UIRenderer renderer;
    renderer.windowRenderer = render;
    renderer.screenSize = screenSize;

    //TODO: flip args
    Image img(render, "/tmp/desktop.png");
    Image usr(render, "/home/cub3d/Development/LockScreen/res/img/img.png");
    Image dot(render, "/home/cub3d/Development/LockScreen/res/img/dot.png");

    ClockWidget wid;
    wid.font = std::shared_ptr<TTFFont>(&detailFont);
    wid.x = screenSize.w - detailFont.stringWidth("00:00:00") - 2;
    wid.y = 2;

    std::shared_ptr<UIRenderer> ui = std::shared_ptr<UIRenderer>(&renderer);

    PasswordEntryWidget pass(ui);
    pass.x = screenSize.w / 2;
    pass.y = screenSize.h / 2 + 32 * 5;

    SDL_SetRenderDrawColor(render, 0, 255, 255, 255);

    while(running) {
        if(wid.isDirty() || pass.isDirty()) {
            screenDirty = true;
        }

        if(screenDirty) {
            SDL_RenderClear(render);

            img.draw(0, 0, 0);
            usr.draw(screenSize.w / 2 - usr.size.w / 2, screenSize.h / 2 - usr.size.h / 2 - 16, 0);

            mainFont.drawString("CUB3D", screenSize.w / 2 - mainFont.stringWidth("CUB3D") / 2,
                            screenSize.h / 2 + usr.size.h / 2 + 8);

            wid.draw();

            pass.draw();

            for(int x = 0; x < ss.length(); x++) {
                dot.draw(pass.x - pass.background->size.w / 2 + dot.size.w * x + 2, pass.y + pass.background->size.h / 2 + dot.size.h / 2, 0);
            }

            ev_invoke(EV_DEFAULT, xcb->xcb_check, 0);

            SDL_RenderPresent(render);

            screenDirty = false;
        }
    }

    return 0;
}