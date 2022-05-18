#ifndef play_H
#include "play.h"
#endif // play_H
#ifndef draw_H
#include "draw.h"
#endif // draw_H
#ifndef action_H
#include "action.h"
#endif // action_H
#ifndef mainobject_H
#include " mainobject.h"
#endif // mainobject_H

Input input_type_;
play_ play;
act_ act;
draw_ draw;
void act_::input_action()
{
    if (e.type == SDL_KEYDOWN)
    {
        switch (e.key.keysym.sym)
        {
        case SDLK_RIGHT:
        {
            input_type_.right_ = 1;
            input_type_.left_ = 0;
            break;
        }
        case SDLK_LEFT:
        {
            input_type_.left_ = 1;
            input_type_.right_ = 0;
            break;
        }
        case SDLK_UP:
        {
            input_type_.up_ = 1;
            break;
        }
        }
    }
    else if (e.type == SDL_KEYUP)
    {
        switch (e.key.keysym.sym)
        {
        case SDLK_RIGHT:
        {
            input_type_.right_ = 0;
            break;
        }
        case SDLK_LEFT:
        {
            input_type_.left_ = 0;
            break;
        }
        case SDLK_UP:
        {
            input_type_.up_ = 0;
            break;
        }
        }
    }
}

Uint32 callback( Uint32 interval, void* param)
{
    bool *check = (bool*) param;
    *check = 1;
    return 0;
}

void act_::trap(int X_pos, int Y_pos)
{
    bool *p = &ok[mat[Y_pos / TILE_SIZE][X_pos / TILE_SIZE]];
    SDL_TimerID timerID = SDL_AddTimer(400, callback, p);
}


