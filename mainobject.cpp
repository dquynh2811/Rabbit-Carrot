
#include "mainobject.h"

const int TILE_SIZE = 50;
const int MAX_MAP_X = 24;
const int MAX_MAP_Y = 12;
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 600;
int x_pos_ = 0, y_pos_ = 450;
SDL_Texture *img[20];
SDL_Window* window;
SDL_Renderer* renderer;
bool ok[50];
int mat[30][30];
PLV pos_lv;
SDL_Texture *bg;
SDL_Texture *rabbit;
Map_ Map;

SDL_Texture* Map_::loadTexture(const std::string &file)
{
    SDL_Texture *texture = nullptr;
	SDL_Surface *loadedImage = IMG_Load(file.c_str());
	if (loadedImage != nullptr){
		texture = SDL_CreateTextureFromSurface(renderer, loadedImage);
		SDL_FreeSurface(loadedImage);
	}
	return texture;
}

void Map_::renderTexture(SDL_Texture *texture, int x, int y, int w, int h)
{
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
    dst.w = w;
    dst.h = h;
	SDL_RenderCopy(renderer, texture, NULL, &dst);
}

void Map_::renderTexture(SDL_Texture *texture, int x, int y)
{
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
	SDL_RenderCopy(renderer, texture, NULL, &dst);
}

void Map_::load_img() {
    img[1] = Map.loadTexture("img/brick.png");
    img[2] = Map.loadTexture("img/trap_up.png");
    img[3] = Map.loadTexture("img/trap_down.png");
    img[4] = Map.loadTexture("img/trap_left.png");
    img[5] = Map.loadTexture("img/base.png");
    img[6] = Map.loadTexture("img/carrot.png");
    memset(ok, 0, sizeof(ok));
}

void Map_::RandMap() {
    int t = rand() % 17 + 1;
    string s = "background/bg";
    string num = "";
    if (t > 9) {
        while(t) {
            num += t % 10 + 48;
            t /= 10;
        }
        reverse(num.begin(), num.end());
    }
    else {
        num += '0';
        num += t + '0';
    }
    s += num + ".jpg";
    bg = Map.loadTexture(s);
    Map.renderTexture(rabbit, 0, 400, 30, 30);
}


void Map_::upLevel()
{
     mapIndex++;
     if(mapIndex > 5) mapIndex = 1;
}

int Map_::getLevel()
{
    return mapIndex;
}

void Map_::load_data() {
    string s = "map/map";
//    cerr << mapIndex << endl;
    s += char(mapIndex + '0');
    s += ".dat";
    ifstream fileInput(s.c_str());
    while(!fileInput.eof()) {
        for (int i = 0; i < MAX_MAP_Y; i++){
            for (int j = 0; j < MAX_MAP_X; j++){
                fileInput >> mat[i][j];
            }
        }
    }
    fileInput.close();
}

void Map_::wel_load()
{
    Map_::mapIndex = 1;
    SDL_RenderClear(renderer);
    renderTexture(welcome, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    renderTexture(start, 250, 150, 225, 100);
    renderTexture(quit, 250, 325, 225, 100);
    SDL_RenderPresent(renderer);
}

