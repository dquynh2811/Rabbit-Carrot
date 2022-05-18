#include "mainobject.h"
#include "play.h"
#include "draw.h"

void draw_::RenderMap()
{
    SDL_RenderClear(renderer);
    Map.renderTexture(bg, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    for (int i = 0; i < MAX_MAP_Y; i++)
    {
        for (int j = 0; j < MAX_MAP_X; j++)
        {
            int pos_y = i * TILE_SIZE;
            int pos_x = j * TILE_SIZE;
            switch (mat[i][j])
            {
            case 1:
            {
                Map.renderTexture(img[1], pos_x, pos_y, TILE_SIZE, TILE_SIZE);
                break;
            }
            case 2:
            {
                if(!ok[2])
                    Map.renderTexture(img[1], pos_x, pos_y, TILE_SIZE, TILE_SIZE);
                break;
            }
            case 3:
            {
                if(ok[3])
                    Map.renderTexture(img[2], pos_x, pos_y, TILE_SIZE, TILE_SIZE);
                break;
            }
            case 4:
            {
                if(ok[4])
                    Map.renderTexture(img[3], pos_x, pos_y, TILE_SIZE, TILE_SIZE);
                break;
            }
            case 5:
            {
                if(ok[5])
                    Map.renderTexture(img[4], pos_x, pos_y, TILE_SIZE, TILE_SIZE);
                break;
            }
            case 6:
            {
                Map.renderTexture(img[5], pos_x, pos_y, TILE_SIZE, TILE_SIZE);
                break;
            }
            case 7:
            {
                Map.renderTexture(img[6], pos_x, pos_y, TILE_SIZE, TILE_SIZE);
                break;
            }
            }
        }
    }
}
void draw_::show_rabbit()
{
    rect_.x = x_pos_ ;
    rect_.y = y_pos_ ;
    SDL_Rect renderQuad = {rect_.x, rect_.y, rect_.w, rect_.h};
    SDL_RenderCopy(renderer, rabbit, NULL, &renderQuad);
}


