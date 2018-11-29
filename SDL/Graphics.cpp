#include "../include/Graphics.hpp"

Button menuButtons[ TOTAL_MENU_BUTTONS ];
Button pauseButton[2];
Button creditsBackButton;
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
Texture menu_screen;
Texture credit_screen;
Texture pause_screen;
Texture round_screen;
Texture knight, solider, archer;
Texture map_screen;
TTF_Font * font;
Texture textActiveItem,textHP, textBones, textMetal, textRound;
Texture castle_left[3],castle_right[3];
Texture bones[30],metal[30];

bool Graphics::init(){
    bool success = true;

    //Inicializa o  SDL
    if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 ){
        printf( "Erro ao iniciar o SDL \n Erro: %s\n", SDL_GetError() );
        success = false;
    }
    else {
        window = SDL_CreateWindow( "Jan of Empiries", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( window == NULL ){
            printf( "Janela nao pode ser criada! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else{
            //cria renderer vsync
            renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if( renderer == NULL )
            {
                printf( "Nao foi possivel renderizar utilizando SDL! \n Error: %s\n", SDL_GetError() );
                success = false;
            }
            else
            {
                if( TTF_Init() == -1 )
                {
                    printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
                    success = false;
                }else{
                    //inicializa a cor do renderer
                    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );

                    //carregamento de png
                    int imgFlags = IMG_INIT_PNG;
                    if( !( IMG_Init( imgFlags ) & imgFlags ) )
                    {
                        printf( "Erro ao iniciar o SDL_Image \n Erro: %s\n", IMG_GetError() );
                        success = false;
                    }
                }
            }
        }
    }
    return success;
}

bool Graphics::loadMedia(){
    bool success = true;

    //carrega menu
    if( !menu_screen.loadFromFile( "../assets/menu_screen.png" ) ) {
        printf( "Failed to load texture!\n" );
        success = false;
    }

    //carrega credits
    if( !credit_screen.loadFromFile( "../assets/credit_screen.png" ) ) {
        printf( "Failed to load texture!\n" );
        success = false;
    }

    if( !pause_screen.loadFromFile( "../assets/pause_screen.png" ) ) {
        printf( "Failed to load texture!\n" );
        success = false;
    }

    if( !map_screen.loadFromFile( "../assets/map_game.png" ) ) {
        printf( "Failed to load texture!\n" );
        success = false;
    }

    if( !round_screen.loadFromFile( "../assets/round_screen.png" ) ) {
        printf( "Failed to load texture!\n" );
        success = false;
    }

    if( !knight.loadFromFile( "../assets/knight.png" ) ) {
        printf( "Failed to load texture!\n" );
        success = false;
    }

    if( !solider.loadFromFile( "../assets/solider.png" ) ) {
        printf( "Failed to load texture!\n" );
        success = false;
    }

    if( !archer.loadFromFile( "../assets/archer.png" ) ) {
        printf( "Failed to load texture!\n" );
        success = false;
    }

    if (!castle_right[0].loadFromFile( "../assets/pilar_archer_right.png" ) ) {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    if (!castle_right[1].loadFromFile( "../assets/pilar_knight_right.png" ) ) {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    if (!castle_right[2].loadFromFile( "../assets/pilar_solider_right.png" ) ) {
        printf( "Failed to load texture!\n" );
        success = false;
    }

    if (!castle_left[0].loadFromFile( "../assets/pilar_archer_left.png" ) ) {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    if (!castle_left[1].loadFromFile( "../assets/pilar_knight_left.png" ) ) {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    if (!castle_left[2].loadFromFile( "../assets/pilar_solider_left.png" ) ) {
        printf( "Failed to load texture!\n" );
        success = false;
    }

    for (int i = 0; i < 30; i++)
    {
        if (!bones[i].loadFromFile( "../assets/bones.png" ) ) {
            printf( "Failed to load texture!\n" );
            success = false;
        }
        if (!metal[i].loadFromFile( "../assets/metal.png" ) ) {
            printf( "Failed to load texture!\n" );
            success = false;
        }
    }

    font = TTF_OpenFont("../assets/arial.ttf", 18);

    menuButtons[0].setPositionSizeType(0,0,800,200, BUTTON_PLAY);
    menuButtons[1].setPositionSizeType(0,200,800,200,BUTTON_CREDITS);
    menuButtons[2].setPositionSizeType(0,400,800,200,BUTTON_QUIT);
    creditsBackButton.setPositionSizeType(0,500,800,100,BUTTON_BACK_CREDITS);
    pauseButton[0].setPositionSizeType(0,0,800,300,BUTTON_BACK_GAME);
    pauseButton[1].setPositionSizeType(0,300,800,300,BUTTON_QUIT);

    return success;
}

void Graphics::close(){
    SDL_DestroyRenderer( renderer );
    SDL_DestroyWindow( window );
    window = NULL;
    renderer = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}