#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_

#include <Windows.h>
#include <string>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>


//Screen
const int WIDTH_BACKGROUND = 640;
const int HEIGHT_BACKGROUND = 480;
const int WIDTH_CELL = 160;
const int HEIGHT_CELL = 120;
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

//Image
const std:: string s[14] = {"0.png", "1.png","2.png" ,"3.png" ,"4.png" ,"5.png" ,"6.png" ,"7.png" ,"8.png" ,"9.png" ,"10.png" ,"11.png" ,"12.png" ,"13.png" };
//Time
const int TIME_PLAYING = 30;

static SDL_Surface* g_screen = NULL;
static SDL_Surface* g_bkground = NULL;
static SDL_Event g_even;


namespace SDLCommonFunc
{
	SDL_Surface* LoadImage(std::string file_path);
	SDL_Rect ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y, int w, int h);
	void CleanUp();

}


#endif