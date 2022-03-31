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
const std:: string s[50] = {"image/0.png", "image/1.png","image/2.png" ,"image/3.png" ,"image/4.png" ,"image/5.png" ,"image/6.png" ,"image/7.png" ,"image/8.png" ,"image/9.png" ,"image/10.png" ,"image/11.png" ,"image/12.png" ,"image/13.png", "image/14.png","image/15.png" ,"image/16.png" ,"image/17.png" ,"image/18.png" ,"image/19.png" ,"image/20.png" ,"image/21.png" ,"image/22.png" ,"image/23.png" ,"image/24.png" ,"image/25.png" ,"image/26.png" ,"image/27.png" ,"image/28.png" ,"image/29.png" ,"image/30.png" ,"image/31.png" };

//Time
const int TIME_PLAYING = 60;

//Initialize
static SDL_Surface* g_screen = NULL;
static SDL_Surface* g_bkground = NULL;
static SDL_Surface* g_menu = NULL;
static SDL_Event g_even;


namespace SDLCommonFunc
{
	SDL_Surface* LoadImage(std::string file_path);
	SDL_Rect ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y, int w, int h);
	void CleanUp();
	int ShowMenu(SDL_Surface* des, TTF_Font* font);
	bool CheckFocusWithRect(const int& x, const int& y, const SDL_Rect& rect);

}


#endif