int act_::Play()
{
    bool is_quit = false;
    while (!is_quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                is_quit = true;
                return -1;
            }
            act.input_action();
        }

        SDL_RenderClear(renderer);
        play.do_player();
        if(y_pos_ > 550)
        {
            draw.RenderMap();
            Map.renderTexture(sadrabbit, x_pos_ - 20, y_pos_ - 20, 60, 60);
            SDL_RenderPresent(renderer);
            Mix_PlayMusic(scream, 1);
            SDL_Delay(600);
            SDL_RenderClear(renderer);
            Map.renderTexture(die, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
            Map.renderTexture(rel, 450, 400, 100, 100);
            Map.renderTexture(menu, 600, 400, 200, 100);
            Mix_PlayChannel(1, lose, -1);
            SDL_RenderPresent(renderer);
            while(1)
            {
                if (SDL_WaitEvent(&e) != 0)
                {
                    if (e.type == SDL_MOUSEBUTTONDOWN)
                    {
                        if(e.button.x >= 450 && e.button.x <= 550 && e.button.y >= 400 && e.button.y <= 500)
                        {
                            e.button.x = 0;
                            e.button.y = 0;
                            Mix_PlayMusic(click, 1);
                            return 1;
                        }
                        if(e.button.x >= 600 && e.button.x <= 800 && e.button.y >= 400 && e.button.y <= 500)
                        {
                            e.button.x = 0;
                            e.button.y = 0;
                            Mix_PlayMusic(click, 1);
                            return 2;
                        }
                    }
                    if (e.type == SDL_QUIT)
                    {
                        is_quit = true;
                        return -1;
                    }
                }
            }
        }

        if(mat[(y_pos_ + 35) / TILE_SIZE][x_pos_ / TILE_SIZE] == 2)
            trap(x_pos_, y_pos_ + 35);
        if (y_pos_ >= 35)
            if(mat[(y_pos_ - 15) / TILE_SIZE][x_pos_ / TILE_SIZE] == 2)
                trap(x_pos_, y_pos_ - 15);
        if(mat[y_pos_ / TILE_SIZE][(x_pos_ + 35) / TILE_SIZE] == 2)
            trap(x_pos_ + 35, y_pos_);
        if(mat[y_pos_ / TILE_SIZE][x_pos_ / TILE_SIZE] > 1 && mat[y_pos_ / TILE_SIZE][x_pos_ / TILE_SIZE] != 7)
            trap(x_pos_, y_pos_);

        draw.RenderMap();
        draw.show_rabbit();
        Map.renderTexture(lvl[Map.getLevel()], 0, 0, 80, 40);
        SDL_RenderPresent(renderer);
        if (input_type_.up_ == 1)
        {
            Mix_PlayMusic(up, 1);
        }
        if (ok[mat[y_pos_ / TILE_SIZE][x_pos_ / TILE_SIZE]] == 1 && mat[y_pos_ / TILE_SIZE][x_pos_ / TILE_SIZE] != 2 && mat[y_pos_ / TILE_SIZE][x_pos_ / TILE_SIZE] != 0)
        {
            draw.RenderMap();
            Map.renderTexture(sadrabbit, x_pos_ - 20, y_pos_ - 20, 60, 60);
            SDL_RenderPresent(renderer);
            Mix_PlayMusic(scream, 1);
            SDL_Delay(600);
            SDL_RenderClear(renderer);
            Map.renderTexture(die, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
            Map.renderTexture(rel, 450, 400, 100, 100);
            Map.renderTexture(menu, 600, 400, 200, 100);
            Mix_PlayChannel(1, lose, -1);
            SDL_RenderPresent(renderer);
            while(1)
            {
                if (SDL_WaitEvent(&e) != 0)
                {
                    if (e.type == SDL_MOUSEBUTTONDOWN)
                    {
                        if(e.button.x >= 450 && e.button.x <= 550 && e.button.y >= 400 && e.button.y <= 500)
                        {
                            e.button.x=0;
                            e.button.y=0;
                            Mix_PlayMusic(click, 1);
                            return 1;
                        }
                        if(e.button.x >= 600 && e.button.x <= 800 && e.button.y >= 400 && e.button.y <= 500)
                        {
                            e.button.x=0;
                            e.button.y=0;
                            Mix_PlayMusic(click, 1);
                            return 2;
                        }
                    }
                    if (e.type == SDL_QUIT)
                    {
                        is_quit = true;
                        return -1;
                    }
                }
            }
        }
        if(mat[y_pos_ / TILE_SIZE][x_pos_ / TILE_SIZE] == 7)
        {
            if(Map.getLevel() != 5)
            {
                SDL_Delay(50);
                SDL_RenderClear(renderer);
                Map.renderTexture(win, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
                Map.renderTexture(rel, 275, 400, 100, 100);
                Map.renderTexture(menu, 425, 400, 200, 100);
                Map.renderTexture(next, 675, 400, 200, 100);

                Mix_PlayChannel(1, wins, -1);
                SDL_RenderPresent(renderer);
                while(1)
                {
                    if (SDL_WaitEvent(&e) != 0)
                    {
                        if (e.type == SDL_MOUSEBUTTONDOWN)
                        {
                            if(e.button.x >= 275 && e.button.x <= 375 && e.button.y >= 400 && e.button.y <= 500)
                            {
                                e.button.x = 0;
                                e.button.y = 0;
                                Mix_PlayMusic(click, 1);
                                return 1;
                            }
                            if(e.button.x >= 425 && e.button.x <= 625 && e.button.y >= 400 && e.button.y <= 500)
                            {
                                e.button.x = 0;
                                e.button.y = 0;
                                Mix_PlayMusic(click, 1);
                                return 2;
                            }
                            if(e.button.x >= 675 && e.button.x <= 875 && e.button.y >= 400 && e.button.y <= 500)
                            {
                                e.button.x = 0;
                                e.button.y = 0;
                                Mix_PlayMusic(click, 1);
                                return 3;
                            }
                        }
                        if (e.type == SDL_QUIT)
                        {
                            is_quit = true;
                            return -1;
                        }
                    }
                }
            }
            else
            {
                SDL_Delay(50);
                SDL_RenderClear(renderer);
                Map.renderTexture(winLv5, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
                Map.renderTexture(rel, 450, 400, 100, 100);
                Map.renderTexture(menu, 600, 400, 200, 100);

                Mix_PlayChannel(1, wins, -1);
                SDL_RenderPresent(renderer);
                while(1)
                {
                    if (SDL_WaitEvent(&e) != 0)
                    {
                        if (e.type == SDL_MOUSEBUTTONDOWN)
                        {
                            if(e.button.x >= 450 && e.button.x <= 550 && e.button.y >= 400 && e.button.y <= 500)
                            {
                                e.button.x=0;
                                e.button.y=0;
                                Mix_PlayMusic(click, 1);
                                return 1;
                            }
                            if(e.button.x >= 600 && e.button.x <= 800 && e.button.y >= 400 && e.button.y <= 500)
                            {
                                e.button.x=0;
                                e.button.y=0;
                                Mix_PlayMusic(click, 1);
                                return 2;
                            }
                        }
                        if (e.type == SDL_QUIT)
                        {
                            is_quit = true;
                            return -1;
                        }
                    }
                }
            }
        }
    }
    return -1;
}


