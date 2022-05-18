#include "mainobject.h"
#include "play.h"
#include "action.h"
#include "draw.h"
const string WINDOW_TITLE = "Rabbit & Carrot";

void logSDLError(ostream& os, const string &msg, bool fatal = false);
void logSDLError(ostream& os, const string &msg, bool fatal)
{
    os << msg << " Error: " << SDL_GetError() << endl;
    if (fatal)
    {
        SDL_Quit();
        exit(1);
    }
}
void initSDL()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logSDLError(cout, "SDL_Init", true);
    if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
    }
    window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr)
        logSDLError(cout, "CreateWindow", true);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr)
        logSDLError(cout, "CreateRenderer", true);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
    }
    //Initialize SDL_mixer
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
    }
}
void quitSDL()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------
int run()
{
    Mix_PlayChannel(1, act.music, -1);
    Mix_Volume(1, MIX_MAX_VOLUME / 3);
    SDL_RenderClear(renderer);
    play.SetRect();
    Map.load_data();

    memset(ok, 0, sizeof(ok));
    x_val_ = 0;
    y_val_ = 0;
    x_pos_ = 0;
    y_pos_ = 470;
    on_ground = false;
    input_type_.left_ = 0;
    input_type_.right_ = 0;
    input_type_.down_ = 0;
    input_type_.up_ = 0;
    draw.RenderMap();
    draw.show_rabbit();
    SDL_RenderPresent(renderer);
    int ret = act.Play();
    if(ret == -1)
    {
        quitSDL();
        return -1;
    }
    if(e.type == SDL_QUIT)
    {
        quitSDL();
        return -1;
    }

    if (ret == 2)
    {
        SDL_RenderClear(renderer);
        Map.wel_load();
        SDL_RenderPresent(renderer);
        Mix_PlayChannel(1, act.music1, -1);
        return -2;
    }
    if(ret == 3)
    {
        Map.upLevel();
        Map.RandMap();
    }
    return ret;
}
int main(int argc, char* argv[])
{

    initSDL();
    SDL_Event e;
    Map.load_img();
    Map.set_plv();
    act.Set();
    rabbit = Map.loadTexture("img/rabbit.png");
    Map.welcome = Map.loadTexture("menu/bgw.png");
    Map.start = Map.loadTexture("menu/start.PNG");
    Map.quit = Map.loadTexture("menu/quit.PNG");
    Map.bgl = Map.loadTexture("menu/bg.jpg");

    SDL_RenderClear(renderer);
    Map.wel_load();
    SDL_RenderPresent(renderer);
    Mix_PlayChannel(1, act.music1, -1);
    while(1)
    {
        if ( SDL_WaitEvent(&e) != 0 )
        {
            if(e.type == SDL_QUIT)
            {
                quitSDL();
                return 0;
            }
            if(e.type == SDL_MOUSEBUTTONDOWN)
            {
                if(e.button.x >= 250 && e.button.x <= 475 && e.button.y >= 150 && e.button.y <= 250)
                {
                    e.button.x = 0;
                    e.button.y = 0;
                    Mix_PlayMusic(act.click, 1);
                    Map.RandMap();
                    while(1)
                    {
                        int T = run();
                        if (T == -1)
                        {
                            quitSDL();
                            return 0;
                        }
                        else if(T == -2) break;

                    }
                }

                if(e.button.x >= 250 && e.button.x <= 475 && e.button.y >= 325 && e.button.y <= 425)
                {
                    quitSDL();
                    return 0;
                }
            }
        }
    }
    quitSDL();
    return 0;
}
