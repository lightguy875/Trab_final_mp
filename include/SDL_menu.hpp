#ifndef SDL_STRUCTURE
#define SDL_STRUCTURE
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <stdio.h>
#include <string>
#include "GeneralButton.hpp"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define MENU_BUTTONS 3

enum GameState {
    GAME_MENU,
    GAME_CREDITS,
    GAME_QUIT,
};

class MenuGraphics{
    public:
    MenuGraphics();
    void close();
    void start_menu();
    SDL_Texture * loadTexture(std::string path);
    bool getGRunning();
    void setGRunning(bool state);

    private:
    bool g_running;
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* m_pTexture;
    SDL_Event Events;
    GeneralButton menuButtons[MENU_BUTTONS];
    GeneralButton creditsBackButton;
    GameState state_menu;

};


#endif
