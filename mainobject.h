
#ifndef mainobject_H
#define mainobject_H

#include <bits/stdc++.h>
#include <windows.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
using namespace std;
struct PLV
{
    int l1;
    int r1;
    int l2;
    int r2;
};
extern PLV pos_lv;
class Map_
{
public:
    SDL_Texture *lv;
    SDL_Texture* loadTexture(const std::string &file);
    SDL_Texture *welcome;
    SDL_Texture *next;
    SDL_Texture *start;
    SDL_Texture *quit;
    SDL_Texture *bgl;
    int mapIndex = 1;

    void Lv();
    void renderTexture(SDL_Texture *texture, int x, int y, int w, int h);
    void renderTexture(SDL_Texture *texture, int x, int y);
    void load_map();
    void set_plv()
    {
            pos_lv.l1 = 1200;
            pos_lv.r1 = 1500;
            pos_lv.l2 = 50;
            pos_lv.r2 = 150;
    }
    void upLevel();
    int getLevel();
    void load_data();
    void load_img();
    void RandMap();
    void wel_load();
    void load_continue();
};


extern const int TILE_SIZE;
extern const int MAX_MAP_X;
extern const int MAX_MAP_Y;
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern int x_pos_, y_pos_;
extern SDL_Texture *img[20];
extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern bool ok[50];
extern int mat[30][30];
extern SDL_Texture *bg;
extern SDL_Texture *rabbit;
extern Map_ Map;
#endif

