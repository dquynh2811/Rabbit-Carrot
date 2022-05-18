
#ifndef action_H
#define action_H

#include "mainobject.h"
#include "play.h"

class act_
{
public:
    Mix_Chunk* music;
    Mix_Chunk* music1;
    Mix_Music* up;
    Mix_Music* scream;
    Mix_Music* click;
    Mix_Chunk* lose;
    Mix_Chunk* wins;
    SDL_Texture * rel;
    SDL_Texture * menu;
    SDL_Texture * next;
    SDL_Texture *sadrabbit;
    SDL_Texture *die;
    SDL_Texture *win;
    SDL_Texture *winLv5;
    SDL_Texture *lvl[6];
    void Set()
    {
        music = Mix_LoadWAV("sound//Lobby-Time.mp3");
        music1 = Mix_LoadWAV("sound//welcome.mp3");
        up = Mix_LoadMUS("sound//up.mp3");
        scream = Mix_LoadMUS("sound//scream.mp3");
        click = Mix_LoadMUS("sound//click.mp3");
        lose = Mix_LoadWAV("sound//lose.wav");
        wins = Mix_LoadWAV("sound//Feel-Good.mp3");
        rel = Map.loadTexture("img/reload.png");
        menu = Map.loadTexture("img/menu.png");
        next = Map.loadTexture("img/next.png");
        sadrabbit = Map.loadTexture("img/sadrabbit.png");
        die = Map.loadTexture("img/die.png");
        win = Map.loadTexture("img/win.png");
        winLv5 = Map.loadTexture("img/winLv5.png");
        for(int i = 1; i <= 5; ++i)
        {
            string s = "img/lvli.png";
            s[7] = char(i + '0');
            lvl[i] =  Map.loadTexture(s);
        }
    }
    void input_action();
    //Uint32 callback( Uint32 interval, void* param );
    void trap(int X_pos, int Y_pos);
    int Play();
};
extern act_ act;
#endif // action_H

