#include "CommonFunction.h"
#include "Board.h"
#include"TextObject.h"
#include <ctime>
#include <iostream>

#undef main
TTF_Font* g_font_text = NULL;

bool Init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {   
        return false;
    }

    g_screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
    SDL_WM_SetCaption("Pipe Water", NULL);

    if (g_screen == NULL)
        return false;
    if (TTF_Init() == -1) {
        return false;
    }
    g_font_text = TTF_OpenFont("Raleway-Medium.ttf", 20);
    if (g_font_text == NULL )
    {
        return false;
    }
    return true;
}




int main(int arc, char* argv[])
{
    bool is_quit = false;
    if (Init() == false)
        return 0;
    // Apply Background
    g_bkground = SDLCommonFunc::LoadImage("background.png");
    if (g_bkground == NULL)
    {
        return 0;
    }
    //Make text
    TextObject time_game;
    //Make Board
    Board board;
    board.Show_Board(g_screen);
 
    SDL_Flip(g_screen);
    while (!is_quit)
    {
        SDLCommonFunc::ApplySurface(g_bkground, g_screen, 0, 0,SCREEN_HEIGHT,SCREEN_WIDTH);
        while (SDL_PollEvent(&g_even))
        {
            if (g_even.type == SDL_QUIT)
            {
                is_quit = true;
                break;
            }
         
        }
        
        board.HandleInputAction(g_even);
        board.Show_Board(g_screen);
        //Show time for game
        std::string str_time = "Time: ";
        Uint32 time_val = TIME_PLAYING - SDL_GetTicks() / 1000;
        std::string str_val = std::to_string(time_val);
        str_time += str_val;
        time_game.SetText(str_time);
        time_game.SetRect(WIDTH_BACKGROUND - 120, 10);
        time_game.CreatFontText(g_font_text, g_screen);
        if (SDL_Flip(g_screen) == -1)
            return 0;
        

        if (board.CheckBoard())
        {
            g_bkground = SDLCommonFunc::LoadImage("WinScreen.png");
            SDLCommonFunc::ApplySurface(g_bkground, g_screen, 0, 0, SCREEN_HEIGHT, SCREEN_WIDTH);
            time_game.CreatFontText(g_font_text, g_screen);
            if (SDL_Flip(g_screen) == -1)
                return 0;
            if (MessageBox(NULL, L"You Win!", L"Infomation", MB_ICONINFORMATION) == IDOK)
            {                
                break;
            }
        }
        
        if (time_val == 0)
        {

            if (MessageBox(NULL, L"GameOver!", L"Infomation", MB_ICONINFORMATION) == IDOK)
            {
                break;
            }
        }
      

       
        SDL_Delay(70);
    }
   
   
    
    SDLCommonFunc::CleanUp();
    SDL_Quit();

    return 1;
}
